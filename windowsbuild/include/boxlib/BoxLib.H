/*
** (c) 1996-2003 The Regents of the University of California (through
** E.O. Lawrence Berkeley National Laboratory), subject to approval by
** the U.S. Department of Energy.  Your use of this software is under
** license -- the license agreement is attached and included in the
** directory as license.txt or you may contact Berkeley Lab's Technology
** Transfer Department at TTD@lbl.gov.  NOTICE OF U.S. GOVERNMENT RIGHTS.
** The Software was developed under funding from the U.S. Government
** which consequently retains certain rights as follows: the
** U.S. Government has been granted for itself and others acting on its
** behalf a paid-up, nonexclusive, irrevocable, worldwide license in the
** Software to reproduce, prepare derivative works, and perform publicly
** and display publicly.  Beginning five (5) years after the date
** permission to assert copyright is obtained from the U.S. Department of
** Energy, and subject to any subsequent five (5) year renewals, the
** U.S. Government is granted for itself and others acting on its behalf
** a paid-up, nonexclusive, irrevocable, worldwide license in the
** Software to reproduce, prepare derivative works, distribute copies to
** the public, perform publicly and display publicly, and to permit
** others to do so.
*/

#ifndef BL_BOXLIB_H
#define BL_BOXLIB_H

//
// $Id: BoxLib.H,v 1.15 2001/07/31 17:56:25 lijewski Exp $
//

//
//@Man:
//@Memo: Error-reporting Functions and Version Number
/*@Doc:

  This class consists entirely of static error-reporting functions that
  are used throughout the BoxLib implementation together with a version
  string.  In the best of all possible worlds we'd use a namespace, but
  we aren't there, yet :-)  Note that all the output functions add a
  terminating exclamation mark, so there is no need to add any punctuation
  to sentences that get output explicitly.
*/

namespace BoxLib
{
    void Initialize (int& argc, char**& argv);

    void Finalize();
    //
    //@ManDoc: Print out message to cerr and exit via BoxLib::Abort().
    //
    void Error (const char * msg = 0);
    //
    //@ManDoc: Print out warning message to cerr.
    //
    void Warning (const char * msg);
    //
    //@ManDoc: Print out message to cerr and exit via abort().
    //
    void Abort (const char * msg = 0);

    /*@ManDoc: Prints assertion failed messages to cerr and exits
               via abort().  Intended for use by the BL\_ASSERT() macro
               in <BLassert.H>.
    */
    void Assert (const char* EX,
                 const char* file,
                 int         line);

    /*@ManDoc: Prints out an out-of-memory message and aborts.  It is
             called by various BoxLib routines when a call to new fails.

             Called as BoxLib::OutOfMemory(\_\_FILE\_\_, \_\_LINE\_\_);
    */
    void OutOfMemory (const char* file,
                      int         line);
#ifdef NDEBUG
    const bool NDebug = true;
#else
    const bool NDebug = false;
#endif
}

#endif /*BL_BOXLIB_H*/
