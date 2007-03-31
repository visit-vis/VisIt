# Microsoft Developer Studio Project File - Name="xmledit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=xmledit - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "xmledit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xmledit.mak" CFG="xmledit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xmledit - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "xmledit - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "xmledit - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\xmledit"
# PROP Intermediate_Dir "Release\xmledit"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "QT_NO_COMPAT" /YX /FD /TP /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib qt-mt302.lib /nologo /subsystem:console /machine:I386 /out:"../../bin/Release/xmledit.exe"

!ELSEIF  "$(CFG)" == "xmledit - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug\xmledit"
# PROP Intermediate_Dir "Debug\xmledit"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "QT_NO_COMPAT" /YX /FD /GZ /TP /c
# SUBTRACT CPP /X /u
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib qt-mt302.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../bin/Debug/xmledit.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "xmledit - Win32 Release"
# Name "xmledit - Win32 Debug"
# Begin Group "moc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEdit_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditAttribute_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditCode_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditConstants_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditEnums_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditFields_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditFunctions_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditIncludes_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditMakefile_moc.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditPlugin_moc.C
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLDocument.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEdit.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditAttribute.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditCode.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditConstants.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditEnums.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditFields.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditFunctions.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditIncludes.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditMain.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditMakefile.C
# End Source File
# Begin Source File

SOURCE=..\..\visit\tools\xmledit\XMLEditPlugin.C
# End Source File
# End Target
# End Project
