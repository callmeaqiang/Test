/********************************************************************************
** Form generated from reading UI file 'processstatuswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSSTATUSWIDGET_H
#define UI_PROCESSSTATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessStatusWidget
{
public:

    void setupUi(QWidget *ProcessStatusWidget)
    {
        if (ProcessStatusWidget->objectName().isEmpty())
            ProcessStatusWidget->setObjectName(QStringLiteral("ProcessStatusWidget"));
        ProcessStatusWidget->resize(548, 360);

        retranslateUi(ProcessStatusWidget);

        QMetaObject::connectSlotsByName(ProcessStatusWidget);
    } // setupUi

    void retranslateUi(QWidget *ProcessStatusWidget)
    {
        ProcessStatusWidget->setWindowTitle(QApplication::translate("ProcessStatusWidget", "ProcessStatusWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProcessStatusWidget: public Ui_ProcessStatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSSTATUSWIDGET_H
