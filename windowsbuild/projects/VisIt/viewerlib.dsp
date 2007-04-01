# Microsoft Developer Studio Project File - Name="viewerlib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=viewerlib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "viewerlib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "viewerlib.mak" CFG="viewerlib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "viewerlib - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "viewerlib - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "viewerlib - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "VIEWERLIB_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VIEWER_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comm.lib state.lib misc.lib plugin.lib proxybase.lib visit_vtk.lib pipeline_ser.lib plotter.lib dbatts.lib viswindow.lib avtexceptions.lib viewerrpc.lib engineproxy.lib enginerpc.lib mdsproxy.lib mdsrpc.lib visitparser.lib qt-mt302.lib winutil.lib avtmath_ser.lib avtview.lib avtfilters.lib avtfilewriter.lib qtviswindow.lib /nologo /dll /machine:I386 /out:"Release/viewer.dll"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\viewer.dll ..\..\bin\Release\viewer.dll	copy Release\viewer.lib ..\..\lib\Release\viewer.lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "viewerlib - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "VIEWERLIB_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VIEWER_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comm.lib state.lib misc.lib plugin.lib proxybase.lib visit_vtk.lib pipeline_ser.lib plotter.lib dbatts.lib viswindow.lib avtexceptions.lib viewerrpc.lib engineproxy.lib enginerpc.lib mdsproxy.lib mdsrpc.lib visitparser.lib qt-mt302.lib winutil.lib avtmath_ser.lib qtviswindow.lib /nologo /dll /debug /machine:I386 /out:"Debug/viewer.dll" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\viewer.dll ..\..\bin\Debug\viewer.dll	copy Debug\viewer.lib ..\..\lib\Debug\viewer.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "viewerlib - Win32 Release"
# Name "viewerlib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\viewer\main\ActionGroupDescription.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\AnimationActions.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\LineoutListItem.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\NoEngineException.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\PlotAndOperatorActions.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewActions.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerAction.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerActionBase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerActionManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerAnimation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerConfigManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerConnectionProgressDialog.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerEngineManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerFileServer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerHostProfileSelector.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerHostProfileSelectorNoWin.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerHostProfileSelectorWithWin.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerMessageBuffer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerMessaging.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerMultipleAction.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerOperator.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerOperatorFactory.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerPalette.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerPasswordWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerPlot.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerPlotFactory.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerPlotList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerPopupMenu.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerQueryManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerRemoteProcessChooser.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerRPCObserver.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerServerManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerSubject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerToggleAction.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerToolbar.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerWindowManager.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerWindowManagerAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\WindowActions.C
# End Source File
# End Group
# Begin Group "moc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\viewer\main\PlotAndOperatorActions_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerAction_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerActionBase_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerConnectionProgressDialog_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerHostProfileSelectorWithWin_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerMultipleAction_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerPasswordWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerRPCObserver_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerSubject_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\viewer\main\ViewerWindowManager_moc.C
# End Source File
# End Group
# End Target
# End Project
