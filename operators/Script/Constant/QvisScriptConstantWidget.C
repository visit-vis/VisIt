#include <QvisScriptConstantWidget.h>
#include <QLabel>
#include <QDoubleSpinBox>

QvisScriptConstantWidget::QvisScriptConstantWidget(QWidget*)
{
    edit = new QDoubleSpinBox();
    edit->setValue(0);
}

QWidget*
QvisScriptConstantWidget::GetRenderWidget()
{
    return edit;
}

MapNode&
QvisScriptConstantWidget::GetMapNode()
{
    mapnode["constant"] = edit->value();
    return mapnode;
}

void
QvisScriptConstantWidget::SetMapNode(const MapNode &node)
{
    mapnode = node;
}
