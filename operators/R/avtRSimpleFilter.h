#ifndef AVT_R_SIMPLE_FILTER_H
#define AVT_R_SIMPLE_FILTER_H

#include <filters_exports.h>
#include <avtDatasetToDatasetFilter.h>
#include <avtTimeLoopFilter.h>
#include <string>
#include <vector>

class vtkDataSet;

// ****************************************************************************
// Class:  avtRSimpleFilter
//
//
// Programmer:  Dave Pugmire
// Creation:    February  7, 2012
//
// ****************************************************************************

class AVTFILTERS_API avtRSimpleFilter : virtual public avtDatasetToDatasetFilter,
                                        virtual public avtTimeLoopFilter
{
  public:
    avtRSimpleFilter();
    virtual ~avtRSimpleFilter();
    virtual const char* GetType() {return "avtRSimpleFilter";}

    float cutoff, percentile;
    std::string rscript;

  protected:
    void                    Initialize();
    virtual void            Execute();
    virtual void            PreExecute();
    virtual void            PostExecute();
    virtual void            CreateFinalOutput();
    virtual bool            ExecutionSuccessful();

    virtual bool            FilterSupportsTimeParallelization();
    virtual bool            DataCanBeParallelizedOverTime(void);

    float                   CalculateThreshold(int loc);

    vtkDataSet *outDS;
    int numTuples;
    bool nodeCenteredData, initialized;
    int idx0, idxN;

    std::vector<std::vector<float> > values;
};

#endif
