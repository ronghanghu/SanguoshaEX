/********************************************************************************
** Form generated from reading UI file 'ZhuangbeiArea.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUANGBEIAREA_H
#define UI_ZHUANGBEIAREA_H

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

class Ui_ZhuangbeiArea
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *judge0;
    QLabel *judge1;
    QLabel *judge2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *wuqiWidget;
    QWidget *fangjuWidget;
    QWidget *jianmaWidget;
    QWidget *jiamaWidget;

    void setupUi(QWidget *ZhuangbeiArea)
    {
        if (ZhuangbeiArea->objectName().isEmpty())
            ZhuangbeiArea->setObjectName(QString::fromUtf8("ZhuangbeiArea"));
        ZhuangbeiArea->resize(166, 205);
        verticalLayout = new QVBoxLayout(ZhuangbeiArea);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 3, -1, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        judge0 = new QLabel(ZhuangbeiArea);
        judge0->setObjectName(QString::fromUtf8("judge0"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(judge0->sizePolicy().hasHeightForWidth());
        judge0->setSizePolicy(sizePolicy);
        judge0->setMinimumSize(QSize(28, 28));

        horizontalLayout->addWidget(judge0);

        judge1 = new QLabel(ZhuangbeiArea);
        judge1->setObjectName(QString::fromUtf8("judge1"));
        sizePolicy.setHeightForWidth(judge1->sizePolicy().hasHeightForWidth());
        judge1->setSizePolicy(sizePolicy);
        judge1->setMinimumSize(QSize(28, 28));

        horizontalLayout->addWidget(judge1);

        judge2 = new QLabel(ZhuangbeiArea);
        judge2->setObjectName(QString::fromUtf8("judge2"));
        sizePolicy.setHeightForWidth(judge2->sizePolicy().hasHeightForWidth());
        judge2->setSizePolicy(sizePolicy);
        judge2->setMinimumSize(QSize(28, 28));

        horizontalLayout->addWidget(judge2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        wuqiWidget = new QWidget(ZhuangbeiArea);
        wuqiWidget->setObjectName(QString::fromUtf8("wuqiWidget"));
        wuqiWidget->setMinimumSize(QSize(147, 29));
        wuqiWidget->setMaximumSize(QSize(147, 29));

        verticalLayout->addWidget(wuqiWidget);

        fangjuWidget = new QWidget(ZhuangbeiArea);
        fangjuWidget->setObjectName(QString::fromUtf8("fangjuWidget"));
        fangjuWidget->setMinimumSize(QSize(147, 29));
        fangjuWidget->setMaximumSize(QSize(147, 29));

        verticalLayout->addWidget(fangjuWidget);

        jianmaWidget = new QWidget(ZhuangbeiArea);
        jianmaWidget->setObjectName(QString::fromUtf8("jianmaWidget"));
        jianmaWidget->setMinimumSize(QSize(147, 29));
        jianmaWidget->setMaximumSize(QSize(147, 29));

        verticalLayout->addWidget(jianmaWidget);

        jiamaWidget = new QWidget(ZhuangbeiArea);
        jiamaWidget->setObjectName(QString::fromUtf8("jiamaWidget"));
        jiamaWidget->setMinimumSize(QSize(147, 29));
        jiamaWidget->setMaximumSize(QSize(147, 29));

        verticalLayout->addWidget(jiamaWidget);


        retranslateUi(ZhuangbeiArea);

        QMetaObject::connectSlotsByName(ZhuangbeiArea);
    } // setupUi

    void retranslateUi(QWidget *ZhuangbeiArea)
    {
        Q_UNUSED(ZhuangbeiArea);
    } // retranslateUi

};

namespace Ui {
    class ZhuangbeiArea: public Ui_ZhuangbeiArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUANGBEIAREA_H
