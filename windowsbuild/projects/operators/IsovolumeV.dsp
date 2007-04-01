# Microsoft Developer Studio Project File - Name="IsovolumeV" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=IsovolumeV - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "IsovolumeV.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "IsovolumeV.mak" CFG="IsovolumeV - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IsovolumeV - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "IsovolumeV - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "IsovolumeV - Win32 Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I "..\..\visit\operators\Isovolume" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "GENERAL_PLUGIN_EXPORTS" /D "VIEWER_PLUGIN_EXPORTS" /D "GENERAL_PLUGIN_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib pipeline_ser.lib avtexceptions.lib viewer.lib dbatts.lib visit_vtk.lib vtkCommon.lib vtkGraphics.lib vtkFiltering.lib /nologo /dll /machine:I386 /out:"Release/libVIsovolume.dll"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\libVIsovolume.dll ..\..\bin\Release\operators
# End Special Build Tool

!ELSEIF  "$(CFG)" == "IsovolumeV - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I "..\..\visit\operators\Isovolume" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "GENERAL_PLUGIN_EXPORTS" /D "VIEWER_PLUGIN_EXPORTS" /TP
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib pipeline_ser.lib avtexceptions.lib viewer.lib dbatts.lib visit_vtk.lib vtkCommon.lib vtkGraphics.lib vtkFiltering.lib /nologo /dll /debug /machine:I386 /out:"Debug/libVIsovolume.dll" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\libVIsovolume.dll ..\..\bin\Debug\operators
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "IsovolumeV - Win32 Release"
# Name "IsovolumeV - Win32 Debug"
# Begin Source File

SOURCE=..\..\visit\operators\Isovolume\avtIsovolumeFilter.C
DEP_CPP_AVTIS=\
	"..\..\visit\operators\Isovolume\avtIsovolumeFilter.h"\
	"..\..\visit\operators\Isovolume\IsovolumeAttributes.h"\
	{$(INCLUDE)}"array_ref_ptr.h"\
	{$(INCLUDE)}"AttributeGroup.h"\
	{$(INCLUDE)}"AttributeSubject.h"\
	{$(INCLUDE)}"avtCommonDataFunctions.h"\
	{$(INCLUDE)}"avtDataAttributes.h"\
	{$(INCLUDE)}"avtDataObject.h"\
	{$(INCLUDE)}"avtDataObjectInformation.h"\
	{$(INCLUDE)}"avtDataObjectSink.h"\
	{$(INCLUDE)}"avtDataObjectSource.h"\
	{$(INCLUDE)}"avtDataObjectToDatasetFilter.h"\
	{$(INCLUDE)}"avtDataRepresentation.h"\
	{$(INCLUDE)}"avtDataset.h"\
	{$(INCLUDE)}"avtDatasetSink.h"\
	{$(INCLUDE)}"avtDatasetSource.h"\
	{$(INCLUDE)}"avtDatasetToDataObjectFilter.h"\
	{$(INCLUDE)}"avtDatasetToDatasetFilter.h"\
	{$(INCLUDE)}"avtDataSpecification.h"\
	{$(INCLUDE)}"avtDataTree.h"\
	{$(INCLUDE)}"avtDataTreeStreamer.h"\
	{$(INCLUDE)}"avtDataValidity.h"\
	{$(INCLUDE)}"avtFilter.h"\
	{$(INCLUDE)}"avtGhostData.h"\
	{$(INCLUDE)}"avtMatrix.h"\
	{$(INCLUDE)}"avtPipelineSpecification.h"\
	{$(INCLUDE)}"avtPluginFilter.h"\
	{$(INCLUDE)}"avtPluginStreamer.h"\
	{$(INCLUDE)}"avtSIL.h"\
	{$(INCLUDE)}"avtSILCollection.h"\
	{$(INCLUDE)}"avtSILMatrix.h"\
	{$(INCLUDE)}"avtSILRestriction.h"\
	{$(INCLUDE)}"avtSILSet.h"\
	{$(INCLUDE)}"avtStreamer.h"\
	{$(INCLUDE)}"avtTypes.h"\
	{$(INCLUDE)}"avtVector.h"\
	{$(INCLUDE)}"dbatts_exports.h"\
	{$(INCLUDE)}"DebugStream.h"\
	{$(INCLUDE)}"math_exports.h"\
	{$(INCLUDE)}"misc_exports.h"\
	{$(INCLUDE)}"pipeline_exports.h"\
	{$(INCLUDE)}"ref_ptr.h"\
	{$(INCLUDE)}"state_exports.h"\
	{$(INCLUDE)}"Subject.h"\
	{$(INCLUDE)}"vectortypes.h"\
	{$(INCLUDE)}"visit_vtk_exports.h"\
	{$(INCLUDE)}"VisItException.h"\
	{$(INCLUDE)}"visitstream.h"\
	{$(INCLUDE)}"viswindow_exports.h"\
	{$(INCLUDE)}"VisWindowTypes.h"\
	{$(INCLUDE)}"vtkCellData.h"\
	{$(INCLUDE)}"vtkCellDataToPointData.h"\
	{$(INCLUDE)}"vtkCellLinks.h"\
	{$(INCLUDE)}"vtkCellType.h"\
	{$(INCLUDE)}"vtkCellTypes.h"\
	{$(INCLUDE)}"vtkConfigure.h"\
	{$(INCLUDE)}"vtkDataArray.h"\
	{$(INCLUDE)}"vtkDataObject.h"\
	{$(INCLUDE)}"vtkDataSet.h"\
	{$(INCLUDE)}"vtkDataSetAttributes.h"\
	{$(INCLUDE)}"vtkDataSetSource.h"\
	{$(INCLUDE)}"vtkDataSetToDataSetFilter.h"\
	{$(INCLUDE)}"vtkDataSetToUnstructuredGridFilter.h"\
	{$(INCLUDE)}"vtkFieldData.h"\
	{$(INCLUDE)}"vtkIdType.h"\
	{$(INCLUDE)}"vtkIndent.h"\
	{$(INCLUDE)}"vtkIntArray.h"\
	{$(INCLUDE)}"vtkIOStream.h"\
	{$(INCLUDE)}"vtkIOStreamFwd.h"\
	{$(INCLUDE)}"vtkObject.h"\
	{$(INCLUDE)}"vtkObjectBase.h"\
	{$(INCLUDE)}"vtkOStreamWrapper.h"\
	{$(INCLUDE)}"vtkOStrStreamWrapper.h"\
	{$(INCLUDE)}"vtkPointData.h"\
	{$(INCLUDE)}"vtkPoints.h"\
	{$(INCLUDE)}"vtkPointSet.h"\
	{$(INCLUDE)}"vtkPolyData.h"\
	{$(INCLUDE)}"vtkProcessObject.h"\
	{$(INCLUDE)}"vtkSetGet.h"\
	{$(INCLUDE)}"vtkSource.h"\
	{$(INCLUDE)}"vtkSystemIncludes.h"\
	{$(INCLUDE)}"vtkTimeStamp.h"\
	{$(INCLUDE)}"vtkUnsignedCharArray.h"\
	{$(INCLUDE)}"vtkUnstructuredGrid.h"\
	{$(INCLUDE)}"vtkUnstructuredGridSource.h"\
	{$(INCLUDE)}"vtkVisItClipper.h"\
	{$(INCLUDE)}"vtkWin32Header.h"\
	{$(INCLUDE)}"vtkWinCE.h"\
	
