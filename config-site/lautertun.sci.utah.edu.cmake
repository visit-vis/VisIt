#/Projects/VisIt/Thirdparty/visit/cmake/3.0.2/i386-apple-darwin12_gcc/bin/cmake
##
## ../trunk//src/svn_bin/build_visit generated host.cmake
## created: Wed Jan 21 21:06:14 MST 2015
## system: Darwin lautertun.sci.utah.edu 12.5.0 Darwin Kernel Version 12.5.0: Sun Sep 29 13:33:47 PDT 2013; root:xnu-2050.48.12~1/RELEASE_X86_64 x86_64
## by: allen

##SET(CMAKE_BUILD_TYPE Debug CACHE STRING "")

##
## Setup VISITHOME & VISITARCH variables.
##
SET(VISITHOME /Projects/VisIt/Thirdparty/visit)
SET(VISITARCH i386-apple-darwin12_gcc)

## Compiler flags.
##
VISIT_OPTION_DEFAULT(VISIT_C_COMPILER gcc TYPE FILEPATH)
VISIT_OPTION_DEFAULT(VISIT_CXX_COMPILER g++ TYPE FILEPATH)
VISIT_OPTION_DEFAULT(VISIT_C_FLAGS "-fno-common -fexceptions" TYPE STRING)
VISIT_OPTION_DEFAULT(VISIT_CXX_FLAGS "-fno-common -fexceptions" TYPE STRING)

##
## Parallel Build Setup.
##
VISIT_OPTION_DEFAULT(VISIT_PARALLEL ON TYPE BOOL)
## (configured w/ mpi compiler wrapper)
VISIT_OPTION_DEFAULT(VISIT_MPI_COMPILER ${VISITHOME}/mpich/3.0.4/${VISITARCH}/bin/mpicc TYPE FILEPATH)

##
## VisIt Thread Option
##
VISIT_OPTION_DEFAULT(VISIT_THREAD OFF TYPE BOOL)

##
## VisIt paraDIS Option.
##
VISIT_OPTION_DEFAULT(VISIT_PARADIS ON TYPE BOOL)

##
## VisIt build all database plugins
##
VISIT_OPTION_DEFAULT(VISIT_BUILD_ALL_PLUGINS ON TYPE BOOL)

##############################################################
##
## Database reader plugin support libraries
##
## The HDF4, HDF5 and NetCDF libraries must be first so that
## their libdeps are defined for any plugins that need them.
##
## For libraries with LIBDEP settings, order matters.
## Libraries with LIBDEP settings that depend on other
## Library's LIBDEP settings must come after them.
##############################################################
##

##
## R
##
VISIT_OPTION_DEFAULT(VISIT_R_DIR ${VISITHOME}/R/2.13.2/${VISITARCH}/lib/R)

##
## Python
##
VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/2.7.6/${VISITARCH})

##
## Qt
##
VISIT_OPTION_DEFAULT(VISIT_QT_BIN ${VISITHOME}/qt/4.8.6/${VISITARCH}/bin)

##
## VTK
##
SETUP_APP_VERSION(VTK 6.1.0)
VISIT_OPTION_DEFAULT(VISIT_VTK_DIR ${VISITHOME}/vtk-r/${VTK_VERSION}/${VISITARCH})

##
## MPICH
##

# Give VisIt information so it can install MPI into the binary distribution.
VISIT_OPTION_DEFAULT(VISIT_MPICH_DIR ${VISITHOME}/mpich/3.0.4/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_MPICH_INSTALL ON)

# Tell VisIt the parallel compiler so it can deduce parallel flags
VISIT_OPTION_DEFAULT(VISIT_MPI_COMPILER ${VISIT_MPICH_DIR}/bin/mpicc)
VISIT_OPTION_DEFAULT(VISIT_PARALLEL ON)

##
## ADIOS
## (configured w/ mpi compiler wrapper)
##
VISIT_OPTION_DEFAULT(VISIT_ADIOS_DIR ${VISITHOME}/adios/1.7.0/${VISITARCH})

##
## BOOST
##
SETUP_APP_VERSION(BOOST 1_57_0)
VISIT_OPTION_DEFAULT(VISIT_BOOST_DIR ${VISITHOME}/boost/1_57_0/${VISITARCH})

