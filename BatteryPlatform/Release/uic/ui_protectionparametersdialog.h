/********************************************************************************
** Form generated from reading UI file 'protectionparametersdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTECTIONPARAMETERSDIALOG_H
#define UI_PROTECTIONPARAMETERSDIALOG_H

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

class Ui_ProtectionParametersDialog
{
public:
    QVBoxLayout *verticalLayout_12;
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
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_total_voltage_overshoot_warning;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_total_voltage_overshoot_protect;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_total_voltage__overshoot_relieve;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEdit_single_voltage_overshoot_warning;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *lineEdit_single_voltage_overshoot_protect;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_single_voltage_overshoot_relieve;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_26;
    QLineEdit *lineEdit_total_voltage_overfall_warning;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_28;
    QLineEdit *lineEdit_total_voltage_overfall_protect;
    QLabel *label_29;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_30;
    QLineEdit *lineEdit_total_voltage__overfall_relieve;
    QLabel *label_31;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_20;
    QLineEdit *lineEdit_single_voltage_overfall_warning;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_22;
    QLineEdit *lineEdit_single_voltage_overfall_protect;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_24;
    QLineEdit *lineEdit_single_voltage_overfall_relieve;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_31;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_32;
    QLineEdit *lineEdit_charge_overcurrent_waring;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_34;
    QLineEdit *lineEdit_charge_overcurrent_protect;
    QLabel *label_35;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_36;
    QLineEdit *lineEdit_charge_overcurrent_dealy_time;
    QLabel *label_37;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_38;
    QLineEdit *lineEdit_charge_overcurrent_relieve_time;
    QLabel *label_39;
    QHBoxLayout *horizontalLayout_32;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_40;
    QLineEdit *lineEdit_discharge_overcurrent_waring;
    QLabel *label_41;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_42;
    QLineEdit *lineEdit_discharge_overcurrent_protect_one;
    QLabel *label_43;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_46;
    QLineEdit *lineEdit_discharge_overcurrent_protect_two;
    QLabel *label_47;
    QHBoxLayout *horizontalLayout_33;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_44;
    QLineEdit *lineEdit_discharge_overcurrent_delay_time_one;
    QLabel *label_45;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_48;
    QLineEdit *lineEdit_discharge_overcurrent_delay_time_two;
    QLabel *label_49;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_50;
    QLineEdit *lineEdit_discharge_overcurrent_relieve_time_one;
    QLabel *label_51;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_52;
    QLineEdit *lineEdit_discharge_overcurrent_relieve_time_two;
    QLabel *label_53;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ProtectionParametersDialog)
    {
        if (ProtectionParametersDialog->objectName().isEmpty())
            ProtectionParametersDialog->setObjectName(QStringLiteral("ProtectionParametersDialog"));
        ProtectionParametersDialog->resize(1169, 842);
        ProtectionParametersDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QDialog#ProtectionParametersDialog{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_12 = new QVBoxLayout(ProtectionParametersDialog);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(ProtectionParametersDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_testname = new QLineEdit(ProtectionParametersDialog);
        lineEdit_testname->setObjectName(QStringLiteral("lineEdit_testname"));
        lineEdit_testname->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(lineEdit_testname);


        verticalLayout_12->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(ProtectionParametersDialog);
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


        verticalLayout_12->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ProtectionParametersDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_total_voltage_overshoot_warning = new QLineEdit(groupBox_2);
        lineEdit_total_voltage_overshoot_warning->setObjectName(QStringLiteral("lineEdit_total_voltage_overshoot_warning"));
        lineEdit_total_voltage_overshoot_warning->setMinimumSize(QSize(120, 0));
        lineEdit_total_voltage_overshoot_warning->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(lineEdit_total_voltage_overshoot_warning);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label_10);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_total_voltage_overshoot_protect = new QLineEdit(groupBox_2);
        lineEdit_total_voltage_overshoot_protect->setObjectName(QStringLiteral("lineEdit_total_voltage_overshoot_protect"));
        lineEdit_total_voltage_overshoot_protect->setMinimumSize(QSize(120, 0));
        lineEdit_total_voltage_overshoot_protect->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(lineEdit_total_voltage_overshoot_protect);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_11);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_total_voltage__overshoot_relieve = new QLineEdit(groupBox_2);
        lineEdit_total_voltage__overshoot_relieve->setObjectName(QStringLiteral("lineEdit_total_voltage__overshoot_relieve"));
        lineEdit_total_voltage__overshoot_relieve->setMinimumSize(QSize(120, 0));
        lineEdit_total_voltage__overshoot_relieve->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_7->addWidget(lineEdit_total_voltage__overshoot_relieve);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_12);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_single_voltage_overshoot_warning = new QLineEdit(groupBox_2);
        lineEdit_single_voltage_overshoot_warning->setObjectName(QStringLiteral("lineEdit_single_voltage_overshoot_warning"));
        lineEdit_single_voltage_overshoot_warning->setMinimumSize(QSize(120, 0));
        lineEdit_single_voltage_overshoot_warning->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_9->addWidget(lineEdit_single_voltage_overshoot_warning);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(label_17);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        lineEdit_single_voltage_overshoot_protect = new QLineEdit(groupBox_2);
        lineEdit_single_voltage_overshoot_protect->setObjectName(QStringLiteral("lineEdit_single_voltage_overshoot_protect"));
        lineEdit_single_voltage_overshoot_protect->setMinimumSize(QSize(120, 0));
        lineEdit_single_voltage_overshoot_protect->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_10->addWidget(lineEdit_single_voltage_overshoot_protect);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_18);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lineEdit_single_voltage_overshoot_relieve = new QLineEdit(groupBox_2);
        lineEdit_single_voltage_overshoot_relieve->setObjectName(QStringLiteral("lineEdit_single_voltage_overshoot_relieve"));
        lineEdit_single_voltage_overshoot_relieve->setMinimumSize(QSize(120, 0));
        lineEdit_single_voltage_overshoot_relieve->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(lineEdit_single_voltage_overshoot_relieve);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(label_19);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_11->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(2);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_16->addWidget(label_26);

        lineEdit_total_voltage_overfall_warning = new QLineEdit(groupBox_2);
        lineEdit_total_voltage_overfall_warning->setObjectName(QStringLiteral("lineEdit_total_voltage_overfall_warning"));
        lineEdit_total_voltage_overfall_warning->setMinimumSize(QSize(120, 0));
        lineEdit_total_voltage_overfall_warning->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_16->addWidget(lineEdit_total_voltage_overfall_warning);

        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy2.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(label_27);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_17->addWidget(label_28);

        lineEdit_total_voltage_overfall_protect = new QLineEdit(groupBox_2);
        lineEdit_total_voltage_overfall_protect->setObjectName(QStringLiteral("lineEdit_total_voltage_overfall_protect"));
        lineEdit_total_voltage_overfall_protect->setMinimumSize(QSize(120, 0));
        lineEdit_total_voltage_overfall_protect->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_17->addWidget(lineEdit_total_voltage_overfall_protect);

        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy2.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy2);

        horizontalLayout_17->addWidget(label_29);


        verticalLayout_5->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName(QStringLiteral("label_30"));

        horizontalLayout_18->addWidget(label_30);

        lineEdit_total_voltage__overfall_relieve = new QLineEdit(groupBox_2);
        lineEdit_total_voltage__overfall_relieve->setObjectName(QStringLiteral("lineEdit_total_voltage__overfall_relieve"));
        lineEdit_total_voltage__overfall_relieve->setMinimumSize(QSize(120, 0));
        lineEdit_total_voltage__overfall_relieve->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_18->addWidget(lineEdit_total_voltage__overfall_relieve);

        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy2.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy2);

        horizontalLayout_18->addWidget(label_31);


        verticalLayout_5->addLayout(horizontalLayout_18);


        horizontalLayout_19->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_12->addWidget(label_20);

        lineEdit_single_voltage_overfall_warning = new QLineEdit(groupBox_2);
        lineEdit_single_voltage_overfall_warning->setObjectName(QStringLiteral("lineEdit_single_voltage_overfall_warning"));
        lineEdit_single_voltage_overfall_warning->setMinimumSize(QSize(120, 0));
        lineEdit_single_voltage_overfall_warning->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_12->addWidget(lineEdit_single_voltage_overfall_warning);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);

        horizontalLayout_12->addWidget(label_21);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_13->addWidget(label_22);

        lineEdit_single_voltage_overfall_protect = new QLineEdit(groupBox_2);
        lineEdit_single_voltage_overfall_protect->setObjectName(QStringLiteral("lineEdit_single_voltage_overfall_protect"));
        lineEdit_single_voltage_overfall_protect->setMinimumSize(QSize(120, 0));
        lineEdit_single_voltage_overfall_protect->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_13->addWidget(lineEdit_single_voltage_overfall_protect);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);

        horizontalLayout_13->addWidget(label_23);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_14->addWidget(label_24);

        lineEdit_single_voltage_overfall_relieve = new QLineEdit(groupBox_2);
        lineEdit_single_voltage_overfall_relieve->setObjectName(QStringLiteral("lineEdit_single_voltage_overfall_relieve"));
        lineEdit_single_voltage_overfall_relieve->setMinimumSize(QSize(120, 0));
        lineEdit_single_voltage_overfall_relieve->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_14->addWidget(lineEdit_single_voltage_overfall_relieve);

        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        sizePolicy2.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy2);

        horizontalLayout_14->addWidget(label_25);


        verticalLayout_4->addLayout(horizontalLayout_14);


        horizontalLayout_19->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_19);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_20->addWidget(label_32);

        lineEdit_charge_overcurrent_waring = new QLineEdit(groupBox_2);
        lineEdit_charge_overcurrent_waring->setObjectName(QStringLiteral("lineEdit_charge_overcurrent_waring"));
        lineEdit_charge_overcurrent_waring->setMinimumSize(QSize(120, 0));
        lineEdit_charge_overcurrent_waring->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_20->addWidget(lineEdit_charge_overcurrent_waring);

        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy2.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy2);

        horizontalLayout_20->addWidget(label_33);


        verticalLayout_7->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        horizontalLayout_21->addWidget(label_34);

        lineEdit_charge_overcurrent_protect = new QLineEdit(groupBox_2);
        lineEdit_charge_overcurrent_protect->setObjectName(QStringLiteral("lineEdit_charge_overcurrent_protect"));
        lineEdit_charge_overcurrent_protect->setMinimumSize(QSize(120, 0));
        lineEdit_charge_overcurrent_protect->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_21->addWidget(lineEdit_charge_overcurrent_protect);

        label_35 = new QLabel(groupBox_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy2.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy2);

        horizontalLayout_21->addWidget(label_35);


        verticalLayout_7->addLayout(horizontalLayout_21);


        horizontalLayout_31->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_36 = new QLabel(groupBox_2);
        label_36->setObjectName(QStringLiteral("label_36"));

        horizontalLayout_22->addWidget(label_36);

        lineEdit_charge_overcurrent_dealy_time = new QLineEdit(groupBox_2);
        lineEdit_charge_overcurrent_dealy_time->setObjectName(QStringLiteral("lineEdit_charge_overcurrent_dealy_time"));
        lineEdit_charge_overcurrent_dealy_time->setMinimumSize(QSize(120, 0));
        lineEdit_charge_overcurrent_dealy_time->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_22->addWidget(lineEdit_charge_overcurrent_dealy_time);

        label_37 = new QLabel(groupBox_2);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy2.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy2);

        horizontalLayout_22->addWidget(label_37);


        verticalLayout_8->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_38 = new QLabel(groupBox_2);
        label_38->setObjectName(QStringLiteral("label_38"));

        horizontalLayout_23->addWidget(label_38);

        lineEdit_charge_overcurrent_relieve_time = new QLineEdit(groupBox_2);
        lineEdit_charge_overcurrent_relieve_time->setObjectName(QStringLiteral("lineEdit_charge_overcurrent_relieve_time"));
        lineEdit_charge_overcurrent_relieve_time->setMinimumSize(QSize(120, 0));
        lineEdit_charge_overcurrent_relieve_time->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_23->addWidget(lineEdit_charge_overcurrent_relieve_time);

        label_39 = new QLabel(groupBox_2);
        label_39->setObjectName(QStringLiteral("label_39"));
        sizePolicy2.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy2);

        horizontalLayout_23->addWidget(label_39);


        verticalLayout_8->addLayout(horizontalLayout_23);


        horizontalLayout_31->addLayout(verticalLayout_8);


        verticalLayout_6->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_40 = new QLabel(groupBox_2);
        label_40->setObjectName(QStringLiteral("label_40"));

        horizontalLayout_24->addWidget(label_40);

        lineEdit_discharge_overcurrent_waring = new QLineEdit(groupBox_2);
        lineEdit_discharge_overcurrent_waring->setObjectName(QStringLiteral("lineEdit_discharge_overcurrent_waring"));
        lineEdit_discharge_overcurrent_waring->setMinimumSize(QSize(120, 0));
        lineEdit_discharge_overcurrent_waring->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_24->addWidget(lineEdit_discharge_overcurrent_waring);

        label_41 = new QLabel(groupBox_2);
        label_41->setObjectName(QStringLiteral("label_41"));
        sizePolicy2.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy2);

        horizontalLayout_24->addWidget(label_41);


        horizontalLayout_32->addLayout(horizontalLayout_24);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        label_42 = new QLabel(groupBox_2);
        label_42->setObjectName(QStringLiteral("label_42"));

        horizontalLayout_25->addWidget(label_42);

        lineEdit_discharge_overcurrent_protect_one = new QLineEdit(groupBox_2);
        lineEdit_discharge_overcurrent_protect_one->setObjectName(QStringLiteral("lineEdit_discharge_overcurrent_protect_one"));
        lineEdit_discharge_overcurrent_protect_one->setMinimumSize(QSize(120, 0));
        lineEdit_discharge_overcurrent_protect_one->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_25->addWidget(lineEdit_discharge_overcurrent_protect_one);

        label_43 = new QLabel(groupBox_2);
        label_43->setObjectName(QStringLiteral("label_43"));
        sizePolicy2.setHeightForWidth(label_43->sizePolicy().hasHeightForWidth());
        label_43->setSizePolicy(sizePolicy2);

        horizontalLayout_25->addWidget(label_43);


        verticalLayout_9->addLayout(horizontalLayout_25);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_46 = new QLabel(groupBox_2);
        label_46->setObjectName(QStringLiteral("label_46"));

        horizontalLayout_27->addWidget(label_46);

        lineEdit_discharge_overcurrent_protect_two = new QLineEdit(groupBox_2);
        lineEdit_discharge_overcurrent_protect_two->setObjectName(QStringLiteral("lineEdit_discharge_overcurrent_protect_two"));
        lineEdit_discharge_overcurrent_protect_two->setMinimumSize(QSize(120, 0));
        lineEdit_discharge_overcurrent_protect_two->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_27->addWidget(lineEdit_discharge_overcurrent_protect_two);

        label_47 = new QLabel(groupBox_2);
        label_47->setObjectName(QStringLiteral("label_47"));
        sizePolicy2.setHeightForWidth(label_47->sizePolicy().hasHeightForWidth());
        label_47->setSizePolicy(sizePolicy2);

        horizontalLayout_27->addWidget(label_47);


        verticalLayout_9->addLayout(horizontalLayout_27);


        horizontalLayout_32->addLayout(verticalLayout_9);


        verticalLayout_6->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_44 = new QLabel(groupBox_2);
        label_44->setObjectName(QStringLiteral("label_44"));

        horizontalLayout_26->addWidget(label_44);

        lineEdit_discharge_overcurrent_delay_time_one = new QLineEdit(groupBox_2);
        lineEdit_discharge_overcurrent_delay_time_one->setObjectName(QStringLiteral("lineEdit_discharge_overcurrent_delay_time_one"));
        lineEdit_discharge_overcurrent_delay_time_one->setMinimumSize(QSize(120, 0));
        lineEdit_discharge_overcurrent_delay_time_one->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_26->addWidget(lineEdit_discharge_overcurrent_delay_time_one);

        label_45 = new QLabel(groupBox_2);
        label_45->setObjectName(QStringLiteral("label_45"));
        sizePolicy2.setHeightForWidth(label_45->sizePolicy().hasHeightForWidth());
        label_45->setSizePolicy(sizePolicy2);

        horizontalLayout_26->addWidget(label_45);


        verticalLayout_10->addLayout(horizontalLayout_26);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_48 = new QLabel(groupBox_2);
        label_48->setObjectName(QStringLiteral("label_48"));

        horizontalLayout_28->addWidget(label_48);

        lineEdit_discharge_overcurrent_delay_time_two = new QLineEdit(groupBox_2);
        lineEdit_discharge_overcurrent_delay_time_two->setObjectName(QStringLiteral("lineEdit_discharge_overcurrent_delay_time_two"));
        lineEdit_discharge_overcurrent_delay_time_two->setMinimumSize(QSize(120, 0));
        lineEdit_discharge_overcurrent_delay_time_two->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_28->addWidget(lineEdit_discharge_overcurrent_delay_time_two);

        label_49 = new QLabel(groupBox_2);
        label_49->setObjectName(QStringLiteral("label_49"));
        sizePolicy2.setHeightForWidth(label_49->sizePolicy().hasHeightForWidth());
        label_49->setSizePolicy(sizePolicy2);

        horizontalLayout_28->addWidget(label_49);


        verticalLayout_10->addLayout(horizontalLayout_28);


        horizontalLayout_33->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        label_50 = new QLabel(groupBox_2);
        label_50->setObjectName(QStringLiteral("label_50"));

        horizontalLayout_29->addWidget(label_50);

        lineEdit_discharge_overcurrent_relieve_time_one = new QLineEdit(groupBox_2);
        lineEdit_discharge_overcurrent_relieve_time_one->setObjectName(QStringLiteral("lineEdit_discharge_overcurrent_relieve_time_one"));
        lineEdit_discharge_overcurrent_relieve_time_one->setMinimumSize(QSize(120, 0));
        lineEdit_discharge_overcurrent_relieve_time_one->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_29->addWidget(lineEdit_discharge_overcurrent_relieve_time_one);

        label_51 = new QLabel(groupBox_2);
        label_51->setObjectName(QStringLiteral("label_51"));
        sizePolicy2.setHeightForWidth(label_51->sizePolicy().hasHeightForWidth());
        label_51->setSizePolicy(sizePolicy2);

        horizontalLayout_29->addWidget(label_51);


        verticalLayout_11->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        label_52 = new QLabel(groupBox_2);
        label_52->setObjectName(QStringLiteral("label_52"));

        horizontalLayout_30->addWidget(label_52);

        lineEdit_discharge_overcurrent_relieve_time_two = new QLineEdit(groupBox_2);
        lineEdit_discharge_overcurrent_relieve_time_two->setObjectName(QStringLiteral("lineEdit_discharge_overcurrent_relieve_time_two"));
        lineEdit_discharge_overcurrent_relieve_time_two->setMinimumSize(QSize(120, 0));
        lineEdit_discharge_overcurrent_relieve_time_two->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_30->addWidget(lineEdit_discharge_overcurrent_relieve_time_two);

        label_53 = new QLabel(groupBox_2);
        label_53->setObjectName(QStringLiteral("label_53"));
        sizePolicy2.setHeightForWidth(label_53->sizePolicy().hasHeightForWidth());
        label_53->setSizePolicy(sizePolicy2);

        horizontalLayout_30->addWidget(label_53);


        verticalLayout_11->addLayout(horizontalLayout_30);


        horizontalLayout_33->addLayout(verticalLayout_11);


        verticalLayout_6->addLayout(horizontalLayout_33);


        verticalLayout_12->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        SaveBtn = new QPushButton(ProtectionParametersDialog);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout_2->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(ProtectionParametersDialog);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout_2->addWidget(ModifyBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        ReturnBtn = new QPushButton(ProtectionParametersDialog);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout_2->addWidget(ReturnBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_12->addLayout(horizontalLayout_2);


        retranslateUi(ProtectionParametersDialog);

        QMetaObject::connectSlotsByName(ProtectionParametersDialog);
    } // setupUi

    void retranslateUi(QDialog *ProtectionParametersDialog)
    {
        ProtectionParametersDialog->setWindowTitle(QApplication::translate("ProtectionParametersDialog", "ProtectionParametersDialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("ProtectionParametersDialog", "please enter test name:", Q_NULLPTR));
        lineEdit_testname->setText(QString());
        groupBox->setTitle(QApplication::translate("ProtectionParametersDialog", "Parameter Setting\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ProtectionParametersDialog", "charge voltage:", Q_NULLPTR));
        lineEdit_chargeVoltage->setInputMask(QString());
        lineEdit_chargeVoltage->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_15->setText(QApplication::translate("ProtectionParametersDialog", "charge current:", Q_NULLPTR));
        lineEdit_chargeCurrent->setPlaceholderText(QString());
        label_13->setText(QApplication::translate("ProtectionParametersDialog", "A", Q_NULLPTR));
        label_16->setText(QApplication::translate("ProtectionParametersDialog", "discharge current:", Q_NULLPTR));
        lineEdit_dischargeCurrent->setPlaceholderText(QString());
        label_14->setText(QApplication::translate("ProtectionParametersDialog", "A", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ProtectionParametersDialog", "protection parameters", Q_NULLPTR));
        label_3->setText(QApplication::translate("ProtectionParametersDialog", "Total voltage overshoot warning value", Q_NULLPTR));
        label_10->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_4->setText(QApplication::translate("ProtectionParametersDialog", "Total voltage overshoot protect value", Q_NULLPTR));
        label_11->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_5->setText(QApplication::translate("ProtectionParametersDialog", "Total voltage overshoot relieve value", Q_NULLPTR));
        label_12->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_7->setText(QApplication::translate("ProtectionParametersDialog", "Single voltage overshoot warning value", Q_NULLPTR));
        label_17->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_8->setText(QApplication::translate("ProtectionParametersDialog", "Single voltage overshoot protect value", Q_NULLPTR));
        label_18->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_6->setText(QApplication::translate("ProtectionParametersDialog", "Single voltage overshoot relieve value", Q_NULLPTR));
        label_19->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_26->setText(QApplication::translate("ProtectionParametersDialog", "Total voltage overfall warning value", Q_NULLPTR));
        label_27->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_28->setText(QApplication::translate("ProtectionParametersDialog", "Total voltage overfall protect value", Q_NULLPTR));
        label_29->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_30->setText(QApplication::translate("ProtectionParametersDialog", "Total voltage overfall relieve value", Q_NULLPTR));
        label_31->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_20->setText(QApplication::translate("ProtectionParametersDialog", "Single voltage overfall warning value", Q_NULLPTR));
        label_21->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_22->setText(QApplication::translate("ProtectionParametersDialog", "Single voltage overfall protect value", Q_NULLPTR));
        label_23->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_24->setText(QApplication::translate("ProtectionParametersDialog", "Single voltage overfall relieve value", Q_NULLPTR));
        label_25->setText(QApplication::translate("ProtectionParametersDialog", "V", Q_NULLPTR));
        label_32->setText(QApplication::translate("ProtectionParametersDialog", "Charge overcurrent warning value", Q_NULLPTR));
        label_33->setText(QApplication::translate("ProtectionParametersDialog", "A", Q_NULLPTR));
        label_34->setText(QApplication::translate("ProtectionParametersDialog", "Charge overcurrent protect value", Q_NULLPTR));
        label_35->setText(QApplication::translate("ProtectionParametersDialog", "A", Q_NULLPTR));
        label_36->setText(QApplication::translate("ProtectionParametersDialog", "Charge overcurrent dealy time", Q_NULLPTR));
        label_37->setText(QApplication::translate("ProtectionParametersDialog", "S", Q_NULLPTR));
        label_38->setText(QApplication::translate("ProtectionParametersDialog", "Charge overcurrent relieve time", Q_NULLPTR));
        label_39->setText(QApplication::translate("ProtectionParametersDialog", "S", Q_NULLPTR));
        label_40->setText(QApplication::translate("ProtectionParametersDialog", "Discharge overcurrent warning value", Q_NULLPTR));
        label_41->setText(QApplication::translate("ProtectionParametersDialog", "A", Q_NULLPTR));
        label_42->setText(QApplication::translate("ProtectionParametersDialog", "Discharge overcurrent protect one value", Q_NULLPTR));
        label_43->setText(QApplication::translate("ProtectionParametersDialog", "A", Q_NULLPTR));
        label_46->setText(QApplication::translate("ProtectionParametersDialog", "Discharge overcurrent protect two value", Q_NULLPTR));
        label_47->setText(QApplication::translate("ProtectionParametersDialog", "A", Q_NULLPTR));
        label_44->setText(QApplication::translate("ProtectionParametersDialog", "Discharge overcurrent delay time one", Q_NULLPTR));
        label_45->setText(QApplication::translate("ProtectionParametersDialog", "S", Q_NULLPTR));
        label_48->setText(QApplication::translate("ProtectionParametersDialog", "Discharge overcurrent delay time two", Q_NULLPTR));
        label_49->setText(QApplication::translate("ProtectionParametersDialog", "S", Q_NULLPTR));
        label_50->setText(QApplication::translate("ProtectionParametersDialog", "Discharge overcurrent relieve time one", Q_NULLPTR));
        label_51->setText(QApplication::translate("ProtectionParametersDialog", "S", Q_NULLPTR));
        label_52->setText(QApplication::translate("ProtectionParametersDialog", "Discharge overcurrent relieve time two", Q_NULLPTR));
        label_53->setText(QApplication::translate("ProtectionParametersDialog", "S", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("ProtectionParametersDialog", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("ProtectionParametersDialog", "ModifyBtn", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("ProtectionParametersDialog", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProtectionParametersDialog: public Ui_ProtectionParametersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTECTIONPARAMETERSDIALOG_H
