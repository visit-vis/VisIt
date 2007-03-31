import os, sys, string

# Write the header
f = open("OperatorPlugins.dsw", "w")
f.write('Microsoft Developer Studio Workspace File, Format Version 6.00\n')
f.write('# WARNING: DO NOT EDIT OR DELETE THIS WORKSPACE FILE!\n')
f.write('\n')

# Here is a project string
Project = \
'###############################################################################\n' \
'\n' \
'Project: \"Slice\"=.\\Slice.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SliceE\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SliceG\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SliceI\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SliceS\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SliceV\n' \
'    End Project Dependency\n' \
'}}}\n' \
'\n' \
'###############################################################################\n' \
'\n' \
'Project: \"SliceE\"=.\\SliceE.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'###############################################################################\n' \
'\n' \
'Project: \"SliceG\"=.\\SliceG.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'###############################################################################\n' \
'\n' \
'Project: \"SliceI\"=.\\SliceI.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'###############################################################################\n' \
'\n' \
'Project: \"SliceS\"=.\\SliceS.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'###############################################################################\n' \
'\n' \
'Project: \"SliceV\"=.\\SliceV.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'}}}\n' \
'\n'

# Write each project that was mentioned on the command line to the workspace file.
for project in sys.argv[1:]:
    # Replace the project string.
    s = string.replace(Project, 'Slice', project)
    # Write the project to the file.
    f.write(s)

f.write('###############################################################################\n')
f.write('\n')
f.write('Project: \"_TOP_LEVEL\"=.\\_TOP_LEVEL.dsp - Package Owner=<4>\n')
f.write('\n')
f.write('Package=<5>\n')
f.write('{{{\n')
f.write('}}}\n')
f.write('\n')
f.write('Package=<4>\n')
f.write('{{{\n')
# Write another dependency
for project in sys.argv[1:]:
    f.write('    Begin Project Dependency\n')
    f.write('    Project_Dep_Name %s\n' % project)
    f.write('    End Project Dependency\n')
f.write('}}}\n')
f.write('\n')
f.write('###############################################################################\n')
f.write('\n')
f.write('Global:\n')
f.write('\n')
f.write('Package=<5>\n')
f.write('{{{\n')
f.write('}}}\n')
f.write('\n')
f.write('Package=<3>\n')
f.write('{{{\n')
f.write('}}}\n')
f.write('\n')
f.write('###############################################################################\n')
f.close()


# Create the runmoc batch file
f = open("runoperatormoc.bat", "w")
f.write('@echo off\n')
f.write('set MOC=%QTDIR%\\bin\\moc.exe\n')
f.write('set VISIT=%VISITDEVDIR%\\visit\n')
f.write('echo ***********************************************************************\n')
f.write('echo Preprocessing VisIt operator source using %MOC%\n')
f.write('echo ...\n')
f.write('echo Running moc on the operator source\n')
f.write('set O=%VISIT%\\operators\n')
for project in sys.argv[1:]:
    f.write('%%MOC%% %%O%%\\%s\Qvis%sWindow.h -o %%O%%\\%s\\Qvis%sWindow_moc.C\n' % (project, project, project, project))
f.write('echo ...\n')
f.write('echo Done.\n')
f.write('echo ***********************************************************************\n')
f.close()

