/**********************
ar_detect.cpp
Author: Suren Byna <SByna@lbl.gov>
Lawrence Berkeley Lab

Description:
This is an implementation to detect Atmospheric Rivers in a given vapor data. Current implementation reads vapor data from given files and calculates 3 day average data files. The ar_detect funtion thresholds the vapor data to a low and high values and then labels the data. The labeled data is then passed to SAUF (Scan with Array-based Union Find) funtion to identify connected  components in 2D array. The generated connected component labels are then scanned to verify whether any vapor bands (atmospheric rivers) originating tropical area and ending at any land. When high moisture touches land, there could be a lot of rain fall, which would affect human lives. The vapor thresholds, region of interest, and origin and destination of vapor bands are parameterized to detect atmospheric rivers in any given region of the world map.

**********************/

#include "AtmosphericRivers.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//#include <netcdf.h>
#include "params.h"

avtTECA::RequestedTimeFrame
AtmosphericRivers::GetRequestedTimeFrame()
{
    return avtTECA::ThreeDays;
}

stringVector AtmosphericRivers::GetVariables()
{
    stringVector vars;
    vars.push_back(LON_VAR_NAME);
    vars.push_back(LAT_VAR_NAME);
    vars.push_back(DATA_VAR_NAME);

    return vars;
}

void
AtmosphericRivers::ExecuteProcess()
{

//    ar_detect_nc(timesteps,in_file, out_file, dataset);

//    void AtmosphericRivers::ar_detect_nc (const std::vector< int >& timesteps,
//                                          const std::string& in_file,
//                                          const std::string& out_file,
//                                          const std::string& dataset);
}

void
AtmosphericRivers::CollectResults()
{

}

avtDataTree_p
AtmosphericRivers::CreateOutput()
{
    return new avtDataTree();
}

// read vapor data from netCDF file for three time steps and average them
// Assuming each time step data refers to 1 day's data
// This version reads a block of 2D vapor array using start [] and count []
//      values that are specific to a desired region
//      from three time steps and averages them
long int
AtmosphericRivers::read_vapor_data_nc_3day (float * vapor_data, input_params * ips, \
                                  int rows_from, int rows_to,           \
                                  int cols_from, int cols_to)
{
    int retval;//, ncid[3], varid[3];
    int pos, start_pos, avg_count;

    // Find the block size to read
    int num_cols = cols_to - cols_from;
    int num_rows = rows_to - rows_from;

    // Allocate buffer for partial data for each time step
    float part_vapor_data[num_rows][num_cols];


    // init vapor data to 0 -- Just to make sure there is no garbage
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            pos = i * num_cols + j;
            vapor_data[pos] = 0;
        }
    }

    avg_count = 3;

    // read and sum data from all the time steps
    for (int iter = 0; iter < avg_count; iter++)
    {
        start_pos = ips->time_step[iter];

        static size_t start[] = {start_pos, rows_from, cols_from};
        static size_t count[] = {1, num_rows, num_cols};


        if( retval = GetData(DATA_VAR_NAME, ips->time_step[iter], start, count, &part_vapor_data[0][0]) )
        {
//            printf ("Timestep: %d Error 3:%d: %s Filename: %s\n",
//                    ips->time_step[iter], iter+1,
//                    retval,
//                    ips->ifname[iter]);
            //exit (2);
            throw VisItException("Error getting data: 86");
        }

        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                pos = i * num_cols + j;
                vapor_data[pos] = vapor_data[pos] + part_vapor_data[i][j];
            }
        }
    }

    // 3-day average
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            pos = i * num_cols + j;
            vapor_data[pos] = vapor_data[pos]/avg_count;
        }
    }

    return (num_rows * num_cols);
}
// end read_vapor_data_nc_3day ()

// Threshold vapor data with low and high values
void
AtmosphericRivers::vapor_thresholding (float *input, unsigned *output,
                  int low, int high, int rows, int cols)
{
    int i, j;

    float vapor_val;
    long int pos;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            pos = i * cols + j;
            vapor_val = input[pos];
            if (vapor_val >= low && vapor_val <= high)
            {
                output[pos] = 1;
            }
            else
            {
                output[pos] = 0;
            }
        }
    }
#ifdef DEBUG
    printf ("Done thresholding...\n");
#endif
}

// Code borrowed from John Wu's sauf.cpp
// Find the minimal value starting @arg ind.
inline unsigned
AtmosphericRivers::afind(const std::vector<unsigned>& equiv,
              const unsigned ind)
{
    unsigned ret = ind;
    while (equiv[ret] < ret)
    {
        ret = equiv[ret];
    }
    return ret;
}
// end afind

