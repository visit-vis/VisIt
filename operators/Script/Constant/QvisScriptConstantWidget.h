#ifndef QVIS_SCRIPT_CONSTANT_WIDGET_H
#define QVIS_SCRIPT_CONSTANT_WIDGET_H

#include <QvisScriptWidgetInterface.h>

class QDoubleSpinBox;
class QvisScriptConstantWidget : public QvisScriptWidgetInterface
{
    MapNode mapnode;
    QDoubleSpinBox* edit;
public:
    QvisScriptConstantWidget(QWidget* parent = NULL);
    virtual QWidget* GetRenderWidget();
    virtual MapNode&  GetMapNode();
    virtual void SetMapNode(const MapNode &node);
    virtual QString GetName() { return "Constant"; }
};

#endif
