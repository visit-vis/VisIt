#include <avtParallel.h>
#include <avtRSimpleFilter.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkFloatArray.h>
#include <vtkDoubleArray.h>
#include <vtkIntArray.h>
#include <limits>
#include <vtkRInterface.h>
#include <vtkRectilinearGrid.h>
#include <DebugStream.h>

#include <avtCallback.h>
#include <avtDatabase.h>
#include <avtDatabaseMetaData.h>
#include <InvalidFilesException.h>

#ifdef PARALLEL
  #include <mpi.h>
#endif

using namespace std;

// ****************************************************************************
// Method:  avtRSimpleFilter::avtRSimpleFilter
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

avtRSimpleFilter::avtRSimpleFilter()
{
    initialized = false;
    outDS = NULL;
    numTuples = 0;
    nodeCenteredData = false;

    cutoff = 0.5;
    percentile = 0.9;
}

// ****************************************************************************
// Method:  avtRSimpleFilter::~avtRSimpleFilter
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

avtRSimpleFilter::~avtRSimpleFilter()
{
}

// ****************************************************************************
// Method:  avtRSimpleFilter::FilterSupportsTimeParallelization
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

bool
avtRSimpleFilter::FilterSupportsTimeParallelization()
{
    return true;
}

// ****************************************************************************
// Method:  avtRSimpleFilter::DataCanBeParallelizedOverTime
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

bool
avtRSimpleFilter::DataCanBeParallelizedOverTime()
{
    return true;
}


// ****************************************************************************
// Method:  avtRSimpleFilter::CalculateThreshold
//
// Programmer:  Dave Pugmire
// Creation:    May 22, 2012
//
// ****************************************************************************

float
avtRSimpleFilter::CalculateThreshold(int loc)
{
    int nVals = values[loc].size();
    if (nVals == 0)
        return 0.0f;
    
    vtkDoubleArray *inData = vtkDoubleArray::New();
    inData->SetNumberOfComponents(1);
    inData->SetNumberOfTuples(nVals);
    for (int i = 0; i < nVals; i++)
        inData->SetValue(i, values[loc][i]);

    vtkRInterface *RI = vtkRInterface::New();
    RI->AssignVTKDataArrayToRVariable(inData, "inData");

    char str[128];
    sprintf(str, "%q = quantile(inData, %f)\n", percentile);

    RI->EvalRscript(str);
    vtkDoubleArray *Q = vtkDoubleArray::SafeDownCast(RI->AssignRVariableToVTKDataArray("q"));

    float threshold = 0.0f;
    if (Q)
        threshold = (float)Q->GetComponent(0,0);

    inData->Delete();
    RI->Delete();
    return threshold;
}


// ****************************************************************************
// Method:  avtRSimpleFilter::ExecutionSuccessful
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

bool
avtRSimpleFilter::ExecutionSuccessful()
{
    return true;
}

// ****************************************************************************
// Method:  avtRSimpleFilter::Initialize
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

void
avtRSimpleFilter::Initialize()
{
    if (initialized)
        return;

    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);

    if (nleaves != 1)
    {
        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
    }

    vtkDataSet *inDS = leaves[0];
    outDS = (vtkDataSet *)(inDS->NewInstance());
    outDS->CopyStructure(inDS);

    nodeCenteredData = (GetInput()->GetInfo().GetAttributes().GetCentering() == AVT_NODECENT);
    if (nodeCenteredData)
        numTuples = inDS->GetPointData()->GetScalars()->GetNumberOfTuples();
    else
        numTuples = inDS->GetCellData()->GetScalars()->GetNumberOfTuples();
    
    values.resize(numTuples);

    //cout<<"values:"<<values.size()<<" x "<<values[0].size()<<" x "<<values[0][0].size()<<endl;
    //cout<<"values["<<numTuples<<"]["<<numBins<<"][numTimes]"<<endl;
    
    idx0 = 0;
    idxN = numTuples;
    
#ifdef PARALLEL
    int rank = PAR_Rank();
    int nProcs = PAR_Size();

    int nSamplesPerProc = (numTuples / nProcs);
    int oneExtraUntil = (numTuples % nProcs);
    if (rank < oneExtraUntil)
    {
        idx0 = (rank)*(nSamplesPerProc+1);
        idxN = (rank+1)*(nSamplesPerProc+1);
    }
    else
    {
        idx0 = (rank)*(nSamplesPerProc) + oneExtraUntil;
        idxN = (rank+1)*(nSamplesPerProc) + oneExtraUntil;
    }
    debug1<<"I have: ["<<idx0<<" "<<idxN<<"]"<<endl;
#endif
    
    initialized = true;
    delete [] leaves;
}


