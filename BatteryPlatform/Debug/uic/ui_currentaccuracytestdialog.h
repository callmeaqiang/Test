/********************************************************************************
** Form generated from reading UI file 'currentaccuracytestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTACCURACYTESTDIALOG_H
#define UI_CURRENTACCURACYTESTDIALOG_H

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

class Ui_CurrentAccuracyTestDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_testname;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_3;
    QLineEdit *lineEdit_voltage;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_4;
    QLineEdit *lineEdit_max_current;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *lineEdit_current_gap;
    QLabel *label_17;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_error_percentage;
    QLineEdit *lineEdit_error_percentage;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_error_current;
    QLineEdit *lineEdit_error_current;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *CurrentAccuracyTestDialog)
    {
        if (CurrentAccuracyTestDialog->objectName().isEmpty())
            CurrentAccuracyTestDialog->setObjectName(QStringLiteral("CurrentAccuracyTestDialog"));
        CurrentAccuracyTestDialog->resize(399, 350);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/res/battery.png"), QSize(), QIcon::Normal, QIcon::Off);
        CurrentAccuracyTestDialog->setWindowIcon(icon);
        CurrentAccuracyTestDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	background-color: rgb(66, 66, 66);\n"
"    border-radius: 8px;\n"
"    padding: 10px 10px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 24px;\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {   \n"
"	\n"
"	background-color: rgb(33, 33, 33);\n"
"}\n"
"QPushButton:pressed {\n"
"    padding-left:13px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:13px;\n"
"}\n"
"QDialog{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(CurrentAccuracyTestDialog);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(CurrentAccuracyTestDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_testname = new QLineEdit(CurrentAccuracyTestDialog);
        lineEdit_testname->setObjectName(QStringLiteral("lineEdit_testname"));
        lineEdit_testname->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(lineEdit_testname);


        verticalLayout_2->addLayout(horizontalLayout_4);

        groupBox_4 = new QGroupBox(CurrentAccuracyTestDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_22->addWidget(label_3);

        lineEdit_voltage = new QLineEdit(groupBox_4);
        lineEdit_voltage->setObjectName(QStringLiteral("lineEdit_voltage"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_voltage->sizePolicy().hasHeightForWidth());
        lineEdit_voltage->setSizePolicy(sizePolicy1);
        lineEdit_voltage->setMinimumSize(QSize(140, 0));
        lineEdit_voltage->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_22->addWidget(lineEdit_voltage);

        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);

        horizontalLayout_22->addWidget(label_18);


        verticalLayout_3->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_23->addWidget(label_4);

        lineEdit_max_current = new QLineEdit(groupBox_4);
        lineEdit_max_current->setObjectName(QStringLiteral("lineEdit_max_current"));
        sizePolicy1.setHeightForWidth(lineEdit_max_current->sizePolicy().hasHeightForWidth());
        lineEdit_max_current->setSizePolicy(sizePolicy1);
        lineEdit_max_current->setMinimumSize(QSize(140, 0));
        lineEdit_max_current->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_23->addWidget(lineEdit_max_current);

        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);

        horizontalLayout_23->addWidget(label_19);


        verticalLayout_3->addLayout(horizontalLayout_23);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_5->addWidget(label_16);

        lineEdit_current_gap = new QLineEdit(groupBox_4);
        lineEdit_current_gap->setObjectName(QStringLiteral("lineEdit_current_gap"));
        sizePolicy1.setHeightForWidth(lineEdit_current_gap->sizePolicy().hasHeightForWidth());
        lineEdit_current_gap->setSizePolicy(sizePolicy1);
        lineEdit_current_gap->setMinimumSize(QSize(140, 0));
        lineEdit_current_gap->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_5->addWidget(lineEdit_current_gap);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_17);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox = new QGroupBox(CurrentAccuracyTestDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_error_percentage = new QRadioButton(groupBox);
        radioButton_error_percentage->setObjectName(QStringLiteral("radioButton_error_percentage"));

        horizontalLayout->addWidget(radioButton_error_percentage);

        lineEdit_error_percentage = new QLineEdit(groupBox);
        lineEdit_error_percentage->setObjectName(QStringLiteral("lineEdit_error_percentage"));
        lineEdit_error_percentage->setMinimumSize(QSize(136, 0));
        lineEdit_error_percentage->setMaximumSize(QSize(136, 16777215));

        horizontalLayout->addWidget(lineEdit_error_percentage);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label_21);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton_error_current = new QRadioButton(groupBox);
        radioButton_error_current->setObjectName(QStringLiteral("radioButton_error_current"));

        horizontalLayout_2->addWidget(radioButton_error_current);

        lineEdit_error_current = new QLineEdit(groupBox);
        lineEdit_error_current->setObjectName(QStringLiteral("lineEdit_error_current"));
        lineEdit_error_current->setMinimumSize(QSize(140, 0));
        lineEdit_error_current->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_2->addWidget(lineEdit_error_current);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy2.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label_20);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        SaveBtn = new QPushButton(CurrentAccuracyTestDialog);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(SaveBtn->sizePolicy().hasHeightForWidth());
        SaveBtn->setSizePolicy(sizePolicy3);
        SaveBtn->setMinimumSize(QSize(0, 0));
        SaveBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(CurrentAccuracyTestDialog);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));
        sizePolicy3.setHeightForWidth(ModifyBtn->sizePolicy().hasHeightForWidth());
        ModifyBtn->setSizePolicy(sizePolicy3);
        ModifyBtn->setMinimumSize(QSize(0, 0));
        ModifyBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(ModifyBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ReturnBtn = new QPushButton(CurrentAccuracyTestDialog);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));
        sizePolicy3.setHeightForWidth(ReturnBtn->sizePolicy().hasHeightForWidth());
        ReturnBtn->setSizePolicy(sizePolicy3);
        ReturnBtn->setMinimumSize(QSize(0, 0));
        ReturnBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(ReturnBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(CurrentAccuracyTestDialog);

        QMetaObject::connectSlotsByName(CurrentAccuracyTestDialog);
    } // setupUi

    void retranslateUi(QDialog *CurrentAccuracyTestDialog)
    {
        CurrentAccuracyTestDialog->setWindowTitle(QApplication::translate("CurrentAccuracyTestDialog", "CurrentAccuracyTestDialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurrentAccuracyTestDialog", "please enter test name:", Q_NULLPTR));
        lineEdit_testname->setText(QString());
        groupBox_4->setTitle(QApplication::translate("CurrentAccuracyTestDialog", "Charge Current Accuracy", Q_NULLPTR));
        label_3->setText(QApplication::translate("CurrentAccuracyTestDialog", "Charge Voltage:", Q_NULLPTR));
        lineEdit_voltage->setInputMask(QString());
        lineEdit_voltage->setPlaceholderText(QString());
        label_18->setText(QApplication::translate("CurrentAccuracyTestDialog", "V", Q_NULLPTR));
        label_4->setText(QApplication::translate("CurrentAccuracyTestDialog", "Max Current:", Q_NULLPTR));
        lineEdit_max_current->setInputMask(QString());
        lineEdit_max_current->setPlaceholderText(QString());
        label_19->setText(QApplication::translate("CurrentAccuracyTestDialog", "A", Q_NULLPTR));
        label_16->setText(QApplication::translate("CurrentAccuracyTestDialog", "Current Gap:", Q_NULLPTR));
        lineEdit_current_gap->setPlaceholderText(QString());
        label_17->setText(QApplication::translate("CurrentAccuracyTestDialog", "A", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CurrentAccuracyTestDialog", "Error Type", Q_NULLPTR));
        radioButton_error_percentage->setText(QApplication::translate("CurrentAccuracyTestDialog", "Error percentage", Q_NULLPTR));
        lineEdit_error_percentage->setText(QApplication::translate("CurrentAccuracyTestDialog", "1", Q_NULLPTR));
        label_21->setText(QApplication::translate("CurrentAccuracyTestDialog", "%", Q_NULLPTR));
        radioButton_error_current->setText(QApplication::translate("CurrentAccuracyTestDialog", "Error current", Q_NULLPTR));
        lineEdit_error_current->setText(QApplication::translate("CurrentAccuracyTestDialog", "0.2", Q_NULLPTR));
        label_20->setText(QApplication::translate("CurrentAccuracyTestDialog", "A", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("CurrentAccuracyTestDialog", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("CurrentAccuracyTestDialog", "Modify", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("CurrentAccuracyTestDialog", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurrentAccuracyTestDialog: public Ui_CurrentAccuracyTestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTACCURACYTESTDIALOG_H
