
#ifndef AVT_R_TMP_FILTER_H
#define AVT_R_TMP_FILTER_H

#include <filters_exports.h>
#include <avtDatasetToDatasetFilter.h>
#include <avtTimeLoopFilter.h>
#include <string>
#include <vector>

class vtkDataSet;
class vtkFloatArray;

class AVTFILTERS_API avtTimeIteratorOperation : virtual public avtDatasetToDatasetFilter,
                                                virtual public avtTimeLoopFilter
{
  public:
    avtTimeIteratorOperation() {operation = -1; initialized=false; output=NULL;}
    virtual ~avtTimeIteratorOperation() {}
    
  protected:
    virtual void Initialize() = 0;

    int operation;
    bool initialized;
    vtkDataSet *outDS;
    vtkFloatArray *output;
};


class avtStratifiedTimeIteratorOperation : public avtTimeIteratorOperation
{
  public:
    avtStratifiedTimeIteratorOperation() {numStrata = -1;}
    ~avtStratifiedTimeIteratorOperation() {}
    
  protected:
    int numStrata;

    virtual void Initialize();
};


class avtMonthlyIteratorOperation : public avtStratifiedTimeIteratorOperation
{
  public:
    avtMonthlyIteratorOperation();
    ~avtMonthlyIteratorOperation() {}

    virtual const char* GetType() {return "avtMonthlyIteratorOperation";}
    
  protected:
    virtual void            Execute();
    virtual void            PreExecute() {}
    virtual void            PostExecute() {}
    virtual void            CreateFinalOutput();
    virtual bool            ExecutionSuccessful() {return true;}
};






#endif AVT_R_TMP_FILTER_H
