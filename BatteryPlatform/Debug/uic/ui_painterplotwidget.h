/********************************************************************************
** Form generated from reading UI file 'painterplotwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTERPLOTWIDGET_H
#define UI_PAINTERPLOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_PainterPlotWidget
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *qcustomplot_voltage;
    QCustomPlot *qcustomplot_current;
    QCustomPlot *qcustomplot_temperature;
    QCustomPlot *qcustomplot_Soc;

    void setupUi(QWidget *PainterPlotWidget)
    {
        if (PainterPlotWidget->objectName().isEmpty())
            PainterPlotWidget->setObjectName(QStringLiteral("PainterPlotWidget"));
        PainterPlotWidget->resize(1105, 747);
        verticalLayout = new QVBoxLayout(PainterPlotWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        qcustomplot_voltage = new QCustomPlot(PainterPlotWidget);
        qcustomplot_voltage->setObjectName(QStringLiteral("qcustomplot_voltage"));

        verticalLayout->addWidget(qcustomplot_voltage);

        qcustomplot_current = new QCustomPlot(PainterPlotWidget);
        qcustomplot_current->setObjectName(QStringLiteral("qcustomplot_current"));

        verticalLayout->addWidget(qcustomplot_current);

        qcustomplot_temperature = new QCustomPlot(PainterPlotWidget);
        qcustomplot_temperature->setObjectName(QStringLiteral("qcustomplot_temperature"));

        verticalLayout->addWidget(qcustomplot_temperature);

        qcustomplot_Soc = new QCustomPlot(PainterPlotWidget);
        qcustomplot_Soc->setObjectName(QStringLiteral("qcustomplot_Soc"));

        verticalLayout->addWidget(qcustomplot_Soc);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(PainterPlotWidget);

        QMetaObject::connectSlotsByName(PainterPlotWidget);
    } // setupUi

    void retranslateUi(QWidget *PainterPlotWidget)
    {
        PainterPlotWidget->setWindowTitle(QApplication::translate("PainterPlotWidget", "PainterPlotWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PainterPlotWidget: public Ui_PainterPlotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTERPLOTWIDGET_H
