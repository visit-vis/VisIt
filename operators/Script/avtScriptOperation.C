/*****************************************************************************
*
* Copyright (c) 2000 - 2012, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//  File: avtScriptOperation.C
// ************************************************************************* //

#include <avtScriptOperation.h>
#include <InstallationFunctions.h>
#include <vtkDataArray.h>

#include <vtkRInterface.h>
#include <avtPythonFilterEnvironment.h>
#include <Python.h>

#include <avtDatasetToDatasetFilter.h>
#include <avtTimeLoopFilter.h>
#include <vtkDataSet.h>
#include <vtkFloatArray.h>
#include <vtkPointData.h>
#include <vtkCellData.h>

#include <avtParallel.h>
#include <vector>
#include <map>
#ifdef PARALLEL
  #include <mpi.h>
#endif

using namespace std;

class avtTimeWindowLoopFilter : virtual public avtDatasetToDatasetFilter,
				virtual public avtTimeLoopFilter
{
    /// record which rank has what timesteps and parts of the datasets..
  public:
    avtTimeWindowLoopFilter() {initialized = false; index=0;}
    virtual ~avtTimeWindowLoopFilter() {}
    virtual const char* GetType() {return "avtTimeWindowLoopFilter";}

    //vector< vector<float> > values;
    vector<float> values;
    size_t index;

  protected:
    void                    Initialize();
    virtual void            Execute();
    virtual void            CreateFinalOutput();
    virtual bool            ExecutionSuccessful() { return true; }

    virtual bool            FilterSupportsTimeParallelization() { return true; }
    virtual bool            DataCanBeParallelizedOverTime() { return true; }
    //virtual bool            OperationNeedsAllData(void) { return true; }

    bool handleOutputShapeAndData(PyObject* result);

    bool initialized, nodeCenteredData;
    int numTuples, idx0, idxN;
  public:
    string script;
    avtPythonFilterEnvironment *environment;
    vtkDataSet* inputDataSet;
    int inputDomain;
    vtkShapedDataArray outputdataArray;
};

void
avtTimeWindowLoopFilter::Initialize()
{
    if (initialized)
	return;

    vtkDataSet *inDS = inputDataSet;
    nodeCenteredData = (GetInput()->GetInfo().GetAttributes().GetCentering() == AVT_NODECENT);
    if (nodeCenteredData)
        numTuples = inDS->GetPointData()->GetScalars()->GetNumberOfTuples();
    else
        numTuples = inDS->GetCellData()->GetScalars()->GetNumberOfTuples();

    idx0 = 0;
    idxN = numTuples;
    index = 0;
    
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
#endif

    initialized = true;
    
    // values need to be number of tuples * total number of timesteps..
    int totalTimes = GetTotalNumberOfTimeSlicesForRank();
    cout<<PAR_Rank()<<": locs: ["<<idx0<<" "<<idxN<<"] times:"<<totalTimes<<endl;

    //format is: T0_val0, T0_val1, ...., T1_val0, T2_val1, ....
    values.resize(numTuples*totalTimes);
}

void
avtTimeWindowLoopFilter::Execute()
{
    Initialize();

    vtkDataSet *ds = inputDataSet;
    vtkFloatArray *scalars = NULL;

    if (nodeCenteredData)
        scalars = (vtkFloatArray *)ds->GetPointData()->GetScalars();
    else
        scalars = (vtkFloatArray *)ds->GetCellData()->GetScalars();
    float *vals = (float *) scalars->GetVoidPointer(0);

    int rank = PAR_Rank();

    int numTimes = GetEndTime() - GetStartTime() + 1;
    float dsTime = (float)GetInput()->GetInfo().GetAttributes().GetTime();
    int dsCycle = (float)GetInput()->GetInfo().GetAttributes().GetCycle();

    for (size_t i = 0; i < numTuples; i++)
        values[index++] = vals[i];
    
    /*
    int rank = PAR_Rank();
    cout<<"TimeStep: " << rank << " " << currentTime<< " " << GetStartTime() << " " << GetEndTime() << " "
	<< GetInput()->GetInfo().GetAttributes().DataIsReplicatedOnAllProcessors() << endl;
    */
}

