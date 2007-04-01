# Microsoft Developer Studio Project File - Name="guilib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=guilib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "guilib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "guilib.mak" CFG="guilib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "guilib - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "guilib - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "guilib - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GUILIB_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "GUI_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib comm.lib misc.lib plugin.lib viewerproxy.lib viewerrpc.lib mdsrpc.lib mdsproxy.lib proxybase.lib utility.lib dbatts.lib winutil.lib qt-mt302.lib /nologo /dll /machine:I386 /out:"Release/gui.dll"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\gui.dll ..\..\bin\Release\gui.dll	copy Release\gui.lib ..\..\lib\Release\gui.lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "guilib - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GUILIB_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "GUI_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib comm.lib misc.lib utility.lib plugin.lib viewerproxy.lib viewerrpc.lib mdsrpc.lib mdsproxy.lib proxybase.lib utility.lib dbatts.lib winutil.lib qt-mt302.lib /nologo /dll /debug /machine:I386 /out:"Debug/gui.dll" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\gui.dll ..\..\bin\Debug\gui.dll	copy Debug\gui.lib ..\..\lib\Debug\gui.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "guilib - Win32 Release"
# Name "guilib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\gui\ColorTableObserver.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\ExprDeleteButton.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\ExpressionTable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\ExprTypeItem.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\FileServerList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\GUIBase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\Interpreter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\KFBase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\KFListView.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\KFListViewItem.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\KFTimeSlider.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\mini3D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\NameSimplifier.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QualifiedFilename.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAbstractOpacityBar.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnimationSlider.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnimationWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnnotationObjectInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnnotationObjectInterfaceFactory.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnnotationWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAppearanceWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisApplication.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisCheckListManagerWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorButton.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorGridWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorManagerWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorSelectionWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorTableButton.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorTableWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisCommandLineWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDatabaseCorrelationListWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDatabaseCorrelationWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDelayedWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDelayedWindowObserver.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDelayedWindowSimpleObserver.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisEngineWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisExpressionsWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisFileInformationWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisFilePanel.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisFileSelectionWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisGaussianOpacityBar.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisGlobalLineoutWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisGUIApplication.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisHelpListViewItem.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisHelpWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisHostProfileWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisKeyframeWindow.C

!IF  "$(CFG)" == "guilib - Win32 Release"

# ADD CPP /Ze

!ELSEIF  "$(CFG)" == "guilib - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLightingWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLightingWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLineStyleWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLineWidthWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisListViewFileItem.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisMainWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisMaterialWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisMessageWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisNotepadArea.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisOpacitySlider.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisOperatorWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisOutputWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPickWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPlotListBox.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPlotListBoxItem.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPlotManagerWidget.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPluginWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPostableWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPostableWindowObserver.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPostableWindowSimpleObserver.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPreferencesWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisQueryOverTimeWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisQueryWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisRecentPathRemovalWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisRenderingWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSaveWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisScreenPositionEdit.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisScreenPositioner.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisScribbleOpacityBar.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSpectrumBar.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSubsetListView.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSubsetListViewItem.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSubsetWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisText2DInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisTimeSliderInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisTurnDownButton.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisVCRControl.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisViewWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisWindowBase.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\SplashScreen.C
# End Source File
# End Group
# Begin Group "moc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\gui\ExprDeleteButton_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\ExpressionTable_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\ExprTypeItem_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\KFListView_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\KFTimeSlider_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAbstractOpacityBar_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnimationSlider_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnimationWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnnotationObjectInterface_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAnnotationWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisAppearanceWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisApplication_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisCheckListManagerWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorButton_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorGridWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorManagerWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorSelectionWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorTableButton_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisColorTableWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisCommandLineWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDatabaseCorrelationListWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDatabaseCorrelationWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDelayedWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDelayedWindowObserver_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisDelayedWindowSimpleObserver_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisEngineWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisExpressionsWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisFileInformationWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisFilePanel_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisFileSelectionWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisGaussianOpacityBar_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisGlobalLineoutWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisGUIApplication_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisHelpWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisHostProfileWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisKeyframeWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLightingWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLightingWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLineStyleWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisLineWidthWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisMainWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisMaterialWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisMessageWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisNotepadArea_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisOpacitySlider_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisOperatorWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisOutputWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPickWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPlotListBox_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPlotManagerWidget_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPluginWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPostableWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPostableWindowObserver_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPostableWindowSimpleObserver_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisPreferencesWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisQueryOverTimeWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisQueryWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisRecentPathRemovalWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisRenderingWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSaveWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisScreenPositionEdit_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisScreenPositioner_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisScribbleOpacityBar_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSpectrumBar_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSubsetListView_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisSubsetWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisText2DInterface_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisTimeSliderInterface_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisTurnDownButton_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisVCRControl_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisViewWindow_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\QvisWindowBase_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\gui\SplashScreen_moc.C
# End Source File
# End Group
# End Target
# End Project
