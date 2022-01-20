/********************************************************************************
** Form generated from reading UI file 'chargetestwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGETESTWIDGET_H
#define UI_CHARGETESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChargeTestWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label;
    QLineEdit *lineEdit_Voltage;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_ConstantCuurrent;
    QRadioButton *radioButton_changecurrent;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_Current;
    QLabel *label_13;
    QCheckBox *checkBox_voltageAccuracy;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_21;
    QRadioButton *radioButton_fullcharge;
    QRadioButton *radioButton_overShoot;
    QHBoxLayout *horizontalLayout_16;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_Soc;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_17;
    QRadioButton *radioButton_4;
    QLineEdit *lineEdit_singleVoltage;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_18;
    QRadioButton *radioButton_5;
    QLineEdit *lineEdit_totalVoltage;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_19;
    QRadioButton *radioButton_6;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_20;
    QRadioButton *radioButton_8;
    QLineEdit *lineEdit_Capiciy;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ChargeTestWidget)
    {
        if (ChargeTestWidget->objectName().isEmpty())
            ChargeTestWidget->setObjectName(QStringLiteral("ChargeTestWidget"));
        ChargeTestWidget->resize(729, 727);
        ChargeTestWidget->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{	\n"
"	color: rgb(0, 255, 0);\n"
"	background-color: rgb(0, 0, 145);\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QGroupBox\n"
"{\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QRadioButton\n"
"{\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QCheckBox\n"
"{\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLabel\n"
"{	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
""));
        gridLayout = new QGridLayout(ChargeTestWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(ChargeTestWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_15->addWidget(label);

        lineEdit_Voltage = new QLineEdit(groupBox);
        lineEdit_Voltage->setObjectName(QStringLiteral("lineEdit_Voltage"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Voltage->sizePolicy().hasHeightForWidth());
        lineEdit_Voltage->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(lineEdit_Voltage);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_15->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        radioButton_ConstantCuurrent = new QRadioButton(groupBox);
        radioButton_ConstantCuurrent->setObjectName(QStringLiteral("radioButton_ConstantCuurrent"));

        verticalLayout_7->addWidget(radioButton_ConstantCuurrent);

        radioButton_changecurrent = new QRadioButton(groupBox);
        radioButton_changecurrent->setObjectName(QStringLiteral("radioButton_changecurrent"));

        verticalLayout_7->addWidget(radioButton_changecurrent);


        horizontalLayout_4->addLayout(verticalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEdit_Current = new QLineEdit(groupBox);
        lineEdit_Current->setObjectName(QStringLiteral("lineEdit_Current"));
        sizePolicy.setHeightForWidth(lineEdit_Current->sizePolicy().hasHeightForWidth());
        lineEdit_Current->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_Current);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_4);

        checkBox_voltageAccuracy = new QCheckBox(groupBox);
        checkBox_voltageAccuracy->setObjectName(QStringLiteral("checkBox_voltageAccuracy"));

        verticalLayout->addWidget(checkBox_voltageAccuracy);


        verticalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(ChargeTestWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        radioButton_fullcharge = new QRadioButton(groupBox_3);
        radioButton_fullcharge->setObjectName(QStringLiteral("radioButton_fullcharge"));

        horizontalLayout_21->addWidget(radioButton_fullcharge);

        radioButton_overShoot = new QRadioButton(groupBox_3);
        radioButton_overShoot->setObjectName(QStringLiteral("radioButton_overShoot"));

        horizontalLayout_21->addWidget(radioButton_overShoot);


        verticalLayout_2->addLayout(horizontalLayout_21);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(2);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout_16->addWidget(radioButton_3);

        lineEdit_Soc = new QLineEdit(groupBox_3);
        lineEdit_Soc->setObjectName(QStringLiteral("lineEdit_Soc"));
        sizePolicy.setHeightForWidth(lineEdit_Soc->sizePolicy().hasHeightForWidth());
        lineEdit_Soc->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(lineEdit_Soc);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_16->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(2);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        horizontalLayout_17->addWidget(radioButton_4);

        lineEdit_singleVoltage = new QLineEdit(groupBox_3);
        lineEdit_singleVoltage->setObjectName(QStringLiteral("lineEdit_singleVoltage"));

        horizontalLayout_17->addWidget(lineEdit_singleVoltage);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_17->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(2);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        horizontalLayout_18->addWidget(radioButton_5);

        lineEdit_totalVoltage = new QLineEdit(groupBox_3);
        lineEdit_totalVoltage->setObjectName(QStringLiteral("lineEdit_totalVoltage"));

        horizontalLayout_18->addWidget(lineEdit_totalVoltage);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_18->addWidget(label_11);


        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        horizontalLayout_19->addWidget(radioButton_6);

        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_19->addWidget(lineEdit_6);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_19->addWidget(label_12);


        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        radioButton_8 = new QRadioButton(groupBox_3);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));

        horizontalLayout_20->addWidget(radioButton_8);

        lineEdit_Capiciy = new QLineEdit(groupBox_3);
        lineEdit_Capiciy->setObjectName(QStringLiteral("lineEdit_Capiciy"));

        horizontalLayout_20->addWidget(lineEdit_Capiciy);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_20->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout_20);


        verticalLayout_4->addWidget(groupBox_3);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        SaveBtn = new QPushButton(ChargeTestWidget);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(ChargeTestWidget);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout->addWidget(ModifyBtn);

        ReturnBtn = new QPushButton(ChargeTestWidget);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout->addWidget(ReturnBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);


        gridLayout->addLayout(verticalLayout_6, 1, 1, 2, 2);

        horizontalSpacer_2 = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(181, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 89, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(ChargeTestWidget);

        QMetaObject::connectSlotsByName(ChargeTestWidget);
    } // setupUi

    void retranslateUi(QWidget *ChargeTestWidget)
    {
        ChargeTestWidget->setWindowTitle(QApplication::translate("ChargeTestWidget", "ChargeTestWidget", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ChargeTestWidget", "\345\205\205\347\224\265\346\265\201\347\250\213\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ChargeTestWidget", "\345\205\205\347\224\265\347\224\265\345\216\213\357\274\232               ", Q_NULLPTR));
        label_9->setText(QApplication::translate("ChargeTestWidget", "V", Q_NULLPTR));
        radioButton_ConstantCuurrent->setText(QApplication::translate("ChargeTestWidget", "\346\201\222\346\265\201\345\205\205\347\224\265      ", Q_NULLPTR));
        radioButton_changecurrent->setText(QApplication::translate("ChargeTestWidget", "\347\255\211\351\227\264\351\232\224\347\224\265\346\265\201\345\205\205\347\224\265    ", Q_NULLPTR));
        label_13->setText(QApplication::translate("ChargeTestWidget", "A", Q_NULLPTR));
        checkBox_voltageAccuracy->setText(QApplication::translate("ChargeTestWidget", "\347\255\211Soc\351\227\264\351\232\224\350\257\273\345\217\226\347\224\265\345\216\213", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ChargeTestWidget", "\346\210\252\346\255\242\346\235\241\344\273\266\357\274\232", Q_NULLPTR));
        radioButton_fullcharge->setText(QApplication::translate("ChargeTestWidget", "\346\273\241\345\205\205", Q_NULLPTR));
        radioButton_overShoot->setText(QApplication::translate("ChargeTestWidget", "\350\277\207\345\205\205", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("ChargeTestWidget", "\345\205\205\347\224\265\350\207\263SOC\342\211\245          ", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChargeTestWidget", "%", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("ChargeTestWidget", "\345\205\205\347\224\265\350\207\263\345\215\225\344\275\223\347\224\265\345\216\213\342\211\245   ", Q_NULLPTR));
        label_10->setText(QApplication::translate("ChargeTestWidget", "V", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("ChargeTestWidget", "\345\205\205\347\224\265\350\207\263\347\224\265\346\261\240\347\224\265\345\216\213\342\211\245   ", Q_NULLPTR));
        label_11->setText(QApplication::translate("ChargeTestWidget", "V", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("ChargeTestWidget", "\345\205\205\347\224\265\350\207\263\347\224\265\346\265\201\342\211\244         ", Q_NULLPTR));
        label_12->setText(QApplication::translate("ChargeTestWidget", "A", Q_NULLPTR));
        radioButton_8->setText(QApplication::translate("ChargeTestWidget", "\345\205\205\347\224\265\350\207\263\345\256\271\351\207\217\342\211\245         ", Q_NULLPTR));
        label_14->setText(QApplication::translate("ChargeTestWidget", "Ah", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("ChargeTestWidget", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("ChargeTestWidget", "ModifyBtn", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("ChargeTestWidget", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChargeTestWidget: public Ui_ChargeTestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGETESTWIDGET_H
