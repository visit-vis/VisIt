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

#ifndef BL_CONSTANTS_H
#define BL_CONSTANTS_H

/*
 * $Id: CONSTANTS.H,v 1.12 2001/08/02 16:37:49 car Exp $
 */

#include <REAL.H>


#ifdef BL_LANG_FORT

#define bigreal BL_REAL_E(1.0,30)
#define zero    BL_REAL(0.0)
#define one     BL_REAL(1.0)
#define two     BL_REAL(2.0)
#define three   BL_REAL(3.0)
#define four    BL_REAL(4.0)
#define five    BL_REAL(5.0)
#define six     BL_REAL(6.0)
#define seven   BL_REAL(7.0)
#define eight   BL_REAL(8.0)
#define nine    BL_REAL(9.0)
#define ten     BL_REAL(10.0)
#define twelve  BL_REAL(12.0)
#define fifteen BL_REAL(15.0)
#define sixteen BL_REAL(16.0)
#define twenty  BL_REAL(20.0)
#define seventy BL_REAL(70.0)
#define ninety  BL_REAL(90.0)
#define tenth   BL_REAL(0.1)
#define eighth  BL_REAL(0.125)
#define sixth   BL_REAL(0.1666666666666667)
#define fifth   BL_REAL(0.2)
#define forth   BL_REAL(0.25)
#define fourth  BL_REAL(0.25)
#define third   BL_REAL(0.3333333333333333)
#define half    BL_REAL(0.5)
#define two3rd  BL_REAL(0.6666666666666667)
#define Pi      BL_REAL(3.1415926535897932)

#endif /*BL_LANG_FORT*/

#endif /*BL_CONSTANTS_H*/