void
avtTimeWindowLoopFilter::CreateFinalOutput()
{
    Barrier();
    cout<<"CreateFinalOutput : values= "<<values.size()<<endl;
    
    size_t totalTupleSize = idxN-idx0;
    int numTimes = GetEndTime() - GetStartTime() + 1;
    
    vector<float> finalVals;
#ifdef PARALLEL
    finalVals.resize((idxN-idx0)*numTimes);
    float *res = new float[numTimes];
    float *tmp = new float[numTimes];

    map<int,int> cycleMap;
    vector<int> myCycles = GetCyclesForRank();
    for (int i = 0; i < myCycles.size(); i++)
	cycleMap[myCycles[i]] = i;
    int finalIdx = 0;
    for (int i = 0; i < numTuples; i++)
    {
	for (int j = 0; j < numTimes; j++)
	    res[j] = tmp[j] = 0.0f;

	for (int j = 0; j < numTimes; j++)
	{
	    //If I have this timestep...
	    map<int, int>:: const_iterator mi = cycleMap.find(j);
	    if (mi != cycleMap.end())
	    {
		int ti = mi->second;
		int idx = ti*numTuples + i;
		tmp[j] = values[idx];
	    }
	}
	
	MPI_Allreduce(tmp, res, numTimes, MPI_FLOAT, MPI_SUM, VISIT_MPI_COMM);
	if (i >= idx0 && i < idxN)
	    for (int j = 0; j < numTimes; j++)
		finalVals[finalIdx++] = res[j];
    }
    delete [] tmp;
    delete [] res;
#else
    //Redo the indexing.....
    finalVals = values;
    int idx = 0;
    for (int i = 0; i < numTuples; i++)
	for (int j = 0; j < numTimes; j++)
	    finalVals[idx++] = values[j*numTuples +i];
#endif

    //std::cout << GetEndTime() << " " << GetStartTime() << std::endl;
    //std::vector<float> inputArray;

    //inputArray.resize(numTimes);
    //cout<<__FILE__<<" "<<__LINE__<<endl;

    outputdataArray.vtkarray = 0;

    PyObject *retval = PyTuple_New(numTimes);

    for (int i = 0; i < totalTupleSize; i++)
    {
        for(int j = 0; j < numTimes; ++j)
        {
            PyObject* value = PyInt_FromLong(finalVals[j*totalTupleSize + i]);
            //PyObject* value = PyInt_FromLong(finalVals[(i*(numTimes))+j]);
            PyTuple_SET_ITEM(retval, j, value);
        }

        environment->Interpreter()->SetGlobalObject(retval,"__internal_array");
        environment->Interpreter()->RunScript(script);
        PyObject* result = environment->Interpreter()->GetGlobalObject("res");
        handleOutputShapeAndData(result);
    }

    SetOutputDataTree(new avtDataTree(inputDataSet,inputDomain));
    Barrier();
}

#include <vtkUnsignedCharArray.h>
#include <vtkIntArray.h>
#include <vtkLongArray.h>
#include <vtkDoubleArray.h>
#include <vtkStringArray.h>
#include <vtkCharArray.h>

