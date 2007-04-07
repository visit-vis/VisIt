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

#ifndef _WINSTD_H_
#define _WINSTD_H_

// This files 'fixes' MSVC 6 so that it is more like real C++.
#if defined(WIN32) && !defined(__MINGW32__)
// The STL and template classes in general will yield symbols greater
// than 256 chars, which are truncated; this suppresses the CL
// warning.
#pragma warning(disable:4786)
#pragma warning(disable:4251)
#define NOMINMAX
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
//#undef max
//#undef min
//#undef abs

typedef int mode_t;
typedef int pid_t;

// Place some globals in the standard namespace, where they belong
namespace std
{
//template <class T> inline T min(const T& l, const T& r) { return (l<r)?l:r; }
//template <class T> inline T max(const T& l, const T& r) { return (l<r)?r:l; }
//template <class T> inline T abs(const T& r) { return (r<0)?-r:r; }

using ::pow;
using ::fabs;
using ::sqrt;
using ::exp;
using ::log;
using ::log10;
using ::sin;
using ::cos;
using ::tan;
using ::asin;
using ::acos;
using ::atan;
using ::sinh;
using ::cosh;
using ::tanh;
using ::floor;
using ::ceil;
using ::fmod;
using ::frexp;
using ::ldexp;
using ::modf;

using ::exit;
using ::abort;

using ::strerror;
using ::sprintf;
}
#endif

#if defined( BL_OSF1 ) && !defined(BL_KCC_VERSION)
namespace std
{
template <class T> inline T abs(const T& r) { return (r<0)?-r:r; }
}
#endif
#if defined( BL_Linux ) && (BL_ICC_MAJOR_VERSION == 5)
namespace std
{
template <class T> inline T abs(const T& r) { return (r<0)?-r:r; }
}
#endif
#if defined( BL_GCC_VERSION) && (BL_GCC_MAJOR_VERSION < 3)
#define BL_USE_SETBUF
#endif
#endif
