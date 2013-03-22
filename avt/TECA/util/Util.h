#ifndef UTIL_H
#define UTIL_H

#include "tnt_fortran_array1d.h"
#include "tnt_fortran_array2d.h"

using namespace std;
using namespace TNT;

class Util {
 public:
  
  static void init1DVec(Fortran_Array1D<float>&v, int i);
  static void init1DVec(Fortran_Array1D<int>&v, int i);

  static void init1DVec_padded(Fortran_Array1D<float>& v,
			       const Fortran_Array1D<float>& in);

  static void init2DVec(Fortran_Array2D<float>& v,
			int i, int j);

  static void init2DVec(Fortran_Array2D<int>& v,
			int i, int j);

  static void init2DVec(Fortran_Array2D<bool>& v,
			int i, int j);

  
  static void init2DVec_padded(Fortran_Array2D<float>& v,
			       const Fortran_Array2D<float>& in); 
  
  static void gpad1(Fortran_Array1D<float>& xx,
		    const Fortran_Array1D<float> & Gxx); 

  static void gpad2(Fortran_Array2D<float>& xx,
		    const Fortran_Array2D<float>& Gxx);

  static float MAXVAL(const Fortran_Array2D<float> &v,
		   int im, int ip, int jm, int jp);

  static float MAXVAL_LOC(const Fortran_Array2D<float> &v,
		   int im, int ip, int jm, int jp,
			int& iwmax, int& jwmax);
		   
  static float MAXVAL_All(const Fortran_Array2D<float>& v);
  
  static float MINVAL_All(const Fortran_Array2D<float> &v);

  //  static float SUM_Rows(const Fortran_Array2D<float>& v);

  static int MINLOC(const Fortran_Array1D<float>& v);

  static int MINLOC(Fortran_Array1D<int>& v);

  static int MINLOC(Fortran_Array1D<int>& v, int start, int end);

  static void scalar_mul2D(Fortran_Array2D<float>& target,
			   Fortran_Array2D<float>& source,
			   const float& s);

  static float geodesic_distance(float lat1, float lon1,
                                 float lat2, float lon2);

  //  target(ti_start:ti_end) = src(si_start:si_end)
  //
  static void copy_subarray1D(Fortran_Array1D<float>& target,
			      const int& ti_start, const int& ti_end,
			      const Fortran_Array1D<float>& src, 
			      const int& si_start, const int& si_end);


  //  target(ti_start:ti_end, tj_start:tj_end) = src(si_start:si_end, sj_start:sj_end)
  //
  static void copy_subarray2D(Fortran_Array2D<float>& target,
			      const int& ti_start, const int& ti_end,
			      const int& tj_start, const int& tj_end, 
			      const Fortran_Array2D<float>& src, 
			      const int& si_start, const int& si_end, 
			      const int& sj_start, const int& sj_end);


  // 1D copy convenience functions..
  
  //  target(start:end) = source(:)
  //
  static void copy_subarray1D(Fortran_Array1D<float>& target,
			      const int& ti_start, const int& ti_end,
			      const Fortran_Array1D<float>& src);


  // 2D copy convenience functions..

  //  target(i_start:i_end, j_start:j_end)=src(:,:)
  //
  static void copy_subarray2D(Fortran_Array2D<float>& target,
			      const int& ti_start, const int& ti_end,
			      const int& tj_start, const int& tj_end, 
			      const Fortran_Array2D<float>& src);

  //  target(ti_start, tj_start:tj_end)=src(si_start,sj_start:sj_end) 
  //
  static void copy_subarray2Dj(Fortran_Array2D<float>& target,
			       const int& ti_start, 
			       const int& tj_start, const int& tj_end, 
			       Fortran_Array2D<float>& src,
			       const int& si_start, 
			       const int& sj_start, const int& sj_end);
  
  //  target(ti_start:ti_end, tj_start)=src(si_start:si_end,sj_start)
  //
  static void copy_subarray2Di(Fortran_Array2D<float>& target,
			       const int& ti_start, const int& ti_end,
			       const int& tj_start, 
			       Fortran_Array2D<float>& src, 
			       const int& si_start, const int& si_end, 
			       const int& sj_start);


  // target(:) = source(j,:)
  static void get_Row_2D(Fortran_Array1D<float>& target,
			 const Fortran_Array2D<float>& src,
			 const int& j);

  // target(:) = source(:,k)
  static void get_Column_2D(Fortran_Array1D<float>& target,
			    const Fortran_Array2D<float>& src,
			    const int& k);
  
  // target(j,:) = source(:)
  static void insert_Row_2D(Fortran_Array2D<float>& target,
			    const int& j,
			    const Fortran_Array1D<float>& src);
  
  // target(:,k) = source(:)
  static void insert_Column_2D(Fortran_Array2D<float>& target,
			       const int& k,
			       const Fortran_Array1D<float>& src);
  

  /*
  static s_vector< s_vector<float> > init2dVec(int x, int y);
  static void deallocate2dVec(s_vector< s_vector<float> >& v);

  static s_vector< s_vector<float> > create2DPadding(float* in, int sv1, int sv2);

  static void avg9(s_vector< s_vector<float> >& v);
  
  static void gpad1(s_vector<float>& xx);
  static void gpad2(s_vector< s_vector<float> >& xx);
  
  //  static uint64_t serialize(uint32_t a, uint32_t b);
  //  static uint64_t deserialize(uint64_t k, uint32_t& a, uint32_t& b);
  
  static float MAXVAL(s_vector< s_vector<float> >& v, 
		      int im, int ip, int jm, int jp);

  static float MAXVAL_All(s_vector< s_vector<float> >& v);
  
  static float MINVAL_All(s_vector< s_vector<float> >& v);


  static int MINLOC(vector<float>& v);

  static void getclump(set<uint64_t>& hv, set<uint64_t> * s, 
		       uint32_t vlon, uint32_t vlat);
  */

 private:
  

};

#endif
