/********************************************************************************
** Form generated from reading UI file 'chargeanddischargetestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEANDDISCHARGETESTDIALOG_H
#define UI_CHARGEANDDISCHARGETESTDIALOG_H

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

class Ui_ChargeAndDischargeTestDialog
{
public:
    QVBoxLayout *verticalLayout_3;
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
    QLineEdit *lineEdit_chargeCurrent_standard;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *lineEdit_chargeCurrent_fast;
    QLabel *label_14;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_17;
    QLineEdit *lineEdit_dischargeCurrent_standard;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_19;
    QLineEdit *lineEdit_dischargeCurrent_fast;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ChargeAndDischargeTestDialog)
    {
        if (ChargeAndDischargeTestDialog->objectName().isEmpty())
            ChargeAndDischargeTestDialog->setObjectName(QStringLiteral("ChargeAndDischargeTestDialog"));
        ChargeAndDischargeTestDialog->resize(440, 383);
        ChargeAndDischargeTestDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QDialog#ChargeAndDischargeTestDialog{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(ChargeAndDischargeTestDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(ChargeAndDischargeTestDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_testname = new QLineEdit(ChargeAndDischargeTestDialog);
        lineEdit_testname->setObjectName(QStringLiteral("lineEdit_testname"));
        lineEdit_testname->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(lineEdit_testname);


        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(ChargeAndDischargeTestDialog);
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

        lineEdit_chargeCurrent_standard = new QLineEdit(groupBox);
        lineEdit_chargeCurrent_standard->setObjectName(QStringLiteral("lineEdit_chargeCurrent_standard"));
        sizePolicy1.setHeightForWidth(lineEdit_chargeCurrent_standard->sizePolicy().hasHeightForWidth());
        lineEdit_chargeCurrent_standard->setSizePolicy(sizePolicy1);
        lineEdit_chargeCurrent_standard->setMinimumSize(QSize(140, 0));
        lineEdit_chargeCurrent_standard->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_4->addWidget(lineEdit_chargeCurrent_standard);

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

        lineEdit_chargeCurrent_fast = new QLineEdit(groupBox);
        lineEdit_chargeCurrent_fast->setObjectName(QStringLiteral("lineEdit_chargeCurrent_fast"));
        sizePolicy1.setHeightForWidth(lineEdit_chargeCurrent_fast->sizePolicy().hasHeightForWidth());
        lineEdit_chargeCurrent_fast->setSizePolicy(sizePolicy1);
        lineEdit_chargeCurrent_fast->setMinimumSize(QSize(140, 0));
        lineEdit_chargeCurrent_fast->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_5->addWidget(lineEdit_chargeCurrent_fast);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_14);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ChargeAndDischargeTestDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_6->addWidget(label_17);

        lineEdit_dischargeCurrent_standard = new QLineEdit(groupBox_2);
        lineEdit_dischargeCurrent_standard->setObjectName(QStringLiteral("lineEdit_dischargeCurrent_standard"));
        sizePolicy1.setHeightForWidth(lineEdit_dischargeCurrent_standard->sizePolicy().hasHeightForWidth());
        lineEdit_dischargeCurrent_standard->setSizePolicy(sizePolicy1);
        lineEdit_dischargeCurrent_standard->setMinimumSize(QSize(140, 0));
        lineEdit_dischargeCurrent_standard->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_6->addWidget(lineEdit_dischargeCurrent_standard);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_18);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_7->addWidget(label_19);

        lineEdit_dischargeCurrent_fast = new QLineEdit(groupBox_2);
        lineEdit_dischargeCurrent_fast->setObjectName(QStringLiteral("lineEdit_dischargeCurrent_fast"));
        sizePolicy1.setHeightForWidth(lineEdit_dischargeCurrent_fast->sizePolicy().hasHeightForWidth());
        lineEdit_dischargeCurrent_fast->setSizePolicy(sizePolicy1);
        lineEdit_dischargeCurrent_fast->setMinimumSize(QSize(140, 0));
        lineEdit_dischargeCurrent_fast->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_7->addWidget(lineEdit_dischargeCurrent_fast);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy2.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_20);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        SaveBtn = new QPushButton(ChargeAndDischargeTestDialog);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout_2->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(ChargeAndDischargeTestDialog);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout_2->addWidget(ModifyBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        ReturnBtn = new QPushButton(ChargeAndDischargeTestDialog);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout_2->addWidget(ReturnBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(ChargeAndDischargeTestDialog);

        QMetaObject::connectSlotsByName(ChargeAndDischargeTestDialog);
    } // setupUi

    void retranslateUi(QDialog *ChargeAndDischargeTestDialog)
    {
        ChargeAndDischargeTestDialog->setWindowTitle(QApplication::translate("ChargeAndDischargeTestDialog", "ChargeAndDischargeTestDialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChargeAndDischargeTestDialog", "please enter test name:", Q_NULLPTR));
        lineEdit_testname->setText(QString());
        groupBox->setTitle(QApplication::translate("ChargeAndDischargeTestDialog", "Charge Parameter Setting\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ChargeAndDischargeTestDialog", "charge voltage:", Q_NULLPTR));
        lineEdit_chargeVoltage->setInputMask(QString());
        lineEdit_chargeVoltage->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("ChargeAndDischargeTestDialog", "V", Q_NULLPTR));
        label_15->setText(QApplication::translate("ChargeAndDischargeTestDialog", "Standard charge current:", Q_NULLPTR));
        lineEdit_chargeCurrent_standard->setPlaceholderText(QString());
        label_13->setText(QApplication::translate("ChargeAndDischargeTestDialog", "A", Q_NULLPTR));
        label_16->setText(QApplication::translate("ChargeAndDischargeTestDialog", " Fast charge current:", Q_NULLPTR));
        lineEdit_chargeCurrent_fast->setPlaceholderText(QString());
        label_14->setText(QApplication::translate("ChargeAndDischargeTestDialog", "A", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ChargeAndDischargeTestDialog", "Discharging Parameter Setting\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("ChargeAndDischargeTestDialog", "Standard discharge current:", Q_NULLPTR));
        lineEdit_dischargeCurrent_standard->setPlaceholderText(QString());
        label_18->setText(QApplication::translate("ChargeAndDischargeTestDialog", "A", Q_NULLPTR));
        label_19->setText(QApplication::translate("ChargeAndDischargeTestDialog", " Fast discharge current:", Q_NULLPTR));
        lineEdit_dischargeCurrent_fast->setPlaceholderText(QString());
        label_20->setText(QApplication::translate("ChargeAndDischargeTestDialog", "A", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("ChargeAndDischargeTestDialog", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("ChargeAndDischargeTestDialog", "ModifyBtn", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("ChargeAndDischargeTestDialog", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChargeAndDischargeTestDialog: public Ui_ChargeAndDischargeTestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEANDDISCHARGETESTDIALOG_H
