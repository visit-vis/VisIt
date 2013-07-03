#include "TropicalCyclone.h"

//#include "NetCDFInterface.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sys/stat.h>
#include <vector>
#include <set>

#include <cstdio>
#include <cstring>

#include "util/Spline.h"
#include "util/Util.h"

#ifdef PARALLEL
#include <mpi.h>
#endif

#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "util/tnt_fortran_array2d.h"
#include "util/tnt_fortran_array1d.h"

#include <avtCalendar.h>

#include <DebugStream.h>
#include <avtCallback.h>

avtTECA::RequestedTimeFrame TstormsDriver::GetRequestedTimeFrame()
{
    return avtTECA::Default;
}

stringVector TstormsDriver::GetVariables()
{
    stringVector vars;
    vars.push_back("lat");
    vars.push_back("lon");
    vars.push_back("U850");
    vars.push_back("V850");
    vars.push_back("UBOT");
    vars.push_back("VBOT");
    vars.push_back("T200");
    vars.push_back("T500");
    vars.push_back("PSL");
    vars.push_back("Z200");
    vars.push_back("Z1000");
    vars.push_back("PRECT");

    return vars;
}
#include <avtParallel.h>
void
TstormsDriver::ExecuteProcess()
{
    size_t latsize = 0, lonsize = 0;
    float* latvals = GetLatValues(currentTime, latsize);
    float* lonvals = GetLongValues(currentTime, lonsize);

    Glat = TNT::Fortran_Array1D<float>(latsize);
    Glon = TNT::Fortran_Array1D<float>(lonsize);

    for(size_t i = 0; i < latsize; ++i)
        Glat(i) = latvals[i];
    for(size_t i = 0; i < lonsize; ++i)
        Glon(i) = lonvals[i];


    int TIMESTEP_WITHIN_FILE=currentTime;
    std::string input_filename = "abc";
    std::stringstream ss1, ss2;

    ss1<<input_filename<<"-raw_cyclone."<<setw(5)<<setfill('0')<<TIMESTEP_WITHIN_FILE<<".txt";
    ss2<<input_filename<<"-raw_cyclone."<<setw(5)<<setfill('0')<<TIMESTEP_WITHIN_FILE<<".log";

    TstormsTimestep ts(currentTime, this, ss1.str(), ss2.str());

    ts.initialize_thresholds();
    ts.print_thresholds();
    ts.static_initialize();
    ts.changeTimestep(currentTime);
    ts.go();

    Barrier();
    /*
    time_t start_time, end_time;

    start_time = time(NULL);

    NetCDFInterface nc_file(input_filename);

    int n;

    std::string output_filename=ss1.str();
    std::string log_filename   =ss2.str();

    TstormsTimestep ts(1, &nc_file, output_filename, log_filename);

    ts.initialize_thresholds();
    ts.print_thresholds();

    ts.static_initialize();

    //for (n = 0; n < nc_file.time.dim1(); n += 1) {
      n = TIMESTEP_WITHIN_FILE;

      time_t start_t, end_t;
      start_t = time(NULL);

      ts.changeTimestep(n);

      std::cout << nc_file.time(n) << "\t"
             << ts.date[0] << " " << ts.date[1] << " " << ts.date[2]<< " "
             << ts.date[3] << " " << ts.date[4] << " " << ts.date[5] << "\n";

      ts.go();

      std::cout << endl;

      end_t = time(NULL);

      std::cout <<"\t*** timestep took "<<(end_t-start_t)<<" seconds "<<endl;
      */

}

/// concat code..
//int current_year=0;

void open_file(std::ofstream& outfile, int year)
{
    std::stringstream ss;
    ss<<"cyclones."<<year;
    std::string outfilename = ss.str();
    outfile.open(outfilename.c_str());
    if (!outfile)
    {
        cout<<"Could not open "<<outfilename<<" file for writing"<<endl;
        exit(1);
    }

}

int concat_f3()
{
    std::ofstream outfile;
    int current_year = 0;
    std::ifstream file_list;
    file_list.open("result_list.txt");
    if (!file_list) {
        cout<<"Could not open file_list file for reading"<<endl;
        exit(1);
    }

    open_file(outfile, 1);

    while(!file_list.eof()) {

        std::string input_line;
        std::getline(file_list, input_line);

        if (input_line.length()>10) {

            std::ifstream infile;

            infile.open(input_line.c_str(),ios::in);
            if (!infile){
                cout<<"could not open "<<input_line<<" for processing"<<endl;
                exit(1);
            }
            std::cout<<"Processing "<<input_line<<std::endl;
            std::string dummy1, dummy2, dummy3;
            std::getline(infile,dummy1);
            std::getline(infile,dummy2);
            std::getline(infile,dummy3);

            while (!infile.eof())
            {
                std::string line;
                int day(-1), month(-1), year(-1), count(-1), hour(-1);
                infile>>day>>month>>year>>count>>hour;

                if (current_year!=year) { //close file and open new one
                    current_year = year;
                    outfile.close();
                    open_file(outfile,current_year);
                }

                if ((count>0)&&(!infile.eof())) {
                    cout<<day<<" "<<month<<" "<<year<<" "<<count<<" "<<hour<<endl;
                    bool save = false;
                    if (hour%6==0)//skip every 6 hours..
                        save = true;

                    if (save)
                        outfile<<setprecision(5)
                              <<setw(10)<<setfill(' ')<<day<<" "
                             <<setw(10)<<setfill(' ')<<month<<" "
                            <<setw(10)<<setfill(' ')<<year<<" "
                           <<setw(10)<<setfill(' ')<<count<<" "
                          <<setw(10)<<setfill(' ')<<hour<<endl;

                    for (int i=0;i<count;i++) {
                        int id, idex, jdex;
                        float a, b, c, d, e;
                        float f, g, h;
                        int cond_a, cond_b;
                        char c_a='F';
                        char c_b='F';
                        infile>>id>>idex>>jdex>>a>>b>>c>>d>>e>>f>>g>>h>>cond_a>>cond_b;
                        if (cond_a==1)
                            c_a = 'T';
                        if (cond_b==1)
                            c_b = 'T';

                        if (save)
                            outfile<<setw(10)<<setfill(' ')<<idex<<" "
                                  <<setw(10)<<setfill(' ')<<jdex<<" "
                                 <<setw(12)<<setfill(' ')<<fixed<<a<<" "
                                <<setw(12)<<setfill(' ')<<b<<" "
                               <<setw(12)<<setfill(' ')<<c<<" "
                              <<setw(12)<<setfill(' ')<<d<<" "
                             <<setw(12)<<setfill(' ')<<scientific<<e<<"  "
                            <<setw(12)<<setfill(' ')<<fixed<<f<<"  "
                            <<setw(12)<<setfill(' ')<<scientific<<g<<" "
                            <<setw(12)<<setfill(' ')<<fixed<<h<<" "
                            <<setw(1)<<c_a<<" "
                            <<setw(1)<<c_b<<endl;

                    }//i=0..count loop
                }//count>0
            } //!infile.eof()

            infile.close();

        }
    }

    file_list.close();

    outfile.close();
    return 0;
}

void
TstormsDriver::CollectResults()
{

    /// concatenate results..
    /// concat_f3();

//    //input_filename = argv[1];

//    Trajectory tr("todo");

//    tr.initialize_thresholds();

//    tr.read_data();

//    tr.evaluate_trajectories();

//    tr.compute_stats();

//    tr.compute_summary();

//    tr.cleanup();


}

avtDataTree_p
TstormsDriver::CreateOutput()
{
    return new avtDataTree();
}


void TstormsDriver::set_dx_dy(TNT::Fortran_Array1D<float>& dx, float& dy)
{
    /// give it some size..
    dx = Glat;

    float PI, RADIAN, dlat, dlon, radius;
    radius = 6371.0e3;
    PI = 4.0*atan(1.0);
    RADIAN = 180.0/PI;
    dlat =  fabs(Glat(2)-Glat(1)) / RADIAN;
    dlon =      (Glon(2)-Glon(1)) / RADIAN;

    for (int j=1; j<=Glat.dim1(); j++) {
      dx(j)= (radius * cos(Glat(j) / RADIAN) * dlon);
    }
    dy = radius * dlat;
}


void
TstormsDriver::read3dTimestep(const std::string& var, int timestep, TNT::Fortran_Array2D<float>& v, bool do_padding)
{
    float* data;
    intVector shape;

    //std::cout << "reading " << var.c_str() << std::endl;
    data = (float*)GetData(var.c_str(), timestep, shape);

    v = TNT::Fortran_Array2D<float>(shape[0],shape[1]);


        size_t index = 0;
        for(size_t j = 0; j < shape[1]; ++j)
        {
            for(size_t i = 0; i < shape[0]; ++i)
            {
                v(i+1,j+1) = data[i*shape[1] + j];//data[index++];//data[i*shape[1] + j];//data[index++];
                //if(data[j*shape[0] + i] != v(i+1,j+1) )
                //    std::cout << "blah: " << i << " " << j << std::endl;
            }
        }

//        std::cout << std::endl;

//        std::cout << shape[0] << " " << v.dim1() << std::endl;
//    std::cout << "reading " << var.c_str() << " returned: " << shape[0] << " " << shape[1] << std::endl;
    //convert timestep to float3d array...
//    v = TNT::Fortran_Array2D<float>(shape[0],shape[1],data);

//        if(var == "PSL")
//        {
//            for(size_t i = 0; i < shape[0]; ++i)
//            {
//                std::cout << v(i+1,1) << std::endl;
//            }

//            exit(0);
//        }
}




Trajectory::Trajectory(const char *input_filename)
{

  numax    = 3000; //maximum number of cyclones detections in a day
  nrmax    = 3000; //maximum number of days

  mdays = 0;

#ifdef COUNT_FIELD
    input_file.open("raw_cyclone.txt");
#else
//    input_file.open("cyclones");
      input_file.open(input_filename);
#endif

    if (!input_file) {
      cout<<"Could not open raw cyclones file for reading"<<endl;
      exit(1);
    }

    trajectory_results.open("traj_out.txt");
    if (!trajectory_results) {
      cout<<"Could not open results file for writing"<<endl;
      exit(1);
    }

    //trajectory_results<<"#This file contains complete storm tracks "<<endl;
    //trajectory_results<<"# #pts year month day hour %thick %twc"<<endl;
    //trajectory_results<<"# lon lat wind psl year month day hour"<<endl;


    trajectory_origins.open("ori_out.txt");
    if (!trajectory_origins) {
      cout<<"Could not open results origins file for writing"<<endl;
      exit(1);
    }
    //trajectory_origins<<"#This file contains the points where the storm tracks originate"<<endl;
    //trajectory_origins<<"# Format is "<<endl;
    //trajectory_origins<<"# lon lat year month day hour "<<endl;


    trajectory_sixhourly.open("ori_6hr_out.txt");
    if (!trajectory_sixhourly) {
      cout<<"Could not open results 6hr file for writing"<<endl;
      exit(1);
    }

    trajectory_summary.open("traj_summary.txt");
    if (!trajectory_summary) {
      cout<<"Could not open trajectory summary file for writing"<<endl;
      exit(1);
    }
    trajectory_summary<<setprecision(4)
              <<setw(4)<<setfill(' ')<<"ID"<<" "
              <<setw(4)<<setfill(' ')<<"YEAR"<<" "
              <<setw(4)<<setfill(' ')<<"MO"<<" "
              <<setw(4)<<setfill(' ')<<"DAY"<<" "
              <<setw(4)<<setfill(' ')<<"HR"<<" "
              <<setw(8)<<setfill(' ')<<"LONG"<<" "
              <<setw(8)<<setfill(' ')<<" LAT" <<" "
              <<setw(8)<<setfill(' ')<<" MAXWIND"<<" "
              <<setw(4)<<setfill(' ')<<" CAT"<<" "
              <<setw(8)<<setfill(' ')<<"MWR"<<" "
              <<setw(8)<<setfill(' ')<<"MAXPRECIP"<<" "
              <<setw(8)<<setfill(' ')<<"MPR "<<" "
              <<setw(12)<<setfill(' ')<<" MAXVORT"<<" "
              <<setw(8)<<fixed<<setfill(' ')<<"MINPSL"<<" "
              <<setw(6)<<setfill(' ')<<"  LNGTH"<<" "
              <<setw(8)<<setfill(' ')<<"THICK"<<"   "
              <<setw(8)<<setfill(' ')<<" WARMCORE"<<endl;
    //    trajectory_summary<<"ID YEAR MO DAY HR LONG LAT MAXWIND CAT MINPSL LENGTH THICK WARMCORE"<<endl;

    visit_output.open("visit_output.txt");
    if (!visit_output) {
      cout<<"Could not open visit output file for writing"<<endl;
      exit(1);
    }
   // visit_output<<"id,year,month,day,hour,lon,lat,maxwind,category,minpsl"<<endl;
    visit_output<<"id,year,month,day,hour,lon,lat,maxwind,mwr,maxprecip,mpr,category,vort,minpsl"<<endl;
    static_initialize();

    initialize_thresholds();
}

void Trajectory::static_initialize() {

  Util::init1DVec(icand, numax);
  Util::init1DVec(jcand, numax);
  Util::init1DVec(ix,    numax);
  Util::init1DVec(iy,    numax);
  Util::init1DVec(bon_1, numax);
  Util::init1DVec(bon_2, numax);
  Util::init1DVec(rtot,  numax);

  Util::init1DVec(day,   numax);
  Util::init1DVec(month, numax);
  Util::init1DVec(year,  numax);
  Util::init1DVec(number,numax);
  Util::init1DVec(hour,  numax);

  Util::init2DVec(rlon, nrmax, numax);
  Util::init2DVec(rlat, nrmax, numax);
  Util::init2DVec(wind, nrmax, numax);
  Util::init2DVec(wind_radius, nrmax, numax);
  Util::init2DVec(precip, nrmax, numax);
  Util::init2DVec(precip_radius, nrmax, numax);
  Util::init2DVec(vort, nrmax, numax);
  Util::init2DVec(psl, nrmax, numax);

  Util::init2DVec(available,  nrmax, numax);
  Util::init2DVec(exist_wind, nrmax, numax);
  Util::init2DVec(exist_twc,  nrmax, numax);
  Util::init2DVec(exist_thick,nrmax, numax);

}

bool Trajectory::contains(string a, string b) {
    if (a.find(b)==string::npos) return false;
    return true;
}

void Trajectory::set_threshhold(string name, float val) {
    if (contains(name, string("rcrit"))) {
        rcrit = val;
    }
    else if (contains(name, string("nwcrit"))) {
        nwcrit = val;
    }
    else if (contains(name, string("wcrit"))) {
        wcrit = val;
    }
}

void Trajectory::initialize_thresholds() {
#ifdef THREE_HOUR_INTERVAL
  rcrit =  200.0;
  wcrit =  17.0;
  nwcrit = 16;
#else
  rcrit =  400.0;//TOFIX:: take hours into consideration
  wcrit =  17.0;
  nwcrit = 8; //TOFIX:: take hours into consideration
#endif

  do_filt = false;

  PI = 4.0f * atan(1.0f);
  RADIAN = 180.0f/PI;
  RADIUS = 6371.0;

// from Tstormstimestep
      string name, s;
    int i;
    float val;
    ifstream f;
    struct stat buffer;
    if (stat("thresh2.conf",&buffer)) {
    cout << "Warning: thresh2.conf not found.. using defaults"<<endl;
    return;
    }
    f.open("thresh2.conf");
    while (!f.eof()) {
        std::getline(f,s);
        if (s == "") continue;
        i = s.find("=");
        name = s.substr(0,i);
        val = (float) atof(s.substr(i+1).c_str());
        set_threshhold(name, val);
    }

  cout <<"Set thresholds to "<<endl;
  cout <<" rcrit = "<<rcrit<<", wcrit = "<<wcrit<<", nwcrit = "<<nwcrit<<endl;

}

void Trajectory::cleanup() {
  if (input_file)
    input_file.close();

  if (trajectory_results)
    trajectory_results.close();

  if (trajectory_origins)
    trajectory_origins.close();

  if (trajectory_sixhourly)
    trajectory_sixhourly.close();

  if (visit_output)
    visit_output.close();


  //  cout<<"Done w/ cleanup"<<endl;
}

//
// this function will read the raw_cyclones file and fill in data
// structures with a list of detections
//
void Trajectory::read_data() {

  int iday=1;

  while (!input_file.eof()) {

    int day0(-1), month0(-1), year0(-1), number0(-1), hour0(-1);
    input_file>>day0>>month0>>year0>>number0>>hour0;

    cout<<" Read "
    <<" day="<<day0
    <<" month="<<month0
    <<" year="<<year0
    <<" number="<<number0
    <<" hour="<<hour0
    <<endl;


    if ((day0>=0)&&(month0>=0)&&
    (year0>=0)&&(number0>=0)&&(hour0>=0)) {

      // 1D arrays..
      //cout<<"Setting iday="<<iday<<endl;
      number(iday) = number0;
      year(iday) = year0;
      month(iday) = month0;
      day(iday) = day0;
      hour(iday) = hour0;

      if (number0>0) {
    for (int jcyc=1; jcyc<=number0; jcyc++) {

      int idex, jdex;
      float psl_lon, psl_lat, wind_max, wind_rad, precip_max, precip_rad, vort_max, psl_min;
      bool twc_is(false);
      bool thick_is(false);
      char cond_a, cond_b;

#ifdef COUNT_FIELD
          int count;
      input_file>>count>>idex>>jdex
            >>psl_lon>>psl_lat>>wind_max>>wind_rad>>precip_max>>precip_rad>>vort_max>>psl_min
            >>twc_is>>thick_is;
#else
      input_file>>idex>>jdex
            >>psl_lon>>psl_lat>>wind_max>>wind_rad>>precip_max>>precip_rad>>vort_max>>psl_min
            >>cond_a>>cond_b;

      if (cond_a=='T')
        twc_is = true;
      if (cond_b=='T')
        thick_is = true;

#endif

      rlon(iday,jcyc) = psl_lon;
      rlat(iday,jcyc) = psl_lat;
      wind(iday,jcyc) = wind_max;
      wind_radius(iday,jcyc) = wind_rad;
      exist_wind(iday,jcyc) = ( wind_max >= wcrit );
      precip(iday,jcyc) = precip_max;
          precip_radius(iday,jcyc) = precip_rad;
      vort(iday,jcyc) = vort_max;
      psl(iday,jcyc) = psl_min*0.01;
      exist_twc(iday,jcyc) = twc_is;
      exist_thick(iday,jcyc) = thick_is;
      available(iday,jcyc) = true;;

    }//jcyc loop
      } //number0>0

      iday++;
    } //if it's a valid line
  }    //while !input_file.eof()

    mdays = iday-1;
  print_summary();
}

void Trajectory::print_summary() {

  cout<<"Read #days="<<mdays<<" entries from raw_file"<<endl;

  for (int i=1; i<=mdays-1; i++) {
    cout<<"Timestep "<<setw(4)<<i<<" had "<<number(i)<<" detections"<<endl;

    //cout<<"Day "<<i<<endl;

    for (int j=1; j<=number(i); j++) {

      /*
      cout<<exist_wind(i,j)<<" "
      <<exist_twc(i,j)<<" "
      <<exist_thick(i,j)<<" "
      <<available(i,j)<<endl;
      */
      /*
      cout <<setw(10)<<rlon(i,j)<<" "
       <<setw(10)<<rlat(i,j)<<" "
       <<setw(10)<<psl(i,j)<<" "
       <<setw(10)<<wind(i,j)<<endl;
      */

      /*if (exist_twc(i,j) && exist_thick(i,j) && exist_wind(i,j))
      {
    cout<<j<<" "
        <<setw(10)<<rlon(i,j)<<" "
        <<setw(10)<<rlat(i,j)<<" "
        <<setw(10)<<wind(i,j)<<" "
        <<0<<" "
        <<setw(10)<<psl(i,j)<<" "
        <<exist_twc(i,j)<<" "
        <<exist_thick(i,j)<<" "
        <<exist_wind(i,j)<<" "
        <<endl;
      }
      */

    }

  }

}

