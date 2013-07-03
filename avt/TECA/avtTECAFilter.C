/******************************************************************************
*
* Copyright (c) 2000 - 2011, Lawrence Livermore National Security, LLC
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
******************************************************************************/

// ************************************************************************* //
//                             avtTECAFilter.C                               //
// ************************************************************************* //

#include <avtTECAFilter.h>

#include <DebugStream.h>
#include <ImproperUseException.h>

#include <string.h>

#include <avtParallel.h>

//int cuErrOpts = 2; ///CU_VERBOSE
//int cuErrorOccurred = 0;

// ****************************************************************************
//  Method: avtTECAFilter constructor
//
//  Programmer: Hank Childs
//  Creation:   February 27, 2012
//
//  Modifications:
//
// ****************************************************************************

avtTECAFilter::avtTECAFilter()
{
}


// ****************************************************************************
//  Method: avtTECAFilter destructor
//
//  Programmer: Hank Childs
//  Creation:   February 27, 2012
//
//  Modifications:
//
// ****************************************************************************

avtTECAFilter::~avtTECAFilter()
{
}

bool
avtTECAFilter::RankOwnsTimeSlice(int t)
{
    return (t % PAR_Size() == PAR_Rank());

    /// loop over times > t and return true..
}

// ****************************************************************************
//  Method: avtTECAFilter::ExecuteData
//
//  Purpose:
//    Takes in an input dataset and passes it to TECA for processing.
//
//  Arguments:
//      inDS      The input dataset.
//      <unused>  The domain number.
//      <unused>  The label.
//
//  Returns:      The output dataset.
//
//  Programmer: Hank Childs
//  Creation:   February 27, 2012
//
// ****************************************************************************
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
vtkDataSet *
avtTECAFilter::ExecuteData(vtkDataSet *inDS, int, std::string)
{
    indtime = GetInput()->GetInfo().GetAttributes().GetTime();

    int times = 0;

    std::cout << currentTime << std::endl;
    indataset[currentTime] = inDS;
//    indataset[currentTime+1] = inDS;
//    indataset[currentTime+2] = inDS;

    ExecuteProcess();

    indataset.clear();
//    //inDS->Register(NULL);
//    vtkDataSet* dataset = inDS->NewInstance();
//    dataset->DeepCopy(inDS);
    return inDS;
}


// ****************************************************************************
//  Method: avtTECAFilter::UpdateDataObjectInfo
//
//  Purpose:
//      Not clear yet.
//
//  Programmer: Hank Childs
//  Creation:   February 27, 2012
//
// ****************************************************************************

void
avtTECAFilter::UpdateDataObjectInfo(void)
{
}


// ****************************************************************************
//  Method: avtTECAFilter::ModifyContract
//
//  Purpose:  
//      Set up a contract from the variables TECA needs.
// 
//  Programmer: Hank Childs
//  Creation:   February 27, 2012
//
// ****************************************************************************

avtContract_p
avtTECAFilter::ModifyContract(avtContract_p spec)
{
/*
    cerr << "Should be calling GetVariables and dealing with ghost time slices"
         << endl;
 */
    avtDataRequest_p ds = spec->GetDataRequest();

    // set this so we can use the name in exec data
    std::string primaryVariable = std::string(ds->GetVariable());
    //cout <<PAR_Rank() << ": primaryVariable = " << primaryVariable <<endl;
        //
        // Make a new one
        //
    avtDataRequest_p nds = new avtDataRequest(ds);

    /// get all the requested information..
    InitializeAnalysis();

    int n_vars          = vars.size();
    // process all vars
    for(int i = 0; i < n_vars ; i++)
    {
        std::string var_str = vars[i];
        if (primaryVariable != var_str && var_str != std::string("default") &&
                var_str != "lat" && var_str != "lon")
        {
            cout << "Adding \"" << var_str << "\" as secondary var" <<endl;
            nds->AddSecondaryVariable(var_str.c_str());
        }
    }

    //
    // Create the new pipeline spec from the data spec, and return
    //
    avtContract_p rv = new avtContract(spec, nds);
    //rv->SetReplicateSingleDomainOnAllProcessors(true);
    return rv;
}


// ****************************************************************************
//  Method: avtTECAFilter::CreateFinalOutput
//
//  Purpose:
//
//  Programmer: Hank Childs
//  Creation:   February 27, 2012
//
// ****************************************************************************

void
avtTECAFilter::CreateFinalOutput(void)
{
    FinalizeAnalysis();
}


void 
avtTECAFilter::PreExecute(void)
{
    //SetNumberOfTimesteps(GetNumberOfTimeSlices());
}


void
avtTECAFilter::ReleaseData(void)
{
    avtTimeLoopFilter::ReleaseData();
    avtDataTreeIterator::ReleaseData();
}


void
avtTECAFilter::SetupAVTOutput()
{
    //avtDataTree_p tree = CreateOutput();
    //SetOutputDataTree(tree);
}

