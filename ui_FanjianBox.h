/********************************************************************************
** Form generated from reading UI file 'FanjianBox.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FANJIANBOX_H
#define UI_FANJIANBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "sgsui_GameButton.h"

QT_BEGIN_NAMESPACE

class Ui_FanjianBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *messageLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    sgsui::GameButton *heartButton;
    sgsui::GameButton *spadeButton;
    sgsui::GameButton *diamondButton;
    sgsui::GameButton *clubButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FanjianBox)
    {
        if (FanjianBox->objectName().isEmpty())
            FanjianBox->setObjectName(QString::fromUtf8("FanjianBox"));
        verticalLayout = new QVBoxLayout(FanjianBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(25, -1, 25, 25);
        messageLabel = new QLabel(FanjianBox);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messageLabel->sizePolicy().hasHeightForWidth());
        messageLabel->setSizePolicy(sizePolicy);
        messageLabel->setAlignment(Qt::AlignCenter);
        messageLabel->setWordWrap(true);

        verticalLayout->addWidget(messageLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        heartButton = new sgsui::GameButton(FanjianBox);
        heartButton->setObjectName(QString::fromUtf8("heartButton"));

        horizontalLayout->addWidget(heartButton);

        spadeButton = new sgsui::GameButton(FanjianBox);
        spadeButton->setObjectName(QString::fromUtf8("spadeButton"));

        horizontalLayout->addWidget(spadeButton);

        diamondButton = new sgsui::GameButton(FanjianBox);
        diamondButton->setObjectName(QString::fromUtf8("diamondButton"));

        horizontalLayout->addWidget(diamondButton);

        clubButton = new sgsui::GameButton(FanjianBox);
        clubButton->setObjectName(QString::fromUtf8("clubButton"));

        horizontalLayout->addWidget(clubButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FanjianBox);

        QMetaObject::connectSlotsByName(FanjianBox);
    } // setupUi

    void retranslateUi(QWidget *FanjianBox)
    {
        FanjianBox->setWindowTitle(QApplication::translate("FanjianBox", "Form", 0, QApplication::UnicodeUTF8));
        messageLabel->setText(QApplication::translate("FanjianBox", "<font color=white><b>\345\221\250\347\221\234\345\257\271\344\275\240\344\275\277\347\224\250\344\272\206\345\217\215\351\227\264\357\274\214\350\257\267\351\200\211\346\213\251\350\212\261\350\211\262</b></font>", 0, QApplication::UnicodeUTF8));
        heartButton->setText(QApplication::translate("FanjianBox", "<font color=white>\347\272\242\346\241\203</font><font color=red>\342\231\245</font>", 0, QApplication::UnicodeUTF8));
        spadeButton->setText(QApplication::translate("FanjianBox", "<font color=white>\351\273\221\346\241\203</font><font color=black>\342\231\240</font>", 0, QApplication::UnicodeUTF8));
        diamondButton->setText(QApplication::translate("FanjianBox", "<font color=white>\346\226\271\347\211\207</font><font color=red>\342\231\246</font>", 0, QApplication::UnicodeUTF8));
        clubButton->setText(QApplication::translate("FanjianBox", "<font color=white>\350\215\211\350\212\261</font><font color=black>\342\231\243</font>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FanjianBox: public Ui_FanjianBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FANJIANBOX_H
