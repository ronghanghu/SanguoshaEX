/********************************************************************************
** Form generated from reading UI file 'WujiangChooseBox.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUJIANGCHOOSEBOX_H
#define UI_WUJIANGCHOOSEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "sgsui_ResultPlayerLabel.h"
#include "sgsui_WujiangButton.h"

QT_BEGIN_NAMESPACE

class Ui_WujiangChooseBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *messageLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *centralLayout;
    QFrame *wujiangFrame;
    QHBoxLayout *cardLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *zhugongInfoFrame;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *zhugongWujiangLabel;
    sgsui::ResultPlayerLabel *zhugongPixmapLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QFrame *avaliableCardFrame;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    sgsui::WujiangButton *wujiangButton1;
    sgsui::WujiangButton *wujiangButton2;
    sgsui::WujiangButton *wujiangButton3;
    sgsui::WujiangButton *wujiangButton4;
    sgsui::WujiangButton *wujiangButton5;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *WujiangChooseBox)
    {
        if (WujiangChooseBox->objectName().isEmpty())
            WujiangChooseBox->setObjectName(QString::fromUtf8("WujiangChooseBox"));
        WujiangChooseBox->resize(1024, 400);
        WujiangChooseBox->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(WujiangChooseBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 20, 0, 20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        messageLabel = new QLabel(WujiangChooseBox);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));

        horizontalLayout->addWidget(messageLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        centralLayout = new QHBoxLayout();
        centralLayout->setSpacing(0);
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));
        wujiangFrame = new QFrame(WujiangChooseBox);
        wujiangFrame->setObjectName(QString::fromUtf8("wujiangFrame"));
        cardLayout = new QHBoxLayout(wujiangFrame);
        cardLayout->setSpacing(0);
        cardLayout->setContentsMargins(0, 0, 0, 0);
        cardLayout->setObjectName(QString::fromUtf8("cardLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        cardLayout->addItem(horizontalSpacer_2);

        zhugongInfoFrame = new QWidget(wujiangFrame);
        zhugongInfoFrame->setObjectName(QString::fromUtf8("zhugongInfoFrame"));
        horizontalLayout_5 = new QHBoxLayout(zhugongInfoFrame);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        zhugongWujiangLabel = new QLabel(zhugongInfoFrame);
        zhugongWujiangLabel->setObjectName(QString::fromUtf8("zhugongWujiangLabel"));
        zhugongWujiangLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(zhugongWujiangLabel);

        zhugongPixmapLabel = new sgsui::ResultPlayerLabel(zhugongInfoFrame);
        zhugongPixmapLabel->setObjectName(QString::fromUtf8("zhugongPixmapLabel"));

        verticalLayout_4->addWidget(zhugongPixmapLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        cardLayout->addWidget(zhugongInfoFrame);

        avaliableCardFrame = new QFrame(wujiangFrame);
        avaliableCardFrame->setObjectName(QString::fromUtf8("avaliableCardFrame"));
        verticalLayout_2 = new QVBoxLayout(avaliableCardFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 153, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wujiangButton1 = new sgsui::WujiangButton(avaliableCardFrame);
        wujiangButton1->setObjectName(QString::fromUtf8("wujiangButton1"));

        horizontalLayout_2->addWidget(wujiangButton1);

        wujiangButton2 = new sgsui::WujiangButton(avaliableCardFrame);
        wujiangButton2->setObjectName(QString::fromUtf8("wujiangButton2"));

        horizontalLayout_2->addWidget(wujiangButton2);

        wujiangButton3 = new sgsui::WujiangButton(avaliableCardFrame);
        wujiangButton3->setObjectName(QString::fromUtf8("wujiangButton3"));

        horizontalLayout_2->addWidget(wujiangButton3);

        wujiangButton4 = new sgsui::WujiangButton(avaliableCardFrame);
        wujiangButton4->setObjectName(QString::fromUtf8("wujiangButton4"));

        horizontalLayout_2->addWidget(wujiangButton4);

        wujiangButton5 = new sgsui::WujiangButton(avaliableCardFrame);
        wujiangButton5->setObjectName(QString::fromUtf8("wujiangButton5"));

        horizontalLayout_2->addWidget(wujiangButton5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 152, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);


        cardLayout->addWidget(avaliableCardFrame);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        cardLayout->addItem(horizontalSpacer_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        cardLayout->addItem(horizontalSpacer);


        centralLayout->addWidget(wujiangFrame);


        verticalLayout->addLayout(centralLayout);


        retranslateUi(WujiangChooseBox);

        QMetaObject::connectSlotsByName(WujiangChooseBox);
    } // setupUi

    void retranslateUi(QWidget *WujiangChooseBox)
    {
        zhugongWujiangLabel->setText(QApplication::translate("WujiangChooseBox", "<font color=white><b>\344\270\273\345\205\254\346\255\246\345\260\206</b></font>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(WujiangChooseBox);
    } // retranslateUi

};

namespace Ui {
    class WujiangChooseBox: public Ui_WujiangChooseBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUJIANGCHOOSEBOX_H
