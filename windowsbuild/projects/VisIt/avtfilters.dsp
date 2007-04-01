# Microsoft Developer Studio Project File - Name="avtfilters" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=avtfilters - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "avtfilters.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "avtfilters.mak" CFG="avtfilters - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "avtfilters - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "avtfilters - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "avtfilters - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\avtfilters"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AVTFILTERS_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "AVTFILTERS_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib comm.lib utility.lib avtexceptions.lib dbatts.lib avtview.lib avtmath_ser.lib pipeline_ser.lib visit_vtk.lib visit_vtk_light.lib vtkCommon.lib vtkFiltering.lib vtkGraphics.lib vtkRendering.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\avtfilters.lib ..\..\lib\Release\avtfilters.lib	copy Release\avtfilters.dll ..\..\bin\Release\avtfilters.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "avtfilters - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\avtfilters"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AVTFILTERS_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "AVTFILTERS_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib comm.lib utility.lib avtexceptions.lib dbatts.lib avtview.lib avtmath_ser.lib pipeline_ser.lib visit_vtk.lib visit_vtk_light.lib vtkCommon.lib vtkFiltering.lib vtkGraphics.lib vtkRendering.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\avtfilters.lib ..\..\lib\Debug\avtfilters.lib	copy Debug\avtfilters.dll ..\..\bin\Debug\avtfilters.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "avtfilters - Win32 Release"
# Name "avtfilters - Win32 Debug"
# Begin Group "Source files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtCondenseDatasetFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtContourFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtCoordSystemConvert.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtCurrentExtentFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtCurveConstructorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtFeatureEdgesFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtGhostZoneAndFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtGhostZoneFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtImageCommunicator.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtImageCompositer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtMassVoxelExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtPointToGlyphFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtRayCompositer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtRayTracer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtResampleFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtSamplePointCommunicator.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtSamplePointExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtSamplePointToSurfaceFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtShiftCenteringFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtSimilarityTransformFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtSmoothPolyDataFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtSummationFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtTiledImageCompositor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtTransform.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtVertexNormalsFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtWholeImageCompositerNoZ.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtWholeImageCompositerWithZ.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Filters\avtWorldSpaceToImageSpaceTransform.C
# End Source File
# End Group
# End Target
# End Project
