#ifndef PARAMS_H
#define PARAMS_H

#include <vtkDataSet.h>

// Parameters used in AR detection

// ========= Parameters to be changed based on dataset =============

#define NUM_TIME_STEPS 1	// Number of time steps that an MPI job processes

#define DATA_VAR_NAME "TMQ"	// Name of the Integrated water vapor variable
#define LON_VAR_NAME "lon"	// Name of the longitude variable
#define LAT_VAR_NAME "lat"	// Name of the latitude variable

// Change the dataset code using the following codes
// CAM5: 1001
// CMIP5: 1002
// CMIP3: 1003
// fvCAM: 1004
#define DATASET 1001	// CAM5		// Set the dataset value - CAM5 code
//#define DATASET 1002 			// Set the dataset value - CMIP5 code

struct input_params
{
	int num_lats;
	int num_lons;
	int file_type;
    //char *ifname[3];
    int time_step[3];
	char *ofname;
	char *dataset;
};

struct output_params
{
	double end_top_lat;
    double end_top_lon;
    double end_bot_lat;
    double end_bot_lon;
    double length;
    double width;
    int year;
    int month;
    int day;
};

//====================== Do not change the following ===========

//Dataset codes
#define CAM5 1001
#define CMIP5 1002
#define CMIP3 1003
#define fvCAM 1004

#define LAT_DEG 180
#define LON_DEG 360

//#define DEG_GRAN_LAT (float) ((float)LAT_DEG/ (float)NUM_LATS)
//#define DEG_GRAN_LON (float) ((float) LON_DEG/(float) NUM_LONS)

// Region of Interest for the west coast of the USA
#define LAT_TOP 56
#define LAT_BOT 19
#define LONG_LEFT 180
#define LONG_RIGHT 250

#define RIGHT_BOUND 90		// Not used
#define BOT_BOUND 40		// Not used
#define LEFT_BOUND 10		// Not used

// Due to the lack of exact land masks for the western coast of the US, 
// Using approximate land mask boundaries
#define LEFT_BOUND_LON 180	//180 Degrees longitude, starting from left
#define RIGHT_BOUND_LON_1 233	// 233 degrees longitude, ending at right
#define RIGHT_BOUND_LON_2 238	// 238 degrees longitude, ending at right
#define RIGHT_BOUND_LAT_1 29	// 29 degrees latitude, ending at right
#define RIGHT_BOUND_LAT_2 56	// 56 degrees latitude, ending at right
#define BOT_BOUND_LAT 18	// 18 degrees latitude, starting at bottom

#define AR_LENGTH_KMS 2000
#define AR_WIDTH_KMS 1250	// Should be 1000 km

#define THRESHOLD_PERCENT_IN_MESH 5

#define LOWER_VAPOR_THRESHOLD_NC 20
#define UPPER_VAPOR_THRESHOLD_NC 75

#define LOWER_VAPOR_THRESHOLD_GZ 4
#define UPPER_VAPOR_THRESHOLD_GZ 45


#endif	// PARAMS_H
