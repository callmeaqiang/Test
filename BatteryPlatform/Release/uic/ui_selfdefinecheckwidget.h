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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelfDefineCheckWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label_warning;

    void setupUi(QWidget *SelfDefineCheckWidget)
    {
        if (SelfDefineCheckWidget->objectName().isEmpty())
            SelfDefineCheckWidget->setObjectName(QStringLiteral("SelfDefineCheckWidget"));
        SelfDefineCheckWidget->resize(116, 23);
        SelfDefineCheckWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(SelfDefineCheckWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(SelfDefineCheckWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(20, 20));
        pushButton->setMaximumSize(QSize(20, 20));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/res/res/warning.png);\n"
"background:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/res/warning.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton);

        label_warning = new QLabel(SelfDefineCheckWidget);
        label_warning->setObjectName(QStringLiteral("label_warning"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_warning->sizePolicy().hasHeightForWidth());
        label_warning->setSizePolicy(sizePolicy);
        label_warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label_warning);


        retranslateUi(SelfDefineCheckWidget);

        QMetaObject::connectSlotsByName(SelfDefineCheckWidget);
    } // setupUi

    void retranslateUi(QWidget *SelfDefineCheckWidget)
    {
        SelfDefineCheckWidget->setWindowTitle(QApplication::translate("SelfDefineCheckWidget", "SelfDefineCheckWidget", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("SelfDefineCheckWidget", "Warning", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QString());
        label_warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelfDefineCheckWidget: public Ui_SelfDefineCheckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELFDEFINECHECKWIDGET_H
