/********************************************************************************
** Form generated from reading UI file 'AboutFrame.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFRAME_H
#define UI_ABOUTFRAME_H

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
#include "sgsui_TextBrowser.h"

QT_BEGIN_NAMESPACE

class Ui_AboutFrame
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *messageLabel;
    sgsui::TextBrowser *aboutText;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    sgsui::GameButton *okButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *AboutFrame)
    {
        if (AboutFrame->objectName().isEmpty())
            AboutFrame->setObjectName(QString::fromUtf8("AboutFrame"));
        AboutFrame->resize(306, 311);
        verticalLayout_2 = new QVBoxLayout(AboutFrame);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(25, 30, 25, 30);
        messageLabel = new QLabel(AboutFrame);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(messageLabel);

        aboutText = new sgsui::TextBrowser(AboutFrame);
        aboutText->setObjectName(QString::fromUtf8("aboutText"));

        verticalLayout_2->addWidget(aboutText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okButton = new sgsui::GameButton(AboutFrame);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(AboutFrame);

        QMetaObject::connectSlotsByName(AboutFrame);
    } // setupUi

    void retranslateUi(QWidget *AboutFrame)
    {
        messageLabel->setText(QApplication::translate("AboutFrame", "<font color=white><b>\345\205\263\344\272\216\344\270\211\345\233\275\346\235\200EX</b></font>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AboutFrame);
    } // retranslateUi

};

namespace Ui {
    class AboutFrame: public Ui_AboutFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFRAME_H
