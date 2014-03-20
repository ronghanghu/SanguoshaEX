/********************************************************************************
** Form generated from reading UI file 'HelpBox.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPBOX_H
#define UI_HELPBOX_H

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
#include "sgsui_GameButton.h"
#include "sgsui_TextBrowser.h"

QT_BEGIN_NAMESPACE

class Ui_HelpBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *messageLabel;
    sgsui::TextBrowser *helpText;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    sgsui::GameButton *okButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *HelpBox)
    {
        if (HelpBox->objectName().isEmpty())
            HelpBox->setObjectName(QString::fromUtf8("HelpBox"));
        HelpBox->resize(306, 331);
        verticalLayout = new QVBoxLayout(HelpBox);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(25, 30, 25, 30);
        messageLabel = new QLabel(HelpBox);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(messageLabel);

        helpText = new sgsui::TextBrowser(HelpBox);
        helpText->setObjectName(QString::fromUtf8("helpText"));

        verticalLayout->addWidget(helpText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okButton = new sgsui::GameButton(HelpBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(HelpBox);

        QMetaObject::connectSlotsByName(HelpBox);
    } // setupUi

    void retranslateUi(QWidget *HelpBox)
    {
        messageLabel->setText(QApplication::translate("HelpBox", "<font color=white><b>\344\270\211\345\233\275\346\235\200EX\345\270\256\345\212\251</b></font>", 0, QApplication::UnicodeUTF8));
        helpText->setHtml(QApplication::translate("HelpBox", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; marg"
                        "in-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(HelpBox);
    } // retranslateUi

};

namespace Ui {
    class HelpBox: public Ui_HelpBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPBOX_H
