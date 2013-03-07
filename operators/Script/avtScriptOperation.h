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
//  File: avtScriptOperation.h
// ************************************************************************* //

#ifndef AVT_SCRIPT_OPERATION_H
#define AVT_SCRIPT_OPERATION_H

#include <ScriptOperation.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkImageData.h>
/// class to provide default script operations..
class avtScriptOperation : public ScriptOperationsManager
{
    class avtVisItForEachLocation : public ScriptOperation
    {
    public:
        virtual bool func(ScriptArguments&, vtkDataArray*& result);

        virtual ScriptOperationResponse GetSignature(std::string& name,
                                  stringVector& argnames,
                                  std::vector<ScriptVariantTypeEnum>& argtypes);
    };

    class avtVisItForEachLocationR : public ScriptOperation
    {
    public:
        virtual bool func(ScriptArguments&, vtkDataArray*& result);

        virtual ScriptOperationResponse GetSignature(std::string& name,
                                  stringVector& argnames,
                                  std::vector<ScriptVariantTypeEnum>& argtypes);
    };

    class avtVisItForEachLocationPython : public ScriptOperation
    {
    public:
        virtual bool func(ScriptArguments&, vtkDataArray*& result);

        virtual ScriptOperationResponse GetSignature(std::string& name,
                                  stringVector& argnames,
                                  std::vector<ScriptVariantTypeEnum>& argtypes);
    };



    class avtVisItForEachFile : public ScriptOperation
    {
    public:
        virtual bool func(ScriptArguments&, vtkDataArray*&)
        {
            return false;
        }

        virtual ScriptOperationResponse GetSignature(std::string& name,
                                  stringVector& argnames,
                                  std::vector<ScriptVariantTypeEnum>& argtypes)
        {
            name = "visit_foreach_file";
            return ScriptOperation::VTK_DATA_ARRAY;
        }
    };

    class avtVisItGetRSupportDirectory : public ScriptOperation
    {
        virtual bool func(ScriptArguments&, Variant&);

        virtual ScriptOperationResponse GetSignature(std::string& name,
                                  stringVector& argnames,
                                  std::vector<ScriptVariantTypeEnum>& argtypes);
    };

    class avtVisItGetVarInfo : public ScriptOperation
    {
        /// we are always returning true unless the script
        /// itself is failing not the inquiry..
        virtual bool func(ScriptArguments& args, Variant& result)
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

        virtual ScriptOperationResponse GetSignature(std::string& name,
                                  stringVector& argnames,
                                  std::vector<ScriptVariantTypeEnum>& argtypes)
        {
            name = "visit_get_var_info";

            argnames.push_back("variableName");
            argtypes.push_back(ScriptOperation::STRING_TYPE);

            return ScriptOperation::CONSTANT;
        }
    };

    class avtVisItWriteData : public ScriptOperation
    {
        virtual bool func(ScriptArguments &args,
                          vtkShapedDataArray& result);

        virtual ScriptOperationResponse GetSignature(std::string& name,
                                  stringVector& argnames,
                                  std::vector<ScriptVariantTypeEnum>& argtypes);
    };
public:
    avtScriptOperation();
    void RegisterOperations(ScriptManager* manager);
private:
    /// visit foreach location variations..
    avtVisItForEachLocation vfel;
    avtVisItForEachLocationR vfelr;
    avtVisItForEachLocationPython vfelp;

    avtVisItForEachFile vfef;
    avtVisItGetRSupportDirectory avag;

    avtVisItGetVarInfo vgvi;
};

#endif
