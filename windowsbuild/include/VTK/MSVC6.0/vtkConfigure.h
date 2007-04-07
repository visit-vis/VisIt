/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkConfigure.h.in,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __vtkConfigure_h
#define __vtkConfigure_h

/* This header is configured by VTK's build process.  */

/*--------------------------------------------------------------------------*/
/* Platform Features                                                        */

/* Byte order.  */
/* #undef VTK_WORDS_BIGENDIAN */

/* Threading system.  */
/* #undef VTK_USE_PTHREADS */
/* #undef VTK_USE_SPROC */
/* #undef VTK_HP_PTHREADS */
#define VTK_USE_WIN32_THREADS

/* Size of fundamental data types.  */
#define VTK_SIZEOF_CHAR   1
#define VTK_SIZEOF_DOUBLE 8
#define VTK_SIZEOF_FLOAT  4
#define VTK_SIZEOF_INT    4
#define VTK_SIZEOF_LONG   4
#define VTK_SIZEOF_SHORT  2

/* Define size of long long and/or __int64 bit integer type only if the type
   exists.  */
/* #undef VTK_SIZEOF_LONG_LONG  */
#define VTK_SIZEOF___INT64   8

/* Whether types "long long" and "__int64" are enabled.  If a type is
   enabled then it is a unique fundamental type.  */
/* #undef VTK_TYPE_USE_LONG_LONG */
#define VTK_TYPE_USE___INT64

/* Some properties of the available types.  */
/* #undef VTK_TYPE_SAME_LONG_AND___INT64 */
/* #undef VTK_TYPE_SAME_LONG_LONG_AND___INT64 */
/* #undef VTK_TYPE_CONVERT_UI64_TO_DOUBLE */

/* Whether type "char" is signed (it may be signed or unsigned).  */
#define VTK_TYPE_CHAR_IS_SIGNED 1

/* Compiler features.  */
#define VTK_NO_EXPLICIT_TEMPLATE_INSTANTIATION
/* #undef VTK_NO_FULL_TEMPLATE_SPECIALIZATION */
/* #undef VTK_NO_ANSI_STRING_STREAM */
/* #undef VTK_NO_STD_NAMESPACE */
#define VTK_NO_FOR_SCOPE
#define VTK_COMPILER_HAS_BOOL
/* #undef VTK_ISTREAM_SUPPORTS_LONG_LONG */
/* #undef VTK_OSTREAM_SUPPORTS_LONG_LONG */
#define VTK_STREAM_EOF_SEVERITY 0
/* #undef VTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T */

/*--------------------------------------------------------------------------*/
/* VTK Platform Configuration                                               */

/* Whether we are building shared libraries.  */
#define VTK_BUILD_SHARED_LIBS

/* Whether vtkIdType is a 64-bit integer type (or a 32-bit integer type).  */
/* #undef VTK_USE_64BIT_IDS */

/* Whether we are using ANSI C++ streams (or old-style streams).  */
/* #undef VTK_USE_ANSI_STDLIB */

/* Whether VTK was built to support Carbon or Cocoa on the Mac.  */
/* #undef VTK_USE_CARBON */
/* #undef VTK_USE_COCOA */

/* Whether we are linking to Tcl/Tk statically.  */
/* #undef VTK_TCL_TK_STATIC */

/* Whether Tk widgets are NOT initialized when vtkRendering loads.  */
/* #undef VTK_USE_TK */

/* Wheter the Tcl/Tk support files are copied to the build dir */
/* #undef VTK_TCL_TK_COPY_SUPPORT_LIBRARY */

/* Configure internal Tk headers.  */
#ifdef VTK_USE_CARBON
# define USE_NON_CONST
# define MAC_OSX_TK
#endif


/*--------------------------------------------------------------------------*/
/* VTK Versioning                                                           */

/* Version number.  */
#define VTK_MAJOR_VERSION 5
#define VTK_MINOR_VERSION 0
#define VTK_BUILD_VERSION 0
#define VTK_VERSION "5.0.0"

/* C++ compiler used.  */
#define VTK_CXX_COMPILER "cl"

/* Compatibility settings.  */
/* #undef VTK_LEGACY_REMOVE */
/* #undef VTK_LEGACY_SILENT */

/*--------------------------------------------------------------------------*/
/* Setup VTK based on platform features and configuration.                  */

/* Setup vtkstd, a portable namespace for std.  */
#ifndef VTK_NO_STD_NAMESPACE
# define vtkstd std
#else
# define vtkstd
#endif

/* Define a "vtkstd_bool" type.  This should be used as the
   return type of comparison operators to keep STL happy on all
   platforms.  It should not be used elsewhere.  Only use bool
   if this file is included by a c++ file. */
#if defined(VTK_COMPILER_HAS_BOOL) && defined(__cplusplus)
typedef bool vtkstd_bool;
#else
typedef int vtkstd_bool;
#endif

/* Define a macro to help define template specializations.  Skip if
   compiling a windows resource file because the resource compiler
   warns about truncating the long symbol.  */
#if !defined(RC_INVOKED)
# if defined(VTK_NO_FULL_TEMPLATE_SPECIALIZATION)
#  define VTK_TEMPLATE_SPECIALIZE
# else
#  define VTK_TEMPLATE_SPECIALIZE template <>
# endif
#endif

/* Use the common for-scope work-around when compiling a source in VTK.  */
#if defined(VTK_IN_VTK) && !defined(VTK_NO_WORKAROUND_FOR_SCOPE)
# define VTK_WORKAROUND_FOR_SCOPE
#endif
#if defined(VTK_NO_FOR_SCOPE) && defined(VTK_WORKAROUND_FOR_SCOPE)
# ifndef for
#  define for if(0) {} else for
#  if defined(_MSC_VER)
#   pragma warning (disable: 4127) /* conditional expression is constant */
#  endif
# endif
#endif

/* Provide missing streaming operators.  */
#if defined(VTK_SIZEOF_LONG_LONG)
# if !defined(VTK_OSTREAM_SUPPORTS_LONG_LONG)
#  define VTK_IOSTREAM_NEED_OPERATORS_LL
# elif !defined(VTK_ISTREAM_SUPPORTS_LONG_LONG)
#  define VTK_IOSTREAM_NEED_OPERATORS_LL
# endif
# if defined(VTK_IOSTREAM_NEED_OPERATORS_LL)
   typedef long long vtkIOStreamSLL;
   typedef unsigned long long vtkIOStreamULL;
# endif
#elif defined(VTK_SIZEOF___INT64)
# if defined(_MSC_VER) && (_MSC_VER < 1300)
#  define VTK_IOSTREAM_NEED_OPERATORS_LL
   typedef __int64 vtkIOStreamSLL;
   typedef unsigned __int64 vtkIOStreamULL;
# endif
#endif

#endif
