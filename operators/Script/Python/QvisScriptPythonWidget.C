#include <QvisScriptPythonWidget.h>
#include <QvisPythonSyntaxHighlighter.h>
#include "ui_Python.h"

QvisScriptPythonWidget::QvisScriptPythonWidget(QWidget *parent)
{
    widget = new QWidget();
    form = new Ui::PythonForm();
    form->setupUi(widget);

    new QvisPythonSyntaxHighlighter(form->code->document());
}
QWidget*
QvisScriptPythonWidget::GetRenderWidget()
{
    QWidget* widget = new QWidget();
    Ui::PythonForm* form = new Ui::PythonForm();
    form->setupUi(widget);
    new QvisPythonSyntaxHighlighter(form->code->document());

    return widget;
}

MapNode&
QvisScriptPythonWidget::GetMapNode()
{
    return mapnode;
}

void
QvisScriptPythonWidget::SetMapNode(const MapNode &node)
{
    mapnode = node;

    //load Python script..
}
