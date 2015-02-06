# this section should go in its own "prepare windows type cmake file"
IF (MSVC_VERSION)
  SET(ERRMSG "You have chosen a compiler version not currently supported.  You will need to build all dependent 3rd party libraries with this compiler, and provide the correct locations for them.")
  MESSAGE(STATUS "MSVC_VERSION=${MSVC_VERSION}")
  IF (MSVC12)
      SET(VISIT_MSVC_VERSION "MSVC2013")
  ELSEIF (MSVC11)
      SET(VISIT_MSVC_VERSION "MSVC2012")
      VISIT_OPTION_DEFAULT(VISIT_ENABLE_XDB ON)
  ELSEIF (MSVC10)
      SET(VISIT_MSVC_VERSION "MSVC2010")
  ELSE()
      MESSAGE(SEND_ERROR "${ERRMSG}")
  ENDIF()
ELSE (MSVC_VERSION)
  MESSAGE(SEND_ERROR "${ERRMSG}")
ENDIF(MSVC_VERSION)

# this can be left in generic_windows.cmake, but allow user to
# have their own config-site file

IF (CMAKE_CL_64)
    SET(VISIT_MSVC_VERSION "${VISIT_MSVC_VERSION}-x64")
ENDIF (CMAKE_CL_64)
MESSAGE(STATUS "Prebuilt library directory name: ${VISIT_MSVC_VERSION}")

IF(NOT DEFINED VISIT_WINDOWS_DIR)
    IF(EXISTS ${VISIT_SOURCE_DIR}/../windowsbuild)
        SET(VISIT_WINDOWS_DIR ${VISIT_SOURCE_DIR}/../windowsbuild)
    ELSE()
        message(FATAL_ERROR "Please set VISIT_WINDOWS_DIR to location of 'windowsbuild' files")
    ENDIF()
ENDIF()
get_filename_component(VISIT_WINDOWS_DIR ${VISIT_WINDOWS_DIR} ABSOLUTE)
SET(VISITHOME ${VISIT_WINDOWS_DIR}/${VISIT_MSVC_VERSION})


# Create the NSIS installer package (override default from root CMakeLists.txt
OPTION(VISIT_MAKE_NSIS_INSTALLER "Create an installer package using NSIS." ON)

##############################################################
##
## Required libraries
##
##############################################################

##
## BOOST
##
VISIT_OPTION_DEFAULT(VISIT_BOOST_DIR ${VISITHOME}/boost_minimal_headers/1.57.0)


##
## VTK
##
IF(VISIT_QT5)
  VISIT_OPTION_DEFAULT(VISIT_VTK_DIR  ${VISITHOME}/vtk-qt5/${VTK_VERSION})
ELSE()
  VISIT_OPTION_DEFAULT(VISIT_VTK_DIR  ${VISITHOME}/vtk/${VTK_VERSION})
ENDIF()

##
## QT
##
if (VISIT_QT5)
  VISIT_OPTION_DEFAULT(VISIT_QT_DIR     ${VISITHOME}/Qt/5.2.1)
else()
  if(MSVC12)
      SET(VISIT_QT_VERSION "4.8.6")
  else()
      SET(VISIT_QT_VERSION "4.8.3")
  endif()
  VISIT_OPTION_DEFAULT(VISIT_QT_BIN     ${VISITHOME}/Qt/${VISIT_QT_VERSION}/lib)
  VISIT_OPTION_DEFAULT(QT_DIR           ${VISITHOME}/Qt/${VISIT_QT_VERSION})
  VISIT_OPTION_DEFAULT(QT_QMAKE_EXECUTABLE ${VISIT_QT_BIN}/qmake.exe TYPE FILEPATH)
endif()

##
## PYTHON
##
if(MSVC10)
  VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/2.7.5)
else()
  VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/2.7.9)
endif()

##
## PYSIDE
##
VISIT_OPTION_DEFAULT(VISIT_PYSIDE_DIR ${VISITHOME}/PySide/1.2.2)

##############################################################
##
## Some misc libraries Database readers may depend upon
##
##############################################################

