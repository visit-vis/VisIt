#include <QvisScriptRWidget.h>
#include <QvisRSyntaxHighlighter.h>

#include "ui_R.h"

QvisScriptRWidget::QvisScriptRWidget(QWidget* parent)
{
    widget = new QWidget();
    form = new Ui::RForm();
    form->setupUi(widget);

    new QvisRSyntaxHighlighter(form->code->document());
}

QWidget*
QvisScriptRWidget::GetRenderWidget()
{
    return widget;
}

MapNode&
QvisScriptRWidget::GetMapNode()
{
    return mapnode;
}

void
QvisScriptRWidget::SetMapNode(const MapNode &node)
{
    mapnode = node;

    //Load R script..
}
