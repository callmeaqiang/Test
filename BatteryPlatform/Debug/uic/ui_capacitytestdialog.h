/********************************************************************************
** Form generated from reading UI file 'capacitytestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPACITYTESTDIALOG_H
#define UI_CAPACITYTESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CapacityTestDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_testname;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label;
    QLineEdit *lineEdit_chargeVoltage;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QLineEdit *lineEdit_chargeCurrent;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *lineEdit_dischargeCurrent;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_17;
    QLineEdit *lineEdit_cycles;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *CapacityTestDialog)
    {
        if (CapacityTestDialog->objectName().isEmpty())
            CapacityTestDialog->setObjectName(QStringLiteral("CapacityTestDialog"));
        CapacityTestDialog->resize(414, 308);
        CapacityTestDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"		\n"
"	background-color: rgb(80, 80, 80);\n"
"    border-radius: 8px;\n"
"    padding: 10px 10px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 24px;\n"
"    margin: 8px 4px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {   \n"
"	\n"
"	background-color: rgb(0, 0, 0);\n"
"}\n"
"QPushButton:pressed {\n"
"    padding-left:13px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:13px;\n"
"}\n"
"QDialog#CapacityTestDialog{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(CapacityTestDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(CapacityTestDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_testname = new QLineEdit(CapacityTestDialog);
        lineEdit_testname->setObjectName(QStringLiteral("lineEdit_testname"));
        lineEdit_testname->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(lineEdit_testname);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(CapacityTestDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(8);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_15->addWidget(label);

        lineEdit_chargeVoltage = new QLineEdit(groupBox);
        lineEdit_chargeVoltage->setObjectName(QStringLiteral("lineEdit_chargeVoltage"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_chargeVoltage->sizePolicy().hasHeightForWidth());
        lineEdit_chargeVoltage->setSizePolicy(sizePolicy1);
        lineEdit_chargeVoltage->setMinimumSize(QSize(140, 0));
        lineEdit_chargeVoltage->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_15->addWidget(lineEdit_chargeVoltage);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);

        horizontalLayout_15->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_4->addWidget(label_15);

        lineEdit_chargeCurrent = new QLineEdit(groupBox);
        lineEdit_chargeCurrent->setObjectName(QStringLiteral("lineEdit_chargeCurrent"));
        sizePolicy1.setHeightForWidth(lineEdit_chargeCurrent->sizePolicy().hasHeightForWidth());
        lineEdit_chargeCurrent->setSizePolicy(sizePolicy1);
        lineEdit_chargeCurrent->setMinimumSize(QSize(140, 0));
        lineEdit_chargeCurrent->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_4->addWidget(lineEdit_chargeCurrent);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_13);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_5->addWidget(label_16);

        lineEdit_dischargeCurrent = new QLineEdit(groupBox);
        lineEdit_dischargeCurrent->setObjectName(QStringLiteral("lineEdit_dischargeCurrent"));
        sizePolicy1.setHeightForWidth(lineEdit_dischargeCurrent->sizePolicy().hasHeightForWidth());
        lineEdit_dischargeCurrent->setSizePolicy(sizePolicy1);
        lineEdit_dischargeCurrent->setMinimumSize(QSize(140, 0));
        lineEdit_dischargeCurrent->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_5->addWidget(lineEdit_dischargeCurrent);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_14);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_6->addWidget(label_17);

        lineEdit_cycles = new QLineEdit(groupBox);
        lineEdit_cycles->setObjectName(QStringLiteral("lineEdit_cycles"));
        sizePolicy1.setHeightForWidth(lineEdit_cycles->sizePolicy().hasHeightForWidth());
        lineEdit_cycles->setSizePolicy(sizePolicy1);
        lineEdit_cycles->setMinimumSize(QSize(140, 0));
        lineEdit_cycles->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_6->addWidget(lineEdit_cycles);

        horizontalSpacer = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        SaveBtn = new QPushButton(CapacityTestDialog);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout_2->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(CapacityTestDialog);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout_2->addWidget(ModifyBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        ReturnBtn = new QPushButton(CapacityTestDialog);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout_2->addWidget(ReturnBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(CapacityTestDialog);

        QMetaObject::connectSlotsByName(CapacityTestDialog);
    } // setupUi

    void retranslateUi(QDialog *CapacityTestDialog)
    {
        CapacityTestDialog->setWindowTitle(QApplication::translate("CapacityTestDialog", "CapacityTestDialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("CapacityTestDialog", "please enter test name:", Q_NULLPTR));
        lineEdit_testname->setText(QString());
        groupBox->setTitle(QApplication::translate("CapacityTestDialog", "Parameter Setting\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("CapacityTestDialog", "charge voltage:", Q_NULLPTR));
        lineEdit_chargeVoltage->setInputMask(QString());
        lineEdit_chargeVoltage->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("CapacityTestDialog", "V", Q_NULLPTR));
        label_15->setText(QApplication::translate("CapacityTestDialog", "charge current:", Q_NULLPTR));
        lineEdit_chargeCurrent->setPlaceholderText(QString());
        label_13->setText(QApplication::translate("CapacityTestDialog", "A", Q_NULLPTR));
        label_16->setText(QApplication::translate("CapacityTestDialog", "discharge current:", Q_NULLPTR));
        lineEdit_dischargeCurrent->setPlaceholderText(QString());
        label_14->setText(QApplication::translate("CapacityTestDialog", "A", Q_NULLPTR));
        label_17->setText(QApplication::translate("CapacityTestDialog", "Number of cycles:", Q_NULLPTR));
        lineEdit_cycles->setText(QApplication::translate("CapacityTestDialog", "3", Q_NULLPTR));
        lineEdit_cycles->setPlaceholderText(QString());
        SaveBtn->setText(QApplication::translate("CapacityTestDialog", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("CapacityTestDialog", "ModifyBtn", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("CapacityTestDialog", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CapacityTestDialog: public Ui_CapacityTestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPACITYTESTDIALOG_H