#include <vtkRectilinearGrid.h>
#include <vtkImageData.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkDataArray.h>
bool
avtTECAFilter::GetLatVal(int timestep, size_t index[2], double &lat_val)
{
    if(indataset.count(timestep) == 0)
        return false;

    vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(indataset[timestep]);

    if(!grid)
        return false;

    vtkDataArray* lat = grid->GetXCoordinates();

    if(index[0] == index[1])
        lat_val = lat->GetTuple1(index[0]);
    else
    {    lat_val = lat->GetTuple1(index[0]);
        //for(int i = index[0],j = 0; i < index[1]; ++i, ++j)
        //    lat_val[j] = lat->GetTuple1(i);
    }
    return true;
}



bool
avtTECAFilter::GetLongVal(int timestep, size_t index[2], double &lon_val)
{
    if(indataset.count(timestep) == 0)
        return false;


    vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(indataset[timestep]);

    if(!grid)
        return false;

    vtkDataArray* lon = grid->GetYCoordinates();

//    for(int i = index[0],j = 0; i < index[1]; ++i, ++j)
//        lon_val[j] = lon->GetTuple1(i);

    if(index[0] == index[1])
        lon_val = lon->GetTuple1(index[0]);
    else
    {    lon_val = lon->GetTuple1(index[0]);
        //for(int i = index[0],j = 0; i < index[1]; ++i, ++j)
        //    lat_val[j] = lat->GetTuple1(i);
    }

    return true;
}

float *avtTECAFilter::GetLatValues(int timestep, size_t& lat_values)
{
    if(indataset.count(timestep) == 0)
        return NULL;
    vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(indataset[timestep]);

    if(!grid)
        return NULL;

    vtkDataArray* lat = grid->GetXCoordinates();

    //std::cout << lat->GetClassName() << std::endl;
    lat_values = lat->GetDataSize();
    return (float*)lat->GetVoidPointer(0);
}

float*
avtTECAFilter::GetLatValues(int timestep, intVector& lat_values)
{
    if(indataset.count(timestep) == 0)
        return NULL;
    vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(indataset[timestep]);

    if(!grid)
        return NULL;

    vtkDataArray* lat = grid->GetXCoordinates();

    lat_values.clear();
    int dim[3];
    grid->GetDimensions(dim);
    for(int i = 0; i < 3; ++i)
        lat_values.push_back(dim[i]);

    return (float*)lat->GetVoidPointer(0);
}

float*
avtTECAFilter::GetLongValues(int timestep, size_t &long_values)
{
    if(indataset.count(timestep) == 0)
        return NULL;

    vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(indataset[timestep]);

    if(!grid)
        return NULL;

    vtkDataArray* lon = grid->GetYCoordinates();
    long_values = lon->GetDataSize();


    //std::cout << lon->GetClassName() << std::endl;
    return (float*)lon->GetVoidPointer(0);
}

float*
avtTECAFilter::GetLongValues(int timestep, intVector &long_values)
{
    if(indataset.count(timestep) == 0)
        return NULL;

    vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(indataset[timestep]);

    if(!grid)
        return NULL;

    vtkDataArray* lon = grid->GetYCoordinates();

    long_values.clear();
    int dim[3];
    grid->GetDimensions(dim);
    for(int i = 0; i < 3; ++i)
        long_values.push_back(dim[i]);

    return (float*)lon->GetVoidPointer(0);

}


bool avtTECAFilter::GetData(const char* varname, int timestep, size_t *start, size_t* count, void* data)
{
//    intVector shape;
//    void* tmpdata = GetData(varname,timestep,shape);

//    if(tmpdata == NULL)
//        return NULL;

//    return NULL;
}

void*
avtTECAFilter::GetData(const char* varname, int timestep, intVector& shape)
{
    if(indataset.count(timestep) == 0)
        return NULL;

    vtkRectilinearGrid* grid = vtkRectilinearGrid::SafeDownCast(indataset[timestep]);

    if(!grid)
        return NULL;

    shape.clear();
    int dim[3];
    grid->GetDimensions(dim);
    for(int i = 0; i < 3; ++i)
        shape.push_back(dim[i]);

    if(std::string(varname) == "lon")
    {
        float* res = GetLongValues(timestep,shape);
        if(!res) return NULL;

        return res;
    }
    else if(std::string(varname) == "lat")
    {
        float* res = GetLatValues(timestep,shape);
        if(!res) return NULL;

        return res;
    }
    else
    {
        vtkDataSet* dataset = indataset[timestep];
        vtkDataArray* array = dataset->GetPointData()->GetArray(varname);
        if(!array)
            array = dataset->GetCellData()->GetArray(varname);

        if(!array) return NULL;

        //std::cout << array->GetClassName() << std::endl;
        return array->GetVoidPointer(0);
    }

    return NULL;
}

