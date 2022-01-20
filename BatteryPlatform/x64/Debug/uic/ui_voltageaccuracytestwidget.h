/********************************************************************************
** Form generated from reading UI file 'voltageaccuracytestwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLTAGEACCURACYTESTWIDGET_H
#define UI_VOLTAGEACCURACYTESTWIDGET_H

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

class Ui_VoltageAccuracyTestWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddChargeBtn;
    QPushButton *AddDischargeBtn;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QPushButton *ReturnBtn;
    QTabWidget *tabWidget;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *VoltageAccuracyTestWidget)
    {
        if (VoltageAccuracyTestWidget->objectName().isEmpty())
            VoltageAccuracyTestWidget->setObjectName(QStringLiteral("VoltageAccuracyTestWidget"));
        VoltageAccuracyTestWidget->resize(1558, 920);
        gridLayout = new QGridLayout(VoltageAccuracyTestWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        AddChargeBtn = new QPushButton(VoltageAccuracyTestWidget);
        AddChargeBtn->setObjectName(QStringLiteral("AddChargeBtn"));

        horizontalLayout->addWidget(AddChargeBtn);

        AddDischargeBtn = new QPushButton(VoltageAccuracyTestWidget);
        AddDischargeBtn->setObjectName(QStringLiteral("AddDischargeBtn"));

        horizontalLayout->addWidget(AddDischargeBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(VoltageAccuracyTestWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(400, 700));
        tableWidget->setMaximumSize(QSize(400, 700));
        tableWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        SaveBtn = new QPushButton(VoltageAccuracyTestWidget);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SaveBtn->sizePolicy().hasHeightForWidth());
        SaveBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(SaveBtn);

        ModifyBtn = new QPushButton(VoltageAccuracyTestWidget);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ModifyBtn->sizePolicy().hasHeightForWidth());
        ModifyBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(ModifyBtn);

        ReturnBtn = new QPushButton(VoltageAccuracyTestWidget);
        ReturnBtn->setObjectName(QStringLiteral("ReturnBtn"));
        sizePolicy2.setHeightForWidth(ReturnBtn->sizePolicy().hasHeightForWidth());
        ReturnBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(ReturnBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        tabWidget = new QTabWidget(VoltageAccuracyTestWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(1000, 800));
        tabWidget->setMaximumSize(QSize(1000, 800));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::pane\n"
"{\n"
"	border: -1px;\n"
"	top:-2px;\n"
"	left: 1px;\n"
"}"));

        horizontalLayout_3->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 2, 2);

        horizontalSpacer_2 = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 2, 1, 1);


        retranslateUi(VoltageAccuracyTestWidget);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(VoltageAccuracyTestWidget);
    } // setupUi

    void retranslateUi(QWidget *VoltageAccuracyTestWidget)
    {
        VoltageAccuracyTestWidget->setWindowTitle(QApplication::translate("VoltageAccuracyTestWidget", "VoltageAccuracyTestWidget", Q_NULLPTR));
        AddChargeBtn->setText(QApplication::translate("VoltageAccuracyTestWidget", "AddCharge", Q_NULLPTR));
        AddDischargeBtn->setText(QApplication::translate("VoltageAccuracyTestWidget", "AddDischarge", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("VoltageAccuracyTestWidget", "SaveBtn", Q_NULLPTR));
        ModifyBtn->setText(QApplication::translate("VoltageAccuracyTestWidget", "Modify", Q_NULLPTR));
        ReturnBtn->setText(QApplication::translate("VoltageAccuracyTestWidget", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VoltageAccuracyTestWidget: public Ui_VoltageAccuracyTestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLTAGEACCURACYTESTWIDGET_H
