@echo off
set MOC=%QTDIR%\bin\moc.exe
set VISIT=%VISITDEVDIR%\visit
echo ***********************************************************************
echo Preprocessing VisIt operator source using %MOC%
echo ...
echo Running moc on the operator source
set O=%VISIT%\operators
%MOC% %O%\Box\QvisBoxWindow.h -o %O%\Box\QvisBoxWindow_moc.C
%MOC% %O%\Clip\QvisClipWindow.h -o %O%\Clip\QvisClipWindow_moc.C
%MOC% %O%\Cone\QvisConeWindow.h -o %O%\Cone\QvisConeWindow_moc.C
%MOC% %O%\Context\QvisContextWindow.h -o %O%\Context\QvisContextWindow_moc.C
%MOC% %O%\Cylinder\QvisCylinderWindow.h -o %O%\Cylinder\QvisCylinderWindow_moc.C
%MOC% %O%\Displace\QvisDisplaceWindow.h -o %O%\Displace\QvisDisplaceWindow_moc.C
%MOC% %O%\IndexSelect\QvisIndexSelectWindow.h -o %O%\IndexSelect\QvisIndexSelectWindow_moc.C
%MOC% %O%\InverseGhostZone\QvisInverseGhostZoneWindow.h -o %O%\InverseGhostZone\QvisInverseGhostZoneWindow_moc.C
%MOC% %O%\IsoSurface\QvisIsoSurfaceWindow.h -o %O%\IsoSurface\QvisIsoSurfaceWindow_moc.C
%MOC% %O%\Lineout\QvisLineoutWindow.h -o %O%\Lineout\QvisLineoutWindow_moc.C
%MOC% %O%\OnionPeel\QvisOnionPeelWindow.h -o %O%\OnionPeel\QvisOnionPeelWindow_moc.C
%MOC% %O%\Reflect\QvisReflectWindow.h -o %O%\Reflect\QvisReflectWindow_moc.C
%MOC% %O%\Reflect\QvisReflectWidget.h -o %O%\Reflect\QvisReflectWidget_moc.C
%MOC% %O%\SiloDump\QvisSiloDumpWindow.h -o %O%\SiloDump\QvisSiloDumpWindow_moc.C
%MOC% %O%\Slice\QvisSliceWindow.h -o %O%\Slice\QvisSliceWindow_moc.C
%MOC% %O%\SphereSlice\QvisSphereSliceWindow.h -o %O%\SphereSlice\QvisSphereSliceWindow_moc.C
%MOC% %O%\ThreeSlice\QvisThreeSliceWindow.h -o %O%\ThreeSlice\QvisThreeSliceWindow_moc.C
%MOC% %O%\Threshold\QvisThresholdWindow.h -o %O%\Threshold\QvisThresholdWindow_moc.C
%MOC% %O%\Transform\QvisTransformWindow.h -o %O%\Transform\QvisTransformWindow_moc.C
echo ...
echo Done.
echo ***********************************************************************
