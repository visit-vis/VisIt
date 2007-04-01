# Microsoft Developer Studio Project File - Name="mdsrpc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=mdsrpc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mdsrpc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mdsrpc.mak" CFG="mdsrpc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mdsrpc - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mdsrpc - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mdsrpc - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\mdsrpc"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MDSRPC_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "MDSERVER_RPC_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib utility.lib dbatts.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\mdsrpc.lib ..\..\lib\Release\mdsrpc.lib	copy Release\mdsrpc.dll ..\..\bin\Release\mdsrpc.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mdsrpc - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\mdsrpc"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MDSRPC_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "MDSERVER_RPC_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib utility.lib dbatts.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\mdsrpc.lib ..\..\lib\Debug\mdsrpc.lib	copy Debug\mdsrpc.dll ..\..\bin\Debug\mdsrpc.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "mdsrpc - Win32 Release"
# Name "mdsrpc - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\ChangeDirectoryException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\ChangeDirectoryRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\CloseDatabaseRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\ConnectRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\CreateGroupListRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\ExpandPathRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\GetDirectoryRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\GetFileListException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\GetFileListRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\GetMetaDataException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\GetMetaDataRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\GetSILRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\mdserver\rpc\LoadPluginsRPC.C
# End Source File
# End Group
# End Target
# End Project
