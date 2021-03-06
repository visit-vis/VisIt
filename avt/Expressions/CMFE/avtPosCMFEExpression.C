/*****************************************************************************
*
* Copyright (c) 2000 - 2015, Lawrence Livermore National Security, LLC
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
//                           avtPosCMFEExpression.C                          //
// ************************************************************************* //

#include <avtPosCMFEExpression.h>

#include <avtPosCMFEAlgorithm.h>


// ****************************************************************************
//  Method: avtPosCMFEExpression constructor
//
//  Purpose:
//      Defines the constructor.  Note: this should not be inlined in the
//      header because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   October 11, 2005
//
// ****************************************************************************

avtPosCMFEExpression::avtPosCMFEExpression()
{
    ;
}


// ****************************************************************************
//  Method: avtPosCMFEExpression destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   October 11, 2005
//
// ****************************************************************************

avtPosCMFEExpression::~avtPosCMFEExpression()
{
    ;
}


// ****************************************************************************
//  Method: avtPosCMFEExpression::PerformCMFE
//
//  Purpose:
//      Performs a cross-mesh field evaluation based on position-based 
//      differencing.
//
//  Programmer: Hank Childs
//  Creation:   October 11, 2005
// 
//  Modifications:
//
//    Hank Childs, Sat Jan 21 12:56:57 PST 2006
//    Re-wrote to use avtPosCMFEAlgorithm.
//
//    Hank Childs, Tue Mar 13 11:16:24 PDT 2012
//    Return early if we were given a SIL with no data.  
//
//    Hank Childs, Wed Mar 14 08:47:56 PDT 2012
//    Determine if we should run in a "serial-only" mode.
//
//    David Camp, Wed Mar 15 08:47:56 PDT 2012
//    Change the emtpy data to return an avtDataTree_p object.
//
// ****************************************************************************

avtDataTree_p
avtPosCMFEExpression::PerformCMFE(avtDataTree_p output_mesh,
                                  avtDataTree_p mesh_to_be_sampled,
                                  const std::string &invar,
                                  const std::string &outvar)
{
    if (!onDemandProcessing && !initialSILHasData)
    {
        // This is empty data, just return an empty tree.
        avtDataTree_p rv = new avtDataTree();
        return rv;
    }

    bool serialOnly = onDemandProcessing;
    return avtPosCMFEAlgorithm::PerformCMFE(output_mesh, mesh_to_be_sampled,
                                            invar, varnames[1], outvar,
                                            serialOnly);
}


// ****************************************************************************
//  Method:  avtPosCMFEAlgorithm::FilterUnderstandsTransformedRectMesh
//
//  Purpose:
//    If this filter returns true, this means that it correctly deals
//    with rectilinear grids having an implied transform set in the
//    data attributes.  It can do this conditionally if desired.
//
//  Arguments:
//    none
//
//  Programmer:  Jeremy Meredith
//  Creation:    February 15, 2007
//
//  Note:
//    Report explicitly that this filter does NOT understand transformed
//    rectilinear grids.  This method should default to returning false
//    anyway, but there are specific reasons this filter cannot yet be
//    optimized in this fashion, so ensure that even if other CMFE's change
//    to default to true, this one remains false until it can be fixed.
//
// ****************************************************************************

bool
avtPosCMFEExpression::FilterUnderstandsTransformedRectMesh()
{
    // This avtPosCMFEAlgorithm is not optimized for transformed
    // rectilinear grids.  Furthermore, it calls a form of
    // avtDatasetExaminer::GetSpatialExtents that also does not
    // understand these transformed rectilinear grids.  These
    // both must be fixed before this can return 'true'.
    return false;
}
