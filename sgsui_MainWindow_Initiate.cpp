/*
 * sgsui_MainWindow_init.cpp
 *
 *  Created on: Jun 20, 2012
 *      Author: latios
 */

#include "sgsui_MainWindow.h"
#include "sgsui_ZhuangbeiArea.h"
#include "sgsui_WujiangArea.h"
#include "sgsui_PlayerArea.h"
#include "sgsui_MessageBox.h"
#include "sgsui_DialogBox.h"
#include "sgsui_CardContainer.h"
#include "sgsui_WujiangChooseBox.h"
#include "sgsui_GuanxingBox.h"
#include "sgsui_WugufengdengBox.h"
#include "sgsui_FanjianBox.h"
#include "sgsui_GameOverBox.h"
#include "sgsui_AboutFrame.h"
#include "sgsui_HelpBox.h"
#include "sgsui_PixmapAnimationWidget.h"
#include "sgsui_LineAnimationWidget.h"
#include "sgsui_PosAnimation.h"
#include "sgsui_BlockTimer.h"
#include "sgsui_ZhuangbeiLabel.h"
#include "sgsui_CardViewer.h"
#include "sgsui_AudioPlayer.h"
#include "sgsui_Shoupai.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"

namespace sgsui {

MainWindow * MainWindow::mainWindowPointer = 0;
const QSize MainWindow::minSize(1024, 650);

MainWindow::MainWindow() :
		Interface(GUIStaticData::getHumanIndex() - 1), playerCount(
				GUIStaticData::getPlayerCount()), playerIndex(
				GUIStaticData::getHumanIndex()), GUIresponding(true), currentPlayerSeat(
				-1), responseType(NotResponding), skillVerShaOrNot(false), isGoingToAbandon(
				false), cancelResponse(false), shoupaiNumToDiscard(0), maxShoupaiSelect(
				0), minShoupaiSelect(0), maxPlayerSelect(0), minPlayerSelect(0), selectedZhuangbei(
				false), selectedSkill(sgs::ConstData::hkNone), liuliAttacker(0) {
	printDebug("MainWindow::MainWindow: start");

	// create splash
	QSplashScreen* splash = new QSplashScreen();
	splash->setPixmap(splashStr());
	splash->show();
	setWindowIcon(QIcon("images/icon.png"));
	splash->showMessage(GUIStaticData::startingGame,
			Qt::AlignRight | Qt::AlignTop, Qt::white);
	// create GUI objects
	setupUi(this);
	setMinimumSize(minSize);
	GUIStaticData::resetData();
	setOptions(GUIStaticData::getOptions());

	splash->showMessage(GUIStaticData::initWindowWidgets,
			Qt::AlignRight | Qt::AlignTop, Qt::white);
	initiateWindowWidgets();

	splash->showMessage(GUIStaticData::initStyleSheet,
			Qt::AlignRight | Qt::AlignTop, Qt::white);
	initiateStyleSheet();

	splash->showMessage(GUIStaticData::initAnimation,
			Qt::AlignRight | Qt::AlignTop, Qt::white);
	initiateAnimation();

	splash->showMessage(GUIStaticData::initMusic, Qt::AlignRight | Qt::AlignTop,
			Qt::white);
	initiateMusic();

	splash->showMessage(GUIStaticData::initDebug, Qt::AlignRight | Qt::AlignTop,
			Qt::white);
	initiateDebug();

	splash->showMessage(GUIStaticData::initOver, Qt::AlignRight | Qt::AlignTop,
			Qt::white);
	QApplication::processEvents();

	splash->finish(this);
	delete splash;
	mainWindowPointer = this;
}

void MainWindow::setOptions(int options) {

	//from lower to higher
	musicCheckBox->setChecked(options & 1);
	soundCheckBox->setChecked((options >> 1) & 1);
	fullscreenCheckBox->setChecked((options >> 2) & 1);
	AICheckBox->setChecked((options >> 3) & 1);
	changeScreenState(fullscreenCheckBox->isChecked());
	connect(AICheckBox, SIGNAL(clicked(bool)), this, SLOT(trustClicked(bool)));
}

MainWindow::~MainWindow() {
	mainWindowPointer = 0;

	// Shoupai are card buttons which have no parent
	// they need to be deleted here
	for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
			iter != shoupaiList.end(); ++iter) {
		delete *iter;
	}
}

