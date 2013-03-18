/*****************************************************************************
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
*****************************************************************************/

// ************************************************************************* //
//                             avtTECAFilter.h                               //
// ************************************************************************* //

#ifndef AVT_TECA_FILTER_H
#define AVT_TECA_FILTER_H

#include <teca_exports.h>

#include <avtDataTreeIterator.h>
#include <avtTECA.h>
#include <avtTimeLoopFilter.h>


// ****************************************************************************
//  Class: avtTECAFilter
//
//  Purpose:
//    A filter that utilizes the TECA system developed by Oliver Ruebel and 
//    Prabhat.
//
//  Programmer: Hank Childs
//  Creation:   February 27, 2012
//
// ****************************************************************************

class TECA_API avtTECAFilter : public avtTimeLoopFilter,
                                     public avtDataTreeIterator, 
                                     public avtTECA
{
  public:
    avtTECAFilter();
    virtual                  ~avtTECAFilter();

    virtual const char       *GetType(void)   { return "avtTECAFilter"; }
    virtual const char       *GetDescription(void)
                                  { return "Apply TECA as a filter"; }

  protected:
    virtual vtkDataSet       *ExecuteData(vtkDataSet *, int, std::string);
    virtual void              PreExecute(void);
    virtual void              UpdateDataObjectInfo(void);
    virtual void              ReleaseData(void);
    virtual avtContract_p     ModifyContract(avtContract_p);

    virtual bool              FilterSupportsTimeParallelization(void) { return true; }
    virtual bool              DataCanBeParallelizedOverTime(void) { return true; }
    virtual bool              OperationNeedsAllData(void) { return false; }

    virtual void              CreateFinalOutput(void);
    virtual bool              ExecutionSuccessful(void) { return true; }

    virtual void              SetupAVTOutput();
    virtual avtDataTree_p     CreateOutput() = 0;

    virtual bool              GetData(int timestep, size_t *start, size_t* count, void* data) { return true; }
//    if ((retval = nc_get_var1_double (ncid, lon_varid, index, &lon_val)))
    virtual double              GetLongVal(int timestep, size_t index[2], double& lon_val) { return 0; }
    virtual double              GetLatVal(int timestep, size_t index[2], double& lat_val) { return 0; }
};


#endif


