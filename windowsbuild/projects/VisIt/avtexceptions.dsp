# Microsoft Developer Studio Project File - Name="avtexceptions" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=avtexceptions - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "avtexceptions.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "avtexceptions.mak" CFG="avtexceptions - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "avtexceptions - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "avtexceptions - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "avtexceptions - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AVTEXCEPTIONS_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "AVTEXCEPTION_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\avtexceptions.lib ..\..\lib\Release\avtexceptions.lib	copy Release\avtexceptions.dll ..\..\bin\Release\avtexceptions.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "avtexceptions - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AVTEXCEPTIONS_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "AVTEXCEPTION_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\avtexceptions.lib ..\..\lib\Release\avtexceptions.lib	copy Debug\avtexceptions.dll ..\..\bin\Release\avtexceptions.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "avtexceptions - Win32 Release"
# Name "avtexceptions - Win32 Debug"
# Begin Group "Database"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\BadPermissionException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\FileDoesNotExistException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\InvalidDBTypeException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\InvalidFilesException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\InvalidSourceException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\InvalidTimeStepException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\InvalidVariableException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\InvalidZoneTypeException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Database\SiloException.C
# End Source File
# End Group
# Begin Group "Pipeline"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\AbortException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\BadCellException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\BadDomainException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\BadIndexException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\BadNodeException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\BadVectorException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\ExpressionException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\GhostCellException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\ImproperUseException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\IncompatibleDomainListsException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\IntervalTreeNotCalculatedException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\InvalidCategoryException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\InvalidCellTypeException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\InvalidDimensionsException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\InvalidLimitsException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\InvalidMergeException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\InvalidSetException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\LogicalIndexException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\NoCurveException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\NoDefaultVariableException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\NoInputException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\NonQueryableInputException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Pipeline\UnexpectedValueException.C
# End Source File
# End Group
# Begin Group "VisWindow"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\VisWindow\BadColleagueException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\VisWindow\BadInteractorException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\VisWindow\BadPlotException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\VisWindow\BadWindowModeException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\VisWindow\PlotDimensionalityException.C
# End Source File
# End Group
# Begin Group "Plotter"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\common\Exceptions\Plotter\InvalidColortableException.C
# End Source File
# End Group
# End Target
# End Project
