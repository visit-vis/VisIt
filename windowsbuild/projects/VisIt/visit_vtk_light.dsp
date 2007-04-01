# Microsoft Developer Studio Project File - Name="visit_vtk_light" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=visit_vtk_light - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "visit_vtk_light.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "visit_vtk_light.mak" CFG="visit_vtk_light - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "visit_vtk_light - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "visit_vtk_light - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "visit_vtk_light - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "visit_vtk_light_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VISIT_VTK_LIGHT_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib vtkCommon.lib vtkFiltering.lib vtkIO.lib vtkGraphics.lib vtkHybrid.lib vtkRendering.lib misc.lib avtexceptions.lib vtktiff.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\visit_vtk_light.lib ..\..\lib\Release\visit_vtk_light.lib	copy Release\visit_vtk_light.dll ..\..\bin\Release\visit_vtk_light.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "visit_vtk_light - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "visit_vtk_light_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VISIT_VTK_LIGHT_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib vtkCommon.lib vtkFiltering.lib vtkIO.lib vtkGraphics.lib vtkHybrid.lib vtkRendering.lib misc.lib avtexceptions.lib vtktiff.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\visit_vtk_light.dll ..\..\bin\Debug\visit_vtk_light.dll	copy Debug\visit_vtk_light.lib ..\..\lib\Debug\visit_vtk_light.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "visit_vtk_light - Win32 Release"
# Name "visit_vtk_light - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\ClipCasesHex.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\ClipCasesPyr.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\ClipCasesQua.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\ClipCasesTet.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\ClipCasesTri.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\ClipCasesWdg.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\InitVTKNoGraphics.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\vtkDataSetFromVolume.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\vtkDebugStream.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\vtkTriangulationTables.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\vtkUnstructuredGridBoundaryFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\lightweight\vtkVisItUtility.C
# End Source File
# End Group
# End Target
# End Project
