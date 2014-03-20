/*
 * sgsui_MainWindow.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#include "sgsui_MainWindow.h"
#include "sgsui_ZhuangbeiArea.h"
#include "sgsui_WujiangArea.h"
#include "sgsui_PlayerArea.h"
#include "sgsui_Shoupai.h"
#include "sgsui_MessageBox.h"
#include "sgsui_DialogBox.h"
#include "sgsui_CardContainer.h"
#include "sgsui_WujiangChooseBox.h"
#include "sgsui_GuanxingBox.h"
#include "sgsui_FanjianBox.h"
#include "sgsui_GameOverBox.h"
#include "sgsui_PixmapAnimationWidget.h"
#include "sgsui_LineAnimationWidget.h"
#include "sgsui_ZhuangbeiLabel.h"
#include "sgsui_WugufengdengBox.h"
#include "sgsui_BlockTimer.h"
#include "sgsui_ZhuangbeiPic.h"
#include "sgsui_AudioPlayer.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include "sgsdata_enum.h"
#include <QtGui>

namespace sgsui {

MainWindow * MainWindow::mainWindowPtr() {
	return mainWindowPointer;
}

void MainWindow::appendHistory(const QString &textInput) {
	if (!mainWindowPointer)
		return;
	mainWindowPointer->historyText->append(setColored(textInput, false));
}

void MainWindow::appendDebug(const QString &textInput) {
	if (!mainWindowPointer)
		return;
	mainWindowPointer->debugText->append(textInput);
}

void MainWindow::exec() {
	if (!blockLoop.isRunning()) {
		emit blocked();
		printDebug(
				"<font color=red><b>Notice: </b></font>MainWindow::exec: MainWindow is blocked");
		blockLoop.exec();
		emit
		unblocked();
		printDebug(
				"<font color=red><b>Notice: </b></font>MainWindow::exec: MainWindow is unblocked");
	} else
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::exec: MainWindow is already blocking!");
}

void MainWindow::sleepSomeTime(int sleepTime) {
	if (blockTimer)
		blockTimer->block(sleepTime);
}

void MainWindow::unblock() {
	if (blockLoop.isRunning()) {
		blockLoop.quit();
	}
}

bool MainWindow::isSingleStep() const {
	return singleCheckBox->isChecked();
}

void MainWindow::pause() {
	pauseButton->click();
}

void MainWindow::pauseClicked() {
	if (responseType != NotResponding || !blockingFrameList.empty()) {
		pauseButton->setChecked(!pauseButton->isChecked());
		return;
	}

	if (pauseButton->isChecked()) {
		showPauseMessage(
				singleCheckBox->isChecked() ?
						GUIStaticData::singleStep : GUIStaticData::gamePaused);
		exec();
		pauseBox->hide();
		statusbar->clearMessage();
	} else {
		unblock();
	}
}

bool MainWindow::isBlocked() const {
	return blockLoop.isRunning();
}

bool MainWindow::isResponding() const {
	if (!GUIresponding
			&& blockingFrameMovingAnimation->state()
					!= QAbstractAnimation::Running) {
		if (!blockingFrameList.empty()) {
			QPoint position = blockingFrameList.back()->pos();
			QPoint translate(10, 0);
			blockingFrameMovingAnimation->setTargetObject(
					blockingFrameList.back());
			blockingFrameMovingAnimation->setStartValue(position);
			blockingFrameMovingAnimation->setKeyValueAt(0.25,
					position + translate);
			blockingFrameMovingAnimation->setKeyValueAt(0.75,
					position - translate);
			blockingFrameMovingAnimation->setEndValue(position);
			blockingFrameMovingAnimation->start();
		} else
			printDebug(
					"<font color=red><b>Warning: </b></font>MainWindow::isResponding(): MainWindow has been set NOT responding while no widget is blocking it");
	}
	return GUIresponding && responseType != NotResponding;
}

bool MainWindow::isRespondingNoAnimation() const {
	return (responseType != NotResponding) && GUIresponding;
}

void MainWindow::setResponding(bool responding, BlockingFrame *blockWidget) {
	if (responding) {
		blockingFrameList.remove(blockWidget);
		GUIresponding = blockingFrameList.empty();
	} else {
		blockingFrameList.push_back(blockWidget);
		GUIresponding = false;
	}
}

bool MainWindow::isSoundOn() const {
	return soundCheckBox->isChecked();
}

void MainWindow::addUsedCard(CardFrame * usedCard) {
	if (usedCardLayout->count() > GUIStaticData::maxUsedCardContain)
		delete usedCardLayout->takeAt(1)->widget();
	usedCardLayout->addWidget(usedCard);
}

void MainWindow::addShoupai(const sgs::DataType::Card * card) {
	Shoupai* addedShoupai = new Shoupai(card, this);
	shoupaiLayout->addWidget(addedShoupai);
	shoupaiList.push_back(addedShoupai);
	printDebug(
			"MainWindow::addShoupai: adding card "
					+ cardFullDisplayName(card, false));
}

void MainWindow::removeShoupai(Shoupai * shoupaiToRemove) {
	shoupaiLayout->removeWidget(shoupaiToRemove);
	shoupaiList.remove(shoupaiToRemove);
	delete shoupaiToRemove;
}

void MainWindow::endResponse() {

	// this function should only be called at the end of a response
	// it set every Shoupai and PlayerArea and ZhuangbeiPic selectable

	responseType = NotResponding;

	terminateCardSelect();
	terminatePlayerSelect();
	terminateZhuangbeiSelect();
	terminateSkillSelect();
	checkButtons();

	// clear data
	isGoingToAbandon = false;
	selectedZhuangbei = 0;
	selectedSkill = sgs::ConstData::hkNone;
	cancelResponse = false;
	selectedShoupaiList.clear();
	selectedPlayerAreaList.clear();
	maxShoupaiSelect = 0;
	minShoupaiSelect = 0;
	maxPlayerSelect = 0;
	minPlayerSelect = 0;
	skillVerShaOrNot = false;
	tuxiList.clear();
	selectedSkillCardVec.clear();
	liuliAttacker = 0;
	printDebug("MainWindow::endResponse: response is over");
}

void MainWindow::terminatePlayerSelect() {
	for (std::vector<PlayerArea*>::iterator iter =
			otherPlayerAreaVector.begin(); iter != otherPlayerAreaVector.end();
			++iter) {
		(*iter)->setSelectable();
		(*iter)->setUnselected();
	}
	wujiangA->setSelectable();
	wujiangA->setUnselected();
}

void MainWindow::terminateCardSelect() {
	for (std::list<Shoupai*>::iterator iter = shoupaiList.begin();
			iter != shoupaiList.end(); ++iter) {
		(*iter)->setUnselected();
		(*iter)->setSelectable();
	}
}

void MainWindow::terminateZhuangbeiSelect() {
	zhuangbeiA->setSelectable(0, true, true);
	zhuangbeiA->setSelectable(1, true, true);
	zhuangbeiA->setSelectable(2, true, true);
	zhuangbeiA->setSelectable(3, true, true);
}

void MainWindow::terminateSkillSelect() {
	wujiangA->disableAllSkillButtons();
}

void MainWindow::changeMusicState(bool musicOn) {
	if (musicOn)
		audioPlayer->startBGM();
	else
		audioPlayer->pauseBGM();
}

void MainWindow::changeScreenState(bool fullscreen) {
	if (fullscreen)
		setWindowState(Qt::WindowFullScreen);
	else
		setWindowState(Qt::WindowMaximized);
}

QPoint MainWindow::cardDeckPoint() const {
	return realPos(cardDeckLabel);
}

QPoint MainWindow::lastShoupaiPoint() const {
	int cardFrameWidth = 93, verticalMargin = 37;
	int maxHorizontalPos = shoupaiArea->width() - cardFrameWidth;
	int existingDeckWidth =
			static_cast<int>(cardFrameWidth * shoupaiList.size());
	return realPos(shoupaiArea)
			+ QPoint(
					existingDeckWidth > maxHorizontalPos ?
							maxHorizontalPos : existingDeckWidth,
					verticalMargin);
}

QPoint MainWindow::shoupaiEndPoint() const {
	int verticalMargin = 37;
	return realPos(shoupaiArea) + QPoint(shoupaiArea->width(), verticalMargin);
}

QPoint MainWindow::usedCardPoint() const {
	return realPos(usedCardFrame);
}

QPoint MainWindow::zhuangbeiPoint() const {
	QPoint zhuangbeiMargin(20, 20);
	return realPos(zhuangbeiArea) + zhuangbeiMargin;
}

QPoint MainWindow::shoupaiCenterPoint() const {
	return realPos(shoupaiArea) + QPoint(shoupaiArea->size().width() / 2, 20);
}

QPoint MainWindow::wujiangCenterPoint() const {
	return realPos(wujiangArea)
			+ QPoint(wujiangArea->size().width() / 2,
					wujiangArea->size().height() / 2);
}

QPoint MainWindow::realPos(QWidget* widgetToCal) {
	QPoint topLeftCoordinate = widgetToCal->pos();
	for (QWidget *thisWidget = widgetToCal->parentWidget();
			thisWidget != widgetToCal->window();
			thisWidget = thisWidget->parentWidget())
		topLeftCoordinate += thisWidget->pos();
	return topLeftCoordinate;
}

void MainWindow::showWugu(
		const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wuguCards) {
	wugufengdengBox->showContainer(wuguCards);
}

void MainWindow::closeEvent(QCloseEvent *event) {
	raise();
	if (getDialogResponse(GUIStaticData::quitOrNot) == 0) {
		event->ignore();
	} else {
		QApplication::processEvents();
		GUIStaticData::quitGame();
	}
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

	// PlayerArea
	if (event->modifiers() == Qt::AltModifier) {
		if (event->key() == Qt::Key_0) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(0);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
		if (event->key() == Qt::Key_1) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(1);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
		if (event->key() == Qt::Key_2) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(2);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
		if (event->key() == Qt::Key_3) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(3);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
		if (event->key() == Qt::Key_4) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(4);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
		if (event->key() == Qt::Key_5) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(5);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
		if (event->key() == Qt::Key_6) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(6);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
		if (event->key() == Qt::Key_7) {
			AbstractPlayerArea* clickedPlayer = goToAbstractPlayerArea(7);
			if (clickedPlayer)
				clickedPlayer->click();
			return;
		}
	}

	// zhuangbei
	if (event->modifiers() == Qt::ControlModifier) {
		ZhuangbeiPic* clickedZhuangbei;
		if (event->key() == Qt::Key_1) {
			clickedZhuangbei = zhuangbeiA->getWuqiPic();
			if (clickedZhuangbei)
				clickedZhuangbei->click();
			return;
		}
		if (event->key() == Qt::Key_2) {
			clickedZhuangbei = zhuangbeiA->getFangjuPic();
			if (clickedZhuangbei)
				clickedZhuangbei->click();
			return;
		}
		if (event->key() == Qt::Key_3) {
			clickedZhuangbei = zhuangbeiA->getJianmaPic();
			if (clickedZhuangbei)
				clickedZhuangbei->click();
			return;
		}
		if (event->key() == Qt::Key_4) {
			clickedZhuangbei = zhuangbeiA->getJiamaPic();
			if (clickedZhuangbei)
				clickedZhuangbei->click();
			return;
		}
	}

	if ((event->key() == Qt::Key_F7 && event->modifiers() == Qt::NoModifier)
			|| (event->key() == Qt::Key_P
					&& event->modifiers() == Qt::ControlModifier)) {
		pauseButton->click();
		return;
	}
	if (event->key() == Qt::Key_F12 && event->modifiers() == Qt::NoModifier) {
		singleCheckBox->click();
		return;
	}
	if ((event->key() == Qt::Key_F1 && event->modifiers() == Qt::NoModifier)
			|| (event->key() == Qt::Key_H
					&& event->modifiers() == Qt::ControlModifier)) {
		helpButton->click();
		return;
	}
	if (event->key() == Qt::Key_M
			&& event->modifiers() == Qt::ControlModifier) {
		musicCheckBox->click();
		return;
	}
	if (event->key() == Qt::Key_S
			&& event->modifiers() == Qt::ControlModifier) {
		soundCheckBox->click();
		return;
	}
	if (event->key() == Qt::Key_F
			&& event->modifiers() == Qt::ControlModifier) {
		fullscreenCheckBox->click();
		return;
	}
	if (event->key() == Qt::Key_T
			&& event->modifiers() == Qt::ControlModifier) {
		AICheckBox->click();
		return;
	}
	if ((event->key() == Qt::Key_F11 && event->modifiers() == Qt::NoModifier)
			|| (event->key() == Qt::Key_D
					&& event->modifiers() == Qt::ControlModifier)) {
		debugCheckBox->click();
		if (debugCheckBox->isChecked())
			showTipMessage(GUIStaticData::debugTurnedOn);
		else
			showTipMessage(GUIStaticData::debugTurnedOff);
		return;
	}
	if (event->key() == Qt::Key_Q
			&& event->modifiers() == Qt::ControlModifier) {
		close();
		return;
	}
	if ((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
			&& event->modifiers() == Qt::NoModifier) {
		if (!blockingFrameList.empty())
			blockingFrameList.back()->enterKeyPressedEvent();
		else
			okButton->click();
		return;
	}
	if (event->key() == Qt::Key_Escape
			&& event->modifiers() == Qt::NoModifier) {
		if (!blockingFrameList.empty())
			blockingFrameList.back()->escapeKeyPressedEvent();
		else
			cancelButton->click();
		return;
	}
	if (event->key() == Qt::Key_Delete
			&& event->modifiers() == Qt::NoModifier) {
		abandonButton->click();
		return;
	}

	// shoupai select
	if (event->key() == Qt::Key_1 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(0);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_2 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(1);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_3 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(2);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_4 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(3);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_5 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(4);
		if (shoupai)
			shoupai->click();
	}
	if (event->key() == Qt::Key_6 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(5);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_7 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(6);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_8 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(7);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_9 && event->modifiers() == Qt::NoModifier) {
		CardButton* shoupai = goToShoupai(8);
		if (shoupai)
			shoupai->click();
		return;
	}
	if (event->key() == Qt::Key_0 && event->modifiers() == Qt::NoModifier) {
		if (responseType == NotResponding)
			return;

		if (responseType == DiscardCard) {
			std::vector<Shoupai *> selected_copy(selectedAbandonList.begin(),
					selectedAbandonList.end());
			for (std::vector<Shoupai *>::iterator iter = selected_copy.begin();
					iter != selected_copy.end(); ++iter) {
				(*iter)->click();
			}
		} else {
			std::vector<Shoupai *> selected_copy(selectedShoupaiList.begin(),
					selectedShoupaiList.end());
			for (std::vector<Shoupai *>::iterator iter = selected_copy.begin();
					iter != selected_copy.end(); ++iter) {
				(*iter)->click();
			}
		}
		return;
	}
	QMainWindow::keyPressEvent(event);
}

CardButton* MainWindow::goToShoupai(unsigned shoupaiIndex) {

	// shoupaiIndex starts from 0
	if (shoupaiList.size() > shoupaiIndex) {
		std::list<Shoupai *>::iterator iter = shoupaiList.begin();
		for (unsigned i = 0; i < shoupaiIndex; ++i) {
			++iter;
		}
		return *iter;
	} else
		return 0;
}

AbstractPlayerArea* MainWindow::goToAbstractPlayerArea(int pressedKey) {
	if (pressedKey <= 0) {
		return wujiangA;
	} else if (pressedKey < GUIStaticData::getPlayerCount()) {
		return otherPlayerAreaAtIndex(pressedKey + 1);
	}
	return 0;
}

void MainWindow::runPixmapAnimation(int targetPlayerIndex,
		PixmapAnimationType animationType) {
	if (targetPlayerIndex < 1 || targetPlayerIndex > playerCount) {
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::runPixmapAnimation: invalid target index");
		return;
	} else {
		printDebug(
				"MainWindow::runPixmapAnimation: start, target index (seat + 1) = "
						+ QString::number(targetPlayerIndex));
	}

	QPoint targetPoint = animationPointAtIndex(targetPlayerIndex);
	pixmapAnimationWidget->pixmapAnimation(targetPoint, animationType);

	if (animationType == DamageAnimation
			|| animationType == LightningAnimation) {
		if (targetPlayerIndex != playerIndex) {
			QWidget* target =
					otherPlayerAreaAtIndex(targetPlayerIndex)->parentWidget();
			damageMovingAnimation->setTargetObject(target);
			QPoint originPos = target->pos();
			damageMovingAnimation->setStartValue(originPos);
			damageMovingAnimation->setKeyValueAt(0.5,
					originPos + QPoint(20, 0));
			damageMovingAnimation->setEndValue(originPos);
			damageMovingAnimation->start();
		}

		if (animationType == DamageAnimation)
			audioPlayer->playSound(DamageEffectSound,
					getSexAtIndex(targetPlayerIndex) == sgs::ConstData::MALE);
		else
			audioPlayer->playSound(LightningEffectSound);
	}
}

void MainWindow::showTipMessage(const QString &tip, bool richText,
		int duration) {
	duration = duration > 0 ? duration : GUIStaticData::showTipDuration;
	tipBox->setGeometry(
			QRect(
					mainFrame->geometry().center()
							- QPoint(tipBox->width() / 2, tipBox->height() / 2),
					tipBox->size()));
	tipBox->showTipMessage(tip, richText, duration);
	statusbar->showStatusBarMessage(tip, richText, duration);
}

void MainWindow::showPauseMessage(const QString & pause, bool richText) {
	pauseBox->setGeometry(
			QRect(
					mainFrame->geometry().center()
							- QPoint(pauseBox->width() / 2,
									pauseBox->height() / 2), pauseBox->size()));
	pauseBox->showPauseMessage(pause);

	// -1 means that this statusbar message does not disappear automatically
	statusbar->showStatusBarMessage(pause, richText, -1);
}

void MainWindow::showStatusBarMessage(const QString &tip, bool richText,
		int duration) {
	statusbar->showStatusBarMessage(tip, richText, duration);
}

int MainWindow::getDialogResponse(const QString &message) {
	dialogBox = new DialogBox(this);
	dialogBox->setGeometry(
			QRect(
					mainFrame->geometry().center()
							- QPoint(dialogBox->width() / 2,
									dialogBox->height() / 2),
					dialogBox->size()));
	int returnValue = dialogBox->exec(message);
	delete dialogBox;
	dialogBox = 0;
	return returnValue;
}

sgs::ConstData::HeroType MainWindow::chooseWujiang(
		sgs::ConstData::HeroType zhugong, sgs::ConstData::PlayerRole shenfen,
		sgs::ConstData::HeroType avaliable1,
		sgs::ConstData::HeroType avaliable2,
		sgs::ConstData::HeroType avaliable3) {
	sgs::ConstData::HeroType result = wujiangChooseBox->chooseWujiang(zhugong,
			shenfen, avaliable1, avaliable2, avaliable3);
	audioPlayer->playSound(PlayersCreated);
	return result;
}

sgs::ConstData::HeroType MainWindow::chooseZhugongWujiang(
		sgs::ConstData::HeroType avaliable1,
		sgs::ConstData::HeroType avaliable2,
		sgs::ConstData::HeroType avaliable3,
		sgs::ConstData::HeroType avaliable4,
		sgs::ConstData::HeroType avaliable5) {

	sgs::ConstData::HeroType result = wujiangChooseBox->chooseZhugongWujiang(
			avaliable1, avaliable2, avaliable3, avaliable4, avaliable5);
	audioPlayer->playSound(PlayersCreated);
	return result;
}

void MainWindow::runGuanxing() {
	// TODO complete it;
}

void MainWindow::runWugufengdeng() {
	// TODO complete it;
}

sgs::ConstData::CardColor MainWindow::runFanjian() {
	fanjianBox->setGeometry(
			QRect(
					mainFrame->geometry().center()
							- QPoint(fanjianBox->width() / 2,
									fanjianBox->height() / 2),
					fanjianBox->size()));

	return fanjianBox->getFanjianColor();
}

void MainWindow::runLineAnimation(int sourcePlayerIndex, int targetPlayerIndex1,
		int targetPlayerIndex2, int targetPlayerIndex3, int targetPlayerIndex4,
		int targetPlayerIndex5, int targetPlayerIndex6,
		int targetPlayerIndex7) {

	int targetCandidates[7] = { targetPlayerIndex1, targetPlayerIndex2,
			targetPlayerIndex3, targetPlayerIndex4, targetPlayerIndex5,
			targetPlayerIndex6, targetPlayerIndex7 };
	int verticalDifference = 50;
	lineAnimationWidget->setGeometry(
			mainFrame->geometry().adjusted(0, 0, 0, verticalDifference));

	QPoint startPoint = animationPointAtIndex(sourcePlayerIndex);

	std::vector<QPoint> targetPointVec;
	for (int i = 0; i < 7; ++i) {
		if (targetCandidates[i])
			targetPointVec.push_back(
					animationPointAtIndex(targetCandidates[i]));
	}
	lineAnimationWidget->lineAnimation(startPoint, targetPointVec);
}

PlayerArea* MainWindow::otherPlayerAreaAtIndex(int index) const {
	if (index == playerIndex || index < 0 || index > playerCount) {
		printDebug(
				"MainWindow::otherPlayerAreaAtIndex: index == playerIndex or index invalid");
		return 0;
	}
	int initiatePosition =
			(index > playerIndex) ?
					(index - playerIndex) : (playerCount + index - playerIndex);
	return *(otherPlayerAreaVector.begin() + (initiatePosition - 1));
}

QPoint MainWindow::cardPointAtIndex(int index) const {
	if (index == playerIndex) {
		return lastShoupaiPoint();
	} else {
		QPoint cardPointMargin(10, 0);
		return otherPlayerAreaAtIndex(index)->topLeftPoint() + cardPointMargin;
	}
}

QPoint MainWindow::animationPointAtIndex(int index) const {
	if (index == playerIndex)
		return shoupaiCenterPoint();
	else
		return otherPlayerAreaAtIndex(index)->realGeometry().center();
}

QPoint MainWindow::judgePointAtIndex(int index) const {
	if (index == playerIndex) {
		QPoint judgeMargin(10, -20);
		return realPos(zhuangbeiArea) + judgeMargin;
	} else {
		QPoint judgeMargin(60, -5);
		return otherPlayerAreaAtIndex(index)->topLeftPoint() + judgeMargin;
	}
}

QPoint MainWindow::zhuangbeiPointAtIndex(int index) const {
	if (index == playerIndex)
		return zhuangbeiPoint();
	else
		return otherPlayerAreaAtIndex(index)->realGeometry().center();
}

sgs::ConstData::HeroSex MainWindow::getSexAtIndex(int index) const {
	if (index == playerIndex)
		return wujiangA->getSex();
	else
		return otherPlayerAreaAtIndex(index)->getSex();
}

sgs::ConstData::HeroType MainWindow::getHeroTypeAtIndex(int index) const {
	if (index == playerIndex)
		return wujiangA->getHeroType();
	else
		return otherPlayerAreaAtIndex(index)->getHeroType();
}

sgs::ConstData::PlayerRole MainWindow::getRoleAtIndex(int index) const {
	if (index == playerIndex)
		return wujiangA->getRole();
	else
		return otherPlayerAreaAtIndex(index)->getRole();
}

bool MainWindow::getIsDeadAtIndex(int index) const {
	if (index == playerIndex)
		return wujiangA->isDead();
	else
		return otherPlayerAreaAtIndex(index)->isDead();
}

const CardFrame * MainWindow::getWuqiAtIndex(int index) const {
	if (index == playerIndex)
		return zhuangbeiA->getWuqi();
	else
		return otherPlayerAreaAtIndex(index)->getWuqi();
}

const CardFrame * MainWindow::getFangjuAtIndex(int index) const {
	if (index == playerIndex)
		return zhuangbeiA->getFangju();
	else
		return otherPlayerAreaAtIndex(index)->getFangju();
}

const CardFrame * MainWindow::getJianmaAtIndex(int index) const {
	if (index == playerIndex)
		return zhuangbeiA->getJianma();
	else
		return otherPlayerAreaAtIndex(index)->getJianma();
}

const CardFrame * MainWindow::getJiamaAtIndex(int index) const {
	if (index == playerIndex)
		return zhuangbeiA->getJiama();
	else
		return otherPlayerAreaAtIndex(index)->getJiama();
}

void MainWindow::addWuqiAtIndex(int index, CardFrame * newWuqiCard) {
	if (index == playerIndex)
		zhuangbeiA->addWuqi(newWuqiCard);
	else
		otherPlayerAreaAtIndex(index)->addWuqi(newWuqiCard);
}

void MainWindow::addFangjuAtIndex(int index, CardFrame * newFangjuCard) {
	if (index == playerIndex)
		zhuangbeiA->addFangju(newFangjuCard);
	else
		otherPlayerAreaAtIndex(index)->addFangju(newFangjuCard);
}

void MainWindow::addJianmaAtIndex(int index, CardFrame * newJianmaCard) {
	if (index == playerIndex)
		zhuangbeiA->addJianma(newJianmaCard);
	else
		otherPlayerAreaAtIndex(index)->addJianma(newJianmaCard);
}

void MainWindow::addJiamaAtIndex(int index, CardFrame * newJiamaCard) {
	if (index == playerIndex)
		zhuangbeiA->addJiama(newJiamaCard);
	else
		otherPlayerAreaAtIndex(index)->addJiama(newJiamaCard);
}

void MainWindow::removeWuqiAtIndex(int index) {
	if (index == playerIndex)
		zhuangbeiA->removeWuqi();
	else
		otherPlayerAreaAtIndex(index)->removeWuqi();
}

void MainWindow::removeFangjuAtIndex(int index) {
	if (index == playerIndex)
		zhuangbeiA->removeFangju();
	else
		otherPlayerAreaAtIndex(index)->removeFangju();
}

void MainWindow::removeJianmaAtIndex(int index) {
	if (index == playerIndex)
		zhuangbeiA->removeJianma();
	else
		otherPlayerAreaAtIndex(index)->removeJianma();
}

void MainWindow::removeJiamaAtIndex(int index) {
	if (index == playerIndex)
		zhuangbeiA->removeJiama();
	else
		otherPlayerAreaAtIndex(index)->removeJiama();
}

void MainWindow::addJudgeAtIndex(int index,
		sgs::ConstData::CardType judgeCard) {
	if (index == playerIndex)
		zhuangbeiA->addJudge(judgeCard);
	else
		otherPlayerAreaAtIndex(index)->addJudge(judgeCard);
}

void MainWindow::removeJudgeAtIndex(int index, sgs::ConstData::CardType judgeCard) {
	if (index == playerIndex)
		zhuangbeiA->removeJudge(judgeCard);
	else
		otherPlayerAreaAtIndex(index)->removeJudge(judgeCard);
}

void MainWindow::showSkillAtIndex(int index, sgs::ConstData::HeroSkill skill) {
	if (index == playerIndex)
		wujiangA->showSkill(skill);
	else
		otherPlayerAreaAtIndex(index)->showSkill(skill);
}

void MainWindow::showZhuangbeiAtIndex(int index,
		sgs::ConstData::CardType equipCard) {
	if (index == playerIndex) {
		QPoint zhuangbeiLabelMargin(10, -60);
		zhuangbeiLabel->move(zhuangbeiPoint() + zhuangbeiLabelMargin);
		zhuangbeiLabel->showZhuangbei(equipCard);
	} else
		otherPlayerAreaAtIndex(index)->showZhuangbei(equipCard);
}

void MainWindow::gameOver(char result) {
	gameOverBox->showResult(result);
}

AudioPlayer * MainWindow::getAudioPlayer() const {
	return audioPlayer;
}

AudioPlayer * MainWindow::getSkillPlayer() const {
	return skillPlayer;
}

void MainWindow::setDead(int targetPlayerIndex) {
	if (targetPlayerIndex == playerIndex) {
		wujiangA->setDead();
	} else {
		otherPlayerAreaAtIndex(targetPlayerIndex)->setDead();
	}
}

void MainWindow::setRespodingPhase(int targetPlayerIndex, bool responding) {
	if (targetPlayerIndex == playerIndex) {
		/*DO NOTHING, as GUI doesn't has the phase of human player*/
	} else {
		otherPlayerAreaAtIndex(targetPlayerIndex)->setResponding(responding);
	}
}

void MainWindow::setDying(int targetPlayerIndex, bool dying) {
	if (targetPlayerIndex == playerIndex) {
		wujiangA->setDying(dying);
	} else {
		otherPlayerAreaAtIndex(targetPlayerIndex)->setDying(dying);
	}
}

int MainWindow::getHP(int targetPlayerIndex) const {
	if (targetPlayerIndex == playerIndex) {
		return wujiangA->getHP();
	} else {
		return otherPlayerAreaAtIndex(targetPlayerIndex)->getHP();
	}
}

void MainWindow::setHP(int targetPlayerIndex, int HP) {
	if (targetPlayerIndex == playerIndex) {
		wujiangA->setHP(HP);
	} else {
		otherPlayerAreaAtIndex(targetPlayerIndex)->setHP(HP);
	}
}

void MainWindow::setHPDamage(int targetPlayerIndex, int HPDamage) {
	if (targetPlayerIndex == playerIndex) {
		wujiangA->setHPDamage(HPDamage);
	} else {
		PlayerArea * targetPlayerArea = otherPlayerAreaAtIndex(
				targetPlayerIndex);
		targetPlayerArea->setHPDamage(HPDamage);
	}
}

} /* namespace sgsui */
