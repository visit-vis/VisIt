import os, sys, string

Project = \
"# Microsoft Developer Studio Project File - Name=\"Silo\" - Package Owner=<4>\n"  \
"# Microsoft Developer Studio Generated Build File, Format Version 6.00\n"  \
"# ** DO NOT EDIT **\n"  \
"\n"  \
"# TARGTYPE \"Win32 (x86) Generic Project\" 0x010a\n"  \
"\n"  \
"CFG=Silo - Win32 Debug\n"  \
"!MESSAGE This is not a valid makefile. To build this project using NMAKE,\n"  \
"!MESSAGE use the Export Makefile command and run\n"  \
"!MESSAGE \n"  \
"!MESSAGE NMAKE /f \"Silo.mak\".\n"  \
"!MESSAGE \n"  \
"!MESSAGE You can specify a configuration when running NMAKE\n"  \
"!MESSAGE by defining the macro CFG on the command line. For example:\n"  \
"!MESSAGE \n"  \
"!MESSAGE NMAKE /f \"Silo.mak\" CFG=\"Silo - Win32 Debug\"\n"  \
"!MESSAGE \n"  \
"!MESSAGE Possible choices for configuration are:\n"  \
"!MESSAGE \n"  \
"!MESSAGE \"Silo - Win32 Release\" (based on \"Win32 (x86) Generic Project\")\n"  \
"!MESSAGE \"Silo - Win32 Debug\" (based on \"Win32 (x86) Generic Project\")\n"  \
"!MESSAGE \n"  \
"\n"  \
"# Begin Project\n"  \
"# PROP AllowPerConfigDependencies 0\n"  \
"# PROP Scc_ProjName \"\"\n"  \
"# PROP Scc_LocalPath \"\"\n"  \
"MTL=midl.exe\n"  \
"\n"  \
"!IF  \"$(CFG)\" == \"Silo - Win32 Release\"\n"  \
"\n"  \
"# PROP BASE Use_MFC 0\n"  \
"# PROP BASE Use_Debug_Libraries 0\n"  \
"# PROP BASE Output_Dir \"Release\"\n"  \
"# PROP BASE Intermediate_Dir \"Release\"\n"  \
"# PROP BASE Target_Dir \"\"\n"  \
"# PROP Use_MFC 0\n"  \
"# PROP Use_Debug_Libraries 0\n"  \
"# PROP Output_Dir \"Release\"\n"  \
"# PROP Intermediate_Dir \"Release\"\n"  \
"# PROP Target_Dir \"\"\n"  \
"\n"  \
"!ELSEIF  \"$(CFG)\" == \"Silo - Win32 Debug\"\n"  \
"\n"  \
"# PROP BASE Use_MFC 0\n"  \
"# PROP BASE Use_Debug_Libraries 1\n"  \
"# PROP BASE Output_Dir \"Debug\"\n"  \
"# PROP BASE Intermediate_Dir \"Debug\"\n"  \
"# PROP BASE Target_Dir \"\"\n"  \
"# PROP Use_MFC 0\n"  \
"# PROP Use_Debug_Libraries 1\n"  \
"# PROP Output_Dir \"Debug\"\n"  \
"# PROP Intermediate_Dir \"Debug\"\n"  \
"# PROP Target_Dir \"\"\n"  \
"\n"  \
"!ENDIF \n"  \
"\n"  \
"# Begin Target\n"  \
"\n"  \
"# Name \"Silo - Win32 Release\"\n"  \
"# Name \"Silo - Win32 Debug\"\n"  \
"# End Target\n"  \
"# End Project\n"

IProject = \
"# Microsoft Developer Studio Project File - Name=\"SiloI\" - Package Owner=<4>\n" \
"# Microsoft Developer Studio Generated Build File, Format Version 6.00\n" \
"# ** DO NOT EDIT **\n" \
"\n" \
"# TARGTYPE \"Win32 (x86) Dynamic-Link Library\" 0x0102\n" \
"\n" \
"CFG=SiloI - Win32 Debug\n" \
"!MESSAGE This is not a valid makefile. To build this project using NMAKE,\n" \
"!MESSAGE use the Export Makefile command and run\n" \
"!MESSAGE \n" \
"!MESSAGE NMAKE /f \"SiloI.mak\".\n" \
"!MESSAGE \n" \
"!MESSAGE You can specify a configuration when running NMAKE\n" \
"!MESSAGE by defining the macro CFG on the command line. For example:\n" \
"!MESSAGE \n" \
"!MESSAGE NMAKE /f \"SiloI.mak\" CFG=\"SiloI - Win32 Debug\"\n" \
"!MESSAGE \n" \
"!MESSAGE Possible choices for configuration are:\n" \
"!MESSAGE \n" \
"!MESSAGE \"SiloI - Win32 Release\" (based on \"Win32 (x86) Dynamic-Link Library\")\n" \
"!MESSAGE \"SiloI - Win32 Debug\" (based on \"Win32 (x86) Dynamic-Link Library\")\n" \
"!MESSAGE \n" \
"\n" \
"# Begin Project\n" \
"# PROP AllowPerConfigDependencies 0\n" \
"# PROP Scc_ProjName \"\"\n" \
"# PROP Scc_LocalPath \"\"\n" \
"CPP=cl.exe\n" \
"MTL=midl.exe\n" \
"RSC=rc.exe\n" \
"\n" \
"!IF  \"$(CFG)\" == \"SiloI - Win32 Release\"\n" \
"\n" \
"# PROP BASE Use_MFC 0\n" \
"# PROP BASE Use_Debug_Libraries 0\n" \
"# PROP BASE Output_Dir \"Release\"\n" \
"# PROP BASE Intermediate_Dir \"Release\"\n" \
"# PROP BASE Target_Dir \"\"\n" \
"# PROP Use_MFC 0\n" \
"# PROP Use_Debug_Libraries 0\n" \
"# PROP Output_Dir \"Release\"\n" \
"# PROP Intermediate_Dir \"Release\"\n" \
"# PROP Ignore_Export_Lib 0\n" \
"# PROP Target_Dir \"\"\n" \
"# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D \"WIN32\" /D \"NDEBUG\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"SILOI_EXPORTS\" /YX /FD /c\n" \
"# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I \"..\\..\\visit\\databases\\Silo\" /D \"NDEBUG\" /D \"WIN32\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"GENERAL_PLUGIN_EXPORTS\" /D \"USING_MSVC6\" /YX /FD /TP /c\n" \
"# ADD BASE MTL /nologo /D \"NDEBUG\" /mktyplib203 /win32\n" \
"# ADD MTL /nologo /D \"NDEBUG\" /mktyplib203 /win32\n" \
"# ADD BASE RSC /l 0x409 /d \"NDEBUG\"\n" \
"# ADD RSC /l 0x409 /d \"NDEBUG\"\n" \
"BSC32=bscmake.exe\n" \
"# ADD BASE BSC32 /nologo\n" \
"# ADD BSC32 /nologo\n" \
"LINK32=link.exe\n" \
"# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386\n" \
"# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  plugin.lib /nologo /dll /machine:I386 /out:\"Release/libISiloDatabase.dll\"\n" \
"# Begin Special Build Tool\n" \
"SOURCE=\"$(InputPath)\"\n" \
"PostBuild_Cmds=copy Release\\libISiloDatabase.dll ..\\..\\bin\\Release\\databases\n" \
"# End Special Build Tool\n" \
"\n" \
"!ELSEIF  \"$(CFG)\" == \"SiloI - Win32 Debug\"\n" \
"\n" \
"# PROP BASE Use_MFC 0\n" \
"# PROP BASE Use_Debug_Libraries 1\n" \
"# PROP BASE Output_Dir \"Debug\"\n" \
"# PROP BASE Intermediate_Dir \"Debug\"\n" \
"# PROP BASE Target_Dir \"\"\n" \
"# PROP Use_MFC 0\n" \
"# PROP Use_Debug_Libraries 1\n" \
"# PROP Output_Dir \"Debug\"\n" \
"# PROP Intermediate_Dir \"Debug\"\n" \
"# PROP Ignore_Export_Lib 0\n" \
"# PROP Target_Dir \"\"\n" \
"# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D \"WIN32\" /D \"_DEBUG\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"SILOI_EXPORTS\" /YX /FD /GZ /c\n" \
"# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I \"..\\..\\visit\\databases\\Silo\" /D \"_DEBUG\" /D \"WIN32\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"GENERAL_PLUGIN_EXPORTS\" /D \"USING_MSVC6\" /YX /FD /GZ /TP /c\n" \
"# ADD BASE MTL /nologo /D \"_DEBUG\" /mktyplib203 /win32\n" \
"# ADD MTL /nologo /D \"_DEBUG\" /mktyplib203 /win32\n" \
"# ADD BASE RSC /l 0x409 /d \"_DEBUG\"\n" \
"# ADD RSC /l 0x409 /d \"_DEBUG\"\n" \
"BSC32=bscmake.exe\n" \
"# ADD BASE BSC32 /nologo\n" \
"# ADD BSC32 /nologo\n" \
"LINK32=link.exe\n" \
"# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept\n" \
"# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib plugin.lib /nologo /dll /debug /machine:I386 /out:\"Debug/libISiloDatabase.dll\" /pdbtype:sept\n" \
"# Begin Special Build Tool\n" \
"SOURCE=\"$(InputPath)\"\n" \
"PostBuild_Cmds=copy Debug\\libISiloDatabase.dll ..\\..\\bin\\Debug\\databases\n" \
"# End Special Build Tool\n" \
"\n" \
"!ENDIF \n" \
"\n" \
"# Begin Target\n" \
"\n" \
"# Name \"SiloI - Win32 Release\"\n" \
"# Name \"SiloI - Win32 Debug\"\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\SiloPluginInfo.C\n" \
"# End Source File\n" \
"# End Target\n" \
"# End Project\n"



EProject = \
"# Microsoft Developer Studio Project File - Name=\"SiloE\" - Package Owner=<4>\n" \
"# Microsoft Developer Studio Generated Build File, Format Version 6.00\n" \
"# ** DO NOT EDIT **\n" \
"\n" \
"# TARGTYPE \"Win32 (x86) Dynamic-Link Library\" 0x0102\n" \
"\n" \
"CFG=SiloE - Win32 Debug\n" \
"!MESSAGE This is not a valid makefile. To build this project using NMAKE,\n" \
"!MESSAGE use the Export Makefile command and run\n" \
"!MESSAGE \n" \
"!MESSAGE NMAKE /f \"SiloE.mak\".\n" \
"!MESSAGE \n" \
"!MESSAGE You can specify a configuration when running NMAKE\n" \
"!MESSAGE by defining the macro CFG on the command line. For example:\n" \
"!MESSAGE \n" \
"!MESSAGE NMAKE /f \"SiloE.mak\" CFG=\"SiloE - Win32 Debug\"\n" \
"!MESSAGE \n" \
"!MESSAGE Possible choices for configuration are:\n" \
"!MESSAGE \n" \
"!MESSAGE \"SiloE - Win32 Release\" (based on \"Win32 (x86) Dynamic-Link Library\")\n" \
"!MESSAGE \"SiloE - Win32 Debug\" (based on \"Win32 (x86) Dynamic-Link Library\")\n" \
"!MESSAGE \n" \
"\n" \
"# Begin Project\n" \
"# PROP AllowPerConfigDependencies 0\n" \
"# PROP Scc_ProjName \"\"\n" \
"# PROP Scc_LocalPath \"\"\n" \
"CPP=cl.exe\n" \
"MTL=midl.exe\n" \
"RSC=rc.exe\n" \
"\n" \
"!IF  \"$(CFG)\" == \"SiloE - Win32 Release\"\n" \
"\n" \
"# PROP BASE Use_MFC 0\n" \
"# PROP BASE Use_Debug_Libraries 0\n" \
"# PROP BASE Output_Dir \"Release\"\n" \
"# PROP BASE Intermediate_Dir \"Release\"\n" \
"# PROP BASE Target_Dir \"\"\n" \
"# PROP Use_MFC 0\n" \
"# PROP Use_Debug_Libraries 0\n" \
"# PROP Output_Dir \"Release\"\n" \
"# PROP Intermediate_Dir \"Release\"\n" \
"# PROP Ignore_Export_Lib 0\n" \
"# PROP Target_Dir \"\"\n" \
"# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D \"WIN32\" /D \"NDEBUG\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"SILOE_EXPORTS\" /YX /FD /c\n" \
"# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I \"..\\..\\visit\\databases\\Silo\" /D \"NDEBUG\" /D \"WIN32\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"GENERAL_PLUGIN_EXPORTS\" /D \"ENGINE_PLUGIN_EXPORTS\" /D \"USING_MSVC6\" /YX /FD /TP /c\n" \
"# ADD BASE MTL /nologo /D \"NDEBUG\" /mktyplib203 /win32\n" \
"# ADD MTL /nologo /D \"NDEBUG\" /mktyplib203 /win32\n" \
"# ADD BASE RSC /l 0x409 /d \"NDEBUG\"\n" \
"# ADD RSC /l 0x409 /d \"NDEBUG\"\n" \
"BSC32=bscmake.exe\n" \
"# ADD BASE BSC32 /nologo\n" \
"# ADD BSC32 /nologo\n" \
"LINK32=link.exe\n" \
"# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386\n" \
"# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  state.lib misc.lib plugin.lib pipeline_ser.lib dbatts.lib database_ser.lib avtexceptions.lib vtkCommon.lib /nologo /dll /machine:I386 /out:\"Release/libESiloDatabase_ser.dll\"\n" \
"# Begin Special Build Tool\n" \
"SOURCE=\"$(InputPath)\"\n" \
"PostBuild_Cmds=copy Release\\libESiloDatabase_ser.dll ..\\..\\bin\\Release\\databases\n" \
"# End Special Build Tool\n" \
"\n" \
"!ELSEIF  \"$(CFG)\" == \"SiloE - Win32 Debug\"\n" \
"\n" \
"# PROP BASE Use_MFC 0\n" \
"# PROP BASE Use_Debug_Libraries 1\n" \
"# PROP BASE Output_Dir \"Debug\"\n" \
"# PROP BASE Intermediate_Dir \"Debug\"\n" \
"# PROP BASE Target_Dir \"\"\n" \
"# PROP Use_MFC 0\n" \
"# PROP Use_Debug_Libraries 1\n" \
"# PROP Output_Dir \"Debug\"\n" \
"# PROP Intermediate_Dir \"Debug\"\n" \
"# PROP Ignore_Export_Lib 0\n" \
"# PROP Target_Dir \"\"\n" \
"# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D \"WIN32\" /D \"_DEBUG\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"SILOE_EXPORTS\" /YX /FD /GZ /c\n" \
"# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I \"..\\..\\visit\\databases\\Silo\" /D \"_DEBUG\" /D \"WIN32\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"GENERAL_PLUGIN_EXPORTS\" /D \"ENGINE_PLUGIN_EXPORTS\" /D \"USING_MSVC6\" /YX /FD /GZ /TP /c\n" \
"# ADD BASE MTL /nologo /D \"_DEBUG\" /mktyplib203 /win32\n" \
"# ADD MTL /nologo /D \"_DEBUG\" /mktyplib203 /win32\n" \
"# ADD BASE RSC /l 0x409 /d \"_DEBUG\"\n" \
"# ADD RSC /l 0x409 /d \"_DEBUG\"\n" \
"BSC32=bscmake.exe\n" \
"# ADD BASE BSC32 /nologo\n" \
"# ADD BSC32 /nologo\n" \
"LINK32=link.exe\n" \
"# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept\n" \
"# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib pipeline_ser.lib dbatts.lib database_ser.lib avtexceptions.lib vtkCommon.lib /nologo /dll /debug /machine:I386 /out:\"Debug/libESiloDatabase_ser.dll\" /pdbtype:sept\n" \
"# Begin Special Build Tool\n" \
"SOURCE=\"$(InputPath)\"\n" \
"PostBuild_Cmds=copy Debug\\libESiloDatabase_ser.dll ..\\..\\bin\\Debug\\databases\n" \
"# End Special Build Tool\n" \
"\n" \
"!ENDIF \n" \
"\n" \
"# Begin Target\n" \
"\n" \
"# Name \"SiloE - Win32 Release\"\n" \
"# Name \"SiloE - Win32 Debug\"\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\avtSiloFileFormat.C\n" \
"# End Source File\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\SiloCommonPluginInfo.C\n" \
"# End Source File\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\SiloEnginePluginInfo.C\n" \
"# End Source File\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\SiloPluginInfo.C\n" \
"# End Source File\n" \
"# End Target\n" \
"# End Project\n"



