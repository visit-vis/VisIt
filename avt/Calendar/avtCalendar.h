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

#ifndef AVTCALENDAR_H
#define AVTCALENDAR_H

#include <calendar_exports.h>
#include <ImproperUseException.h>

// ****************************************************************************
//  Class:  avtCalendar
//
//  Purpose:
//
//  Programmer:  Hari Krishnan
//  Creation:    November 27, 2012
//
// ****************************************************************************
class CALENDAR_API avtCalendar
{
public:
    enum time_Units {
        time_Seconds = 1, time_Minutes, time_Hours, time_Days,
        time_Weeks, time_Months, time_Seasons, time_Years
    };

    enum Calendar { Standard, Gregorian, Julian, Mixed,
                    NoLeap, ThreeSixty, Clim, ClimLeap, Default };

    struct TimeObject
    {
        int type;
    };

    struct ComptimeObject;

    struct ReltimeObject : public TimeObject
    {                 /* reltime instance object */
        double value;
        //char units[CD_MAX_RELUNITS+1];
        std::string units;
        ReltimeObject() { type = 0; }

        int compare(TimeObject& other, const Calendar& calendar);

        ReltimeObject add(double value, const time_Units &units, const Calendar& calendar);
        ReltimeObject sub(double value,const time_Units &units,const Calendar& calendar);
        ReltimeObject toRelativeTime(char *outunits,const Calendar& calendar);
        ComptimeObject toComponentTime(const Calendar& calendar);
    };

    struct ComptimeObject : public TimeObject
    {                 /* comptime instance object */
        long year;
        int month;
        int day;
        int hour;
        int minute;
        double second;
        double absvalue;			     /* abstime value */
        std::string absunits;
        double fraction;			     /* abstime fractional part */
        ComptimeObject() { type = 1; }

        int compare(TimeObject& other, const Calendar& calendar);

        ComptimeObject add(double value,const time_Units& units,const Calendar& calendar);
        ComptimeObject sub(double value,const time_Units& units,const Calendar& calendar);
        ReltimeObject toRelativeTime(char* outunits, const Calendar& calendar);
        ComptimeObject toComponentTime(const Calendar& calendar);
    };

    static ComptimeObject
    s2c(char* ctime, const Calendar& calendar);

    static ReltimeObject
    s2r(char* ctime, char* runits, const Calendar& calendar = Mixed);

    static ReltimeObject
    c2r(const ComptimeObject &compTime, const char* relUnits, const Calendar &calendar = Mixed);

    static ComptimeObject
    r2c(const ReltimeObject &relTime, const Calendar &calendar = Mixed);

    static ReltimeObject
    r2r(const ReltimeObject &relTime, char *outUnits, const Calendar& calendar = Mixed);

    static int
    compare(const TimeObject& t1, const TimeObject& t2, const Calendar& calendar = Mixed);

    /// static functions..
    static ReltimeObject reltime(double value, char* units);

    static ReltimeObject relativetime(double value, char* units);

    static ComptimeObject comptime(long year, int month = 0, int day = 0,
                            int hour = -1, int minute = -1, double second = -1.0);

    static ComptimeObject componenttime(long year, int month = 0, int day = 0,
                            int hour = -1, int minute = -1, double second = -1.0);

    static ComptimeObject abstime(double absvalue,char *absunits);

    /// static member..

    static Calendar getDefaultCalendar() { return defaultCalendar; }
    static void setDefaultCalendar(const Calendar& calendar) { defaultCalendar = calendar; }

private:
    avtCalendar();
    ~avtCalendar();

    static Calendar defaultCalendar;
};

#endif
