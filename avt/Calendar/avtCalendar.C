/*****************************************************************************
*
* Copyright (c) 2000 - 2012, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/
#include "avtCalendar.h"
#include "cdms.h"
#include "cdmsint.h"
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <VisItException.h>

int cuErrOpts = 0;

typedef avtCalendar::time_Units time_Units;
typedef avtCalendar::TimeObject TimeObject;
typedef avtCalendar::ReltimeObject ReltimeObject;
typedef avtCalendar::ComptimeObject ComptimeObject;

avtCalendar::Calendar avtCalendar::defaultCalendar = avtCalendar::Default;

int cdParseRelunits(cdCalenType timetype, char* relunits, int* unit, cdCompTime* base_comptime);
int cdValidateTime(cdCalenType timetype, cdCompTime comptime);
void cdCompAddMixed(cdCompTime ct, double value, cdCompTime *result);

#define VALCMP(a,b) ((a)<(b)?-1:(b)<(a)?1:0)

bool is_reltimeobject(const TimeObject& object)
{
    return object.type == 0;
}

#define Reltime_Check is_reltimeobject

bool is_comptimeobject(const TimeObject& object)
{
    return object.type == 1;
}

#define Comptime_Check is_comptimeobject


/*****************************************************************************
 * Helper functions
 *****************************************************************************/

inline void onError(const char* msg)
{
    RETHROW VisItException(msg);
}

cdCalenType convertCalendar(const avtCalendar::Calendar& calendar)
{
    cdCalenType calentype = cdMixed;

    switch(calendar)
    {
        case avtCalendar::Standard: { calentype = cdStandard; break; }
        case avtCalendar::Gregorian: { calentype = cdStandard; break; }
        case avtCalendar::Julian: { calentype = cdJulian; break; }
        case avtCalendar::Mixed: { calentype = cdMixed; break; }

        case avtCalendar::NoLeap: { calentype = cdNoLeap; break; }

        case avtCalendar::ThreeSixty: { calentype = cd360; break; }
        case avtCalendar::Clim: { calentype = cdClim; break; }
        case avtCalendar::ClimLeap: { calentype = cdClimLeap; break; }
        case avtCalendar::Default: { calentype = cdMixed; break; }
        default: { calentype = cdMixed; }
    };

    return calentype;
}

avtCalendar::Calendar convertCalendar(const cdCalenType& calentype)
{
    avtCalendar::Calendar calendar = avtCalendar::Mixed;

    switch(calentype)
    {
        case cdStandard : { calendar = avtCalendar::Standard; break; }
        //case cdStandard: { calendar = avtCalendar::Gregorian; break; }
        case cdJulian: { calendar = avtCalendar::Julian; break; }
        case cdMixed: { calendar = avtCalendar::Mixed; break; }

        case cdNoLeap: { calendar = avtCalendar::NoLeap; break; }

        case cd360: { calendar = avtCalendar::ThreeSixty; break; }
        case cdClim: { calendar = avtCalendar::Clim; break; }
        case cdClimLeap: { calendar = avtCalendar::ClimLeap; break; }
        //case cdMixed: { calendar = avtCalendar::Default; break; }
        default: { calendar = avtCalendar::Mixed; }
    };

    return calendar;
}

static ReltimeObject
newreltimeobject(double value, const char *units)/* instance constructor function */
{                                /* these don't get an 'args' input */
    ReltimeObject self;
    cdCalenType calendar;
    cdUnitTime relunits;
    cdCompTime basetime;

    calendar = convertCalendar(avtCalendar::getDefaultCalendar());

    /* Check that the relative time units will parse */
    if (cdParseRelunits(calendar, const_cast<char*>(units), &relunits, &basetime))
        onError("Invalid relative time units");

    self.value = value;
    self.units = units;
    return self;
}