void MainWindow::trustClicked(bool trust) {
	if (trust) {
		showTipMessage(GUIStaticData::trustTurnedOn);
	} else {
		showTipMessage(GUIStaticData::trustTurnedOff);
	}
}

void MainWindow::initiateWindowWidgets() {
	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	okButton->setDisabledPixmap(QPixmap("images/button/ok-disabled.png"));
	connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));

	cancelButton->setEnabledPixmap(QPixmap("images/button/cancel.png"));
	cancelButton->setDisabledPixmap(
			QPixmap("images/button/cancel-disabled.png"));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));

	abandonButton->setEnabledPixmap(QPixmap("images/button/discard.png"));
	abandonButton->setDisabledPixmap(
			QPixmap("images/button/discard-disabled.png"));
	connect(abandonButton, SIGNAL(clicked()), this, SLOT(abandonClicked()));

	quitButton->setEnabledPixmap(QPixmap("images/button/close.png"));
	quitButton->setDisabledPixmap(QPixmap("images/button/close.png"));
	quitButton->setPressedPixmap(QPixmap("images/button/close-pressed.png"));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

	aboutButton->setEnabledPixmap(QPixmap("images/button/enabled-big.png"));
	aboutButton->setDisabledPixmap(QPixmap("images/button/disabled-big.png"));
	aboutButton->setPressedPixmap(QPixmap("images/button/pressed-big.png"));

	bigPauseButton->setEnabledPixmap(
			QPixmap("images/button/enabled-large.png"));
	bigPauseButton->setDisabledPixmap(
			QPixmap("images/button/disabled-large.png"));
	bigPauseButton->setPressedPixmap(
			QPixmap("images/button/pressed-large.png"));
	connect(bigPauseButton, SIGNAL(clicked()), pauseButton, SLOT(click()));

	helpButton->setEnabledPixmap(QPixmap("images/button/enabled-large.png"));
	helpButton->setDisabledPixmap(QPixmap("images/button/disabled-large.png"));
	helpButton->setPressedPixmap(QPixmap("images/button/pressed-large.png"));

	tipBox = new MessageBox(this);
	tipBox->hide();
	pauseBox = new MessageBox(this);
	pauseBox->hide();
	cardContainer = new CardContainer(this);
	cardContainer->hide();
	wujiangChooseBox = new WujiangChooseBox(this);
	wujiangChooseBox->hide();
	guanxingBox = new GuanxingBox(this);
	guanxingBox->hide();

	zhuangbeiLabel = new ZhuangbeiLabel(this);
	zhuangbeiLabel->hide();

	aboutFrame = new AboutFrame(this);
	aboutFrame->hide();
	connect(aboutButton, SIGNAL(clicked()), aboutFrame, SLOT(showAboutInfo()));

	helpBox = new HelpBox(this);
	helpBox->hide();
	connect(helpButton, SIGNAL(clicked()), helpBox, SLOT(displayHelp()));

	wugufengdengBox = new WugufengdengBox(this);
	wugufengdengBox->hide();

	fanjianBox = new FanjianBox(this);
	fanjianBox->hide();

	cardViewer = new CardViewer(this);
	cardViewer->hide();

	gameOverBox = new GameOverBox(this);
	gameOverBox->hide();

	cardDeckLabel->hide();

	blockingFrameMovingAnimation = new QPropertyAnimation(this);
	blockingFrameMovingAnimation->setPropertyName("pos");
	blockingFrameMovingAnimation->setDuration(
			GUIStaticData::blockingFrameMovingDuration);

	debugCheckBox->hide();
	debugTabWidget->hide();
	testWidget->hide();
	connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseClicked()));

	checkButtons();
}