// Set the values starting with @arg ind.
inline void
AtmosphericRivers::aset(std::vector<unsigned>& equiv,
         const unsigned ind, const unsigned val)
{
    unsigned i = ind;
    while (equiv[i] < i)
    {
        unsigned j = equiv[i];
        equiv[i] = val;
        i = j;
    }
    equiv[i] = val;
} // aset

// SAUF -- Scan with Array-based Union-Find.
// This is an implementation that follows the decision try to minimize
// number of neighbors visited and uses the array-based union-find
// algorithms to minimize work on the union-find data strucutre.  It works
// with each pixel/cell of the 2D binary image individually.
// The 2D binary image is passed to sauf as a unsigned*.  On input, the
// zero value is treated as the background, and non-zero is treated as
// object.  On successful completion of this function, the non-zero values
// in array image is replaced by its label.
// The return value is the number of components found.
unsigned
AtmosphericRivers::sauf(const unsigned nrow, const unsigned ncol, unsigned *image)
{
    const unsigned ncells = ncol * nrow;
    const unsigned ncp1 = ncol + 1;
    const unsigned ncm1 = ncol - 1;
    std::vector<unsigned int> equiv;	// equivalence array
    unsigned nextLabel = 1;

    equiv.reserve(ncol);
    equiv.push_back(0);

    // the first cell of the first line
    if (*image != 0)
    {
    *image = nextLabel;
    equiv.push_back(nextLabel);
    ++ nextLabel;
    }
    // first row of cells
    for (unsigned i = 1; i < ncol; ++ i)
    {
    if (image[i] != 0)
    {
        if (image[i-1] != 0)
        {
        image[i] = image[i-1];
        }
        else
        {
        equiv.push_back(nextLabel);
        image[i] = nextLabel;
        ++ nextLabel;
        }
    }
    }

    // scan the rest of lines, check neighbor b first
    for (unsigned j = ncol; j < ncells; j += ncol)
    {
    unsigned nc, nd, k, l;

    // the first point of the line has two neighbors, and the two
    // neighbors must have at most one label (recorded as nc)
    if (image[j] != 0)
    {
        if (image[j-ncm1] != 0)
        nc = image[j-ncm1];
        else if (image[j-ncol] != 0)
        nc = image[j-ncol];
        else
        nc = nextLabel;
        if (nc != nextLabel) { // use existing label
        nc = equiv[nc];
        image[j] = nc;
        }
        else { // need a new label
        equiv.push_back(nc);
        image[j] = nc;
        ++ nextLabel;
        }
    }

    // the rest of the line
    for (unsigned i = j+1; i < j+ncol; ++ i)
    {
        if (image[i] != 0) {
        if (image[i-ncol] != 0) {
            nc = image[i-ncol];
            l = afind(equiv, nc);
            aset(equiv, nc, l);
            image[i] = l;
        }
        else if (i-ncm1<j && image[i-ncm1] != 0) {
            nc = image[i-ncm1];

            if (image[i-1] != 0)
            nd = image[i-1];
            else if (image[i-ncp1] != 0)
            nd = image[i-ncp1];
            else
            nd = nextLabel;
            if (nd < nextLabel) {
            k = afind(equiv, nc);
            l = afind(equiv, nd);
            if (l <= k) {
                aset(equiv, nc, l);
                aset(equiv, nd, l);
            }
            else {
                l = k;
                aset(equiv, nc, k);
                aset(equiv, nd, k);
            }
            image[i] = l;
            }
            else {
            l = afind(equiv, nc);
            aset(equiv, nc, l);
            image[i] = l;
            }
        }
        else if (image[i-1] != 0) {
            nc = image[i-1];
            l = afind(equiv, nc);
            aset(equiv, nc, l);
            image[i] = l;
        }
        else if (image[i-ncp1] != 0) {
            nc = image[i-ncp1];
            l = afind(equiv, nc);
            aset(equiv, nc, l);
            image[i] = l;
        }
        else { // need a new label
            equiv.push_back(nextLabel);
            image[i] = nextLabel;
            ++ nextLabel;
        }
        }
    }
    } // for (unsigned j ...

    // phase II: re-number the labels to be consecutive
    nextLabel = 0;
    const unsigned nequiv = equiv.size();
    for (unsigned i = 0; i < nequiv;  ++ i) {
    if (equiv[i] < i) { // chase one more time
#if defined(_DEBUG) || defined(DEBUG)
        std::cout << i << " final " << equiv[i] << " ==> "
              << equiv[equiv[i]] << std::endl;
#endif
        equiv[i] = equiv[equiv[i]];
    }
    else { // change to the next smallest unused label
#if defined(_DEBUG) || defined(DEBUG)
        std::cout << i << " final " << equiv[i] << " ==> "
              << nextLabel << std::endl;
#endif
        equiv[i] = nextLabel;
        ++ nextLabel;
    }
    }

    if (nextLabel < nequiv) {// relabel all cells to their minimal labels
    for (unsigned i = 0; i < ncells; ++ i)
        image[i] = equiv[image[i]];
    }

#if defined(_DEBUG) || defined(DEBUG)
    std::cout << "sauf(" << nrow << ", " << ncol << ") assigned "
          << nextLabel-1 << " label" << (nextLabel>2?"s":"")
          << ", used " << nequiv << " provisional labels"
          << std::endl;
#endif
    return nextLabel-1;
} // sauf
// end code borrowed from John Wu's sauf.cpp

