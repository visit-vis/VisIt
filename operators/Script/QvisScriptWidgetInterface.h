#ifndef QVIS_SCRIPT_WIDGET_INTERFACE_H
#define QVIS_SCRIPT_WIDGET_INTERFACE_H

#include <QWidget>
#include <MapNode.h>

class QvisScriptWidgetInterface : public QObject
{
public:
    virtual QString     GetName() = 0;
    virtual QWidget*    GetRenderWidget() = 0;
    virtual void        SetMapNode(const MapNode& node)  = 0;
    virtual MapNode&    GetMapNode() = 0;
};

#endif
