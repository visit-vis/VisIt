
SET(PYTHON_LIBG_SOURCES
Python/QvisScriptPythonWidget.C
${VISIT_INCLUDE_DIR}/gui/QvisPythonSyntaxHighlighter.C
)

SET(PYTHON_LIBG_MOC_SOURCES
Python/QvisScriptPythonWidget.h
${VISIT_INCLUDE_DIR}/gui/QvisPythonSyntaxHighlighter.h
)

LIST(APPEND LIBG_SOURCES ${PYTHON_LIBG_SOURCES})
LIST(APPEND LIBG_MOC_SOURCES ${PYTHON_LIBG_MOC_SOURCES})


INCLUDE_DIRECTORIES(Python)
