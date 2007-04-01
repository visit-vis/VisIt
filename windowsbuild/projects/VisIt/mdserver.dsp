# Microsoft Developer Studio Project File - Name="mdserver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mdserver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mdserver.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mdserver.mak" CFG="mdserver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mdserver - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mdserver - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mdserver - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\mdserver"
# PROP Intermediate_Dir "Release\mdserver"
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
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib comm.lib misc.lib mdsrpc.lib dbatts.lib database_ser.lib avtexceptions.lib plugin.lib utility.lib /nologo /subsystem:console /machine:I386 /out:"../../bin/Release/mdserver.exe"

!ELSEIF  "$(CFG)" == "mdserver - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug\mdserver"
# PROP Intermediate_Dir "Debug\mdserver"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "USING_MSVC6" /YX /FD /GZ /TP /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib comm.lib misc.lib mdsrpc.lib dbatts.lib database_ser.lib avtexceptions.lib plugin.lib utility.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../bin/Debug/mdserver.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "mdserver - Win32 Release"
# Name "mdserver - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\mdserver\main\ChangeDirectoryRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\CloseDatabaseRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\ConnectRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\ExpandPathRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\GetDirectoryRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\GetFileListRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\GetMetaDataRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\GetPluginErrorsRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\GetSILRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\KeepAliveRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\LoadPluginsRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\main.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\MDServerApplication.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\MDServerConnection.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\main\QuitRPCExecutor.C
# End Source File
# Begin Source File

SOURCE=..\..\resources\visitresources.rc
# End Source File
# End Group
# End Target
# End Project