//
// this is the key function, it will examine storm detections
// and stitch them together (and write them to file)
//
void Trajectory::evaluate_trajectories() {
  cout<<"Starting evaluating trajectories"<<endl;

  int num_traj(0);
  int year0(0), month0(0), day0(0), hour0(0);
  int long_traj(0);
  int l(0), i1(0), j1(0);
  int ncand(0);
  float rlon_0(0.0), rlat_0(0.0), rlon_i(0.0), rlat_i(0.0);
  float dx(0.0), dy(0.0), dr(0.0);
  int bon(0);

  int nwnd = 0;
  int fthick = 0;
  int ftwc = 0;
  float pthick = 0.0;
  float ptwc = 0.0;

  num_traj = 0;

  for (int iday=1; iday<=mdays-1; iday++) {

    year0 = year(iday);
    month0= month(iday);
    day0  = day(iday);
    hour0 = hour(iday);

    /*
      cout<<"considering iday="<<iday
      <<" corresponding to year="<<year0
      <<" month="<<month0
      <<" day="<<day0
      <<" hour="<<hour0<<endl;
    */

    for (int jcyc=1; jcyc<=number(iday); jcyc++) {

      long_traj = 1;
      ix(1) = iday; // ix and iy arrays are implicitly indexed by long_traj
      iy(1) = jcyc;

      if (available(iday, jcyc) &&
      exist_wind(iday, jcyc)) {

        l  = iday +1; //check next day
        i1 = iday;
        j1 = jcyc;

      line_10: ncand = 0;

        //$$$$$$$$$$
        if (l >mdays) goto line_999;
        //$$$$$$$$$$

        // check for candidates on the following day

        rlon_0 = rlon(i1,j1)/RADIAN;
        rlat_0 = rlat(i1,j1)/RADIAN;

        for (int inc=1; inc<=number(l); inc++) {
          if (available(l,inc)) {
        rlon_i = rlon(l,inc)/RADIAN;
        rlat_i = rlat(l,inc)/RADIAN;

        dx = RADIUS * (rlon_i - rlon_0) * cos(rlat_0);
        dy = RADIUS * (rlat_i - rlat_0);
        dr = sqrt(dx*dx + dy*dy);

        if (dr<=rcrit) {
          ncand = ncand + 1;
          icand(ncand) = l;
          jcand(ncand) = inc;
          //  cout<<"dr<=rcrit, ncand="<< ncand<<endl;
        }//if dr is less than distance criteria
          } //if available
        }//inc loop over #cyclones

      line_999:
        //continue;

    // no more candidate storms
    if (ncand==0) {

      //cout<<"ncand==0"<<endl;
      // check winds; count exist_thick and exist_twc flags

      nwnd = 0;
      fthick = 0;
      ftwc = 0;

      for (int inc=1; inc<=long_traj; inc++) {
        if ( (exist_wind(ix(inc),iy(inc))) &&
          (exist_twc(ix(inc),iy(inc))) &&
         (exist_thick(ix(inc),iy(inc)))) {
          nwnd = nwnd + 1;
          //cout<<"nwnd = "<<nwnd<<endl;
        }

        if (exist_thick(ix(inc),iy(inc)))
          fthick = fthick + 1;

        if (exist_twc(ix(inc),iy(inc)))
          ftwc = ftwc + 1;
      }//inc loop


      // compute percentage of time steps that passed thickness
      // and warm core criteria
      if ( long_traj > 0) {
        pthick = (1.0*fthick)/(1.0*long_traj);
        ptwc = (1.0*ftwc)/(1.0*long_traj);
        //cout<<"\t long_traj = "<<long_traj<<" %thick= "<<pthick<<"  %twc= "<<ptwc<<endl;
      }

          int max_category(-99);
      //if ((long_traj>0) && (nwnd>=nwcrit)) {
      if ((long_traj>1) && (nwnd>=nwcrit)) {

        num_traj = num_traj + 1;

        // FINALLY!! output trajectory info!!
        // "start #pts year month day hour %thick %twc"<<endl;
        trajectory_results<<setprecision(4)
                  <<"start"
                  <<setw(4)<<long_traj<<" "
                  <<setw(4)<<year0<<" "
                  <<setw(4)<<month0<<" "
                  <<setw(4)<<day0<<" "
                  <<setw(4)<<hour0<<" "
                  <<setw(5)<<pthick<<" "
                  <<setw(5)<<ptwc<<endl;
        cout<<"...................Found trajectory.................."<<endl;
        for (int inc1=1; inc1<=long_traj; inc1++) {
          int year1  = year (iday+inc1-1);
          int month1 = month(iday+inc1-1);
          int day1   = day  (iday+inc1-1);
          int hour1  = hour (iday+inc1-1);

          trajectory_results<<setw(10)<<rlon(ix(inc1),iy(inc1))<<" "
                <<setw(10)<<rlat(ix(inc1),iy(inc1))<<" "
                <<setw(10)<<wind(ix(inc1),iy(inc1))<<" "
                <<setw(10)<<wind_radius(ix(inc1),iy(inc1))<<" "
                <<setw(10)<<scientific<<precip(ix(inc1),iy(inc1))<<" "
                                <<setw(10)<<fixed<<precip_radius(ix(inc1),iy(inc1))<<" "
                <<setw(10)<<scientific<<vort(ix(inc1),iy(inc1))<<" "
                <<setw(10)<<fixed<<psl(ix(inc1),iy(inc1))<<" "
                <<setw(4)<<year1<<" "
                <<setw(4)<<month1<<" "
                <<setw(4)<<day1<<" "
                <<setw(4)<<hour1<<endl;

          int category(-1);
          category = get_hurricane_category(wind(ix(inc1),iy(inc1)));
              if (category>max_category)
        max_category=category;

          visit_output<<setprecision(3)
              <<setw(4) <<setfill(' ')<<num_traj <<","
              <<setw(4) <<setfill(' ')<<year1    <<","
              <<setw(4) <<setfill(' ')<<month1   <<","
              <<setw(4) <<setfill(' ')<<day1     <<","
              <<setw(4) <<setfill(' ')<<hour1    <<","
              <<setw(10)<<setfill(' ')<<rlon(ix(inc1),iy(inc1))<<","
              <<setw(10)<<setfill(' ')<<rlat(ix(inc1),iy(inc1))<<","
              <<setw(10)<<setfill(' ')<<wind(ix(inc1),iy(inc1))<<","
              <<setw(10)<<setfill(' ')<<wind_radius(ix(inc1),iy(inc1))<<","
              <<setw(10)<<scientific<<setfill(' ')<<precip(ix(inc1),iy(inc1))<<","
              <<setw(10)<<fixed<<setfill(' ')<<precip_radius(ix(inc1),iy(inc1))<<","
              <<setw(4) <<setfill(' ')<<category  <<","
              <<setw(10)<<scientific<<setfill(' ')<<vort(ix(inc1),iy(inc1))<<","
              <<setw(10)<<fixed<<setfill(' ')<<psl(ix(inc1),iy(inc1))
              <<endl;

             trajectory_sixhourly<<setw(4)<<num_traj<<" "
                 <<setw(10)<<rlon(ix(inc1),iy(inc1))<<" "
                                 <<setw(10)<<rlat(ix(inc1),iy(inc1))<<" "
                 <<setw(4)<<year1<<" "
                                 <<setw(4)<<month1<<" "
                                 <<setw(4)<<day1<<" "
                                 <<setw(4)<<hour1<<" "
                 <<setw(4)<<category<<endl;

        }//inc1 loop

        trajectory_origins<<setw(10)<<rlon(ix(1),iy(1))<<" "
                  <<setw(10)<<rlat(ix(1),iy(1))<<" "
                  <<setw(4)<<year0<<" "
                  <<setw(4)<<month0<<" "
                  <<setw(4)<<day0<<" "
                  <<setw(4)<<hour0<<" "
                  <<setw(4)<<max_category<<endl;

        //eliminate storms used for trajectory
        for (int inc1=1;inc1<=long_traj;inc1++)
          available(ix(inc1),iy(inc1))= false;

      }//if long_traj and wind criteria are met, write stuff
    }//(ncand==0)


    if (ncand==1) {

      long_traj  = long_traj + 1;
      ix(long_traj) = icand(1);
      iy(long_traj) = jcand(1);

      l  = l + 1;
      i1 = ix(long_traj);
      j1 = iy(long_traj);

      goto line_10;//HORRIBLE..

    }//(ncand==1)


    // more that one candidate storm
    if (ncand>1) {

      rlon_0 =      rlon(i1,j1);
      rlat_0 = fabs(rlat(i1,j1));

      bon = 0;

      for(int inc=1; inc<=ncand; inc++) {//go over all candidates
        rlon_i =      rlon(l,inc);
        rlat_i = fabs(rlat(l,inc));

        if( rlon_i <= rlon_0 ) {
          if( rlat_i >= rlat_0 ) {
        bon  = bon + 1;
        //bon_1 and bon_2 are implicitly indexed by bon
        bon_1(bon) = icand(inc);
        bon_2(bon) = jcand(inc);
          }
        }
      }//inc over ncand loop

      if( bon == 1 ) {
        long_traj  = long_traj + 1;
        ix(long_traj) = bon_1(1);
        iy(long_traj) = bon_2(1);

        l  = l + 1;
        i1 = ix(long_traj);
        j1 = iy(long_traj);

        goto line_10;
      }// bon==1

      if (bon>=2) {

        for(int inc=1; inc<=bon; inc++) {
          dx = ( rlon(bon_1(inc),bon_2(inc)) - rlon(i1,j1) );
          dy = ( rlat(bon_1(inc),bon_2(inc)) - rlat(i1,j1) );
          rtot(inc) = sqrt( dx*dx + dy*dy );
        }//inc loop over bon

        int imin = Util::MINLOC(rtot, 1, bon);

        long_traj  = long_traj + 1;
        ix(long_traj) = bon_1(imin);
        iy(long_traj) = bon_2(imin);

        l  = l + 1;
        i1 = ix(long_traj);
        j1 = iy(long_traj);

        goto  line_10;
      }// bon>=2

      if (bon==0) {

        for (int inc=1; inc<=ncand; inc++) {
          dx = ( rlon(icand(inc),jcand(inc)) - rlon(i1,j1) );
          dy = ( rlat(icand(inc),jcand(inc)) - rlat(i1,j1) );
          rtot(inc) = sqrt( dx*dx + dy*dy );
        }//inc loop over ncand

        int imin = Util::MINLOC(rtot, 1, ncand);

        long_traj  = long_traj + 1;
        ix(long_traj) = icand(imin);
        iy(long_traj) = jcand(imin);

        l  = l + 1;
        i1 = ix(long_traj);
        j1 = iy(long_traj);


        goto line_10;
      }// bon==0


    }//ncand>1

      }//available && exist_wind

    } //loop over all cyclone detections in an instant

  }// loop over all timesteps

  trajectory_results.close();
  trajectory_origins.close();
  trajectory_sixhourly.close();

  cout<<"Done evaluating trajectories"<<endl;
}

