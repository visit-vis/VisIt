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

/* include/config.h.  Generated automatically by configure.  */
/* include/config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef gid_t */

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef uid_t */

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* Define as _setjmp and _longjmp if they work instead of setjmp and longjmp */
/* #undef setjmp */
/* #undef longjmp */

/* Define if the SILO SDX driver is compiled. */
/*#define HAVE_SDX_DRIVER 1*/

/* Define if the DMF driver is compiled */
/* #undef HAVE_DMF_DRIVER */

/* Define if the HDF5 driver is compiled */
#define HAVE_HDF5_DRIVER 1

/* Define if the NetCDF driver is compiled */
/*#define HAVE_NETCDF_DRIVER 1*/

/* Define if the EXODUS driver is compiled */
/* #undef HAVE_EXODUS_DRIVER */

/* Define if the PDB driver is compiled */
#define HAVE_PDB_DRIVER 1

/* Define if the TAURUS driver is compiled */
#define HAVE_TAURUS_DRIVER 1

/* Define if you have a pointer to the fclose() function available. */
#define HAVE_FCLOSE_POINTER 1

/* Define if you have a pointer to the fflush() function available. */
#define HAVE_FFLUSH_POINTER 1

/* Define if you have a pointer to the fopen() function available. */
#define HAVE_FOPEN_POINTER 1

/* Define if you have a pointer to the fprintf() function available. */
#define HAVE_FPRINTF_POINTER 1

/* Define if you have a pointer to the fread() function available. */
#define HAVE_FREAD_POINTER 1

/* Define if you have a pointer to the fseek() function available. */
#define HAVE_FSEEK_POINTER 1

/* Define if you have a pointer to the setvbuf() function available. */
#define HAVE_SETVBUF_POINTER 1

/* Define if you have a pointer to the ftell() function available. */
#define HAVE_FTELL_POINTER 1

/* Define if you have a pointer to the fwrite() function available. */
#define HAVE_FWRITE_POINTER 1

/* Define for the VERSION number of the package. */
#define VERSION "4.5.1"

/* Define to disable the "stat" file system checks. */
/* #undef DISABLE_FILESYSTEM_CHECKS */

/* The number of bytes in a boolean.  */
#define SIZEOF_BOOLEAN 0

/* The number of bytes in a char.  */
#define SIZEOF_CHAR 1

/* The number of bytes in a double.  */
#define SIZEOF_DOUBLE 8

/* The number of bytes in a float.  */
#define SIZEOF_FLOAT 4

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a int16.  */
#define SIZEOF_INT16 0

/* The number of bytes in a int32.  */
#define SIZEOF_INT32 0

/* The number of bytes in a int64.  */
#define SIZEOF_INT64 0

/* The number of bytes in a int8.  */
#define SIZEOF_INT8 0

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a long double.  */
#define SIZEOF_LONG_DOUBLE 12

/* The number of bytes in a long float.  */
#define SIZEOF_LONG_FLOAT 0

/* The number of bytes in a long long.  */
#define SIZEOF_LONG_LONG 8

/* The number of bytes in a real32.  */
#define SIZEOF_REAL32 0

/* The number of bytes in a real64.  */
#define SIZEOF_REAL64 0

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* The number of bytes in a size_t.  */
#define SIZEOF_SIZE_T 4

/* The number of bytes in a uint16.  */
#define SIZEOF_UINT16 0

/* The number of bytes in a uint32.  */
#define SIZEOF_UINT32 0

/* The number of bytes in a uint64.  */
#define SIZEOF_UINT64 0

/* The number of bytes in a uint8.  */
#define SIZEOF_UINT8 0

/* The number of bytes in a unsigned char.  */
#define SIZEOF_UNSIGNED_CHAR 1

/* The number of bytes in a unsigned int.  */
#define SIZEOF_UNSIGNED_INT 4

/* The number of bytes in a unsigned long.  */
#define SIZEOF_UNSIGNED_LONG 4

/* The number of bytes in a unsigned long long.  */
#define SIZEOF_UNSIGNED_LONG_LONG 8

/* The number of bytes in a unsigned short.  */
#define SIZEOF_UNSIGNED_SHORT 2

/* The number of bytes in a void *.  */
#define SIZEOF_VOID_P 4

/* Define if you have the add_history function.  */
/* #undef HAVE_ADD_HISTORY */

/* Define if you have the atexit function.  */
#define HAVE_ATEXIT 1

/* Define if you have the div function.  */
#define HAVE_DIV 1

/* Define if you have the fnmatch function.  */
#define HAVE_FNMATCH 1

/* Define if you have the isnan function.  */
#define HAVE_ISNAN 1

/* Define if you have the fpclass function.  */
/* #undef HAVE_FPCLASS */

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the memmove function.  */
/*#define HAVE_MEMMOVE 1*/

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1

/* Define if you have the readline function.  */
/* #undef HAVE_READLINE */

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the <dmf.h> header file.  */
/* #undef HAVE_DMF_H */

/* Define if you have the <dsl.h> header file.  */
/* #undef HAVE_DSL_H */

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <fnmatch.h> header file.  */
#define HAVE_FNMATCH_H 1

/* Define if you have the <ieeefp.h> header file.  */
/* #undef HAVE_IEEEFP_H */

/* Define if you have the <hdf5.h> header file.  */
#define HAVE_HDF5_H

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <readline/history.h> header file.  */
/* #undef HAVE_READLINE_HISTORY_H */

/* Define if you have the <readline/readline.h> header file.  */
/* #undef HAVE_READLINE_READLINE_H */

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <unistd.h> header file.  */
/*#define HAVE_UNISTD_H 1*/

/* Define if you have the <vbt.h> header file.  */
/* #undef HAVE_VBT_H */

/* Define if you have the <zlib.h> header file.  */
/*#define HAVE_ZLIB_H 1*/

/* Define if you have the dmf library (-ldmf).  */
/* #undef HAVE_LIBDMF */

/* Define if you have the dsl library (-ldsl).  */
/* #undef HAVE_LIBDSL */

/* Define if you have the hdf5 library (-lhdf5).  */
#define HAVE_LIBHDF5

/* Define if you have the vbt library (-lvbt).  */
/* #undef HAVE_LIBVBT */

/* Define if you have the z library (-lz).  */
/*#define HAVE_LIBZ 1*/
