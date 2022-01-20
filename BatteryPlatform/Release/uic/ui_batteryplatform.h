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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BatteryPlatformClass
{
public:
    QAction *ReturnHome;
    QAction *Closeexe;
    QAction *actioninsistance;
    QAction *actionchargeAccuracyTest;
    QAction *actiondischargeAccuracyTests;
    QAction *actionVoltage_Accuracy_Test;
    QAction *actionVerify_Data;
    QAction *actionUI;
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *PactBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLineEdit *lineEdit_CVoltage;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLineEdit *lineEdit_Capacity;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *label_log_path;
    QPushButton *pushButton_path;
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
    QMenu *menuTools;
    QMenu *menuAddTest;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BatteryPlatformClass)
    {
        if (BatteryPlatformClass->objectName().isEmpty())
            BatteryPlatformClass->setObjectName(QStringLiteral("BatteryPlatformClass"));
        BatteryPlatformClass->setEnabled(true);
        BatteryPlatformClass->resize(1532, 931);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/res/battery.png"), QSize(), QIcon::Normal, QIcon::Off);
        BatteryPlatformClass->setWindowIcon(icon);
        BatteryPlatformClass->setStyleSheet(QLatin1String("QMainWindow{	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        BatteryPlatformClass->setIconSize(QSize(60, 60));
        ReturnHome = new QAction(BatteryPlatformClass);
        ReturnHome->setObjectName(QStringLiteral("ReturnHome"));
        Closeexe = new QAction(BatteryPlatformClass);
        Closeexe->setObjectName(QStringLiteral("Closeexe"));
        actioninsistance = new QAction(BatteryPlatformClass);
        actioninsistance->setObjectName(QStringLiteral("actioninsistance"));
        actionchargeAccuracyTest = new QAction(BatteryPlatformClass);
        actionchargeAccuracyTest->setObjectName(QStringLiteral("actionchargeAccuracyTest"));
        actiondischargeAccuracyTests = new QAction(BatteryPlatformClass);
        actiondischargeAccuracyTests->setObjectName(QStringLiteral("actiondischargeAccuracyTests"));
        actionVoltage_Accuracy_Test = new QAction(BatteryPlatformClass);
        actionVoltage_Accuracy_Test->setObjectName(QStringLiteral("actionVoltage_Accuracy_Test"));
        actionVerify_Data = new QAction(BatteryPlatformClass);
        actionVerify_Data->setObjectName(QStringLiteral("actionVerify_Data"));
        actionUI = new QAction(BatteryPlatformClass);
        actionUI->setObjectName(QStringLiteral("actionUI"));
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
        widget->setStyleSheet(QString::fromUtf8("QPushButton#StartBtn, #Verify_Btn, #TurnToUIBtn{\n"
"	\n"
"	background-color: rgb(88, 88, 88);\n"
"    border-radius: 8px;\n"
"    padding: 5px 5px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 24px;\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover#StartBtn, :hover#Verify_Btn, :hover#TurnToUIBtn\n"
"{   	\n"
"	background-color: rgb(70, 70, 70);\n"
"}\n"
"QPushButton:pressed#StartBtn ,:pressed#Verify_Btn,:pressed#TurnToUIBtn{   \n"
"	\n"
"	background-color: rgb(70, 70, 70);\n"
"    padding-left:8px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:8px;\n"
"}\n"
"QPushButton#pushButton_path{\n"
"background:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"\n"
"}\n"
"QPushButton:pressed#pushButton_path{\n"
"    padding-left:3px;\n"
"    /"
                        "*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}\n"
"QWidget#widget\n"
"{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(212, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(150, 0));
        label_5->setMaximumSize(QSize(150, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_5->setTextFormat(Qt::AutoText);

        horizontalLayout_5->addWidget(label_5);

        PactBox = new QComboBox(groupBox);
        PactBox->setObjectName(QStringLiteral("PactBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PactBox->sizePolicy().hasHeightForWidth());
        PactBox->setSizePolicy(sizePolicy1);
        PactBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_5->addWidget(PactBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(150, 0));
        label_4->setMaximumSize(QSize(150, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4->setTextFormat(Qt::AutoText);

        horizontalLayout_8->addWidget(label_4);

        lineEdit_CVoltage = new QLineEdit(groupBox);
        lineEdit_CVoltage->setObjectName(QStringLiteral("lineEdit_CVoltage"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_CVoltage->sizePolicy().hasHeightForWidth());
        lineEdit_CVoltage->setSizePolicy(sizePolicy2);
        lineEdit_CVoltage->setFocusPolicy(Qt::StrongFocus);
        lineEdit_CVoltage->setReadOnly(false);
        lineEdit_CVoltage->setCursorMoveStyle(Qt::LogicalMoveStyle);

        horizontalLayout_8->addWidget(lineEdit_CVoltage);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(150, 0));
        label_3->setMaximumSize(QSize(150, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3->setTextFormat(Qt::AutoText);

        horizontalLayout_7->addWidget(label_3);

        lineEdit_Capacity = new QLineEdit(groupBox);
        lineEdit_Capacity->setObjectName(QStringLiteral("lineEdit_Capacity"));
        sizePolicy2.setHeightForWidth(lineEdit_Capacity->sizePolicy().hasHeightForWidth());
        lineEdit_Capacity->setSizePolicy(sizePolicy2);
        lineEdit_Capacity->setFocusPolicy(Qt::StrongFocus);
        lineEdit_Capacity->setReadOnly(false);
        lineEdit_Capacity->setCursorMoveStyle(Qt::LogicalMoveStyle);

        horizontalLayout_7->addWidget(lineEdit_Capacity);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(150, 0));
        label_6->setMaximumSize(QSize(150, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_6->setTextFormat(Qt::AutoText);

        horizontalLayout_6->addWidget(label_6);

        label_log_path = new QLabel(groupBox);
        label_log_path->setObjectName(QStringLiteral("label_log_path"));

        horizontalLayout_6->addWidget(label_log_path);

        pushButton_path = new QPushButton(groupBox);
        pushButton_path->setObjectName(QStringLiteral("pushButton_path"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_path->sizePolicy().hasHeightForWidth());
        pushButton_path->setSizePolicy(sizePolicy3);
        pushButton_path->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/res/filepath.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_path->setIcon(icon1);
        pushButton_path->setIconSize(QSize(40, 40));

        horizontalLayout_6->addWidget(pushButton_path);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        StartBtn = new QPushButton(groupBox);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        StartBtn->setMinimumSize(QSize(90, 60));
        StartBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(StartBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Verify_Btn = new QPushButton(groupBox);
        Verify_Btn->setObjectName(QStringLiteral("Verify_Btn"));
        Verify_Btn->setMinimumSize(QSize(90, 60));
        Verify_Btn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(Verify_Btn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        TurnToUIBtn = new QPushButton(groupBox);
        TurnToUIBtn->setObjectName(QStringLiteral("TurnToUIBtn"));
        TurnToUIBtn->setMinimumSize(QSize(100, 60));
        TurnToUIBtn->setStyleSheet(QStringLiteral(""));

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
        menuBar->setGeometry(QRect(0, 0, 1532, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuAddTest = new QMenu(menuBar);
        menuAddTest->setObjectName(QStringLiteral("menuAddTest"));
        BatteryPlatformClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(BatteryPlatformClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BatteryPlatformClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuAddTest->menuAction());
        menu->addAction(ReturnHome);
        menu->addSeparator();
        menu->addAction(Closeexe);
        menu->addSeparator();
        menuTools->addAction(actionVerify_Data);
        menuTools->addAction(actionUI);
        menuAddTest->addAction(actioninsistance);
        menuAddTest->addSeparator();
        menuAddTest->addAction(actiondischargeAccuracyTests);
        menuAddTest->addSeparator();
        menuAddTest->addAction(actionchargeAccuracyTest);
        menuAddTest->addSeparator();
        menuAddTest->addAction(actionVoltage_Accuracy_Test);

        retranslateUi(BatteryPlatformClass);

        QMetaObject::connectSlotsByName(BatteryPlatformClass);
    } // setupUi

    void retranslateUi(QMainWindow *BatteryPlatformClass)
    {
        BatteryPlatformClass->setWindowTitle(QApplication::translate("BatteryPlatformClass", "BatteryPlatform", Q_NULLPTR));
        ReturnHome->setText(QApplication::translate("BatteryPlatformClass", "Communication Setting", Q_NULLPTR));
        Closeexe->setText(QApplication::translate("BatteryPlatformClass", "Exit", Q_NULLPTR));
        actioninsistance->setText(QApplication::translate("BatteryPlatformClass", "Charge Test", Q_NULLPTR));
        actionchargeAccuracyTest->setText(QApplication::translate("BatteryPlatformClass", "Current Accuracy Test", Q_NULLPTR));
        actiondischargeAccuracyTests->setText(QApplication::translate("BatteryPlatformClass", "Discharge Test", Q_NULLPTR));
        actionVoltage_Accuracy_Test->setText(QApplication::translate("BatteryPlatformClass", "Voltage Accuracy Test", Q_NULLPTR));
        actionVerify_Data->setText(QApplication::translate("BatteryPlatformClass", "Verify Data", Q_NULLPTR));
        actionUI->setText(QApplication::translate("BatteryPlatformClass", "UI", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BatteryPlatformClass", "Communication setting", Q_NULLPTR));
        label_5->setText(QApplication::translate("BatteryPlatformClass", "Choose Pact\357\274\232", Q_NULLPTR));
        PactBox->clear();
        PactBox->insertItems(0, QStringList()
         << QApplication::translate("BatteryPlatformClass", "Please choose pact type", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("BatteryPlatformClass", "Charge Voltage", Q_NULLPTR));
        lineEdit_CVoltage->setInputMask(QString());
        lineEdit_CVoltage->setText(QString());
        lineEdit_CVoltage->setPlaceholderText(QApplication::translate("BatteryPlatformClass", "/V", Q_NULLPTR));
        label_3->setText(QApplication::translate("BatteryPlatformClass", "Battery Capacity", Q_NULLPTR));
        lineEdit_Capacity->setInputMask(QString());
        lineEdit_Capacity->setText(QString());
        lineEdit_Capacity->setPlaceholderText(QApplication::translate("BatteryPlatformClass", "/Ah", Q_NULLPTR));
        label_6->setText(QApplication::translate("BatteryPlatformClass", "Report Path", Q_NULLPTR));
        label_log_path->setText(QString());
        pushButton_path->setText(QString());
        StartBtn->setText(QApplication::translate("BatteryPlatformClass", "Save", Q_NULLPTR));
        Verify_Btn->setText(QApplication::translate("BatteryPlatformClass", "Verify", Q_NULLPTR));
        TurnToUIBtn->setText(QApplication::translate("BatteryPlatformClass", "Turn to UI", Q_NULLPTR));
        menu->setTitle(QApplication::translate("BatteryPlatformClass", "Start", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("BatteryPlatformClass", "Tools", Q_NULLPTR));
        menuAddTest->setTitle(QApplication::translate("BatteryPlatformClass", "AddTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BatteryPlatformClass: public Ui_BatteryPlatformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYPLATFORM_H
