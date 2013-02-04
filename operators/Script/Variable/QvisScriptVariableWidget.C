#include <QvisScriptVariableWidget.h>
#include <QLabel>
#include <QvisVariableButton.h>

QvisScriptVariableWidget::QvisScriptVariableWidget(QWidget* parent)
{
    int mask = QvisVariableButton::Scalars |
            QvisVariableButton::Vectors |
            QvisVariableButton::Meshes |
            QvisVariableButton::Materials |
            QvisVariableButton::Subsets |
            QvisVariableButton::Species |
            QvisVariableButton::Curves |
            QvisVariableButton::Tensors |
            QvisVariableButton::SymmetricTensors |
            QvisVariableButton::Labels |
            QvisVariableButton::Arrays;
    variable = new QvisVariableButton(true, true, true, mask, NULL);
}

QWidget*
QvisScriptVariableWidget::GetRenderWidget()
{
    return variable;
}

void QvisScriptVariableWidget::SetMapNode(const MapNode &node)
{
    mapnode = node;

    if(node.HasEntry("variable"))
        variable->setVariable(QString(mapnode["variable"].AsString().c_str()));
}

MapNode& QvisScriptVariableWidget::GetMapNode()
{
    mapnode["variable"] = variable->getVariable().toStdString();
    return mapnode;
}
