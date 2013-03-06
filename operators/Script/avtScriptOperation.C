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

using namespace std;

class avtTimeWindowLoopFilter : virtual public avtDatasetToDatasetFilter,
				virtual public avtTimeLoopFilter
{
    /// record which rank has what timesteps and parts of the datasets..
  public:
    avtTimeWindowLoopFilter() {initialized = false; }
    virtual ~avtTimeWindowLoopFilter() {}
    virtual const char* GetType() {return "avtTimeWindowLoopFilter";}

    //vector< vector<float> > values;
    vector<float> values;
    vector<int> times;

  protected:
    void                    Initialize();
    virtual void            Execute();
    virtual void            CreateFinalOutput();
    virtual bool            ExecutionSuccessful() { return true; }

    virtual bool            FilterSupportsTimeParallelization() { return true; }
    virtual bool            DataCanBeParallelizedOverTime() { return false; }
    //virtual bool            OperationNeedsAllData(void) { return true; }

    bool initialized, nodeCenteredData;
    int numTuples, idx0, idxN;
  public:
    string script;
    avtPythonFilterEnvironment *environment;
    vtkDataSet* inputDataSet;
    int inputDomain;
};

void
avtTimeWindowLoopFilter::Initialize()
{
    if (initialized)
	return;
    
//    cout<<__FILE__<<" "<<__LINE__<<endl;
//    int nleaves;
//    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);
//    if (nleaves != 1)
//    {
//        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
//    }

    vtkDataSet *inDS = inputDataSet; //leaves[0];
    nodeCenteredData = (GetInput()->GetInfo().GetAttributes().GetCentering() == AVT_NODECENT);
    if (nodeCenteredData)
        numTuples = inDS->GetPointData()->GetScalars()->GetNumberOfTuples();
    else
        numTuples = inDS->GetCellData()->GetScalars()->GetNumberOfTuples();

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
#endif
    cout<<"I have: ["<<idx0<<" "<<idxN<<"]"<<endl;
    //delete [] leaves;

    initialized = true;

    /// values need to be number of tuples * total number of timesteps..
    values.resize((idxN-idx0)*(GetEndTime()-GetStartTime()+1));
}

void
avtTimeWindowLoopFilter::Execute()
{
    //cout<<__FILE__<<" "<<__LINE__<<endl;
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
    for (size_t i = 0; i < numTuples; i++)
    {
        if(i >= idx0 && i < idxN)
        {
            size_t index = rank + (i-idx0)*(numTimes); //0 index then arrange by rank..
            //values.push_back(8640*vals[i]);
            //times.push_back(currentTime);
            values[index] = vals[i];
        }
    }

    /*
    int rank = PAR_Rank();
    cout<<"TimeStep: " << rank << " " << currentTime<< " " << GetStartTime() << " " << GetEndTime() << " "
	<< GetInput()->GetInfo().GetAttributes().DataIsReplicatedOnAllProcessors() << endl;
    */
}

void
avtTimeWindowLoopFilter::CreateFinalOutput()
{
    cout<<"CreateFinalOutput "<<endl;
    cout<<"values= "<<values.size()<<endl;

    //std::cout << GetEndTime() << " " << GetStartTime() << std::endl;
    //std::vector<float> inputArray;

    size_t totalTupleSize = idxN-idx0;

    int numTimes = GetEndTime() - GetStartTime() + 1;
    //inputArray.resize(numTimes);
    PyObject *retval = PyTuple_New(numTimes);

    for (int i = 0; i < totalTupleSize; i++)
    {
        for(int j = 0; j < numTimes; ++j)
        {
            PyObject* value = PyInt_FromLong(values[(i*(numTimes))+j]);
            PyTuple_SET_ITEM(retval, j, value);
        }

        environment->Interpreter()->SetGlobalObject(retval,"__internal_array");
        environment->Interpreter()->RunScript(script);
    }

    SetOutputDataTree(new avtDataTree(inputDataSet,inputDomain));
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
avtScriptOperation::avtVisItForEachLocation::func(ScriptArguments& args, vtkDataArray*&result)
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

    if(kernelLanguage.AsString() == "R")
        resultKernel << "res = res[0]\n";


    std::cout << resultKernel.str() << std::endl;
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

    result = var->NewInstance();
    result->DeepCopy(var);

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
    return ScriptOperation::VTK_DATA_ARRAY;
}


bool
avtScriptOperation::avtVisItForEachLocationR::func(ScriptArguments& args, vtkDataArray*&result)
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

    resultKernel << "res = res[0]\n";

    /// run the time loop filter..

    avtTimeWindowLoopFilter *filt = new avtTimeWindowLoopFilter;
    filt->environment = args.GetPythonEnvironment();
    filt->inputDataSet = args.GetInputDataSet();
    filt->inputDomain = args.GetInputDomain();
    filt->script = resultKernel.str();

    filt->SetInput(args.GetInput());
    avtDataObject_p dob = filt->GetOutput();

    dob->Update(args.GetContract());

    result = var->NewInstance();
    result->DeepCopy(var);

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
    return ScriptOperation::VTK_DATA_ARRAY;
}

bool
avtScriptOperation::avtVisItForEachLocationPython::func(ScriptArguments& args, vtkDataArray*&result)
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

    result = var->NewInstance();
    result->DeepCopy(var);

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
    return ScriptOperation::VTK_DATA_ARRAY;
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
avtScriptOperation::avtVisItWriteToDisk::func(ScriptArguments& args, Variant& result)
{
    std::string vlibdir = GetVisItLibraryDirectory() + VISIT_SLASH_CHAR + "r_support";
    std::string vlibrdir  = vlibdir  + VISIT_SLASH_CHAR + "Rscripts" + VISIT_SLASH_CHAR;
    result = vlibrdir;
    return true;
}

ScriptOperation::ScriptOperationResponse
avtScriptOperation::avtVisItWriteToDisk::GetSignature(std::string& name,
                          stringVector& argnames,
                          std::vector<ScriptOperation::ScriptVariantTypeEnum>& argtypes)
{
    name = "visit_write";

    argnames.push_back("filename");
    argtypes.push_back(ScriptOperation::INT_VECTOR_TYPE);

    argnames.push_back("variable");
    argtypes.push_back(ScriptOperation::VTK_DATA_ARRAY_TYPE);

    argnames.push_back("index");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("stride");
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
}