int
AtmosphericRivers::st_in_left_bound_lon (point *ar_points, int count, int cols_from, int timestep)
{
    int retval;
    double lon_val;
    size_t index[2];

    for (int i = 0; i < count; i++)
    {
        index[0] = index[1] = (size_t) (ar_points[i].y + cols_from);

        if( retval = GetLongVal(timestep,index, lon_val) )
        {
            //printf ("Error 23: %s\n",retval));
            //exit (2);
        }

        if (lon_val >= LEFT_BOUND_LON)	// <= may be different based on region
        {
            return 1;
        }
    }

    return 0;
}

int
AtmosphericRivers::st_in_bottom_bound_lat (point *ar_points, int count, int rows_from, int timestep)
{
    int retval;
    double lat_val;
    size_t index[2];

    for (int i = 0; i < count; i++)
    {
        index[0] = index[1] = (size_t) (ar_points[i].x + rows_from);
        if( retval = GetLatVal(timestep, index, lat_val))
        {
            //printf ("Error 23: %s\n", nc_strerror(retval));
            //exit (2);
        }

        if (lat_val >= BOT_BOUND_LAT)	// >= may be different based on region
        {
            return 1;
        }
    }
    return 0;
}

int
AtmosphericRivers::en_in_right_bound_lon (int *boundary_c, int count, int cols_from, int timestep)
{
    int retval;
    double lon_val;
    size_t index[2];

    // Look for lon variable
    for (int i = 0; i < count; i++)
    {
        index[0] = index[1] = (size_t) (boundary_c[i] + cols_from);
        //if ((retval = nc_get_var1_double (ncid, lon_varid, index, &lon_val)))
        if (retval = GetLongVal(timestep, index, lon_val))
        {
//            printf ("Error 23: %s\n", nc_strerror(retval));
//            exit (2);
        }

        if (lon_val >= RIGHT_BOUND_LON_1 &&	\
            lon_val <= RIGHT_BOUND_LON_2)  // <= may be different based on region
        {
            return 1;
        }
    }

    return 0;
}

int
AtmosphericRivers::en_in_right_bound_lat_lon (int *boundary_r, int *boundary_c, int count, \
                   int rows_from, int cols_from, int num_rows,  \
                   int timestep, output_params *opars)
{
    int retval;
    double lon_val, lat_val;
    size_t index[2];
    int end_col_idx[num_rows];
    int end_col_count = 0;
    int touch_down = 0;


    for (int i = 0; i < count; i++)
    {
        index[0] = index[1] = (size_t) (boundary_c[i] + cols_from);
        //if ((retval = nc_get_var1_double (ncid, lon_varid, index, &lon_val)))
        if(retval = GetLongVal(timestep,index,lon_val))
        {
//            printf ("Error 433: %s\n", nc_strerror(retval));
//            exit (2);
        }

        // Due to the lack of exact land masks for the western coast of the US,
        // Using approximate land mask boundaries
        if ((lon_val >= RIGHT_BOUND_LON_1) &&	\
            (lon_val <= RIGHT_BOUND_LON_2))  // <= may be different based on region
        {
            end_col_idx[end_col_count] = i;
            end_col_count++;
        }
    }

    // look for rows that fall between lat boundaries
    touch_down = 0;
    int top_touch = 0;
    double top_lat, top_lon;
    double bot_lat, bot_lon;

    if (end_col_count > 0)
    {
        for (int i = 0; i < end_col_count; i++)
        {
            index[0] = index[1] = (size_t) (boundary_r[end_col_idx[i]] + rows_from);
            //if ((retval = nc_get_var1_double (ncid, lat_varid, index, &lat_val)))
            if(retval = GetLatVal(timestep,index,lat_val))
            {
//                printf ("Error 46: %s\n", nc_strerror(retval));
//                exit (2);
            }

            //if ((retval = nc_get_var1_double (ncid, lon_varid, index, &lon_val)))
            if(retval = GetLongVal(timestep,index,lon_val))
            {
//                printf ("Error 47: %s\n", nc_strerror(retval));
//                exit (2);
            }
            // Due to the lack of exact land masks for the western coast of the US,
            // Using approximate land mask boundaries
            if ((lat_val >= RIGHT_BOUND_LAT_1) &&
            (lat_val <= RIGHT_BOUND_LAT_2))
            {
                touch_down = 1;
                if (top_touch == 0)
                {
                    top_lat = lat_val;
                    top_lon = lon_val;
                    top_touch = 1;
                }
                bot_lat = lat_val;
                bot_lon = lon_val;
            }
        }
    }

    opars->end_top_lat = top_lat;
    opars->end_top_lon = top_lon;
    opars->end_bot_lat = bot_lat;
    opars->end_bot_lon = bot_lon;
    return touch_down;
}

