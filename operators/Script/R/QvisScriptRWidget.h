#ifndef QVIS_SCRIPT_R_WIDGET_H
#define QVIS_SCRIPT_R_WIDGET_H

#include <QvisScriptWidgetInterface.h>

namespace Ui {
    class RForm;
}

class QWidget;

class QvisScriptRWidget : public QvisScriptWidgetInterface
{
    MapNode mapnode;
    QWidget* widget;
    Ui::RForm* form;
public:
    QvisScriptRWidget(QWidget* parent = NULL);
    virtual QWidget*    GetRenderWidget();
    virtual MapNode&    GetMapNode();
    virtual void        SetMapNode(const MapNode& node);
    virtual QString     GetName() { return "R"; }
};

#endif
