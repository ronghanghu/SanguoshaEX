/********************************************************************************
** Form generated from reading UI file 'CardButton.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDBUTTON_H
#define UI_CARDBUTTON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardButton
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *upperSpacerWidget;
    QVBoxLayout *cardLayout;
    QFrame *lowerSpacerWidget;

    void setupUi(QWidget *CardButton)
    {
        if (CardButton->objectName().isEmpty())
            CardButton->setObjectName(QString::fromUtf8("CardButton"));
        CardButton->resize(93, 170);
        CardButton->setMinimumSize(QSize(93, 170));
        verticalLayout = new QVBoxLayout(CardButton);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 3, 0, 3);
        upperSpacerWidget = new QFrame(CardButton);
        upperSpacerWidget->setObjectName(QString::fromUtf8("upperSpacerWidget"));

        verticalLayout->addWidget(upperSpacerWidget);

        cardLayout = new QVBoxLayout();
        cardLayout->setSpacing(0);
        cardLayout->setObjectName(QString::fromUtf8("cardLayout"));

        verticalLayout->addLayout(cardLayout);

        lowerSpacerWidget = new QFrame(CardButton);
        lowerSpacerWidget->setObjectName(QString::fromUtf8("lowerSpacerWidget"));

        verticalLayout->addWidget(lowerSpacerWidget);


        retranslateUi(CardButton);

        QMetaObject::connectSlotsByName(CardButton);
    } // setupUi

    void retranslateUi(QWidget *CardButton)
    {
        Q_UNUSED(CardButton);
    } // retranslateUi

};

namespace Ui {
    class CardButton: public Ui_CardButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDBUTTON_H
