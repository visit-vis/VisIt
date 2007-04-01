# Microsoft Developer Studio Project File - Name="queries" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=queries - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "queries.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "queries.mak" CFG="queries - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "queries - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "queries - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "queries - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "QUERIES_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "QUERY_EXPORTS" /D "USING_MSVC6" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib dbatts.lib pipeline_ser.lib avtexceptions.lib avtmath_ser.lib expression.lib avtfilters.lib visit_vtk.lib visit_vtk_light.lib vtkCommon.lib vtkGraphics.lib vtkFiltering.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\queries.lib ..\..\lib\Release\queries.lib	copy Release\queries.dll ..\..\bin\Release\queries.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "queries - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "QUERIES_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "QUERY_EXPORTS" /D "USING_MSVC6" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib dbatts.lib pipeline_ser.lib avtexceptions.lib avtmath_ser.lib expression.lib avtfilters.lib visit_vtk.lib visit_vtk_light.lib vtkCommon.lib vtkGraphics.lib vtkFiltering.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\queries.lib ..\..\lib\Debug\queries.lib	copy Debug\queries.dll ..\..\bin\Debug\queries.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "queries - Win32 Release"
# Name "queries - Win32 Debug"
# Begin Group "Abstract"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Queries\Abstract\avtCurveComparisonQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Abstract\avtCurveQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Abstract\avtDataObjectQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Abstract\avtDatasetQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Abstract\avtGeneralQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Abstract\avtMultipleInputQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Abstract\avtTwoPassDatasetQuery.C
# End Source File
# End Group
# Begin Group "Queries"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtActualDataMinMaxQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtActualDataNumNodesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtActualDataNumZonesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtAreaBetweenCurvesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtCompactnessQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtCycleQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtEulerianQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtIntegrateQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtL2NormBetweenCurvesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtL2NormQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtMinMaxQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtNodeCoordsQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtNumNodesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtNumZonesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtOriginalDataMinMaxQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtOriginalDataNumNodesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtOriginalDataNumZonesQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtSummationQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtTimeQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtTotalRevolvedSurfaceAreaQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtTotalRevolvedVolumeQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtTotalSurfaceAreaQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtTotalVolumeQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtVariableQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtVariableSummationQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtWeightedVariableSummationQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Queries\avtZoneCenterQuery.C
# End Source File
# End Group
# Begin Group "Misc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Queries\Misc\avtQueryFactory.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Misc\avtQueryOverTimeFilter.C
# End Source File
# End Group
# Begin Group "Pick"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtActualCoordsQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtActualNodeCoordsQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtActualZoneCoordsQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtCurvePickQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtLocateCellQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtLocateNodeQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtLocateQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtNodePickQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtPickByNodeQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtPickByZoneQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtPickQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Queries\Pick\avtZonePickQuery.C
# End Source File
# End Group
# End Target
# End Project
