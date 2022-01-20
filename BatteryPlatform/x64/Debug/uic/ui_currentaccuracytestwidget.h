/********************************************************************************
** Form generated from reading UI file 'currentaccuracytestwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTACCURACYTESTWIDGET_H
#define UI_CURRENTACCURACYTESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurrentAccuracyTestWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddChargeBtn;
    QPushButton *AddDischargeBtn;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QPushButton *ReturnBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CurrentAccuracyTestWidget)
    {
        if (CurrentAccuracyTestWidget->objectName().isEmpty())
            CurrentAccuracyTestWidget->setObjectName(QStringLiteral("CurrentAccuracyTestWidget"));
        CurrentAccuracyTestWidget->resize(1468, 964);
        CurrentAccuracyTestWidget->setStyleSheet(QString::fromUtf8("QPushButton#AddDischargeBtn\n"
"{\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    padding: 16px 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    margin: 4px 2px;\n"
"    background-color: white;\n"
"    color: black;\n"
"    border: 2px solid #f44336;\n"
"}\n"
"\n"
"QPushButton#AddDischargeBtn:hover\n"
"{\n"
"    background-color: #f44336;\n"
"    color: white;\n"
"}\n"
"QPushButton#AddDischargeBtn:pressed\n"
"{\n"
"    background-color: #06AD56;\n"
"}\n"
"QPushButton#AddChargeBtn {\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    padding: 16px 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    margin: 4px 2px;\n"
"    background-color: white;\n"
"    color: black;\n"
"    border: 2px solid #008cba;\n"
"}\n"
"QPushButton#AddChargeBtn:hover\n"
"{\n"
"    background-color: #008cba;\n"
"    color: white;\n"
""
                        "}\n"
"QPushButton#AddChargeBtn:pressed\n"
"{\n"
"    background-color: #06AD56;\n"
"}\n"
"QPushButton#SaveBtn,#ModifyBtn,#ReturnBtn\n"
"{\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    padding: 16px 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    margin: 4px 2px;\n"
"    background-color: white;\n"
"    color: black;\n"
"    border: 2px solid #4CAF50;\n"
"}\n"
"\n"
"QPushButton#SaveBtn:hover\n"
"{\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"}\n"
"QPushButton#ModifyBtn:hover\n"
"{\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"}\n"
"QPushButton#ReturnBtn:hover\n"
"{\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"}"));
        gridLayout = new QGridLayout(CurrentAccuracyTestWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(6, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidget = new QTableWidget(CurrentAccuracyTestWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(400, 0));
        tableWidget->setMaximumSize(QSize(400, 16777215));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableView\n"
"{\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"    alternate-background-color:#e3edf9;\n"
"    font:16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    \n"
"	color: rgb(0, 85, 255);\n"
"    gridline-color: #ccddf0;\n"
"}\n"
" \n"
"QTableView::item\n"
"{  \n"
"    font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color:#677483;\n"
"    gridline-color: #ccddf0;\n"
"}\n"
" \n"
"QTableView::item:selected\n"
"{  \n"
"    color:#677483;\n"
"}\n"
" \n"
"QHeaderView::section { \n"
"    color: black;\n"
"    font:bold 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    text-align:center;\n"
"    height:32px;\n"
"    background-color: #d1dff0;\n"
"    border:1px solid #8faac9;\n"
"    border-left:none;\n"
"}\n"
" \n"
"// border-left:none;\351\230\262\346\255\242\344\270\255\351\227\264\350\241\250\345\244\264\347\232\204border\351\207\215\345\217\240\n"
"QHeaderView::section:first\n"
"{\n"
"    border-left:1px solid #8faac9;\n"
"}"));

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        AddChargeBtn = new QPushButton(CurrentAccuracyTestWidget);
        AddChargeBtn->setObjectName(QStringLiteral("AddChargeBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddChargeBtn->sizePolicy().hasHeightForWidth());
        AddChargeBtn->setSizePolicy(sizePolicy1);
        AddChargeBtn->setMinimumSize(QSize(0, 0));
        AddChargeBtn->setMaximumSize(QSize(16777215, 16777215));
        AddChargeBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(AddChargeBtn);

        AddDischargeBtn = new QPushButton(CurrentAccuracyTestWidget);
        AddDischargeBtn->setObjectName(QStringLiteral("AddDischargeBtn"));
        sizePolicy1.setHeightForWidth(AddDischargeBtn->sizePolicy().hasHeightForWidth());
        AddDischargeBtn->setSizePolicy(sizePolicy1);
        AddDischargeBtn->setMinimumSize(QSize(0, 0));
        AddDischargeBtn->setMaximumSize(QSize(16777215, 16777215));
        AddDischargeBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(AddDischargeBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(CurrentAccuracyTestWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(1000, 800));
        tabWidget->setMaximumSize(QSize(1000, 800));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::pane\n"
"{\n"
"	border: -1px;\n"
"	top:-2px;\n"
"	left: 1px;\n"
"}"));
        tabWidget->setTabShape(QTabWidget::Rounded);

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        SaveBtn = new QPushButton(CurrentAccuracyTestWidget);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));
        sizePolicy1.setHeightForWidth(SaveBtn->sizePolicy().hasHeightForWidth());
        SaveBtn->setSizePolicy(sizePolicy1);
        SaveBtn->setMinimumSize(QSize(0, 0));
        SaveBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(CurrentAccuracyTestWidget);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));
        sizePolicy1.setHeightForWidth(ModifyBtn->sizePolicy().hasHeightForWidth());
        ModifyBtn->setSizePolicy(sizePolicy1);
        ModifyBtn->setMinimumSize(QSize(0, 0));
        ModifyBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(ModifyBtn);

        ReturnBtn = new QPushButton(CurrentAccuracyTestWidget);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));
        sizePolicy1.setHeightForWidth(ReturnBtn->sizePolicy().hasHeightForWidth());
        ReturnBtn->setSizePolicy(sizePolicy1);
        ReturnBtn->setMinimumSize(QSize(0, 0));
        ReturnBtn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(ReturnBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 2, 2);

        horizontalSpacer_3 = new QSpacerItem(7, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);


        retranslateUi(CurrentAccuracyTestWidget);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CurrentAccuracyTestWidget);
    } // setupUi

    void retranslateUi(QWidget *CurrentAccuracyTestWidget)
    {
        CurrentAccuracyTestWidget->setWindowTitle(QApplication::translate("CurrentAccuracyTestWidget", "CurrentAccuracyTestWidget", Q_NULLPTR));
        AddChargeBtn->setText(QApplication::translate("CurrentAccuracyTestWidget", "chargeTest", Q_NULLPTR));
        AddDischargeBtn->setText(QApplication::translate("CurrentAccuracyTestWidget", "dischargeTest", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("CurrentAccuracyTestWidget", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("CurrentAccuracyTestWidget", "Modify", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("CurrentAccuracyTestWidget", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurrentAccuracyTestWidget: public Ui_CurrentAccuracyTestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTACCURACYTESTWIDGET_H
