# Microsoft Developer Studio Project File - Name="VolumeE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=VolumeE - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VolumeE.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VolumeE.mak" CFG="VolumeE - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VolumeE - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "VolumeE - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VolumeE - Win32 Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I "..\..\visit\plots\Volume" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "ENGINE_PLUGIN_EXPORTS" /D "GENERAL_PLUGIN_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib plotter.lib pipeline_ser.lib avtexceptions.lib visit_vtk.lib vtkCommon.lib vtkFiltering.lib vtkRendering.lib opengl32.lib /nologo /dll /machine:I386 /out:"Release/libEVolume_ser.dll"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\libEVolume_ser.dll ..\..\bin\Release\plots
# End Special Build Tool

!ELSEIF  "$(CFG)" == "VolumeE - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I "..\..\visit\plots\Volume" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "ENGINE_PLUGIN_EXPORTS" /D "GENERAL_PLUGIN_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib plotter.lib pipeline_ser.lib avtexceptions.lib visit_vtk.lib vtkCommon.lib vtkFiltering.lib vtkRendering.lib opengl32.lib /nologo /dll /debug /machine:I386 /out:"Debug/libEVolume_ser.dll" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\libEVolume_ser.dll ..\..\bin\Debug\plots
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "VolumeE - Win32 Release"
# Name "VolumeE - Win32 Debug"
# Begin Source File

SOURCE=..\..\visit\plots\Volume\avtMesa3DTextureVolumeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\avtMesaSplattingVolumeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\avtOpenGL3DTextureVolumeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\avtOpenGLSplattingVolumeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\avtVolumeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\avtVolumePlot.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\avtVolumeRenderer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\BoundingBoxContourer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\VolumeAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\VolumeCommonPluginInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\VolumeEnginePluginInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\plots\Volume\VolumePluginInfo.C
# End Source File
# End Target
# End Project