// function will compute trajectory summary statistics for different classes and total

void Trajectory::compute_stats() {

  compute_traj_stats(0, false);
  compute_traj_stats(1, false);
  compute_traj_stats(2, false);
  compute_traj_stats(3, false);
  compute_traj_stats(4, false);
  compute_traj_stats(5, false);
  compute_traj_stats(100, false);

  compute_traj_stats(0, true);
  compute_traj_stats(1, true);
  compute_traj_stats(2, true);
  compute_traj_stats(3, true);
  compute_traj_stats(4, true);
  compute_traj_stats(5, true);
  compute_traj_stats(100, true);
}

// first argument determines whether individual categories need to be processed, or all TCs
// category_type>5 for total

// second argument determines if only origin point of a TC should be considered, or six_hourly data
//

void Trajectory::compute_traj_stats(int category_type, bool six_hourly) {

  bool do_total_count = (category_type>5)?true:false;

  if (do_total_count)
  cout<<"\tComputing summary stats on ALL categories"<<endl;
  else
  cout<<"\tComputing summary stats on Cat."<<category_type<<endl;


  int ix = 360;
  int iy = 180;
  int ireg = 12;

  float  pi = 180.0;
  float tpi = 360.0;
  float hpi =  90.0;

  float dlon, lon0, dlat, lat0;

  Fortran_Array2D<int> imask;
  Util::init2DVec(imask, ix, iy);

  int   nr; //, ny, m, indyr, indyr0;
  //int   n, nc,
  int ii, jj;

  Fortran_Array2D<int> icnt;

  //icnt is array months x regions
  Util::init2DVec(icnt, 13, ireg);

  string months[]={" J"," F"," M"," A"," M"," J"," J"," A"," S"," O"," N"," D","Yr"};
  string bx[]={" G","WA","EA","WP","EP","NI","SI","AU","SP","SA","NH","SH"};


  cmask_file.open("/project/projectdirs/vacet/Wehner/tstorms-install/imask_2");

  if (!cmask_file) {
    cout<<"Could not open cmask file for reading"<<endl;
    exit(1);
  }

  //
  // read region mask, this will help in sorting counts to basins
  //
  for (int jj=1; jj<=iy; jj++) {
    for (int ii=1; ii<=ix; ii++) {
      int val(-1);
      cmask_file>>val;
      imask(ii,jj) = val;
    }
  }

  lon0 = 0.0;
  dlon = tpi/(float)(ix);
  lat0 = hpi - 0.5*pi/float(iy);
  dlat =       2.0*lat0/float(iy-1);

  // this can be cleaned up..
  ifstream ori;

  if (six_hourly)
    ori.open("ori_6hr_out.txt");
  else
    ori.open("ori_out.txt");

  if (!ori) {
    cout<<"Could not open ori_out for processing"<<endl;
    exit(1);
  }

  stringstream stats_filename;
  if (six_hourly) {
      if (do_total_count)
        stats_filename<<"traj_6hr_stat.txt";
      else
        stats_filename<<"traj_6hr_stat."<<category_type<<".txt";
  }
  else {
          if (do_total_count)
            stats_filename<<"traj_stat.txt";
          else
            stats_filename<<"traj_stat."<<category_type<<".txt";
  }

  string sname=stats_filename.str();
  ofstream stats(sname.c_str());
  if (!stats) {
    cout<<"Could not open file "<<stats_filename.str()<<" for writing..."<<endl;
    exit(1);
  }

  while (!ori.eof()) {
    float xcyc(-1), ycyc(-1);
    int   year(-1), month(-1), day(-1), hour(-1);
    int   category(-99);

    int id(-1);
   if (six_hourly)
    ori>>id>>xcyc>>ycyc>>year>>month>>day>>hour>>category;
   else
    ori>>xcyc>>ycyc>>year>>month>>day>>hour>>category;

    // file is valid  && ( category type matches      || all categories)
    if ( (!ori.eof()) && ( (category==category_type) || (do_total_count))) {

      jj = ( lat0 - ycyc ) / dlat + 1.5;
      ii = ( xcyc - lon0 ) / dlon + 1.5;
      if ( ii == 0  ) ii = ix;
      if ( ii >  ix ) ii = ii - ix;
      nr = imask(ii,jj);
      icnt(month,1)  = icnt(month,1)  + 1;
      if (nr>0)
    icnt(month,nr) = icnt(month,nr) + 1;
    }//!ori.eof()
  }

  //compute sum for NH
  for (int m=1; m<=12; m++) //loop over all months
    for (int r=2; r<=6; r++) //loop over NH regions
      icnt(m, ireg-1) = icnt(m, ireg-1) + icnt(m,r);


  //SH
  for (int m=1; m<=12; m++) //loop over all months
    for (int r=7; r<=10; r++) //loop over NH regions
      icnt(m, ireg) = icnt(m, ireg) + icnt(m,r);

  //Year
  for (int m=1; m<=12; m++)
    for (int r=1; r<=ireg; r++)
      icnt(13, r) = icnt(13, r) + icnt(m,r);


  if (six_hourly) {
     if (do_total_count)
     stats <<" Number of 6-hour timesteps::"<<icnt(13,1)<<endl;
     else
     stats<<" Number of Cat."<<category_type<<" 6-hour timesteps "<<icnt(13,1)<<endl;
  }
  else {
  if (do_total_count)
    stats<<" Number of Storms " <<icnt(13,1)<<endl;
  else
    stats<<" Number of Cat."<<category_type<<" Storms "<<icnt(13,1)<<endl;
}

  stats<<"   ";
  for (int nr=1; nr<=ireg+1; nr++)
    stats<<setw(6)<<months[nr-1];
  stats<<endl;

  for (int nr=1; nr<=ireg; nr++){
    stats<<setw(3)<<bx[nr-1];
    for (int m=1; m<=13; m++)
      stats<<setw(6)<<icnt(m, nr);
    stats<<endl;
  }

  ori.close();
  stats.close();
  cmask_file.close();

//  imask.clear();
//  icnt.clear();

  cout<<"\tDone w/ computing stats for cat="<<category_type<<endl;
}

// Saffir-simpson scale prescribes the following limits:
//http://en.wikipedia.org/wiki/Tropical_cyclone_scales
// CAT wind
//      km/h
// -1:   0- 62           : Tropical depression
//  0:  63-117               : Tropical storm
//  1: 119-153
//  2: 154-177
//  3: 178-209
//  4: 210-249
//  5:    >250

// 1 m/s -> 3.6 Km/h

int Trajectory::get_hurricane_category(float windmax) {

  float wind = 3.6 * windmax;
  if (wind<0)
    return -99;

  if (wind<=62)
    return -1;

  if (wind<=117)
    return 0;

  if (wind<=153)
    return 1;

  if (wind<=177)
    return 2;

  if (wind<=209)
    return 3;

  if (wind<=249)
    return 4;

  else
    return 5;

}


