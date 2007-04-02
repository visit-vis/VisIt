# Microsoft Developer Studio Project File - Name="state" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=state - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "state.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "state.mak" CFG="state - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "state - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "state - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "state - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\state"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "STATE_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "STATE_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib comm.lib utility.lib wsock32.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\state.dll ..\..\bin\Release\state.dll	copy Release\state.lib ..\..\lib\Release\state.lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "state - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\state"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "STATE_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "STATE_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib misc.lib comm.lib utility.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\state.dll ..\..\bin\Debug\state.dll	copy Debug\state.lib ..\..\lib\Debug\state.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "state - Win32 Release"
# Name "state - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\common\state\AnimationAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\AnnotationAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\AnnotationObject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\AnnotationObjectList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\AppearanceAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\AttributeGroup.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\AttributeSubject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\AttributeSubjectMap.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\BoxExtents.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ClientInformation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ClientInformationList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ClientMethod.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ColorAttribute.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ColorAttributeList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ColorControlPoint.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ColorControlPointList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ColorTableAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ColorTableManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\CompactSILRestrictionAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ConfigManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ContourOpAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\DatabaseAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\DatabaseCorrelation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\DatabaseCorrelationList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\DataNode.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\DBOptionsAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\DBPluginInfoAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\EngineList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ExportDBAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\Expression.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ExpressionList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\GaussianControlPoint.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\GaussianControlPointList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\GlobalAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\GlobalLineoutAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\HostProfile.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\HostProfileList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\InteractorAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\KeepAliveRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\KeyframeAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\LightAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\LightList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\Line.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\MaterialAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\MeshManagementAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\MessageAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\MovieAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\NamespaceAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\Observer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ObserverToCallback.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PickAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PickVarInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PlaneAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\Plot.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PlotList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PlotQueryInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PluginManagerAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\Point.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PointAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\PrinterAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ProcessAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\QueryAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\QueryList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\QueryOverTimeAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\QuitRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\RenderingAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ResampleAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SaveWindowAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SILAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SILMatrixAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SILRestrictionAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SimilarityTransformAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SimpleObserver.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SimulationCommand.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SphereAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\StatusAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\Subject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SurfaceFilterAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\SyncAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\TimeFormat.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\View2DAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\View3DAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ViewAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\ViewCurveAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\VisItRPC.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\VisualCueInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\VisualCueList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\WindowAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\WindowInformation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\common\state\Xfer.C
# End Source File
# End Group
# End Target
# End Project
