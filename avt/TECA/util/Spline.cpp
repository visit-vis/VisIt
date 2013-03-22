#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include "Spline.h"
#include "Util.h"

using namespace std;

Spline::Spline() {}
//: nmax(2), pcom(nmax), xicom(nmax) {}

inline void copysecondindex(Fortran_Array1D<float>& to,  
			    Fortran_Array2D<float>& from, 
			    int index) {
    int n;
    for (n = 1; n < to.dim1(); n++){
      to(n) = from(n,index);
    }
}

inline float sign(float x, float y) {
    return (y >= 0 ? abs(x) : -abs(x));
}

//!-----------------------------------------------------------------------
//! Given an M by N tabulated function YA and tabulated independant 
//! variables X1A (M values) and X2A (N values), this routine constructs
//! one-dimensional natural cubic splines of the rows and returns 
//! the second-derivatives in the array Y2A.
//!-----------------------------------------------------------------------

void Spline::splie2(  const Fortran_Array1D<float>& x1a,
		      const Fortran_Array1D<float>& x2a,
		      const Fortran_Array2D<float>& ya, 
		      Fortran_Array2D<float>& y2a) {

  //x1a is not referenced!!
  float ypval(1.0e30);
  int m(0), n(0);
  Fortran_Array1D<float> ytmp(ya.dim2());
  Fortran_Array1D<float> y2tmp(ya.dim2());

  m = ya.dim1(); 
  n = ya.dim2();
  
  for (int j=1; j<=m; j++) { 
    
    Util::get_Row_2D(ytmp, ya, j);
    
    spline(x2a, ytmp, ypval, ypval, y2tmp);
    
    Util::insert_Row_2D(y2a, j, y2tmp);
    
  }
  
}

void Spline::splie3(  const Fortran_Array1D<float>& x1a,   
		      const Fortran_Array1D<float>& x2a,
		      const Fortran_Array2D<float>& ya, 
		      Fortran_Array2D<float>& y2a) {

  Fortran_Array1D<float> ytmp(ya.dim1());
  Fortran_Array1D<float> y2tmp(ya.dim1());
  
  float ypval(1.0e30);
  int m(0), n(0);
    
  m = ya.dim1();
  n = ya.dim2();

  for (int k=1; k<=n; k++) {

    Util::get_Column_2D(ytmp, ya, k);
    
    spline(x1a, ytmp, ypval, ypval, y2tmp);
  
    Util::insert_Column_2D(y2a, k, y2tmp);

  }
}

void Spline::spline( const Fortran_Array1D<float>& x,  
		     const Fortran_Array1D<float>& y, 
		     const float& yp1, 
		     const float& ypn, 
		     Fortran_Array1D<float>& y2) {
  
  Fortran_Array1D<float>   u(x.dim1());
  Fortran_Array1D<float> sig(x.dim1());
  Fortran_Array1D<float>   p(x.dim1());

  float qn(0), un(0);
  float yptest(.99e30);
  
  int n = x.dim();
  
  if (yp1 > yptest) {
    y2(1) = 0.0;
     u(1) = 0.0;
  } 
  else {
    y2(1) = -0.5;
    u(1)  = ( 3.0 / ( x(2) - x(1) ) ) * 
                  ( ( y(2) - y(1) ) / ( x(2) - x(1) ) - yp1 );

  }

  for (int i = 2; i <=n-1; i++) {
    //%%%%%%%%%%%%%%
    sig(i) = ( x(i) - x(i-1) ) / ( x(i+1) - x(i-1) );
      p(i) = sig(i) * y2(i-1) + 2.0;
     y2(i) = ( sig(i) - 1.0 ) / p(i);

      u(i) = ( 6.0 * ( ( y(i+1) - y(i)   )    
                   / ( x(i+1) - x(i)   )    
                   - ( y(i)   - y(i-1) )    
                   / ( x(i)   - x(i-1) ) )  
	           / ( x(i+1) - x(i-1) ) - sig(i) * u(i-1) ) / p(i);
    //%%%%%%%%%%%%%%
}

  if (ypn > yptest) {
    qn = 0.0;
    un = 0.0;
  } 
  else {
    qn = 0.5;
    un = (3.0/(x(n)-x(n-1)))*(ypn-(y(n)-y(n-1))/(x(n)-x(n-1)));
  }

  y2(n) = (un - qn * u(n-1)) / (qn * y2(n-1) + 1.0);

  for (int i = n-1; i >= 1; i--) {
    y2(i) = y2(i) * y2(i+1) + u(i);
  }
}

