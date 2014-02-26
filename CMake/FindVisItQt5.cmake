# Configure for Qt5..
IF(NOT DEFINED VISIT_QT_DIR)
    MESSAGE(FATAL_ERROR "Qt5 installation directory not specified")
ENDIF()

SET(QT_MOC_EXECUTABLE ${VISIT_QT_DIR}/bin/qmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(QT5_INCLUDE_DIRS "")
set(QT5_LIBRARIES "")

macro (add_module module)
# Configure new path to 

MESSAGE(STATUS ${VISIT_QT_DIR}/lib/cmake/${module})
SET(${module}_DIR ${VISIT_QT_DIR}/lib/cmake/${module}/ )
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${VISIT_QT_DIR}/lib/cmake/${module}/" )

find_package(${module} REQUIRED)

include_directories(${${module}_INCLUDE_DIRS})

add_definitions(${${module}_DEFINITIONS})

#set(CMAKE_CXX_FLAGS "${${module}_EXECUTABLE_COMPILE_FLAGS}")

#set(QT5_INCLUDE_DIRS "${QT5_INCLUDE_DIRS} ${${module}_INCLUDES}")
set(QT5_LIBRARIES "${QT5_LIBRARIES} ${${module}_LIBRARIES}")
endmacro (add_module module)


SET(Qt5_DIR ${VISIT_QT_DIR}/lib/cmake/Qt5)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${VISIT_QT_DIR}/lib/cmake/Qt5" )

find_package (Qt5 REQUIRED Core Gui Widgets OpenGL Network PrintSupport Xml UiTools)

add_module (Qt5Core)
add_module (Qt5Gui)
add_module (Qt5Widgets)
add_module (Qt5OpenGL)
add_module (Qt5Network)
#add_module (Qt5WebSockets)
add_module (Qt5PrintSupport)
add_module (Qt5Xml)
add_module (Qt5UiTools)

set(QT_QTUITOOLS_LIBRARY ${Qt5UiTools_LIBRARIES})
set(QT_QTOPENGL_LIBRARY ${Qt5OpenGL_LIBRARIES})
set(QT_QTGUI_LIBRARY ${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5PrintSupport_LIBRARIES})
set(QT_QTNETWORK_LIBRARY ${Qt5Network_LIBRARIES})
set(QT_QTXML_LIBRARY ${Qt5Xml_LIBRARIES})
set(QT_CORE_LIBRARY ${Qt5Core_LIBRARIES})
#MESSAGE(FATAL_ERROR "QT5_INCLUDE ${Qt5_INCLUDES} ${Qt5_LIBRARIES} ${Qt5_FIND_COMPONENTS}")


