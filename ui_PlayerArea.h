/********************************************************************************
** Form generated from reading UI file 'PlayerArea.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERAREA_H
#define UI_PLAYERAREA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerArea
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *shoupaiNumLabel;

    void setupUi(QWidget *PlayerArea)
    {
        if (PlayerArea->objectName().isEmpty())
            PlayerArea->setObjectName(QString::fromUtf8("PlayerArea"));
        PlayerArea->resize(124, 182);
        horizontalLayout = new QHBoxLayout(PlayerArea);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(110, 75, 5, 88);
        shoupaiNumLabel = new QLabel(PlayerArea);
        shoupaiNumLabel->setObjectName(QString::fromUtf8("shoupaiNumLabel"));
        shoupaiNumLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(shoupaiNumLabel);


        retranslateUi(PlayerArea);

        QMetaObject::connectSlotsByName(PlayerArea);
    } // setupUi

    void retranslateUi(QWidget *PlayerArea)
    {
        Q_UNUSED(PlayerArea);
    } // retranslateUi

};

namespace Ui {
    class PlayerArea: public Ui_PlayerArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERAREA_H
