/*
** (c) 1996-2003 The Regents of the University of California (through
** E.O. Lawrence Berkeley National Laboratory), subject to approval by
** the U.S. Department of Energy.  Your use of this software is under
** license -- the license agreement is attached and included in the
** directory as license.txt or you may contact Berkeley Lab's Technology
** Transfer Department at TTD@lbl.gov.  NOTICE OF U.S. GOVERNMENT RIGHTS.
** The Software was developed under funding from the U.S. Government
** which consequently retains certain rights as follows: the
** U.S. Government has been granted for itself and others acting on its
** behalf a paid-up, nonexclusive, irrevocable, worldwide license in the
** Software to reproduce, prepare derivative works, and perform publicly
** and display publicly.  Beginning five (5) years after the date
** permission to assert copyright is obtained from the U.S. Department of
** Energy, and subject to any subsequent five (5) year renewals, the
** U.S. Government is granted for itself and others acting on its behalf
** a paid-up, nonexclusive, irrevocable, worldwide license in the
** Software to reproduce, prepare derivative works, distribute copies to
** the public, perform publicly and display publicly, and to permit
** others to do so.
*/

#ifndef _BL_PROFILER_H_
#define _BL_PROFILER_H_
//
// $Id: Profiler.H,v 1.8 2001/08/21 22:16:26 car Exp $
//
#include <iostream>
#include <string>
#include <typeinfo>

class Profiler
{
public:
    class Tag;
    Profiler(const Tag& tag_, bool hold = false);
    void start();
    void stop();
    ~Profiler();
    static void on();
    static void off();
    static bool is_profiling();
    static std::string clean_name(const std::string& str);
    static void Initialize();
    static void Finalize();
private:
    static void glean();
    const Tag& tag;
    bool started;
    static bool profiling;
    Profiler(const Profiler& prf);
    Profiler& operator=(const Profiler& prf);
};

class Profiler::Tag
{
public:
    explicit Tag(const std::string& tag_);
    const std::string& name() const;
private:
    int itag;
    const std::string tag;
    static int next_itag;
};

#ifdef BL_PROFILING
#define BL_PROFILE(a)							\
static Profiler::Tag bl_prf_tag_((a));			\
Profiler bl_prf_(bl_prf_tag_, false)

#define BL_PROFILE_TIMER(var, a)					\
static Profiler::Tag bl_prf_tag_##var((a));			\
Profiler bl_prf_##var(bl_prf_tag_##var, true)

#define BL_PROFILE_START(var) bl_prf_##var.start()
#define BL_PROFILE_STOP(var) bl_prf_##var.stop()
#define BL_PROFILE_THIS_NAME() Profiler::clean_name(std::string(typeid(*this).name()))
#else
#define BL_PROFILE(a)
#define BL_PROFILE_TIMER(var, a)
#define BL_PROFILE_START(var)
#define BL_PROFILE_STOP(var)
#define BL_PROFILE_THIS_NAME()
#endif

#endif