static ComptimeObject
newcomptimeobject(long year, int month, int day, int hour, int minute, double second)                 /* instance constructor function */
{
    ComptimeObject self;
    cdCompTime ct;
    std::string absunits;
    double absvalue;

    absunits = "day as %Y%m%d.%f";
    if(second<0.0) second = 0.0;
    if(minute<0) minute = 0;
    if(hour<0){
        hour=0;
        absunits="day as %Y%m%d.%f";
    }
    if(day<=0){
        day=1;
        absunits="calendar_month as %Y%m.%f";
    }
    if(month<=0){
        month=1;
        absunits="calendar_year as %Y.%f";
    }

    ct.year = year;
    ct.month = month;
    ct.day = day;
    ct.hour = (double)hour + ((double)minute + second/60.0)/60.0;
    if (cdValidateTime(cdStandard, ct))	     /* calendar is ignored */
        onError("Invalid component time");

    self.year = year;
    self.month = month;
    self.day = day;
    self.hour = hour;
    self.minute = minute;
    self.second = second;

    if (cdComp2Abs(ct, const_cast<char*>(absunits.c_str()), cdDouble, 0.0, &absvalue))
        onError("Invalid component time");

    self.absvalue = absvalue;
    self.absunits = absunits;
    self.fraction = 0.0;
    return self;
}

static ComptimeObject
newabstimeobject(long year, int month, int day, int hour, int minute, double second, double absvalue, char *absunits, double fraction)                 /* instance constructor function */
{
    ComptimeObject self;

    self = newcomptimeobject(year,month,day,hour,minute,second);
    self.absvalue = absvalue;
    self.absunits = absunits;
    self.fraction = fraction;
    return self;                /* a new type-instance object */
}

static int
Reltime_Compare(const ReltimeObject &v, const ReltimeObject &w)
{
    cdCalenType calendar;
    double v_days, w_days;

    calendar = convertCalendar(avtCalendar::getDefaultCalendar());
                         /* Convert both values to "days", then compare */
    cdRel2Rel(calendar, const_cast<char*>(v.units.c_str()), v.value, "days", &v_days);
    cdRel2Rel(calendar, const_cast<char*>(w.units.c_str()), w.value, "days", &w_days);
    return VALCMP(v_days, w_days);
}

static int
Comptime_Compare(const ComptimeObject &v, const ComptimeObject &w)
{
    int test;              /* compare objects and return -1, 0 or 1 */

    if (test = VALCMP(v.year,w.year))
        return test;
    else if (test = VALCMP(v.month,w.month))
        return test;
    else if (test = VALCMP(v.day,w.day))
        return test;
    else if (test = VALCMP(v.hour,w.hour))
        return test;
    else if (test = VALCMP(v.minute,w.minute))
        return test;
    else
        return (test = VALCMP(v.second,w.second));
}

/// Helper Functions
static ReltimeObject
reltime_add(const ReltimeObject &self, double value, const time_Units& units, cdCalenType calendar){
    double result, reltime;
    long incr;
    cdCompTime ct, ctmp;

                         /* Increment in integer months */
    if(units >= avtCalendar::time_Months){

        switch(units){
        case avtCalendar::time_Years:
            incr = (long)(12.0*value);
            break;
        case avtCalendar::time_Seasons:
            incr = (long)(3.0*value);
            break;
        case avtCalendar::time_Months:
            incr = (long)value;
            break;
        default:
            onError("Invalid units indicator");
            break;
        }
        cdRel2Rel(calendar, const_cast<char*>(self.units.c_str()), self.value, "months", &reltime);
        reltime += (double)incr;
        cdRel2Rel(calendar, "months", reltime, const_cast<char*>(self.units.c_str()), &result);
        return newreltimeobject(result, self.units.c_str());
    }
                         /* Increment in floating-point hours */
    else {
        switch(units){
        case avtCalendar::time_Weeks:
            value *= 168.0;
            break;
        case avtCalendar::time_Days:
            value *= 24.0;
            break;
        case avtCalendar::time_Hours:
            break;
        case avtCalendar::time_Minutes:
            value /= 60.0;
            break;
        case avtCalendar::time_Seconds:
            value /= 3600.0;
            break;
        default:
            onError("Invalid units indicator");
            break;
        }
        if (calendar == cdMixed){
            cdRel2Comp(calendar, const_cast<char*>(self.units.c_str()), self.value, &ctmp);
            cdCompAddMixed(ctmp, value, &ct);
            cdComp2Rel(calendar, ct, const_cast<char*>(self.units.c_str()), &result);
        }
        else {
            cdRel2Rel(calendar, const_cast<char*>(self.units.c_str()), self.value, "hours", &reltime);
            reltime += value;
            cdRel2Rel(calendar, "hours", reltime, const_cast<char*>(self.units.c_str()), &result);
        }
        return newreltimeobject(result, self.units.c_str());
    }
}

