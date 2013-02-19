#ifndef QVIS_SCRIPT_VARIABLE_WIDGET_H
#define QVIS_SCRIPT_VARIABLE_WIDGET_H

#include <QvisScriptWidgetInterface.h>

class QvisVariableButton;

class QvisScriptVariableWidget : public QvisScriptWidgetInterface
{
    Q_OBJECT

    MapNode mapnode;
    QvisVariableButton* variable;
public:
    QvisScriptVariableWidget(QWidget* parent = NULL);
    virtual QWidget* GetRenderWidget();
    virtual MapNode&  GetMapNode();
    virtual void      SetMapNode(const MapNode &node);
    virtual QString GetName() { return "Variable"; }
};

#endif
