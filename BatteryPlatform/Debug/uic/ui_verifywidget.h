/********************************************************************************
** Form generated from reading UI file 'verifywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFYWIDGET_H
#define UI_VERIFYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VerifyWidget)
    {
        if (VerifyWidget->objectName().isEmpty())
            VerifyWidget->setObjectName(QStringLiteral("VerifyWidget"));
        VerifyWidget->resize(1196, 779);
        VerifyWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	background-color: rgb(88, 88, 88);\n"
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
"	background-color: rgb(70, 70, 70);\n"
"}\n"
"QWidget#VerifyWidget\n"
"{	\n"
"	background-color: rgb(255, 255, 255);\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        verticalLayout = new QVBoxLayout(VerifyWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        textBrowser = new QTextBrowser(VerifyWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(VerifyWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(VerifyWidget);

        QMetaObject::connectSlotsByName(VerifyWidget);
    } // setupUi

    void retranslateUi(QWidget *VerifyWidget)
    {
        VerifyWidget->setWindowTitle(QApplication::translate("VerifyWidget", "VerifyWidget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VerifyWidget", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VerifyWidget: public Ui_VerifyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFYWIDGET_H
