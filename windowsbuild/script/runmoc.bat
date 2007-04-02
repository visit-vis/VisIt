@echo off
set MOC=%QTDIR%\bin\moc.exe
set VISIT=%VISITDEVDIR%\visit
set HEADERS=%VISITDEVDIR%\include\visit

echo ************************************************************************
echo Preprocessing VisIt source from %VISITDEVDIR% using %MOC%
echo ...

echo Running moc on the GUI source
set G=%VISIT%\gui

%MOC% %HEADERS%\KFListView.h                       -o %G%\KFListView_moc.C
%MOC% %HEADERS%\KFTimeSlider.h                     -o %G%\KFTimeSlider_moc.C
%MOC% %HEADERS%\QvisAbstractOpacityBar.h           -o %G%\QvisAbstractOpacityBar_moc.C
%MOC% %HEADERS%\QvisAnimationSlider.h              -o %G%\QvisAnimationSlider_moc.C
%MOC% %HEADERS%\QvisAnimationWindow.h              -o %G%\QvisAnimationWindow_moc.C
%MOC% %HEADERS%\QvisAnnotationObjectInterface.h    -o %G%\QvisAnnotationObjectInterface_moc.C
%MOC% %HEADERS%\QvisAnnotationWindow.h             -o %G%\QvisAnnotationWindow_moc.C
%MOC% %HEADERS%\QvisAppearanceWindow.h             -o %G%\QvisAppearanceWindow_moc.C
%MOC% %HEADERS%\QvisApplication.h                  -o %G%\QvisApplication_moc.C
%MOC% %HEADERS%\QvisCheckListManagerWidget.h       -o %G%\QvisCheckListManagerWidget_moc.C
%MOC% %HEADERS%\QvisColorButton.h                  -o %G%\QvisColorButton_moc.C
%MOC% %HEADERS%\QvisColorGridWidget.h              -o %G%\QvisColorGridWidget_moc.C
%MOC% %HEADERS%\QvisColorManagerWidget.h           -o %G%\QvisColorManagerWidget_moc.C
%MOC% %HEADERS%\QvisColorSelectionWidget.h         -o %G%\QvisColorSelectionWidget_moc.C
%MOC% %HEADERS%\QvisColorTableButton.h             -o %G%\QvisColorTableButton_moc.C
%MOC% %HEADERS%\QvisColorTableWindow.h             -o %G%\QvisColorTableWindow_moc.C
%MOC% %HEADERS%\QvisCommandWindow.h                -o %G%\QvisCommandWindow_moc.C
%MOC% %HEADERS%\QvisCompositeTransition.h          -o %G%\QvisCompositeTransition_moc.C
%MOC% %HEADERS%\QvisDatabaseCorrelationWindow.h    -o %G%\QvisDatabaseCorrelationWindow_moc.C
%MOC% %HEADERS%\QvisDatabaseCorrelationListWindow.h -o %G%\QvisDatabaseCorrelationListWindow_moc.C
%MOC% %HEADERS%\QvisDelayedWindow.h                -o %G%\QvisDelayedWindow_moc.C
%MOC% %HEADERS%\QvisDelayedWindowObserver.h        -o %G%\QvisDelayedWindowObserver_moc.C
%MOC% %HEADERS%\QvisDelayedWindowSimpleObserver.h  -o %G%\QvisDelayedWindowSimpleObserver_moc.C
%MOC% %HEADERS%\QvisElementButton.h                -o %G%\QvisElementButton_moc.C
%MOC% %HEADERS%\QvisEngineWindow.h                 -o %G%\QvisEngineWindow_moc.C
%MOC% %HEADERS%\QvisExportDBWindow.h               -o %G%\QvisExportDBWindow_moc.C
%MOC% %HEADERS%\QvisExpressionsWindow.h            -o %G%\QvisExpressionsWindow_moc.C
%MOC% %HEADERS%\QvisFileInformationWindow.h        -o %G%\QvisFileInformationWindow_moc.C
%MOC% %HEADERS%\QvisFileLineEdit.h                 -o %G%\QvisFileLineEdit_moc.C
%MOC% %HEADERS%\QvisFilePanel.h                    -o %G%\QvisFilePanel_moc.C
%MOC% %HEADERS%\QvisFileOpenDialog.h               -o %G%\QvisFileOpenDialog_moc.C
%MOC% %HEADERS%\QvisFileOpenWindow.h               -o %G%\QvisFileOpenWindow_moc.C
%MOC% %HEADERS%\QvisFilePanel.h                    -o %G%\QvisFilePanel_moc.C
%MOC% %HEADERS%\QvisFileSelectionWindow.h          -o %G%\QvisFileSelectionWindow_moc.C
%MOC% %HEADERS%\QvisFtp.h                          -o %G%\QvisFtp_moc.C
%MOC% %HEADERS%\QvisGUIApplication.h               -o %G%\QvisGUIApplication_moc.C
%MOC% %HEADERS%\QvisGaussianOpacityBar.h           -o %G%\QvisGaussianOpacityBar_moc.C
%MOC% %HEADERS%\QvisGlobalLineoutWindow.h          -o %G%\QvisGlobalLineoutWindow_moc.C
%MOC% %HEADERS%\QvisGridWidget.h                   -o %G%\QvisGridWidget_moc.C
%MOC% %HEADERS%\QvisHelpWindow.h                   -o %G%\QvisHelpWindow_moc.C
%MOC% %HEADERS%\QvisHostProfileWindow.h            -o %G%\QvisHostProfileWindow_moc.C
%MOC% %HEADERS%\QvisImageAnnotationInterface.h     -o %G%\QvisImageAnnotationInterface_moc.C
%MOC% %HEADERS%\QvisInteractorWindow.h             -o %G%\QvisInteractorWindow_moc.C
%MOC% %HEADERS%\QvisInterpreter.h                  -o %G%\QvisInterpreter_moc.C
%MOC% %HEADERS%\QvisKeyframeWindow.h               -o %G%\QvisKeyframeWindow_moc.C
%MOC% %HEADERS%\QvisLightingWidget.h               -o %G%\QvisLightingWidget_moc.C
%MOC% %HEADERS%\QvisLightingWindow.h               -o %G%\QvisLightingWindow_moc.C
%MOC% %HEADERS%\QvisLine2DInterface.h              -o %G%\QvisLine2DInterface_moc.C
%MOC% %HEADERS%\QvisLineStyleWidget.h              -o %G%\QvisLineStyleWidget_moc.C
%MOC% %HEADERS%\QvisLineWidthWidget.h              -o %G%\QvisLineWidthWidget_moc.C
%MOC% %HEADERS%\QvisMainWindow.h                   -o %G%\QvisMainWindow_moc.C
%MOC% %HEADERS%\QvisMaterialWindow.h               -o %G%\QvisMaterialWindow_moc.C
%MOC% %HEADERS%\QvisMeshManagementWindow.h         -o %G%\QvisMeshManagementWindow_moc.C
%MOC% %HEADERS%\QvisMessageWindow.h                -o %G%\QvisMessageWindow_moc.C
%MOC% %HEADERS%\QvisMovieProgressDialog.h          -o %G%\QvisMovieProgressDialog_moc.C
%MOC% %HEADERS%\QvisNotepadArea.h                  -o %G%\QvisNotepadArea_moc.C
%MOC% %HEADERS%\QvisOpacitySlider.h                -o %G%\QvisOpacitySlider_moc.C
%MOC% %HEADERS%\QvisOperatorWindow.h               -o %G%\QvisOperatorWindow_moc.C
%MOC% %HEADERS%\QvisOutputWindow.h                 -o %G%\QvisOutputWindow_moc.C
%MOC% %HEADERS%\QvisPeriodicTableWidget.h          -o %G%\QvisPeriodicTableWidget_moc.C
%MOC% %HEADERS%\QvisPickWindow.h                   -o %G%\QvisPickWindow_moc.C
%MOC% %HEADERS%\QvisPlotListBox.h                  -o %G%\QvisPlotListBox_moc.C
%MOC% %HEADERS%\QvisPlotManagerWidget.h            -o %G%\QvisPlotManagerWidget_moc.C
%MOC% %HEADERS%\QvisPluginWindow.h                 -o %G%\QvisPluginWindow_moc.C
%MOC% %HEADERS%\QvisPointControl.h                 -o %G%\QvisPointControl_moc.C
%MOC% %HEADERS%\QvisPostableWindow.h               -o %G%\QvisPostableWindow_moc.C
%MOC% %HEADERS%\QvisPostableWindowObserver.h       -o %G%\QvisPostableWindowObserver_moc.C
%MOC% %HEADERS%\QvisPostableWindowSimpleObserver.h -o %G%\QvisPostableWindowSimpleObserver_moc.C
%MOC% %HEADERS%\QvisPredefinedViewports.h          -o %G%\QvisPredefinedViewports_moc.C
%MOC% %HEADERS%\QvisPreferencesWindow.h            -o %G%\QvisPreferencesWindow_moc.C
%MOC% %HEADERS%\QvisQueryWindow.h                  -o %G%\QvisQueryWindow_moc.C
%MOC% %HEADERS%\QvisQueryOverTimeWindow.h          -o %G%\QvisQueryOverTimeWindow_moc.C
%MOC% %HEADERS%\QvisRecentPathRemovalWindow.h      -o %G%\QvisRecentPathRemovalWindow_moc.C
%MOC% %HEADERS%\QvisRenderingWindow.h              -o %G%\QvisRenderingWindow_moc.C
%MOC% %HEADERS%\QvisSaveMovieWizard.h              -o %G%\QvisSaveMovieWizard_moc.C
%MOC% %HEADERS%\QvisSaveWindow.h                   -o %G%\QvisSaveWindow_moc.C
%MOC% %HEADERS%\QvisScreenPositioner.h             -o %G%\QvisScreenPositioner_moc.C
%MOC% %HEADERS%\QvisScreenPositionEdit.h           -o %G%\QvisScreenPositionEdit_moc.C
%MOC% %HEADERS%\QvisScribbleOpacityBar.h           -o %G%\QvisScribbleOpacityBar_moc.C
%MOC% %HEADERS%\QvisSequenceButton.h               -o %G%\QvisSequenceButton_moc.C
%MOC% %HEADERS%\QvisSequenceTransition.h           -o %G%\QvisSequenceTransition_moc.C
%MOC% %HEADERS%\QvisSequenceView.h                 -o %G%\QvisSequenceView_moc.C
%MOC% %HEADERS%\QvisSessionFileDatabaseLoader.h    -o %G%\QvisSessionFileDatabaseLoader_moc.C
%MOC% %HEADERS%\QvisSessionSourceChangerDialog.h   -o %G%\QvisSessionSourceChangerDialog_moc.C
%MOC% %HEADERS%\QvisSessionSourceChanger.h         -o %G%\QvisSessionSourceChanger_moc.C
%MOC% %HEADERS%\QvisSimulationWindow.h             -o %G%\QvisSimulationWindow_moc.C
%MOC% %HEADERS%\QvisSpectrumBar.h                  -o %G%\QvisSpectrumBar_moc.C
%MOC% %HEADERS%\QvisStripChart.h                   -o %G%\QvisStripChart_moc.C
%MOC% %HEADERS%\QvisSubsetListView.h               -o %G%\QvisSubsetListView_moc.C
%MOC% %HEADERS%\QvisSubsetWindow.h                 -o %G%\QvisSubsetWindow_moc.C
%MOC% %HEADERS%\QvisText2DInterface.h              -o %G%\QvisText2DInterface_moc.C
%MOC% %HEADERS%\QvisTimeSliderInterface.h          -o %G%\QvisTimeSliderInterface_moc.C
%MOC% %HEADERS%\QvisTurnDownButton.h               -o %G%\QvisTurnDownButton_moc.C
%MOC% %HEADERS%\QvisVariableButton.h               -o %G%\QvisVariableButton_moc.C
%MOC% %HEADERS%\QvisVariableButtonHelper.h         -o %G%\QvisVariableButtonHelper_moc.C
%MOC% %HEADERS%\QvisVCRControl.h                   -o %G%\QvisVCRControl_moc.C
%MOC% %HEADERS%\QvisViewWindow.h                   -o %G%\QvisViewWindow_moc.C
%MOC% %HEADERS%\QvisViewportWidget.h               -o %G%\QvisViewportWidget_moc.C
%MOC% %HEADERS%\QvisVisItUpdate.h                  -o %G%\QvisVisItUpdate_moc.C
%MOC% %HEADERS%\QvisWindowBase.h                   -o %G%\QvisWindowBase_moc.C
%MOC% %HEADERS%\QvisWizard.h                       -o %G%\QvisWizard_moc.C
%MOC% %HEADERS%\SimCommandSlots.h                  -o %G%\SimCommandSlots_moc.C
%MOC% %HEADERS%\SplashScreen.h                     -o %G%\SplashScreen_moc.C

