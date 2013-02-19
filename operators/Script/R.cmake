
SET(R_LIBG_SOURCES
R/QvisScriptRWidget.C
R/QvisRSyntaxHighlighter.C
)

SET(R_LIBG_MOC_SOURCES
R/QvisScriptRWidget.h
R/QvisRSyntaxHighlighter.h
)

SET(R_LIBE_SOURCES
${VISIT_SOURCE_DIR}/operators/R/avtTMP.C
${VISIT_SOURCE_DIR}/operators/R/avtRFilter.C
${VISIT_SOURCE_DIR}/operators/R/avtRExtremesFilter.C
${VISIT_SOURCE_DIR}/operators/R/RAttributes.C
${VISIT_SOURCE_DIR}/operators/R/ExtremeValueAnalysisAttributes.C
)

LIST(APPEND LIBG_SOURCES ${R_LIBG_SOURCES})
LIST(APPEND LIBG_MOC_SOURCES ${R_LIBG_MOC_SOURCES})
LIST(APPEND LIBE_SOURCES ${R_LIBE_SOURCES})

INCLUDE_DIRECTORIES(R ${VISIT_SOURCE_DIR}/operators/R)