void Spline::splint( const Fortran_Array1D<float>& xa,  
		     const Fortran_Array1D<float>& ya,  
		     const Fortran_Array1D<float>& y2a,
                     const float& x, 
		     float& y, 
		     float& dy, float& dyy){
  
  int n(0), k(0), klo(0), khi(0);
  float h(0), a(0), b(0), ddy(0);
  
  n = xa.dim1();
  klo = 1; 
  khi = n;
  
  while (khi - klo > 1) {
    k = ( khi + klo ) / 2;
    if (xa(k)>x) {
      khi = k;
    } 
    else {
      klo = k;
    }
  }
  
  h = xa(khi) - xa(klo);

  if (h == 0.0) {
    //cout << " *** SPLINT: bad xa input";
  }

  a = (xa(khi) - x) / h;
  b = (x - xa(klo)) / h;
  
  y = a * ya(klo) + b * ya(khi) 
    + ( ( a*a*a - a)  * y2a(klo) 
    + ( b*b*b - b)  * y2a(khi)) * (h*h) / 6.0;

  dy =( ya(khi) - ya(klo) )/h 
    - ( 3.0 * a*a - 1.0) * h * y2a(klo)/6.0 
    + ( 3.0 * b*b - 1.0) * h * y2a(khi)/6.0;

  ddy = a*y2a(klo)+b*y2a(khi);

}

void Spline::splin2 ( const Fortran_Array1D<float>& x1a,  
		      const Fortran_Array1D<float>& x2a,
                      const Fortran_Array2D<float>& ya,  
		      const Fortran_Array2D<float>& y2a,
		      const float& x1, const float& x2, 
		      float& y, float& dy, float& ddy) {
  

  Fortran_Array1D<float>  ytmp(ya.dim2());
  Fortran_Array1D<float> y2tmp(ya.dim2());
  
  Fortran_Array1D<float>  yytmp(ya.dim1());
  Fortran_Array1D<float> yy2tmp(ya.dim1());
  
  float y1(0), y2(0), ypval(1.0e30);
  
  int m = ya.dim1();
  int n = ya.dim2();
  
  for (int j=1; j<=m; j++) {
    
    Util::get_Row_2D( ytmp, ya, j);
    Util::get_Row_2D(y2tmp, y2a, j);

    splint(x2a, ytmp, y2tmp, x2, yytmp(j), y1, y2);
  }
  
  spline(x1a, yytmp, ypval, ypval, yy2tmp);
  splint(x1a, yytmp, yy2tmp, x1, y, dy, ddy);

  ddy = 0.0;
  
}

void Spline::splin3 ( const Fortran_Array1D<float>& x1a,  
		      const Fortran_Array1D<float>& x2a,
                      const Fortran_Array2D<float>& ya,  
		      const Fortran_Array2D<float>& y2a,
		      const float& x1, const float& x2, 
		      float& y, float& dy, float& ddy) {

  Fortran_Array1D<float> ytmp(ya.dim1());
  Fortran_Array1D<float> y2tmp(ya.dim1());
  Fortran_Array1D<float> yytmp(ya.dim2());
  Fortran_Array1D<float> yy2tmp(ya.dim2());

  float y1(0), y2(0), ypval(1.0e30);

  int m = ya.dim1();
  int n = ya.dim2();  

  for (int k=1; k<=n; k++) {
    
    Util::get_Column_2D( ytmp, ya, k);
    Util::get_Column_2D(y2tmp, y2a, k);
    
    splint(x1a, ytmp, y2tmp, x1, yytmp(k), y1, y2);
  }
  
  spline(x2a, yytmp, ypval, ypval, yy2tmp);
  splint(x2a, yytmp, yy2tmp, x2, y, dy, ddy);
  ddy = 0.0;

}


