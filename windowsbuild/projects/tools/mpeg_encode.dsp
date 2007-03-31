# Microsoft Developer Studio Project File - Name="silex" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=silex - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "silex.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "silex.mak" CFG="silex - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "silex - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "silex - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "silex - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /TP /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib qt-mt302.lib silohdf5.lib /nologo /subsystem:console /machine:I386 /out:"../../bin/Release/silex.exe"

!ELSEIF  "$(CFG)" == "silex - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /TP /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib qt-mt302.lib silo.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../bin/Debug/silex.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "silex - Win32 Release"
# Name "silex - Win32 Debug"
# Begin Group "moc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\tools\silex\Explorer_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloArrayView_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloDirTreeView_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloDirView_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloObjectView_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloValueView_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloView_moc.C
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\visit\tools\silex\Explorer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\main.C
# End Source File
# Begin Source File

SOURCE=..\..\resources\silex.rc
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloArrayView.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloDirTreeView.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloDirView.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloFile.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloObjectView.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloValueView.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\silex\SiloView.C
# End Source File
# End Target
# End Project
