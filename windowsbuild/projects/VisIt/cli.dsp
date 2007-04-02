# Microsoft Developer Studio Project File - Name="cli" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=cli - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cli.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cli.mak" CFG="cli - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cli - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "cli - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cli - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\cli"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "USING_MSVC6" /YX /FD /TP /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comm.lib state.lib misc.lib plugin.lib dbatts.lib viewerproxy.lib viewerrpc.lib python21.lib /nologo /subsystem:console /machine:I386 /out:"../../bin/Release/cli.exe"

!ELSEIF  "$(CFG)" == "cli - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\cli"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "USING_MSVC6" /U "_DEBUG" /YX /FD /GZ /TP /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comm.lib state.lib misc.lib plugin.lib dbatts.lib viewerproxy.lib viewerrpc.lib python21.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../bin/Debug/cli.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "cli - Win32 Release"
# Name "cli - Win32 Debug"
# Begin Source File

SOURCE=..\..\visit\visitpy\cli.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\Logging.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyAnnotationAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyDatabaseCorrelation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyExportDBAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyGlobalAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyGlobalLineoutAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyHostProfile.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyImageObject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyInteractorAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyKeyframeAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyLightAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyLineObject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyMaterialAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyMeshManagementAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyMethodDoc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyPickAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyPrinterAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyProcessAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyQueryOverTimeAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyRenderingAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PySaveWindowAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PySILRestriction.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyText2DObject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyTimeSliderObject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyView2DAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyView3DAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyViewAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyViewCurveAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\PyWindowInformation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visitpy\visitmodule.C
# End Source File
# Begin Source File

SOURCE=..\..\resources\visitresources.rc
# End Source File
# End Target
# End Project