//-----------------------------------------------------------------------
// Given a starting point P that is a s_vector of length N, Fletcher-Reeves
// Polak-Ribiere minimization is performed on a function FUNV, using its
// gradient as calculated by a routine DFUNC,. The convergence tolerance
// on the function value is input as FTOL. Returned quantities are P
// (the location of the minimum), ITER (the number of iterations
// that were performed), and FRET(the minimum value of the function).
// The routine LINMIN is called to perform line minimizations.
// Maximum anticipated value of N; maximum allowed number of iterations;
// small number to rectify special case of converging to exactly zero 
// function value
//!-----------------------------------------------------------------------
void Spline::frprm (  const Fortran_Array1D<float>& x1a,   
		      const Fortran_Array1D<float>& x2a, 
                      const Fortran_Array2D<float>& ya,  
		      const Fortran_Array2D<float>& y2a,
                      const Fortran_Array2D<float>& y3a, 
		      Fortran_Array1D<float>& p, 
		      const float& ftol, 
		     int& iter, float& fret, int& ierror) {

  //cout<<"frprm:: start()"<<endl;

  Fortran_Array1D<float> g(p.dim1());
  Fortran_Array1D<float> h(p.dim1());
  Fortran_Array1D<float> xi(p.dim1());
  
  float p1(0), px(0), pxx(0), py(0), pyy(0), fp(0);
  float s0(0), pp1(0), pp2(0), gg(0), dgg(0), gam(0), eps(0); 

  eps = 1.0e-10;
  int l(0), m(0), n(0), j(0), its(0), ier(0), itmax(0); 
  itmax = 50;

  l = ya.dim1();
  m = ya.dim2();
  n = p.dim1();

  splin2(x1a, x2a, ya, y2a, p(1), p(2), p1, px, pxx);
  splin3(x1a, x2a, ya, y3a, p(1), p(2), p1, py, pyy);

  fp = p1;
  xi(1) = px;
  xi(2) = py;
  
  for (j=1; j<=n; j++){
    g(j)  = -xi(j);
    h(j)  =  g(j);
    xi(j) = h(j);
  }

  for (its = 1; its <= itmax; its++){
    iter = its;
    s0 = sqrt(xi(1)*xi(1) + xi(2)*xi(2));
    xi(1) = xi(1) / s0;
    xi(2) = xi(2) / s0;
    
    /*
    cout<<"before "<<setw(10)<<p(1)<<" "<<setw(10)<<p(2)
	<<" "<<setw(10)<<xi(1)<<" "<<setw(10)<<xi(2)<<" "
	<<setw(10)<<fret<<" "<<ier<<endl;
    */

    linmin(p, xi, fret, x1a, x2a, ya, y2a, ier);

    //cout<<"("<<setw(2)<<its<<") "<<setw(10)<<p(1)<<" "<<setw(10)<<p(2)
    //	<<" "<<setw(10)<<xi(1)<<" "<<setw(10)<<xi(2)<<" "
    //	<<setw(10)<<fret<<" "<<ier<<endl;
    
    if (ier == 1) {
      ierror = 1;
      //cout<<"frprm:: end() ier=1"<<endl;
      return;
    }
    if ((2.0*abs(fret-fp))<=(ftol*(abs(fret)+abs(fp)+eps))) {
      //cout<<"frprm:: end() fret-fp condition"<<endl;
      return;
    }
    pp1 = p(1);
    pp2 = p(2);
    if (p(1) <=   0.0) pp1 = p(1)   + 360.0;
    if (p(1) >= 360.0) pp1 = p(1)   - 360.0;
    if (p(2) <=- 90.0) pp2 = -180.0 - p(2);
    if (p(2) >=  90.0) pp2 = 180.0  - p(2);
    
    splin2(x1a, x2a, ya, y2a, pp1, pp2, p1, px, pxx);
    splin3(x1a, x2a, ya, y3a, pp1, pp2, p1, py, pyy);

    xi(1) = px;
    xi(2) = py;
    fp = p1;
    gg = 0.0;
    dgg = 0.0;

    for (j=1; j<=n; j++) {
      gg = gg + g(j)*g(j);
      dgg = dgg + xi(j)*xi(j);
      dgg = dgg + (xi(j)+g(j))*xi(j);
    }

    if (gg == 0.0) {
      //cout<<"frprm:: end() gg=0"<<endl;
      return;
    }
    
    gam = dgg / gg;
    
    for (j=1; j<=n; j++) {
      g(j) = -xi(j);
      h(j) = g(j) + gam*h(j);
      xi(j) = h(j);
    }
  }
  
  ierror = 1;
  //cout << " *** FRPRM: maximum iterations exceeded"<<endl;
}

