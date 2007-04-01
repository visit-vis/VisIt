# Microsoft Developer Studio Project File - Name="plotter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=plotter - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "plotter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "plotter.mak" CFG="plotter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "plotter - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "plotter - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "plotter - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\plotter"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "PLOTTER_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "PLOTTER_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib avtexceptions.lib visit_vtk.lib dbatts.lib pipeline_ser.lib vtkCommon.lib vtkRendering.lib vtkFiltering.lib vtkGraphics.lib vtkHybrid.lib opengl32.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\plotter.lib ..\..\lib\Release\plotter.lib	copy Release\plotter.dll ..\..\bin\Release\plotter.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "plotter - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\plotter"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "PLOTTER_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "PLOTTER_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib avtexceptions.lib visit_vtk.lib dbatts.lib pipeline_ser.lib vtkCommon.lib vtkRendering.lib vtkFiltering.lib vtkGraphics.lib vtkHybrid.lib opengl32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\plotter.lib ..\..\lib\Debug\plotter.lib	copy Debug\plotter.dll ..\..\bin\Debug\plotter.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "plotter - Win32 Release"
# Name "plotter - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtBehavior.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtColorTables.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtCustomRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtDecorationsDrawable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtDecorationsMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtDrawable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtDrawer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtExternallyRenderedImagesActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtGeometryDrawable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtImageDrawable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtImageMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLabelActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLabeledCurveMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLegend.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLevelsLegend.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLevelsMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLightList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLineoutActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtLookupTable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtMesaSurfaceAndWireframeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtOpenGLSurfaceAndWireframeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtPickActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtPlot.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtPointGlyphMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtSurfaceAndWireframeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtTensorGlyphMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtTheater.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtTransparencyActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtUserDefinedMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtVariableLegend.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtVariableMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtVectorGlyphMapper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\avtVolumeVariableLegend.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Plotter\RenderOrder.C
# End Source File
# End Group
# End Target
# End Project
