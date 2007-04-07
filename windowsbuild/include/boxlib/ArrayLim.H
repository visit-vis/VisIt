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

#ifndef BL_ARRAYLIM_H
#define BL_ARRAYLIM_H

/*
** $Id: ArrayLim.H,v 1.10 2002/06/04 16:48:48 car Exp $
*/

#if !defined(BL_LANG_FORT)

/*
** C stuff ...
*/

#ifdef BL_USE_ARLIM

#error "BL_USE_ARLIM is deprecated"

#define ARLIM_P(x)  const int*
#define ARLIM(x)  x

#else

#if     BL_SPACEDIM==1
#define ARLIM_P(x)  const int&
#define ARLIM(x)  x[0]
#elif   BL_SPACEDIM==2
#define ARLIM_P(x)  const int&,const int&
#define ARLIM(x)  x[0],x[1]
#elif   BL_SPACEDIM==3
#define ARLIM_P(x)  const int&,const int&,const int&
#define ARLIM(x)  x[0],x[1],x[2]
#endif
#endif

#define BL_TO_FORTRAN(x) (x).dataPtr(), ARLIM((x).loVect()), ARLIM((x).hiVect())
#define BL_TO_FORTRAN_N(x,n) (x).dataPtr(n), ARLIM((x).loVect()), ARLIM((x).hiVect())

#else

/*
** Fortran stuff ...
*/

#include <REAL.H>

#ifdef BL_USE_ARLIM

#error "This section of code is deprecated: BL_USE_ARLIM is invalid"

#if (BL_SPACEDIM == 1)
#define DIMS(a) a##_lo, a##_hi
#define DIMDEC(a) a##_lo(1), a##_hi(1)
#define DIMV(a) a##_lo(1):a##_hi(1)
#define DIM1(a) a##_lo(1):a##_hi(1)
#define ARG_L1(a) a##_lo(1)
#define ARG_H1(a) a##_hi(1)
#endif

#if (BL_SPACEDIM == 2)
#define DIMS(a) a##_lo, a##_hi
#define DIMDEC(a) a##_lo(2), a##_hi(2)
#define DIMV(a) a##_lo(1):a##_hi(1), a##_lo(2):a##_hi(2)
#define DIM1(a) a##_lo(1):a##_hi(1)
#define DIM2(a) a##_lo(2):a##_hi(2)
#define ARG_L1(a) a##_lo(1)
#define ARG_L2(a) a##_lo(2)
#define ARG_H1(a) a##_hi(1)
#define ARG_H2(a) a##_hi(2)
#endif

#if (BL_SPACEDIM == 3)
#define DIMS(a) a##_lo, a##_hi
#define DIMDEC(a) a##_lo(3), a##_hi(3)
#define DIMV(a) a##_lo(1):a##_hi(1), a##_lo(2):a##_hi(2), a##_lo(3):a##_hi(3)
#define DIM1(a) a##_lo(1):a##_hi(1)
#define DIM2(a) a##_lo(2):a##_hi(2)
#define DIM3(a) a##_lo(3):a##_hi(3)
#define DIM12(a) a##_lo(1):a##_hi(1), a##_lo(2):a##_hi(2)
#define DIM23(a) a##_lo(2):a##_hi(2), a##_lo(3):a##_hi(3)
#define DIM13(a) a##_lo(1):a##_hi(1), a##_lo(3):a##_hi(3)
#define ARG_L1(a) a##_lo(1)
#define ARG_L2(a) a##_lo(2)
#define ARG_L3(a) a##_lo(3)
#define ARG_H1(a) a##_hi(1)
#define ARG_H2(a) a##_hi(2)
#define ARG_H3(a) a##_hi(3)
#endif

#else

#if __STDC__==1

#if (BL_SPACEDIM == 1)
#define DIMS(a) a##_l1, a##_h1
#define DIMDEC(a) a##_l1, a##_h1
#define DIMV(a) a##_l1:a##_h1
#define DIM1(a) a##_l1:a##_h1
#define ARG_L1(a) a##_l1
#define ARG_H1(a) a##_h1
#define DIMARG(a) a##(1)
#endif