void MainWindow::createPlayers() {
	printDebug("MainWindow::createPlayers: start");

	// initiate battlefield infomation
	playerCount = GUIStaticData::getPlayerCount();
	playerIndex = GUIStaticData::getHumanIndex();

	// initiate myself
	zhuangbeiA = new ZhuangbeiArea(this, zhuangbeiArea);
	wujiangA = new WujiangArea(playerIndex, wujiangArea);
	innerAI = Interface::createInterface(playerIndex - 1,
			wujiangA->getHeroType(), true);

	// initiate others
	switch (playerCount - 1) {
	case 1:
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 0) % playerCount + 1,
						playerFrame4));
		break;
	case 2:
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 0) % playerCount + 1,
						playerFrame3));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 1) % playerCount + 1,
						playerFrame4));
		centralPlayerLayout->removeItem(player5spacer);
		playerFrame5->hide();
		break;
	case 3:
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 0) % playerCount + 1,
						playerFrame3));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 1) % playerCount + 1,
						playerFrame4));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 2) % playerCount + 1,
						playerFrame5));
		break;
	case 4:
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 0) % playerCount + 1,
						playerFrame2));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 1) % playerCount + 1,
						playerFrame3));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 2) % playerCount + 1,
						playerFrame4));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 3) % playerCount + 1,
						playerFrame6));
		centralPlayerLayout->removeItem(player5spacer);
		playerFrame5->hide();
		break;
	case 5:
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 0) % playerCount + 1,
						playerFrame2));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 1) % playerCount + 1,
						playerFrame3));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 2) % playerCount + 1,
						playerFrame4));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 3) % playerCount + 1,
						playerFrame5));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 4) % playerCount + 1,
						playerFrame6));
		break;
	case 6:
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 0) % playerCount + 1,
						playerFrame1));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 1) % playerCount + 1,
						playerFrame2));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 2) % playerCount + 1,
						playerFrame3));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 3) % playerCount + 1,
						playerFrame4));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 4) % playerCount + 1,
						playerFrame6));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 5) % playerCount + 1,
						playerFrame7));
		centralPlayerLayout->removeItem(player5spacer);
		playerFrame5->hide();
		break;
	case 7:
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 0) % playerCount + 1,
						playerFrame1));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 1) % playerCount + 1,
						playerFrame2));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 2) % playerCount + 1,
						playerFrame3));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 3) % playerCount + 1,
						playerFrame4));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 4) % playerCount + 1,
						playerFrame5));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 5) % playerCount + 1,
						playerFrame6));
		otherPlayerAreaVector.push_back(
				new PlayerArea((playerIndex + 6) % playerCount + 1,
						playerFrame7));
		break;
	}

	// display role label
	int zhugongNum = 0, zhongchenNum = 0, fanzeiNum = 0, neijianNum = 0;
	for (int i = 1; i <= playerCount; ++i) {
		switch (GUIStaticData::getPlayerRole(i)) {
		case sgs::ConstData::ZHU:
			++zhugongNum;
			break;
		case sgs::ConstData::ZHONG:
			++zhongchenNum;
			break;
		case sgs::ConstData::FAN:
			++fanzeiNum;
			break;
		case sgs::ConstData::NEI:
			++neijianNum;
			break;
		default:
			break;
		}
	}

	connect(wujiangA, SIGNAL(skillClicked(sgs::ConstData::HeroSkill, int)),
			this, SLOT(skillClicked(sgs::ConstData::HeroSkill, int)));
	QApplication::processEvents();
	sleepSomeTime(GUIStaticData::createPlayerDuration);
	for (std::vector<PlayerArea *>::iterator iter =
			otherPlayerAreaVector.begin(); iter != otherPlayerAreaVector.end();
			++iter) {
		(*iter)->show();
	}
	zhuangbeiA->show();
	wujiangA->show();
	roleFrame->setupRole(zhugongNum, zhongchenNum, fanzeiNum, neijianNum);
	cardDeckLabel->show();
	GUIStaticData::setPlayersCreated();

	printDebug("MainWindow::createPlayers: over");
}

