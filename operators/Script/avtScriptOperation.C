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

avtScriptOperation::avtScriptOperation()
{}


bool
avtScriptOperation::avtVisItForEachLocation::func(ScriptArguments& args, vtkDataArray*&result)
{
    Variant windowArray = args.getArg(0);
    vtkDataArray* var = (vtkDataArray*)args.getArgAsVoidPtr(1);
    Variant kernelLanguage = args.getArg(2); //R or Python
    Variant kernelName = args.getArg(3); //name of the function to call..
    Variant kernel = args.getArg(4); //kernel itself
    Variant primaryVariable = args.getArg(5); // primary variable name to modify..

    std::vector<Variant> kernelArgs = args.getArgAsVariantVector(6);

    std::cout << "For Each Location: " << windowArray.ToJSON() << " "
              << var->GetClassName() << " "
              << kernelLanguage.AsString() << " "
              << kernelName.AsString() << " "
              << primaryVariable.AsString() <<  " "
              << kernel.AsString() << std::endl;

    for(int i = 0; i < kernelArgs.size(); ++i)
        std::cout << "arg: " << i << " " << kernelArgs[i].ToJSON() << std::endl;

//    avtPythonFilterEnvironment* environ = args.GetPythonEnvironment();

    //run python code or R code (using rpy2)..

//    if(std::string(var->GetClassName()) != "vtkFloatArray") return false;

//    vtkIdType size = var->GetDataSize();
//    float* floatArray = (float*) var->GetVoidPointer(0);

//    std::string primaryVar = primaryVariable.AsString();

//    std::string arglist = "";
//    for(int i = 0; i < kernelArgs.size(); ++i)
//        arglist += kernelArgs[i].AsString() + (kernelArgs.size() == i-1 ? "" : ",");

//    /// TODO: fix for arglist is empty

//    //environ->Interpreter()->RunScript(kernel.AsString());


//    for(int i = 0; i < size; ++i)
//    {
//        float val = floatArray[i];
//        std::ostringstream result;
//        result << kernelName.AsString() <<  "(" <<  primaryVar <<  "=" <<  val << "," << arglist << ")";
//        std::cout << result << std::endl;
//    }

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

    argnames.push_back("kernelName");
    argtypes.push_back(ScriptOperation::STRING_TYPE);

    argnames.push_back("kernel");
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
