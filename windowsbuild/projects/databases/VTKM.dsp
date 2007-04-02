# Microsoft Developer Studio Project File - Name="VTKM" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=VTKM - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VTKM.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VTKM.mak" CFG="VTKM - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VTKM - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "VTKM - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VTKM - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\VTKM"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SILOM_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I "..\..\visit\databases\VTK" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GENERAL_PLUGIN_EXPORTS" /D "MDSERVER_PLUGIN_EXPORTS" /D "USING_MSVC6" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib pipeline_ser.lib dbatts.lib database_ser.lib avtexceptions.lib vtkCommon.lib vtkIO.lib vtkexpat.lib vtkzlib.lib /nologo /dll /machine:I386 /out:"Release/libMVTKDatabase.dll"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\libMVTKDatabase.dll ..\..\bin\Release\databases
# End Special Build Tool

!ELSEIF  "$(CFG)" == "VTKM - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\VTKM"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SILOM_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I "..\..\visit\databases\VTK" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GENERAL_PLUGIN_EXPORTS" /D "MDSERVER_PLUGIN_EXPORTS" /D "USING_MSVC6" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib pipeline_ser.lib dbatts.lib database_ser.lib avtexceptions.lib vtkCommon.lib vtkIO.lib vtkexpat.lib vtkzlib.lib /nologo /dll /debug /machine:I386 /out:"Debug/libMVTKDatabase.dll" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\libMVTKDatabase.dll ..\..\bin\Debug\databases
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "VTKM - Win32 Release"
# Name "VTKM - Win32 Debug"
# Begin Group "XML"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLDataElement.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLDataParser.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLFileReadTester.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLImageDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLParser.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLPolyDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLRectilinearGridReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLStructuredDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLStructuredGridReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLUnstructuredDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLUnstructuredGridReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItXMLUtilities.C
# End Source File
# End Group
# Begin Group "Legacy"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItDataSetReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItInputStream.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItOutputStream.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItPolyDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItRectilinearGridReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItStructuredGridReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItStructuredPointsReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItUnstructuredGridReader.C
# End Source File
# End Group
# Begin Group "Compression"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItBase64InputStream.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItBase64OutputStream.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItBase64Utilities.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItDataCompressor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\vtkVisItZLibDataCompressor.C
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\visit\databases\VTK\avtVTKFileFormat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\avtVTKOptions.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\avtVTKWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\VTKCommonPluginInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\VTKMDServerPluginInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\databases\VTK\VTKPluginInfo.C
# End Source File
# End Target
# End Project