void Spline::linmin( Fortran_Array1D<float>& p, 
		     Fortran_Array1D<float>& xi, 
		     float& fret,  
		     const Fortran_Array1D<float>& x1a,  
		     const Fortran_Array1D<float>& x2a,
		     const Fortran_Array2D<float>& ya,  
		     const Fortran_Array2D<float>& y2a, 
		     int& ier) {
  
    int l, m, n, j;
    float ax, xx, bx, fa, fx, fb, xmin, tol; 
    tol = 1.0e-4;
    l = ya.dim1();
    m = ya.dim2();
    n = p.dim1();

    int ncom = n;
    int nmax=2;
    Fortran_Array1D<float> pcom(nmax);
    Fortran_Array1D<float> xicom(nmax);

    for (j=1; j<=n; j++){
      pcom(j) = p(j);
      xicom(j) = xi(j);
    }
    ax = 0.0;
    xx = 1.0;

    mnbrak(ax, xx, bx, fa, fx, fb, 
	   x1a, x2a, ya, y2a, 
	   pcom, xicom, ncom);
    
    ier = 0;
    
    brent(ax, xx, bx, tol, fret, xmin, 
	  x1a, x2a, ya, y2a, ier, 
	  pcom, xicom, ncom);

    if (xmin <= 1.0e-5) xmin = 0.0;

    for (j=1; j<=n; j++){
      xi(j) = xmin * xi(j);
      p(j)  = p(j) + xi(j);
    }
}

void Spline::linmin1 (Fortran_Array1D<float>& p,  
		      const Fortran_Array1D<float>& xi, 
		      float& fret,  
		      const Fortran_Array1D<float>& x1a,  
		      const Fortran_Array1D<float>& x2a,  
		      const Fortran_Array2D<float>& ya, 
		      const Fortran_Array2D<float>& y2a, 
		      int& ier, const float& val, const float& dist_val,
		      Fortran_Array1D<float>& pcom, 
		      Fortran_Array1D<float>& xicom) {
  
  float x20(0), y20(0), x(0), d(0), y(0), py(0), pyy(0), y0(0), y1(0), tol(0); 
  tol = 1.0e-4;
  int l(0), m(0), n(0), j(0);
  
  Fortran_Array1D<float> xt(p.dim1());
  
  l = ya.dim1();
  m = ya.dim2();
  n = p.dim1();

  int ncom = n;
  x20 = p(1);
  y20 = p(2);
  
  for (j=1; j<=n; j++) {
    pcom(j) = p(j);
    xicom(j) = xi(j);
  }
  
  ier = 0;
  x = 1.0;
  d = 0.0;
  
  splin2(x1a, x2a, ya, y2a, p(1), p(2), y, py, pyy);

  y0 = y;

  while (1) {
    
    for (j=1; j<=n; j++) {
      xt(j) = p(j) + x * xicom(j);
    }
    
    d = sqrt(pow(xt(1)-x20,2)+pow(xt(2)-y20,2));

    splin2(x1a, x2a, ya, y2a, xt(1), xt(2), y1, py, pyy);

    if (abs(d) >= dist_val) {
      ier = 1; 
      return;
    }
    if (x <= 0.0001) {
      fret = y; 
      return;
    }
    if ((y0-y1) >= val) {
      return;
    }
    if ( ((y0-y1) <= 2.0) && (y <= 1000000.0) ) {
      p(1) = xt(1);
      p(2) = xt(2);
      continue;
    }

    if (y1 >= 10000000.0) {
      p(1) = xt(1);
      p(2) = xt(2);
    }
    x = x / 2.0;
  }
}

void Spline::f1d1m (float& y, const float& x,  
		    const Fortran_Array1D<float>& x1a,  
		    const Fortran_Array1D<float>& x2a,
		    const Fortran_Array2D<float>& ya,  
		    const Fortran_Array2D<float>& y2a,
		    Fortran_Array1D<float>& pcom, 
		    Fortran_Array1D<float>& xicom, 
		    int& ncom ) {
  //
  // needs pcom, xicom, ncom as input
  //
  int l(0), m(0), j(0);
  float py(0), pyy(0);
  int nmax=2;
  Fortran_Array1D<float> xt(nmax);

  l = ya.dim1();
  m = ya.dim2();

  for (j=1; j<=ncom; j++){
    xt(j) = pcom(j) + x * xicom(j);
  }
  
  if( xt(1) <=   0.0 ) xt(1) =  360.0 + xt(1);
    if( xt(1) >= 360.0 ) xt(1) =  xt(1) - 360.0;
    if( xt(2) <= -90.0 ) xt(2) = -180.0 - xt(2);
    if( xt(2) >=  90.0 ) xt(2) =  180.0 - xt(2);  
    splin2(x1a, x2a, ya, y2a, xt(1), xt(2), y, py, pyy);
}