void
AtmosphericRivers::get_lat_long_from_file (int row, int col,
                 double *lat, double *lon, int timestep)
{
    int retval;
    double lat_val;
    double lon_val;
    size_t index[2];

    // Read lat
    index[0] = index[1] = (size_t) row;
    //if ((retval = nc_get_var1_double (ncid, lat_varid, index, &lat_val)))
    if(retval = GetLatVal(timestep,index,lat_val))
    {
//        printf ("Error 13: %s\n", nc_strerror(retval));
//        exit (2);
    }
    index[0] = index[1] = (size_t) col;

    //if ((retval = nc_get_var1_double (ncid, lon_varid, index, &lon_val)))
    if(retval = GetLongVal(timestep,index,lon_val))
    {
//        printf ("Error 23: %s\n", nc_strerror(retval));
//        exit (2);
    }

    *lat = lat_val;
    *lon = lon_val;
}

// Calculate geodesic distance between two lat, long pairs
// from http://www.geodatasource.com/developers/c
// from http://osiris.tuwien.ac.at/~wgarn/gis-gps/latlong.html
// from http://www.codeproject.com/KB/cpp/Distancecplusplus.aspx
double
AtmosphericRivers::calc_geodesic_distance (double lat1, double lon1, double lat2, double lon2)
{
    double R = 6371;
        double PI = 4.0 * atan(1.0);

        //main code inside the class
        double dlat1 = lat1 * (PI/180);

        double dlon1 = lon1 * (PI/180);
        double dlat2 = lat2 * (PI/180);
        double dlon2 = lon2 * (PI/180);

        double dLon = dlon1 - dlon2;
        double dLat = dlat1 - dlat2;

        double aHarv = 	pow (sin (dLat/2.0), 2.0) +	\
            cos (dlat1) * cos (dlat2) * pow (sin (dLon/2), 2);

        double cHarv = 2 * atan2 (sqrt(aHarv), sqrt(1.0 - aHarv));

        double distance = R*cHarv;

    return distance;
}

// This function calculates the average geodesic width
// As each pixel represents certain area, the total area
// is the product of the number of pixels and the area of
// one pixel. The average width is: the total area devided
// by the medial axis length
// We are calculating the average width, since we are not
// determining where exactly to cut off the tropical region
// to calculate the real width of an atmospheric river
float
AtmosphericRivers::find_geodesic_width_ar (int bound_pt_x, int bound_pt_y, float ar_len, \
                int count, int rows_from, int cols_from, int timestep)
{
    // Find pixel area
    int pixel_x = bound_pt_x + rows_from;
    int pixel_y = bound_pt_y + cols_from;

    int pixel_right_x = pixel_x;
    int pixel_right_y = pixel_y + 1;

    int pixel_bot_x = pixel_x + 1;
    int pixel_bot_y = pixel_y;

    double lat_val[2];
    double lon_val[2];

    get_lat_long_from_file (pixel_x, pixel_y, \
            &lat_val[0], &lon_val[0], timestep);
    get_lat_long_from_file (pixel_right_x, pixel_right_y, \
            &lat_val[1], &lon_val[1], timestep);

    float dim1 = calc_geodesic_distance (lat_val[0], lon_val[0], \
                lat_val[1], lon_val[1]);

    get_lat_long_from_file (pixel_bot_x, pixel_bot_y, \
            &lat_val[1], &lon_val[1], timestep);

    float dim2 = calc_geodesic_distance (lat_val[0], lon_val[0], \
                lat_val[1], lon_val[1]);

    // This is the area of one pixel
    float pixel_area = dim2 * dim2;	   // Modify if there is a better way

    // The total area
    float total_area = pixel_area * count;

    // Find average width
    float width = total_area / ar_len;

    return width;
}


