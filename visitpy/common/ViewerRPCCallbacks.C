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
#include <ViewerRPCCallbacks.h>

// ****************************************************************************
// Method: ViewerRPCCallbacks::ViewerRPCCallbacks
//
// Purpose: 
//   Constructor for the ViewerRPCCallbacks class.
//
// Programmer: Brad Whitlock
// Creation:   Tue Feb  5 11:46:12 PST 2008
//
// Modifications:
//   
// ****************************************************************************

ViewerRPCCallbacks::ViewerRPCCallbacks()
{
    for(int r = 0; r < (int)ViewerRPC::MaxRPC; ++r)
    {
        pycb[r] = 0;
        pycb_data[r] = 0;
    }
}

// ****************************************************************************
// Method: ViewerRPCCallbacks::~ViewerRPCCallbacks
//
// Purpose: 
//   Destructor for the ViewerRPCCallbacks class.
//
// Programmer: Brad Whitlock
// Creation:   Tue Feb  5 11:46:12 PST 2008
//
// Modifications:
//   Brad Whitlock, Thu Aug 19 15:52:59 PDT 2010
//   Be careful about deleting a class instance from here.
//   
// ****************************************************************************

ViewerRPCCallbacks::~ViewerRPCCallbacks()
{
    for(int r = 0; r < (int)ViewerRPC::MaxRPC; ++r)
    {
        if(pycb[r] != 0)
            Py_DECREF(pycb[r]);
        if(pycb_data[r] != 0)
        {
#ifdef Py_REFCNT
            // Hack! I found that decrementing the refcount of a class 
            //       instance from here causes a crash if it's the last
            //       reference and it will cause the object to be deleted.
            //       Decrementing the refcount on other object types is fine,
            //       even if it causes the object to get deleted. Other objects
            //       work okay so our reference counting seems good.
            bool lastInstance = Py_REFCNT(pycb_data[r]) == 1 &&
                                PyInstance_Check(pycb_data[r]);
            if(!lastInstance)
#endif
                Py_DECREF(pycb_data[r]);
        }
    }
}

// ****************************************************************************
// Method: ViewerRPCCallbacks::GetCallbackNames
//
// Purpose: 
//   Get the callback names.
//
// Arguments:
//   names : The return vector for the callback names.
//
// Programmer: Brad Whitlock
// Creation:   Tue Feb  5 11:46:40 PST 2008
//
// Modifications:
//   
// ****************************************************************************

void
ViewerRPCCallbacks::GetCallbackNames(stringVector &names)
{
    for(int r = 0; r < (int)ViewerRPC::MaxRPC; ++r)
        names.push_back(ViewerRPC::ViewerRPCType_ToString((ViewerRPC::ViewerRPCType)r));
}

// ****************************************************************************
// Method: ViewerRPCCallbacks::RegisterCallback
//
// Purpose: 
//   Registers a callback for a specific viewerrpc (by name).
//
// Arguments:
//   rpcName : The name of the ViewerRPC for which we're installing a callback.
//   cb      : The user-provided callback.
//   cbdata  : callback data.
//
// Returns:    True on success; False on failure.
//
// Note:       Call with NULL cb, cbdata to unregister the callback.
//
// Programmer: Brad Whitlock
// Creation:   Tue Feb  5 11:47:52 PST 2008
//
// Modifications:
//   
// ****************************************************************************

bool
ViewerRPCCallbacks::RegisterCallback(const std::string &rpcName, PyObject *cb, 
    PyObject *cbdata)
{
    bool retval = false;
    ViewerRPC::ViewerRPCType r;
    if(ViewerRPC::ViewerRPCType_FromString(rpcName, r))
    {
        if(pycb[r] != 0)
            Py_DECREF(pycb[r]);
        if(pycb_data[r] != 0)
            Py_DECREF(pycb_data[r]);
        pycb[r] = cb;
        pycb_data[r] = cbdata;
        if(pycb[r] != 0)
            Py_INCREF(pycb[r]);
        if(pycb_data[r] != 0)
            Py_INCREF(pycb_data[r]);
        retval = true;
    }
    return retval;
}

// ****************************************************************************
// Method: ViewerRPCCallbacks::GetCallback
//
// Purpose: 
//   Returns the user-defined callback for the specified rpc.
//
// Arguments:
//   r : The rpc whose callback we want to access.
//
// Returns:    
//
// Note:       
//
// Programmer: Brad Whitlock
// Creation:   Tue Feb  5 11:48:55 PST 2008
//
// Modifications:
//   
// ****************************************************************************

PyObject *
ViewerRPCCallbacks::GetCallback(ViewerRPC::ViewerRPCType r)
{
    return pycb[r];
}

// ****************************************************************************
// Method: ViewerRPCCallbacks::GetCallbackData
//
// Purpose: 
//   Returns the user-defined callback data for the specified rpc.
//
// Arguments:
//   r : The rpc whose callback data we want to access.
//
// Returns:    
//
// Note:       
//
// Programmer: Brad Whitlock
// Creation:   Wed Feb  6 10:26:44 PST 2008
//
// Modifications:
//   
// ****************************************************************************

PyObject *
ViewerRPCCallbacks::GetCallbackData(ViewerRPC::ViewerRPCType r)
{
    return pycb_data[r];
}