// ****************************************************************************
// Method:  avtRSimpleFilter::PreExecute
//
// Programmer:  Dave Pugmire
// Creation:    March 16, 2012
//
// ****************************************************************************

void
avtRSimpleFilter::PreExecute()
{
    avtDatasetToDatasetFilter::PreExecute();
}

// ****************************************************************************
// Method:  avtRSimpleFilter::PostExecute
//
// Programmer:  Dave Pugmire
// Creation:    March 16, 2012
//
// ****************************************************************************

void
avtRSimpleFilter::PostExecute()
{
    avtDatasetToDatasetFilter::PostExecute();
}

// ****************************************************************************
// Method:  avtRSimpleFilter::Execute
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

void
avtRSimpleFilter::Execute()
{
    debug1<<"avtRSimpleFilter::Execute() time= "<<currentTime<<endl;

    Initialize();
    
    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);
    vtkDataSet *ds = leaves[0];
    vtkFloatArray *scalars = NULL;

    if (nodeCenteredData)
        scalars = (vtkFloatArray *)ds->GetPointData()->GetScalars();
    else
        scalars = (vtkFloatArray *)ds->GetCellData()->GetScalars();
    float *vals = (float *) scalars->GetVoidPointer(0);

    int nTuples = scalars->GetNumberOfTuples();

    //cout<<"processing "<<currentTime<<" sv = "<<scalingVal<<" index= "<<index<<endl;

    for (int i = 0; i < nTuples; i++)
    {
        float v = vals[i];
        if (v > cutoff)
            values[i].push_back(v);
    }
}

// ****************************************************************************
// Method:  avtRSimpleFilter::CreateFinalOutput
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// Modifications:
//
//   Dave Pugmire, Wed Apr 11 17:07:26 EDT 2012
//   Remove the processing of locations in rounds. No longer needed.
//
// ****************************************************************************

void
avtRSimpleFilter::CreateFinalOutput()
{
    avtCallback::ResetTimeout(0);

    int numTimes = 1;
    //Exchange data....
#ifdef PARALLEL
    float *tmp = new float[numTimes];
    float *res = new float[numTimes];
    
    cout<<"FIX THIS!!!!"<<endl;
#if 0
    for (int i=0; i<numTuples; i++)
    {
        for (int t=0; t<numTimes; t++)
        {
            tmp[t] = 0.0;//-numeric_limits<float>::min();
            flags[t] = 0;
        }
        int nt = values[i].size();
        for (int t=0; t<nt; t++)
        {
            //if(PAR_Rank()== 0 ) cout<<values[i][b][t].time<<endl;
            tmp[values[i][t].time] = values[b][i][t].val;
            flags[values[b][i][t].time] = 1;
        }
        MPI_Allreduce(tmp, res, numTimes, MPI_FLOAT, MPI_SUM, VISIT_MPI_COMM);
        MPI_Allreduce(flags, flagsRes, numTimes, MPI_INT, MPI_SUM, VISIT_MPI_COMM);

        for (int b = 0; b < numBins; b++)
            values[i][b].resize(0);

        //See if it's one of my locations.
        if (i >= idx0 && i < idxN)
        {
            for (int t=0; t<numTimes; t++)
            {
                if (flagsRes[t])
                {
                    int b = GetIndexFromDay(t);
                    values[b][i].push_back(sample(res[t], t));
                }
            }
        }
    }
    
    delete [] tmp;
    delete [] res;
    delete [] flags;
    delete [] flagsRes;
#endif
#endif

    vtkRInterface *RI = vtkRInterface::New();
    
    vector<float> outputs_rv;
    outputs_rv.resize(numTuples);

    for (int i = idx0; i < idxN; i++)
    {
        float threshold = CalculateThreshold(i);

        int numExceedences = 0;
        int nt = values[i].size();
        for (int t = 0; t < nt; t++)
            if (values[i][t] > threshold)
                numExceedences++;

        if (numExceedences == 0)
        {
            outputs_rv[i] = -1.0;
        }
        else
        {
            //cout<<"numExceedences: "<<numExceedences<<endl;
            vtkDoubleArray *exceedences = vtkDoubleArray::New();
            exceedences->SetNumberOfComponents(1);
            exceedences->SetNumberOfTuples(numExceedences);
        
            int idx = 0;
            for (int t = 0; t < nt; t++)
                if (values[i][t] > threshold)
                {
                    exceedences->SetValue(idx, values[i][t]);
                    idx++;
                    if (idx == numExceedences)
                        break;
                }
            RI->AssignVTKDataArrayToRVariable(exceedences, "exceedences");
            //cout<<"Exceedences: ";
            //for (int e = 0; e < numExceedences; e++)
            //    cout<<" "<<exceedences->GetComponent(0,e);
            //cout<<endl;
        
            string cmd ="output = mean(exceedences)\n";
            RI->EvalRscript(cmd.c_str());
            
            vtkDoubleArray *out_rv = vtkDoubleArray::SafeDownCast(RI->AssignRVariableToVTKDataArray("output"));
            //cout<<"out_rv  : "<<out_rv->GetNumberOfComponents()<<" x "<<out_rv->GetNumberOfTuples()<<": "<<out_rv->GetComponent(0,0)<<endl;
            outputs_rv[i] = (float)out_rv->GetComponent(0,0);
            
            exceedences->Delete();
        }
    }

#if PARALLEL
    cout<<"FIX THIS!!"<<endl;

#if 0
    float *in0 = new float[numTuples], *in1 = new float[numTuples];
    float *sum0 = new float[numTuples], *sum1 = new float[numTuples];
    int N = outputs_rv.size();
    
    for (int n = 0; n < N; n++)
        in0[n] = in1[n] = sum0[n] = sum1[n] = 0.0;
    for (int n = 0; n < N; n++)
    {
        for (int b = 0; b<numBins; b++)
        {
            for (int i=0; i<numTuples; i++)
            {
                if (i >= idx0 && i < idxN)
                {
                    in0[i] = outputs_rv[n][b][i];
                    in1[i] = outputs_serv[n][b][i];
                }
                else
                    in0[i] = in1[i] = 0.0f;
            }
            SumFloatArray(in0, sum0, numTuples);
            SumFloatArray(in1, sum1, numTuples);
            if (PAR_Rank() == 0)
            {
                for (int i=0; i<numTuples; i++)
                {
                    outputs_rv[n][b][i] = sum0[i];
                    outputs_serv[n][b][i] = sum1[i];
                }
            }
        }
    }
    if (atts.GetComputeParamValues())
    {
        for (int n = 0; n < N; n++)
            in0[n] = in1[n] = sum0[n] = sum1[n] = 0.0;
        N = outputs_mle.size();
        for (int n = 0; n < N; n++)
        {
            for (int b = 0; b<numBins; b++)
            {
                for (int i=0; i<numTuples; i++)
                {
                    if (i >= idx0 && i < idxN)
                    {
                        in0[i] = outputs_mle[n][b][i];
                        in1[i] = outputs_semle[n][b][i];
                    }
                    else
                        in0[i] = in1[i] = 0.0f;
                }
                SumFloatArray(in0, sum0, numTuples);
                SumFloatArray(in1, sum1, numTuples);
                if (PAR_Rank() == 0)
                {
                    for (int i=0; i<numTuples; i++)
                    {
                        outputs_mle[n][b][i] = sum0[i];
                        outputs_semle[n][b][i] = sum1[i];
                    }
                }
            }
        }
    }

    delete [] in0;
    delete [] in1;
    delete [] sum0;
    delete [] sum1;
#endif
#endif
    if (PAR_Rank() == 0)
    {
        int displayIdx = 0;
        /*
        if (atts.GetAggregation() == PeaksOverThresholdAttributes::ANNUAL)
            displayIdx = 0;
        else if (atts.GetAggregation() == PeaksOverThresholdAttributes::MONTHLY)
            displayIdx = (int)atts.GetDisplayMonth() - (int)(PeaksOverThresholdAttributes::JAN);
        else if (atts.GetAggregation() == PeaksOverThresholdAttributes::MONTHLY)
            displayIdx = (int)atts.GetDisplaySeason() - (int)(PeaksOverThresholdAttributes::WINTER);
        */
        
        //cout<<"Create output.....("<<numOutputComponents<<" x "<<numTuples<<")"<<endl;
        vtkFloatArray *outVar = vtkFloatArray::New();
        outVar->SetNumberOfComponents(1);
        outVar->SetNumberOfTuples(numTuples);
        int idx = 0;
        for (int i = 0; i < numTuples; i++, idx++)
        {
            outVar->SetValue(i, outputs_rv[i]);
        }
    
        if (nodeCenteredData)
            outDS->GetPointData()->SetScalars(outVar);
        else
            outDS->GetPointData()->SetScalars(outVar);
        
        outVar->Delete();

        avtDataTree_p outputTree = new avtDataTree(outDS, 0);
        SetOutputDataTree(outputTree);
        outDS->Delete();

        //cout<<"outputs: "<<outputs_rv.size()<<" "<<outputs_rv[0].size()<<" "<<outputs_rv[0][0].size()<<endl;
    }
    else
        SetOutputDataTree(new avtDataTree());

    avtCallback::ResetTimeout(5*60);
}

