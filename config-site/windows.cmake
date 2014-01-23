# this section should go in its own "prepare windows type cmake file"
IF (MSVC_VERSION)
  SET(ERRMSG "You have chosen a compiler version not currently supported.  You will need to build all dependent 3rd party libraries with this compiler, and provide the correct locations for them.")
  MESSAGE(STATUS "MSVC_VERSION=${MSVC_VERSION}")
  SET(PYTHONVER "2.6")
  SET(JPEGVER "6b")
  SET(ZLIBVER "1.2.7")
  SET(BOXLIBVER "0.1.8")
  SET(CGNSVER "3.1.3")
  SET(HDF4VER "4.2.6")
  SET(PYSIDEVER "1.1.1")
  IF (NOT MSVC_VERSION LESS 1700)
      SET(VISIT_MSVC_VERSION "MSVC2012")
      SET(PYTHONVER "2.7.5")
      SET(JPEGVER "9")
      SET(ZLIBVER "1.2.8")
      SET(BOXLIBVER "2011.04.28")
      SET(CGNSVER "3.1.4")
      SET(HDF4VER "4.2.9")
      SET(PYSIDEVER "1.2.1")
  ELSEIF (NOT MSVC_VERSION LESS 1600)
      SET(VISIT_MSVC_VERSION "MSVC2010")
      SET(PYTHONVER "2.7.5")
      SET(JPEGVER "8c")
      SET(PYSIDEVER "1.2.1")
  ELSEIF (NOT MSVC_VERSION LESS 1500)
      SET(VISIT_MSVC_VERSION "MSVC90")
  ELSEIF (NOT MSVC_VERSION LESS 1400)
      MESSAGE(SEND_ERROR "${ERRMSG}")
  ELSE (NOT MSVC_VERSION LESS 1600)
      MESSAGE(SEND_ERROR "${ERRMSG}")
  ENDIF (NOT MSVC_VERSION LESS 1700)

ELSE (MSVC_VERSION)
  MESSAGE(SEND_ERROR "${ERRMSG}")
ENDIF(MSVC_VERSION)

# this can be left in generic_windows.cmake, but allow user to
# have their own config-site file

IF (CMAKE_CL_64)
    SET(VISIT_MSVC_VERSION "${VISIT_MSVC_VERSION}-x64")
ENDIF (CMAKE_CL_64)
MESSAGE(STATUS "Prebuilt library directory name: ${VISIT_MSVC_VERSION}")

SET(VISIT_WINDOWS_DIR ${VISIT_SOURCE_DIR}/../windowsbuild)
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
## VTK
##
VISIT_OPTION_DEFAULT(VISIT_VTK_DIR  ${VISITHOME}/vtk/${VTK_VERSION})

##
## QT
##
VISIT_OPTION_DEFAULT(VISIT_QT_BIN     ${VISITHOME}/Qt/4.8.3/lib)
VISIT_OPTION_DEFAULT(QT_DIR           ${VISITHOME}/Qt/4.8.3)
VISIT_OPTION_DEFAULT(QT_QMAKE_EXECUTABLE ${VISIT_QT_BIN}/qmake.exe TYPE FILEPATH)

##
## PYTHON
##
VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/${PYTHONVER})

##
## PYSIDE
##
VISIT_OPTION_DEFAULT(VISIT_PYSIDE_DIR ${VISITHOME}/PySide/${PYSIDEVER})

##############################################################
##
## Some misc libraries Database readers may depend upon
##
##############################################################

##
## JPEG
##
## jpeg lib names changed, disable it for MSVC 2012 for now
IF (MSVC_VERSION LESS 1700)
VISIT_OPTION_DEFAULT(VISIT_JPEG_DIR     ${VISITHOME}/jpeg/${JPEGVER})
ENDIF()

##
## SZIP
##
VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR     ${VISITHOME}/szip/2.0)

##
## ZLIB
##
VISIT_OPTION_DEFAULT(VISIT_ZLIB_DIR     ${VISITHOME}/zlib/${ZLIBVER})

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

## hdf4 lib names changed, disable it for MSVC 2012 for now
IF (MSVC_VERSION LESS 1700)
VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR     ${VISITHOME}/hdf4/${HDF4VER})
VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP  
    JPEG_LIBRARY_DIR libjpeg 
    SZIP_LIBRARY_DIR szlibdll 
    ZLIB_LIBRARY_DIR zlib1
    TYPE STRING
)
ENDIF()

##
## HDF5
##
VISIT_OPTION_DEFAULT(VISIT_HDF5_DIR     ${VISITHOME}/hdf5/1.8.7)
VISIT_OPTION_DEFAULT(VISIT_HDF5_LIBDEP  
    SZIP_LIBRARY_DIR szlibdll 
    ZLIB_LIBRARY_DIR zlib1
    TYPE STRING
)

##
## NETCDF
##
VISIT_OPTION_DEFAULT(VISIT_NETCDF_DIR   ${VISITHOME}/netcdf/4.1.1)
VISIT_OPTION_DEFAULT(VISIT_NETCDF_LIBDEP 
    HDF5_LIBRARY_DIR hdf5dll ${VISIT_HDF5_LIBDEP}
    TYPE STRING
)

##
## BOXLIB
##
VISIT_OPTION_DEFAULT(VISIT_BOXLIB_DIR ${VISITHOME}/BoxLib/${BOXLIBVER})

##
## CCMIO
##
VISIT_OPTION_DEFAULT(VISIT_CCMIO_DIR    ${VISITHOME}/ccmio/2.6.1)

##
## CFITSIO
##
VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR  ${VISITHOME}/cfitsio/3006)

##
## CGNS
##
VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR     ${VISITHOME}/cgns/${CGNSVER})
VISIT_OPTION_DEFAULT(VISIT_CGNS_LIBDEP 
    HDF5_LIBRARY_DIR hdf5dll ${VISIT_HDF5_LIBDEP}
    TYPE STRING
)

##
## GDAL
##
VISIT_OPTION_DEFAULT(VISIT_GDAL_DIR     ${VISITHOME}/gdal/1.10.0)

##
## H5PART
##
VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR   ${VISITHOME}/h5part/1.6.5)
VISIT_OPTION_DEFAULT(VISIT_H5PART_LIBDEP 
    HDF5_LIBRARY_DIR hdf5dll ${VISIT_HDF5_LIBDEP}
    TYPE STRING
)


##
## MILI
##
VISIT_OPTION_DEFAULT(VISIT_MILI_DIR     ${VISITHOME}/Mili/13.1.1-patch)

##
## SILO
##
VISIT_OPTION_DEFAULT(VISIT_SILO_DIR     ${VISITHOME}/silo/4.9.1)

VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP  
    HDF5_LIBRARY_DIR hdf5dll ${VISIT_HDF5_LIBDEP}
    TYPE STRING
)

##
## XDMF
##
VISIT_OPTION_DEFAULT(VISIT_XDMF_DIR ${VISITHOME}/Xdmf/2.1.1)
VISIT_OPTION_DEFAULT(VISIT_XDMF_LIBDEP 
    HDF5_LIBRARY_DIR hdf5dll ${VISIT_HDF5_LIBDEP}
    VTK_LIBRARY_DIRS vtklibxml2-${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}
    TYPE STRING
)