void Spline::mnbrak (float& ax, float& bx, float& cx, 
		     float& fa, float& fb, float& fc, 
		     const Fortran_Array1D<float>& x1a,  
		     const Fortran_Array1D<float>& x2a,
		     const Fortran_Array2D<float>& ya,  
		     const Fortran_Array2D<float>& y2a,
		     Fortran_Array1D<float>& pcom, 
		     Fortran_Array1D<float>& xicom, 
		     int& ncom) {

  int l(0), m(0);
  float dum(0), r(0), q(0), u(0), ulim(0), fu(0), uxt(0), uxb(0), gold(0), glimit(0), tiny(0);
    gold = 1.618034; 
    glimit = 100.0; 
    tiny = 1.0e-20;

    l = ya.dim1();
    m = ya.dim2();

    f1d1m(fa, ax, x1a, x2a, ya, y2a, pcom, xicom, ncom);
    f1d1m(fb, bx, x1a, x2a, ya, y2a, pcom, xicom, ncom);

    if (fb > fa) {
      dum = ax; 
      ax = bx; 
      bx = dum; 
      dum = fb; 
      fb = fa; 
      fa = dum;
    }

    cx = bx + gold*(bx-ax);

    f1d1m(fc, cx, x1a, x2a, ya, y2a, pcom, xicom, ncom);

    while (fb >= fc) {
        r = (bx - ax) * (fb - fc);
        q = (bx - cx) * (fb - fa);
        uxt = (bx - cx) * q - (bx - ax) * r;
        uxb = 2.0 * sign(fmax(abs(q-r),tiny),q-r);
        u = bx - uxt/uxb;
        u = min(cx+gold*(cx-bx),u);
        ulim = bx + glimit*(cx-bx);

        if (((bx - u)*(u - cx))>0.0) {
	  f1d1m(fu, u, x1a, x2a, ya, y2a, pcom, xicom, ncom);
            if (fu < fc) {
                ax = bx; fa = fb; bx = u; fb = fu; return;
            } else if (fu > fb) {
                cx = u; fc = fu; return;
            }
            u = cx + gold*(cx - bx);
            f1d1m(fu, u, x1a, x2a, ya, y2a, pcom, xicom, ncom);
        } else if (((cx-u)*(u-ulim))>0.0) {
	  f1d1m(fu, u, x1a, x2a,ya, y2a, pcom, xicom, ncom);
            if (fu < fc) {
                bx = cx; 
		cx = u;
                u = cx + gold*(cx-bx);
                fb = fc; 
		fc = fu;
                f1d1m(fu, u, x1a, x2a, ya, y2a, pcom, xicom, ncom);
            }
        } else if (((u-ulim)*(ulim-cx))>=0.0) {
            u = ulim;
            f1d1m(fu, u, x1a, x2a, ya, y2a, pcom, xicom, ncom);
        } else {
            u = cx + gold*(cx-bx);
            f1d1m(fu, u, x1a, x2a, ya, y2a, pcom, xicom, ncom);
        }
        ax = bx; 
	bx = cx; 
	cx = u; 
	fa = fb; 
	fb = fc; 
	fc = fu;
    }
}

