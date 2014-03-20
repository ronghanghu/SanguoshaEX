/********************************************************************************
** Form generated from reading UI file 'WugufengdengBox.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUGUFENGDENGBOX_H
#define UI_WUGUFENGDENGBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "sgsui_GameButton.h"

QT_BEGIN_NAMESPACE

class Ui_WugufengdengBox
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    sgsui::GameButton *okButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *WugufengdengBox)
    {
        if (WugufengdengBox->objectName().isEmpty())
            WugufengdengBox->setObjectName(QString::fromUtf8("WugufengdengBox"));
        WugufengdengBox->resize(650, 230);
        verticalLayout = new QVBoxLayout(WugufengdengBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 20);
        verticalSpacer = new QSpacerItem(20, 170, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okButton = new sgsui::GameButton(WugufengdengBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WugufengdengBox);

        QMetaObject::connectSlotsByName(WugufengdengBox);
    } // setupUi

    void retranslateUi(QWidget *WugufengdengBox)
    {
        Q_UNUSED(WugufengdengBox);
    } // retranslateUi

};

namespace Ui {
    class WugufengdengBox: public Ui_WugufengdengBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUGUFENGDENGBOX_H
