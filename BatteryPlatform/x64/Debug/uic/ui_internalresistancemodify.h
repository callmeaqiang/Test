/********************************************************************************
** Form generated from reading UI file 'internalresistancemodify.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERNALRESISTANCEMODIFY_H
#define UI_INTERNALRESISTANCEMODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
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

class Ui_InternalResistanceModify
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_13;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *chargeCurrentI1;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLineEdit *chargeCurrentI2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLineEdit *chargeI1Time;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLineEdit *chargeI2Time;
    QLabel *label_13;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLineEdit *dischargeCurrentI1;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_16;
    QLineEdit *dischargeCurrentI2;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_18;
    QLineEdit *dischargeI1Time;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_20;
    QLineEdit *dischargeI2Time;
    QLabel *label_21;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *hysteresisMinute;
    QLabel *label_7;
    QLineEdit *hysteresisSecond;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *ConstructBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *ModifyBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *InternalResistanceModify)
    {
        if (InternalResistanceModify->objectName().isEmpty())
            InternalResistanceModify->setObjectName(QStringLiteral("InternalResistanceModify"));
        InternalResistanceModify->resize(1239, 838);
        InternalResistanceModify->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{	\n"
"color: rgb(0, 255, 0);\n"
"	background-color: rgb(0, 0, 145);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QWidget#InternalResistanceModify\n"
"{\n"
"background-color: rgb(147, 147, 147);\n"
"}\n"
"QLabel\n"
"{\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        gridLayout_2 = new QGridLayout(InternalResistanceModify);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(347, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        label = new QLabel(InternalResistanceModify);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 226, 0);"));

        horizontalLayout_8->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));

        verticalLayout_2->addLayout(horizontalLayout_13);

        groupBox = new QGroupBox(InternalResistanceModify);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        chargeCurrentI1 = new QLineEdit(groupBox);
        chargeCurrentI1->setObjectName(QStringLiteral("chargeCurrentI1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chargeCurrentI1->sizePolicy().hasHeightForWidth());
        chargeCurrentI1->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(chargeCurrentI1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        chargeCurrentI2 = new QLineEdit(groupBox);
        chargeCurrentI2->setObjectName(QStringLiteral("chargeCurrentI2"));
        sizePolicy.setHeightForWidth(chargeCurrentI2->sizePolicy().hasHeightForWidth());
        chargeCurrentI2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(chargeCurrentI2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        chargeI1Time = new QLineEdit(groupBox);
        chargeI1Time->setObjectName(QStringLiteral("chargeI1Time"));
        sizePolicy.setHeightForWidth(chargeI1Time->sizePolicy().hasHeightForWidth());
        chargeI1Time->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(chargeI1Time);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);

        chargeI2Time = new QLineEdit(groupBox);
        chargeI2Time->setObjectName(QStringLiteral("chargeI2Time"));
        sizePolicy.setHeightForWidth(chargeI2Time->sizePolicy().hasHeightForWidth());
        chargeI2Time->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(chargeI2Time);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(InternalResistanceModify);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_7->addWidget(label_14);

        dischargeCurrentI1 = new QLineEdit(groupBox_2);
        dischargeCurrentI1->setObjectName(QStringLiteral("dischargeCurrentI1"));
        sizePolicy.setHeightForWidth(dischargeCurrentI1->sizePolicy().hasHeightForWidth());
        dischargeCurrentI1->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(dischargeCurrentI1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_7->addWidget(label_15);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_9->addWidget(label_16);

        dischargeCurrentI2 = new QLineEdit(groupBox_2);
        dischargeCurrentI2->setObjectName(QStringLiteral("dischargeCurrentI2"));
        sizePolicy.setHeightForWidth(dischargeCurrentI2->sizePolicy().hasHeightForWidth());
        dischargeCurrentI2->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(dischargeCurrentI2);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_9->addWidget(label_17);


        gridLayout->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_11->addWidget(label_18);

        dischargeI1Time = new QLineEdit(groupBox_2);
        dischargeI1Time->setObjectName(QStringLiteral("dischargeI1Time"));
        sizePolicy.setHeightForWidth(dischargeI1Time->sizePolicy().hasHeightForWidth());
        dischargeI1Time->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(dischargeI1Time);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_11->addWidget(label_19);


        gridLayout->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_12->addWidget(label_20);

        dischargeI2Time = new QLineEdit(groupBox_2);
        dischargeI2Time->setObjectName(QStringLiteral("dischargeI2Time"));
        sizePolicy.setHeightForWidth(dischargeI2Time->sizePolicy().hasHeightForWidth());
        dischargeI2Time->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(dischargeI2Time);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_12->addWidget(label_21);


        gridLayout->addLayout(horizontalLayout_12, 3, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_5 = new QGroupBox(InternalResistanceModify);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        horizontalLayout = new QHBoxLayout(groupBox_5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        hysteresisMinute = new QLineEdit(groupBox_5);
        hysteresisMinute->setObjectName(QStringLiteral("hysteresisMinute"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hysteresisMinute->sizePolicy().hasHeightForWidth());
        hysteresisMinute->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(hysteresisMinute);

        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        hysteresisSecond = new QLineEdit(groupBox_5);
        hysteresisSecond->setObjectName(QStringLiteral("hysteresisSecond"));
        sizePolicy1.setHeightForWidth(hysteresisSecond->sizePolicy().hasHeightForWidth());
        hysteresisSecond->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(hysteresisSecond);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);


        horizontalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(groupBox_5);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        ConstructBtn = new QPushButton(InternalResistanceModify);
        ConstructBtn->setObjectName(QStringLiteral("ConstructBtn"));

        horizontalLayout_10->addWidget(ConstructBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        ModifyBtn = new QPushButton(InternalResistanceModify);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout_10->addWidget(ModifyBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        ReturnBtn = new QPushButton(InternalResistanceModify);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout_10->addWidget(ReturnBtn);


        verticalLayout_3->addLayout(horizontalLayout_10);


        gridLayout_2->addLayout(verticalLayout_3, 1, 1, 2, 1);

        horizontalSpacer_5 = new QSpacerItem(347, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 77, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(InternalResistanceModify);

        QMetaObject::connectSlotsByName(InternalResistanceModify);
    } // setupUi

    void retranslateUi(QWidget *InternalResistanceModify)
    {
        InternalResistanceModify->setWindowTitle(QApplication::translate("InternalResistanceModify", "InternalResistanceModify", Q_NULLPTR));
        label->setText(QApplication::translate("InternalResistanceModify", "\347\224\265\351\230\273\346\265\213\350\257\225\345\217\202\346\225\260\351\205\215\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("InternalResistanceModify", "\345\205\205\347\224\265\347\224\265\351\230\273\346\265\213\350\257\225", Q_NULLPTR));
        label_3->setText(QApplication::translate("InternalResistanceModify", "\347\224\265\346\265\201I1      ", Q_NULLPTR));
        label_4->setText(QApplication::translate("InternalResistanceModify", "A", Q_NULLPTR));
        label_9->setText(QApplication::translate("InternalResistanceModify", "\347\224\265\346\265\201I2      ", Q_NULLPTR));
        label_5->setText(QApplication::translate("InternalResistanceModify", "A", Q_NULLPTR));
        label_12->setText(QApplication::translate("InternalResistanceModify", "I1\346\265\213\351\207\217\346\227\266\351\227\264", Q_NULLPTR));
        label_11->setText(QApplication::translate("InternalResistanceModify", "s", Q_NULLPTR));
        label_10->setText(QApplication::translate("InternalResistanceModify", "I2\346\265\213\351\207\217\346\227\266\351\227\264", Q_NULLPTR));
        label_13->setText(QApplication::translate("InternalResistanceModify", "s", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("InternalResistanceModify", "\346\224\276\347\224\265\347\224\265\351\230\273\346\265\213\350\257\225", Q_NULLPTR));
        label_14->setText(QApplication::translate("InternalResistanceModify", "\347\224\265\346\265\201I1      ", Q_NULLPTR));
        label_15->setText(QApplication::translate("InternalResistanceModify", "A", Q_NULLPTR));
        label_16->setText(QApplication::translate("InternalResistanceModify", "\347\224\265\346\265\201I2      ", Q_NULLPTR));
        label_17->setText(QApplication::translate("InternalResistanceModify", "A", Q_NULLPTR));
        label_18->setText(QApplication::translate("InternalResistanceModify", "I1\346\265\213\351\207\217\346\227\266\351\227\264", Q_NULLPTR));
        label_19->setText(QApplication::translate("InternalResistanceModify", "s", Q_NULLPTR));
        label_20->setText(QApplication::translate("InternalResistanceModify", "I2\346\265\213\351\207\217\346\227\266\351\227\264", Q_NULLPTR));
        label_21->setText(QApplication::translate("InternalResistanceModify", "s", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("InternalResistanceModify", "\351\235\231\347\275\256\346\265\201\347\250\213", Q_NULLPTR));
        label_6->setText(QApplication::translate("InternalResistanceModify", "\351\235\231\347\275\256\346\227\266\351\225\277", Q_NULLPTR));
        label_7->setText(QApplication::translate("InternalResistanceModify", "min", Q_NULLPTR));
        label_8->setText(QApplication::translate("InternalResistanceModify", "s", Q_NULLPTR));
        ConstructBtn->setText(QApplication::translate("InternalResistanceModify", "Construct", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("InternalResistanceModify", "Modify", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("InternalResistanceModify", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InternalResistanceModify: public Ui_InternalResistanceModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERNALRESISTANCEMODIFY_H
