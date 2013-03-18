#ifndef AR_DETECT_H
#define AR_DETECT_H

#include <teca_exports.h>

#include <vector>
#include <string>

#include <avtTECAFilter.h>
struct input_params;
struct output_params;

class TECA_API AtmosphericRivers : public avtTECAFilter
{
    typedef struct lat_lon_pair_t
    {
            double lat;
            double lon;
    }lat_lon_pair;

    typedef struct point_t
    {
            int x;
            int y;
    }point;

    void ar_detect_nc (std::vector< std::string >& filenames,
               std::vector< int >& timesteps,
               std::string out_file,
               std::string dataset);

    void init_output_params (output_params *opars);

    long int read_vapor_data_nc_3day (float * vapor_data, input_params *ips,
                                      int rows_from, int rows_to,
                                      int cols_from, int cols_to);

    void vapor_thresholding (float *input, unsigned *output,
                             int low, int high, int rows, int cols);

    inline unsigned afind(const std::vector<unsigned>& equiv,
                          const unsigned ind);

    inline void aset(std::vector<unsigned>& equiv,
                     const unsigned ind, const unsigned val);

    unsigned sauf(const unsigned nrow, const unsigned ncol, unsigned *image);

    int st_in_left_bound_lon (point *ar_points, int count,
                  int cols_from, int timestep);

    int st_in_bottom_bound_lat (point *ar_points, int count,
                    int rows_from, int timestep);

    int en_in_right_bound_lon (int *boundary_c, int count, int cols_from, int timestep);

    int en_in_right_bound_lat_lon (int *boundary_r, int *boundary_c, int count,
                                   int rows_from, int cols_from, int num_rows,
                                   int timestep, output_params *opars);

    void get_lat_long_from_file (int row, int col,
                                 double *lat, double *lon, int timestep);

    double calc_geodesic_distance (double lat1, double lon1, double lat2, double lon2);

    float find_geodesic_width_ar (int bound_pt_x, int bound_pt_y, float ar_len,
                                  int count, int rows_from, int cols_from, int timestep);

    float find_geodesic_length_ar (int *boundary_r, int *boundary_c, int count,
                                   int num_rows, int num_cols, int rows_from, int cols_from,
                                   int timestep);

    void get_boundary_points (int *boundary_row, int *boundary_col,
                              int rows_from, int cols_from,
                              lat_lon_pair *llpairs, int count, int timestep);

    int verify_ar_exist (int num_rows, int num_cols,
                         unsigned *labeled_data, int num_labels,
                         int rows_from, int cols_from, input_params *ips,
                         float *length, float *width, int *pe_or_ar,
                 output_params *opars);

    void get_cutoff_points (int *rows_from, int *cols_from,
                            int *rows_to, int *cols_to, input_params *ips);

    void date_from_days (int days, int *day, int *month, int leap);

    void find_date_from_dfname (input_params *ips, int *yyyy, int *mm, int *dd, int time_step);

    int get_num_input_files (char *ifile);

    int read_data_file_name (int proc_id, char *inputs_file, char *data_file);

    void get_num_time_steps (char *ifname, int *num_ts_array);

    void dump_output_params (output_params *opars, char* output_file_name, int pe_or_ar);
};

#endif // AR_DETECT_H
