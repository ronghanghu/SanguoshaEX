/********************************************************************************
** Form generated from reading UI file 'CardContainer.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDCONTAINER_H
#define UI_CARDCONTAINER_H

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
#include "sgsui_GameButton.h"

QT_BEGIN_NAMESPACE

class Ui_CardContainer
{
public:
    QVBoxLayout *CardContainerLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *messageLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *centralLayout;
    QSpacerItem *horizontalSpacer_5;
    QFrame *cardFrame;
    QHBoxLayout *cardLayout;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    sgsui::GameButton *okButton;
    sgsui::GameButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CardContainer)
    {
        if (CardContainer->objectName().isEmpty())
            CardContainer->setObjectName(QString::fromUtf8("CardContainer"));
        CardContainer->setWindowModality(Qt::WindowModal);
        CardContainerLayout = new QVBoxLayout(CardContainer);
        CardContainerLayout->setSpacing(0);
        CardContainerLayout->setObjectName(QString::fromUtf8("CardContainerLayout"));
        CardContainerLayout->setContentsMargins(25, 30, 25, 30);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        messageLabel = new QLabel(CardContainer);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));

        horizontalLayout->addWidget(messageLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        CardContainerLayout->addLayout(horizontalLayout);

        centralLayout = new QHBoxLayout();
        centralLayout->setSpacing(0);
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralLayout->addItem(horizontalSpacer_5);

        cardFrame = new QFrame(CardContainer);
        cardFrame->setObjectName(QString::fromUtf8("cardFrame"));
        cardFrame->setMinimumSize(QSize(0, 170));
        cardFrame->setMaximumSize(QSize(16777215, 170));
        cardLayout = new QHBoxLayout(cardFrame);
        cardLayout->setSpacing(0);
        cardLayout->setContentsMargins(0, 0, 0, 0);
        cardLayout->setObjectName(QString::fromUtf8("cardLayout"));

        centralLayout->addWidget(cardFrame);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralLayout->addItem(horizontalSpacer_6);


        CardContainerLayout->addLayout(centralLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        CardContainerLayout->addItem(verticalSpacer);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        okButton = new sgsui::GameButton(CardContainer);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        buttonLayout->addWidget(okButton);

        cancelButton = new sgsui::GameButton(CardContainer);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        buttonLayout->addWidget(cancelButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);


        CardContainerLayout->addLayout(buttonLayout);


        retranslateUi(CardContainer);

        QMetaObject::connectSlotsByName(CardContainer);
    } // setupUi

    void retranslateUi(QWidget *CardContainer)
    {
        Q_UNUSED(CardContainer);
    } // retranslateUi

};

namespace Ui {
    class CardContainer: public Ui_CardContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDCONTAINER_H
