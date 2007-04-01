@echo off
set MOC=%QTDIR%\bin\moc.exe
set VISIT=%VISITDEVDIR%\visit

echo ************************************************************************
echo Preprocessing VisIt source using %MOC%
echo ...

echo Running moc on the Plugin source
set G=%VISIT%\plots

%MOC% %G%\Boundary\QvisBoundaryPlotWindow.h             -o %G%\Boundary\QvisBoundaryPlotWindow_moc.C
%MOC% %G%\Contour\QvisContourPlotWindow.h               -o %G%\Contour\QvisContourPlotWindow_moc.C
%MOC% %G%\Curve\QvisCurvePlotWindow.h                   -o %G%\Curve\QvisCurvePlotWindow_moc.C
%MOC% %G%\FilledBoundary\QvisFilledBoundaryPlotWindow.h -o %G%\FilledBoundary\QvisFilledBoundaryPlotWindow_moc.C
%MOC% %G%\Label\QvisLabelPlotWindow.h                   -o %G%\Label\QvisLabelPlotWindow_moc.C
%MOC% %G%\Histogram\QvisHistogramPlotWindow.h           -o %G%\Histogram\QvisHistogramPlotWindow_moc.C
%MOC% %G%\Mesh\QvisMeshPlotWindow.h                     -o %G%\Mesh\QvisMeshPlotWindow_moc.C
%MOC% %G%\Pseudocolor\QvisPseudocolorPlotWindow.h       -o %G%\Pseudocolor\QvisPseudocolorPlotWindow_moc.C
%MOC% %G%\Streamline\QvisStreamlinePlotWindow.h         -o %G%\Streamline\QvisStreamlinePlotWindow_moc.C
%MOC% %G%\Subset\QvisSubsetPlotWindow.h                 -o %G%\Subset\QvisSubsetPlotWindow_moc.C
%MOC% %G%\Surface\QvisSurfacePlotWindow.h               -o %G%\Surface\QvisSurfacePlotWindow_moc.C
%MOC% %G%\Tensor\QvisTensorPlotWindow.h                 -o %G%\Tensor\QvisTensorPlotWindow_moc.C
%MOC% %G%\Topology\QvisTopologyPlotWindow.h             -o %G%\Topology\QvisTopologyPlotWindow_moc.C
%MOC% %G%\Truecolor\QvisTruecolorPlotWindow.h           -o %G%\Truecolor\QvisTruecolorPlotWindow_moc.C
%MOC% %G%\Vector\QvisVectorPlotWindow.h                 -o %G%\Vector\QvisVectorPlotWindow_moc.C
%MOC% %G%\Volume\QvisVolumePlotWindow.h                 -o %G%\Volume\QvisVolumePlotWindow_moc.C

echo ...
echo Done.
echo ************************************************************************