import os, sys, string

# Write the header
f = open("PlotPlugins.dsw", "w")
f.write('Microsoft Developer Studio Workspace File, Format Version 6.00\n')
f.write('# WARNING: DO NOT EDIT OR DELETE THIS WORKSPACE FILE!\n')
f.write('\n')

# Here is a project string
Project = \
'###############################################################################\n' \
'\n' \
'Project: \"Contour\"=.\\Contour.dsp - Package Owner=<4>\n' \
'\n' \
'Package=<5>\n' \
'{{{\n' \
'}}}\n' \
'\n' \
'Package=<4>\n' \
'{{{\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name ContourE\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name ContourG\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name ContourI\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name ContourS\n' \
'    End Project Dependency\n' \
'    Begin Project Dependency\n' \
'    Project_Dep_Name ContourV\n' \
'    End Project Dependency\n' \
'}}}\n' \
'\n' \
'###############################################################################\n' \
'\n' \
'Project: \"ContourE\"=.\ContourE.dsp - Package Owner=<4>\n' \
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
'Project: \"ContourG\"=.\ContourG.dsp - Package Owner=<4>\n' \
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
'Project: \"ContourI\"=.\ContourI.dsp - Package Owner=<4>\n' \
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
'Project: \"ContourS\"=.\ContourS.dsp - Package Owner=<4>\n' \
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
'Project: \"ContourV\"=.\ContourV.dsp - Package Owner=<4>\n' \
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
    s = string.replace(Project, 'Contour', project)
    # Write the project to the file.
    f.write(s)

f.write('###############################################################################\n')
f.write('\n')
f.write('Project: \"_TOP_LEVEL\"=.\_TOP_LEVEL.dsp - Package Owner=<4>\n')
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
