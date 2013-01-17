#include <avtTMP.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkFloatArray.h>
#include <avtDatabaseMetaData.h>


void
avtStratifiedTimeIteratorOperation::Initialize()
{
    if (initialized)
        return;

    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);

    if (nleaves != 1)
    {
        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
    }

    vtkDataSet *inDS = leaves[0];
    int numTuples;
    bool nodeCenteredData = (GetInput()->GetInfo().GetAttributes().GetCentering() == AVT_NODECENT);
    if (nodeCenteredData)
        numTuples = inDS->GetPointData()->GetScalars()->GetNumberOfTuples();
    else
        numTuples = inDS->GetCellData()->GetScalars()->GetNumberOfTuples();
    cout<<"NODE = "<<nodeCenteredData<<endl;


    outDS = (vtkDataSet *)(inDS->NewInstance());
    outDS->CopyStructure(inDS);
    
    output = vtkFloatArray::New();
    output->SetNumberOfComponents(numStrata);
    output->SetNumberOfTuples(numTuples);
    
    if (nodeCenteredData)
        outDS->GetPointData()->SetScalars(output);
    else
        outDS->GetPointData()->SetScalars(output);


    cout<<"avtStratifiedTimeIteratorOperation::Initialize(): numStrata = "<<numStrata<<endl;
    initialized = true;
}

avtMonthlyIteratorOperation::avtMonthlyIteratorOperation()
{
    numStrata = 12;
}


void
avtMonthlyIteratorOperation::Execute()
{
    Initialize();
    
    int nleaves;
    vtkDataSet **leaves = GetInputDataTree()->GetAllLeaves(nleaves);
    vtkDataSet *ds = leaves[0];
    vtkFloatArray *scalars = NULL;
    if (nleaves != 1)
    {
        EXCEPTION1(ImproperUseException, "Multi-domain not supported yet.");
    }
    
    bool nodeCenteredData = true;

    if (nodeCenteredData)
        scalars = (vtkFloatArray *)ds->GetPointData()->GetScalars();
    else
        scalars = (vtkFloatArray *)ds->GetCellData()->GetScalars();
    float *vals = (float *) scalars->GetVoidPointer(0);

    int numTuples = scalars->GetNumberOfTuples();

    int strata = currentTime % numStrata;
    
    for (int i = 0; i < numTuples; i++)
        output->SetComponent(i, strata, vals[i] > 1.0);

    cout<<"Execute"<<endl;

}

void
avtMonthlyIteratorOperation::CreateFinalOutput()
{
    cout<<"CreateFinalOutput"<<endl;
    avtDataTree_p outputTree = new avtDataTree(outDS, 0);
    SetOutputDataTree(outputTree);
    outDS->Delete();
    
    outDS->Print(cout);
}
