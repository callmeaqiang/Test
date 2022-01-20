/********************************************************************************
** Form generated from reading UI file 'dischargetestwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCHARGETESTWIDGET_H
#define UI_DISCHARGETESTWIDGET_H

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

class Ui_DischargeTestWidget
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton_constantCurrent;
    QRadioButton *radioButton_changeCurrent;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Current;
    QLabel *label_3;
    QCheckBox *checkBox_voltageAccuracy;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_21;
    QRadioButton *FullDischarge;
    QRadioButton *OverLay;
    QHBoxLayout *horizontalLayout_16;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_Soc;
    QLabel *label;
    QHBoxLayout *horizontalLayout_17;
    QRadioButton *radioButton_4;
    QLineEdit *lineEdit_4;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_18;
    QRadioButton *radioButton_5;
    QLineEdit *lineEdit_5;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_19;
    QRadioButton *radioButton_6;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_20;
    QRadioButton *radioButton_8;
    QLineEdit *lineEdit_8;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *DischargeTestWidget)
    {
        if (DischargeTestWidget->objectName().isEmpty())
            DischargeTestWidget->setObjectName(QStringLiteral("DischargeTestWidget"));
        DischargeTestWidget->resize(1071, 805);
        DischargeTestWidget->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        gridLayout_2 = new QGridLayout(DischargeTestWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 211, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(DischargeTestWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        radioButton_constantCurrent = new QRadioButton(groupBox_2);
        radioButton_constantCurrent->setObjectName(QStringLiteral("radioButton_constantCurrent"));

        verticalLayout_5->addWidget(radioButton_constantCurrent);

        radioButton_changeCurrent = new QRadioButton(groupBox_2);
        radioButton_changeCurrent->setObjectName(QStringLiteral("radioButton_changeCurrent"));

        verticalLayout_5->addWidget(radioButton_changeCurrent);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_Current = new QLineEdit(groupBox_2);
        lineEdit_Current->setObjectName(QStringLiteral("lineEdit_Current"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Current->sizePolicy().hasHeightForWidth());
        lineEdit_Current->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit_Current);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);

        checkBox_voltageAccuracy = new QCheckBox(groupBox_2);
        checkBox_voltageAccuracy->setObjectName(QStringLiteral("checkBox_voltageAccuracy"));

        verticalLayout->addWidget(checkBox_voltageAccuracy);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(DischargeTestWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        FullDischarge = new QRadioButton(groupBox);
        FullDischarge->setObjectName(QStringLiteral("FullDischarge"));

        horizontalLayout_21->addWidget(FullDischarge);

        OverLay = new QRadioButton(groupBox);
        OverLay->setObjectName(QStringLiteral("OverLay"));

        horizontalLayout_21->addWidget(OverLay);


        verticalLayout_2->addLayout(horizontalLayout_21);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(2);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setMinimumSize(QSize(300, 0));

        horizontalLayout_16->addWidget(radioButton_3);

        lineEdit_Soc = new QLineEdit(groupBox);
        lineEdit_Soc->setObjectName(QStringLiteral("lineEdit_Soc"));
        sizePolicy.setHeightForWidth(lineEdit_Soc->sizePolicy().hasHeightForWidth());
        lineEdit_Soc->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(lineEdit_Soc);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(2);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setMinimumSize(QSize(300, 0));

        horizontalLayout_17->addWidget(radioButton_4);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_17->addWidget(lineEdit_4);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_17->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(2);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setMinimumSize(QSize(300, 0));

        horizontalLayout_18->addWidget(radioButton_5);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_18->addWidget(lineEdit_5);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_18->addWidget(label_11);


        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(2);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setMinimumSize(QSize(300, 0));

        horizontalLayout_19->addWidget(radioButton_6);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_19->addWidget(lineEdit_6);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_19->addWidget(label_12);


        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(2);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        radioButton_8 = new QRadioButton(groupBox);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setMinimumSize(QSize(300, 0));

        horizontalLayout_20->addWidget(radioButton_8);

        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_20->addWidget(lineEdit_8);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_20->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout_20);


        verticalLayout_3->addWidget(groupBox);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        SaveBtn = new QPushButton(DischargeTestWidget);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(DischargeTestWidget);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));

        horizontalLayout->addWidget(ModifyBtn);

        ReturnBtn = new QPushButton(DischargeTestWidget);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));

        horizontalLayout->addWidget(ReturnBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(226, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 210, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(DischargeTestWidget);

        QMetaObject::connectSlotsByName(DischargeTestWidget);
    } // setupUi

    void retranslateUi(QWidget *DischargeTestWidget)
    {
        DischargeTestWidget->setWindowTitle(QApplication::translate("DischargeTestWidget", "DischargeTestWidget", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DischargeTestWidget", "\346\224\276\347\224\265\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        radioButton_constantCurrent->setText(QApplication::translate("DischargeTestWidget", "\346\201\222\346\265\201\346\224\276\347\224\265      ", Q_NULLPTR));
        radioButton_changeCurrent->setText(QApplication::translate("DischargeTestWidget", "\347\255\211\347\224\265\346\265\201\345\214\272\351\227\264\346\224\276\347\224\265", Q_NULLPTR));
        label_3->setText(QApplication::translate("DischargeTestWidget", "A", Q_NULLPTR));
        checkBox_voltageAccuracy->setText(QApplication::translate("DischargeTestWidget", "\346\230\257\345\220\246\347\255\211\351\227\264\351\232\224SOC\350\257\273\345\217\226\347\224\265\345\216\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DischargeTestWidget", "\346\210\252\346\255\242\346\235\241\344\273\266\357\274\232", Q_NULLPTR));
        FullDischarge->setText(QApplication::translate("DischargeTestWidget", "\346\273\241\346\224\276", Q_NULLPTR));
        OverLay->setText(QApplication::translate("DischargeTestWidget", "\350\277\207\346\224\276", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("DischargeTestWidget", "\346\224\276\347\224\265\350\207\263SOC\342\211\244        ", Q_NULLPTR));
        label->setText(QApplication::translate("DischargeTestWidget", "%", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("DischargeTestWidget", "\346\224\276\347\224\265\350\207\263\345\215\225\344\275\223\347\224\265\345\216\213\342\211\244   ", Q_NULLPTR));
        label_10->setText(QApplication::translate("DischargeTestWidget", "V", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("DischargeTestWidget", "\346\224\276\347\224\265\350\207\263\347\224\265\346\261\240\347\224\265\345\216\213\342\211\244   ", Q_NULLPTR));
        label_11->setText(QApplication::translate("DischargeTestWidget", "V", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("DischargeTestWidget", "\346\224\276\347\224\265\347\224\265\350\207\263\347\224\265\346\265\201\342\211\244            ", Q_NULLPTR));
        label_12->setText(QApplication::translate("DischargeTestWidget", "A", Q_NULLPTR));
        radioButton_8->setText(QApplication::translate("DischargeTestWidget", "\346\224\276\347\224\265\350\207\263\345\256\271\351\207\217\342\211\244               ", Q_NULLPTR));
        label_14->setText(QApplication::translate("DischargeTestWidget", "Ah", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("DischargeTestWidget", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("DischargeTestWidget", "ModifyBtn", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("DischargeTestWidget", "ReturnBtn", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DischargeTestWidget: public Ui_DischargeTestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCHARGETESTWIDGET_H
