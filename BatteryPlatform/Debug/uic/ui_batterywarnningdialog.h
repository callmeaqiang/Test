/********************************************************************************
** Form generated from reading UI file 'batterywarnningdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYWARNNINGDIALOG_H
#define UI_BATTERYWARNNINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatteryWarnningDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTableWidget *tableWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_DealAll;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *BatteryWarnningDialog)
    {
        if (BatteryWarnningDialog->objectName().isEmpty())
            BatteryWarnningDialog->setObjectName(QStringLiteral("BatteryWarnningDialog"));
        BatteryWarnningDialog->resize(1115, 812);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/res/warning.png"), QSize(), QIcon::Normal, QIcon::Off);
        BatteryWarnningDialog->setWindowIcon(icon);
        BatteryWarnningDialog->setStyleSheet(QLatin1String("QDialog{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(BatteryWarnningDialog);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        splitter = new QSplitter(BatteryWarnningDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(2);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        tableWidget = new QTableWidget(widget_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);

        splitter->addWidget(widget_2);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        tableWidget_2 = new QTableWidget(widget);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        verticalLayout->addWidget(tableWidget_2);

        splitter->addWidget(widget);

        verticalLayout_2->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_DealAll = new QPushButton(BatteryWarnningDialog);
        pushButton_DealAll->setObjectName(QStringLiteral("pushButton_DealAll"));

        horizontalLayout->addWidget(pushButton_DealAll);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(BatteryWarnningDialog);

        QMetaObject::connectSlotsByName(BatteryWarnningDialog);
    } // setupUi

    void retranslateUi(QDialog *BatteryWarnningDialog)
    {
        BatteryWarnningDialog->setWindowTitle(QApplication::translate("BatteryWarnningDialog", "BatteryWarnningDialog", Q_NULLPTR));
        label->setText(QApplication::translate("BatteryWarnningDialog", "Untreated", Q_NULLPTR));
        label_2->setText(QApplication::translate("BatteryWarnningDialog", "Processed", Q_NULLPTR));
        pushButton_DealAll->setText(QApplication::translate("BatteryWarnningDialog", "Treate All", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BatteryWarnningDialog: public Ui_BatteryWarnningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYWARNNINGDIALOG_H
