#include <avtTMP.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkFloatArray.h>
#include <avtDatabaseMetaData.h>
#include <vtkRInterface.h>
#include <vtkDoubleArray.h>
#include <limits>

void
avtStratifiedTimeIteratorOperation::OperationInit()
{
    int numTuples = output->GetNumberOfTuples();
    float val;
    if (operation == MIN_OPERATOR)
        val = numeric_limits<float>::max();
    else if (operation == MAX_OPERATOR)
        val = -numeric_limits<float>::max();
        
    for (int i = 0; i < numTuples; i++)
    {
        for (int j = 0; j < numStrata; j++)
            output->SetComponent(i, j, val);
    }
}


void
avtStratifiedTimeIteratorOperation::Initialize()
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
    int numTuples;
    bool nodeCenteredData = (GetInput()->GetInfo().GetAttributes().GetCentering() == AVT_NODECENT);
    if (nodeCenteredData)
        numTuples = inDS->GetPointData()->GetScalars()->GetNumberOfTuples();
    else
        numTuples = inDS->GetCellData()->GetScalars()->GetNumberOfTuples();
    cout<<"NODE = "<<nodeCenteredData<<endl;


    outDS = (vtkDataSet *)(inDS->NewInstance());
    outDS->CopyStructure(inDS);
    
    output = vtkFloatArray::New();
    output->SetNumberOfComponents(numStrata);
    output->SetNumberOfTuples(numTuples);
    
    if (nodeCenteredData)
        outDS->GetPointData()->SetScalars(output);
    else
        outDS->GetPointData()->SetScalars(output);


    cout<<"avtStratifiedTimeIteratorOperation::Initialize(): numStrata = "<<numStrata<<endl;
    initialized = true;
}

avtMonthlyIteratorOperation::avtMonthlyIteratorOperation()
{
    numStrata = 12;
}


void
avtMonthlyIteratorOperation::Execute()
{
    Initialize();
    
    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);
    vtkDataSet *ds = leaves[0];
    vtkFloatArray *scalars = NULL;
    if (nleaves != 1)
    {
        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
    }
    
    bool nodeCenteredData = true;

    if (nodeCenteredData)
        scalars = (vtkFloatArray *)ds->GetPointData()->GetScalars();
    else
        scalars = (vtkFloatArray *)ds->GetCellData()->GetScalars();
    float *vals = (float *) scalars->GetVoidPointer(0);

    int numTuples = scalars->GetNumberOfTuples();

    int strata = currentTime % numStrata;
    
    if (operation == MIN_OPERATOR)
    {
        for (int i = 0; i < numTuples; i++)
        {
            float val = output->GetComponent(i, strata);
            if (vals[i] < val)
                output->SetComponent(i, strata, vals[i]);
        }
    }
    else if (operation == MAX_OPERATOR)
    {
        for (int i = 0; i < numTuples; i++)
        {
            float val = output->GetComponent(i, strata);
            if (vals[i] > val)
                output->SetComponent(i, strata, vals[i]);
        }
    }

    cout<<"Execute strata= "<<strata<<endl;

}

void
avtMonthlyIteratorOperation::CreateFinalOutput()
{
    cout<<"CreateFinalOutput"<<endl;
    avtDataTree_p outputTree = new avtDataTree(outDS, 0);
    SetOutputDataTree(outputTree);
    outDS->Delete();
    
    outDS->Print(cout);
}


avtMonthlyExceedencesOperation::avtMonthlyExceedencesOperation()
{
    numStrata = 12;
}

void
avtMonthlyExceedencesOperation::Initialize()
{
    avtStratifiedTimeIteratorOperation::Initialize();
    
    if (initialized)
        return;
    
    int numTuples = output->GetNumberOfTuples();
    vals.resize(numStrata);
    for (int i = 0; i < numStrata; i++)
        vals[i].resize(numTuples);
    initialized = true;
}

void
avtMonthlyExceedencesOperation::Execute()
{
    Initialize();
    
    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);
    vtkDataSet *ds = leaves[0];
    vtkFloatArray *scalars = NULL;
    if (nleaves != 1)
    {
        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
    }
    
    bool nodeCenteredData = true;

    if (nodeCenteredData)
        scalars = (vtkFloatArray *)ds->GetPointData()->GetScalars();
    else
        scalars = (vtkFloatArray *)ds->GetCellData()->GetScalars();
    float *v = (float *) scalars->GetVoidPointer(0);

    int numTuples = scalars->GetNumberOfTuples();
    int strata = currentTime % numStrata;

    cout<<"Execute: strata= "<<strata<<endl;
    float cutoff = 0.24;
    for (int i = 0; i < numTuples; i++)
    {
        if (v[i] > cutoff)
            vals[strata][i].push_back(v[i]);
    }
    cout<<"... done execute"<<endl;
}

void
avtMonthlyExceedencesOperation::CreateFinalOutput()
{
    cout<<"CreateFinalOutput"<<endl;
    avtDataTree_p outputTree = new avtDataTree(outDS, 0);
    SetOutputDataTree(outputTree);
    outDS->Delete();
    
    outDS->Print(cout);
}



avtRScriptWithArgsFilter::avtRScriptWithArgsFilter()
{
}

void
avtRScriptWithArgsFilter::Execute()
{
    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);

    if (nleaves != 1)
    {
        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
    }

    vtkDataSet *inDS = leaves[0];
    int numTuples;
    bool nodeCenteredData = (GetInput()->GetInfo().GetAttributes().GetCentering() == AVT_NODECENT);
    vtkDataArray *scalars;
    if (nodeCenteredData)
    {
        numTuples = inDS->GetPointData()->GetScalars()->GetNumberOfTuples();
        scalars = inDS->GetPointData()->GetScalars();
    }
    else
    {
        numTuples = inDS->GetCellData()->GetScalars()->GetNumberOfTuples();
        scalars = inDS->GetCellData()->GetScalars();
    }
    cout<<"NODE = "<<nodeCenteredData<<endl;


    outDS = (vtkDataSet *)(inDS->NewInstance());
    outDS->CopyStructure(inDS);
    
    output = vtkFloatArray::New();
    output->SetNumberOfComponents(1);
    output->SetNumberOfTuples(numTuples);
    
    if (nodeCenteredData)
        outDS->GetPointData()->SetScalars(output);
    else
        outDS->GetPointData()->SetScalars(output);


    vtkRInterface *RI = vtkRInterface::New();
    vtkDoubleArray *inData = vtkDoubleArray::New();
    inData->SetNumberOfComponents(1);
    inData->SetNumberOfTuples(1);
    
    string cmd;
    for (int a = 0; a < arguments.size(); a++)
    {
        char args[256];
        sprintf(args, "%s <- %f\n", argNames[a].c_str(), arguments[a]);
        cmd += args;
    }
    cmd += rcode;
    for (int i = 0; i < numTuples; i++)
    {
        //cout<<(double)scalars->GetComponent(i,0) <<" ---> ";
        inData->SetValue(0, (double)scalars->GetComponent(i,0));
        RI->AssignVTKDataArrayToRVariable(inData, inputName.c_str());
        
        //cout<<cmd<<endl;
        RI->EvalRscript(cmd.c_str());
        vtkDoubleArray *out = vtkDoubleArray::SafeDownCast(RI->AssignRVariableToVTKDataArray(outputName.c_str()));
        output->SetValue(i,(float)out->GetComponent(0,0));
        //cout<<output->GetComponent(i,0)<<endl;
    }
    
    inData->Delete();
    RI->Delete();


    avtDataTree_p outputTree = new avtDataTree(outDS, 0);
    SetOutputDataTree(outputTree);
    outDS->Delete();

    cout<<"avtOpOverTimeFilter    DONE"<<endl;
}

avtOpOverTimeFilter::avtOpOverTimeFilter()
{
    operation = MAX_OPERATOR;
}

void
avtOpOverTimeFilter::OperationInit()
{
    int numTuples = output->GetNumberOfTuples();
    float val;
    if (operation == MIN_OPERATOR)
        val = numeric_limits<float>::max();
    else if (operation == MAX_OPERATOR)
        val = -numeric_limits<float>::max();
        
    for (int i = 0; i < numTuples; i++)
        output->SetComponent(i, 0, val);
}


void
avtOpOverTimeFilter::Initialize()
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
    int numTuples;
    bool nodeCenteredData = (GetInput()->GetInfo().GetAttributes().GetCentering() == AVT_NODECENT);
    if (nodeCenteredData)
        numTuples = inDS->GetPointData()->GetScalars()->GetNumberOfTuples();
    else
        numTuples = inDS->GetCellData()->GetScalars()->GetNumberOfTuples();
    cout<<"NODE = "<<nodeCenteredData<<endl;


    outDS = (vtkDataSet *)(inDS->NewInstance());
    outDS->CopyStructure(inDS);
    
    output = vtkFloatArray::New();
    output->SetNumberOfComponents(1);
    output->SetNumberOfTuples(numTuples);
    
    if (nodeCenteredData)
        outDS->GetPointData()->SetScalars(output);
    else
        outDS->GetPointData()->SetScalars(output);


    initialized = true;
}

void
avtOpOverTimeFilter::Execute()
{
    Initialize();
    
    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);
    vtkDataSet *ds = leaves[0];
    vtkFloatArray *scalars = NULL;
    if (nleaves != 1)
    {
        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
    }
    
    bool nodeCenteredData = true;

    if (nodeCenteredData)
        scalars = (vtkFloatArray *)ds->GetPointData()->GetScalars();
    else
        scalars = (vtkFloatArray *)ds->GetCellData()->GetScalars();
    float *vals = (float *) scalars->GetVoidPointer(0);

    int numTuples = scalars->GetNumberOfTuples();

    if (operation == MIN_OPERATOR)
    {
        for (int i = 0; i < numTuples; i++)
        {
            float val = output->GetComponent(i, 0);
            if (vals[i] < val)
                output->SetComponent(i, 0, vals[i]);
        }
    }
    else if (operation == MAX_OPERATOR)
    {
        for (int i = 0; i < numTuples; i++)
        {
            float val = output->GetComponent(i, 0);
            if (vals[i] > val)
                output->SetComponent(i, 0, vals[i]);
        }
    }
}


void
avtOpOverTimeFilter::CreateFinalOutput()
{
    avtDataTree_p outputTree = new avtDataTree(outDS, 0);
    SetOutputDataTree(outputTree);
    outDS->Delete();

    cout<<"avtOpOverTimeFilter  DONE"<<endl;
    
    //outDS->Print(cout);
}