void Trajectory::compute_summary() {
  cout<<"Computing summary for storms"<<endl;
  ifstream trajectory_results;
  trajectory_results.open("traj_out.txt");

  if (!trajectory_results) {
    cout<<"Could not open results file for writing"<<endl;
    exit(1);
  }

  int storm_count= 1;

  while(!trajectory_results.eof()) {
    string header;
    string line;
    int count(-1);
    int year(-1), month(-1), day(-1), hour(-1);
    float pthick(-1), ptwc(-1);

    std::getline(trajectory_results, line);
    cout<<line<<endl;
    stringstream ss;
    ss<<line;
    ss>>header>>count>>year>>month>>day>>hour>>pthick>>ptwc;

    //cout<<" "<<header<<" "<<count<<" "<<year<<" "<<month<<" "<<day<<" "<<hour<<" "<<pthick<<" "<<ptwc<<" "<<endl;;

    if ((count>-1)&&(ptwc>-1)) {

      float maxwind(-9999);
      float max_wind_radius(-9999);
      float minpsl(999999);
      float maxvort(-9999);
      float maxprecip(-9999);
      float max_precip_radius(-9999);

      float lon0(-1), lat0(-1), wind0(-1), wind_radius0(-1), precip0(-1), precip_radius0(-1), vort0(-1), psl0(-1);
      int year0(-1), month0(-1), day0(-1), hour0(-1);
      float lon(-99), lat(-99);
      int category(-99);

      for (int i=0; i<count; i++) {
    trajectory_results>>lon0>>lat0>>wind0>>wind_radius0>>precip0>>precip_radius0>>vort0>>psl0>>year0>>month0>>day0>>hour0;

    if (lon0==-1) {
      cout<<"we have a problem"<<endl;
      cout<<" "<<lon0<<" "<<lat0<<" "<<wind0<<" "<<wind_radius0<<" "<<precip0<<" "<<precip_radius0
          <<" "<<vort0<<" "<<psl0<<" "<<year0<<" "<<month0<<" "<<day0<<" "<<hour0;

      exit(1);
    }

    if (i==0) {
      lon=lon0;
      lat=lat0;
    }

    if (wind0>maxwind) {
      maxwind=wind0;
      max_wind_radius = wind_radius0;
    }

    if (psl0<minpsl)
      minpsl = psl0;

    if (precip0>maxprecip){
      maxprecip = precip0;
          max_precip_radius = precip_radius0;
    }
    if (vort0>maxvort)
      maxvort=vort0;

      }

      //convert maxwind to category on simpson/sapphir scale
      // Assuming that the units are m/s;
      //TODO:: this needs to be changed to read netcdf file

      category = get_hurricane_category(maxwind);

      trajectory_summary<<setw(4)<<setfill(' ')<<storm_count<<" "
            <<setw(4)<<setfill(' ')<<year <<" "
            <<setw(4)<<setfill(' ')<<month<<" "
            <<setw(4)<<setfill(' ')<<day  <<" "
            <<setw(4)<<setfill(' ')<<hour <<" "
            <<setw(8)<<setfill(' ')<<lon<<" "
            <<setw(8)<<setfill(' ')<<lat<<" "
            <<setw(8)<<setfill(' ')<<maxwind<<" "
            <<setw(4)<<setfill(' ')<<category<<" "
            <<setw(8)<<setfill(' ')<<max_wind_radius<<" "
            <<setw(8)<<scientific<<setfill(' ')<<maxprecip<<" "
            <<setw(8)<<fixed<<setfill(' ')<<max_precip_radius<<" "
            <<setw(12)<<scientific<<setfill(' ')<<maxvort<<" "
            <<setw(8)<<fixed<<setfill(' ')<<minpsl<<" "
            <<setw(6)<<setfill(' ')<<count<<" "
            <<setw(8)<<setfill(' ')<<pthick<<"   "
            <<setw(8)<<setfill(' ')<<ptwc<<endl;
      storm_count++;
    }

    //cout<<"Storm count "<<storm_count<<endl;
  }

  trajectory_results.close();
  trajectory_summary.close();
}

int GRID_BOXES = 16; //hk added 16
//int TIMESTEP_WITHIN_FILE=-99;
//int NUM_FILES=0;
//int MPI_RANK=0;
//int MPI_SIZE=1;
//std::string FILENAME;

TstormsTimestep::TstormsTimestep(int t,
                                 TstormsDriver* driver,
                                 std::string result_name,
                                 std::string log_filename)
{

  rank = 0;
  size = 1;
#ifdef PARALLEL
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);
#endif

  set_default_thresholds();


  data = driver;
  //data = ncfile;

  //assumes that lat/lon/dx/dy won't vary across timesteps..
  //lat = Util::init2DVec_padded(data->Glat);
  //lon = Util::init2DVec_padded(data->Glon);

  //dx = dx;
  //dy = dy;
  data->set_dx_dy(dx,dy);
  //logfile<<"TstormsTimestep constructor determined  "
  //<<"  lat size="<<lat.dim1()
  //<<", lon size="<<lon.dim1()<<endl;

  std::cout << "opening " << result_name << std::endl;
  result_file.open(result_name.c_str(), fstream::out);
  if (!result_file) {
    cout<<"Could not open results file for writing"<<endl;
    exit(1);
  }

  result_file<<"# This file will have 2 kinds of entries:"<<endl;
  result_file<<"#day month year count hour"<<endl;
  result_file<<"#   #    i   j   psl_lon    psl_lat    wind_max   max_wind_r  precip_max   max_prcip_r  vort_max    psl_min  twc? thick?"<<endl;

  storm_count = 0;



}

void TstormsTimestep::final_cleanup() {
  static_cleanup();
  result_file.close();
}

void TstormsTimestep::changeTimestep(int t){
  timestep = t;
  setdate();
  storm_count = 0;
}

void TstormsTimestep::go() {


  std::cout << "reading data" << std::endl;
  read_data();

  std::cout << "mainloop" << std::endl;
  mainloop();

  std::cout << "output" << std::endl;
  outputResultsToFile();

  std::cout << "cleanup" << std::endl;
  cleanup();

  std::cout << PAR_Rank() << ": end" << std::endl;
}

//
// this function will read all the data needed for hurricane detection
//
void TstormsTimestep::read_data() {

  float min, max;
  Util::init2DVec(wrk1, data->Glon.dim1(), data->Glat.dim1());
  Util::init2DVec(wrk2, data->Glon.dim1(), data->Glat.dim1());

  std::cout <<"read_data wrk1 size is "<<wrk1.dim1()<<"x"<<wrk1.dim2()<<endl;

  // compute vorticity
  data->read3dTimestep("U850", timestep, wrk1, false);
  min = Util::MINVAL_All(wrk1);
  max = Util::MAXVAL_All(wrk1);

  std::cout<<"\t**** uu max="<<setw(12)<<max<<" "<<" min="<<setw(12)<<min<<endl;

  data->read3dTimestep("V850", timestep, wrk2, false);
  min = Util::MINVAL_All(wrk2);
  max = Util::MAXVAL_All(wrk2);

  std::cout<<"\t**** vv max="<<setw(12)<<max<<" "<<" min="<<setw(12)<<min<<endl;

  comp_vort(wrk1, wrk2);
  min = Util::MINVAL_All(Gvort);
  max = Util::MAXVAL_All(Gvort);

  std::cout<<"\t**** vort max="<<setw(12)<<scientific<<max<<" "<<" min="<<setw(12)<<min<<endl;
  // compute wind
  if (use_sfc_wind) {
    data->read3dTimestep("UBOT", timestep, wrk1, false);
    min = Util::MINVAL_All(wrk1);
    max = Util::MAXVAL_All(wrk1);

    std::cout << "\t**** using wind speed at models lowest level\n";
    std::cout<<"\t**** uu max="<<setw(12)<<fixed<<max<<" "<<" min="<<setw(12)<<min<<endl;

    data->read3dTimestep("VBOT", timestep, wrk2, false);
    min = Util::MINVAL_All(wrk2);
    max = Util::MAXVAL_All(wrk2);

    std::cout<<"\t**** vv max="<<setw(12)<<max<<" "<<" min="<<setw(12)<<min<<endl;
  }

  comp_wind(wrk1, wrk2);
  min = Util::MINVAL_All(Gwind);
  max = Util::MAXVAL_All(Gwind);

  std::cout<<"\t**** wind max="<<setw(12)<<max<<" "<<" min="<<setw(12)<<min<<endl;

  // compute temperature average
  data->read3dTimestep("T200", timestep, wrk1, false);
  data->read3dTimestep("T500", timestep, wrk2, false);

  for (int i=1; i<=wrk1.dim1(); i++) { //compute temperature average
    for (int j=1; j<=wrk1.dim2(); j++) {
      Gtbar(i,j) = atwc * wrk1(i,j) + (1.0-atwc) * wrk2(i,j);
    }
  }

  min = Util::MINVAL_All(Gtbar);
  max = Util::MAXVAL_All(Gtbar);
  std::cout<<"\t**** tbar max="<<setw(12)<<max<<" "<<" min="<<setw(12)<<min<<endl;

  // read sea level pressure
  data->read3dTimestep("PSL", timestep, Gpsl, false);

  min = Util::MINVAL_All(Gpsl);
  max = Util::MAXVAL_All(Gpsl);
  std::cout<<"\t**** psl max="<<setw(12)<<max<<" "<<" min="<<setw(12)<<min<<endl;

  // compute thickness between 200 and 1000 mb
  data->read3dTimestep("Z200",  timestep, wrk1, false);
  data->read3dTimestep("Z1000", timestep, wrk2, false);

  for (int i = 1; i<=wrk1.dim1(); i++) {
    for (int j = 1; j<=wrk1.dim2(); j++) {
      Gthick(i,j) = wrk1(i,j) - wrk2(i,j);
    }
  }

  min = Util::MINVAL_All(Gthick);
  max = Util::MAXVAL_All(Gthick);
  std::cout<<"\t**** thick max="<<setw(12)<<max<<" "<<" min="<<setw(12)<<min<<endl;

  // read precipitation
  data->read3dTimestep("PRECT", timestep, Gprecip, false);

  min = Util::MINVAL_All(Gprecip);
  max = Util::MAXVAL_All(Gprecip);
  std::cout<<"\t**** precip max="<<setw(12)<<scientific<<max<<" "<<" min="<<setw(12)<<min<<fixed<<endl;
  // optional smoothing argument..
  /*
    if (do_smoothing) {
    Util::avg9(vort);
    Util::avg9(psl);
    }
  */

}


//
// comp_vorticity will create the vorticity field..
//
void TstormsTimestep::comp_vort(const Fortran_Array2D<float>& uu,
                const Fortran_Array2D<float>& vv) {
  //logfile<<"Computing vorticity"<<endl;
  int imx = uu.dim1();
  int jmx = uu.dim2();

  /*
    for (int i=1;i<=3;i++)
    for (int j=1; j<=3; j++)
    logfile<<i<<" "<<j<<" "<<uu(i,j)<<endl;
  */

  //logfile<<"(imx-1)= "<<imx-1<<", (jmx-1)= "<<jmx-1<<endl;


  for (int i=1; i<=Gvort.dim1(); i++)
    for (int j=1; j<=Gvort.dim2(); j++)
      Gvort(i,j)=0.0;

    for (int j=2; j<=jmx-1; j++) {
      for (int i=2; i<=imx-1; i++) {

    Gvort(i,j) = ( vv(i+1,j) - vv(i-1,j) ) / ( 2.0*dx(j) )
               - ( uu(i,j+1) - uu(i,j-1) ) / ( 2.0*dy    );

    }
  }
  /*
  logfile<<"dy = "<<dy<<endl;
  logfile<<"dx = "<<endl;
  for (int j=1;j<=jmx;j++)
    logfile<<dx(j)<<" ";

  logfile<<endl;
  */
}

