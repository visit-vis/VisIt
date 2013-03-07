#ifndef SCRIPTOPERATION_H
#define SCRIPTOPERATION_H

#include <vectortypes.h>
#include <MapNode.h>

#include <avtDataset.h>
#include <avtDataObject.h>
#include <avtContract.h>


class avtPythonFilterEnvironment;

/// a shaped VTK DataArray
struct vtkShapedDataArray
{
    intVector shape;
    vtkDataArray* vtkarray;
};

class ScriptArguments
{
    friend class avtScriptFilter;
public:
    avtPythonFilterEnvironment* pythonFilter;
    avtDataObject_p input;
    avtContract_p contract;
    vtkDataSet* input_mesh;
    int input_domain;

    std::vector<Variant> args; ///simplest case..

    std::map<int,void*> datamap; /// unknown case..

    /// dataArray with shape information..
    /// I am really trying to avoid bringing in the NUMPY API
    /// but if this does not work then I will pursue that route..
    std::map<int,vtkShapedDataArray> dataArrayMap;

    std::map<int, std::vector<Variant> > variantVector;

    /// functions..
    int GetInputDomain() { return input_domain; }
    vtkDataSet* GetInputDataSet() { return input_mesh; }
    avtPythonFilterEnvironment* GetPythonEnvironment() { return pythonFilter; }
    avtDataObject_p GetInput() { return input; }
    avtContract_p GetContract() { return contract; }
    size_t getArgSize() { args.size(); }
    Variant getArg(size_t i) { return args[i]; }

    void* getArgAsVoidPtr(size_t i)
    {
        if(datamap.count(i) > 0)
            return datamap[i];
        return (void*)&args[i];
    }

    std::vector<Variant> getArgAsVariantVector(int i)
    {
        if(variantVector.count(i) > 0)
            return variantVector[i];

        std::vector<Variant> tmp;
        tmp.push_back(args[i]);
        return tmp;
    }
};

class ScriptOperation;
class ScriptManager
{
public:
    virtual void RegisterOperation(ScriptOperation* operation) = 0;
};

class ScriptOperationsManager
{
public:
    virtual void RegisterOperations(ScriptManager* parent) = 0;
};

class ScriptOperation
{
public:
    enum ScriptOperationResponse
    {
        CONSTANT,
        VTK_DATA_ARRAY,
        VTK_MULTI_DIMENSIONAL_DATA_ARRAY,
        VTK_DATASET,
        AVT_DATA_SET
    };

    /// TODO: I really want to use the Variant/MapNode class here
    /// but I also need an ability to return VTK_DATA_ARRAY_TYPE as an option..
    /// not sure how I am going to honor vtkDataSets from R?
    typedef enum
    {
        EMPTY_TYPE = 0,
        BOOL_TYPE, CHAR_TYPE, UNSIGNED_CHAR_TYPE, INT_TYPE, LONG_TYPE,
        FLOAT_TYPE, DOUBLE_TYPE, STRING_TYPE,
        BOOL_VECTOR_TYPE, CHAR_VECTOR_TYPE, UNSIGNED_CHAR_VECTOR_TYPE,
        INT_VECTOR_TYPE, LONG_VECTOR_TYPE, FLOAT_VECTOR_TYPE,
        DOUBLE_VECTOR_TYPE, STRING_VECTOR_TYPE, VARIANT_TYPE, VARIANT_VECTOR_TYPE,
        VTK_DATA_ARRAY_TYPE, VTK_DATASET_TYPE, VTK_AVTDATASET_TYPE
    } ScriptVariantTypeEnum;

    //DRP. Return type based methods....
    virtual bool func(ScriptArguments& args,
                      Variant& result){ (void) args; (void) result; return false; }

    virtual bool func(ScriptArguments& args,
                      vtkShapedDataArray& result){ (void) args; (void) result; return false; }

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
