@echo off
set MOC=%QTDIR%\bin\moc.exe
set VISIT=%VISITDEVDIR%\visit
set HEADERS=%VISITDEVDIR%\include\tools

echo ************************************************************************
echo Preprocessing silex source using %MOC%
echo ...

echo Running moc on the silex source
set S=%VISIT%\tools\silex

%MOC% %HEADERS%\Explorer.h        -o %S%\Explorer_moc.C
%MOC% %HEADERS%\SiloArrayView.h   -o %S%\SiloArrayView_moc.C
%MOC% %HEADERS%\SiloDirTreeView.h -o %S%\SiloDirTreeView_moc.C
%MOC% %HEADERS%\SiloDirView.h     -o %S%\SiloDirView_moc.C
%MOC% %HEADERS%\SiloObjectView.h  -o %S%\SiloObjectView_moc.C
%MOC% %HEADERS%\SiloValueView.h   -o %S%\SiloValueView_moc.C
%MOC% %HEADERS%\SiloView.h        -o %S%\SiloView_moc.C


echo Running moc on the xmledit source
set X=%VISIT%\tools\xmledit

%MOC% %HEADERS%\XMLEdit.h          -o %X%\XMLEdit_moc.C
%MOC% %HEADERS%\XMLEditAttribute.h -o %X%\XMLEditAttribute_moc.C
%MOC% %HEADERS%\XMLEditPlugin.h    -o %X%\XMLEditPlugin_moc.C
%MOC% %HEADERS%\XMLEditEnums.h     -o %X%\XMLEditEnums_moc.C
%MOC% %HEADERS%\XMLEditFields.h    -o %X%\XMLEditFields_moc.C
%MOC% %HEADERS%\XMLEditFunctions.h -o %X%\XMLEditFunctions_moc.C
%MOC% %HEADERS%\XMLEditCode.h      -o %X%\XMLEditCode_moc.C
%MOC% %HEADERS%\XMLEditConstants.h -o %X%\XMLEditConstants_moc.C
%MOC% %HEADERS%\XMLEditIncludes.h  -o %X%\XMLEditIncludes_moc.C
%MOC% %HEADERS%\XMLEditMakefile.h  -o %X%\XMLEditMakefile_moc.C

echo ...
echo Done.
echo ************************************************************************