#if (BL_SPACEDIM == 2)
#define DIMS(a) a##_l1, a##_l2 , a##_h1, a##_h2
#define DIMDEC(a) a##_l1, a##_l2 , a##_h1, a##_h2
#define DIMV(a) a##_l1:a##_h1, a##_l2:a##_h2
#define DIM1(a) a##_l1:a##_h1
#define DIM2(a) a##_l2:a##_h2
#define ARG_L1(a) a##_l1
#define ARG_L2(a) a##_l2
#define ARG_H1(a) a##_h1
#define ARG_H2(a) a##_h2
#define DIMARG(a) a##(1),a##(2)
#endif

#if (BL_SPACEDIM == 3)
#define DIMS(a) a##_l1, a##_l2 , a##_l3, a##_h1, a##_h2, a##_h3
#define DIMDEC(a) a##_l1, a##_l2 , a##_l3, a##_h1, a##_h2, a##_h3
#define DIMV(a) a##_l1:a##_h1, a##_l2:a##_h2, a##_l3:a##_h3
#define DIM1(a) a##_l1:a##_h1
#define DIM2(a) a##_l2:a##_h2
#define DIM3(a) a##_l3:a##_h3
#define DIM12(a) a##_l1:a##_h1, a##_l2:a##_h2
#define DIM23(a) a##_l2:a##_h2, a##_l3:a##_h3
#define DIM13(a) a##_l1:a##_h1, a##_l3:a##_h3
#define ARG_L1(a) a##_l1
#define ARG_L2(a) a##_l2
#define ARG_L3(a) a##_l3
#define ARG_H1(a) a##_h1
#define ARG_H2(a) a##_h2
#define ARG_H3(a) a##_h3
#define DIMARG(a) a##(1),a##(2),a##(3)
#endif

#else

#if (BL_SPACEDIM == 1)
#define DIMS(a) a/**/_l1, a/**/_h1
#define DIMDEC(a) a/**/_l1, a/**/_h1
#define DIMV(a) a/**/_l1:a/**/_h1
#define DIM1(a) a/**/_l1:a/**/_h1
#define ARG_L1(a) a/**/_l1
#define ARG_H1(a) a/**/_h1
#define DIMARG(a) a/**/(1)
#endif

#if (BL_SPACEDIM == 2)
#define DIMS(a) a/**/_l1, a/**/_l2 , a/**/_h1, a/**/_h2
#define DIMDEC(a) a/**/_l1, a/**/_l2 , a/**/_h1, a/**/_h2
#define DIMV(a) a/**/_l1:a/**/_h1, a/**/_l2:a/**/_h2
#define DIM1(a) a/**/_l1:a/**/_h1
#define DIM2(a) a/**/_l2:a/**/_h2
#define ARG_L1(a) a/**/_l1
#define ARG_L2(a) a/**/_l2
#define ARG_H1(a) a/**/_h1
#define ARG_H2(a) a/**/_h2
#define DIMARG(a) a/**/(1),a/**/(2)
#endif

#if (BL_SPACEDIM == 3)
#define DIMS(a) a/**/_l1, a/**/_l2 , a/**/_l3, a/**/_h1, a/**/_h2, a/**/_h3
#define DIMDEC(a) a/**/_l1, a/**/_l2 , a/**/_l3, a/**/_h1, a/**/_h2, a/**/_h3
#define DIMV(a) a/**/_l1:a/**/_h1, a/**/_l2:a/**/_h2, a/**/_l3:a/**/_h3
#define DIM1(a) a/**/_l1:a/**/_h1
#define DIM2(a) a/**/_l2:a/**/_h2
#define DIM3(a) a/**/_l3:a/**/_h3
#define DIM12(a) a/**/_l1:a/**/_h1, a/**/_l2:a/**/_h2
#define DIM23(a) a/**/_l2:a/**/_h2, a/**/_l3:a/**/_h3
#define DIM13(a) a/**/_l1:a/**/_h1, a/**/_l3:a/**/_h3
#define ARG_L1(a) a/**/_l1
#define ARG_L2(a) a/**/_l2
#define ARG_L3(a) a/**/_l3
#define ARG_H1(a) a/**/_h1
#define ARG_H2(a) a/**/_h2
#define ARG_H3(a) a/**/_h3
#define DIMARG(a) a/**/(1),a/**/(2),a/**/(3)
#endif

#endif /*__STDC__==1*/

#endif /*BL_USE_ARLIM*/

#endif /*!defined(BL_LANG_FORT)*/

#endif /*BL_ARRAYLIM_H*/
