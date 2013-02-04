#include <QvisScriptBuiltInFunctionsWidget.h>
#include <QLabel>

QWidget*
QvisScriptBuiltinFunctionsWidget::GetRenderWidget()
{
    return new QLabel("Built In Functions ...");
}

MapNode&
QvisScriptBuiltinFunctionsWidget::GetMapNode()
{
    return mapnode;
}

void
QvisScriptBuiltinFunctionsWidget::SetMapNode(const MapNode &node)
{
    mapnode = node;
}