static ComptimeObject
reltime_tocomp(const ReltimeObject &self, cdCalenType calendar){
    cdCompTime compTime;
    int hour, min;
    double sec, fmin;

    cdRel2Comp(calendar, const_cast<char*>(self.units.c_str()), self.value, &compTime);
    hour = compTime.hour;
    fmin = 60.0*(compTime.hour - (double)hour);
    min = fmin;
    sec = 60.0*(fmin - (double)min);
    if (fabs(sec)<1.0e-11)
        sec=0.0;

    return newcomptimeobject((long)compTime.year, (int)compTime.month, (int)compTime.day, hour, min, sec);
}

static ReltimeObject
reltime_torel(const ReltimeObject &self, char *outunits, cdCalenType calendar){

    double outTime;

    cdRel2Rel(calendar, const_cast<char*>(self.units.c_str()), self.value, outunits, &outTime);

    return newreltimeobject(outTime, outunits);
}

static ReltimeObject
comptime_torel(const ComptimeObject &self, const char *outunits, cdCalenType calendar){
    cdCompTime ct;
    double reltime;

    ct.year = self.year;
    ct.month = self.month;
    ct.day = self.day;
    ct.hour = (double)self.hour + (((double)self.minute+self.second/60.0)/60.0);

    cdComp2Rel(calendar, ct, const_cast<char*>(outunits), &reltime);
    return newreltimeobject(reltime, outunits);
}

static int
reltime_cmp(const ReltimeObject &self, const TimeObject &other, cdCalenType calendar){
    cdCalenType saveCalendar;
    int result;
    ReltimeObject otherReltime;

                         /* The compare is done by the module methods, which
                            get the value of the calendar from "DefaultCalendar",
                        so temporarily override this. */

    saveCalendar = convertCalendar(avtCalendar::getDefaultCalendar());
    avtCalendar::setDefaultCalendar(convertCalendar(calendar));

    if (is_reltimeobject(other)){
        result = Reltime_Compare(self,static_cast<const ReltimeObject&>(other));
        avtCalendar::setDefaultCalendar(convertCalendar(saveCalendar));
        return result;
    }
    else if (is_comptimeobject(other)){
                         /* Coerce comptime to reltime */
        otherReltime = comptime_torel(static_cast<const ComptimeObject&>(other), const_cast<char*>(self.units.c_str()), calendar);
        result = Reltime_Compare(self,otherReltime);
        avtCalendar::setDefaultCalendar(convertCalendar(saveCalendar));
        return result;
    }
    else {
        avtCalendar::setDefaultCalendar(convertCalendar(saveCalendar));
        onError("Cannot compare a time and non-time object");
    }
    return -1;
}