echo Running moc on the viewer source
set V=%VISIT%\viewer\main
%MOC% %HEADERS%\PlotAndOperatorActions.h           -o %V%\PlotAndOperatorActions_moc.C
%MOC% %HEADERS%\ViewerAction.h                     -o %V%\ViewerAction_moc.C
%MOC% %HEADERS%\ViewerActionBase.h                 -o %V%\ViewerActionBase_moc.C
%MOC% %HEADERS%\ViewerClientConnection.h           -o %V%\ViewerClientConnection_moc.C
%MOC% %HEADERS%\ViewerConnectionProgressDialog.h   -o %V%\ViewerConnectionProgressDialog_moc.C
%MOC% %HEADERS%\ViewerHostProfileSelectorWithWin.h -o %V%\ViewerHostProfileSelectorWithWin_moc.C
%MOC% %HEADERS%\ViewerMetaDataObserver.h           -o %V%\ViewerMetaDataObserver_moc.C
%MOC% %HEADERS%\ViewerMultipleAction.h             -o %V%\ViewerMultipleAction_moc.C
%MOC% %HEADERS%\ViewerPasswordWindow.h             -o %V%\ViewerPasswordWindow_moc.C
%MOC% %HEADERS%\ViewerRPCObserver.h                -o %V%\ViewerRPCObserver_moc.C
%MOC% %HEADERS%\ViewerSILAttsObserver.h            -o %V%\ViewerSILAttsObserver_moc.C
%MOC% %HEADERS%\ViewerSubject.h                    -o %V%\ViewerSubject_moc.C
%MOC% %HEADERS%\ViewerWindowManager.h              -o %V%\ViewerWindowManager_moc.C

echo Running moc on the vtkQt source
set Q=%VISIT%\vtkqt
%MOC% %HEADERS%\vtkQtRenderWindowInteractor.h      -o %Q%\vtkQtRenderWindowInteractor_moc.C
%MOC% %HEADERS%\vtkQtGLWidget.h                    -o %Q%\vtkQtGLWidget_moc.C

echo Running moc on the winutil source
set W=%VISIT%\winutil
%MOC% %HEADERS%\QvisVariablePopupMenu.h            -o %W%\QvisVariablePopupMenu_moc.C

echo ...
echo Done.
echo ************************************************************************
