/********************************************************************************
** Form generated from reading UI file 'mainreference.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINREFERENCE_H
#define UI_MAINREFERENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainReference
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *UIReference;
    QHBoxLayout *horizontalLayout_3;
    QCustomPlot *customplot;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *socLable;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *Voltage;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *chargeNum;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLabel *dischargeNum;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLabel *capicityLable;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *fill_capicityLable;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLabel *charge_Current;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLabel *discharge_Current;
    QLabel *label_22;
    QSpacerItem *verticalSpacer;
    QWidget *TestList;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddTestBtn;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QListView *listView;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *UpBtn;
    QPushButton *DownBtn;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *TestStartBtn;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QListView *listView_2;
    QWidget *tab_3;

    void setupUi(QWidget *MainReference)
    {
        if (MainReference->objectName().isEmpty())
            MainReference->setObjectName(QStringLiteral("MainReference"));
        MainReference->resize(1153, 806);
        gridLayout = new QGridLayout(MainReference);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        tabWidget = new QTabWidget(MainReference);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane{\n"
"	border: 2px solid rgb(210, 210, 210);\n"
"	background:rgb(246, 246, 246);\n"
"	border-top-color:transparent;}\n"
"QTabWidget::tab-bar{\n"
"	background:rgb(0, 0, 0);\n"
"	subcontrol-position:left;}\n"
"QTabBar::tab{\n"
"	width:120px;\n"
"	height:36px;\n"
"	font: 8pt ;\n"
"	background:rgb(210, 210, 210);\n"
"	border: 2px solid rgb(255, 255, 255);	border-top-		left-radius: 8px;	\n"
"	border-top-right-radius: 8px;}\n"
"QTabBar::tab:selected{\n"
"	background:rgb(9, 181, 97);\n"
"	border-bottom-color:rgb(246, 246, 246);\n"
"}\n"
"\n"
"\n"
""));
        UIReference = new QWidget();
        UIReference->setObjectName(QStringLiteral("UIReference"));
        horizontalLayout_3 = new QHBoxLayout(UIReference);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        customplot = new QCustomPlot(UIReference);
        customplot->setObjectName(QStringLiteral("customplot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customplot->sizePolicy().hasHeightForWidth());
        customplot->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(customplot);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(UIReference);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setStyleSheet(QLatin1String("QFrame#frame\n"
"{\n"
"border-radius:10px;\n"
"border:1px solid rgb(51, 211, 39)\n"
"} "));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        socLable = new QLabel(frame);
        socLable->setObjectName(QStringLiteral("socLable"));
        socLable->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_4->addWidget(socLable);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_13);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Voltage = new QLabel(frame);
        Voltage->setObjectName(QStringLiteral("Voltage"));
        Voltage->setMinimumSize(QSize(0, 0));
        Voltage->setMaximumSize(QSize(10000, 16777215));
        Voltage->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_2->addWidget(Voltage);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        chargeNum = new QLabel(frame);
        chargeNum->setObjectName(QStringLiteral("chargeNum"));
        chargeNum->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_5->addWidget(chargeNum);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        dischargeNum = new QLabel(frame);
        dischargeNum->setObjectName(QStringLiteral("dischargeNum"));
        dischargeNum->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_6->addWidget(dischargeNum);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        capicityLable = new QLabel(frame);
        capicityLable->setObjectName(QStringLiteral("capicityLable"));
        capicityLable->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_7->addWidget(capicityLable);

        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_17);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_8->addWidget(label_9);

        fill_capicityLable = new QLabel(frame);
        fill_capicityLable->setObjectName(QStringLiteral("fill_capicityLable"));
        fill_capicityLable->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_8->addWidget(fill_capicityLable);

        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(label_19);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_9->addWidget(label_10);

        charge_Current = new QLabel(frame);
        charge_Current->setObjectName(QStringLiteral("charge_Current"));
        charge_Current->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_9->addWidget(charge_Current);

        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(label_21);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_10->addWidget(label_11);

        discharge_Current = new QLabel(frame);
        discharge_Current->setObjectName(QStringLiteral("discharge_Current"));
        discharge_Current->setStyleSheet(QStringLiteral("color: rgb(14, 110, 255);"));

        horizontalLayout_10->addWidget(discharge_Current);

        label_22 = new QLabel(frame);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_22);


        verticalLayout_3->addLayout(horizontalLayout_10);


        verticalLayout_7->addLayout(verticalLayout_3);


        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        tabWidget->addTab(UIReference, QString());
        TestList = new QWidget();
        TestList->setObjectName(QStringLiteral("TestList"));
        horizontalLayout_12 = new QHBoxLayout(TestList);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_12 = new QLabel(TestList);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_2->addWidget(label_12);

        tableWidget = new QTableWidget(TestList);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        AddTestBtn = new QPushButton(TestList);
        AddTestBtn->setObjectName(QStringLiteral("AddTestBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(AddTestBtn->sizePolicy().hasHeightForWidth());
        AddTestBtn->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(AddTestBtn);

        comboBox = new QComboBox(TestList);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_12->addLayout(verticalLayout_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_5 = new QLabel(TestList);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_5->addWidget(label_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        listView = new QListView(TestList);
        listView->setObjectName(QStringLiteral("listView"));
        sizePolicy3.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy3);
        listView->setMinimumSize(QSize(400, 0));
        listView->setMaximumSize(QSize(400, 16777215));
        listView->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        listView->setDragEnabled(true);

        verticalLayout_4->addWidget(listView);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        UpBtn = new QPushButton(TestList);
        UpBtn->setObjectName(QStringLiteral("UpBtn"));
        sizePolicy1.setHeightForWidth(UpBtn->sizePolicy().hasHeightForWidth());
        UpBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(UpBtn);

        DownBtn = new QPushButton(TestList);
        DownBtn->setObjectName(QStringLiteral("DownBtn"));
        sizePolicy1.setHeightForWidth(DownBtn->sizePolicy().hasHeightForWidth());
        DownBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(DownBtn);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        TestStartBtn = new QPushButton(TestList);
        TestStartBtn->setObjectName(QStringLiteral("TestStartBtn"));
        sizePolicy1.setHeightForWidth(TestStartBtn->sizePolicy().hasHeightForWidth());
        TestStartBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_21->addWidget(TestStartBtn);

        pushButton_3 = new QPushButton(TestList);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        horizontalLayout_21->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(TestList);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);

        horizontalLayout_21->addWidget(pushButton_4);


        verticalLayout_6->addLayout(horizontalLayout_21);


        horizontalLayout_12->addLayout(verticalLayout_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_6 = new QLabel(TestList);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_8->addWidget(label_6);

        listView_2 = new QListView(TestList);
        listView_2->setObjectName(QStringLiteral("listView_2"));

        verticalLayout_8->addWidget(listView_2);


        horizontalLayout_12->addLayout(verticalLayout_8);

        tabWidget->addTab(TestList, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(MainReference);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainReference);
    } // setupUi

    void retranslateUi(QWidget *MainReference)
    {
        MainReference->setWindowTitle(QApplication::translate("MainReference", "MainReference", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainReference", "SOC     \357\274\232", Q_NULLPTR));
        socLable->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainReference", "%", Q_NULLPTR));
        label->setText(QApplication::translate("MainReference", "voltage \357\274\232", Q_NULLPTR));
        Voltage->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainReference", "V", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainReference", "charge number\357\274\232", Q_NULLPTR));
        chargeNum->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainReference", "discharge number\357\274\232", Q_NULLPTR));
        dischargeNum->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainReference", "Capicity Now:", Q_NULLPTR));
        capicityLable->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainReference", "Ah", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainReference", "Capicity Full   \357\274\232", Q_NULLPTR));
        fill_capicityLable->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainReference", "Ah", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainReference", "charge current\357\274\232", Q_NULLPTR));
        charge_Current->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainReference", "A", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainReference", "discharge current\357\274\232", Q_NULLPTR));
        discharge_Current->setText(QApplication::translate("MainReference", "0", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainReference", "A", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(UIReference), QApplication::translate("MainReference", "UI reference", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainReference", "\346\265\213\350\257\225\351\205\215\346\226\271\345\210\227\350\241\250\357\274\232", Q_NULLPTR));
        AddTestBtn->setText(QApplication::translate("MainReference", "Add Test", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainReference", "select type of test", Q_NULLPTR)
         << QApplication::translate("MainReference", "ResistanceTest", Q_NULLPTR)
         << QApplication::translate("MainReference", "CurrentAccuracyTest", Q_NULLPTR)
         << QApplication::translate("MainReference", "VoltageAccuracyTest", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainReference", "\345\276\205\346\265\213\350\257\225\345\210\227\350\241\250\357\274\232", Q_NULLPTR));
        UpBtn->setText(QApplication::translate("MainReference", "UP", Q_NULLPTR));
        DownBtn->setText(QApplication::translate("MainReference", "DOWN", Q_NULLPTR));
        TestStartBtn->setText(QApplication::translate("MainReference", "Start", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainReference", "Pause", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainReference", "Terminate", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainReference", "\346\265\213\350\257\225\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(TestList), QApplication::translate("MainReference", "Test List", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainReference", "Log Inquire", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainReference: public Ui_MainReference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINREFERENCE_H
