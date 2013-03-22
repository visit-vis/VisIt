#include "Util.h"
#include <limits>
#include <assert.h>
#include <math.h>

//TODO: return to 32 after ANL test
//#define PAD_SIZE 80
#define PAD_SIZE 64
// NOTE: PAD_SIZE needs to be 2x GRID_BOXES specified in the command line 

void Util::init2DVec(Fortran_Array2D<float>& result, int i, int j){
  
  Fortran_Array2D<float> V(i,j);
  for (int ii=1;ii<=i;ii++)
    for (int jj=1;jj<=j;jj++)
      V(ii,jj)=0.0;

  result = V.copy();
}

void Util::init2DVec(Fortran_Array2D<bool>& result, int i, int j){
  
  Fortran_Array2D<bool> V(i,j);
  for (int ii=1;ii<=i;ii++)
    for (int jj=1;jj<=j;jj++)
      V(ii,jj)=false;

  result = V.copy();
}

void Util::init2DVec(Fortran_Array2D<int>& result, int i, int j){
  
  Fortran_Array2D<int> V(i,j);
  for (int ii=1;ii<=i;ii++)
    for (int jj=1;jj<=j;jj++)
      V(ii,jj)=0;

  result = V.copy();
}

void Util::init2DVec_padded(Fortran_Array2D<float>& v, 
			    const Fortran_Array2D<float>& in){
  
  Fortran_Array2D<float> out(in.dim1()+PAD_SIZE, in.dim2()+PAD_SIZE);
  gpad2(out, in);

  v = out.copy();
}

void Util::init1DVec(Fortran_Array1D<float>& v, int i){
  
  Fortran_Array1D<float> V(i);
  for (int ii=1;ii<=i;ii++)
    V(ii)=0.0;
  
  v = V.copy();

}

void Util::init1DVec(Fortran_Array1D<int>& v, int i){
  
  Fortran_Array1D<int> V(i);
  for (int ii=1;ii<=i;ii++)
    V(ii)=0;
  
  v = V.copy();

}

void Util::init1DVec_padded(Fortran_Array1D<float>& v, 
			    const Fortran_Array1D<float>& in){
  
  Fortran_Array1D<float> out(in.dim1()+PAD_SIZE);
  gpad1(out, in);
  
  v = out.copy();
}

// this function will assume that Gxx and xx are already allocated
// it will place contents of Gxx in the middle of xx vector
// and do a linear trend falloff 
//
void Util::gpad1( Fortran_Array1D<float>& xx,
		  const Fortran_Array1D<float> & Gxx) {
  
  int nx2 = xx.dim() - Gxx.dim();
  int nx = nx2/2;
  int nxp1 = nx+1;
  
  int ix = Gxx.dim();
  int ip =  xx.dim() + 1;

  copy_subarray1D(xx, 
		  nxp1, ix+nx,
		  Gxx);
  
  float dx = xx(nx+2)-xx(nx+1);
  
  for (int i=1; i<=nx; i++) {
    xx(   i) = xx(   nxp1) - (nxp1 -i)*dx;
    xx(ip-i) = xx(ip-nxp1) + (nxp1 -i)*dx;
  }
}
// 
// This version of gpad2() will take contents of Gxx
// place them midway in the array xx
// all fill in the border with periodic values
//
void Util::gpad2(Fortran_Array2D<float>& xx,
		 const Fortran_Array2D<float>& Gxx) {

  int ix = Gxx.dim1();
  int jx = Gxx.dim2();
  
  int nx2 = xx.dim1() - Gxx.dim1();
  int nx = nx2/2;
  int nxp1 = nx + 1;
  
  copy_subarray2D(xx, nxp1, ix+nx, nxp1, jx+nx,
		  Gxx);
  
  //bottom rows
  for (int i=1; i<=nx; i++) {    
    copy_subarray2Dj(xx, i+ix+nx, nxp1, jx+nx,
		     xx, i   +nx, nxp1, jx+nx);  
  }
  
#ifdef _FIX_FORTRAN_BUG
  //top rows
  for (int i=1; i<=nx; i++) {
    copy_subarray2Dj(xx, i,    nxp1, jx+nx,
		     xx, i+nx, nxp1, jx+nx);
  }
#else
  //top rows
  for (int i=1; i<=nx; i++) {
    copy_subarray2Dj(xx, i,    nxp1, jx+nx,
		     xx, i+ix, nxp1, jx+nx);
  }
#endif
  


  // left columns
  for (int j=1; j<=nx; j++) {
    //cout<<"xx["<<1<<":"<<ix+nx2<<","<<j   <<"] ="
    //<<"xx["<<1<<":"<<ix+nx2<<","<<nxp1<<"]"<<endl;
    
    copy_subarray2Di(xx, 1, ix+nx2, j,
    	     xx, 1, ix+nx2, nxp1);
  }

  //right columns
  for (int j=1; j<=nx; j++) {
    //cout<<"xx["<<1<<":"<<ix+nx2<<","<<j+jx+nx   <<"] ="
    //<<"xx["<<1<<":"<<ix+nx2<<","<<jx+nx<<"]"<<endl;
    
    copy_subarray2Di(xx, 1, ix+nx2, j+jx+nx,
		     xx, 1, ix+nx2,   jx+nx);
    
  }
}

//
// This generic copy subarray function will do the following
//  target(ti_start:ti_end) = src(si_start:si_end)
// 


void Util::copy_subarray1D(Fortran_Array1D<float>& target,
			   const int& ti_start, const int& ti_end,
			   const Fortran_Array1D<float>& src, 
			   const int& si_start, const int& si_end) {
  
  //check if (i,j) indices are in valid range
  assert(ti_start>=1&&ti_start<=target.dim1());
  assert(ti_end>=1&&ti_end<=target.dim1());

  assert(si_start>=1&&si_start<=src.dim1());
  assert(si_end>=1&&si_end<=src.dim1());

  // check validity of (i,j) indices
  assert(ti_end>=ti_start); 

  assert(si_end>=si_start); 

  int t_extent1(1);
  int s_extent1(1);
  
  t_extent1 = ti_end-ti_start+1;  
  s_extent1 = si_end-si_start+1;  

  assert(t_extent1==s_extent1);
  
  //number of elements match up, now place the subarray
  int si, ti;
  
  for (si=si_start,ti=ti_start; 
       si<=si_end && ti<=ti_end; 
       si++, ti++) {
    
    target(ti) = src(si);
    
  }
}

//
// convenince function for doing the following:
//  target(start:end) = source(:)
//
void Util::copy_subarray1D(Fortran_Array1D<float>& target,
			   const int& ti_start, const int& ti_end,
			   const Fortran_Array1D<float>& src) {
  
  copy_subarray1D(target, ti_start, ti_end, 
		  src,    1,        src.dim1());
  
}

float Util::geodesic_distance(float lat0, float lon0,
                              float lat1, float lon1) {

  float PI = 4.0f * atan(1.0f);
  float RADIAN = 180.0f/PI;
  float RADIUS = 6371.0;
  float rlon_0 = lon0/RADIAN;
  float rlat_0 = lat0/RADIAN;
  float rlon_1 = lon1/RADIAN;
  float rlat_1 = lat1/RADIAN;

  float dx = RADIUS * (rlon_1 - rlon_0) * cos(rlat_0);
  float dy = RADIUS * (rlat_1 - rlat_0);
  float dr = sqrt(dx*dx + dy*dy);
 
  return dr;
}


//
// This generic copy subarray function will do the following
//  target(ti_start:ti_end, tj_start:tj_end) = src(si_start:si_end, sj_start:sj_end)
// 


void Util::copy_subarray2D(Fortran_Array2D<float>& target,
			   const int& ti_start, const int& ti_end,
			   const int& tj_start, const int& tj_end, 
			   const Fortran_Array2D<float>& src, 
			   const int& si_start, const int& si_end, 
			   const int& sj_start, const int& sj_end) {
  
  //check if (i,j) indices are in valid range
  assert(ti_start>=1);
  assert(ti_start<=target.dim1());
  assert(ti_end>=1);
  assert(ti_end<=target.dim1());
  
  assert(tj_start>=1&&tj_start<=target.dim2());
  assert(tj_end>=1&&tj_end<=target.dim2());

  assert(si_start>=1&&si_start<=src.dim1());
  assert(si_end>=1&&si_end<=src.dim1());

  assert(sj_start>=1&&sj_start<=src.dim2());
  assert(sj_end>=1&&sj_end<=src.dim2());

  // check validity of (i,j) indices
  assert(ti_end>=ti_start); 
  assert(tj_end>=tj_start);

  assert(si_end>=si_start); 
  assert(sj_end>=sj_start);

  int t_extent1(0);
  int t_extent2(0);
  int s_extent1(0);
  int s_extent2(0);
  
  t_extent1 = ti_end-ti_start+1;  
  t_extent2 = tj_end-tj_start+1;
  s_extent1 = si_end-si_start+1;  
  s_extent2 = sj_end-sj_start+1;

  assert(t_extent1==s_extent1);
  assert(t_extent2==s_extent2);
  
  //number of elements match up, now place the subarray
  int si, sj, ti, tj;
  
  for (si=si_start,ti=ti_start; 
       si<=si_end && ti<=ti_end; 
       si++, ti++) {

  for (sj=sj_start,tj=tj_start; 
       sj<=sj_end && tj<=tj_end; 
       sj++, tj++) {
      
      target(ti,tj) = src(si, sj);
    
    }

  }
}

//
// function will do the following:
//  target(i_start:i_end, j_start:j_end)=src(:,:)
//
//
void Util::copy_subarray2D(Fortran_Array2D<float>& target,
			   const int& ti_start, const int& ti_end,
			   const int& tj_start, const int& tj_end, 
			   const Fortran_Array2D<float>& src) {
  
  copy_subarray2D(target,ti_start, ti_end,     tj_start, tj_end,
		  src,   1,        src.dim1(), 1,        src.dim2());  


}


//
// function will do the following:
//  target(ti_start, tj_start:tj_end)=src(si_start,sj_start:sj_end)
//
//
void Util::copy_subarray2Dj(Fortran_Array2D<float>& target,
			    const int& ti_start, 
			    const int& tj_start, const int& tj_end, 
			    Fortran_Array2D<float>& src,
			    const int& si_start, 
			    const int& sj_start, const int& sj_end) {
  
  copy_subarray2D(target,ti_start, ti_start, tj_start, tj_end,
		  src,   si_start, si_start, sj_start, sj_end);  

}

//
// function will do the following:
//  target(ti_start:ti_end, tj_start)=src(si_start:si_end,sj_start)
//
//
void Util::copy_subarray2Di(Fortran_Array2D<float>& target,
			    const int& ti_start, const int& ti_end,
			    const int& tj_start, 
			    Fortran_Array2D<float>& src,
			    const int& si_start, const int& si_end, 
			    const int& sj_start) {
  
  copy_subarray2D(target,ti_start, ti_end,   tj_start, tj_start,
		  src,   si_start, si_end,   sj_start, sj_start);  

}


//
// function will look at all entries in the range
// v[im:ip, jm:jp]
// boundary conditions are INCLUSIVE!! 
// and return the max value
//

float Util::MAXVAL(const Fortran_Array2D<float> &v, 
			int im, int ip, int jm, int jp) {

float maxval=numeric_limits<float>::min();
  
  for (int i=im; i<=ip; i++) {
    for (int j=jm; j<=jp; j++) {
      float val = v(i,j);
      if (val>maxval)
	maxval=val;
    }
  }

return maxval;
}


float Util::MAXVAL_LOC(const Fortran_Array2D<float> &v,
		   int im, int ip, int jm, int jp,
			int& iwmax, int& jwmax){

  int max_iloc(-1), max_jloc(-1);
  
  float maxval=numeric_limits<float>::min();
  
  for (int i=im; i<=ip; i++) {
    for (int j=jm; j<=jp; j++) {
      float val = v(i,j);
      if (val>maxval) {
	     maxval=val;
		 max_iloc = i;
		 max_jloc = j;
		}
    }
  }
  
  iwmax = max_iloc;
  jwmax = max_jloc;
  
  return maxval;
}


float Util::MAXVAL_All(const Fortran_Array2D<float>& v){

  float maxval=numeric_limits<float>::min();
  
  for (int i=1; i<=v.dim1(); i++) {
    for (int j=1; j<=v.dim2(); j++) {
      float val = v(i,j);
      
      if (val>maxval)
	maxval=val;
    }
  }
  
  return maxval;  
}

float Util::MINVAL_All(const Fortran_Array2D<float> &v){
  
  float minval=numeric_limits<float>::max();
  
  for (int i=1; i<=v.dim1(); i++) {
    for (int j=1; j<=v.dim2(); j++) {
      float val = v(i,j);
      
      if (val<minval)
	minval=val;
    }
  }
  
  return minval;
  
}

// function will return the value of the minimum location in the array
int Util::MINLOC(const Fortran_Array1D<float>& v) {
  float min_val = numeric_limits<float>::max();
  int min_loc = -1;

  for (int i=1; i<=v.dim1(); i++){
    if (v(i)<min_val) {
      min_val = v(i);
      min_loc = i;
    }
  }
  
  return min_loc;
}

int Util::MINLOC(Fortran_Array1D<int>& v) {
  int min_val = numeric_limits<int>::max();
  int min_loc = -1;

  for (int i=1; i<=v.dim1(); i++){
    if (v(i)<min_val) {
      min_val = v(i);
      min_loc = i;
    }
  }
  
  return min_loc;
}


int Util::MINLOC(Fortran_Array1D<int>& v, int start, int end) {
  int min_val = numeric_limits<int>::max();
  int min_loc = -1;
  
  assert(start>=1);
  assert(end<=v.dim1());
  assert(end>=start);
  
  for (int i=start; i<=end; i++){
    if (v(i)<min_val) {
      min_val = v(i);
      min_loc = i;
    }
  }
  
  return min_loc;
}


void Util::scalar_mul2D(Fortran_Array2D<float>& target,
			Fortran_Array2D<float>& source,
			const float& s) {
 
  assert(target.dim1()==source.dim1());
  assert(target.dim2()==source.dim2());

  for (int i=1; i<=target.dim1(); i++) {
    for (int j=1; j<=target.dim2(); j++) {
      target(i,j) = s*source(i,j);
    }
  }
}

    
// target(:) = source(j,:)
void Util::get_Row_2D(Fortran_Array1D<float>& target,
		      const Fortran_Array2D<float>& src,
		      const int& j){

  assert(target.dim1()==src.dim2());
  
  for (int k=1;k<=src.dim2();k++)
    target(k)=src(j,k);
 
}

// target(:) = source(:,k)
void Util::get_Column_2D(Fortran_Array1D<float>& target,
			 const Fortran_Array2D<float>& src,
			 const int& k){
  
  assert(target.dim1()==src.dim1());
  
  for (int i=1;i<=src.dim1();i++)
    target(i)=src(i,k);
  
}

// target(j,:) = source(:)
void Util::insert_Row_2D(Fortran_Array2D<float>& target,
			 const int& j,
			 const Fortran_Array1D<float>& src){

  assert(target.dim2()==src.dim1());  

  for (int k=1;k<=src.dim1();k++)
    target(j,k)=src(k);

}

// target(:,k) = source(:)
void Util::insert_Column_2D(Fortran_Array2D<float>& target,
			    const int& k,
			    const Fortran_Array1D<float>& src){
 
  assert(target.dim1()==src.dim1());  

  for (int i=1;i<=src.dim1();i++)
    target(i,k)=src(i);
 
}