bool
avtTimeWindowLoopFilter::handleOutputShapeAndData(PyObject* obj)
{
    if(PyTuple_Check(obj))
    {
        size_t size = PyTuple_Size(obj);
        /// make sure the new size and first size matches..
        /// TODO: better error checking..
        /// Convert this logic to construct multi dimensional shape array..
        if(!outputdataArray.vtkarray)
        {
            /// figure out output type from object..
            outputdataArray.shape.push_back(0);
            outputdataArray.shape.push_back(size);
        }
        else
        {
            if(size != outputdataArray.shape[1])
            {
                std::cerr << "shape sizes do not match, this operation does "
                          << "not support varying results from kernels"
                          << size << " " << outputdataArray.shape[1]
                          << std::endl;
                /// error
                return false;
            }
        }

        outputdataArray.shape[0] += 1;

        for(size_t i = 0; i < size; ++i)
        {
            PyObject* retobj = PyTuple_GetItem(obj,i);

            if (PyBool_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkUnsignedCharArray::New();
                vtkUnsignedCharArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((retobj == Py_False ? 0: 1 ));
            }
            else if(PyInt_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkIntArray::New();
                vtkIntArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((int)PyInt_AsLong(retobj));
            }
            else if(PyLong_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkLongArray::New();
                vtkLongArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((long)PyLong_AsLong(retobj));
            }
            else if(PyFloat_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkDoubleArray::New();
                vtkDoubleArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((double)PyFloat_AsDouble(retobj));
            }
            else if(PyString_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkStringArray::New();
                vtkStringArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((const char*)PyString_AsString(retobj));
            }
            else
            {
                std::cerr << "Something else.." << std::endl;
            }
        }

    }
    else if(PyList_Check(obj))
    {
        size_t size = PyList_Size(obj);
        /// make sure the new size and first size matches..
        /// TODO: better error checking..
        /// Convert this logic to construct multi dimensional shape array..
        if(!outputdataArray.vtkarray)
        {
            /// figure out output type from object..
            outputdataArray.shape.push_back(0);
            outputdataArray.shape.push_back(size);
        }
        else
        {
            if(size != outputdataArray.shape[1])
            {
                std::cerr << "shape sizes do not match, this operation does "
                          << "not support varying results from kernels: "
                          << size << " " << outputdataArray.shape[1]
                          << std::endl;
                /// error
                return false;
            }
        }
        outputdataArray.shape[0] += 1;
        for(size_t i = 0; i < size; ++i)
        {
            PyObject* retobj = PyList_GetItem(obj,i);

            if (PyBool_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkUnsignedCharArray::New();
                vtkUnsignedCharArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((retobj == Py_False ? 0: 1 ));
            }
            else if(PyInt_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkIntArray::New();
                vtkIntArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((int)PyInt_AsLong(retobj));
            }
            else if(PyLong_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkLongArray::New();
                vtkLongArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((long)PyLong_AsLong(retobj));
            }
            else if(PyFloat_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkDoubleArray::New();
                vtkDoubleArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((double)PyFloat_AsDouble(retobj));
            }
            else if(PyString_Check(retobj))
            {
                if(!outputdataArray.vtkarray)
                    outputdataArray.vtkarray = vtkStringArray::New();
                vtkStringArray::SafeDownCast(outputdataArray.vtkarray)
                        ->InsertNextValue((const char*)PyString_AsString(retobj));
            }
            else
            {
                std::cerr << "Something else.." << std::endl;
            }
        }
    }
    else
    {
        if(!outputdataArray.vtkarray)
            outputdataArray.shape.push_back(0);

        outputdataArray.shape[0] += 1;

        if (PyBool_Check(obj))
        {
            if(!outputdataArray.vtkarray)
                outputdataArray.vtkarray = vtkUnsignedCharArray::New();
            vtkUnsignedCharArray::SafeDownCast(outputdataArray.vtkarray)
                    ->InsertNextValue((obj == Py_False ? 0: 1 ));
        }
        else if(PyInt_Check(obj))
        {
            if(!outputdataArray.vtkarray)
                outputdataArray.vtkarray = vtkIntArray::New();
            vtkIntArray::SafeDownCast(outputdataArray.vtkarray)
                    ->InsertNextValue((int)PyInt_AsLong(obj));
        }
        else if(PyLong_Check(obj))
        {
            if(!outputdataArray.vtkarray)
                outputdataArray.vtkarray = vtkLongArray::New();
            vtkLongArray::SafeDownCast(outputdataArray.vtkarray)
                    ->InsertNextValue((long)PyLong_AsLong(obj));
        }
        else if(PyFloat_Check(obj))
        {
            if(!outputdataArray.vtkarray)
                outputdataArray.vtkarray = vtkDoubleArray::New();
            vtkDoubleArray::SafeDownCast(outputdataArray.vtkarray)
                    ->InsertNextValue((double)PyFloat_AsDouble(obj));
        }
        else if(PyString_Check(obj))
        {
            if(!outputdataArray.vtkarray)
                outputdataArray.vtkarray = vtkStringArray::New();
            vtkStringArray::SafeDownCast(outputdataArray.vtkarray)
                    ->InsertNextValue((const char*)PyString_AsString(obj));
        }
        else
        {
            std::cerr << "Something else.." << std::endl;
        }
    }


    return true;
}


avtScriptOperation::avtScriptOperation()
{}

#include <avtOriginatingSource.h>
#include <avtMetaData.h>
#include <avtDatabase.h>
#include <avtDatabaseMetaData.h>
#include <avtCallback.h>
#include <avtSourceFromDatabase.h>


