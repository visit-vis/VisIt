/*****************************************************************************
*
* Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400142
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
//                        avtMultipleInputExpressionFilter.h                 //
// ************************************************************************* //

#ifndef AVT_MULTIPLE_INPUT_EXPRESSION_FILTER_H
#define AVT_MULTIPLE_INPUT_EXPRESSION_FILTER_H

#include <expression_exports.h>

#include <avtExpressionDataTreeIterator.h>


// ****************************************************************************
//  Class: avtMultipleInputExpressionFilter
//
//  Purpose:
//      A filter that performs a calculation on multiple variables.
//
//  Programmer: Sean Ahern
//  Creation:   Fri Jun 14 17:57:37 PDT 2002
//
//  Modifications:
//
//    Hank Childs, Fri Sep 19 15:20:35 PDT 2003
//    Add destructor.
//
//    Hank Childs, Mon Dec 27 10:37:15 PST 2004
//    Changed inheritance from avtExpressionFilter to avtExpressionDataTreeIterator.
//
//    Hank Childs, Thu Jan  6 11:00:35 PST 2005
//    Added MixedCenteringYieldsZonal method to give derived types a hook into
//    altering behavior of IsPointVariable.
//
// ****************************************************************************

class EXPRESSION_API avtMultipleInputExpressionFilter 
    : virtual public avtExpressionDataTreeIterator
{
  public:
                              avtMultipleInputExpressionFilter() {}
    virtual                  ~avtMultipleInputExpressionFilter();

    virtual void              AddInputVariableName(const char *var);
    void                      ClearInputVariableNames(void);

    virtual const char       *GetType(void)
                                 { return "avtMultipleInputExpressionFilter"; }
    virtual const char       *GetDescription(void) = 0;

  protected:
    std::vector<char *>       varnames;

    virtual bool              IsPointVariable(void);
    virtual bool              MixedCenteringYieldsZonal(void) { return true; };
};

#endif


