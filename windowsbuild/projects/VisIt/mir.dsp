# Microsoft Developer Studio Project File - Name="mir" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=mir - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mir.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mir.mak" CFG="mir - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mir - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mir - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mir - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MIR_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MIR_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib avtexceptions.lib pipeline_ser.lib vtkCommon.lib visit_vtk.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\mir.dll ..\..\bin\Release\mir.dll	copy Release\mir.lib ..\..\lib\Release\mir.lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mir - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MIR_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MIR_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib avtexceptions.lib pipeline_ser.lib vtkCommon.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\mir.dll ..\..\bin\Debug\mir.dll	copy Debug\mir.lib ..\..\lib\Debug\mir.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "mir - Win32 Release"
# Name "mir - Win32 Debug"
# Begin Group "Base"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\MIR\Base\MIR.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Base\MIRConnectivity.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Base\MIROptions.C
# End Source File
# End Group
# Begin Group "Tet"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\Edge.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\Face.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\mat3d_tet.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\MaterialTetrahedron.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\MaterialTriangle.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\QuadraticHash.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\TetMIR.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\Tetrahedralizer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Tet\Triangulator.C
# End Source File
# End Group
# Begin Group "Zoo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\MIR\Zoo\BitUtils.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Zoo\CellReconstructor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Zoo\ResampledMat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\MIR\Zoo\ZooMIR.C
# End Source File
# End Group
# End Target
# End Project
