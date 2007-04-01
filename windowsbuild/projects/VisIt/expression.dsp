# Microsoft Developer Studio Project File - Name="expression" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=expression - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "expression.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "expression.mak" CFG="expression - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "expression - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "expression - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "expression - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\expression"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXPRESSION_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXPRESSION_EXPORTS" /D "USING_MSVC6" /YX /FD /TP /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib avtfilters.lib pipeline_ser.lib avtexceptions.lib state.lib visitparser.lib visit_vtk.lib vtkCommon.lib vtkFiltering.lib vtkGraphics.lib /nologo /dll /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Release\expression.lib ..\..\lib\Release\expression.lib	copy Release\expression.dll ..\..\bin\Release\expression.dll
# End Special Build Tool

!ELSEIF  "$(CFG)" == "expression - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\expression"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXPRESSION_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXPRESSION_EXPORTS" /D "USING_MSVC6" /YX /FD /GZ /TP /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib misc.lib state.lib pipeline_ser.lib avtexceptions.lib visitparser.lib visit_vtk.lib vtkCommon.lib vtkFiltering.lib vtkGraphics.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Debug\expression.lib ..\..\lib\Debug\expression.lib	copy Debug\expression.dll ..\..\bin\Debug\expression.dll
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "expression - Win32 Release"
# Name "expression - Win32 Debug"
# Begin Group "Abstract"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Abstract\avtBinaryMathFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Abstract\avtComparisonFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Abstract\avtExpressionFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Abstract\avtMultipleInputExpressionFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Abstract\avtSingleInputExpressionFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Abstract\avtUnaryMathFilter.C
# End Source File
# End Group
# Begin Group "General"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtDataIdFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtDegreeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtGradientFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtMagnitudeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtMatvfFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtMeshCoordinateFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtNeighborEvaluatorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtNMatsFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtProcessorIdFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtRandomFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtRecenterFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtSpecMFFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtVectorComposeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\General\avtVectorDecomposeFilter.C
# End Source File
# End Group
# Begin Group "Math"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtAbsValFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtArccosFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtArcsinFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtArctanFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtBase10LogFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtBinaryAddFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtBinaryDivideFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtBinaryMultiplyFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtBinaryPowerFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtBinarySubtractFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtCosFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtDegreeToRadianFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtDeterminantFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtEigenvalueFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtEigenvectorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtIdentityFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtInverseFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtNaturalLogFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtPolarCoordinatesFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtRadianToDegreeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtSinFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtSquareFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtSquareRootFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtTanFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtTraceFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtUnaryMinusFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Math\avtVectorCrossProductFilter.C
# End Source File
# End Group
# Begin Group "MeshQuality"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtNeighborFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtNodeDegreeFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtRevolvedSurfaceArea.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtRevolvedVolume.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVerdictFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricArea.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricAspectGamma.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricAspectRatio.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricCondition.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricDiagonal.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricDimension.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricJacobian.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricLargestAngle.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricOddy.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricRelativeSize.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricScaledJacobian.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricShape.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricShapeAndSize.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricShear.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricSkew.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricSmallestAngle.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricStretch.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricTaper.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricVolume.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\avtVMetricWarpage.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\MeshQuality\verdict.C
# End Source File
# End Group
# Begin Group "Management"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Management\avtConstantCreatorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Management\avtExpressionEvaluatorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Management\ExprPipelineState.C
# End Source File
# End Group
# Begin Group "Conditional"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtConditionalFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtLogicalAndFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtLogicalNegationFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtLogicalOrFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtTestEqualToFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtTestGreaterThanFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtTestGreaterThanOrEqualToFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtTestLessThanFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtTestLessThanOrEqualToFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Conditional\avtTestNotEqualToFilter.C
# End Source File
# End Group
# Begin Group "Derivations"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Derivations\avtEffectiveTensorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Derivations\avtPrincipalDeviatoricTensorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Derivations\avtPrincipalTensorFilter.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\components\Expressions\Derivations\avtTensorMaximumShearFilter.C
# End Source File
# End Group
# End Target
# End Project