void TstormsTimestep::comp_wind(const Fortran_Array2D<float>& uu,
                const Fortran_Array2D<float>& vv) {
  //logfile<<"Computing Wind "<<endl;
  //  logfile<<"uu dims "<<uu.dim1()<<"x"<<uu.dim2()<<endl;

  for (int i=1; i<=uu.dim1(); i++) {
    for (int j=1; j<=uu.dim2(); j++) {
      Gwind(i,j) = sqrt(pow(uu(i,j),2)+pow(vv(i,j),2));
    }
  }
}

void TstormsTimestep::initialize_splines() {
  //logfile<<"Initializing splines"<<endl;

}


void TstormsTimestep::mainloop() {
  //logfile<<"Entering mainloop()"<<endl;

  float lon_vort(0), lat_vort(0), vort_max(-99.99), vort_current(-99.00);
  float lon_wmax(-99), lat_wmax(-99), wind_max(-99.99);
  float lon_pmax(-99), lat_pmax(-99), precip_max(-99);
  float lon_psl(0),  lat_psl(0),  psl_min(99.99);
  float lon_twc(0), lat_twc(0), twc_max(-99.99);
  float lon_thick(0), lat_thick(0), thick_max(-99.99);

  float xx(0), yy(0), rr(0);

  int ix(0),jx(0),ixp3(0),jxp3(0),jxp6(0),im(0),ip(0),jm(0),jp(0);
  int nx(0), nx2(0), nxp1(0);
//  nx   = 16;
  nx = GRID_BOXES;// nx is HALF of the grid box extent
  nx2  = nx*2;
  nxp1 = nx + 1;

  float ftol = 0.01;
  int iter = 1000;
  float fret;

  int ierr_pos = 0;
  int ierr_mag = 0;
  Fortran_Array1D<float> p(2);

  bool exist_twc = false;
  bool exist_thick = false;

  ix   = Gwind.dim1();
  jx   = Gwind.dim2();
  ixp3 = ix+nx;
  jxp3 = jx+nx;
  jxp6 = jx+nx2;

  Util::gpad2(wind, Gwind);
  Util::gpad2(precip,  Gprecip);
  Util::gpad2(vort, Gvort);
  Util::gpad2(tbar, Gtbar);
  Util::gpad2(psl,  Gpsl);
  Util::gpad2(thick,Gthick);
  Util::gpad1(rlat, data->Glat);
  Util::gpad1(rlon, data->Glon);

  // change sign of vorticity in southern hemisphere
  for (int j=1; j<=jxp6; j++)
    if (rlat(j)<0.0)
      for (int i=1; i<=vort.dim1();i++)
    vort(i,j) = -1.0*vort(i,j);

  Util::scalar_mul2D(tbar,  tbar, -1.0);
  Util::scalar_mul2D(thick, thick, -1.0);

  Spline::splie2(rlon, rlat, psl, psl_dy);
  Spline::splie3(rlon, rlat, psl, psl_dx);

  Spline::splie2(rlon, rlat, tbar, tbar_dy);
  Spline::splie3(rlon, rlat, tbar, tbar_dx);

  Spline::splie2(rlon, rlat, thick, thick_dy);
  Spline::splie3(rlon, rlat, thick, thick_dx);

  /*
    logfile<<"psl_dy, psl_dx, tbar_dy, tbar_dx"<<endl;

    for (int i=150;i<=152;i++)
    for (int j=150;j<=152;j++)
    logfile<<setw(10)<<psl_dx(i,j)<<" "<<setw(10)<<psl_dy(i,j)<<" "
    <<setw(10)<<tbar_dx(i,j)<<" "<<setw(10)<<tbar_dy(i,j)<<endl;

  */

  // START OF MAIN PROCESSING LOOP!!

  std::cout << "start main processing.." << std::endl;
  std::cout << nxp1 << " " << jxp3 << std::endl;
  std::cout << nxp1 << " " << ixp3 << std::endl;

  for (int j=nxp1; j<=jxp3; j++) {

    // check if the point is within the latitude bounds
    if ((rlat(j)>lat_bound_n)||(rlat(j)<lat_bound_s))
      continue; //move onto the next lat value

    for (int i=nxp1; i<=ixp3; i++) {

      im = i-nx;
      ip = i+nx;
      jm = j-nx;
      jp = j+nx;

      //--------------------------------
      // Step1: Check for vorticity max
      //--------------------------------
      vort_max = Util::MAXVAL(vort, im, ip, jm, jp);

      vort_current = vort(i,j);
      //std::cout <<" vort_local_max= "<<vort_max<<" " << std::endl;

      if ((vort_current<vort_max)||
      (vort_current<crit_vort))
    continue; //move onto the next point

      //Otherwise Step1 is complete, we have a local vorticity maximum
      lon_vort = rlon(i);
      lat_vort = rlat(j);

      //-----------------------------------------------------------
      // Step2:: now search for a local sea level pressure minimum
      //-----------------------------------------------------------
      ierr_pos = 0;
      p(1)=lon_vort;
      p(2)=lat_vort;


      Spline::frprm(rlon, rlat, psl, psl_dy, psl_dx,
            p, ftol, iter, fret, ierr_pos);

      //logfile<<"frprm o/p:: "<<setw(10)<<fret<<" "
      //<<setw(10)<<p(1)<<" "<<setw(10)<<p(2)<<endl;

      psl_min = fret;
      lon_psl = p(1);
      lat_psl = p(2);

      xx      = lon_psl - lon_vort;
      yy      = lat_psl - lat_vort;
      rr      = xx*xx + yy*yy; //distance squared, compared to 2^2 (4)

      if( rr >= crit_dist  ) ierr_pos = 1;
      if( psl_min < 500e2 ) ierr_pos = 1;

      if (ierr_pos==1)
    continue; //move onto the next point

      // Check the magnitude of slp from the minimum point
      ierr_mag = 0;
      Spline::shape(rlon, rlat,
            psl, psl_dy, psl_dx,
            p,
            ftol, iter, fret,
            ierr_mag, crit_psl, dist_psl);

      //      logfile<<"shape o/p "<<ierr_mag<<" "<<setw(10)<<fret<<endl;

      if (ierr_mag==1)
    continue; //move onto next point
      // else the surrounding points match the pressure increase
      // criteria


      //-----------------------------------------------------------
      // Step3:: search for presence of warm core
      //-----------------------------------------------------------

      // check for location
      ierr_pos = 0;
      Spline::frprm(rlon, rlat, tbar, tbar_dy, tbar_dx,
            p, ftol, iter, fret, ierr_pos);

      //     logfile<<"frprm o/p:: "<<setw(10)<<fret<<" "
      //<<setw(10)<<p(1)<<" "<<setw(10)<<p(2)<<endl;

      if (ierr_pos==0) { //local warm core was found
    twc_max = -fret;
    lon_twc = p(1);
    lat_twc = p(2);
    xx      = lon_twc - lon_psl;
    yy      = lat_twc - lat_psl;
    rr      = xx*xx + yy*yy;

    if( rr >= crit_dist ) //squared distance compared to 4 (2^2)
      ierr_pos = 1;
      }
      else {
    twc_max = 0.0;
    lon_twc = 0.0;
    lat_twc = 0.0;
      }

      exist_twc=(ierr_pos==0);

      //check for magnitude
      if (exist_twc) {

    ierr_mag = 0;
    Spline::shape(rlon, rlat,
              tbar, tbar_dy, tbar_dx,
              p,
              ftol, iter, fret,
              ierr_mag, crit_twc, dist_twc);

    //	logfile<<"shape twc o/p "<<ierr_mag<<" "<<setw(10)<<fret<<endl;

    exist_twc = exist_twc && (ierr_mag==0);
      }

      //---------------------------------
      // Step4:: check for thickness max
      //---------------------------------
      // check for location
      ierr_pos = 0;

      Spline::frprm(rlon, rlat, thick, thick_dy, thick_dx,
            p, ftol, iter, fret, ierr_pos);

      //logfile<<"frprm thick max o/p:: "<<setw(10)<<fret<<" "
      //<<setw(10)<<p(1)<<" "<<setw(10)<<p(2)<<endl;

      if( ierr_pos == 0 ){
    thick_max = -fret;
    lon_thick = p(1);
    lat_thick = p(2);
    xx        = lon_thick - lon_psl;
    yy        = lat_thick - lat_psl;
    rr        = xx*xx + yy*yy;
    if(rr >= crit_dist )
      ierr_pos = 1;
      }
      else {
    thick_max = 0.0;
    lon_thick = 0.0;
    lat_thick = 0.0;
      }

      exist_thick = (ierr_pos == 0);
      if (exist_thick) {
    //check for magnitude
    ierr_mag = 0;
    Spline::shape(rlon, rlat,
              thick, thick_dy, thick_dx,
              p,
              ftol, iter, fret, ierr_mag,
              crit_thick, dist_twc);
    //logfile<<"shape thick o/p "<<ierr_mag<<" "<<setw(10)<<fret<<endl;

    exist_thick = exist_thick && (ierr_mag==0);
      }

    std::cout << (i-nx)<<" "<<(j-nx)<<endl;

      // calculate max wind distance
      int iwmax(-1), jwmax(-1);
      wind_max = Util::MAXVAL_LOC(wind, im, ip, jm, jp, iwmax, jwmax);
      lon_wmax = rlon(iwmax);
      lat_wmax = rlat(jwmax);

          float dist_wmax = Util::geodesic_distance(lat_wmax, lon_wmax, lat_psl, lon_psl);

      // calculate max precip distance
      int ipmax(-1), jpmax(-1);
      precip_max = Util::MAXVAL_LOC(precip, im, ip, jm, jp, ipmax, jpmax);
      lon_pmax = rlon(ipmax);
      lat_pmax = rlat(jpmax);

      float dist_pmax = Util::geodesic_distance(lat_pmax, lon_pmax, lat_psl, lon_psl);

      // WE have a Storm detection!!!
      // store results!!
      std::cout << "storm detected" << std::endl;
      ridex.push_back(i-nx);
      rjdex.push_back(j-nx);

      rvort_max.push_back(vort_max);
      rvort_lon.push_back(lon_vort);
      rvort_lat.push_back(lat_vort);

      rwind_max.push_back(wind_max);
      rdist_wmax.push_back(dist_wmax);

      rprecip_max.push_back(precip_max*86400000);
      rdist_precipmax.push_back(dist_pmax);

      rpsl_min.push_back(psl_min);
      rpsl_lon.push_back(lon_psl);
      rpsl_lat.push_back(lat_psl);

      rtwc_max.push_back(twc_max);
      rtwc_lon.push_back(lon_twc);
      rtwc_lat.push_back(lat_twc);
      rexist_twc.push_back(exist_twc);

      rexist_thick.push_back(exist_thick);
      rthick_max.push_back(thick_max);
      rthick_lon.push_back(lon_thick);
      rthick_lat.push_back(lat_thick);
      storm_count++;

    }//j lat loop
  } //i lon loop
  std::cout << "outside_loop" << std::endl;
}



void TstormsTimestep::outputResultsToFile() {

  if (!result_file) {
        std::cout<<"result_file closed, exiting"<<endl;
        //exit(1);
        return;
  }
  //result_file<<day<<" "<<imon<<" "<<iyear<<" "<<ridex.payload_length()()<<" "<<ihour<<endl;

//  result_file<<setw(4)<<date[2]<<" "
//         <<setw(4)<<date[1]<<" "
//         <<setw(4)<<date[0]<<" "
//         <<setw(4)<<ridex.size()<<" "
//         <<setw(4)<<date[3]<<endl;
  /// todo: check on this format..
    result_file<<setw(4)<<date.day <<" "
           <<setw(4)<<date.month<<" "
           <<setw(4)<<date.year<<" "
           <<setw(4)<<ridex.size()<<" "
           <<setw(4)<<date.hour<<endl;

  for (int i=0;i<ridex.size();i++) {

    result_file<<setw(4)<<setfill(' ')<<i<<" "
               <<setw(4)<<setfill(' ')<<ridex[i]<<" "
           <<setw(4)<<setfill(' ')<<rjdex[i]<<" "
           <<setw(10)<<setfill(' ')<<fixed<<rpsl_lon[i]<<" "
           <<setw(10)<<setfill(' ')<<rpsl_lat[i]<<" "
           <<setw(10)<<setfill(' ')<<rwind_max[i]<<"  "
           <<setw(10)<<setfill(' ')<<rdist_wmax[i]<<"  "
           <<setw(10)<<setfill(' ')<<scientific<<rprecip_max[i]<<"  "
           <<setw(10)<<setfill(' ')<<fixed<<rdist_precipmax[i]<<"  "
           <<setw(10)<<setfill(' ')<<scientific<<rvort_max[i]<<"  "
           <<setw(10)<<setfill(' ')<<fixed<<rpsl_min[i]<<"  "
           <<setw(1)<<rexist_twc[i]<<" "
           <<setw(1)<<rexist_thick[i]<<endl;
  }

}

void TstormsTimestep::static_initialize()
{
  Util::init1DVec_padded(rlon, data->Glon);
  Util::init1DVec_padded(rlat, data->Glat);

  Util::init2DVec(Gvort, data->Glon.dim1(), data->Glat.dim1());
  Util::init2DVec(Gwind, data->Glon.dim1(), data->Glat.dim1());
  Util::init2DVec(Gprecip, data->Glon.dim1(), data->Glat.dim1());

  Util::init2DVec(Gtbar, data->Glon.dim1(), data->Glat.dim1());
  Util::init2DVec(Gpsl, data->Glon.dim1(), data->Glat.dim1());
  Util::init2DVec(Gthick, data->Glon.dim1(), data->Glat.dim1());

  Util::init2DVec(vort, rlon.dim1(), rlat.dim1());
  Util::init2DVec(wind, rlon.dim1(), rlat.dim1());
  Util::init2DVec(precip, rlon.dim1(), rlat.dim1());
  Util::init2DVec(tbar, rlon.dim1(), rlat.dim1());
  Util::init2DVec(psl, rlon.dim1(), rlat.dim1());
  Util::init2DVec(thick, rlon.dim1(), rlat.dim1());

  Util::init2DVec(psl_dy, rlon.dim1(), rlat.dim1());
  Util::init2DVec(psl_dx, rlon.dim1(), rlat.dim1());
  Util::init2DVec(tbar_dy, rlon.dim1(), rlat.dim1());
  Util::init2DVec(tbar_dx, rlon.dim1(), rlat.dim1());
  Util::init2DVec(thick_dy, rlon.dim1(), rlat.dim1());
  Util::init2DVec(thick_dx, rlon.dim1(), rlat.dim1());
}


void TstormsTimestep::static_cleanup(){

}

void TstormsTimestep::cleanup(){

  ridex.clear();
  rjdex.clear();
  rvort_max.clear();
  rvort_lon.clear();
  rvort_lat.clear();

  rwind_max.clear();

  rpsl_min.clear();
  rpsl_lon.clear();
  rpsl_lat.clear();

  rwind_max.clear();
  rdist_wmax.clear();
  rprecip_max.clear();
  rdist_precipmax.clear();

  rtwc_max.clear();
  rtwc_lon.clear();
  rtwc_lat.clear();
  rexist_twc.clear();

  rexist_thick.clear();
  rthick_max.clear();
  rthick_lon.clear();
  rthick_lat.clear();

}







void TstormsTimestep::setdate()
{
    avtCalendar::ComptimeObject obj = avtCalendar::componenttime(0,0,0,0,0,0);
//    obj.add(timestep, avtCalendar::time_Units)
}
/*
////////////////////////////////////////////////////////////////////////////
///////////////// CALENDAR ROUTINES ////////////////////////////////////////
                                                                         ///
int round(float x) {                                                     ///
    float tmp(0.0);                                                           ///
    if (modf(x,&tmp)<.5) return (int)floor(x);                           ///
    else return (int)(ceil(x)+.1);                                       ///
}                                                                        ///
                                                                         ///
int TstormsTimestep::calendar(int x) {                                   ///
    int no_leap_cal[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};         ///
    int    leap_cal[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};         ///
    //if (!(no_leap_calendar) && date[0] % 4 == 0)                   ///
    //    return leap_cal[x];                                              ///
    return no_leap_cal[x];                                               ///
}                                                                        ///
                                                                         ///
bool TstormsTimestep::contains_leap_year(float d) {                      ///
    if (!(no_leap_calendar)) {                                     ///
        if (date[0] % 4 == 0) {                                          ///
            if (date[1]<3) return true;                                  ///
            return false;                                                ///
        }                                                                ///
        if (date[0] % 4 == 3) {                                          ///
            if (date[1]>2) return true;                                  ///
            return false;                                                ///
        }                                                                ///
    }
    return false;                                                        ///
}                                                                        ///

// date[] contains
// year month day hours minutes seconds                                  ///
void TstormsTimestep::setdate() {                                        ///
  int n;                                                               ///
    for (n = 0; n < 6; n += 1) {                                         ///
      date[n] = 0; //hk (ref_date)[n];                                   ///
    }                                                                    ///

      float days_since_ref = 0; //hk (time)(timestep+1);                       ///
    while (days_since_ref >= 365) {                                      ///
        if (contains_leap_year(days_since_ref)) {                        ///
            if (days_since_ref >= 366) {                                 ///
                days_since_ref -= 366;                                   ///
                date[0] += 1;                                            ///
                if (date[1]==2 && date[2]==29) {                         ///
                    date[1] = 3; date[2] = 1;                            ///
                }                                                        ///
            }                                                            ///
            else break;                                                  ///
        } else {                                                         ///
            days_since_ref -= 365;                                       ///
            date[0] += 1;                                                ///
        }                                                                ///
    }                                                                    ///
    while (days_since_ref >= calendar(date[1])) {                        ///
        days_since_ref -= calendar(date[1]);                             ///
        date[1] += 1;                                                    ///
        if (date[1] > 12) {                                              ///
            date[0] += 1;                                                ///
            date[1] -= 12;                                               ///
        }                                                                ///
        if (date[2] > calendar(date[1])) {                               ///
            date[2] -= calendar(date[1]);                                ///
            date[1] += 1;                                                ///
        }                                                                ///
        if (date[1] > 12) {                                              ///
            date[0] += 1;                                                ///
            date[1] -= 12;                                               ///
        }                                                                ///
    }                                                                    ///
    while (days_since_ref >= 1) {                                        ///
        days_since_ref -= 1;                                             ///
        date[2] += 1;                                                    ///
        if (date[2] > calendar(date[1])) {                               ///
            date[2] = 1;                                                 ///
            date[1] += 1;                                                ///
            if (date[1] == 13) {                                         ///
                date[0] += 1;                                            ///
                date[1] = 1;                                             ///
            }                                                            ///
        }                                                                ///
    }                                                                    ///
    float hours(0), minutes(0), seconds(0);                                       ///
    minutes = 60.*modf(days_since_ref*24.,&hours);                       ///
    seconds = 60.*modf(minutes,&minutes);                                ///
    date[5] += round(seconds);                                           ///
    if (date[5] >= 60) {                                                 ///
        date[5] -= 60;                                                   ///
        minutes += 1.;                                                   ///
    }                                                                    ///
    date[4] += round(minutes);                                           ///
    if (date[4] >= 60) {                                                 ///
        date[4] -= 60;                                                   ///
        hours += 1.;                                                     ///
    }                                                                    ///
    date[3] += round(hours);                                             ///
    if (date[3] >= 24) {                                                 ///
        date[3] -= 24;                                                   ///
        date[2] += 1;                                                    ///
        if (date[2] > calendar(date[1])) {                               ///
            date[2] -= calendar(date[1]);                                ///
            date[1] += 1;                                                ///
            if (date[1] > 12) {                                          ///
                date[1] -= 12;                                           ///
                date[0] += 1;                                            ///
            }                                                            ///
        }                                                                ///
    }                                                                    ///
}                                                                        ///
//////////// END CALENDAR ROUTINES /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
*/
void TstormsTimestep::set_default_thresholds() {
  crit_vort = 1.6e-4;
  crit_twc = 0.8;
  crit_thick = 50.0;
  crit_dist = 4.0; //squared distance
  dist_twc = 5.0;
  crit_psl = 400.0;
  dist_psl = 5.0;
  lat_bound_n = 90.0;

  lat_bound_s = -90.0;
  atwc = 0.5; //interpolation factor for temperature levels
  do_smoothing = false;
  use_sfc_wind = true;
}

bool TstormsTimestep::contains(std::string a, std::string b) {
    if (a.find(b)==std::string::npos) return false;
    return true;
}

void TstormsTimestep::set_threshhold(std::string name, float val) {
    if (contains(name, std::string("crit_vort"))) {
        crit_vort = val;

    }
    else if (contains(name, std::string("crit_twc"))) {
        crit_twc = val;
    }
    else if (contains(name, std::string("crit_thick"))) {
        crit_thick = val;
    }
    else if (contains(name, std::string("crit_dist"))) {
        crit_dist = val;
    }
    else if (contains(name, std::string("dist_twc"))) {
        dist_twc = val;
    }
    else if (contains(name, std::string("crit_psl"))) {
        crit_psl = val;
    }
    else if (contains(name, std::string("dist_psl"))) {
        dist_psl = val;
    }
    else if (contains(name, std::string("lat_bound_n"))) {
      lat_bound_n = val;
    }
    else if (contains(name, std::string("lat_bound_s"))) {
        lat_bound_s = val;
    }
    else if (contains(name, std::string("atwc"))) {
        atwc = val;
    }
    else if (contains(name, std::string("do_smoothing"))) {
        do_smoothing = val ? true : false;
    }
    else if (contains(name, std::string("use_sfc_wind"))) {
        use_sfc_wind = val ? true : false;
    }
}

void TstormsTimestep::print_thresholds() {
  if (rank==0) {
    logfile<<"------------------------------------------"<<endl;
    logfile<<" Setting crit_vort to "<<crit_vort<<endl;
    logfile<<" Setting crit_twc to "<<crit_twc<<endl;
    logfile<<" Setting crit_thick to "<<crit_thick<<endl;
    logfile<<" Setting crit_dist to "<<crit_dist<<endl;
    logfile<<" Setting dist_twc to "<<dist_twc<<endl;
    logfile<<" Setting crit_psl to "<<crit_psl<<endl;
    logfile<<" Setting dist_psl to "<<dist_psl<<endl;
    logfile<<" Setting lat_bound_n to "<<lat_bound_n<<endl;
    logfile<<" Setting lat_bound_s to "<<lat_bound_s<<endl;
    logfile<<" Setting atwc to "<<atwc<<endl;
    logfile<<" Setting do_smoothing to "<<do_smoothing<<endl;
    logfile<<" Setting use_sfc_wind to "<<use_sfc_wind<<endl;
    logfile<<"------------------------------------------"<<endl;
  }
}

void TstormsTimestep::initialize_thresholds() {
    std::string name, s;
    int i;
    float val;
    ifstream f;
    struct stat buffer;
    if (stat("thresh.conf",&buffer)) return;
    f.open("thresh.conf");
    while (!f.eof()) {
        std::getline(f,s);
        if (s == "") continue;
        i = s.find("=");
        name = s.substr(0,i);
        val = (float) atof(s.substr(i+1).c_str());
        set_threshhold(name, val);
    }
      //logfile<<"Done initializing thresholds"<<endl;
}
//////// END TSTORMS THRESHHOLD INITIALIZATION /////////////////////////////
////////////////////////////////////////////////////////////////////////////
/*
void tstorm_process_file(std::string input_filename) {

  time_t start_time, end_time;

  start_time = time(NULL);

  NetCDFInterface nc_file(input_filename);

  int n;
  std::stringstream ss1, ss2;
  ss1<<input_filename<<"-raw_cyclone."<<setw(5)<<setfill('0')<<TIMESTEP_WITHIN_FILE<<".txt";
  ss2<<input_filename<<"-raw_cyclone."<<setw(5)<<setfill('0')<<TIMESTEP_WITHIN_FILE<<".log";

  std::string output_filename=ss1.str();
  std::string log_filename   =ss2.str();

  TstormsTimestep ts(1, &nc_file, output_filename, log_filename);

  ts.initialize_thresholds();
  ts.print_thresholds();

  ts.static_initialize();

  //for (n = 0; n < nc_file.time.dim1(); n += 1) {
    n = TIMESTEP_WITHIN_FILE;

    time_t start_t, end_t;
    start_t = time(NULL);

    ts.changeTimestep(n);

    std::cout << nc_file.time(n) << "\t"
           << ts.date[0] << " " << ts.date[1] << " " << ts.date[2]<< " "
           << ts.date[3] << " " << ts.date[4] << " " << ts.date[5] << "\n";

    ts.go();

    std::cout << endl;

    end_t = time(NULL);
    std::cout <<"\t*** timestep took "<<(end_t-start_t)<<" seconds "<<endl;
 // }

  ts.final_cleanup();

  end_time = time(NULL);
  std::cout << "***** file took "<< (end_time-start_time)<<" seconds overall"<<endl;

}

void tstorm_driver() {
    tstorm_process_file(FILENAME);
}

//
// function will look at list of files, #files in first and last timestep,
// and calculate the filename to process and the specific timestamp to process
//

#if 0
void calculate_file_offset(vector<std::string> &filenames) {
  NUM_FILES = filenames.size();

  int file_offset = 0;

  if (MPI_RANK < (NUM_STEPS_FIRST*(NUM_FILES-1)) ) { // earlier partitions
    file_offset = MPI_RANK/NUM_STEPS_FIRST;
    TIMESTEP_WITHIN_FILE = MPI_RANK % NUM_STEPS_FIRST;
    FILENAME = filenames[file_offset];
  }
  else { // last partition
    file_offset = NUM_FILES-1;
    TIMESTEP_WITHIN_FILE = MPI_RANK-(NUM_STEPS_FIRST*(NUM_FILES-1));
    FILENAME = filenames[file_offset];
  }

  cout<<"Node "<<MPI_RANK<<" will process "<<FILENAME<<", timestep = "<<TIMESTEP_WITHIN_FILE<<endl;
}
#endif

void calculate_file_offset2(vector<std::string> &filenames, vector<int> &times) {

  NUM_FILES = filenames.size();

  int file_offset = 0;

  vector<int> cumsum; //contains a cumulative index sum
  vector<int> convenience; //contains cumsum[i]-1

  cumsum.resize(times.size());
  convenience.resize(times.size());

  cumsum[0] = times[0];
  convenience[0] = cumsum[0]-1;

  for (int b=1; b<times.size(); b++) {
   cumsum[b]      = cumsum[b-1] + times[b];
   convenience[b] = cumsum[b]   - 1;
  }


  // now search for the MPI rank in the convenience array
  for (int b=0; b<convenience.size(); b++) {
     if (MPI_RANK<=convenience[b]) {
        file_offset = b;
    break;
     }
  }

  FILENAME = filenames[file_offset];
  if (file_offset==0) {
     TIMESTEP_WITHIN_FILE = MPI_RANK;
  }
  else {
     TIMESTEP_WITHIN_FILE = MPI_RANK - convenience[file_offset-1] -1;
  }

  cout<<"Node "<<MPI_RANK<<" will process "<<FILENAME<<", timestep = "<<TIMESTEP_WITHIN_FILE<<endl;
  cout.flush();
}



int main(int argc, char* argv[]) {

  std::string filelist;

  if (argc!=3) {
    cout<<"run tstorms filelist GRID_BOXES"<<endl;
    exit(1);
  }

  filelist = std::string(argv[1]);
  GRID_BOXES = atoi(argv[2]);

  vector<std::string> files;
  vector<int> timesteps_per_file;

  int size = 1;
  int rank = 0;

  double start_time, end_time;

#ifdef PARALLEL
  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  if (rank==0)
   cout<<"Tstorms:: hello from id "<<rank<<endl;

  if (rank==0)
    start_time=MPI_Wtime();

  MPI_RANK = rank;
  MPI_SIZE = size;

#endif

  //loop over all files in filelist and create a local list to process on node

  ifstream f;
  f.open(filelist.c_str());
  if (!f) {
    cout<<"Node "<<rank<<" could not open "<<filelist<<" for processing"<<endl;
#ifdef PARALLEL
    MPI_Finalize();
#endif
    exit(1);
  }

  files.clear();
  std::string name;
  int count=0;
  while (!f.eof()) {
    std::getline(f,name);

    if (name == "") {
      continue;
    }

    files.push_back(name);
    count++;
  }

   timesteps_per_file.resize(files.size());
   for (int i=0; i<files.size(); i++)
    timesteps_per_file[i]=-1;

   // calculate # timesteps per file

   if (MPI_RANK==0) {
    cout<< "files.size = "<<files.size()<<endl;
   // rank 0 will open files and determine # timesteps in each file
   for (int i=0; i<files.size(); i++) {
        cout<<"*********************** Trying to process "<<files[i]<<endl;
        NetCDFInterface nc_file(files[i]);
        timesteps_per_file[i] = nc_file.time.dim1();
        cout<<"***********************Found "<<timesteps_per_file[i]<<" steps in file "<<files[i]<<endl;
    }
  }

  // then bcast values to other nodes
#ifdef PARALLEL
     MPI_Bcast(&timesteps_per_file[0], timesteps_per_file.size(), MPI_INT, 0, MPI_COMM_WORLD);
#endif

  calculate_file_offset2(files, timesteps_per_file);

  tstorm_driver();

#ifdef PARALLEL

  if (rank==0) {
  end_time = MPI_Wtime();
  cout<<"*** Processing "<<count<<" files took"<<(end_time-start_time)<<" units of elapsed time"<<endl;
 }

  MPI_Finalize();
#endif

  return 0;

}
*/