// Medial length is the sum of the distances between the medial
// points in the connected component
float
AtmosphericRivers::find_geodesic_length_ar (int *boundary_r, int *boundary_c, int count, \
                   int num_rows, int num_cols, int rows_from, int cols_from, 	\
                   int timestep)
{
    int jb_r1[num_rows];
    int jb_c1[num_rows], jb_c2[num_rows];

    int b_count = 0;
    int row_track;

    row_track = -1;

    for (int i = 0; i < count; i++)
    {
        if (row_track != boundary_r[i])
        {
            b_count++;
            jb_r1[b_count-1] = boundary_r[i] + rows_from;
            jb_c1[b_count-1] = boundary_c[i] + cols_from;
            row_track = boundary_r[i];
        }
        jb_c2[b_count-1] = boundary_c[i] + cols_from;
    }

    double lat_val[2];
    double lon_val[2];
    float total_dist = 0;
    int mid_col[2];

    for (int i = 0; i < b_count-1; i++)
    {
        mid_col[0] = floor ((jb_c2[i] - jb_c1[i])/2);
        mid_col[1] = floor ((jb_c2[i+1] - jb_c1[i+1])/2);

        get_lat_long_from_file (jb_r1[i], mid_col[0], \
                &lat_val[0], &lon_val[0], timestep);
        get_lat_long_from_file (jb_r1[i+1], mid_col[1], \
                &lat_val[1], &lon_val[1], timestep);
        total_dist += calc_geodesic_distance (lat_val[0], lon_val[0], \
                    lat_val[1], lon_val[1]);
    }
    return total_dist;
}

void
AtmosphericRivers::get_boundary_points (int *boundary_row, int *boundary_col, \
              int rows_from, int cols_from, 	\
              lat_lon_pair *llpairs, int count, int timestep)
{
    int retval;
    double lat_val, lon_val;
    size_t index[2];


    // Read lat
    for (int i = 0; i < count; i++)
    {
        index[0] = index[1] = (size_t) boundary_row[i] + rows_from;
        //if ((retval = nc_get_var1_double (ncid, lat_varid, index, &lat_val)))
        if(retval = GetLatVal(timestep, index, lat_val))
        {
//            printf ("Error 13: %s\n", nc_strerror(retval));
//            exit (2);
        }

        index[0] = index[1] = (size_t) boundary_col[i] + cols_from;
        //if ((retval = nc_get_var1_double (ncid, lon_varid, index, &lon_val)))
        if(retval = GetLongVal(timestep, index, lon_val))
        {
//            printf ("Error 23: %s\n", nc_strerror(retval));
//            exit (2);
        }
        llpairs[i].lat = lat_val;
        llpairs[i].lon = lon_val;

#ifdef DUMP_OUTPUT
        printf ("llp.lat: %f  llp.lon: %f \n", llpairs[i].lat,	\
            llpairs[i].lon);
#endif
    }

}