static ComptimeObject
comptime_add(const ComptimeObject &self, double value, time_Units units, cdCalenType calendar){
    long incr;
    cdCompTime ct, ctmp;
    double reltime;
    int hour, min;
    double sec, fmin;


    /* Increment in integer months */
    if(units >= avtCalendar::time_Months){

        switch(units){
        case avtCalendar::time_Years:
            incr = (long)(12.0*value);
            break;
        case avtCalendar::time_Seasons:
            incr = (long)(3.0*value);
            break;
        case avtCalendar::time_Months:
            incr = (long)value;
            break;
        default:
            onError("Invalid units indicator");
            break;
        }
        ct.year = self.year;
        ct.month = self.month;
        ct.day = self.day;
        ct.hour = (double)self.hour + ((double)self.minute + self.second/60.0)/60.0;
        cdComp2Rel(calendar, ct, "months", &reltime);
        reltime += (double)incr;
        cdRel2Comp(calendar, "months", reltime, &ct);
        hour = ct.hour;
        fmin = 60.0*(ct.hour - (double)hour);
        min = fmin;
        sec = 60.0*(fmin - (double)min);
        return newcomptimeobject((long)ct.year, ct.month, ct.day, hour, min, sec);
    }
                         /* Increment in floating-point hours */
    else {
        switch(units){
        case avtCalendar::time_Weeks:
            value *= 168.0;
            break;
        case avtCalendar::time_Days:
            value *= 24.0;
            break;
        case avtCalendar::time_Hours:
            break;
        case avtCalendar::time_Minutes:
            value /= 60.0;
            break;
        case avtCalendar::time_Seconds:
            value /= 3600.0;
            break;
        default:
            onError("Invalid units indicator");
            break;
        }
        ct.year = self.year;
        ct.month = self.month;
        ct.day = self.day;
        ct.hour = (double)self.hour + ((double)self.minute + self.second/60.0)/60.0;

        if (calendar == cdMixed){
            cdCompAddMixed(ct, value, &ctmp);
            ct.year = ctmp.year;
            ct.month = ctmp.month;
            ct.day = ctmp.day;
            ct.hour = ctmp.hour;
        }
        else {
            cdComp2Rel(calendar, ct, "hours", &reltime);
            reltime += value;
            cdRel2Comp(calendar, "hours", reltime, &ct);
        }
        hour = ct.hour;
        fmin = 60.0*(ct.hour - (double)hour);
        min = fmin;
        sec = 60.0*(fmin - (double)min);
        return newcomptimeobject((long)ct.year, ct.month, ct.day, hour, min, sec);
    }
}

static ComptimeObject
comptime_tocomp(const ComptimeObject &self, cdCalenType calendar){

    return newcomptimeobject(self.year, self.month, self.day, self.hour, self.minute, self.second);
}


static int
comptime_cmp(const ComptimeObject &self, const TimeObject &other, cdCalenType calendar){
    cdCalenType saveCalendar;
    ComptimeObject otherComptime;
    int result;

                         /* The comparisons are done by the module functions, which
                            get the calendar from the value of "DefaultCalendar", so
                        set this temporarily */
    saveCalendar = convertCalendar(avtCalendar::getDefaultCalendar());
    avtCalendar::setDefaultCalendar(convertCalendar(calendar));

    if (is_comptimeobject(other)){
        result = Comptime_Compare(self, static_cast<const ComptimeObject&>(other));
        avtCalendar::setDefaultCalendar(convertCalendar(saveCalendar));
        return result;
    }
    else if (is_reltimeobject(other)){
                         /* Coerce reltime to comptime */
        otherComptime = reltime_tocomp(static_cast<const ReltimeObject&>(other), calendar);
        result = Comptime_Compare(self, otherComptime);
        avtCalendar::setDefaultCalendar(convertCalendar(saveCalendar));
        return result;
    }
    else {
        avtCalendar::setDefaultCalendar(convertCalendar(saveCalendar));
        onError("Cannot compare a time and non-time object");
    }
    return -1;
}


/// RelTime functions

/* Add a time increment to a relative time,
   e.g., rnew = r.add(3, Months [, calendar]) */

ReltimeObject
ReltimeObject::add(double value, const time_Units &units, const Calendar& calendar)
{
    //calendar = GET_CALENDAR;
    return reltime_add(*this, value, units, convertCalendar(calendar));
}

/* Subtract a time increment from a relative time
   e.g., rnew = r.sub(3, Months [, calendar]) */

ReltimeObject
ReltimeObject::sub(double value,const time_Units& units,const Calendar& calendar)
{
    //calendar = GET_CALENDAR;
    return reltime_add(*this, -value, units, convertCalendar(calendar));
}

/* Convert a relative time to component time
   e.g., r.tocomp([calendar])*/

ComptimeObject
ReltimeObject::toComponentTime(const Calendar& calendar)
{
    //calentype = GET_CALENDAR;
    return reltime_tocomp(*this, convertCalendar(calendar));
}