bool
avtScriptOperation::avtVisItForEachLocation::func(ScriptArguments& args, vtkShapedDataArray& result)
{
    Variant windowArray = args.getArg(0);
    vtkDataArray* var = (vtkDataArray*)args.getArgAsVoidPtr(1);
    Variant kernelLanguage = args.getArg(2); //R or Python
    Variant kernel = args.getArg(3); //kernel itself
    Variant kernelName = args.getArg(4); //name of the function to call..
    Variant primaryVariable = args.getArg(5); // primary variable name to modify..

    std::vector<Variant> kernelArgs = args.getArgAsVariantVector(6);

    avtPythonFilterEnvironment* environ = args.GetPythonEnvironment();

    /// register the kernels..
    if(kernelLanguage == "Python")
    {
        environ->Interpreter()->RunScript(kernel.AsString());
    }
    else
    {
        std::ostringstream rsetup;

        rsetup << "import rpy2, rpy2.robjects\n"
               << kernelName.AsString() <<  " = rpy2.robjects.r(\"\"\"\n"
               << kernel.AsString() << "\n"
               << "\"\"\")\n";
        environ->Interpreter()->RunScript(rsetup.str());
    }

    std::string arglist = "";

    for(int i = 0; i < kernelArgs.size(); ++i)
        arglist += kernelArgs[i].ConvertToString() + (i == kernelArgs.size()-1 ? "" : ",");

    std::ostringstream resultKernel;
    resultKernel << "res = " << kernelName.AsString() <<  "(numpy.asarray(__internal_array)";

    if(arglist.size() > 0)
        resultKernel << "," << arglist << ")\n";
    else
        resultKernel << ")\n";

    resultKernel << "res = numpy.asarray(res).tolist()\n";


    /// std::cout << resultKernel.str() << std::endl;
    /// run the time loop filter..

    avtTimeWindowLoopFilter *filt = new avtTimeWindowLoopFilter;
    filt->environment = environ;
    filt->inputDataSet = args.GetInputDataSet();
    filt->inputDomain = args.GetInputDomain();
    filt->script = resultKernel.str();

    filt->SetInput(args.GetInput());
    avtDataObject_p dob = filt->GetOutput();

    //avtContract_p newContract = new avtContract(args.GetContract());
    //newContract->SetReplicateSingleDomainOnAllProcessors(true);
    dob->Update(args.GetContract());

    result = filt->outputdataArray;

    //result.shape.push_back(var->GetDataSize());
    //result.vtkarray = var->NewInstance();
    //result.vtkarray->DeepCopy(var);

    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItForEachLocation::GetSignature(std::string& name,
                          stringVector& argnames,
                          std::vector<ScriptVariantTypeEnum>& argtypes)
{
    name = "visit_foreach_location";
    argnames.push_back("window");
    argtypes.push_back(ScriptOperation::INT_VECTOR_TYPE);

    argnames.push_back("variableName");
    argtypes.push_back(ScriptOperation::VTK_DATA_ARRAY_TYPE);

    argnames.push_back("kernelLanguage");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("kernel");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("kernelName");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("primaryVariable");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("kernelArgs");
    argtypes.push_back(ScriptOperation::VARIANT_VECTOR_TYPE);
    return ScriptOperation::VTK_MULTI_DIMENSIONAL_DATA_ARRAY;
}


bool
avtScriptOperation::avtVisItForEachLocationR::func(ScriptArguments& args, vtkShapedDataArray &result)
{
    Variant windowArray = args.getArg(0);
    vtkDataArray* var = (vtkDataArray*)args.getArgAsVoidPtr(1);
    Variant kernelName = args.getArg(2); //name of the function to call..
    Variant primaryVariable = args.getArg(3); // primary variable name to modify..

    std::vector<Variant> kernelArgs = args.getArgAsVariantVector(4);

    avtPythonFilterEnvironment* environ = args.GetPythonEnvironment();

    std::ostringstream rsetup;
    rsetup << "import rpy2, rpy2.robjects\n"
           << kernelName.AsString() <<  " = rpy2.robjects.r('" << kernelName.AsString() << "')\n";
    environ->Interpreter()->RunScript(rsetup.str());

    std::string arglist = "";

    for(int i = 0; i < kernelArgs.size(); ++i)
        arglist += kernelArgs[i].ConvertToString() + (i == kernelArgs.size()-1 ? "" : ",");

    std::ostringstream resultKernel;
    resultKernel << "res = " << kernelName.AsString() <<  "(numpy.asarray(__internal_array)";

    if(arglist.size() > 0)
        resultKernel << "," << arglist << ")\n";
    else
        resultKernel << ")\n";

    resultKernel << "res = numpy.asarray(res).tolist()\n";

    /// run the time loop filter..

    //std::cout << resultKernel << std::endl;
    avtTimeWindowLoopFilter *filt = new avtTimeWindowLoopFilter;
    filt->environment = args.GetPythonEnvironment();
    filt->inputDataSet = args.GetInputDataSet();
    filt->inputDomain = args.GetInputDomain();
    filt->script = resultKernel.str();

    filt->SetInput(args.GetInput());
    avtDataObject_p dob = filt->GetOutput();

    dob->Update(args.GetContract());

    result = filt->outputdataArray;

    //result.shape.push_back(var->GetDataSize());
    //result.vtkarray = var->NewInstance();
    //result.vtkarray->DeepCopy(var);

    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItForEachLocationR::GetSignature(std::string& name,
                          stringVector& argnames,
                          std::vector<ScriptVariantTypeEnum>& argtypes)
{
    name = "visit_foreach_location_r";
    argnames.push_back("window");
    argtypes.push_back(ScriptOperation::INT_VECTOR_TYPE);

    argnames.push_back("variableName");
    argtypes.push_back(ScriptOperation::VTK_DATA_ARRAY_TYPE);

    argnames.push_back("kernelName");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("primaryVariable");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("kernelArgs");
    argtypes.push_back(ScriptOperation::VARIANT_VECTOR_TYPE);
    return ScriptOperation::VTK_MULTI_DIMENSIONAL_DATA_ARRAY;
}

bool
avtScriptOperation::avtVisItForEachLocationPython::func(ScriptArguments& args, vtkShapedDataArray& result)
{
    Variant windowArray = args.getArg(0);
    vtkDataArray* var = (vtkDataArray*)args.getArgAsVoidPtr(1);
    Variant kernelName = args.getArg(2); //name of the function to call..
    Variant primaryVariable = args.getArg(3); // primary variable name to modify..

    std::vector<Variant> kernelArgs = args.getArgAsVariantVector(4);

    std::string arglist = "";

    for(int i = 0; i < kernelArgs.size(); ++i)
        arglist += kernelArgs[i].ConvertToString() + (i == kernelArgs.size()-1 ? "" : ",");

    std::ostringstream resultKernel;
    resultKernel << "res = " << kernelName.AsString() <<  "(numpy.asarray(__internal_array)";

    if(arglist.size() > 0)
        resultKernel << "," << arglist << ")\n";
    else
        resultKernel << ")\n";

    resultKernel << "res = numpy.asarray(res).tolist()\n";

    //std::cout << resultKernel.str() << std::endl;
    /// run the time loop filter..

    avtTimeWindowLoopFilter *filt = new avtTimeWindowLoopFilter;
    filt->environment = args.GetPythonEnvironment();
    filt->inputDataSet = args.GetInputDataSet();
    filt->inputDomain = args.GetInputDomain();
    filt->script = resultKernel.str();

    filt->SetInput(args.GetInput());
    avtDataObject_p dob = filt->GetOutput();
    dob->Update(args.GetContract());

    result = filt->outputdataArray;

    //result.shape.push_back(var->GetDataSize());
    //result.vtkarray = var->NewInstance();
    //result.vtkarray->DeepCopy(var);

    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItForEachLocationPython::GetSignature(std::string& name,
                          stringVector& argnames,
                          std::vector<ScriptVariantTypeEnum>& argtypes)
{
    name = "visit_foreach_location_python";
    argnames.push_back("window");
    argtypes.push_back(ScriptOperation::INT_VECTOR_TYPE);

    argnames.push_back("variableName");
    argtypes.push_back(ScriptOperation::VTK_DATA_ARRAY_TYPE);

    argnames.push_back("kernelName");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("primaryVariable");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("kernelArgs");
    argtypes.push_back(ScriptOperation::VARIANT_VECTOR_TYPE);
    return ScriptOperation::VTK_MULTI_DIMENSIONAL_DATA_ARRAY;
}


bool
avtScriptOperation::avtVisItGetRSupportDirectory::func(ScriptArguments& args, Variant& result)
{
    std::string vlibdir = GetVisItLibraryDirectory() + VISIT_SLASH_CHAR + "r_support";
    std::string vlibrdir  = vlibdir  + VISIT_SLASH_CHAR + "Rscripts" + VISIT_SLASH_CHAR;
    result = vlibrdir;
    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItGetRSupportDirectory::GetSignature(std::string& name,
                          stringVector& argnames,
                          std::vector<ScriptOperation::ScriptVariantTypeEnum>& argtypes)
{
    (void) argnames;
    (void) argtypes;

    name = "visit_get_r_support_dir";

    return ScriptOperation::CONSTANT;
}

bool
avtScriptOperation::avtVisItWriteData::func(ScriptArguments& args,
                                            vtkShapedDataArray& result)
{
    std::string filename = args.getArg(0).AsString();
    std::string format = args.getArg(1).AsString();
    bool local = args.getArg(2).AsString() == "local";
    vtkDataArray* var = (vtkDataArray*)args.getArgAsVoidPtr(3);

    std::cout << "write out file as: "
              << filename
              << " format: "
              << format
              << std::endl;

    result.shape.push_back(1);
    result.vtkarray = var->NewInstance();
    result.vtkarray->DeepCopy(var);

    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItWriteData::GetSignature(std::string& name,
                          stringVector& argnames,
                          std::vector<ScriptOperation::ScriptVariantTypeEnum>& argtypes)
{
    name = "visit_write";

    argnames.push_back("filename");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("format");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("local_or_global");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("variable");
    argtypes.push_back(ScriptOperation::VTK_DATA_ARRAY_TYPE);

    argnames.push_back("index");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    //argnames.push_back("stride");
    //argtypes.push_back(ScriptOperation::STRING_TYPE);

    return ScriptOperation::VTK_MULTI_DIMENSIONAL_DATA_ARRAY;
}

bool
avtScriptOperation::avtVisItMaxAcrossTime::func(ScriptArguments& args, vtkShapedDataArray &result)
{
    cout<<"avtScriptOperation::avtVisItMaxAcrossTime::func()"<<endl;
    cout<<"args= "<<args.getArgSize()<<endl;
    for (int i = 0; i < args.getArgSize(); i++)
	cout<<i<<": "<<endl;
    
    vtkDataArray* var = (vtkDataArray*)args.getArgAsVoidPtr(0);
    //var->Print(cout);
    
    result.shape.push_back(var->GetDataSize());
    result.vtkarray = var->NewInstance();
    result.vtkarray->DeepCopy(var);
    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItMaxAcrossTime::GetSignature(std::string& name,
					stringVector& argnames,
				       	std::vector<ScriptOperation::ScriptVariantTypeEnum>& argtypes)
{
    name = "visit_max_across_time";

    argnames.push_back("variable");
    argtypes.push_back(ScriptOperation::VTK_DATA_ARRAY_TYPE);
    
    return ScriptOperation::VTK_DATA_ARRAY;
}

/// we are always returning true unless the script
/// itself is failing not the inquiry..
bool
avtScriptOperation::avtVisItGetVarInfo::func(ScriptArguments& args, Variant& result)
{
    std::string varName = args.getArg(0).AsString();
    vtkDataSet* dataset = args.GetInputDataSet();
    bool pointData = true;
    vtkDataArray* array = dataset->GetPointData()->GetScalars(varName.c_str());

    if(!array) {
        array = dataset->GetCellData()->GetScalars(varName.c_str());
        pointData = false;
    }

    /// for now just deal with scalars..
    if(array == NULL)
    {
        result = "";
        return true;
    }

    /// now extract information from the array..
    /// through in mesh dimensions to help inquiring class reshape
    /// information correctly..
    JSONNode resultNode;
    resultNode["type"] = pointData ? "pointdata" : "celldata";
    JSONNode::JSONArray dims(3,-1);
    resultNode["dims"] = dims;

    result = resultNode.ToString();

    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItGetVarInfo::GetSignature(std::string& name,
                          stringVector& argnames,
                          std::vector<ScriptVariantTypeEnum>& argtypes)
{
    name = "visit_get_var_info";

    argnames.push_back("variableName");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    return ScriptOperation::CONSTANT;
}

void
avtScriptOperation::RegisterOperations(ScriptManager *manager)
{
    manager->RegisterOperation(&vfel);
    manager->RegisterOperation(&vfelr);
    manager->RegisterOperation(&vfelp);
    manager->RegisterOperation(&vfef);
    manager->RegisterOperation(&avag);
    manager->RegisterOperation(&vgvi);
    manager->RegisterOperation(&vmax);
	manager->RegisterOperation(&avwd);
}
