#ifndef tropical_cyclones_h
#define tropical_cyclones_h

#include <teca_exports.h>

#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "util/tnt_fortran_array1d.h"
#include "util/tnt_fortran_array2d.h"

#include <avtTECAFilter.h>
#include <avtCalendar.h>

class TstormsDriver;

class TECA_API TstormsTimestep
{

public:
    TstormsTimestep(int, TstormsDriver* driver, std::string name, std::string logname);

    void initialize_thresholds();
    void print_thresholds();

    void set_default_thresholds();
    void set_threshhold(std::string name, float val);

    void changeTimestep(int t);

    void go();
    void mainloop();
//    int date[6];
    avtCalendar::ComptimeObject date;

    float crit_vort, crit_twc, crit_thick, crit_dist, dist_twc, crit_psl, dist_psl, lat_bound_n, lat_bound_s, atwc;
    bool do_smoothing, use_sfc_wind;

    ofstream result_file;
    ofstream logfile;

//private:
    void read_data();
    void preprocess_data();

    void static_initialize();
    void static_cleanup();
    void cleanup();
    void final_cleanup();

    float geodesic_distance(float lat1, float lon1,
                        float lat2, float lon2);

    void initialize_splines();

    void setdate();

    void comp_vort(const TNT::Fortran_Array2D<float>&, const TNT::Fortran_Array2D<float>&);
    void comp_wind(const TNT::Fortran_Array2D<float>&, const TNT::Fortran_Array2D<float>&);
    int  calendar(int);
    bool contains_leap_year(float);
    bool contains(std::string, std::string);

    void storeResults(int i, int j,
              float vort_max, float lon_vort, float lat_vort,
              float psl_min, float lon_psl, float lat_psl,
              float twc_max, float lon_twc, float lat_twc,
              bool exist_twc,
              float thick_max, float lon_thick, float lat_thick,
              bool exist_thick,
              float wind_max);

    void outputResultsToFile();
//    void set_dx_dy(TNT::Fortran_Array1D<float>& dx, float& dy);
//    void read3dTimestep(const std::string& var, int timestep, TNT::Fortran_Array2D<float>& v, bool do_padding);

    TstormsDriver* data;
    //NetCDFInterface * data;
    int timestep;
    int storm_count;

    int size;
    int rank;

//    TNT::Fortran_Array1D<float> Glat; /// HK: provide all lat, long values..
//    TNT::Fortran_Array1D<float> Glon;

    TNT::Fortran_Array1D<float> rlat;
    TNT::Fortran_Array1D<float> rlon;

    TNT::Fortran_Array1D<float> dx;
    float dy;

    TNT::Fortran_Array2D<float> vort, Gvort;
    TNT::Fortran_Array2D<float> wind, Gwind;
    TNT::Fortran_Array2D<float> precip, Gprecip;

    TNT::Fortran_Array2D<float> tbar, Gtbar;
    TNT::Fortran_Array2D<float> psl,  Gpsl;
    TNT::Fortran_Array2D<float> thick,Gthick;

    TNT::Fortran_Array2D<float> wrk1;
    TNT::Fortran_Array2D<float> wrk2;

    TNT::Fortran_Array2D<float> psl_dy;
    TNT::Fortran_Array2D<float> psl_dx;
    TNT::Fortran_Array2D<float> tbar_dy;
    TNT::Fortran_Array2D<float> tbar_dx;
    TNT::Fortran_Array2D<float> thick_dy;
    TNT::Fortran_Array2D<float> thick_dx;

    int iday, imon, iyear, ihour;

    //Spline spline;

    //these are the final result variables..
    std::vector<int> ridex, rjdex;
    std::vector<float> rvort_max, rvort_lon, rvort_lat;
    std::vector<float> rwind_max, rdist_wmax;
    std::vector<float> rprecip_max, rdist_precipmax;
    std::vector<float> rpsl_min, rpsl_lon, rpsl_lat;

    std::vector<float> rtwc_max, rtwc_lon, rtwc_lat;
    std::vector<bool> rexist_twc;

    std::vector<bool> rexist_thick;
    std::vector<float> rthick_max, rthick_lon, rthick_lat;

};

class Trajectory {

public:
    Trajectory(const char *input_filename);

    void cleanup();

    bool contains(std::string a, std::string b);
    void set_threshhold(std::string name, float val);
    std::ifstream input_file;
    std::ifstream cmask_file;
    std::ifstream ori;
    std::ifstream stats;

    std::ofstream trajectory_results;
    std::ofstream trajectory_summary;
    std::ofstream trajectory_origins;
    std::ofstream trajectory_sixhourly;
    std::ofstream visit_output;

    void static_initialize();

    int get_hurricane_category(float windmax);

    void initialize_thresholds();
    float rcrit;
    float wcrit;
    int  nwcrit;
    bool do_filt;
    float PI,RADIAN,RADIUS;

    void read_data();

    void evaluate_trajectories();

    void compute_traj_stats(int type, bool six_hour);
    void compute_stats();

    void compute_summary();

    void print_summary();

    TNT::Fortran_Array2D<float> rlon;
    TNT::Fortran_Array2D<float> rlat;
    TNT::Fortran_Array2D<float> wind;
    TNT::Fortran_Array2D<float> wind_radius;
    TNT::Fortran_Array2D<float> precip;
    TNT::Fortran_Array2D<float> precip_radius;
    TNT::Fortran_Array2D<float> vort;
    TNT::Fortran_Array2D<float> psl;

    TNT::Fortran_Array2D<bool> available;
    TNT::Fortran_Array2D<bool> exist_wind;
    TNT::Fortran_Array2D<bool> exist_twc;
    TNT::Fortran_Array2D<bool> exist_thick;

    TNT::Fortran_Array1D<int> day;
    TNT::Fortran_Array1D<int> month;
    TNT::Fortran_Array1D<int> year;
    TNT::Fortran_Array1D<int> number;
    TNT::Fortran_Array1D<int> hour;


    TNT::Fortran_Array1D<int> icand;
    TNT::Fortran_Array1D<int> jcand;
    TNT::Fortran_Array1D<int> ix;
    TNT::Fortran_Array1D<int> iy;
    TNT::Fortran_Array1D<int> bon_1;
    TNT::Fortran_Array1D<int> bon_2;
    TNT::Fortran_Array1D<int> rtot;

    int numax;
    int nmaxtrak;
    int lonmax;
    int nrmax;
    int mdays;

};


class TstormsDriver : public avtTECAFilter
{
public:
    /// input information
    stringVector GetVariables();
    RequestedTimeFrame GetRequestedTimeFrame();

    /// execute phase..
    void ExecuteProcess();

    /// output information
    void CollectResults();
    avtDataTree_p CreateOutput();

    void set_dx_dy(TNT::Fortran_Array1D<float>& dx, float& dy);
    void read3dTimestep(const std::string& var, int timestep, TNT::Fortran_Array2D<float>& v, bool do_padding);
    TNT::Fortran_Array1D<float> Glat; /// HK: provide all lat, long values..
    TNT::Fortran_Array1D<float> Glon;

};
#endif
