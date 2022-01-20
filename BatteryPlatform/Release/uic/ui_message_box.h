/********************************************************************************
** Form generated from reading UI file 'message_box.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_BOX_H
#define UI_MESSAGE_BOX_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Message_Box
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Title;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_close;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_icon;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *Edit_information;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Message_Box)
    {
        if (Message_Box->objectName().isEmpty())
            Message_Box->setObjectName(QStringLiteral("Message_Box"));
        Message_Box->resize(433, 216);
        Message_Box->setStyleSheet(QString::fromUtf8("QDialog#Message_Box\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel\n"
"{\n"
"	\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"/*\346\214\211\351\222\256\346\231\256\351\200\232\346\200\201*/\n"
"QPushButton\n"
"{\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346"
                        "\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(44 , 137 , 255);\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(Message_Box);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Message_Box);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(44, 220, 255);"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        label_Title = new QLabel(widget);
        label_Title->setObjectName(QStringLiteral("label_Title"));

        horizontalLayout_3->addWidget(label_Title);

        horizontalSpacer_3 = new QSpacerItem(277, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_close = new QPushButton(widget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(40, 40));
        pushButton_close->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/res/close_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon);
        pushButton_close->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(pushButton_close);


        verticalLayout_3->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        label_icon = new QLabel(Message_Box);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy);
        label_icon->setMinimumSize(QSize(80, 80));
        label_icon->setMaximumSize(QSize(80, 80));

        verticalLayout_2->addWidget(label_icon);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        Edit_information = new QLabel(Message_Box);
        Edit_information->setObjectName(QStringLiteral("Edit_information"));
        Edit_information->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout->addWidget(Edit_information);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(40);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_accept = new QPushButton(Message_Box);
        pushButton_accept->setObjectName(QStringLiteral("pushButton_accept"));

        horizontalLayout->addWidget(pushButton_accept);

        pushButton_cancel = new QPushButton(Message_Box);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Message_Box);

        QMetaObject::connectSlotsByName(Message_Box);
    } // setupUi

    void retranslateUi(QDialog *Message_Box)
    {
        Message_Box->setWindowTitle(QApplication::translate("Message_Box", "Message_Box", Q_NULLPTR));
        label_Title->setText(QString());
        pushButton_close->setText(QString());
        label_icon->setText(QString());
        Edit_information->setText(QString());
        pushButton_accept->setText(QApplication::translate("Message_Box", "Accept", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Message_Box", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Message_Box: public Ui_Message_Box {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_BOX_H
