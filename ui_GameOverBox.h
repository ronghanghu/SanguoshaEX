/********************************************************************************
** Form generated from reading UI file 'GameOverBox.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERBOX_H
#define UI_GAMEOVERBOX_H

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
#include "sgsui_ResultPlayerLabel.h"

QT_BEGIN_NAMESPACE

class Ui_GameOverBox
{
public:
    QVBoxLayout *verticalLayout_9;
    QLabel *lostLabel;
    QLabel *wonLabel;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_24;
    QSpacerItem *horizontalSpacer_23;
    QFrame *resultFrame1;
    QVBoxLayout *verticalLayout;
    QLabel *playerRole1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    sgsui::ResultPlayerLabel *playerPixmap1;
    QSpacerItem *horizontalSpacer_4;
    QLabel *playerResult1;
    QFrame *resultFrame2;
    QVBoxLayout *verticalLayout_2;
    QLabel *playerRole2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    sgsui::ResultPlayerLabel *playerPixmap2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *playerResult2;
    QFrame *resultFrame3;
    QVBoxLayout *verticalLayout_3;
    QLabel *playerRole3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    sgsui::ResultPlayerLabel *playerPixmap3;
    QSpacerItem *horizontalSpacer_8;
    QLabel *playerResult3;
    QFrame *resultFrame4;
    QVBoxLayout *verticalLayout_4;
    QLabel *playerRole4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    sgsui::ResultPlayerLabel *playerPixmap4;
    QSpacerItem *horizontalSpacer_10;
    QLabel *playerResult4;
    QFrame *resultFrame5;
    QVBoxLayout *verticalLayout_5;
    QLabel *playerRole5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_11;
    sgsui::ResultPlayerLabel *playerPixmap5;
    QSpacerItem *horizontalSpacer_12;
    QLabel *playerResult5;
    QFrame *resultFrame6;
    QVBoxLayout *verticalLayout_6;
    QLabel *playerRole6;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_13;
    sgsui::ResultPlayerLabel *playerPixmap6;
    QSpacerItem *horizontalSpacer_14;
    QLabel *playerResult6;
    QFrame *resultFrame7;
    QVBoxLayout *verticalLayout_7;
    QLabel *playerRole7;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_15;
    sgsui::ResultPlayerLabel *playerPixmap7;
    QSpacerItem *horizontalSpacer_16;
    QLabel *playerResult7;
    QFrame *resultFrame8;
    QVBoxLayout *verticalLayout_8;
    QLabel *playerRole8;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_17;
    sgsui::ResultPlayerLabel *playerPixmap8;
    QSpacerItem *horizontalSpacer_18;
    QLabel *playerResult8;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    sgsui::GameButton *okButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *GameOverBox)
    {
        if (GameOverBox->objectName().isEmpty())
            GameOverBox->setObjectName(QString::fromUtf8("GameOverBox"));
        GameOverBox->resize(1328, 327);
        verticalLayout_9 = new QVBoxLayout(GameOverBox);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(20, 25, 20, 25);
        lostLabel = new QLabel(GameOverBox);
        lostLabel->setObjectName(QString::fromUtf8("lostLabel"));
        lostLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(lostLabel);

        wonLabel = new QLabel(GameOverBox);
        wonLabel->setObjectName(QString::fromUtf8("wonLabel"));
        wonLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(wonLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_19);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_24);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_23);

        resultFrame1 = new QFrame(GameOverBox);
        resultFrame1->setObjectName(QString::fromUtf8("resultFrame1"));
        verticalLayout = new QVBoxLayout(resultFrame1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        playerRole1 = new QLabel(resultFrame1);
        playerRole1->setObjectName(QString::fromUtf8("playerRole1"));
        playerRole1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(playerRole1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        playerPixmap1 = new sgsui::ResultPlayerLabel(resultFrame1);
        playerPixmap1->setObjectName(QString::fromUtf8("playerPixmap1"));

        horizontalLayout_3->addWidget(playerPixmap1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        playerResult1 = new QLabel(resultFrame1);
        playerResult1->setObjectName(QString::fromUtf8("playerResult1"));
        playerResult1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(playerResult1);


        horizontalLayout_2->addWidget(resultFrame1);

        resultFrame2 = new QFrame(GameOverBox);
        resultFrame2->setObjectName(QString::fromUtf8("resultFrame2"));
        verticalLayout_2 = new QVBoxLayout(resultFrame2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        playerRole2 = new QLabel(resultFrame2);
        playerRole2->setObjectName(QString::fromUtf8("playerRole2"));
        playerRole2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(playerRole2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        playerPixmap2 = new sgsui::ResultPlayerLabel(resultFrame2);
        playerPixmap2->setObjectName(QString::fromUtf8("playerPixmap2"));

        horizontalLayout_4->addWidget(playerPixmap2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        playerResult2 = new QLabel(resultFrame2);
        playerResult2->setObjectName(QString::fromUtf8("playerResult2"));
        playerResult2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(playerResult2);


        horizontalLayout_2->addWidget(resultFrame2);

        resultFrame3 = new QFrame(GameOverBox);
        resultFrame3->setObjectName(QString::fromUtf8("resultFrame3"));
        verticalLayout_3 = new QVBoxLayout(resultFrame3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        playerRole3 = new QLabel(resultFrame3);
        playerRole3->setObjectName(QString::fromUtf8("playerRole3"));
        playerRole3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(playerRole3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        playerPixmap3 = new sgsui::ResultPlayerLabel(resultFrame3);
        playerPixmap3->setObjectName(QString::fromUtf8("playerPixmap3"));

        horizontalLayout_5->addWidget(playerPixmap3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_5);

        playerResult3 = new QLabel(resultFrame3);
        playerResult3->setObjectName(QString::fromUtf8("playerResult3"));
        playerResult3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(playerResult3);


        horizontalLayout_2->addWidget(resultFrame3);

        resultFrame4 = new QFrame(GameOverBox);
        resultFrame4->setObjectName(QString::fromUtf8("resultFrame4"));
        verticalLayout_4 = new QVBoxLayout(resultFrame4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        playerRole4 = new QLabel(resultFrame4);
        playerRole4->setObjectName(QString::fromUtf8("playerRole4"));
        playerRole4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(playerRole4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        playerPixmap4 = new sgsui::ResultPlayerLabel(resultFrame4);
        playerPixmap4->setObjectName(QString::fromUtf8("playerPixmap4"));

        horizontalLayout_6->addWidget(playerPixmap4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout_4->addLayout(horizontalLayout_6);

        playerResult4 = new QLabel(resultFrame4);
        playerResult4->setObjectName(QString::fromUtf8("playerResult4"));
        playerResult4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(playerResult4);


        horizontalLayout_2->addWidget(resultFrame4);

        resultFrame5 = new QFrame(GameOverBox);
        resultFrame5->setObjectName(QString::fromUtf8("resultFrame5"));
        verticalLayout_5 = new QVBoxLayout(resultFrame5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        playerRole5 = new QLabel(resultFrame5);
        playerRole5->setObjectName(QString::fromUtf8("playerRole5"));
        playerRole5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(playerRole5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        playerPixmap5 = new sgsui::ResultPlayerLabel(resultFrame5);
        playerPixmap5->setObjectName(QString::fromUtf8("playerPixmap5"));

        horizontalLayout_7->addWidget(playerPixmap5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);


        verticalLayout_5->addLayout(horizontalLayout_7);

        playerResult5 = new QLabel(resultFrame5);
        playerResult5->setObjectName(QString::fromUtf8("playerResult5"));
        playerResult5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(playerResult5);


        horizontalLayout_2->addWidget(resultFrame5);

        resultFrame6 = new QFrame(GameOverBox);
        resultFrame6->setObjectName(QString::fromUtf8("resultFrame6"));
        verticalLayout_6 = new QVBoxLayout(resultFrame6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        playerRole6 = new QLabel(resultFrame6);
        playerRole6->setObjectName(QString::fromUtf8("playerRole6"));
        playerRole6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(playerRole6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        playerPixmap6 = new sgsui::ResultPlayerLabel(resultFrame6);
        playerPixmap6->setObjectName(QString::fromUtf8("playerPixmap6"));

        horizontalLayout_8->addWidget(playerPixmap6);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);


        verticalLayout_6->addLayout(horizontalLayout_8);

        playerResult6 = new QLabel(resultFrame6);
        playerResult6->setObjectName(QString::fromUtf8("playerResult6"));
        playerResult6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(playerResult6);


        horizontalLayout_2->addWidget(resultFrame6);

        resultFrame7 = new QFrame(GameOverBox);
        resultFrame7->setObjectName(QString::fromUtf8("resultFrame7"));
        verticalLayout_7 = new QVBoxLayout(resultFrame7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        playerRole7 = new QLabel(resultFrame7);
        playerRole7->setObjectName(QString::fromUtf8("playerRole7"));
        playerRole7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(playerRole7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_15);

        playerPixmap7 = new sgsui::ResultPlayerLabel(resultFrame7);
        playerPixmap7->setObjectName(QString::fromUtf8("playerPixmap7"));

        horizontalLayout_9->addWidget(playerPixmap7);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_16);


        verticalLayout_7->addLayout(horizontalLayout_9);

        playerResult7 = new QLabel(resultFrame7);
        playerResult7->setObjectName(QString::fromUtf8("playerResult7"));
        playerResult7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(playerResult7);


        horizontalLayout_2->addWidget(resultFrame7);

        resultFrame8 = new QFrame(GameOverBox);
        resultFrame8->setObjectName(QString::fromUtf8("resultFrame8"));
        verticalLayout_8 = new QVBoxLayout(resultFrame8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        playerRole8 = new QLabel(resultFrame8);
        playerRole8->setObjectName(QString::fromUtf8("playerRole8"));
        playerRole8->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(playerRole8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_17);

        playerPixmap8 = new sgsui::ResultPlayerLabel(resultFrame8);
        playerPixmap8->setObjectName(QString::fromUtf8("playerPixmap8"));

        horizontalLayout_10->addWidget(playerPixmap8);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_18);


        verticalLayout_8->addLayout(horizontalLayout_10);

        playerResult8 = new QLabel(resultFrame8);
        playerResult8->setObjectName(QString::fromUtf8("playerResult8"));
        playerResult8->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(playerResult8);


        horizontalLayout_2->addWidget(resultFrame8);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_21);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_22);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_20);


        verticalLayout_9->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okButton = new sgsui::GameButton(GameOverBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_9->addLayout(horizontalLayout);


        retranslateUi(GameOverBox);

        QMetaObject::connectSlotsByName(GameOverBox);
    } // setupUi

    void retranslateUi(QWidget *GameOverBox)
    {
        GameOverBox->setWindowTitle(QApplication::translate("GameOverBox", "Form", 0, QApplication::UnicodeUTF8));
        lostLabel->setText(QApplication::translate("GameOverBox", "<font color=white><b>\346\270\270\346\210\217\347\273\223\346\235\237\357\274\214\346\202\250\345\244\261\350\264\245\344\272\206</b></font>", 0, QApplication::UnicodeUTF8));
        wonLabel->setText(QApplication::translate("GameOverBox", "<font color=white><b>\346\270\270\346\210\217\347\273\223\346\235\237\357\274\214\346\202\250\350\216\267\350\203\234\344\272\206</b></font>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameOverBox: public Ui_GameOverBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERBOX_H
