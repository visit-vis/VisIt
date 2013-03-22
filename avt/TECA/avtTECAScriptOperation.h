#ifndef AVT_TECA_SCRIPT_OPERATION_H
#define AVT_TECA_SCRIPT_OPERATION_H

#include <teca_exports.h>
#include <ScriptOperation.h>

class TECA_API avtTecaScriptOperation : virtual public ScriptOperationsManager
{
public:

    class avtTecaAtmosphericRivers : virtual public ScriptOperation
    {
    public:
        bool
        func(ScriptArguments &args, Variant &result);

        ScriptOperation::ScriptOperationResponse
        GetSignature(std::string &name,
                     stringVector &argnames,
                     std::vector<ScriptVariantTypeEnum> &argtypes);
    };

    class avtTecaTropicalCyclones : public ScriptOperation
    {
    public:
        virtual bool func(ScriptArguments &args, Variant &result);
        virtual ScriptOperationResponse GetSignature(std::string &name,
                                                     stringVector &argnames,
                                                     std::vector<ScriptVariantTypeEnum> &argtypes);
    };

public:
    virtual void RegisterOperations(ScriptManager *parent);


private:
    avtTecaAtmosphericRivers atar;
    avtTecaTropicalCyclones attc;
};


#endif
