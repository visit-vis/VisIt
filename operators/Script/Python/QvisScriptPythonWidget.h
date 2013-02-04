#ifndef QVIS_SCRIPT_PYTHON_WIDGET_H
#define QVIS_SCRIPT_PYTHON_WIDGET_H

#include <QvisScriptWidgetInterface.h>

class QWidget;
namespace Ui {
    class PythonForm;
}
class QvisScriptPythonWidget : public QvisScriptWidgetInterface
{
    MapNode mapnode;
    QWidget* widget;
    Ui::PythonForm* form;
public:
    QvisScriptPythonWidget(QWidget* parent = NULL);
    virtual QWidget*    GetRenderWidget();
    virtual MapNode&    GetMapNode();
    virtual void        SetMapNode(const MapNode &node);
    virtual QString     GetName() { return "Python"; }
};

#endif
