/********************************************************************************
** Form generated from reading UI file 'WujiangArea.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WUJIANGAREA_H
#define UI_WUJIANGAREA_H

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
#include "sgsui_SkillButton.h"

QT_BEGIN_NAMESPACE

class Ui_WujiangArea
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QLabel *noSkill;
    QWidget *skillWidget1;
    QHBoxLayout *horizontalLayout;
    sgsui::SkillButton *skill0;
    QWidget *spacer1;
    sgsui::SkillButton *skill1;
    QWidget *skillWidget2;
    QHBoxLayout *horizontalLayout_2;
    sgsui::SkillButton *skill2;
    QWidget *spacer2;
    sgsui::SkillButton *skill3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WujiangArea)
    {
        if (WujiangArea->objectName().isEmpty())
            WujiangArea->setObjectName(QString::fromUtf8("WujiangArea"));
        verticalLayout = new QVBoxLayout(WujiangArea);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(12, 100, 55, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        noSkill = new QLabel(WujiangArea);
        noSkill->setObjectName(QString::fromUtf8("noSkill"));
        noSkill->setMinimumSize(QSize(0, 40));
        noSkill->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(noSkill);

        skillWidget1 = new QWidget(WujiangArea);
        skillWidget1->setObjectName(QString::fromUtf8("skillWidget1"));
        skillWidget1->setMinimumSize(QSize(0, 25));
        horizontalLayout = new QHBoxLayout(skillWidget1);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        skill0 = new sgsui::SkillButton(skillWidget1);
        skill0->setObjectName(QString::fromUtf8("skill0"));

        horizontalLayout->addWidget(skill0);

        spacer1 = new QWidget(skillWidget1);
        spacer1->setObjectName(QString::fromUtf8("spacer1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spacer1->sizePolicy().hasHeightForWidth());
        spacer1->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(spacer1);

        skill1 = new sgsui::SkillButton(skillWidget1);
        skill1->setObjectName(QString::fromUtf8("skill1"));

        horizontalLayout->addWidget(skill1);


        verticalLayout->addWidget(skillWidget1);

        skillWidget2 = new QWidget(WujiangArea);
        skillWidget2->setObjectName(QString::fromUtf8("skillWidget2"));
        skillWidget2->setMinimumSize(QSize(0, 25));
        horizontalLayout_2 = new QHBoxLayout(skillWidget2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        skill2 = new sgsui::SkillButton(skillWidget2);
        skill2->setObjectName(QString::fromUtf8("skill2"));

        horizontalLayout_2->addWidget(skill2);

        spacer2 = new QWidget(skillWidget2);
        spacer2->setObjectName(QString::fromUtf8("spacer2"));
        sizePolicy.setHeightForWidth(spacer2->sizePolicy().hasHeightForWidth());
        spacer2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(spacer2);

        skill3 = new sgsui::SkillButton(skillWidget2);
        skill3->setObjectName(QString::fromUtf8("skill3"));

        horizontalLayout_2->addWidget(skill3);


        verticalLayout->addWidget(skillWidget2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(WujiangArea);

        QMetaObject::connectSlotsByName(WujiangArea);
    } // setupUi

    void retranslateUi(QWidget *WujiangArea)
    {
        WujiangArea->setWindowTitle(QApplication::translate("WujiangArea", "Form", 0, QApplication::UnicodeUTF8));
        noSkill->setText(QApplication::translate("WujiangArea", "<font color=white><b>\346\262\241\346\234\211\346\212\200\350\203\275</b></font>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WujiangArea: public Ui_WujiangArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WUJIANGAREA_H