##
## JPEG
##
IF(MSVC12)
  IF (CMAKE_CL_64)
     set(JPEG_LIBNAME_PREFIX_LIB false CACHE INTERNAL "Is 'lib' prefixed to jpeg libname")
    VISIT_OPTION_DEFAULT(VISIT_JPEG_DIR     ${VISITHOME}/jpeg/9a)
    SET(JPEGVER "9a")
  ENDIF()
#ELSEIF(MSVC11)
#  IF (CMAKE_CL_64)
#     set(JPEG_LIBNAME_PREFIX_LIB false CACHE INTERNAL "Is 'lib' prefixed to jpeg libname")
#    VISIT_OPTION_DEFAULT(VISIT_JPEG_DIR     ${VISITHOME}/jpeg/9)
#  ENDIF()
ELSEIF(MSVC10)
  set(JPEG_LIBNAME_PREFIX_LIB true CACHE INTERNAL "Is 'lib' prefixed to jpeg libname")
  VISIT_OPTION_DEFAULT(VISIT_JPEG_DIR     ${VISITHOME}/jpeg/8c)
      SET(JPEGVER "8c")
ENDIF()

##
## SZIP
##
IF(MSVC11 OR MSVC12)
  SET(SZIP_LIB_NAME "szip")
  VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR     ${VISITHOME}/szip/2.1)
ELSE()
  SET(SZIP_LIB_NAME "szlibdll")
  VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR     ${VISITHOME}/szip/2.0)
ENDIF()

##
## ZLIB
##
IF(MSVC11 OR MSVC12)
  SET(ZLIB_LIB_NAME "zlib")
  VISIT_OPTION_DEFAULT(VISIT_ZLIB_DIR     ${VISITHOME}/zlib/1.2.8)
ELSE()
  SET(ZLIB_LIB_NAME "zlib1")
  VISIT_OPTION_DEFAULT(VISIT_ZLIB_DIR     ${VISITHOME}/zlib/1.2.7)
ENDIF()

##############################################################
##
## Database reader plugin support libraries
##
## For libraries with LIBDEP settings, order matters.
## Libraries with LIBDEP settings that depend on other
## Library's LIBDEP settings must come after them.
##############################################################

##
## HDF4
##
IF(MSVC12)
  set(HDF4_LIBNAMES_AFFIX_DLL false CACHE INTERNAL "Is 'dll' appended to hdf4 libnames")
  VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR     ${VISITHOME}/hdf4/4.2.10)
  VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP  
      JPEG_LIBRARY_DIR JPEG_LIB
      SZIP_LIBRARY_DIR SZIP_LIB
      ZLIB_LIBRARY_DIR ZLIB_LIBRARY
      TYPE STRING
  )
ELSEIF(MSVC11)
  set(HDF4_LIBNAMES_AFFIX_DLL false CACHE INTERNAL "Is 'dll' appended to hdf4 libnames")
  VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR     ${VISITHOME}/hdf4/4.2.10)
  VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP  
      VTK_LIBRARY_DIRS vtkjpeg-${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}
      SZIP_LIBRARY_DIR SZIP_LIB 
      ZLIB_LIBRARY_DIR ZLIB_LIBRARY
      TYPE STRING
  )
ELSE()
  set(HDF4_LIBNAMES_AFFIX_DLL true CACHE INTERNAL "Is 'dll' appended to hdf4 libnames")
  VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR     ${VISITHOME}/hdf4/4.2.6)
  VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP  
    JPEG_LIBRARY_DIR JPEG_LIB 
    SZIP_LIBRARY_DIR SZIP_LIB 
    ZLIB_LIBRARY_DIR ZLIB_LIBRARY
    TYPE STRING
  )
ENDIF()

##
## HDF5
##
if (MSVC12)
  set(VISIT_HDF5_VERSION "1.8.13")
  VISIT_OPTION_DEFAULT(HDF5_LIBNAMES_AFFIX_DLL OFF TYPE BOOL)
else()
  set(VISIT_HDF5_VERSION "1.8.7")
endif()
VISIT_OPTION_DEFAULT(VISIT_HDF5_DIR     ${VISITHOME}/hdf5/${VISIT_HDF5_VERSION})
VISIT_OPTION_DEFAULT(VISIT_HDF5_LIBDEP  
    SZIP_LIBRARY_DIR SZIP_LIB 
    ZLIB_LIBRARY_DIR ZLIB_LIBRARY
    TYPE STRING
)