void MainWindow::initiateStyleSheet() {
	mainFrame->setStyleSheet(
			"QWidget#mainFrame{border-image:url(images/backdrop/1.jpg)}");
	rightFrame->setStyleSheet(
			"QWidget#rightFrame{border-image:url(images/frame/rightFrame.png)}");
	zhuangbeiArea->setStyleSheet(
			"QWidget#zhuangbeiArea{background-image:url(images/frame/zhuangbeiArea.png)}");
	shoupaiArea->setStyleSheet(
			"QFrame#shoupaiArea{background-image:url(images/frame/shoupaiArea.png)}");
	wujiangArea->setStyleSheet(
			"QWidget#wujiangArea{background-image:url(images/frame/wujiangArea.png)}");
	statusbar->setStyleSheet(
			"QLabel#statusbar{background-image:url(images/frame/statusbar.png)}");
	messageTopFrame->setStyleSheet(
			"QFrame#messageTopFrame{background-image:url(images/frame/messagetop.png)}");
	messageMiddleFrame->setStyleSheet(
			"QFrame#messageMiddleFrame{background-image:url(images/frame/messagemiddle.png)}");
	messageButtomFrame->setStyleSheet(
			"QFrame#messageButtomFrame{background-image:url(images/frame/messagebuttom.png)}");
	cardDeckLabel->setStyleSheet(
			"QLabel#cardDeckLabel{background-image:url(images/system/cardDeck.png)}");
	historyText->setStyleSheet(
			"QTextBrowser#historyText{background-image:url(images/frame/textbackground.png);}"
					"QScrollBar:vertical {margin: 13px 0px 13px 0px; border: 0px; width: 12px;}"
					".QScrollBar::handle:vertical {border-image:url(images/frame/scroll-area.png);}"
					".QScrollBar::add-page:vertical {background-color: rgb(85, 67, 53)}"
					".QScrollBar::sub-page:vertical {background-color: rgb(85, 67, 53)}"
					".QScrollBar::sub-line:vertical {subcontrol-origin: margin; border: 0px; height:12px}"
					".QScrollBar::up-arrow:vertical {border-image:url(images/frame/scroll-up-arrow.png); height:12px}"
					".QScrollBar::down-arrow:vertical {border-image:url(images/frame/scroll-down-arrow.png); height:12px}"
					".QScrollBar::add-line:vertical {subcontrol-origin: margin; border: 0px; height:12px}");
	optionFrame->setStyleSheet(
			"QFrame#optionFrame{background-image:url(images/frame/optionFrame.png)}");
}

void MainWindow::initiateAnimation() {
	cardAnimation = new PosAnimation(usedCardFrame, usedCardLayout, this);
	damageMovingAnimation = new QPropertyAnimation(this);
	damageMovingAnimation->setPropertyName("pos");
	damageMovingAnimation->setDuration(GUIStaticData::damageAnimationDuration);
	lineAnimationWidget = new LineAnimationWidget(this);
	lineAnimationWidget->hide();
	pixmapAnimationWidget = new PixmapAnimationWidget(this);
	pixmapAnimationWidget->hide();
	blockTimer = new BlockTimer(this);
}

void MainWindow::initiateMusic() {
	printDebug("MainWindow::initiateMusic: start");
	audioPlayer = new AudioPlayer(this);
	printDebug("MainWindow::initiateMusic: audioPlayer created");
	skillPlayer = new AudioPlayer(this);
	printDebug("MainWindow::initiateMusic: skillplayer created");
	connect(musicCheckBox, SIGNAL(
			clicked(bool)), this, SLOT(changeMusicState(bool)));
	connect(fullscreenCheckBox, SIGNAL(clicked(bool)), this, SLOT(
			changeScreenState(bool)));
	if (musicCheckBox->isChecked()) {
		printDebug("MainWindow::initiateMusic: starting background music");
		audioPlayer->startBGM();
		printDebug("MainWindow::initiateMusic: background music started");
	}
	printDebug("MainWindow::initiateMusic: over");
}

} /* namespace sgsui */