##
## AdvIO
##
#VISIT_OPTION_DEFAULT(VISIT_ADVIO_DIR ${VISITHOME}/AdvIO/1.2/${VISITARCH})

##
## Boxlib
##
VISIT_OPTION_DEFAULT(VISIT_BOXLIB_DIR ${VISITHOME}/boxlib/1.0.7/${VISITARCH})

##
## CCMIO
##
VISIT_OPTION_DEFAULT(VISIT_CCMIO_DIR ${VISITHOME}/ccmio/2.6.1/${VISITARCH})

##
## CFITSIO
##
VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR ${VISITHOME}/cfitsio/3006/${VISITARCH})

##
## SZIP
##
VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR ${VISITHOME}/szip/2.1/${VISITARCH})

##
## ZLIB
##
VISIT_OPTION_DEFAULT(VISIT_ZLIB_DIR ${VISITHOME}/zlib/1.2.7/${VISITARCH})

##
## HDF5
##
VISIT_OPTION_DEFAULT(VISIT_HDF5_DIR ${VISITHOME}/hdf5/1.8.14/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_HDF5_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz ${VISITHOME}/zlib/1.2.7/${VISITARCH}/lib z TYPE STRING)

##
## CGNS
##
VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR ${VISITHOME}/cgns/3.2.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_CGNS_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## FastBit
##
VISIT_OPTION_DEFAULT(VISIT_FASTBIT_DIR ${VISITHOME}/fastbit/1.2.0/${VISITARCH})

##
## GDAL
##
VISIT_OPTION_DEFAULT(VISIT_GDAL_DIR ${VISITHOME}/gdal/1.10.0/${VISITARCH})

##
## H5Part
##
VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR ${VISITHOME}/h5part/1.6.6/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_H5PART_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Ice-T
##
VISIT_OPTION_DEFAULT(VISIT_ICET_DIR ${VISITHOME}/icet/1.0.0/${VISITARCH})

##
## NetCDF
##
VISIT_OPTION_DEFAULT(VISIT_NETCDF_DIR ${VISITHOME}/netcdf/4.1.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_NETCDF_LIBDEP HDF5_LIBRARY_DIR hdf5_hl HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Nektar++
##
SETUP_APP_VERSION(NEKTAR++ 4.1.0)
VISIT_OPTION_DEFAULT(VISIT_NEKTAR++_DIR ${VISITHOME}/nektar++/${NEKTAR++_VERSION}/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_NEKTAR++_LIBDEP ${VISITHOME}/zlib/1.2.7/${VISITARCH}/lib z TYPE STRING)

##
## Silo
##
VISIT_OPTION_DEFAULT(VISIT_SILO_DIR ${VISITHOME}/silo/4.10.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Uintah
##
SETUP_APP_VERSION(UINTAH 1.7.0)
VISIT_OPTION_DEFAULT(VISIT_UINTAH_DIR ${VISITHOME}/uintah/1.6.0/${VISITARCH})

##
## VISUS 
##
#VISIT_OPTION_DEFAULT(VISIT_VISUS_DIR ${VISITHOME}/visus/ad09cb8/${VISITARCH})

##
## Xdmf
##
VISIT_OPTION_DEFAULT(VISIT_XDMF_DIR ${VISITHOME}/Xdmf/2.1.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_XDMF_LIBDEP HDF5_LIBRARY_DIR hdf5  VTK_LIBRARY_DIRS vtklibxml2-${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}  TYPE STRING)

##############################################################

##
## Enable verbose makefiles (show compiler & linker calls)
##
#SET(VISIT_VERBOSE_MAKEFILE TRUE)

##
## Install MPICH when building the package.
##
SET(VISIT_MPICH_INSTALL TRUE)
VISIT_OPTION_DEFAULT(VISIT_MPICH_INSTALL ON TYPE BOOL)

##
## Install thirdpary libraries when building the package.
##
SET(VISIT_INSTALL_THIRD_PARTY TRUE)
VISIT_OPTION_DEFAULT(VISIT_INSTALL_THIRD_PARTY ON TYPE BOOL)

##
## When building the package make a dmg
##
SET(VISIT_CREATE_APPBUNDLE_PACKAGE TRUE)
VISIT_OPTION_DEFAULT(VISIT_CREATE_APPBUNDLE_PACKAGE ON TYPE BOOL)
