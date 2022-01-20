/********************************************************************************
** Form generated from reading UI file 'batteryplatform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYPLATFORM_H
#define UI_BATTERYPLATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatteryPlatformClass
{
public:
    QAction *ReturnHome;
    QAction *Closeexe;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *IPEdit;
    QCheckBox *ChangeIP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *PortEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *PactBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QCheckBox *LogSaveBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *StartBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *Verify_Btn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *TurnToUIBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BatteryPlatformClass)
    {
        if (BatteryPlatformClass->objectName().isEmpty())
            BatteryPlatformClass->setObjectName(QStringLiteral("BatteryPlatformClass"));
        BatteryPlatformClass->setEnabled(true);
        BatteryPlatformClass->resize(852, 717);
        ReturnHome = new QAction(BatteryPlatformClass);
        ReturnHome->setObjectName(QStringLiteral("ReturnHome"));
        Closeexe = new QAction(BatteryPlatformClass);
        Closeexe->setObjectName(QStringLiteral("Closeexe"));
        centralWidget = new QWidget(BatteryPlatformClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_4 = new QHBoxLayout(page);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"	\n"
"	background-color: rgb(55, 111, 166);\n"
"}"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(212, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 85, 255);\n"
"background-color: rgb(216, 216, 216);"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setMaximumSize(QSize(150, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label_2);

        IPEdit = new QLineEdit(groupBox);
        IPEdit->setObjectName(QStringLiteral("IPEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IPEdit->sizePolicy().hasHeightForWidth());
        IPEdit->setSizePolicy(sizePolicy);
        IPEdit->setEchoMode(QLineEdit::Normal);
        IPEdit->setReadOnly(false);

        horizontalLayout->addWidget(IPEdit);

        ChangeIP = new QCheckBox(groupBox);
        ChangeIP->setObjectName(QStringLiteral("ChangeIP"));
        ChangeIP->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(ChangeIP);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 0));
        label->setMaximumSize(QSize(150, 16777215));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(label);

        PortEdit = new QLineEdit(groupBox);
        PortEdit->setObjectName(QStringLiteral("PortEdit"));
        sizePolicy.setHeightForWidth(PortEdit->sizePolicy().hasHeightForWidth());
        PortEdit->setSizePolicy(sizePolicy);
        PortEdit->setFocusPolicy(Qt::StrongFocus);
        PortEdit->setReadOnly(false);
        PortEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);

        horizontalLayout_2->addWidget(PortEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(150, 0));
        label_5->setMaximumSize(QSize(150, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_5->setTextFormat(Qt::AutoText);

        horizontalLayout_5->addWidget(label_5);

        PactBox = new QComboBox(groupBox);
        PactBox->setObjectName(QStringLiteral("PactBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PactBox->sizePolicy().hasHeightForWidth());
        PactBox->setSizePolicy(sizePolicy2);
        PactBox->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_5->addWidget(PactBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(150, 0));
        label_6->setMaximumSize(QSize(150, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_6->setTextFormat(Qt::AutoText);

        horizontalLayout_6->addWidget(label_6);

        LogSaveBox = new QCheckBox(groupBox);
        LogSaveBox->setObjectName(QStringLiteral("LogSaveBox"));
        LogSaveBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        LogSaveBox->setChecked(false);
        LogSaveBox->setTristate(false);

        horizontalLayout_6->addWidget(LogSaveBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        StartBtn = new QPushButton(groupBox);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        StartBtn->setMinimumSize(QSize(90, 60));
        StartBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    border-radius: 8px;\n"
"    padding: 10px 10px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 24px;\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #4CAF50;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        horizontalLayout_3->addWidget(StartBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Verify_Btn = new QPushButton(groupBox);
        Verify_Btn->setObjectName(QStringLiteral("Verify_Btn"));
        Verify_Btn->setMinimumSize(QSize(90, 60));
        Verify_Btn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    border-radius: 8px;\n"
"    padding: 10px 10px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 24px;\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #4CAF50;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        horizontalLayout_3->addWidget(Verify_Btn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        TurnToUIBtn = new QPushButton(groupBox);
        TurnToUIBtn->setObjectName(QStringLiteral("TurnToUIBtn"));
        TurnToUIBtn->setMinimumSize(QSize(100, 60));
        TurnToUIBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    border-radius: 8px;\n"
"    padding: 10px 10px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 24px;\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #4CAF50;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        horizontalLayout_3->addWidget(TurnToUIBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addWidget(groupBox, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 169, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 169, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);


        horizontalLayout_4->addWidget(widget);

        stackedWidget->addWidget(page);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        BatteryPlatformClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BatteryPlatformClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 852, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        BatteryPlatformClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BatteryPlatformClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BatteryPlatformClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BatteryPlatformClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BatteryPlatformClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(ReturnHome);
        menu->addAction(Closeexe);
        mainToolBar->addSeparator();

        retranslateUi(BatteryPlatformClass);

        QMetaObject::connectSlotsByName(BatteryPlatformClass);
    } // setupUi

    void retranslateUi(QMainWindow *BatteryPlatformClass)
    {
        BatteryPlatformClass->setWindowTitle(QApplication::translate("BatteryPlatformClass", "BatteryPlatform", Q_NULLPTR));
        ReturnHome->setText(QApplication::translate("BatteryPlatformClass", "Communication Setting", Q_NULLPTR));
        Closeexe->setText(QApplication::translate("BatteryPlatformClass", "Exit", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BatteryPlatformClass", "Communication setting", Q_NULLPTR));
        label_2->setText(QApplication::translate("BatteryPlatformClass", "IP Address\357\274\232", Q_NULLPTR));
        ChangeIP->setText(QApplication::translate("BatteryPlatformClass", "Change IP", Q_NULLPTR));
        label->setText(QApplication::translate("BatteryPlatformClass", "Choose Port\357\274\232", Q_NULLPTR));
        PortEdit->setInputMask(QString());
        PortEdit->setPlaceholderText(QApplication::translate("BatteryPlatformClass", "PORT", Q_NULLPTR));
        label_5->setText(QApplication::translate("BatteryPlatformClass", "Choose Pact\357\274\232", Q_NULLPTR));
        PactBox->clear();
        PactBox->insertItems(0, QStringList()
         << QApplication::translate("BatteryPlatformClass", "Please choose pact type", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("BatteryPlatformClass", "Save Log:", Q_NULLPTR));
        LogSaveBox->setText(QApplication::translate("BatteryPlatformClass", "Save", Q_NULLPTR));
        StartBtn->setText(QApplication::translate("BatteryPlatformClass", "Save", Q_NULLPTR));
        Verify_Btn->setText(QApplication::translate("BatteryPlatformClass", "Verify", Q_NULLPTR));
        TurnToUIBtn->setText(QApplication::translate("BatteryPlatformClass", "Turn to UI", Q_NULLPTR));
        menu->setTitle(QApplication::translate("BatteryPlatformClass", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BatteryPlatformClass: public Ui_BatteryPlatformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYPLATFORM_H
