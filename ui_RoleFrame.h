/********************************************************************************
** Form generated from reading UI file 'RoleFrame.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLEFRAME_H
#define UI_ROLEFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoleFrame
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *roleLabel0;
    QLabel *roleLabel1;
    QLabel *roleLabel2;
    QLabel *roleLabel3;
    QLabel *roleLabel4;
    QLabel *roleLabel5;
    QLabel *roleLabel6;
    QLabel *roleLabel7;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *RoleFrame)
    {
        if (RoleFrame->objectName().isEmpty())
            RoleFrame->setObjectName(QString::fromUtf8("RoleFrame"));
        horizontalLayout = new QHBoxLayout(RoleFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 15, 5, -1);
        horizontalSpacer = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        roleLabel0 = new QLabel(RoleFrame);
        roleLabel0->setObjectName(QString::fromUtf8("roleLabel0"));

        horizontalLayout->addWidget(roleLabel0);

        roleLabel1 = new QLabel(RoleFrame);
        roleLabel1->setObjectName(QString::fromUtf8("roleLabel1"));

        horizontalLayout->addWidget(roleLabel1);

        roleLabel2 = new QLabel(RoleFrame);
        roleLabel2->setObjectName(QString::fromUtf8("roleLabel2"));

        horizontalLayout->addWidget(roleLabel2);

        roleLabel3 = new QLabel(RoleFrame);
        roleLabel3->setObjectName(QString::fromUtf8("roleLabel3"));

        horizontalLayout->addWidget(roleLabel3);

        roleLabel4 = new QLabel(RoleFrame);
        roleLabel4->setObjectName(QString::fromUtf8("roleLabel4"));

        horizontalLayout->addWidget(roleLabel4);

        roleLabel5 = new QLabel(RoleFrame);
        roleLabel5->setObjectName(QString::fromUtf8("roleLabel5"));

        horizontalLayout->addWidget(roleLabel5);

        roleLabel6 = new QLabel(RoleFrame);
        roleLabel6->setObjectName(QString::fromUtf8("roleLabel6"));

        horizontalLayout->addWidget(roleLabel6);

        roleLabel7 = new QLabel(RoleFrame);
        roleLabel7->setObjectName(QString::fromUtf8("roleLabel7"));

        horizontalLayout->addWidget(roleLabel7);

        horizontalSpacer_2 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(RoleFrame);

        QMetaObject::connectSlotsByName(RoleFrame);
    } // setupUi

    void retranslateUi(QWidget *RoleFrame)
    {
        Q_UNUSED(RoleFrame);
    } // retranslateUi

};

namespace Ui {
    class RoleFrame: public Ui_RoleFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLEFRAME_H
