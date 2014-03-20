/********************************************************************************
** Form generated from reading UI file 'InitiateBox.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIATEBOX_H
#define UI_INITIATEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitiateBox
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *playerNumSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *roleButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QCheckBox *AICheckBox;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *packageLabel;
    QCheckBox *jzpCheckBox;
    QCheckBox *fengCheckBox;
    QCheckBox *huoCheckBox;
    QCheckBox *linCheckBox;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpinBox *shaSpinBox;
    QCheckBox *shaCheckBox;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *audioLabel;
    QCheckBox *musicCheckBox;
    QCheckBox *soundCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *graphicLabel;
    QCheckBox *fullscreenCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QWidget *debugOption;
    QHBoxLayout *horizontalLayout_8;
    QLabel *debugLogLabel;
    QCheckBox *debugLogCheckBox;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *startButton;

    void setupUi(QDialog *InitiateBox)
    {
        if (InitiateBox->objectName().isEmpty())
            InitiateBox->setObjectName(QString::fromUtf8("InitiateBox"));
        InitiateBox->resize(403, 227);
        verticalLayout = new QVBoxLayout(InitiateBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(InitiateBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        playerNumSpinBox = new QSpinBox(tab);
        playerNumSpinBox->setObjectName(QString::fromUtf8("playerNumSpinBox"));
        playerNumSpinBox->setMinimum(2);
        playerNumSpinBox->setMaximum(8);
        playerNumSpinBox->setValue(8);

        horizontalLayout_2->addWidget(playerNumSpinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        roleButton = new QPushButton(tab);
        roleButton->setObjectName(QString::fromUtf8("roleButton"));
        roleButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(roleButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        AICheckBox = new QCheckBox(tab);
        AICheckBox->setObjectName(QString::fromUtf8("AICheckBox"));

        horizontalLayout_7->addWidget(AICheckBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        packageLabel = new QLabel(tab);
        packageLabel->setObjectName(QString::fromUtf8("packageLabel"));

        horizontalLayout_5->addWidget(packageLabel);

        jzpCheckBox = new QCheckBox(tab);
        jzpCheckBox->setObjectName(QString::fromUtf8("jzpCheckBox"));
        jzpCheckBox->setEnabled(false);

        horizontalLayout_5->addWidget(jzpCheckBox);

        fengCheckBox = new QCheckBox(tab);
        fengCheckBox->setObjectName(QString::fromUtf8("fengCheckBox"));
        fengCheckBox->setEnabled(false);

        horizontalLayout_5->addWidget(fengCheckBox);

        huoCheckBox = new QCheckBox(tab);
        huoCheckBox->setObjectName(QString::fromUtf8("huoCheckBox"));
        huoCheckBox->setEnabled(false);

        horizontalLayout_5->addWidget(huoCheckBox);

        linCheckBox = new QCheckBox(tab);
        linCheckBox->setObjectName(QString::fromUtf8("linCheckBox"));
        linCheckBox->setEnabled(false);

        horizontalLayout_5->addWidget(linCheckBox);


        verticalLayout_3->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        shaSpinBox = new QSpinBox(tab_2);
        shaSpinBox->setObjectName(QString::fromUtf8("shaSpinBox"));
        shaSpinBox->setMinimum(1);
        shaSpinBox->setMaximum(99999);

        horizontalLayout_6->addWidget(shaSpinBox);

        shaCheckBox = new QCheckBox(tab_2);
        shaCheckBox->setObjectName(QString::fromUtf8("shaCheckBox"));

        horizontalLayout_6->addWidget(shaCheckBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        audioLabel = new QLabel(tab_3);
        audioLabel->setObjectName(QString::fromUtf8("audioLabel"));

        horizontalLayout_3->addWidget(audioLabel);

        musicCheckBox = new QCheckBox(tab_3);
        musicCheckBox->setObjectName(QString::fromUtf8("musicCheckBox"));
        musicCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(musicCheckBox);

        soundCheckBox = new QCheckBox(tab_3);
        soundCheckBox->setObjectName(QString::fromUtf8("soundCheckBox"));
        soundCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(soundCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        graphicLabel = new QLabel(tab_3);
        graphicLabel->setObjectName(QString::fromUtf8("graphicLabel"));

        horizontalLayout_4->addWidget(graphicLabel);

        fullscreenCheckBox = new QCheckBox(tab_3);
        fullscreenCheckBox->setObjectName(QString::fromUtf8("fullscreenCheckBox"));
        fullscreenCheckBox->setChecked(true);

        horizontalLayout_4->addWidget(fullscreenCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        debugOption = new QWidget(InitiateBox);
        debugOption->setObjectName(QString::fromUtf8("debugOption"));
        horizontalLayout_8 = new QHBoxLayout(debugOption);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        debugLogLabel = new QLabel(debugOption);
        debugLogLabel->setObjectName(QString::fromUtf8("debugLogLabel"));

        horizontalLayout_8->addWidget(debugLogLabel);

        debugLogCheckBox = new QCheckBox(debugOption);
        debugLogCheckBox->setObjectName(QString::fromUtf8("debugLogCheckBox"));

        horizontalLayout_8->addWidget(debugLogCheckBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(debugOption);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startButton = new QPushButton(InitiateBox);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy);
        startButton->setDefault(true);

        horizontalLayout->addWidget(startButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(InitiateBox);
        QObject::connect(shaCheckBox, SIGNAL(clicked(bool)), shaSpinBox, SLOT(setDisabled(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InitiateBox);
    } // setupUi

    void retranslateUi(QDialog *InitiateBox)
    {
        InitiateBox->setWindowTitle(QApplication::translate("InitiateBox", "\344\270\211\345\233\275\346\235\200EX", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InitiateBox", "\347\216\251\345\256\266\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        playerNumSpinBox->setSuffix(QApplication::translate("InitiateBox", "\344\272\272\345\261\200", 0, QApplication::UnicodeUTF8));
        roleButton->setText(QApplication::translate("InitiateBox", "\345\257\237\347\234\213\350\272\253\344\273\275\345\210\206\351\205\215", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InitiateBox", "\344\272\272\345\267\245\346\231\272\350\203\275", 0, QApplication::UnicodeUTF8));
        AICheckBox->setText(QApplication::translate("InitiateBox", "\346\211\230\347\256\241\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        packageLabel->setText(QApplication::translate("InitiateBox", "\351\231\204\345\212\240\345\214\205", 0, QApplication::UnicodeUTF8));
        jzpCheckBox->setText(QApplication::translate("InitiateBox", "\345\206\233\344\272\211\347\257\207", 0, QApplication::UnicodeUTF8));
        fengCheckBox->setText(QApplication::translate("InitiateBox", "\351\243\216", 0, QApplication::UnicodeUTF8));
        huoCheckBox->setText(QApplication::translate("InitiateBox", "\347\201\253", 0, QApplication::UnicodeUTF8));
        linCheckBox->setText(QApplication::translate("InitiateBox", "\346\236\227", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("InitiateBox", "\345\237\272\346\234\254\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InitiateBox", "\346\257\217\345\233\236\345\220\210\345\217\257\347\224\250\346\235\200\346\225\260", 0, QApplication::UnicodeUTF8));
        shaCheckBox->setText(QApplication::translate("InitiateBox", "\346\262\241\346\234\211\351\231\220\345\210\266", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("InitiateBox", "\350\247\204\345\210\231\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        audioLabel->setText(QApplication::translate("InitiateBox", "\345\243\260\351\237\263\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        musicCheckBox->setText(QApplication::translate("InitiateBox", "\345\274\200\345\220\257\350\203\214\346\231\257\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
        soundCheckBox->setText(QApplication::translate("InitiateBox", "\345\274\200\345\220\257\346\270\270\346\210\217\351\237\263\346\225\210", 0, QApplication::UnicodeUTF8));
        graphicLabel->setText(QApplication::translate("InitiateBox", "\345\233\276\345\275\242\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        fullscreenCheckBox->setText(QApplication::translate("InitiateBox", "\345\205\250\345\261\217\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("InitiateBox", "\345\205\266\345\256\203\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        debugLogLabel->setText(QApplication::translate("InitiateBox", "\350\260\203\350\257\225\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        debugLogCheckBox->setText(QApplication::translate("InitiateBox", "\350\260\203\350\257\225\346\227\245\345\277\227\357\274\210\345\217\257\350\203\275\344\274\232\351\231\215\344\275\216\346\270\270\346\210\217\346\265\201\347\225\205\345\272\246\357\274\211", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("InitiateBox", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InitiateBox: public Ui_InitiateBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIATEBOX_H
