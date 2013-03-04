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

#include <avtParallel.h>

class avtTimeLooperFilter : virtual public avtDatasetToDatasetFilter,
			    virtual public avtTimeLoopFilter
{
    /// record which rank has what timesteps and parts of the datasets..
  public:
    avtTimeLooperFilter() {}
    virtual ~avtTimeLooperFilter() {}
    virtual const char* GetType() {return "avtTimeLooperFilter";}

  protected:
    void                    Initialize() {}
    virtual void            Execute()
    {
        int rank = PAR_Rank();
        cout<<"TimeStep: " << rank << " " << currentTime<< " " << GetStartTime() << " " << GetEndTime() << " "
              << GetInput()->GetInfo().GetAttributes().DataIsReplicatedOnAllProcessors() << endl;
    }
    virtual void            CreateFinalOutput()
    {
        cout<<"CreateFinalOutput "<<endl;
        SetOutputDataTree(new avtDataTree());
    }
    virtual bool            ExecutionSuccessful() { return true; }

    virtual bool            FilterSupportsTimeParallelization() { return false; }
    virtual bool            DataCanBeParallelizedOverTime() { return true; }
};


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

//    std::cout << "For Each Location: " << windowArray.ToJSON() << " "
//              << var->GetClassName() << " "
//              << kernelLanguage.AsString() << " "
//              << kernelName.AsString() << " "
//              << primaryVariable.AsString() <<  " "
//              << kernel.AsString() << std::endl;

//    var->Print(cout);
//    for(int i = 0; i < kernelArgs.size(); ++i)
//        std::cout << "arg: " << i << " " << kernelArgs[i].ConvertToString() << std::endl;

    avtDataObject_p input = args.GetInput();
    std::string db = input->GetInfo().GetAttributes().GetFullDBName();
    ref_ptr<avtDatabase> dbp = avtCallback::GetDatabase(db, 0, NULL);
    avtDatabaseMetaData *md = dbp->GetMetaData(0, 1);

    //std::string varname = var->GetName();


//    const doubleVector& vector = md->GetTimes();
////    std::cout << vector.size() << std::endl;
//    for(int i = 0; i < vector.size(); ++i)
//    {
//        dbp = avtCallback::GetDatabase(db, i, NULL);

//        //avtDataObject_p tr = dbp->GetOutput("pressure",0);
//        std::cout << "--> " << i << " " << vector[i] << " " << dbp->GetType() << std::endl;
//        avtDataTree_p tree = dbp->GetDebugDataTree();
//        int numLeaves;
//        vtkDataSet** leaves = tree->GetAllLeaves(numLeaves);

//        std::cout << numLeaves << " " << leaves << std::endl;
//    }
    avtPythonFilterEnvironment* environ = args.GetPythonEnvironment();

    /*
    avtTimeLooperFilter *filt = new avtTimeLooperFilter;
    avtContract_p spec = args.GetContract();
    filt->SetInput(args.GetInput());
    avtDataObject_p dob = filt->GetOutput();
    dob->Update(spec);
    */

    std::string arglist = "";

    for(int i = 0; i < kernelArgs.size(); ++i)
        arglist += kernelArgs[i].ConvertToString() + (i == kernelArgs.size()-1 ? "" : ",");

    if(kernelLanguage == "Python")
        environ->Interpreter()->RunScript(kernel.AsString());
    else
    {
        std::ostringstream rsetup;

        rsetup << "import rpy2, rpy2.robjects\n"
               << kernelName.AsString() <<  " = rpy2.robjects.r(\"\"\"\n"
               << kernel.AsString() << "\n"
               << "\"\"\")\n";
        //std::cout << rsetup.str() << std::endl;
        environ->Interpreter()->RunScript(rsetup.str());
    }

    result = var->NewInstance();
    result->DeepCopy(var);

    size_t size = var->GetDataSize();

    double resultVal = 0;
    for(size_t i = 0; i < size; ++i)
    {
        double val = var->GetTuple1(i);

        std::ostringstream resultKernel;

        resultKernel << "res = " << kernelName.AsString() <<  "(" <<  val;
        if(arglist.size() > 0)
            resultKernel << "," << arglist << ")\n";
        else
            resultKernel << ")\n";
        if(kernelLanguage.AsString() == "R")
            resultKernel << "res = res[0]\n";

        if(i == 0) std::cout << resultKernel.str() << std::endl;
        environ->Interpreter()->RunScript(resultKernel.str());

        PyObject* obj = environ->Interpreter()->GetGlobalObject("res");

        environ->Interpreter()->PyObjectToDouble(obj,resultVal);
        result->SetTuple1(i,resultVal);
    }

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

void
avtScriptOperation::RegisterOperations(ScriptManager *manager)
{
    manager->RegisterOperation(&vfel);
    manager->RegisterOperation(&vfef);
    manager->RegisterOperation(&avag);
}
