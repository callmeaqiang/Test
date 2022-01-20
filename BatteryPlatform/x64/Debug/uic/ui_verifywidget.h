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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifyWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser_checkSum;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *textBrowser_valueCheck;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VerifyWidget)
    {
        if (VerifyWidget->objectName().isEmpty())
            VerifyWidget->setObjectName(QStringLiteral("VerifyWidget"));
        VerifyWidget->resize(745, 703);
        verticalLayout_4 = new QVBoxLayout(VerifyWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(VerifyWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        textBrowser_checkSum = new QTextBrowser(groupBox);
        textBrowser_checkSum->setObjectName(QStringLiteral("textBrowser_checkSum"));

        verticalLayout->addWidget(textBrowser_checkSum);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        textBrowser_valueCheck = new QTextBrowser(groupBox);
        textBrowser_valueCheck->setObjectName(QStringLiteral("textBrowser_valueCheck"));

        verticalLayout_2->addWidget(textBrowser_valueCheck);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(groupBox);

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


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(VerifyWidget);

        QMetaObject::connectSlotsByName(VerifyWidget);
    } // setupUi

    void retranslateUi(QWidget *VerifyWidget)
    {
        VerifyWidget->setWindowTitle(QApplication::translate("VerifyWidget", "VerifyWidget", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("VerifyWidget", "Verify Information", Q_NULLPTR));
        label->setText(QApplication::translate("VerifyWidget", "SumVerify\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("VerifyWidget", "Value Verify\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VerifyWidget", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VerifyWidget: public Ui_VerifyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFYWIDGET_H
