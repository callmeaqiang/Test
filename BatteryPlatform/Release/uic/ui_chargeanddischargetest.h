/********************************************************************************
** Form generated from reading UI file 'chargeanddischargetest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEANDDISCHARGETEST_H
#define UI_CHARGEANDDISCHARGETEST_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChargeAndDischargeTest
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_4;
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

    void setupUi(QDialog *ChargeAndDischargeTest)
    {
        if (ChargeAndDischargeTest->objectName().isEmpty())
            ChargeAndDischargeTest->setObjectName(QStringLiteral("ChargeAndDischargeTest"));
        ChargeAndDischargeTest->resize(849, 682);
        layoutWidget = new QWidget(ChargeAndDischargeTest);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 360, 411, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        SaveBtn = new QPushButton(layoutWidget);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout_2->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(layoutWidget);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout_2->addWidget(ModifyBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        ReturnBtn = new QPushButton(layoutWidget);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout_2->addWidget(ReturnBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        groupBox = new QGroupBox(ChargeAndDischargeTest);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(140, 60, 581, 191));
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_chargeVoltage->sizePolicy().hasHeightForWidth());
        lineEdit_chargeVoltage->setSizePolicy(sizePolicy);
        lineEdit_chargeVoltage->setMinimumSize(QSize(140, 0));
        lineEdit_chargeVoltage->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_15->addWidget(lineEdit_chargeVoltage);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

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
        sizePolicy.setHeightForWidth(lineEdit_chargeCurrent->sizePolicy().hasHeightForWidth());
        lineEdit_chargeCurrent->setSizePolicy(sizePolicy);
        lineEdit_chargeCurrent->setMinimumSize(QSize(140, 0));
        lineEdit_chargeCurrent->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_4->addWidget(lineEdit_chargeCurrent);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

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
        sizePolicy.setHeightForWidth(lineEdit_dischargeCurrent->sizePolicy().hasHeightForWidth());
        lineEdit_dischargeCurrent->setSizePolicy(sizePolicy);
        lineEdit_dischargeCurrent->setMinimumSize(QSize(140, 0));
        lineEdit_dischargeCurrent->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_5->addWidget(lineEdit_dischargeCurrent);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_14);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(ChargeAndDischargeTest);

        QMetaObject::connectSlotsByName(ChargeAndDischargeTest);
    } // setupUi

    void retranslateUi(QDialog *ChargeAndDischargeTest)
    {
        ChargeAndDischargeTest->setWindowTitle(QApplication::translate("ChargeAndDischargeTest", "ChargeAndDischargeTest", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("ChargeAndDischargeTest", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("ChargeAndDischargeTest", "ModifyBtn", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("ChargeAndDischargeTest", "Return", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ChargeAndDischargeTest", "Charge Parameter Setting\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ChargeAndDischargeTest", "charge voltage\357\274\232                ", Q_NULLPTR));
        lineEdit_chargeVoltage->setInputMask(QString());
        lineEdit_chargeVoltage->setPlaceholderText(QApplication::translate("ChargeAndDischargeTest", "/0.1v", Q_NULLPTR));
        label_9->setText(QApplication::translate("ChargeAndDischargeTest", "/0.1V", Q_NULLPTR));
        label_15->setText(QApplication::translate("ChargeAndDischargeTest", "Standard charge current\357\274\232                ", Q_NULLPTR));
        lineEdit_chargeCurrent->setPlaceholderText(QApplication::translate("ChargeAndDischargeTest", "/0.1A", Q_NULLPTR));
        label_13->setText(QApplication::translate("ChargeAndDischargeTest", "/0.1A", Q_NULLPTR));
        label_16->setText(QApplication::translate("ChargeAndDischargeTest", " Fast discharge current\357\274\232                ", Q_NULLPTR));
        lineEdit_dischargeCurrent->setPlaceholderText(QApplication::translate("ChargeAndDischargeTest", "/0.1A", Q_NULLPTR));
        label_14->setText(QApplication::translate("ChargeAndDischargeTest", "/0.1A", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChargeAndDischargeTest: public Ui_ChargeAndDischargeTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEANDDISCHARGETEST_H
