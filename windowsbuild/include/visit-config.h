/*****************************************************************************
*
* Copyright (c) 2000 - 2007, The Regents of the University of California
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
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
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef VISIT_CONFIG_H
#define VISIT_CONFIG_H
/* include/visit-config.h.  Custom generated for Intel 686 running MS Windows 2000
 */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
/*#define TIME_WITH_SYS_TIME 1*/

/* Define SPLASHSCREEN if the splash screen is enabled */
#define SPLASHSCREEN 1

/* Define USE_PTY if we want to use PTYs */
/*#define USE_PTY 1*/

/* Define for the VERSION number of the package. */
#define VERSION "XXX"

/* The number of bytes in a boolean.  */
#define SIZEOF_BOOLEAN 0

/* The number of bytes in a char.  */
#define SIZEOF_CHAR 1

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a long long.  */
#define SIZEOF_LONG_LONG 8

/* The number of bytes in a unsigned char.  */
#define SIZEOF_UNSIGNED_CHAR 1

/* The number of bytes in a unsigned short.  */
#define SIZEOF_UNSIGNED_SHORT 2

/* The number of bytes in a unsigned int.  */
#define SIZEOF_UNSIGNED_INT 4

/* The number of bytes in a unsigned long.  */
#define SIZEOF_UNSIGNED_LONG 4

/* The number of bytes in a unsigned long long.  */
#define SIZEOF_UNSIGNED_LONG_LONG 8

/* The number of bytes in a float.  */
#define SIZEOF_FLOAT 4

/* The number of bytes in a long float.  */
#define SIZEOF_LONG_FLOAT 0

/* The number of bytes in a double.  */
#define SIZEOF_DOUBLE 8

/* The number of bytes in a long double.  */
#define SIZEOF_LONG_DOUBLE 12

/* The number of bytes in a void *.  */
#define SIZEOF_VOID_P 4

/* The number of bytes in a boolean.  */
/*#define SIZEOF_BOOLEAN 1*/

/* Define if you have the div function.  */
/*#define HAVE_DIV 1*/

/* Define if you have the memmove function.  */
/*#define HAVE_MEMMOVE 1*/

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the strerror function.  */
/*#define HAVE_STRERROR 1*/

/* Define if you have the <fcntl.h> header file.  */
/*#define HAVE_FCNTL_H 1*/

/* Define if you have the <limits.h> header file.  */
/*#define HAVE_LIMITS_H 1*/

/* Define if you have the <sys/time.h> header file.  */
/*#define HAVE_SYS_TIME_H 1*/

/* Define if you have the <sys/types.h> header file.  */
/*#define HAVE_SYS_TYPES_H 1*/

/* Define if you have the <unistd.h> header file.  */
/*#define HAVE_UNISTD_H 1*/

/* Define if you have the prototype for ftime in the <sys/timeb.h>.  */
/*#define HAVE_FTIME_PROTOTYPE 1*/

/* Define if socklen_t is defined */
/*#define HAVE_SOCKLEN_T 1*/

/* Define the extension for plugins */
#define PLUGIN_EXTENSION ".dll" 

/* Define the backslash used in filenames. (char version) */
#define SLASH_CHAR '\\'

/* Define the backslash used in filenames. (string version) */
#define SLASH_STRING "\\"

/* Define if you have the <zlib.h> header file.  */
#define HAVE_ZLIB_H 1

/* Define if you have the bz2 library (-lbz2).  */
#define HAVE_LIBBZ2 1

/* Define if you have the z library (-lz).  */
/*#define HAVE_LIBZ 1*/

#define HAVE_THREADS

#endif