int
AtmosphericRivers::verify_ar_exist (int num_rows, int num_cols, \
              unsigned *labeled_data, int num_labels,
              int rows_from, int cols_from, input_params *ips,
              float *length, float *width, int *pe_or_ar, output_params *opars)
{
    int pos, count;
    point *ar_points = (point *) malloc (sizeof (point) * num_rows * num_cols);
    int *boundary_r = (int *) malloc (sizeof (int) * num_rows*num_cols);
    int *boundary_c = (int *) malloc (sizeof (int) * num_rows*num_cols);

    // Conditions
    int start_in_bot_bound;
    int start_in_left_bound;
    int end_in_right_bound;

    // for all discrete connected component labels
    // verify if there exists an AR
    for (int i = 1; i < num_labels+1; i++)
    {
        count = 0;
        start_in_bot_bound = 0;
        start_in_left_bound = 0;
        end_in_right_bound = 0;

        // get all the points of this connected component
        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                pos = r * num_cols + c;
                if (labeled_data[pos] == i)
                {
                    ar_points[count].x = r;
                    ar_points[count].y = r;
                    *(boundary_r+count) = r;
                    *(boundary_c+count) = c;
                    count++;
                }
            }
        }

        // Number of points in a pineapple express is % of points in regious mesh
        int thr_count = num_rows * num_cols * THRESHOLD_PERCENT_IN_MESH/100;

        if (count > thr_count)
        {
            // Test boundary elements
            // Is start in left bound? i.e. has it started a tropical region
            // much farther from Hawaii, probably near Indonasia
            start_in_left_bound = \
                st_in_left_bound_lon (ar_points, count, \
                    cols_from, ips->time_step[2]);

            // Is start in tropical region bound?
            start_in_bot_bound = \
                st_in_bottom_bound_lat (ar_points, count, \
                    rows_from, ips->time_step[2]);

            // Is end in right bound?
            if ((start_in_left_bound == 1) || (start_in_bot_bound == 1))
            {
                end_in_right_bound = \
                en_in_right_bound_lat_lon (boundary_r, boundary_c, count, \
                    rows_from, cols_from, num_rows, ips->time_step[2], opars);
            }
            else
            {
                return -1;
            }

            // If the origin and destination criteria are met:
            if (   ((start_in_left_bound == 1) || \
                (start_in_bot_bound == 1)) &&  \
                (end_in_right_bound == 1)  \
               )
            {
                //Is the component long enough? > 2000 km
                float ar_len = find_geodesic_length_ar (boundary_r, \
                            boundary_c, count, 	    \
                            num_rows, num_cols, 	    \
                            rows_from, cols_from, 	    \
                            ips->time_step[2]);

                opars->length = ar_len;
#ifdef DEBUG
                printf ("Timestep: %d AR Length: %.3f \n", ips->time_step [2], ar_len);
#endif

                if (ar_len >= AR_LENGTH_KMS)
                {
                    //Is the component thin enough? < 1000 km
                    float ar_wid = find_geodesic_width_ar (\
                                boundary_r[0], boundary_c[0], \
                                ar_len, count, rows_from,     \
                                cols_from, \
                                ips->time_step[2]);

                    opars->width = ar_wid;
#ifdef DEBUG
                    printf ("Rank: %d AR Width: %.3f \n", ips->time_step [2], ar_wid);
#endif
                    *length = ar_len;
                    *width = ar_wid;

                    if (ar_wid <= AR_WIDTH_KMS)
                    {
                        if (start_in_bot_bound == 1)
                        {
                            *pe_or_ar = 1;	// It's a PE
                        }
                        else if (start_in_left_bound == 1)
                        {
                            *pe_or_ar = 2;	// It's an AR, but not PE
                        }
                        // return that all the conditions are met
                        return 10;
                    }
                }
            }
        }
    }
    free (ar_points);
    free (boundary_r);
    free (boundary_c);
    return -1;
}

// Calculate cutoff points required for desired global region
// Not used
// Using get_cutoff_points ()
/*
void calc_cutoff_points (int *rows_from, int *cols_from, int *rows_to, int *cols_to)
{
    *rows_from = (int) ((LAT_BOT + 90 - (DEG_GRAN_LAT/2))/DEG_GRAN_LAT);
    *cols_from = (int) (LONG_LEFT - (DEG_GRAN_LON/2))*(1/DEG_GRAN_LON);
    *rows_to = (int) (LAT_TOP + 90 - (DEG_GRAN_LAT/2))*(1/DEG_GRAN_LAT);
    *cols_to = (int) ((LONG_RIGHT - (DEG_GRAN_LON/2))/DEG_GRAN_LON);

    // *rows_from = (int) ((LAT_BOT + 89.875)/0.25);
    // *cols_from = (int) (LONG_LEFT - 0.125)*4;
    // *rows_to = (int) (LAT_TOP + 89.875)*4;
    // *cols_to = (int) ((LONG_RIGHT - 0.125)/0.25);

#ifdef DEBUG
    printf ("Rows from: %d, Rows to: %d \n", *rows_from, *rows_to);
    printf ("Cols from: %d, Cols to: %d \n", *cols_from, *cols_to);
#endif
}
*/

void
AtmosphericRivers::get_cutoff_points (int *rows_from, int *cols_from, \
            int *rows_to, int *cols_to, input_params *ips)
{
    int retval;
    size_t lat_dim, lon_dim;
    int rows_from_flag = 0;
    int cols_from_flag = 0;
    double lat_val;
    double lon_val;

    int timestep = ips->time_step[2];

#ifdef DEBUG
    printf ("num_lats: %d  num_lons: %d \n", lat_dim, lon_dim);
#endif

    ips->num_lats = (int) lat_dim;
    ips->num_lons = (int) lon_dim;

    // Read lat values
    size_t index[2];

    for (int i = 0; i < ips->num_lats; i++)
    {
        index[0] = index[1] = (size_t) i;
        //if ((retval = nc_get_var1_double (ncid, lat_varid, index, &lat_val)))
        if(retval = GetLatVal(timestep, index, lat_val))
        {
//            printf ("Error 33: %s\n", nc_strerror(retval));
//            exit (2);
        }
        if (rows_from_flag == 0 && lat_val >= LAT_BOT)
        {
            *rows_from = i;
            rows_from_flag = 1;
        }
        if (lat_val >= LAT_TOP)
        {
            *rows_to = i;
            break;
        }
    }

    for (int i = 0; i < ips->num_lons; i++)
    {
        index[0] = index[1] = (size_t) i;
        //if ((retval = nc_get_var1_double (ncid, lon_varid, index, &lon_val)))
        if(retval = GetLongVal(timestep, index, lon_val))
        {
//            printf ("Error 33: %s\n", nc_strerror(retval));
//            exit (2);
        }
        if (cols_from_flag == 0 && lon_val >= LONG_LEFT)
        {
            *cols_from = i;
            cols_from_flag = 1;
        }
        if (lon_val >= LONG_RIGHT)
        {
            *cols_to = i;
            break;
        }
    }


#ifdef DEBUG
    printf ("Correct Rows from: %d, Rows to: %d \n", *rows_from, *rows_to);
    printf ("Correct Cols from: %d, Cols to: %d \n", *cols_from, *cols_to);
#endif

}

void
AtmosphericRivers::date_from_days (int days, int *day, int *month, int leap)
{
    int cnt = 1;
    if (leap == 0)
    {
        int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int k = 0; k < 12; k++)
        {
            for (int m = 0; m < mdays[k]; m++)
            {
                if (cnt == days)
                {
                    *month = k+1;
                    *day = m+1;
                }
                cnt++;
            }
        }
    }
    else
    {
        int mdays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int k = 0; k < 12; k++)
        {
            for (int m = 0; m < mdays[k]; m++)
            {
                if (cnt == days)
                {
                    *month = k+1;
                    *day = m+1;
                }
                cnt++;
            }
        }
    }
}

// Find date from file name for providing output AR event dates
void
AtmosphericRivers::find_date_from_dfname (input_params *ips, int *yyyy, int *mm, int *dd, int time_step, const char* filename)
{
    const char * am_str;
    char date_str[20] = "";
    char year[5] = "";
    char month[3] = "";
    // char day[3] = "";

    *yyyy = *mm = *dd = 0;

    //if (DATASET == CAM5)
    if (strcmp (ips->dataset, "CAM5") == 0)
    {
        // data_file starts with the following prefix
        am_str = strstr (filename, "TMQ_cam5_1_amip_run2.cam2.h1.");
        // 29 is the number of characters in the prefix
        strncpy (date_str, am_str+29, 8);

        for (int i = 0; i < 4; i++)
        {
            year[i] = date_str[i];
        }
        year[4] = '\0';
        for (int i = 0; i < 2; i++)
        {
            month[i] = date_str[i+5];
        }
        month[2] = '\0';

        *yyyy = atoi (year);
        *mm = atoi (month);
        *dd = time_step+1;
    }
    //else if (DATASET == CMIP5)
    else if (strcmp (ips->dataset, "CMIP5") == 0)
    {
        // data_file starts with the following prefix
        am_str = strstr (filename, "hus_day_MRI-CGCM3_historical_r1i1p1_");
        // 36 is the number of characters in the prefix
        strncpy (date_str, am_str+36, 8);

        for (int i = 0; i < 4; i++)
        {
            year[i] = date_str[i];
        }
        year[4] = '\0';

        int num_days, leap;

        *yyyy = atoi (year);
        leap = (*yyyy % 4 == 0) ? 1 : 0;
        num_days = time_step+1;
        date_from_days  (num_days, dd, mm, leap);
    }

#ifdef DEBUG
    printf ("Time step: %d Date: %d %d %d \n", time_step, *yyyy, *mm, *dd);
#endif
}

// get_num_input_files ():
int
AtmosphericRivers::get_num_input_files (char *ifile)
{
    FILE* fptr;
    int c, count = 0;

    fptr = fopen(ifile, "r");

    if(fptr == NULL)
    {
        printf("AR events output file does not exist!\n");
        return -1;
    }

    do {
        c = fgetc(fptr);
        if (c == '\n')
        {
            count++;
        }
    } while (c != EOF);

    fclose(fptr);
    return count;
}

// Read data file name from a list of input file names
int
AtmosphericRivers::read_data_file_name (int proc_id, char *inputs_file, char *data_file)
{
    char * dfile_name;

    std::ifstream ins;
    ins.open(inputs_file);
    std::string line;

    for (int i = 0; i < proc_id; i++)
    {
        getline (ins, line);
    }

    ins.close ();

    if (line.size () != 0)  //Make sure this is a correct condition
    {
        std::string::iterator p;
        p = line.begin();
        dfile_name = &*p;

        dfile_name = strtok (dfile_name, "\n");
        strcpy (data_file, dfile_name);
        return 1;
    }
    else
    {
        return -1;
    }
}

