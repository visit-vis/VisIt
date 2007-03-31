# Microsoft Developer Studio Project File - Name="pipeline_ser" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=pipeline_ser - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pipeline_ser.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pipeline_ser.mak" CFG="pipeline_ser - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pipeline_ser - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "pipeline_ser - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pipeline_ser - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "PIPELINE_SER_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "PIPELINE_EXPORTS" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib comm.lib utility.lib avtexceptions.lib dbatts.lib visit_vtk.lib avtmath_ser.lib vtkCommon.lib vtkIO.lib vtkFiltering.lib vtkGraphics.lib vtkRendering.lib vtkImaging.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\pipeline_ser.lib ..\..\lib\Release\pipeline_ser.lib	copy Release\pipeline_ser.dll ..\..\bin\Release\pipeline_ser.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "pipeline_ser - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "PIPELINE_SER_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USING_MSVC6" /D "PIPELINE_EXPORTS" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib comm.lib utility.lib avtexceptions.lib avtmath_ser.lib dbatts.lib visit_vtk.lib vtkCommon.lib vtkIO.lib vtkFiltering.lib vtkGraphics.lib vtkRendering.lib vtkImaging.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\pipeline_ser.lib ..\..\lib\Debug\pipeline_ser.lib	copy Debug\pipeline_ser.dll ..\..\bin\Debug\pipeline_ser.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "pipeline_ser - Win32 Release"
# Name "pipeline_ser - Win32 Debug"
# Begin Group "Data"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtAverageValueRF.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtCallback.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtCellList.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtCommonDataFunctions.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtCompositeRF.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDataAttributes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDataObject.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDataObjectInformation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDataRepresentation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDataset.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDatasetExaminer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDatasetVerifier.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDataTree.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDataValidity.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDistancePixelizer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDistanceToValueRF.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtDynamicAttribute.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtExtents.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtFacelist.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtFlatLighting.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtGradients.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtHexahedronExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtImage.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtImagePartition.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtImageRepresentation.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtIntervalTree.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtLightingModel.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtMassVoxelExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtMaterial.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtMaximumIntensityProjectionRF.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtMetaData.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtMIPRangeRF.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtMixedVariable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtNullData.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtOpacityMap.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtPhong.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtPointAttribute.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtPyramidExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtRangeMaxTable.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtRay.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtRayFunction.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtSamplePointArbitrator.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtSamplePoints.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtSpecies.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtTetrahedronExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtVariablePixelizer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtView2D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtView3D.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtViewCurve.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtViewInfo.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtVolume.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Data\avtWedgeExtractor.C
# End Source File
# End Group
# Begin Group "Pipeline"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtDataObjectReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtDataObjectString.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtDataObjectWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtDataSetReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtDataSetWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtDataSpecification.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtImageReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtImageWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtNullDataReader.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtNullDataWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtParallel.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Pipeline\avtPipelineSpecification.C
# End Source File
# End Group
# Begin Group "PrivateFilters"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtDataObjectToDatasetFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtDatasetToDataObjectFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtDatasetToDatasetFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtDatasetToImageFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtDatasetToSamplePointsFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtDataTreeStreamer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtFacadeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtPluginStreamer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtSamplePointsToSamplePointsFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtSingleFilterFacade.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PrivateFilters\avtStreamer.C
# End Source File
# End Group
# Begin Group "PublicFilters"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtCompactTreeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtCondenseDatasetFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtContourFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtCurrentExtentFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtCurveConstructorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtFeatureEdgesFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtGhostZoneAndFacelistFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtGhostZoneFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtImageCompositer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtPointToGlyphFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtRayCompositer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtRayTracer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtResampleFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtSamplePointExtractor.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtShiftCenteringFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtSimilarityTransformFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtSmoothPolyDataFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtTransform.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtVertexNormalsFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtWholeImageCompositer.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\PublicFilters\avtWorldSpaceToImageSpaceTransform.C
# End Source File
# End Group
# Begin Group "Sinks"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtDatabaseWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtDataObjectSink.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtDatasetFileWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtDatasetSink.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtFileWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtImageFileWriter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtImageSink.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtMultipleInputSink.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtNullDataSink.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtOriginatingDatasetSink.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtOriginatingSink.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sinks\avtSamplePointsSink.C
# End Source File
# End Group
# Begin Group "Sources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtDataObjectSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtDatasetSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtImageSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtInlinePipelineSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtNullDataSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtSamplePointsSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtSourceFromAVTDataset.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtSourceFromDataset.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtSourceFromImage.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtTerminatingDatasetSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtTerminatingImageSource.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Pipeline\Sources\avtTerminatingSource.C
# End Source File
# End Group
# End Target
# End Project
