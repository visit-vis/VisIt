# Microsoft Developer Studio Project File - Name="database_ser" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=database_ser - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "database_ser.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "database_ser.mak" CFG="database_ser - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "database_ser - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "database_ser - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "database_ser - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\database_ser"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DATABASE_SER_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "DATABASE_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib misc.lib utility.lib plugin.lib avtexceptions.lib dbatts.lib visitparser.lib visit_vtk_light.lib mir.lib pipeline_ser.lib vtkCommon.lib vtkFiltering.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\database_ser.dll ..\..\bin\Release\database_ser.dll	copy Release\database_ser.lib ..\..\lib\Release\database_ser.lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "database_ser - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\database_ser"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DATABASE_SER_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "DATABASE_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib misc.lib utility.lib plugin.lib avtexceptions.lib dbatts.lib visitparser.lib visit_vtk_light.lib mir.lib pipeline_ser.lib vtkCommon.lib vtkFiltering.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\database_ser.dll ..\..\bin\Debug\database_ser.dll	copy Debug\database_ser.lib ..\..\lib\Debug\database_ser.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "database_ser - Win32 Release"
# Name "database_ser - Win32 Debug"
# Begin Group "Database"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtDatabase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtDatabaseFactory.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtDatasetCollection.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtDatasetDatabase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtFileDescriptorManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtGenericDatabase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtIOInformation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtSILGenerator.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtSourceFromDatabase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Database\avtVariableCache.C
# End Source File
# End Group
# Begin Group "Formats"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtFileFormat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtFileFormatInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtMTMDFileFormat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtMTMDFileFormatInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtMTSDFileFormat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtMTSDFileFormatInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtSTMDFileFormat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtSTMDFileFormatInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtSTSDFileFormat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Formats\avtSTSDFileFormatInterface.C
# End Source File
# End Group
# Begin Group "Ghost"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Database\Ghost\avtDomainBoundaries.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Ghost\avtStructuredDomainBoundaries.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Ghost\avtStructuredDomainNesting.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Ghost\avtUnstructuredDomainBoundaries.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Ghost\avtUnstructuredPointBoundaries.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Database\Ghost\StructuredBoundary.C
# End Source File
# End Group
# End Target
# End Project
