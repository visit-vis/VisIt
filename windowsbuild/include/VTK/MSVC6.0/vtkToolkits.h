/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkToolkits.h.in,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __vtkToolkits_h
#define __vtkToolkits_h

/* This header is configured by VTK's build process.  */

/*--------------------------------------------------------------------------*/
/* Selected VTK Toolkits                                                    */

/* #undef VTK_USE_PARALLEL */
#define VTK_USE_RENDERING
/* #undef VTK_USE_GL2PS */

/* The Hybrid and VolumeRendering kits are now switched with Rendering.  */
#ifdef VTK_USE_RENDERING
# define VTK_USE_HYBRID
# define VTK_USE_VOLUMERENDERING
#endif

/*--------------------------------------------------------------------------*/
/* Rendering Configuration                                                  */

/* #undef VTK_USE_X */
#define VTK_USE_MANGLED_MESA
#define VTK_USE_OPENGL_LIBRARY
/* #undef VTK_OPENGL_HAS_OSMESA */
/* #undef VTK_USE_OFFSCREEN */

/*--------------------------------------------------------------------------*/
/* Wrapping Configuration                                                   */

/* #undef VTK_WRAP_TCL */
/* #undef VTK_WRAP_PYTHON */
/* #undef VTK_WRAP_JAVA */

/*--------------------------------------------------------------------------*/
/* Other Configuration Options                                              */

/* Whether we are building MPI support.  */
/* #undef VTK_USE_MPI */

/* Should VTK use the display?  */
#define VTK_USE_DISPLAY

/* is VTK_DATA_ROOT defined? */
/* #undef VTK_DATA_ROOT */
#ifdef VTK_DATA_ROOT
#  undef VTK_DATA_ROOT
#  define VTK_DATA_ROOT "VTK_DATA_ROOT-NOTFOUND"
#endif

/* Debug leaks support.  */
/* #undef VTK_DEBUG_LEAKS */

/* Whether VTK is using its own utility libraries.  */
/* #undef VTK_USE_SYSTEM_PNG */
/* #undef VTK_USE_SYSTEM_ZLIB */
/* #undef VTK_USE_SYSTEM_JPEG */
/* #undef VTK_USE_SYSTEM_TIFF */
/* #undef VTK_USE_SYSTEM_EXPAT */
/* #undef VTK_USE_SYSTEM_FREETYPE */

/* Whether VTK is using vfw32 and if it supports video capture */
#define VTK_USE_VIDEO_FOR_WINDOWS
#define VTK_VFW_SUPPORTS_CAPTURE

/* Whether the real python debug library has been provided.  */
/* #undef VTK_WINDOWS_PYTHON_DEBUGGABLE */

/*--------------------------------------------------------------------------*/
/* Setup VTK based on platform features and configuration.                  */

/* OGLR */
#if ((defined(VTK_USE_OPENGL_LIBRARY) && !defined(_WIN32)) || \
     (defined(VTK_USE_X) && defined(_WIN32)) || \
     (defined(VTK_USE_MANGLED_MESA) && !defined(_WIN32))) && \
     !(defined (VTK_USE_CARBON) || defined(VTK_USE_COCOA))
# define VTK_USE_OGLR
#endif

#endif
