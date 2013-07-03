#include <avtTECAScriptOperation.h>

#include "AtmosphericRivers.h"
#include "TropicalCyclone.h"

bool
avtTecaScriptOperation::avtTecaAtmosphericRivers::func(ScriptArguments &args,
                                                       Variant &result)
{
    AtmosphericRivers ar;
    std::cout << "AR Detection code run.." << std::endl;

    ar.SetInput(args.GetInput());

    avtDataObject_p db = ar.GetOutput();
    db->Update(args.GetContract());

    result = true;
    return true;
}


ScriptOperation::ScriptOperationResponse
avtTecaScriptOperation::avtTecaAtmosphericRivers::GetSignature(std::string &name,
                                                               stringVector &argnames,
                                                               std::vector<ScriptVariantTypeEnum> &argtypes)
{
    (void)argnames;
    (void)argtypes;

    name = "visit_ar_detect";

    return ScriptOperation::CONSTANT;
}

bool
avtTecaScriptOperation::avtTecaTropicalCyclones::func(ScriptArguments &args, Variant &result)
{

    std::cout << "tropical cyclones code called" << std::endl;

    TstormsDriver* ts = new TstormsDriver();
    ts->SetInput(args.GetInput());
    avtDataObject_p db = ts->GetOutput();

    db->Update(args.GetContract());

    result = true;
    return true;
}

ScriptOperation::ScriptOperationResponse
avtTecaScriptOperation::avtTecaTropicalCyclones::GetSignature(std::string &name,
                                                              stringVector &argnames,
                                                              std::vector<ScriptVariantTypeEnum> &argtypes)
{
    (void) argnames;
    (void) argtypes;

    name = "visit_tropical_cyclone";

    return ScriptOperation::CONSTANT;
}

void
avtTecaScriptOperation::RegisterOperations(ScriptManager *parent)
{
    /// register teca functions..
    parent->RegisterOperation(&atar);
    parent->RegisterOperation(&attc);
}
