# Microsoft Developer Studio Project File - Name="remotecommand" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=remotecommand - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "remotecommand.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "remotecommand.mak" CFG="remotecommand - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "remotecommand - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "remotecommand - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "remotecommand - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "REMOTECOMMAND_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I "..\..\visit\tools\qtssh\remotecommand" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "REMOTE_COMMAND_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib ws2_32.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\remotecommand.dll ..\..\bin\Release\remotecommand.dll	copy Release\remotecommand.lib ..\..\lib\Release\remotecommand.lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "remotecommand - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "REMOTECOMMAND_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I "..\..\visit\tools\qtssh\remotecommand" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "REMOTE_COMMAND_EXPORTS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib ws2_32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\remotecommand.lib ..\..\lib\Debug\remotecommand.lib	copy Debug\remotecommand.dll ..\..\bin\Debug\remotecommand.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "remotecommand - Win32 Release"
# Name "remotecommand - Win32 Debug"
# Begin Group "ssh"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSH.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHBLOWF.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHBN.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHCRC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHDES.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHDH.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHDSS.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHMD5.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHPRIME.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHPUBK.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHRAND.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHRSA.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHRSAG.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHSHA.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SSHZLIB.C
# End Source File
# End Group
# Begin Group "puttysrc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\BE_SSH.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\NOISE.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\PAGEANTC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\SETTINGS.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\TREE234.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\VERSION.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\WINNET.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\WINSTORE.C
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\visit\tools\qtssh\remotecommand\RemoteCommand.c
# End Source File
# End Target
# End Project