/* Convert a relative time to a relative time
   with different units, e.g.,
rnew = r.torel("days since 1997" [, calendar])*/

ReltimeObject
ReltimeObject::toRelativeTime(char *outunits,const Calendar& calendar)
{
    //calentype = GET_CALENDAR;
    return reltime_torel(*this, outunits, convertCalendar(calendar));
}

/* Return -1, 0, or 1 as self is less than, equal to,
   or greater than other. Syntax is r.cmp(other [,calendar])
other may be a reltime or a comptime. */
int
ReltimeObject::compare(TimeObject& other, const Calendar& calendar)
{
    //calendar = GET_CALENDAR;
    return reltime_cmp(*this, other, convertCalendar(calendar));
}

/// Comptime functions

ComptimeObject
ComptimeObject::add(double value,const time_Units& units,const Calendar& calendar)
{
    //calendar = GET_CALENDAR;
    return comptime_add(*this, value, units, convertCalendar(calendar));
}

/* Subtract a time increment from a component time
   e.g., cnew = c.sub(3, Months [, calendar]) */

ComptimeObject
ComptimeObject::sub(double value,const time_Units& units,const Calendar& calendar)
{
    //calendar = GET_CALENDAR;
    return comptime_add(*this, -value, units, convertCalendar(calendar));
}

                         /* Convert a component time to a relative time, e.g.,
                        rnew = c.torel("days since 1997" [, calendar])*/

ReltimeObject
ComptimeObject::toRelativeTime(char* outunits, const Calendar& calendar)
{
    //calentype = GET_CALENDAR;
    return comptime_torel(*this, outunits, convertCalendar(calendar));
}

                         /* Copy a component time. This function is provided
                        so that tocomp() can be used for both types.
                        cnew = c.torel([calendar])*/

ComptimeObject
ComptimeObject::toComponentTime(const Calendar& calendar)
{
    //calentype = GET_CALENDAR;
    return comptime_tocomp(*this, convertCalendar(calendar));
}

int
ComptimeObject::compare(TimeObject& other, const Calendar& calendar)
{
    //calendar = GET_CALENDAR;
    return comptime_cmp(*this, other, convertCalendar(calendar));
}

//static struct PyMethodDef comptime_instance_methods[] = {     /* instance methods */
//    { "add", (PyCFunction)PyCdComptime_Add, 1},
//    { "sub", (PyCFunction)PyCdComptime_Sub, 1},
//    { "torel", (PyCFunction)PyCdComptime_Torel, 1},
//    { "torelative", (PyCFunction)PyCdComptime_Torel, 1},
//    { "tocomp", (PyCFunction)PyCdComptime_Tocomp, 1},
//    { "tocomponent", (PyCFunction)PyCdComptime_Tocomp, 1},
//    { "cmp", (PyCFunction)PyCdComptime_Cmp, 1},
//    {NULL,         NULL}
//};


/// External Functions ...

/* Character string -> component time */

//static char doc_char2comp[] = "s2c(string [,calendar])";

static ComptimeObject
s2c_h(char* ctime, cdCalenType calentype = cdMixed)
{
    cdCompTime compTime;
    int hour, min;
    double sec, fmin;

    cdChar2Comp(calentype, ctime, &compTime);

    hour = compTime.hour;
    fmin = 60.0*(compTime.hour - (double)hour);
    min = fmin;
    sec = 60.0*(fmin - (double)min);

    return newcomptimeobject((long)compTime.year, (int)compTime.month, (int)compTime.day, hour, min, sec);
}

/* Character string -> relative time */

//static char doc_char2rel[] = "s2r(string, relunits [, calendar])";

static ReltimeObject
s2r_h(char* ctime, char* runits, cdCalenType calentype = cdMixed)
{
    double rtime;

    cdChar2Rel(calentype, ctime, runits, &rtime);

    return newreltimeobject(rtime, runits);
}

/* Component time -> relative time */

//static char doc_comp2rel[] = "c2r( comptime, relunits [,calendar])";

static ReltimeObject
c2r_h(const ComptimeObject &compTime, const char* relUnits, cdCalenType calentype = cdMixed)
{
    //calentype = GET_CALENDAR;
    return comptime_torel(compTime, relUnits, calentype);
}


