#ifndef _SPLINE_H
#define _SPLINE_H
#include <vector>
#include "tnt_fortran_array1d.h"
#include "tnt_fortran_array2d.h"

using namespace std;
using namespace TNT;

class Spline {

public:
  Spline();

static void splie2(  const Fortran_Array1D<float>& x1a,
		      const Fortran_Array1D<float>& x2a,
		      const Fortran_Array2D<float>& ya, 
		      Fortran_Array2D<float>& y2a);
 
  static void splie3(  const Fortran_Array1D<float>& x1a,   
		      const Fortran_Array1D<float>& x2a,
		      const Fortran_Array2D<float>& ya, 
			Fortran_Array2D<float>& y2a);

  static void spline( const Fortran_Array1D<float>& x,  
		     const Fortran_Array1D<float>& y, 
		     const float& yp1, const float& ypn, 
		       Fortran_Array1D<float>& y2);

  static void splint( const Fortran_Array1D<float>& xa,  
		     const Fortran_Array1D<float>& ya,  
		     const Fortran_Array1D<float>& y2a,
                     const float& x, 
		     float& y, 
		       float& dy, float& dyy);
  
static void splin2 ( const Fortran_Array1D<float>& x1a,  
		      const Fortran_Array1D<float>& x2a,
                      const Fortran_Array2D<float>& ya,  
		      const Fortran_Array2D<float>& y2a,
		      const float& x1, const float& x2, 
		      float& y, float& dy, float& ddy);

static void splin3 ( const Fortran_Array1D<float>& x1a,  
		      const Fortran_Array1D<float>& x2a,
                      const Fortran_Array2D<float>& ya,  
		      const Fortran_Array2D<float>& y2a,
		      const float& x1, const float& x2, 
		      float& y, float& dy, float& ddy);

 static void frprm (  const Fortran_Array1D<float>& x1a,   
		      const Fortran_Array1D<float>& x2a, 
                      const Fortran_Array2D<float>& ya,  
		      const Fortran_Array2D<float>& y2a,
                      const Fortran_Array2D<float>& y3a, 
		      Fortran_Array1D<float>& p, 
		      const float& ftol, 
		       int& iter, float& fret, int& ierror) ;

 static void linmin( Fortran_Array1D<float>& p, 
		     Fortran_Array1D<float>& xi, 
		     float& fret,  
		     const Fortran_Array1D<float>& x1a,  
		     const Fortran_Array1D<float>& x2a,
		     const Fortran_Array2D<float>& ya,  
		     const Fortran_Array2D<float>& y2a, 
		      int& ier);
 
 static void linmin1 (Fortran_Array1D<float>& p,  
		      const Fortran_Array1D<float>& xi, 
		      float& fret,  
		      const Fortran_Array1D<float>& x1a,  
		      const Fortran_Array1D<float>& x2a,  
		      const Fortran_Array2D<float>& ya, 
		      const Fortran_Array2D<float>& y2a, 
		      int& ier, const float& val, const float& dist_val,
		      Fortran_Array1D<float>& pcom, 
		       Fortran_Array1D<float>& xicom);

 static void f1d1m (float& y, const float& x,  
		    const Fortran_Array1D<float>& x1a,  
		    const Fortran_Array1D<float>& x2a,
		    const Fortran_Array2D<float>& ya,  
		    const Fortran_Array2D<float>& y2a,
		    Fortran_Array1D<float>& pcom, 
		    Fortran_Array1D<float>& xicom, 
		     int& ncom );
 
static void mnbrak (float& ax, float& bx, float& cx, 
		     float& fa, float& fb, float& fc, 
		     const Fortran_Array1D<float>& x1a,  
		     const Fortran_Array1D<float>& x2a,
		     const Fortran_Array2D<float>& ya,  
		     const Fortran_Array2D<float>& y2a,
		     Fortran_Array1D<float>& pcom, 
		     Fortran_Array1D<float>& xicom, 
		     int& ncom);

 static void brent (const float& ax, const float& bx, const float& cx, 
		    const float tol, float& fret, float& xmin,  
		    const Fortran_Array1D<float>& x1a, 
		    const Fortran_Array1D<float>& x2a,  
		    const Fortran_Array2D<float>& ya,  
		    const Fortran_Array2D<float>& y2a, 
		    int& ier,
		    Fortran_Array1D<float>& pcom, 
		    Fortran_Array1D<float>& xicom, 
		     int& ncom);
static void shape (  const Fortran_Array1D<float>& x1a,   
		      const Fortran_Array1D<float>& x2a,
		      Fortran_Array2D<float>& ya,  
		      Fortran_Array2D<float>& y2a,
		      Fortran_Array2D<float>& y3a,  
		      const Fortran_Array1D<float>& p, 
		      const float& ftol,  int& iter,  float& fret,
		      int& ierror2, 
		      const float& val, const float& dist_val);

 
};

#endif
