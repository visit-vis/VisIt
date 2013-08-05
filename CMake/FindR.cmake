#*****************************************************************************
#
# Copyright (c) 2000 - 2012, Lawrence Livermore National Security, LLC
# Produced at the Lawrence Livermore National Laboratory
# LLNL-CODE-442911
# All rights reserved.
#
# This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
# full copyright notice is contained in the file COPYRIGHT located at the root
# of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
#
# Redistribution  and  use  in  source  and  binary  forms,  with  or  without
# modification, are permitted provided that the following conditions are met:
#
#  - Redistributions of  source code must  retain the above  copyright notice,
#    this list of conditions and the disclaimer below.
#  - Redistributions in binary form must reproduce the above copyright notice,
#    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
#    documentation and/or other materials provided with the distribution.
#  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
#    be used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
# ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
# LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
# DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
# SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
# CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
# LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
# OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
# DAMAGE.
#
# Modifications:
#
#****************************************************************************/

# Use the R_DIR hint from the config-site .cmake file

INCLUDE(${VISIT_SOURCE_DIR}/CMake/SetUpThirdParty.cmake)

MACRO(INSTALL_VIRTUALENV_R VISIT_R_INSTALL INSTALL_DIR INSTALL_MODE)

    #now that virtual env is installed use pip to install
    #SET(ENV{PATH} "${VISIT_R_INSTALL}/bin:$ENV{PATH}")
    SET(PIP_COMMAND ${INSTALL_DIR}/bin/pip)

    #install rpy2 if R is enabled

    MESSAGE(STATUS "Installing rpy2 using ${PIP_COMMAND}")

    IF(${INSTALL_MODE} STREQUAL "1")
        MESSAGE(STATUS "$ENV{PATH} EXECUTE_PROCESS(COMMAND ${PIP_COMMAND} install rpy2 --global-option=build_ext --global-option=--undef=HAS_READLINE --global-option=--r-home=${VISIT_R_INSTALL})"
        )
        INSTALL(CODE
        "
         SET(TMPPATH \$ENV{PATH})
         SET(ENV{PATH} \"${VISIT_R_INSTALL}/bin:\$ENV{PATH}\")
         EXECUTE_PROCESS(COMMAND ${PIP_COMMAND} install rpy2 --global-option=build_ext --global-option=--undef=HAS_READLINE --global-option=--r-home=${VISIT_R_INSTALL})
         SET(\$ENV{PATH} \${TMPPATH})
        "
        )

    ELSE(${INSTALL_MODE} STREQUAL "1")
        SET(TMPPATH $ENV{PATH})
        SET(ENV{PATH} "${VISIT_R_INSTALL}/bin:$ENV{PATH}")
        EXECUTE_PROCESS(COMMAND ${PIP_COMMAND} install rpy2 --global-option=build_ext --global-option=--undef=HAS_READLINE --global-option=--r-home=${VISIT_R_INSTALL})
        SET(ENV{PATH} ${TMPPATH})
    ENDIF(${INSTALL_MODE} STREQUAL "1")
ENDMACRO(INSTALL_VIRTUALENV_R INSTALL_DIR INSTALL_MODE)


IF (WIN32)
  # TODO, Windows R Support.
  #SET_UP_THIRD_PARTY(R "lib/${VISIT_MSVC_VERSION};lib" include R Rblase Rlapack)
ELSE (WIN32)
  SET_UP_THIRD_PARTY(R lib include R Rblas Rlapack)
  MESSAGE(STATUS "Installing R directory ${VISIT_INSTALLED_VERSION_LIB}")

  FILE(COPY ${VISIT_R_DIR}/
        DESTINATION ${CMAKE_BINARY_DIR}/lib/r_support/R #mac has Resources dir
    FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                     GROUP_READ GROUP_WRITE GROUP_EXECUTE
                     WORLD_READ             WORLD_EXECUTE
    DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE 
                          GROUP_READ GROUP_WRITE GROUP_EXECUTE 
                          WORLD_READ             WORLD_EXECUTE)

  EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/lib/r_support/R/bin/R ${CMAKE_BINARY_DIR}/bin/R)

  IF(VISIT_VIRTUALENV_DIR)
    INSTALL_VIRTUALENV_R(${CMAKE_BINARY_DIR}/lib/r_support/R ${CMAKE_BINARY_DIR} "0")
  ELSE(VISIT_VIRTUALENV_DIR)
    MESSAGE(STATUS "R is installed without Rpy2 support, Operators using rpy2 functionality will not work completely.")
  ENDIF(VISIT_VIRTUALENV_DIR)

    #copy to dev branch..
    IF(VISIT_R_SKIP_INSTALL)
      MESSAGE("Skipping installation of R libraries")
    ELSE(VISIT_R_SKIP_INSTALL)

        INSTALL(DIRECTORY ${VISIT_R_DIR}/
                  DESTINATION ${VISIT_INSTALLED_VERSION_LIB}/r_support/R
            FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                             GROUP_READ GROUP_WRITE GROUP_EXECUTE
                             WORLD_READ             WORLD_EXECUTE
            DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE 
                                  GROUP_READ GROUP_WRITE GROUP_EXECUTE 
                                  WORLD_READ             WORLD_EXECUTE
            CONFIGURATIONS "";None;Debug;Release;RelWithDebInfo;MinSizeRel)

        INSTALL_VIRTUALENV_R(${CMAKE_INSTALL_PREFIX}/${VISIT_INSTALLED_VERSION_LIB}/r_support/R ${CMAKE_INSTALL_PREFIX}/${VISIT_INSTALLED_VERSION} "1")

    ENDIF(VISIT_R_SKIP_INSTALL)
ENDIF (WIN32)

SET(HAVE_LIB_R 1)
