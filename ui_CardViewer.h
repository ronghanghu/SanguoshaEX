/********************************************************************************
** Form generated from reading UI file 'CardViewer.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDVIEWER_H
#define UI_CARDVIEWER_H

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

QT_BEGIN_NAMESPACE

class Ui_CardViewer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *messageLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *cardLabel1;
    QLabel *cardLabel2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CardViewer)
    {
        if (CardViewer->objectName().isEmpty())
            CardViewer->setObjectName(QString::fromUtf8("CardViewer"));
        CardViewer->resize(304, 256);
        verticalLayout = new QVBoxLayout(CardViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(25, 30, 25, 30);
        messageLabel = new QLabel(CardViewer);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messageLabel->sizePolicy().hasHeightForWidth());
        messageLabel->setSizePolicy(sizePolicy);
        messageLabel->setAlignment(Qt::AlignCenter);
        messageLabel->setWordWrap(true);

        verticalLayout->addWidget(messageLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cardLabel1 = new QLabel(CardViewer);
        cardLabel1->setObjectName(QString::fromUtf8("cardLabel1"));
        cardLabel1->setMinimumSize(QSize(93, 130));
        cardLabel1->setMaximumSize(QSize(93, 130));

        horizontalLayout->addWidget(cardLabel1);

        cardLabel2 = new QLabel(CardViewer);
        cardLabel2->setObjectName(QString::fromUtf8("cardLabel2"));
        cardLabel2->setMinimumSize(QSize(93, 130));
        cardLabel2->setMaximumSize(QSize(93, 130));

        horizontalLayout->addWidget(cardLabel2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CardViewer);

        QMetaObject::connectSlotsByName(CardViewer);
    } // setupUi

    void retranslateUi(QWidget *CardViewer)
    {
        Q_UNUSED(CardViewer);
    } // retranslateUi

};

namespace Ui {
    class CardViewer: public Ui_CardViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDVIEWER_H
