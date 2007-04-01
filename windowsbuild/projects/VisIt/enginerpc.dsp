# Microsoft Developer Studio Project File - Name="enginerpc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=enginerpc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "enginerpc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "enginerpc.mak" CFG="enginerpc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "enginerpc - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "enginerpc - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "enginerpc - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\enginerpc"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ENGINERPC_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "ENGINE_RPC_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\enginerpc.lib ..\..\lib\Release\enginerpc.lib	copy Release\enginerpc.dll ..\..\bin\Release\enginerpc.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "enginerpc - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\enginerpc"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ENGINERPC_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "ENGINE_RPC_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\enginerpc.lib ..\..\lib\Debug\enginerpc.lib	copy Debug\enginerpc.dll ..\..\bin\Debug\enginerpc.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "enginerpc - Win32 Release"
# Name "enginerpc - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\engine\rpc\ApplyOperatorRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\ClearCacheRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\CloneNetworkRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\DefineVirtualDatabaseRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\ExecuteRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\MakePlotRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\OpenDatabaseRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\PickRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\QueryRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\ReadRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\ReleaseDataRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\RenderRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\SetWinAnnotAttsRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\StartPickRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\UpdatePlotAttsRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\engine\rpc\UseNetworkRPC.C
# End Source File
# End Group
# End Target
# End Project
