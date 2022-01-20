/********************************************************************************
** Form generated from reading UI file 'selfdefinecheckwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELFDEFINECHECKWIDGET_H
#define UI_SELFDEFINECHECKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelfDefineCheckWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *SelfDefineCheckWidget)
    {
        if (SelfDefineCheckWidget->objectName().isEmpty())
            SelfDefineCheckWidget->setObjectName(QStringLiteral("SelfDefineCheckWidget"));
        SelfDefineCheckWidget->resize(171, 43);
        horizontalLayout = new QHBoxLayout(SelfDefineCheckWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton = new QRadioButton(SelfDefineCheckWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout->addWidget(radioButton);

        lineEdit = new QLineEdit(SelfDefineCheckWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(SelfDefineCheckWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        retranslateUi(SelfDefineCheckWidget);

        QMetaObject::connectSlotsByName(SelfDefineCheckWidget);
    } // setupUi

    void retranslateUi(QWidget *SelfDefineCheckWidget)
    {
        SelfDefineCheckWidget->setWindowTitle(QApplication::translate("SelfDefineCheckWidget", "SelfDefineCheckWidget", Q_NULLPTR));
        radioButton->setText(QString());
        label->setText(QApplication::translate("SelfDefineCheckWidget", "Cutoff", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelfDefineCheckWidget: public Ui_SelfDefineCheckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELFDEFINECHECKWIDGET_H
