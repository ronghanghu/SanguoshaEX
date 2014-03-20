/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed Jul 18 10:25:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "sgsui_GameButton.h"
#include "sgsui_GameCheckBox.h"
#include "sgsui_RoleFrame.h"
#include "sgsui_SkillButton.h"
#include "sgsui_SmartStatusBar.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *mainLayout;
    QFrame *mainFrame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *mainPlayerLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QFrame *playerFrame6;
    QSpacerItem *verticalSpacer_2;
    QFrame *playerFrame7;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *centralPlayerLayout;
    QSpacerItem *player5spacer;
    QFrame *playerFrame5;
    QSpacerItem *horizontalSpacer_4;
    QFrame *playerFrame4;
    QSpacerItem *horizontalSpacer_3;
    QFrame *playerFrame3;
    QSpacerItem *horizontalSpacer_2;
    QFrame *chupaiArea;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QFrame *cardDeckFrame;
    QHBoxLayout *horizontalLayout_8;
    QLabel *cardDeckLabel;
    QFrame *usedCardFrame;
    QHBoxLayout *usedCardLayout;
    QSpacerItem *usedCardSpacer;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_8;
    QFrame *playerFrame2;
    QSpacerItem *verticalSpacer_7;
    QFrame *playerFrame1;
    QSpacerItem *verticalSpacer_6;
    QFrame *buttonsFrame;
    QHBoxLayout *horizontalLayout_7;
    sgsui::GameButton *bigPauseButton;
    sgsui::GameButton *helpButton;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer;
    QCheckBox *debugCheckBox;
    sgsui::BlockableButton *okButton;
    sgsui::BlockableButton *cancelButton;
    sgsui::BlockableButton *abandonButton;
    QFrame *rightFrame;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    sgsui::GameButton *aboutButton;
    QSpacerItem *horizontalSpacer_5;
    sgsui::GameButton *quitButton;
    QFrame *optionFrame;
    QVBoxLayout *_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    sgsui::GameCheckBox *musicCheckBox;
    QSpacerItem *horizontalSpacer_9;
    sgsui::GameCheckBox *soundCheckBox;
    QHBoxLayout *horizontalLayout_5;
    sgsui::GameCheckBox *fullscreenCheckBox;
    QSpacerItem *horizontalSpacer_10;
    sgsui::GameCheckBox *AICheckBox;
    sgsui::RoleFrame *roleFrame;
    QVBoxLayout *messageLayout;
    QFrame *messageTopFrame;
    QVBoxLayout *_7;
    QFrame *messageMiddleFrame;
    QVBoxLayout *verticalLayout_11;
    QTextBrowser *historyText;
    QFrame *messageButtomFrame;
    QTabWidget *debugTabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QTextBrowser *playerText;
    QHBoxLayout *horizontalLayout_12;
    QSpinBox *playerSpinBox;
    QPushButton *refreshPlayerButton;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_8;
    QTextBrowser *dataText;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *autorefreshCheckBox;
    QSpinBox *autorefreshSpinBox;
    QPushButton *refreshDataButton;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_14;
    QSpinBox *card1;
    QCheckBox *dustbinCheckBox1;
    QHBoxLayout *horizontalLayout_16;
    QSpinBox *card2;
    QCheckBox *dustbinCheckBox2;
    QPushButton *exchangeButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_17;
    QSpinBox *HPPlayerSpinBox;
    QSpinBox *HPSpinBox;
    QPushButton *setHPButton;
    QLabel *resultLabel;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_10;
    QTextBrowser *historyMessageText;
    QComboBox *historyComboBox;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *historySpinBox;
    QPushButton *refreshHistoryButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_9;
    QTextBrowser *debugText;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *singleCheckBox;
    QCheckBox *testCheckBox;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *clearDebugButton;
    QPushButton *pauseButton;
    QWidget *testWidget;
    QVBoxLayout *verticalLayout_13;
    QLabel *label;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *debugButton1;
    QPushButton *debugButton2;
    QPushButton *debugButton3;
    QPushButton *debugButton4;
    QHBoxLayout *lowerLayout;
    QFrame *zhuangbeiArea;
    QFrame *shoupaiArea;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *shoupaiLayout;
    QSpacerItem *horizontalSpacer_6;
    QFrame *wujiangArea;
    sgsui::SmartStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1106, 1028);
        MainWindow->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainFrame = new QFrame(centralwidget);
        mainFrame->setObjectName(QString::fromUtf8("mainFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainFrame->sizePolicy().hasHeightForWidth());
        mainFrame->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(mainFrame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        mainPlayerLayout = new QHBoxLayout();
        mainPlayerLayout->setSpacing(0);
        mainPlayerLayout->setObjectName(QString::fromUtf8("mainPlayerLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        playerFrame6 = new QFrame(mainFrame);
        playerFrame6->setObjectName(QString::fromUtf8("playerFrame6"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(playerFrame6->sizePolicy().hasHeightForWidth());
        playerFrame6->setSizePolicy(sizePolicy1);
        playerFrame6->setMinimumSize(QSize(144, 199));

        verticalLayout->addWidget(playerFrame6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        playerFrame7 = new QFrame(mainFrame);
        playerFrame7->setObjectName(QString::fromUtf8("playerFrame7"));
        sizePolicy1.setHeightForWidth(playerFrame7->sizePolicy().hasHeightForWidth());
        playerFrame7->setSizePolicy(sizePolicy1);
        playerFrame7->setMinimumSize(QSize(144, 199));

        verticalLayout->addWidget(playerFrame7);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        mainPlayerLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        centralPlayerLayout = new QHBoxLayout();
        centralPlayerLayout->setSpacing(0);
        centralPlayerLayout->setObjectName(QString::fromUtf8("centralPlayerLayout"));
        player5spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralPlayerLayout->addItem(player5spacer);

        playerFrame5 = new QFrame(mainFrame);
        playerFrame5->setObjectName(QString::fromUtf8("playerFrame5"));
        sizePolicy1.setHeightForWidth(playerFrame5->sizePolicy().hasHeightForWidth());
        playerFrame5->setSizePolicy(sizePolicy1);
        playerFrame5->setMinimumSize(QSize(144, 199));

        centralPlayerLayout->addWidget(playerFrame5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralPlayerLayout->addItem(horizontalSpacer_4);

        playerFrame4 = new QFrame(mainFrame);
        playerFrame4->setObjectName(QString::fromUtf8("playerFrame4"));
        sizePolicy1.setHeightForWidth(playerFrame4->sizePolicy().hasHeightForWidth());
        playerFrame4->setSizePolicy(sizePolicy1);
        playerFrame4->setMinimumSize(QSize(144, 199));

        centralPlayerLayout->addWidget(playerFrame4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralPlayerLayout->addItem(horizontalSpacer_3);

        playerFrame3 = new QFrame(mainFrame);
        playerFrame3->setObjectName(QString::fromUtf8("playerFrame3"));
        sizePolicy1.setHeightForWidth(playerFrame3->sizePolicy().hasHeightForWidth());
        playerFrame3->setSizePolicy(sizePolicy1);
        playerFrame3->setMinimumSize(QSize(144, 199));

        centralPlayerLayout->addWidget(playerFrame3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        centralPlayerLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(centralPlayerLayout);

        chupaiArea = new QFrame(mainFrame);
        chupaiArea->setObjectName(QString::fromUtf8("chupaiArea"));
        sizePolicy.setHeightForWidth(chupaiArea->sizePolicy().hasHeightForWidth());
        chupaiArea->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(chupaiArea);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(7, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        cardDeckFrame = new QFrame(chupaiArea);
        cardDeckFrame->setObjectName(QString::fromUtf8("cardDeckFrame"));
        cardDeckFrame->setMinimumSize(QSize(103, 130));
        cardDeckFrame->setMaximumSize(QSize(103, 130));
        horizontalLayout_8 = new QHBoxLayout(cardDeckFrame);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        cardDeckLabel = new QLabel(cardDeckFrame);
        cardDeckLabel->setObjectName(QString::fromUtf8("cardDeckLabel"));

        horizontalLayout_8->addWidget(cardDeckLabel);


        horizontalLayout_2->addWidget(cardDeckFrame);

        usedCardFrame = new QFrame(chupaiArea);
        usedCardFrame->setObjectName(QString::fromUtf8("usedCardFrame"));
        usedCardFrame->setMinimumSize(QSize(380, 130));
        usedCardFrame->setMaximumSize(QSize(380, 130));
        usedCardFrame->setLayoutDirection(Qt::RightToLeft);
        usedCardLayout = new QHBoxLayout(usedCardFrame);
        usedCardLayout->setSpacing(0);
        usedCardLayout->setObjectName(QString::fromUtf8("usedCardLayout"));
        usedCardLayout->setContentsMargins(8, 0, 0, 0);
        usedCardSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        usedCardLayout->addItem(usedCardSpacer);


        horizontalLayout_2->addWidget(usedCardFrame);

        horizontalSpacer_8 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout_3->addWidget(chupaiArea);


        mainPlayerLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        playerFrame2 = new QFrame(mainFrame);
        playerFrame2->setObjectName(QString::fromUtf8("playerFrame2"));
        sizePolicy1.setHeightForWidth(playerFrame2->sizePolicy().hasHeightForWidth());
        playerFrame2->setSizePolicy(sizePolicy1);
        playerFrame2->setMinimumSize(QSize(144, 199));

        verticalLayout_2->addWidget(playerFrame2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        playerFrame1 = new QFrame(mainFrame);
        playerFrame1->setObjectName(QString::fromUtf8("playerFrame1"));
        sizePolicy1.setHeightForWidth(playerFrame1->sizePolicy().hasHeightForWidth());
        playerFrame1->setSizePolicy(sizePolicy1);
        playerFrame1->setMinimumSize(QSize(144, 199));

        verticalLayout_2->addWidget(playerFrame1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        mainPlayerLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(mainPlayerLayout);

        buttonsFrame = new QFrame(mainFrame);
        buttonsFrame->setObjectName(QString::fromUtf8("buttonsFrame"));
        horizontalLayout_7 = new QHBoxLayout(buttonsFrame);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(3, -1, 0, 0);
        bigPauseButton = new sgsui::GameButton(buttonsFrame);
        bigPauseButton->setObjectName(QString::fromUtf8("bigPauseButton"));

        horizontalLayout_7->addWidget(bigPauseButton);

        helpButton = new sgsui::GameButton(buttonsFrame);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        horizontalLayout_7->addWidget(helpButton);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        debugCheckBox = new QCheckBox(buttonsFrame);
        debugCheckBox->setObjectName(QString::fromUtf8("debugCheckBox"));

        horizontalLayout_7->addWidget(debugCheckBox);

        okButton = new sgsui::BlockableButton(buttonsFrame);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_7->addWidget(okButton);

        cancelButton = new sgsui::BlockableButton(buttonsFrame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_7->addWidget(cancelButton);

        abandonButton = new sgsui::BlockableButton(buttonsFrame);
        abandonButton->setObjectName(QString::fromUtf8("abandonButton"));

        horizontalLayout_7->addWidget(abandonButton);


        verticalLayout_4->addWidget(buttonsFrame);


        mainLayout->addWidget(mainFrame);

        rightFrame = new QFrame(centralwidget);
        rightFrame->setObjectName(QString::fromUtf8("rightFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rightFrame->sizePolicy().hasHeightForWidth());
        rightFrame->setSizePolicy(sizePolicy2);
        rightFrame->setMinimumSize(QSize(190, 0));
        rightFrame->setMaximumSize(QSize(190, 16777215));
        verticalLayout_5 = new QVBoxLayout(rightFrame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, -1, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 6, -1);
        aboutButton = new sgsui::GameButton(rightFrame);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));

        horizontalLayout->addWidget(aboutButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        quitButton = new sgsui::GameButton(rightFrame);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout_5->addLayout(horizontalLayout);

        optionFrame = new QFrame(rightFrame);
        optionFrame->setObjectName(QString::fromUtf8("optionFrame"));
        optionFrame->setMinimumSize(QSize(190, 135));
        optionFrame->setMaximumSize(QSize(190, 135));
        _2 = new QVBoxLayout(optionFrame);
        _2->setObjectName(QString::fromUtf8("_2"));
        _2->setContentsMargins(24, -1, 24, 26);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _2->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(42, -1, -1, 2);
        musicCheckBox = new sgsui::GameCheckBox(optionFrame);
        musicCheckBox->setObjectName(QString::fromUtf8("musicCheckBox"));
        musicCheckBox->setMinimumSize(QSize(16, 16));
        musicCheckBox->setMaximumSize(QSize(16, 16));
        musicCheckBox->setChecked(true);

        horizontalLayout_6->addWidget(musicCheckBox);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        soundCheckBox = new sgsui::GameCheckBox(optionFrame);
        soundCheckBox->setObjectName(QString::fromUtf8("soundCheckBox"));
        soundCheckBox->setMinimumSize(QSize(16, 16));
        soundCheckBox->setMaximumSize(QSize(16, 16));
        soundCheckBox->setChecked(true);

        horizontalLayout_6->addWidget(soundCheckBox);


        _2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(42, -1, -1, -1);
        fullscreenCheckBox = new sgsui::GameCheckBox(optionFrame);
        fullscreenCheckBox->setObjectName(QString::fromUtf8("fullscreenCheckBox"));
        fullscreenCheckBox->setMinimumSize(QSize(16, 16));
        fullscreenCheckBox->setMaximumSize(QSize(16, 16));
        fullscreenCheckBox->setChecked(true);

        horizontalLayout_5->addWidget(fullscreenCheckBox);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        AICheckBox = new sgsui::GameCheckBox(optionFrame);
        AICheckBox->setObjectName(QString::fromUtf8("AICheckBox"));
        AICheckBox->setMinimumSize(QSize(16, 16));
        AICheckBox->setMaximumSize(QSize(16, 16));

        horizontalLayout_5->addWidget(AICheckBox);


        _2->addLayout(horizontalLayout_5);


        verticalLayout_5->addWidget(optionFrame);

        roleFrame = new sgsui::RoleFrame(rightFrame);
        roleFrame->setObjectName(QString::fromUtf8("roleFrame"));

        verticalLayout_5->addWidget(roleFrame);

        messageLayout = new QVBoxLayout();
        messageLayout->setSpacing(0);
        messageLayout->setObjectName(QString::fromUtf8("messageLayout"));
        messageLayout->setContentsMargins(-1, 0, -1, -1);
        messageTopFrame = new QFrame(rightFrame);
        messageTopFrame->setObjectName(QString::fromUtf8("messageTopFrame"));
        messageTopFrame->setMinimumSize(QSize(190, 43));
        messageTopFrame->setMaximumSize(QSize(190, 43));
        _7 = new QVBoxLayout(messageTopFrame);
        _7->setObjectName(QString::fromUtf8("_7"));

        messageLayout->addWidget(messageTopFrame);

        messageMiddleFrame = new QFrame(rightFrame);
        messageMiddleFrame->setObjectName(QString::fromUtf8("messageMiddleFrame"));
        sizePolicy2.setHeightForWidth(messageMiddleFrame->sizePolicy().hasHeightForWidth());
        messageMiddleFrame->setSizePolicy(sizePolicy2);
        messageMiddleFrame->setMinimumSize(QSize(190, 0));
        messageMiddleFrame->setMaximumSize(QSize(190, 16777215));
        verticalLayout_11 = new QVBoxLayout(messageMiddleFrame);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(15, -1, 15, 4);
        historyText = new QTextBrowser(messageMiddleFrame);
        historyText->setObjectName(QString::fromUtf8("historyText"));
        historyText->setStyleSheet(QString::fromUtf8(""));
        historyText->setFrameShape(QFrame::NoFrame);

        verticalLayout_11->addWidget(historyText);


        messageLayout->addWidget(messageMiddleFrame);

        messageButtomFrame = new QFrame(rightFrame);
        messageButtomFrame->setObjectName(QString::fromUtf8("messageButtomFrame"));
        messageButtomFrame->setMinimumSize(QSize(190, 13));
        messageButtomFrame->setMaximumSize(QSize(190, 13));

        messageLayout->addWidget(messageButtomFrame);


        verticalLayout_5->addLayout(messageLayout);

        debugTabWidget = new QTabWidget(rightFrame);
        debugTabWidget->setObjectName(QString::fromUtf8("debugTabWidget"));
        debugTabWidget->setAutoFillBackground(true);
        debugTabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        playerText = new QTextBrowser(tab);
        playerText->setObjectName(QString::fromUtf8("playerText"));

        verticalLayout_7->addWidget(playerText);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        playerSpinBox = new QSpinBox(tab);
        playerSpinBox->setObjectName(QString::fromUtf8("playerSpinBox"));
        playerSpinBox->setMaximum(7);

        horizontalLayout_12->addWidget(playerSpinBox);

        refreshPlayerButton = new QPushButton(tab);
        refreshPlayerButton->setObjectName(QString::fromUtf8("refreshPlayerButton"));

        horizontalLayout_12->addWidget(refreshPlayerButton);


        verticalLayout_7->addLayout(horizontalLayout_12);

        debugTabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_8 = new QVBoxLayout(tab_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        dataText = new QTextBrowser(tab_4);
        dataText->setObjectName(QString::fromUtf8("dataText"));

        verticalLayout_8->addWidget(dataText);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        autorefreshCheckBox = new QCheckBox(tab_4);
        autorefreshCheckBox->setObjectName(QString::fromUtf8("autorefreshCheckBox"));

        horizontalLayout_4->addWidget(autorefreshCheckBox);

        autorefreshSpinBox = new QSpinBox(tab_4);
        autorefreshSpinBox->setObjectName(QString::fromUtf8("autorefreshSpinBox"));
        autorefreshSpinBox->setMinimum(1);

        horizontalLayout_4->addWidget(autorefreshSpinBox);


        verticalLayout_8->addLayout(horizontalLayout_4);

        refreshDataButton = new QPushButton(tab_4);
        refreshDataButton->setObjectName(QString::fromUtf8("refreshDataButton"));

        verticalLayout_8->addWidget(refreshDataButton);

        debugTabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_12 = new QVBoxLayout(tab_5);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(5, -1, 5, -1);
        groupBox = new QGroupBox(tab_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_15 = new QVBoxLayout(groupBox);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        card1 = new QSpinBox(groupBox);
        card1->setObjectName(QString::fromUtf8("card1"));
        card1->setMinimum(1);

        horizontalLayout_14->addWidget(card1);

        dustbinCheckBox1 = new QCheckBox(groupBox);
        dustbinCheckBox1->setObjectName(QString::fromUtf8("dustbinCheckBox1"));

        horizontalLayout_14->addWidget(dustbinCheckBox1);


        verticalLayout_15->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        card2 = new QSpinBox(groupBox);
        card2->setObjectName(QString::fromUtf8("card2"));
        card2->setMinimum(1);

        horizontalLayout_16->addWidget(card2);

        dustbinCheckBox2 = new QCheckBox(groupBox);
        dustbinCheckBox2->setObjectName(QString::fromUtf8("dustbinCheckBox2"));

        horizontalLayout_16->addWidget(dustbinCheckBox2);


        verticalLayout_15->addLayout(horizontalLayout_16);

        exchangeButton = new QPushButton(groupBox);
        exchangeButton->setObjectName(QString::fromUtf8("exchangeButton"));

        verticalLayout_15->addWidget(exchangeButton);


        verticalLayout_12->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_16 = new QVBoxLayout(groupBox_2);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        HPPlayerSpinBox = new QSpinBox(groupBox_2);
        HPPlayerSpinBox->setObjectName(QString::fromUtf8("HPPlayerSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(HPPlayerSpinBox->sizePolicy().hasHeightForWidth());
        HPPlayerSpinBox->setSizePolicy(sizePolicy3);
        HPPlayerSpinBox->setMaximum(7);

        horizontalLayout_17->addWidget(HPPlayerSpinBox);

        HPSpinBox = new QSpinBox(groupBox_2);
        HPSpinBox->setObjectName(QString::fromUtf8("HPSpinBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(HPSpinBox->sizePolicy().hasHeightForWidth());
        HPSpinBox->setSizePolicy(sizePolicy4);
        HPSpinBox->setMinimum(1);

        horizontalLayout_17->addWidget(HPSpinBox);


        verticalLayout_16->addLayout(horizontalLayout_17);

        setHPButton = new QPushButton(groupBox_2);
        setHPButton->setObjectName(QString::fromUtf8("setHPButton"));

        verticalLayout_16->addWidget(setHPButton);


        verticalLayout_12->addWidget(groupBox_2);

        resultLabel = new QLabel(tab_5);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setWordWrap(true);

        verticalLayout_12->addWidget(resultLabel);

        debugTabWidget->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_10 = new QVBoxLayout(tab_3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        historyMessageText = new QTextBrowser(tab_3);
        historyMessageText->setObjectName(QString::fromUtf8("historyMessageText"));

        verticalLayout_10->addWidget(historyMessageText);

        historyComboBox = new QComboBox(tab_3);
        historyComboBox->setObjectName(QString::fromUtf8("historyComboBox"));

        verticalLayout_10->addWidget(historyComboBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        historySpinBox = new QSpinBox(tab_3);
        historySpinBox->setObjectName(QString::fromUtf8("historySpinBox"));
        historySpinBox->setMinimum(1);

        horizontalLayout_3->addWidget(historySpinBox);

        refreshHistoryButton = new QPushButton(tab_3);
        refreshHistoryButton->setObjectName(QString::fromUtf8("refreshHistoryButton"));

        horizontalLayout_3->addWidget(refreshHistoryButton);


        verticalLayout_10->addLayout(horizontalLayout_3);

        debugTabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_9 = new QVBoxLayout(tab_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        debugText = new QTextBrowser(tab_2);
        debugText->setObjectName(QString::fromUtf8("debugText"));

        verticalLayout_9->addWidget(debugText);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, -1, -1, 0);
        singleCheckBox = new QCheckBox(tab_2);
        singleCheckBox->setObjectName(QString::fromUtf8("singleCheckBox"));

        horizontalLayout_13->addWidget(singleCheckBox);

        testCheckBox = new QCheckBox(tab_2);
        testCheckBox->setObjectName(QString::fromUtf8("testCheckBox"));

        horizontalLayout_13->addWidget(testCheckBox);


        verticalLayout_9->addLayout(horizontalLayout_13);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, -1, -1, 0);
        clearDebugButton = new QPushButton(tab_2);
        clearDebugButton->setObjectName(QString::fromUtf8("clearDebugButton"));

        horizontalLayout_11->addWidget(clearDebugButton);

        pauseButton = new QPushButton(tab_2);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setCheckable(true);

        horizontalLayout_11->addWidget(pauseButton);


        verticalLayout_9->addLayout(horizontalLayout_11);

        testWidget = new QWidget(tab_2);
        testWidget->setObjectName(QString::fromUtf8("testWidget"));
        verticalLayout_13 = new QVBoxLayout(testWidget);
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label = new QLabel(testWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout_13->addWidget(label);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        debugButton1 = new QPushButton(testWidget);
        debugButton1->setObjectName(QString::fromUtf8("debugButton1"));

        horizontalLayout_10->addWidget(debugButton1);

        debugButton2 = new QPushButton(testWidget);
        debugButton2->setObjectName(QString::fromUtf8("debugButton2"));

        horizontalLayout_10->addWidget(debugButton2);

        debugButton3 = new QPushButton(testWidget);
        debugButton3->setObjectName(QString::fromUtf8("debugButton3"));

        horizontalLayout_10->addWidget(debugButton3);

        debugButton4 = new QPushButton(testWidget);
        debugButton4->setObjectName(QString::fromUtf8("debugButton4"));

        horizontalLayout_10->addWidget(debugButton4);


        verticalLayout_13->addLayout(horizontalLayout_10);


        verticalLayout_9->addWidget(testWidget);

        debugTabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(debugTabWidget);


        mainLayout->addWidget(rightFrame);


        verticalLayout_6->addLayout(mainLayout);

        lowerLayout = new QHBoxLayout();
        lowerLayout->setSpacing(0);
        lowerLayout->setObjectName(QString::fromUtf8("lowerLayout"));
        zhuangbeiArea = new QFrame(centralwidget);
        zhuangbeiArea->setObjectName(QString::fromUtf8("zhuangbeiArea"));
        zhuangbeiArea->setMinimumSize(QSize(164, 170));
        zhuangbeiArea->setMaximumSize(QSize(164, 170));

        lowerLayout->addWidget(zhuangbeiArea);

        shoupaiArea = new QFrame(centralwidget);
        shoupaiArea->setObjectName(QString::fromUtf8("shoupaiArea"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(shoupaiArea->sizePolicy().hasHeightForWidth());
        shoupaiArea->setSizePolicy(sizePolicy5);
        shoupaiArea->setMinimumSize(QSize(600, 170));
        shoupaiArea->setMaximumSize(QSize(16777215, 170));
        horizontalLayout_9 = new QHBoxLayout(shoupaiArea);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        shoupaiLayout = new QHBoxLayout();
        shoupaiLayout->setSpacing(0);
        shoupaiLayout->setObjectName(QString::fromUtf8("shoupaiLayout"));

        horizontalLayout_9->addLayout(shoupaiLayout);

        horizontalSpacer_6 = new QSpacerItem(748, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        lowerLayout->addWidget(shoupaiArea);

        wujiangArea = new QFrame(centralwidget);
        wujiangArea->setObjectName(QString::fromUtf8("wujiangArea"));
        wujiangArea->setMinimumSize(QSize(190, 170));
        wujiangArea->setMaximumSize(QSize(190, 170));

        lowerLayout->addWidget(wujiangArea);


        verticalLayout_6->addLayout(lowerLayout);

        statusbar = new sgsui::SmartStatusBar(centralwidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setIndent(20);

        verticalLayout_6->addWidget(statusbar);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(debugCheckBox, SIGNAL(clicked(bool)), messageTopFrame, SLOT(setHidden(bool)));
        QObject::connect(debugCheckBox, SIGNAL(clicked(bool)), messageMiddleFrame, SLOT(setHidden(bool)));
        QObject::connect(debugCheckBox, SIGNAL(clicked(bool)), messageButtomFrame, SLOT(setHidden(bool)));
        QObject::connect(debugCheckBox, SIGNAL(clicked(bool)), debugTabWidget, SLOT(setVisible(bool)));
        QObject::connect(clearDebugButton, SIGNAL(clicked()), debugText, SLOT(clear()));
        QObject::connect(testCheckBox, SIGNAL(clicked(bool)), testWidget, SLOT(setVisible(bool)));

        debugTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\211\345\233\275\346\235\200EX", 0, QApplication::UnicodeUTF8));
        bigPauseButton->setText(QApplication::translate("MainWindow", "<font color=white>\346\232\202\345\201\234/\347\273\247\347\273\255(F7)</font>", 0, QApplication::UnicodeUTF8));
        helpButton->setText(QApplication::translate("MainWindow", "<font color=white>\346\230\276\347\244\272\345\270\256\345\212\251(F1)</font>", 0, QApplication::UnicodeUTF8));
        aboutButton->setText(QApplication::translate("MainWindow", "<font color=white>\345\205\263\344\272\216\344\270\211\345\233\275\346\235\200EX</font>", 0, QApplication::UnicodeUTF8));
        playerSpinBox->setPrefix(QApplication::translate("MainWindow", "Player ", 0, QApplication::UnicodeUTF8));
        refreshPlayerButton->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        debugTabWidget->setTabText(debugTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Player", 0, QApplication::UnicodeUTF8));
        autorefreshCheckBox->setText(QApplication::translate("MainWindow", "auto", 0, QApplication::UnicodeUTF8));
        autorefreshSpinBox->setSuffix(QApplication::translate("MainWindow", " sec", 0, QApplication::UnicodeUTF8));
        refreshDataButton->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        debugTabWidget->setTabText(debugTabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Card", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Exchange Cards", 0, QApplication::UnicodeUTF8));
        card1->setPrefix(QApplication::translate("MainWindow", "No. ", 0, QApplication::UnicodeUTF8));
        dustbinCheckBox1->setText(QApplication::translate("MainWindow", "dustbin", 0, QApplication::UnicodeUTF8));
        card2->setPrefix(QApplication::translate("MainWindow", "No. ", 0, QApplication::UnicodeUTF8));
        dustbinCheckBox2->setText(QApplication::translate("MainWindow", "dustbin", 0, QApplication::UnicodeUTF8));
        exchangeButton->setText(QApplication::translate("MainWindow", "Exchange Cards", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "set HP", 0, QApplication::UnicodeUTF8));
        HPPlayerSpinBox->setPrefix(QApplication::translate("MainWindow", "Player ", 0, QApplication::UnicodeUTF8));
        HPSpinBox->setPrefix(QApplication::translate("MainWindow", "HP ", 0, QApplication::UnicodeUTF8));
        setHPButton->setText(QApplication::translate("MainWindow", "set HP", 0, QApplication::UnicodeUTF8));
        debugTabWidget->setTabText(debugTabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Cheat", 0, QApplication::UnicodeUTF8));
        historyComboBox->clear();
        historyComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "All Types", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "HITCARD (MCard)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "USECARD (MCard)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "USESKILL (MSkill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "HURT (MHurt)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "TRANSCARD (MTransCard)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SWITCHPHASE (MSwitchPhase)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "DYING (MDying)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "KILL (MKill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "JUDGE (MJudge)", 0, QApplication::UnicodeUTF8)
        );
        historySpinBox->setSuffix(QApplication::translate("MainWindow", " items", 0, QApplication::UnicodeUTF8));
        refreshHistoryButton->setText(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        debugTabWidget->setTabText(debugTabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "History", 0, QApplication::UnicodeUTF8));
        singleCheckBox->setText(QApplication::translate("MainWindow", "SingleStep", 0, QApplication::UnicodeUTF8));
        testCheckBox->setText(QApplication::translate("MainWindow", "Test", 0, QApplication::UnicodeUTF8));
        clearDebugButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<font color=red>improper use may cause crash</font>", 0, QApplication::UnicodeUTF8));
        debugButton1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        debugButton2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        debugButton3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        debugButton4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        debugTabWidget->setTabText(debugTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