/* Relative time -> component time */

//static char doc_rel2comp[] = "r2c( reltime [, calendar])";

static ComptimeObject
r2c_h(const ReltimeObject &relTime, cdCalenType calentype = cdMixed)
{
    //calentype = GET_CALENDAR;
    return reltime_tocomp(relTime, calentype);
}

/* Relative time -> relative time */

//static char doc_rel2rel[] = "r2r( reltime, newunits [, calendar])";

static ReltimeObject
r2r_h(const ReltimeObject &relTime, char *outUnits, cdCalenType calentype = cdMixed)
{
    //calentype = GET_CALENDAR;
    return reltime_torel(relTime, outUnits, calentype);
}
//static char doc_cmp[] = "cmp( time, time [, calendar])";

static int
cmp_h(const TimeObject& t1, const TimeObject& t2, cdCalenType calendar = cdMixed)
{

    //calendar = GET_CALENDAR;
    if (is_reltimeobject(t1)){
        return reltime_cmp(static_cast<const ReltimeObject&>(t1),t2,calendar);
    }
    else if (is_comptimeobject(t1)){
        return comptime_cmp(static_cast<const ComptimeObject&>(t1),t2,calendar);
    }
    else
    {
        onError("Argument is not a time");
    }
    return -1;
}


/// Calendar API..

ComptimeObject
avtCalendar::s2c(char* ctime, const Calendar &calendar)
{
    return s2c_h(ctime,convertCalendar(calendar));
}

ReltimeObject
avtCalendar::s2r(char* ctime, char* runits, const Calendar &calendar)
{
    return s2r_h(ctime,runits,convertCalendar(calendar));
}

ReltimeObject
avtCalendar::c2r(const ComptimeObject &compTime, const char* relUnits, const Calendar& calendar)
{
    return c2r_h(compTime,relUnits,convertCalendar(calendar));
}
ComptimeObject
avtCalendar::r2c(const ReltimeObject &relTime, const Calendar& calendar)
{
    return r2c_h(relTime,convertCalendar(calendar));
}

ReltimeObject
avtCalendar::r2r(const ReltimeObject &relTime, char *outUnits, const Calendar& calendar)
{
    return r2r_h(relTime,outUnits,convertCalendar(calendar));
}

int
avtCalendar::compare(const TimeObject& t1, const TimeObject& t2, const Calendar &calendar)
{
    return cmp_h(t1,t2,convertCalendar(calendar));
}


ReltimeObject
avtCalendar::reltime(double value, char* units)
{
    return newreltimeobject(value, units);  /* make a new type-instance object */
}                                         /* the hook from module to type... */

ReltimeObject
avtCalendar::relativetime(double value, char* units)
{
    return reltime(value, units);  /* make a new type-instance object */
}                                         /* the hook from module to type... */

ComptimeObject
avtCalendar::comptime(long year, int month, int day,
                        int hour, int minute, double second)
{
    return newcomptimeobject(year, month, day, hour, minute, second);  /* make a new type-instance object */
}

ComptimeObject
avtCalendar::componenttime(long year, int month, int day,
                        int hour, int minute, double second)
{
    return comptime(year, month, day, hour, minute, second);  /* make a new type-instance object */
}

ComptimeObject
avtCalendar::abstime(double absvalue,char *absunits)
{
    cdCompTime comptime;
    double fraction;
    int hour, minute;
    double second, fmin;

    if(cdAbs2Comp(absunits, (void *)&absvalue, cdDouble, &comptime, &fraction))
        onError("Invalid absolute time");

    hour = comptime.hour;
    fmin = 60.0*(comptime.hour-(double)hour);
    minute = fmin;
    second = 60.0*(fmin-(double)minute);

    return newabstimeobject((long)comptime.year, comptime.month, comptime.day, hour, minute, second, absvalue, absunits, fraction);  /* make a new type-instance object */
}

inline 
avtCalendar::avtCalendar()
{}

avtCalendar::~avtCalendar()
{}

#include "cdtime/cdTimeConv.c"
