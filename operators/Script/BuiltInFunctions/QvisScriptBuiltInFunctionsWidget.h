#ifndef QVIS_SCRIPT_BUILTIN_FUNCTIONS_WIDGET_H
#define QVIS_SCRIPT_BUILTIN_FUNCTIONS_WIDGET_H

#include <QvisScriptWidgetInterface.h>

class QvisScriptBuiltinFunctionsWidget : public QvisScriptWidgetInterface
{
    MapNode mapnode;
public:
    QvisScriptBuiltinFunctionsWidget(QWidget* parent = NULL) {}
    virtual QWidget* GetRenderWidget();
    virtual MapNode& GetMapNode();
    virtual void SetMapNode(const MapNode &node);
    virtual QString GetName() { return "BuiltInFunctions"; }
};

#endif
