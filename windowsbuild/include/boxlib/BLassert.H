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

#ifndef BL_BLASSERT_H
#define BL_BLASSERT_H

//
// $Id: BLassert.H,v 1.5 2001/07/17 23:02:18 lijewski Exp $
//

#include <BoxLib.H>

#ifdef BL_ASSERT
#undef BL_ASSERT
#endif

#if defined(NDEBUG)

/*@ManDoc:

  The macro BL\_ASSERT(EX) is a debugging macro, used to test the
  internal consistency of BoxLib, that may also be useful in user
  code.  The argument EX is a C++ expression that you expect to
  always evaluate to true.

  When code is compiled with the DEBUG macro set to TRUE, the
  BL\_ASSERT(EX) macro expands to a boolean test of the expression EX.
  If that expression evaluates to true, nothing happens, but if the
  expression evaluates to false, a message is output detailing the
  file and line number of the BL\_ASSERT(EX) statement, as well as the
  literal expression EX itself, and then exits via abort() using
  BoxLib::Assert().  The idea is that if the assertion fails, something
  has gone terribly wrong somewhere.

  If the DEBUG macro is not set to TRUE, the BL\_ASSERT(EX) call becomes
  a null statement in the code, which will be eliminated by the code
  optimizer.
*/
#define BL_ASSERT(EX) ((void)0)
#else
#if defined(__sgi) || defined(__hpux)
//
// The problem here is that some brain-dead compilers cannot deal with a
// void argument to the ternary operator.  Currently SGI's OCC and CC on
// HP-UX 9.0.1 have this problem.
//
#define BL_ASSERT(EX) if ((EX)) ; else BoxLib::Assert( # EX , __FILE__, __LINE__)
#else
#define BL_ASSERT(EX) (EX)?((void)0):BoxLib::Assert( # EX , __FILE__, __LINE__)
#endif
#endif

#endif /*BL_BL_ASSERT_H*/
