/********************************************************************************
** Form generated from reading UI file 'ScriptrB1800.ui'
**
** Created: Thu Jan 31 11:49:00 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SCRIPTRB1800_H
#define SCRIPTRB1800_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QComboBox *scriptType;
    QLineEdit *scriptName;
    QLabel *label;
    QCheckBox *isScriptExecutable;
    QPushButton *removeScript;
    QPushButton *addScript;
    QTreeWidget *scripts;
    QTabWidget *scriptWidget;
    QWidget *entryWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QGroupBox *childWidget;
    QWidget *graphWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *addGraphName;
    QComboBox *addGraphScripts;
    QPushButton *addGraphNode;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *connectGraphId;
    QComboBox *connectGraphOutput;
    QLabel *label_5;
    QComboBox *connectGraphInput;
    QPushButton *pushButton_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QComboBox *removeGraphId;
    QPushButton *removeGraphNode;
    QWidget *codeWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *finalOutput;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(840, 551);
        gridLayout = new QGridLayout(Form);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        scriptType = new QComboBox(Form);
        scriptType->setObjectName(QString::fromUtf8("scriptType"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scriptType->sizePolicy().hasHeightForWidth());
        scriptType->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(scriptType, 2, 1, 1, 1);

        scriptName = new QLineEdit(Form);
        scriptName->setObjectName(QString::fromUtf8("scriptName"));
        sizePolicy.setHeightForWidth(scriptName->sizePolicy().hasHeightForWidth());
        scriptName->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(scriptName, 1, 1, 1, 1);

        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label, 2, 0, 1, 1);

        isScriptExecutable = new QCheckBox(Form);
        isScriptExecutable->setObjectName(QString::fromUtf8("isScriptExecutable"));
        isScriptExecutable->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(isScriptExecutable, 0, 2, 1, 1);

        removeScript = new QPushButton(Form);
        removeScript->setObjectName(QString::fromUtf8("removeScript"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(removeScript->sizePolicy().hasHeightForWidth());
        removeScript->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(removeScript, 2, 2, 1, 1);

        addScript = new QPushButton(Form);
        addScript->setObjectName(QString::fromUtf8("addScript"));
        sizePolicy2.setHeightForWidth(addScript->sizePolicy().hasHeightForWidth());
        addScript->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(addScript, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_4, 4, 0, 2, 1);

        scripts = new QTreeWidget(Form);
        scripts->setObjectName(QString::fromUtf8("scripts"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scripts->sizePolicy().hasHeightForWidth());
        scripts->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(scripts, 3, 0, 1, 1);

        scriptWidget = new QTabWidget(Form);
        scriptWidget->setObjectName(QString::fromUtf8("scriptWidget"));
        entryWidget = new QWidget();
        entryWidget->setObjectName(QString::fromUtf8("entryWidget"));
        verticalLayout_2 = new QVBoxLayout(entryWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_4 = new QGroupBox(entryWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        childWidget = new QGroupBox(groupBox_4);
        childWidget->setObjectName(QString::fromUtf8("childWidget"));

        gridLayout_2->addWidget(childWidget, 2, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_4);

        scriptWidget->addTab(entryWidget, QString());
        graphWidget = new QWidget();
        graphWidget->setObjectName(QString::fromUtf8("graphWidget"));
        verticalLayout_3 = new QVBoxLayout(graphWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(graphWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_3->addWidget(widget);

        frame_3 = new QFrame(graphWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setFrameShape(QFrame::NoFrame);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        addGraphName = new QLineEdit(frame_3);
        addGraphName->setObjectName(QString::fromUtf8("addGraphName"));

        horizontalLayout->addWidget(addGraphName);

        addGraphScripts = new QComboBox(frame_3);
        addGraphScripts->setObjectName(QString::fromUtf8("addGraphScripts"));

        horizontalLayout->addWidget(addGraphScripts);

        addGraphNode = new QPushButton(frame_3);
        addGraphNode->setObjectName(QString::fromUtf8("addGraphNode"));

        horizontalLayout->addWidget(addGraphNode);


        verticalLayout_3->addWidget(frame_3);

        frame = new QFrame(graphWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        connectGraphId = new QLineEdit(frame);
        connectGraphId->setObjectName(QString::fromUtf8("connectGraphId"));

        horizontalLayout_2->addWidget(connectGraphId);

        connectGraphOutput = new QComboBox(frame);
        connectGraphOutput->setObjectName(QString::fromUtf8("connectGraphOutput"));

        horizontalLayout_2->addWidget(connectGraphOutput);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        connectGraphInput = new QComboBox(frame);
        connectGraphInput->setObjectName(QString::fromUtf8("connectGraphInput"));

        horizontalLayout_2->addWidget(connectGraphInput);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_3->addWidget(frame);

        frame_2 = new QFrame(graphWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_6);

        removeGraphId = new QComboBox(frame_2);
        removeGraphId->setObjectName(QString::fromUtf8("removeGraphId"));

        horizontalLayout_3->addWidget(removeGraphId);

        removeGraphNode = new QPushButton(frame_2);
        removeGraphNode->setObjectName(QString::fromUtf8("removeGraphNode"));
        sizePolicy2.setHeightForWidth(removeGraphNode->sizePolicy().hasHeightForWidth());
        removeGraphNode->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(removeGraphNode);


        verticalLayout_3->addWidget(frame_2);

        scriptWidget->addTab(graphWidget, QString());
        codeWidget = new QWidget();
        codeWidget->setObjectName(QString::fromUtf8("codeWidget"));
        verticalLayout = new QVBoxLayout(codeWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        finalOutput = new QTextEdit(codeWidget);
        finalOutput->setObjectName(QString::fromUtf8("finalOutput"));

        verticalLayout->addWidget(finalOutput);

        scriptWidget->addTab(codeWidget, QString());

        gridLayout->addWidget(scriptWidget, 0, 1, 9, 1);


        retranslateUi(Form);

        scriptWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Name:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Type:", 0, QApplication::UnicodeUTF8));
        isScriptExecutable->setText(QApplication::translate("Form", "Exec:", 0, QApplication::UnicodeUTF8));
        removeScript->setText(QApplication::translate("Form", "-", 0, QApplication::UnicodeUTF8));
        addScript->setText(QApplication::translate("Form", "+", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = scripts->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Form", "Scripts", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        childWidget->setTitle(QString());
        scriptWidget->setTabText(scriptWidget->indexOf(entryWidget), QApplication::translate("Form", "Entry", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "Add:", 0, QApplication::UnicodeUTF8));
        addGraphNode->setText(QApplication::translate("Form", "+", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "Connect Id:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form", "- Connect To -", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form", "+", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form", "Remove:", 0, QApplication::UnicodeUTF8));
        removeGraphNode->setText(QApplication::translate("Form", "-", 0, QApplication::UnicodeUTF8));
        scriptWidget->setTabText(scriptWidget->indexOf(graphWidget), QApplication::translate("Form", "Graph", 0, QApplication::UnicodeUTF8));
        scriptWidget->setTabText(scriptWidget->indexOf(codeWidget), QApplication::translate("Form", "Code", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SCRIPTRB1800_H
