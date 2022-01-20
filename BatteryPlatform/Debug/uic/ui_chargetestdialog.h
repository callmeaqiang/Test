/********************************************************************************
** Form generated from reading UI file 'chargetestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGETESTDIALOG_H
#define UI_CHARGETESTDIALOG_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChargeTestDialog
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
    QLineEdit *lineEdit_Voltage_simple;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QLineEdit *lineEdit_Current_simple;
    QLabel *label_13;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_fullCharge;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_SOC;
    QLineEdit *lineEdit_SOC;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ChargeTestDialog)
    {
        if (ChargeTestDialog->objectName().isEmpty())
            ChargeTestDialog->setObjectName(QStringLiteral("ChargeTestDialog"));
        ChargeTestDialog->resize(404, 346);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/res/battery.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChargeTestDialog->setWindowIcon(icon);
        ChargeTestDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QWidget#ChargeTestDialog{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(ChargeTestDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(ChargeTestDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_testname = new QLineEdit(ChargeTestDialog);
        lineEdit_testname->setObjectName(QStringLiteral("lineEdit_testname"));
        lineEdit_testname->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(lineEdit_testname);


        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(ChargeTestDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_15->addWidget(label);

        lineEdit_Voltage_simple = new QLineEdit(groupBox);
        lineEdit_Voltage_simple->setObjectName(QStringLiteral("lineEdit_Voltage_simple"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_Voltage_simple->sizePolicy().hasHeightForWidth());
        lineEdit_Voltage_simple->setSizePolicy(sizePolicy1);
        lineEdit_Voltage_simple->setMinimumSize(QSize(144, 0));
        lineEdit_Voltage_simple->setMaximumSize(QSize(144, 16777215));

        horizontalLayout_15->addWidget(lineEdit_Voltage_simple);

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

        lineEdit_Current_simple = new QLineEdit(groupBox);
        lineEdit_Current_simple->setObjectName(QStringLiteral("lineEdit_Current_simple"));
        sizePolicy1.setHeightForWidth(lineEdit_Current_simple->sizePolicy().hasHeightForWidth());
        lineEdit_Current_simple->setSizePolicy(sizePolicy1);
        lineEdit_Current_simple->setMinimumSize(QSize(144, 0));
        lineEdit_Current_simple->setMaximumSize(QSize(144, 16777215));

        horizontalLayout_4->addWidget(lineEdit_Current_simple);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_13);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ChargeTestDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        radioButton_fullCharge = new QRadioButton(groupBox_2);
        radioButton_fullCharge->setObjectName(QStringLiteral("radioButton_fullCharge"));

        verticalLayout_2->addWidget(radioButton_fullCharge);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_SOC = new QRadioButton(groupBox_2);
        radioButton_SOC->setObjectName(QStringLiteral("radioButton_SOC"));

        horizontalLayout->addWidget(radioButton_SOC);

        lineEdit_SOC = new QLineEdit(groupBox_2);
        lineEdit_SOC->setObjectName(QStringLiteral("lineEdit_SOC"));
        lineEdit_SOC->setMinimumSize(QSize(140, 0));
        lineEdit_SOC->setMaximumSize(QSize(140, 16777215));

        horizontalLayout->addWidget(lineEdit_SOC);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        SaveBtn = new QPushButton(ChargeTestDialog);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout_2->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(ChargeTestDialog);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout_2->addWidget(ModifyBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        ReturnBtn = new QPushButton(ChargeTestDialog);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout_2->addWidget(ReturnBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(ChargeTestDialog);

        QMetaObject::connectSlotsByName(ChargeTestDialog);
    } // setupUi

    void retranslateUi(QDialog *ChargeTestDialog)
    {
        ChargeTestDialog->setWindowTitle(QApplication::translate("ChargeTestDialog", "ChargeTestDialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChargeTestDialog", "please enter test name:", Q_NULLPTR));
        lineEdit_testname->setText(QString());
        groupBox->setTitle(QApplication::translate("ChargeTestDialog", "simple charge\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ChargeTestDialog", "charge voltage\357\274\232", Q_NULLPTR));
        lineEdit_Voltage_simple->setInputMask(QString());
        lineEdit_Voltage_simple->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("ChargeTestDialog", "V", Q_NULLPTR));
        label_15->setText(QApplication::translate("ChargeTestDialog", "charge current\357\274\232", Q_NULLPTR));
        lineEdit_Current_simple->setPlaceholderText(QString());
        label_13->setText(QApplication::translate("ChargeTestDialog", "A", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ChargeTestDialog", "Cut-of Condition\357\274\232", Q_NULLPTR));
        radioButton_fullCharge->setText(QApplication::translate("ChargeTestDialog", "full Charge", Q_NULLPTR));
        radioButton_SOC->setText(QApplication::translate("ChargeTestDialog", "Charge To SOC>=", Q_NULLPTR));
        label_14->setText(QApplication::translate("ChargeTestDialog", "%", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("ChargeTestDialog", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("ChargeTestDialog", "ModifyBtn", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("ChargeTestDialog", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChargeTestDialog: public Ui_ChargeTestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGETESTDIALOG_H
