import os, sys, string

# Write the header
f = open("DatabasePlugins.dsw", "w")
f.write('Microsoft Developer Studio Workspace File, Format Version 6.00\n')
f.write('# WARNING: DO NOT EDIT OR DELETE THIS WORKSPACE FILE!\n')
f.write('\n')

# Here is a project string
Project = \
'###############################################################################\n' \
'\n' \
'Project: \"Silo\"=Silo.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SiloE\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SiloI\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name SiloM\n' \
'    End Project Dependency\n' \
'}}}\n' \
'\n' \
'###############################################################################\n' \
'\n' \
'Project: \"SiloE\"=SiloE.dsp - Package Owner=<4>\n' \
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
'Project: \"SiloM\"=SiloM.dsp - Package Owner=<4>\n' \
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
'Project: \"SiloI\"=SiloI.dsp - Package Owner=<4>\n' \
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
    s = string.replace(Project, 'Silo', project)
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