void Spline::brent (const float& ax, const float& bx, const float& cx, 
		    const float tol, float& fret, float& xmin,  
		    const Fortran_Array1D<float>& x1a, 
		    const Fortran_Array1D<float>& x2a,  
		    const Fortran_Array2D<float>& ya,  
		    const Fortran_Array2D<float>& y2a, 
		    int& ier,
		    Fortran_Array1D<float>& pcom, 
		    Fortran_Array1D<float>& xicom, 
		    int& ncom) {
    int l(0), m(0), iter(0), itmax; 
 
    float a(0), b(0), v(0), w(0), x(0), e(0), fx(0), fv(0), fw(0), d(0), u(0), fu(0), xm(0);
    float tol1(0), tol2(0), r(0), q(0), p(0), etemp(0);
    float cgold(0), zeps(0); 

    cgold = 0.3819660; 
    zeps = 1.0e-10;
    itmax = 100;

    l = ya.dim1();
    m = ya.dim2();

    a = min(ax, cx);
    b = max(ax, cx);
    v = bx; 
    w = v; 
    x = v; 
    e = 0.0;

    f1d1m(fx, x, x1a, x2a, ya, y2a, pcom, xicom, ncom);

    fv = fx; 
    fw = fx;
    
    for (iter=1; iter<=itmax; iter++){
      
      xm = 0.5 * (a + b);
      tol1 = tol * abs(x) + zeps;
      tol2 = 2.0 * tol1;
      
      if (abs(x-xm)<=(tol2-0.5*(b-a))) {
	xmin = x; fret = fx; return;
      }
      
      if (abs(e)>tol1) {
            r = (x - w) * (fx - fv);
            q = (x - v) * (fx - fw);
            p = (x - v) * q - (x - w) * r;
            q = 2.0 * (q - r);
            if (q > 0.0) p = -p;
            q = abs(q);
            etemp = e;
            e = d;
	    
            if ((abs(p) >= abs(.5*q*etemp))||
		(p<=(q*(a-x)))||
		(p>=(q*(b-x)))) 
	      goto l1;

            d = p / q; 
	    u = x + d;
            if (((u-a)<tol2)||
		((b-u)<tol2)) 
	      d = sign(tol1,xm-x);
            goto l2;
        }

        l1:
        if (x >= xm) 
	  e = a - x;
        else 
	  e = b - x;
        d = cgold * e;
	
    l2:
        if (abs(d)>=tol1) 
	  u = x + d;
        else 
	  u = x + sign(tol1, d);
        f1d1m(fu, u, x1a, x2a, ya, y2a, pcom, xicom, ncom);

        if (fu <= fx) {
            if (u >= x) 
	      a = x;
            else 
	      b = x;
            v = w; 
	    fv = fw; 
	    w = x; 
	    fw = fx; 
	    x = u; 
	    fx = fu;
        } else {
            if (u < x) 
	      a = u;
            else 
	      b = u;
            if ((fu <= fw)||(w == x)){
                v = w; 
		fv = fw; 
		w = u; 
		fw = fu;
            } else if ((fu<=fv)||(v==x)||(v==w)){
                v = u; 
		fv = fu;
            }
        }
    }
    ier = 1;
    //cout << " *** Brent: exceed maximum iterations";
    xmin = x;
    fret = fx;
}

void Spline::shape (  const Fortran_Array1D<float>& x1a,   
		      const Fortran_Array1D<float>& x2a,
		      Fortran_Array2D<float>& ya,  
		      Fortran_Array2D<float>& y2a,
		      Fortran_Array2D<float>& y3a,  
		      const Fortran_Array1D<float>& p, 
		      const float& ftol,  int& iter,  float& fret,
		      int& ierror2, 
		      const float& val, const float& dist_val) {
  

  // ftol, iter and fret are not referenced..

  Fortran_Array1D<float>  q(p.dim1());
  Fortran_Array1D<float>  g(p.dim1());
  Fortran_Array1D<float>  h(p.dim1());
  Fortran_Array1D<float> xi(p.dim1());

  Fortran_Array2D<float> ta(ya.dim1(), ya.dim2());
  Fortran_Array2D<float> t2a(ya.dim1(), ya.dim2());
  Fortran_Array2D<float> t3a(ya.dim1(), ya.dim2());

  int nmax=2;
  Fortran_Array1D<float> pcom(nmax);
  Fortran_Array1D<float> xicom(nmax);

  float dr(0), fret1(0);
  int l(0), m(0), n(0), i(0), ier(0);

  float xi1[] = {0.0,0.0,1.0,-1.0,1.0,1.0,-1.0,-1.0};
  float xi2[] = {1.0,-1.0,0.0,0.0,-1.0,1.0,1.0,-1.0};

  l = ya.dim1();
  m = ya.dim2();
  n = p.dim1();
  
  Util::scalar_mul2D( ta,  ya, -1.0);
  Util::scalar_mul2D(t2a, y2a, -1.0);
  Util::scalar_mul2D(t3a, y3a, -1.0);
  
  for (i = 0; i < 8; i++) {
    if (ierror2 == 0) {
      q(1) = p(1);
      q(2) = p(2);
      xi(1) = xi1[i];
      xi(2) = xi2[i];
      linmin1(q, xi, fret1, x1a, x2a, ta, t2a, ier, val, dist_val, pcom, xicom);
      dr = pow(p(1)-q(1),2) + pow(p(2)-q(2),2);
      if (dr >= 100.0) ierror2 = 1;
      if (ier == 1) ierror2 = 1;
    }
  }
  
}