##
## NETCDF
##
VISIT_OPTION_DEFAULT(VISIT_NETCDF_DIR   ${VISITHOME}/netcdf/4.1.1)
VISIT_OPTION_DEFAULT(VISIT_NETCDF_LIBDEP 
    HDF5_LIBRARY_DIR HDF5_LIB ${VISIT_HDF5_LIBDEP}
    TYPE STRING
)

##
## BOXLIB
##
IF(MSVC11 OR MSVC12)
  VISIT_OPTION_DEFAULT(VISIT_BOXLIB_DIR ${VISITHOME}/BoxLib/2011.04.28)
ELSE()
  VISIT_OPTION_DEFAULT(VISIT_BOXLIB_DIR ${VISITHOME}/BoxLib/0.1.8)
ENDIF()

##
## CCMIO
##
VISIT_OPTION_DEFAULT(VISIT_CCMIO_DIR    ${VISITHOME}/ccmio/2.6.1)

##
## CFITSIO
##
if(MSVC12)
  VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR  ${VISITHOME}/cfitsio/3370)
else()
  VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR  ${VISITHOME}/cfitsio/3006)
endif()

##
## CGNS
##
IF(MSVC11 OR MSVC12)
  VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR     ${VISITHOME}/cgns/3.2.1)
ELSE()
  VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR     ${VISITHOME}/cgns/3.1.3)
ENDIF()
VISIT_OPTION_DEFAULT(VISIT_CGNS_LIBDEP 
    HDF5_LIBRARY_DIR HDF5_LIB ${VISIT_HDF5_LIBDEP}
    TYPE STRING
)

##
## GDAL
##
if(MSVC12)
    SET(VISIT_GDAL_VERSION "1.11.1")
else()
    SET(VISIT_GDAL_VERSION "1.10.0")
endif()
VISIT_OPTION_DEFAULT(VISIT_GDAL_DIR     ${VISITHOME}/gdal/${VISIT_GDAL_VERSION})

##
## H5PART
##
if(MSVC11 OR MSVC12)
  VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR   ${VISITHOME}/h5part/1.6.6)
else()
  VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR   ${VISITHOME}/h5part/1.6.5)
endif()
VISIT_OPTION_DEFAULT(VISIT_H5PART_LIBDEP 
    HDF5_LIBRARY_DIR HDF5_LIB ${VISIT_HDF5_LIBDEP}
    TYPE STRING
)

##
## MFEM
##
VISIT_OPTION_DEFAULT(VISIT_MFEM_DIR     ${VISITHOME}/mfem/3.0)

##
## MILI
##
if(NOT MSVC12)
IF(CMAKE_CL_64 OR NOT MSVC11)
VISIT_OPTION_DEFAULT(VISIT_MILI_DIR     ${VISITHOME}/Mili/13.1.1-patch)
ENDIF()
endif()

##
## SILO
##
if(MSVC12)
  VISIT_OPTION_DEFAULT(VISIT_SILO_DIR     ${VISITHOME}/silo/4.10.2)

  VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP  
      HDF5_LIBRARY_DIR HDF5_LIB ${VISIT_HDF5_LIBDEP}
      TYPE STRING
  )
elseif(MSVC11)
  VISIT_OPTION_DEFAULT(VISIT_SILO_DIR     ${VISITHOME}/silo/4.10.1)

  VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP  
      HDF5_LIBRARY_DIR HDF5_LIB ${VISIT_HDF5_LIBDEP}
      TYPE STRING
  )
endif()

##
## XDMF
##
if(VISIT_QT5)
  VISIT_OPTION_DEFAULT(VISIT_XDMF_DIR ${VISITHOME}/Xdmf-vtk-qt5/2.1.1)
else()
  VISIT_OPTION_DEFAULT(VISIT_XDMF_DIR ${VISITHOME}/Xdmf/2.1.1)
endif()
VISIT_OPTION_DEFAULT(VISIT_XDMF_LIBDEP 
    HDF5_LIBRARY_DIR HDF5_LIB ${VISIT_HDF5_LIBDEP}
    VTK_LIBRARY_DIRS vtklibxml2-${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}
    TYPE STRING
)
