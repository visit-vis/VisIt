# Microsoft Developer Studio Project File - Name="viswindow" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=viswindow - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "viswindow.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "viswindow.mak" CFG="viswindow - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "viswindow - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "viswindow - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "viswindow - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\viswindow"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "VISWINDOW_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VISWINDOW_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib comm.lib misc.lib visit_vtk.lib avtexceptions.lib avtmath_ser.lib plotter.lib pipeline_ser.lib avtview.lib vtkqt.lib vtkCommon.lib vtkFiltering.lib vtkGraphics.lib vtkRendering.lib vtkImaging.lib vtkIO.lib qt-mt302.lib opengl32.lib MesaGL.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\viswindow.dll ..\..\bin\Release\viswindow.dll	copy Release\viswindow.lib ..\..\lib\Release\viswindow.lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "viswindow - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\viswindow"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "VISWINDOW_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VISWINDOW_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib comm.lib misc.lib visit_vtk.lib avtexceptions.lib avtmath_ser.lib plotter.lib avtview.lib pipeline_ser.lib vtkqt.lib vtkCommon.lib vtkFiltering.lib vtkGraphics.lib vtkRendering.lib vtkImaging.lib vtkIO.lib qt-mt302.lib opengl32.lib MesaGL.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\viswindow.lib ..\..\lib\Debug\viswindow.lib	copy Debug\viswindow.dll ..\..\bin\Debug\viswindow.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "viswindow - Win32 Release"
# Name "viswindow - Win32 Debug"
# Begin Group "Colleagues"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\avtAnnotationColleague.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\avtImageColleague.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\avtLine2DColleague.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\avtText2DColleague.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\avtTimeSliderColleague.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinAnnotations.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinAxes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinAxes3D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinBackground.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinColleague.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinFrame.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinInteractions.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinLegends.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinLighting.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinPlots.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinQuery.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinRendering.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinRenderingWithoutWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinTools.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinTriad.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinUserInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Colleagues\VisWinView.C
# End Source File
# End Group
# Begin Group "Interactors"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\Dolly3D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\FlyThrough.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\Lineout2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\Navigate2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\Navigate3D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\NavigateCurve.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\NullInteractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\Pick.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\VisitHotPointInteractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\VisitInteractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\Zoom2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\Zoom3D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\ZoomCurve.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Interactors\ZoomInteractor.C
# End Source File
# End Group
# Begin Group "Proxies"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Proxies\VisWindowProtectionProxy.C
# End Source File
# End Group
# Begin Group "Tools"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\avtBoxToolInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\avtLineToolInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\avtPlaneToolInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\avtPointToolInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\avtSphereToolInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\avtToolInterface.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\VisitBoxTool.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\VisitInteractiveTool.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\VisitLineTool.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\VisitPlaneTool.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\VisitPointTool.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\Tools\VisitSphereTool.C
# End Source File
# End Group
# Begin Group "VisWindow"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\VisWindow\VisWindow.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\VisWindow\VisWindow\VisWindowTypes.C
# End Source File
# End Group
# End Target
# End Project
