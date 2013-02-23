#ifndef SCRIPTOPERATION_H
#define SCRIPTOPERATION_H

#include <vectortypes.h>
#include <Variant.h>

#include <avtDataset.h>
#include <avtDataObject.h>
#include <avtContract.h>


class ScriptOperation
{
public:
    enum ScriptOperationResponse
    {
        VTK_DATA_ARRAY,
        VTK_DATA_SET,
        AVT_DATA_SET
    };

    typedef enum
    {
        EMPTY_TYPE = 0,
        BOOL_TYPE, CHAR_TYPE, UNSIGNED_CHAR_TYPE, INT_TYPE, LONG_TYPE,
        FLOAT_TYPE, DOUBLE_TYPE, STRING_TYPE,
        BOOL_VECTOR_TYPE, CHAR_VECTOR_TYPE, UNSIGNED_CHAR_VECTOR_TYPE,
        INT_VECTOR_TYPE, LONG_VECTOR_TYPE, FLOAT_VECTOR_TYPE,
        DOUBLE_VECTOR_TYPE, STRING_VECTOR_TYPE,
        VTK_DATA_ARRAY_TYPE, VTK_DATASET_ARRAY_TYPE
    } ScriptVariantTypeEnum;

    virtual bool func(avtDataObject_p input,
                      avtContract_p contract,
                      std::vector<Variant>& args,
                      vtkDataArray*& result){ return false; }

    virtual bool func(avtDataObject_p input,
                      avtContract_p contract,
                      std::vector<Variant>& args,
                      vtkDataSet*& result){ return false; }

    virtual bool func(avtDataObject_p input,
                      avtContract_p contract,
                      std::vector<Variant>& args,
                      avtDataset_p& result){ return false; }

    virtual ScriptOperationResponse GetSignature(std::string& name,
                              stringVector& argnames,
                              std::vector<ScriptVariantTypeEnum>& argtypes) = 0;
};

class ScriptManager
{
public:
    virtual void RegisterOperation(ScriptOperation* operation) = 0;
};

#endif