MProject = \
"# Microsoft Developer Studio Project File - Name=\"SiloM\" - Package Owner=<4>\n" \
"# Microsoft Developer Studio Generated Build File, Format Version 6.00\n" \
"# ** DO NOT EDIT **\n" \
"\n" \
"# TARGTYPE \"Win32 (x86) Dynamic-Link Library\" 0x0102\n" \
"\n" \
"CFG=SiloM - Win32 Debug\n" \
"!MESSAGE This is not a valid makefile. To build this project using NMAKE,\n" \
"!MESSAGE use the Export Makefile command and run\n" \
"!MESSAGE \n" \
"!MESSAGE NMAKE /f \"SiloM.mak\".\n" \
"!MESSAGE \n" \
"!MESSAGE You can specify a configuration when running NMAKE\n" \
"!MESSAGE by defining the macro CFG on the command line. For example:\n" \
"!MESSAGE \n" \
"!MESSAGE NMAKE /f \"SiloM.mak\" CFG=\"SiloM - Win32 Debug\"\n" \
"!MESSAGE \n" \
"!MESSAGE Possible choices for configuration are:\n" \
"!MESSAGE \n" \
"!MESSAGE \"SiloM - Win32 Release\" (based on \"Win32 (x86) Dynamic-Link Library\")\n" \
"!MESSAGE \"SiloM - Win32 Debug\" (based on \"Win32 (x86) Dynamic-Link Library\")\n" \
"!MESSAGE \n" \
"\n" \
"# Begin Project\n" \
"# PROP AllowPerConfigDependencies 0\n" \
"# PROP Scc_ProjName \"\"\n" \
"# PROP Scc_LocalPath \"\"\n" \
"CPP=cl.exe\n" \
"MTL=midl.exe\n" \
"RSC=rc.exe\n" \
"\n" \
"!IF  \"$(CFG)\" == \"SiloM - Win32 Release\"\n" \
"\n" \
"# PROP BASE Use_MFC 0\n" \
"# PROP BASE Use_Debug_Libraries 0\n" \
"# PROP BASE Output_Dir \"Release\"\n" \
"# PROP BASE Intermediate_Dir \"Release\"\n" \
"# PROP BASE Target_Dir \"\"\n" \
"# PROP Use_MFC 0\n" \
"# PROP Use_Debug_Libraries 0\n" \
"# PROP Output_Dir \"Release\"\n" \
"# PROP Intermediate_Dir \"Release\"\n" \
"# PROP Ignore_Export_Lib 0\n" \
"# PROP Target_Dir \"\"\n" \
"# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D \"WIN32\" /D \"NDEBUG\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"SILOM_EXPORTS\" /YX /FD /c\n" \
"# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I \"..\\..\\visit\\databases\\Silo\" /D \"NDEBUG\" /D \"WIN32\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"GENERAL_PLUGIN_EXPORTS\" /D \"MDSERVER_PLUGIN_EXPORTS\" /D \"USING_MSVC6\" /YX /FD /TP /c\n" \
"# ADD BASE MTL /nologo /D \"NDEBUG\" /mktyplib203 /win32\n" \
"# ADD MTL /nologo /D \"NDEBUG\" /mktyplib203 /win32\n" \
"# ADD BASE RSC /l 0x409 /d \"NDEBUG\"\n" \
"# ADD RSC /l 0x409 /d \"NDEBUG\"\n" \
"BSC32=bscmake.exe\n" \
"# ADD BASE BSC32 /nologo\n" \
"# ADD BSC32 /nologo\n" \
"LINK32=link.exe\n" \
"# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386\n" \
"# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib pipeline_ser.lib dbatts.lib database_ser.lib avtexceptions.lib vtkCommon.lib /nologo /dll /machine:I386 /out:\"Release/libMSiloDatabase.dll\"\n" \
"# Begin Special Build Tool\n" \
"SOURCE=\"$(InputPath)\"\n" \
"PostBuild_Cmds=copy Release\\libMSiloDatabase.dll ..\\..\\bin\\Release\\databases\n" \
"# End Special Build Tool\n" \
"\n" \
"!ELSEIF  \"$(CFG)\" == \"SiloM - Win32 Debug\"\n" \
"\n" \
"# PROP BASE Use_MFC 0\n" \
"# PROP BASE Use_Debug_Libraries 1\n" \
"# PROP BASE Output_Dir \"Debug\"\n" \
"# PROP BASE Intermediate_Dir \"Debug\"\n" \
"# PROP BASE Target_Dir \"\"\n" \
"# PROP Use_MFC 0\n" \
"# PROP Use_Debug_Libraries 1\n" \
"# PROP Output_Dir \"Debug\"\n" \
"# PROP Intermediate_Dir \"Debug\"\n" \
"# PROP Ignore_Export_Lib 0\n" \
"# PROP Target_Dir \"\"\n" \
"# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D \"WIN32\" /D \"_DEBUG\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"SILOM_EXPORTS\" /YX /FD /GZ /c\n" \
"# ADD CPP /nologo /G6 /MDd /W3 /Gm /GX /ZI /Od /I \"..\\..\\visit\\databases\\Silo\" /D \"_DEBUG\" /D \"WIN32\" /D \"_WINDOWS\" /D \"_MBCS\" /D \"_USRDLL\" /D \"GENERAL_PLUGIN_EXPORTS\" /D \"MDSERVER_PLUGIN_EXPORTS\" /D \"USING_MSVC6\" /YX /FD /GZ /TP /c\n" \
"# ADD BASE MTL /nologo /D \"_DEBUG\" /mktyplib203 /win32\n" \
"# ADD MTL /nologo /D \"_DEBUG\" /mktyplib203 /win32\n" \
"# ADD BASE RSC /l 0x409 /d \"_DEBUG\"\n" \
"# ADD RSC /l 0x409 /d \"_DEBUG\"\n" \
"BSC32=bscmake.exe\n" \
"# ADD BASE BSC32 /nologo\n" \
"# ADD BSC32 /nologo\n" \
"LINK32=link.exe\n" \
"# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept\n" \
"# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib state.lib misc.lib plugin.lib pipeline_ser.lib dbatts.lib database_ser.lib avtexceptions.lib vtkCommon.lib /nologo /dll /debug /machine:I386 /out:\"Debug/libMSiloDatabase.dll\" /pdbtype:sept\n" \
"# Begin Special Build Tool\n" \
"SOURCE=\"$(InputPath)\"\n" \
"PostBuild_Cmds=copy Debug\\libMSiloDatabase.dll ..\\..\\bin\\Debug\\databases\n" \
"# End Special Build Tool\n" \
"\n" \
"!ENDIF \n" \
"\n" \
"# Begin Target\n" \
"\n" \
"# Name \"SiloM - Win32 Release\"\n" \
"# Name \"SiloM - Win32 Debug\"\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\avtSiloFileFormat.C\n" \
"# End Source File\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\SiloCommonPluginInfo.C\n" \
"# End Source File\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\SiloMDServerPluginInfo.C\n" \
"# End Source File\n" \
"# Begin Source File\n" \
"\n" \
"SOURCE=..\\..\\visit\\databases\\Silo\\SiloPluginInfo.C\n" \
"# End Source File\n" \
"# End Target\n" \
"# End Project\n"


#
# Now get the command line for the name of the plugin project files to create.
#
if(len(sys.argv) < 2):
    print "Usage: databaseprojectmaker pluginname\n"
    sys.exit(0)

pluginName = sys.argv[1]

#
# Create the top level directory and go into it.
#
s = string.replace(Project, "Silo", pluginName)
pname = '%s.dsp' % pluginName
f = open(pname, 'w')
f.write(s)
f.close()

#
# Create the I project
#
d = '%sI' % pluginName
s = string.replace(IProject, "Silo", pluginName)
pname = '%sI.dsp' % pluginName
f = open(pname, 'w')
f.write(s)
f.close()

#
# Create the E project
#
d = '%sE' % pluginName
s = string.replace(EProject, "Silo", pluginName)
pname = '%sE.dsp' % pluginName
f = open(pname, 'w')
f.write(s)
f.close()

#
# Create the M project
#
d = '%sM' % pluginName
s = string.replace(MProject, "Silo", pluginName)
pname = '%sM.dsp' % pluginName
f = open(pname, 'w')
f.write(s)
f.close()