// Dump the features of an AR into a file
void
AtmosphericRivers::dump_output_params (output_params *opars, char* output_file_name, int pe_or_ar)
{
    // printf ("Year\tMonth\tDay\tLength\tWidth \n");
    FILE *outfile_t;
    outfile_t = fopen (output_file_name, "a");
    char poa[3];

    if (pe_or_ar == 1)
    {
        strcpy (poa, "PE");
    }
    else if (pe_or_ar == 2)
    {
        strcpy (poa, "AR");
    }

    if (outfile_t != NULL)
    {
        fprintf (outfile_t, "%d\t%d\t%d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%s \n",	\
            opars->year, opars->month, opars->day,	\
            opars->length, opars->width, 		\
            opars->end_top_lat, opars->end_top_lon, \
            opars->end_bot_lat, opars->end_bot_lon, \
            poa);
        fclose (outfile_t);
    }
    else
    {
        printf ("output file opening error... \n");
    }
}

// Driver function for netCDF inputs
// Can be merged into one driver function for all types of files
void AtmosphericRivers::ar_detect_nc (const std::vector< int >& timesteps,
                                      const std::string& in_file,
                                      const std::string& out_file,
                                      const std::string& dataset)
{
    int rows_from;
    int rows_to;
    int cols_from;
    int cols_to;

    input_params *ips = (input_params *) malloc (sizeof (input_params));
    output_params *opars = (output_params *) malloc (sizeof (output_params));

    init_output_params (opars);

    //ips->ifname[0] = (char *) filenames[0].c_str();
    //ips->ifname[1] = (char *) filenames[1].c_str();
    //ips->ifname[2] = (char *) filenames[2].c_str();
    ips->ofname = (char *) out_file.c_str();
    ips->dataset = (char *) dataset.c_str();

    ips->time_step[0] = timesteps[0];
    ips->time_step[1] = timesteps[1];
    ips->time_step[2] = timesteps[2];

    // Call get_cutoff_points only to make sure calc_cutoff_points is correct
    // calc_cutoff_points is much faster and does not cause any IO
    get_cutoff_points (&rows_from, &cols_from, &rows_to, &cols_to, ips);
    // calc_cutoff_points (&rows_from, &cols_from, &rows_to, &cols_to);

    //Parse date from the input file
    int y, m, d;

    // Works for CAM5 model only
    find_date_from_dfname (ips, &y, &m, &d, ips->time_step[2],in_file.c_str());

    opars->year = y;
    opars->month = m;
    opars->day = d;

    int num_rows = rows_to - rows_from;
    int num_cols = cols_to - cols_from;

    if (num_rows < 1 || num_cols < 1)
    {
        printf ("Error: num_rows and num_cols must be positive \n");
        exit (1);
    }

    long int data_size = num_rows * num_cols * sizeof (float);
    float *vapor_data = (float *) malloc (data_size);

    // long int num_vpoints;

    // Read vapor data from vapor data file into buffer
    read_vapor_data_nc_3day (	vapor_data, ips,  \
                    rows_from, rows_to, 	 \
                    cols_from, cols_to);

    // Labeled data
    unsigned *labeled_data = (unsigned *) malloc (num_rows * num_cols * sizeof (int));

    // Perform thresholding
    vapor_thresholding (vapor_data, labeled_data, 		\
            LOWER_VAPOR_THRESHOLD_NC, 		\
            UPPER_VAPOR_THRESHOLD_NC, 		\
            num_rows, num_cols);

    int num_labels = sauf (num_rows, num_cols, labeled_data);

    float length, width;
    int pe_or_ar = 0;
    int ar_exists = 0;

    // Check for conditions
    ar_exists = verify_ar_exist (	num_rows, num_cols, labeled_data, \
                    num_labels, 			  \
                    rows_from, cols_from, ips,	  \
                    &length, &width, &pe_or_ar, 	  \
                    opars);

    // If an AR or a PE exists, dump output params
    if (ar_exists == 10)
    {
        dump_output_params (opars, ips->ofname, pe_or_ar);
    }

    free (ips);
    free (opars);
    free (vapor_data);
    free (labeled_data);
}

void
AtmosphericRivers::init_output_params (output_params *opars)
{
    // init output_params
    opars->end_top_lat = 0.;
    opars->end_top_lon = 0.;
    opars->end_bot_lat = 0.;
    opars->end_bot_lon = 0.;
    opars->length = 0.;
    opars->width = 0.;
    opars->year = 0;
    opars->month = 0;
    opars->day = 0;
}
