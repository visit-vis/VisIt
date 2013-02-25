#ifndef SCRIPTOPERATION_H
#define SCRIPTOPERATION_H

#include <vectortypes.h>
#include <MapNode.h>

#include <avtDataset.h>
#include <avtDataObject.h>
#include <avtContract.h>


class ScriptArguments
{
    friend class avtScriptFilter;

    avtDataObject_p input;
    avtContract_p contract;
    std::vector<Variant> args;
    std::map<int,void*> datamap;
public:
    avtDataObject_p GetInput() { return input; }
    avtContract_p GetContract() { return contract; }
    size_t getArgSize() { args.size(); }
    Variant getArg(size_t i) { return args[i]; }

    void* getArgAsVoidPtr(size_t i)
    {
        if(datamap.count(i) > 0)
            return datamap[i];
        else
            return (void*)&args[i];
    }
};

class ScriptOperation;
class ScriptManager
{
public:
    virtual void RegisterOperation(ScriptOperation* operation) = 0;
};

class ScriptOperation
{
public:
    enum ScriptOperationResponse
    {
        CONSTANT,
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

    virtual bool func(ScriptArguments& args,
                      vtkDataArray*& result){ (void) args; (void) result; return false; }

    virtual bool func(ScriptArguments& args,
                      vtkDataSet*& result){  (void) args; (void) result; return false; }

    virtual bool func(ScriptArguments& args,
                      avtDataset_p& result){ (void) args; (void) result; return false; }

    virtual ScriptOperationResponse GetSignature(std::string& name,
                              stringVector& argnames,
                              std::vector<ScriptVariantTypeEnum>& argtypes) = 0;
};

#endif