# End Source File
# Begin Source File

SOURCE=..\..\visit\operators\Isovolume\IsovolumeAttributes.C
DEP_CPP_ISOVO=\
	"..\..\visit\operators\Isovolume\IsovolumeAttributes.h"\
	{$(INCLUDE)}"AttributeGroup.h"\
	{$(INCLUDE)}"AttributeSubject.h"\
	{$(INCLUDE)}"DataNode.h"\
	{$(INCLUDE)}"state_exports.h"\
	{$(INCLUDE)}"Subject.h"\
	{$(INCLUDE)}"vectortypes.h"\
	{$(INCLUDE)}"visitstream.h"\
	
# End Source File
# Begin Source File

SOURCE=..\..\visit\operators\Isovolume\IsovolumeCommonPluginInfo.C
DEP_CPP_ISOVOL=\
	"..\..\visit\operators\Isovolume\IsovolumeAttributes.h"\
	"..\..\visit\operators\Isovolume\IsovolumePluginInfo.h"\
	{$(INCLUDE)}"AttributeGroup.h"\
	{$(INCLUDE)}"AttributeSubject.h"\
	{$(INCLUDE)}"operator_plugin_exports.h"\
	{$(INCLUDE)}"OperatorPluginInfo.h"\
	{$(INCLUDE)}"plugin_exports.h"\
	{$(INCLUDE)}"state_exports.h"\
	{$(INCLUDE)}"Subject.h"\
	{$(INCLUDE)}"vectortypes.h"\
	{$(INCLUDE)}"visitstream.h"\
	
# End Source File
# Begin Source File

SOURCE=..\..\visit\operators\Isovolume\IsovolumePluginInfo.C
DEP_CPP_ISOVOLU=\
	"..\..\visit\operators\Isovolume\IsovolumeAttributes.h"\
	"..\..\visit\operators\Isovolume\IsovolumePluginInfo.h"\
	{$(INCLUDE)}"AttributeGroup.h"\
	{$(INCLUDE)}"AttributeSubject.h"\
	{$(INCLUDE)}"operator_plugin_exports.h"\
	{$(INCLUDE)}"OperatorPluginInfo.h"\
	{$(INCLUDE)}"plugin_exports.h"\
	{$(INCLUDE)}"state_exports.h"\
	{$(INCLUDE)}"Subject.h"\
	{$(INCLUDE)}"vectortypes.h"\
	{$(INCLUDE)}"visitstream.h"\
	
# End Source File
# Begin Source File

SOURCE=..\..\visit\operators\Isovolume\IsovolumeViewerPluginInfo.C
DEP_CPP_ISOVOLUM=\
	"..\..\visit\operators\Isovolume\Isovolume.xpm"\
	"..\..\visit\operators\Isovolume\IsovolumeAttributes.h"\
	"..\..\visit\operators\Isovolume\IsovolumePluginInfo.h"\
	{$(INCLUDE)}"AttributeGroup.h"\
	{$(INCLUDE)}"AttributeSubject.h"\
	{$(INCLUDE)}"operator_plugin_exports.h"\
	{$(INCLUDE)}"OperatorPluginInfo.h"\
	{$(INCLUDE)}"plugin_exports.h"\
	{$(INCLUDE)}"state_exports.h"\
	{$(INCLUDE)}"Subject.h"\
	{$(INCLUDE)}"vectortypes.h"\
	{$(INCLUDE)}"visitstream.h"\
	
# End Source File
# End Target
# End Project
