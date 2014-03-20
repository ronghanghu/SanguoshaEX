/********************************************************************************
** Form generated from reading UI file 'GuanxingBox.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUANXINGBOX_H
#define UI_GUANXINGBOX_H

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

class Ui_GuanxingBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QFrame *leftFrame;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *messageLabel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    sgsui::ResultPlayerLabel *zhugeliangLabel;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *upHint1;
    QLabel *upHint2;
    QFrame *middleFrame;
    QFrame *upperCardRect1;
    QFrame *upperCardRect2;
    QFrame *upperCardRect3;
    QFrame *upperCardRect4;
    QFrame *upperCardRect5;
    QFrame *lowerCardRect1;
    QFrame *lowerCardRect2;
    QFrame *lowerCardRect3;
    QFrame *lowerCardRect4;
    QFrame *lowerCardRect5;
    QFrame *rightFrame;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *_3;
    QLabel *downHint1;
    QLabel *downHint2;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *hintLabel1;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QLabel *hintLabel2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    sgsui::GameButton *okButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *GuanxingBox)
    {
        if (GuanxingBox->objectName().isEmpty())
            GuanxingBox->setObjectName(QString::fromUtf8("GuanxingBox"));
        GuanxingBox->resize(924, 440);
        verticalLayout = new QVBoxLayout(GuanxingBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 50, 20, 30);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        leftFrame = new QFrame(GuanxingBox);
        leftFrame->setObjectName(QString::fromUtf8("leftFrame"));
        leftFrame->setMinimumSize(QSize(214, 276));
        leftFrame->setMaximumSize(QSize(214, 276));
        horizontalLayout_6 = new QHBoxLayout(leftFrame);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        messageLabel = new QLabel(leftFrame);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));

        horizontalLayout_3->addWidget(messageLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        zhugeliangLabel = new sgsui::ResultPlayerLabel(leftFrame);
        zhugeliangLabel->setObjectName(QString::fromUtf8("zhugeliangLabel"));

        horizontalLayout_4->addWidget(zhugeliangLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        upHint1 = new QLabel(leftFrame);
        upHint1->setObjectName(QString::fromUtf8("upHint1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(upHint1->sizePolicy().hasHeightForWidth());
        upHint1->setSizePolicy(sizePolicy);
        upHint1->setMinimumSize(QSize(40, 0));
        upHint1->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(upHint1);

        upHint2 = new QLabel(leftFrame);
        upHint2->setObjectName(QString::fromUtf8("upHint2"));
        sizePolicy.setHeightForWidth(upHint2->sizePolicy().hasHeightForWidth());
        upHint2->setSizePolicy(sizePolicy);
        upHint2->setMinimumSize(QSize(40, 0));
        upHint2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(upHint2);


        horizontalLayout_6->addLayout(verticalLayout_4);


        horizontalLayout_2->addWidget(leftFrame);

        middleFrame = new QFrame(GuanxingBox);
        middleFrame->setObjectName(QString::fromUtf8("middleFrame"));
        middleFrame->setMinimumSize(QSize(503, 276));
        middleFrame->setMaximumSize(QSize(503, 276));
        upperCardRect1 = new QFrame(middleFrame);
        upperCardRect1->setObjectName(QString::fromUtf8("upperCardRect1"));
        upperCardRect1->setGeometry(QRect(1, 1, 93, 130));
        upperCardRect1->setMinimumSize(QSize(93, 130));
        upperCardRect1->setMaximumSize(QSize(93, 130));
        upperCardRect2 = new QFrame(middleFrame);
        upperCardRect2->setObjectName(QString::fromUtf8("upperCardRect2"));
        upperCardRect2->setGeometry(QRect(103, 1, 93, 130));
        upperCardRect2->setMinimumSize(QSize(93, 130));
        upperCardRect2->setMaximumSize(QSize(93, 130));
        upperCardRect3 = new QFrame(middleFrame);
        upperCardRect3->setObjectName(QString::fromUtf8("upperCardRect3"));
        upperCardRect3->setGeometry(QRect(205, 1, 93, 130));
        upperCardRect3->setMinimumSize(QSize(93, 130));
        upperCardRect3->setMaximumSize(QSize(93, 130));
        upperCardRect4 = new QFrame(middleFrame);
        upperCardRect4->setObjectName(QString::fromUtf8("upperCardRect4"));
        upperCardRect4->setGeometry(QRect(307, 1, 93, 130));
        upperCardRect4->setMinimumSize(QSize(93, 130));
        upperCardRect4->setMaximumSize(QSize(93, 130));
        upperCardRect5 = new QFrame(middleFrame);
        upperCardRect5->setObjectName(QString::fromUtf8("upperCardRect5"));
        upperCardRect5->setGeometry(QRect(409, 1, 93, 130));
        upperCardRect5->setMinimumSize(QSize(93, 130));
        upperCardRect5->setMaximumSize(QSize(93, 130));
        lowerCardRect1 = new QFrame(middleFrame);
        lowerCardRect1->setObjectName(QString::fromUtf8("lowerCardRect1"));
        lowerCardRect1->setGeometry(QRect(1, 145, 93, 130));
        lowerCardRect1->setMinimumSize(QSize(93, 130));
        lowerCardRect1->setMaximumSize(QSize(93, 130));
        lowerCardRect2 = new QFrame(middleFrame);
        lowerCardRect2->setObjectName(QString::fromUtf8("lowerCardRect2"));
        lowerCardRect2->setGeometry(QRect(103, 145, 93, 130));
        lowerCardRect2->setMinimumSize(QSize(93, 130));
        lowerCardRect2->setMaximumSize(QSize(93, 130));
        lowerCardRect3 = new QFrame(middleFrame);
        lowerCardRect3->setObjectName(QString::fromUtf8("lowerCardRect3"));
        lowerCardRect3->setGeometry(QRect(205, 145, 93, 130));
        lowerCardRect3->setMinimumSize(QSize(93, 130));
        lowerCardRect3->setMaximumSize(QSize(93, 130));
        lowerCardRect4 = new QFrame(middleFrame);
        lowerCardRect4->setObjectName(QString::fromUtf8("lowerCardRect4"));
        lowerCardRect4->setGeometry(QRect(307, 145, 93, 130));
        lowerCardRect4->setMinimumSize(QSize(93, 130));
        lowerCardRect4->setMaximumSize(QSize(93, 130));
        lowerCardRect5 = new QFrame(middleFrame);
        lowerCardRect5->setObjectName(QString::fromUtf8("lowerCardRect5"));
        lowerCardRect5->setGeometry(QRect(409, 145, 93, 130));
        lowerCardRect5->setMinimumSize(QSize(93, 130));
        lowerCardRect5->setMaximumSize(QSize(93, 130));

        horizontalLayout_2->addWidget(middleFrame);

        rightFrame = new QFrame(GuanxingBox);
        rightFrame->setObjectName(QString::fromUtf8("rightFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rightFrame->sizePolicy().hasHeightForWidth());
        rightFrame->setSizePolicy(sizePolicy1);
        horizontalLayout_5 = new QHBoxLayout(rightFrame);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 20, 0);
        _3 = new QVBoxLayout();
        _3->setSpacing(0);
        _3->setObjectName(QString::fromUtf8("_3"));
        downHint1 = new QLabel(rightFrame);
        downHint1->setObjectName(QString::fromUtf8("downHint1"));
        sizePolicy.setHeightForWidth(downHint1->sizePolicy().hasHeightForWidth());
        downHint1->setSizePolicy(sizePolicy);
        downHint1->setMinimumSize(QSize(40, 0));
        downHint1->setMaximumSize(QSize(40, 16777215));
        downHint1->setAlignment(Qt::AlignCenter);

        _3->addWidget(downHint1);

        downHint2 = new QLabel(rightFrame);
        downHint2->setObjectName(QString::fromUtf8("downHint2"));
        sizePolicy.setHeightForWidth(downHint2->sizePolicy().hasHeightForWidth());
        downHint2->setSizePolicy(sizePolicy);
        downHint2->setMinimumSize(QSize(40, 0));
        downHint2->setMaximumSize(QSize(40, 16777215));
        downHint2->setAlignment(Qt::AlignCenter);

        _3->addWidget(downHint2);


        horizontalLayout_5->addLayout(_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        _2 = new QVBoxLayout();
        _2->setObjectName(QString::fromUtf8("_2"));
        verticalSpacer_3 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _2->addItem(verticalSpacer_3);

        hintLabel1 = new QLabel(rightFrame);
        hintLabel1->setObjectName(QString::fromUtf8("hintLabel1"));

        _2->addWidget(hintLabel1);

        verticalSpacer_4 = new QSpacerItem(20, 57, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _2->addItem(verticalSpacer_4);

        verticalSpacer_6 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _2->addItem(verticalSpacer_6);

        hintLabel2 = new QLabel(rightFrame);
        hintLabel2->setObjectName(QString::fromUtf8("hintLabel2"));

        _2->addWidget(hintLabel2);

        verticalSpacer_5 = new QSpacerItem(20, 57, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _2->addItem(verticalSpacer_5);


        horizontalLayout_5->addLayout(_2);


        horizontalLayout_2->addWidget(rightFrame);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new sgsui::GameButton(GuanxingBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuanxingBox);

        QMetaObject::connectSlotsByName(GuanxingBox);
    } // setupUi

    void retranslateUi(QWidget *GuanxingBox)
    {
        messageLabel->setText(QApplication::translate("GuanxingBox", "<font color=white><b>\350\247\202\346\230\237</b><font>", 0, QApplication::UnicodeUTF8));
        upHint1->setText(QApplication::translate("GuanxingBox", "<font color=white><b>\344\270\212</b><font>", 0, QApplication::UnicodeUTF8));
        upHint2->setText(QApplication::translate("GuanxingBox", "<font color=white><b>\344\270\212</b><font>", 0, QApplication::UnicodeUTF8));
        downHint1->setText(QApplication::translate("GuanxingBox", "<font color=white><b>\344\270\213</b><font>", 0, QApplication::UnicodeUTF8));
        downHint2->setText(QApplication::translate("GuanxingBox", "<font color=white><b>\344\270\213</b><font>", 0, QApplication::UnicodeUTF8));
        hintLabel1->setText(QApplication::translate("GuanxingBox", "<font color=white>\347\211\214\345\240\206\351\241\266\351\203\250<font>", 0, QApplication::UnicodeUTF8));
        hintLabel2->setText(QApplication::translate("GuanxingBox", "<font color=white>\347\211\214\345\240\206\345\272\225\351\203\250<font>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GuanxingBox);
    } // retranslateUi

};

namespace Ui {
    class GuanxingBox: public Ui_GuanxingBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUANXINGBOX_H
