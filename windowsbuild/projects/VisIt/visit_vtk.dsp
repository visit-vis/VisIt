# Microsoft Developer Studio Project File - Name="visit_vtk" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=visit_vtk - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "visit_vtk.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "visit_vtk.mak" CFG="visit_vtk - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "visit_vtk - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "visit_vtk - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "visit_vtk - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "VISIT_VTK_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VISIT_VTK_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib vtkCommon.lib vtkFiltering.lib vtkIO.lib vtkGraphics.lib vtkHybrid.lib vtkRendering.lib misc.lib avtexceptions.lib vtktiff.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\visit_vtk.lib ..\..\lib\Release\visit_vtk.lib	copy Release\visit_vtk.dll ..\..\bin\Release\visit_vtk.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "visit_vtk - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "VISIT_VTK_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "VISIT_VTK_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib vtkCommon.lib vtkFiltering.lib vtkIO.lib vtkGraphics.lib vtkHybrid.lib vtkRendering.lib misc.lib avtexceptions.lib vtktiff.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\visit_vtk.dll ..\..\bin\Debug\visit_vtk.dll	copy Debug\visit_vtk.lib ..\..\lib\Debug\visit_vtk.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "visit_vtk - Win32 Release"
# Name "visit_vtk - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\visit\visit_vtk\ClipCasesHex.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\ClipCasesPyr.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\ClipCasesQua.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\ClipCasesTet.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\ClipCasesTri.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\ClipCasesWdg.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\InitVTK.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkAxisDepthSort.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkBackgroundActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkConnectedTubeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkDashedXorGridMapper2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkDataSetFromVolume.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkDataSetRemoveGhostCells.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkDebugStream.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkDisjointCubesFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkHankAxisActor2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkHankTIFFWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkKatAxisActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkKatCubeAxesActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkLineoutFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkLinesFromOriginalCells.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkOBJWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkOnionPeelFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkPolyDataRelevantPointsFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkPPMWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkRectilinearGridFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkRGBWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkRubberBandMapper2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkSkewLookupTable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkSlicer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkStructuredGridFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkSurfaceFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkSurfaceFromVolume.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkTensorReduceFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkTimeSliderActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkTriad2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkTriangulationTables.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkUniqueFeatureEdges.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkUnstructuredGridBoundaryFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkUnstructuredGridFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkUnstructuredGridRelevantPointsFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVectorGlyph.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVectorReduceFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVertexFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVerticalScalarBarActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVerticalScalarBarWithOpacityActor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItCellLocator.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItClipper3D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItContourFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItCutter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItFeatureEdges.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItPLOT3DReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItPolyDataNormals.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItScalarTree.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItSTLWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItStreamLine.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVisItUtility.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\visit_vtk\vtkVolumeFromVolume.C
# End Source File
# End Group
# End Target
# End Project
