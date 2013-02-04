/********************************************************************************
** Form generated from reading UI file 'RFV9422.ui'
**
** Created: Thu Jan 17 16:58:08 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef RFV9422_H
#define RFV9422_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RForm
{
public:
    QGridLayout *gridLayout;
    QTextEdit *code;
    QTableWidget *inputArgs;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addOutput;
    QPushButton *removeOutput;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *addInput;
    QPushButton *removeInput;
    QSpacerItem *verticalSpacer;
    QTableWidget *outputArgs;
    QLabel *label;

    void setupUi(QWidget *RForm)
    {
        if (RForm->objectName().isEmpty())
            RForm->setObjectName(QString::fromUtf8("RForm"));
        RForm->resize(519, 537);
        gridLayout = new QGridLayout(RForm);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        code = new QTextEdit(RForm);
        code->setObjectName(QString::fromUtf8("code"));

        gridLayout->addWidget(code, 2, 1, 1, 2);

        inputArgs = new QTableWidget(RForm);
        if (inputArgs->columnCount() < 2)
            inputArgs->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        inputArgs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        inputArgs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        inputArgs->setObjectName(QString::fromUtf8("inputArgs"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputArgs->sizePolicy().hasHeightForWidth());
        inputArgs->setSizePolicy(sizePolicy);
        inputArgs->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(inputArgs, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(RForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        addOutput = new QPushButton(groupBox_2);
        addOutput->setObjectName(QString::fromUtf8("addOutput"));

        verticalLayout_2->addWidget(addOutput);

        removeOutput = new QPushButton(groupBox_2);
        removeOutput->setObjectName(QString::fromUtf8("removeOutput"));

        verticalLayout_2->addWidget(removeOutput);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addWidget(groupBox_2, 3, 2, 2, 1);

        groupBox = new QGroupBox(RForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addInput = new QPushButton(groupBox);
        addInput->setObjectName(QString::fromUtf8("addInput"));

        verticalLayout->addWidget(addInput);

        removeInput = new QPushButton(groupBox);
        removeInput->setObjectName(QString::fromUtf8("removeInput"));

        verticalLayout->addWidget(removeInput);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 0, 2, 1, 1);

        outputArgs = new QTableWidget(RForm);
        if (outputArgs->columnCount() < 2)
            outputArgs->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        outputArgs->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        outputArgs->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        outputArgs->setObjectName(QString::fromUtf8("outputArgs"));
        sizePolicy.setHeightForWidth(outputArgs->sizePolicy().hasHeightForWidth());
        outputArgs->setSizePolicy(sizePolicy);
        outputArgs->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(outputArgs, 3, 1, 2, 1);

        label = new QLabel(RForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);


        retranslateUi(RForm);

        QMetaObject::connectSlotsByName(RForm);
    } // setupUi

    void retranslateUi(QWidget *RForm)
    {
        RForm->setWindowTitle(QApplication::translate("RForm", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = inputArgs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RForm", "Input Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = inputArgs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RForm", "Input Argument", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        addOutput->setText(QApplication::translate("RForm", "+", 0, QApplication::UnicodeUTF8));
        removeOutput->setText(QApplication::translate("RForm", "-", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        addInput->setText(QApplication::translate("RForm", "+", 0, QApplication::UnicodeUTF8));
        removeInput->setText(QApplication::translate("RForm", "-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = outputArgs->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("RForm", "Output Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = outputArgs->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("RForm", "Output Type", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RForm", "R-Code", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RForm: public Ui_RForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // RFV9422_H
