
#ifndef AVT_R_TMP_FILTER_H
#define AVT_R_TMP_FILTER_H

#include <filters_exports.h>
#include <avtDatasetToDatasetFilter.h>
#include <avtTimeLoopFilter.h>
#include <string>
#include <vector>

class vtkDataSet;
class vtkFloatArray;

using namespace std;

#define MIN_OPERATOR 1
#define MAX_OPERATOR 2

class AVTFILTERS_API avtTimeIteratorOperation : virtual public avtDatasetToDatasetFilter,
                                                virtual public avtTimeLoopFilter
{
  public:
    avtTimeIteratorOperation() {operation = -1; initialized=false; output=NULL;}
    virtual ~avtTimeIteratorOperation() {}

    int operation;
    
  protected:
    virtual void Initialize() = 0;
    virtual void OperationInit() = 0;

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
    virtual void OperationInit();
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


class avtMonthlyExceedencesOperation : public avtStratifiedTimeIteratorOperation
{
  public:
    avtMonthlyExceedencesOperation();
    virtual ~avtMonthlyExceedencesOperation() {}

    virtual const char* GetType() {return "avtMonthlyExceedencesOperation";}

  protected:
    virtual void Initialize();
    virtual void            Execute();
    virtual void            PreExecute() {}
    virtual void            PostExecute() {}
    virtual void            CreateFinalOutput();
    virtual bool            ExecutionSuccessful() {return true;}

    //strata, loc, vals
    vector<vector<vector<float> > > vals;
    
};



class avtOpOverTimeFilter : public avtTimeIteratorOperation
{
  public:
    avtOpOverTimeFilter();
    virtual ~avtOpOverTimeFilter() {}
    virtual const char* GetType() {return "avtMaxOverTimeFilter";}
    
  protected:
    virtual void OperationInit();

    virtual void Initialize();
    virtual void Execute();
    virtual void PreExecute() {}
    virtual void PostExecute() {}
    virtual void CreateFinalOutput();
    virtual bool ExecutionSuccessful() {return true;}
};


class avtRScriptWithArgsFilter : public avtDatasetToDatasetFilter
{
  public:
    avtRScriptWithArgsFilter();
    virtual ~avtRScriptWithArgsFilter() {}
    virtual const char* GetType() {return "avtRScriptOneArgFilter";}
    
    vector<float> arguments;
    vector<string> argNames;
    string inputName, outputName;

    string rcode;

  protected:
    void Execute();


    vtkDataSet *outDS;
    vtkFloatArray *output;
};





#endif AVT_R_TMP_FILTER_H
