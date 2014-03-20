/*
 * sgsui_PosAnimation.cpp
 *
 *  Created on: May 5, 2012
 *      Author: latios
 */

#include "sgsui_PosAnimation.h"
#include "sgsui_CardFrame.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

PosAnimation::PosAnimation(QFrame * usedCardFrame, QHBoxLayout * usedCardLayout,
		QObject * parent) :
		QObject(parent), _usedCardFrame(usedCardFrame), _usedCardLayout(
				usedCardLayout), abandonCount(0), addCardIndex(0), animationCount(
				0) {
	usedCardFrameMovingAnimation = 0;

	cardMovingAnimation = new QParallelAnimationGroup(this);

	pauseAnimation = new QPauseAnimation(this);
	pauseAnimation->setDuration(GUIStaticData::useCardAnimationDuration / 3);

	fullAnimation = new QSequentialAnimationGroup(this);
	fullAnimation->addAnimation(cardMovingAnimation);

	connect(cardMovingAnimation, SIGNAL(finished()), this,
			SLOT(movingStopped()));
	connect(fullAnimation, SIGNAL(finished()), this, SLOT(animationStopped()));
}

PosAnimation::~PosAnimation() {
	for (std::vector<QPropertyAnimation *>::iterator iter =
			CardAnimationVector.begin(); iter != CardAnimationVector.end();
			++iter) {
		delete *iter;
	}
}

void PosAnimation::addCard(const QPoint &startPoint, const QPoint &finishPoint,
		CardFrame * targetCard, bool abandonCard) {
	if (blockLoop.isRunning()) {
		printDebug(
				"<font color=red><b>Warning: </b></font>PosAnimation::runAnimation: the previous animation is not finished yet");
		return;
	}

	abandonCount += abandonCard;
	CardVector.push_back(std::pair<CardFrame *, bool>(targetCard, abandonCard));
	QPoint translatedFinishPoint(
			finishPoint + QPoint(abandonCount * abandonCard * 15, 0));
	QPropertyAnimation * animation = 0;
	{
		animation = new QPropertyAnimation(targetCard, "pos", this);
		animation->setDuration(GUIStaticData::useCardAnimationDuration / 2);
		animation->setEasingCurve(QEasingCurve::OutQuad);

		animation->setStartValue(startPoint);
		animation->setEndValue(translatedFinishPoint);
		CardAnimationVector.push_back(animation);
		cardMovingAnimation->addAnimation(animation);
	}
	targetCard->show();
	++addCardIndex;
}

void PosAnimation::runAnimation() {

	// add pause after game started, to make sure the fisrt card distribute is quick without pause
	if (animationCount++ == GUIStaticData::getPlayerCount())
		fullAnimation->addAnimation(pauseAnimation);

	if (blockLoop.isRunning()) {
		printDebug(
				"<font color=red><b>Warning: </b></font>PosAnimation::runAnimation: the previous animation is not finished yet");
		return;
	}

	if (abandonCount > 0) {
		if (_usedCardLayout->count() > GUIStaticData::maxUsedCardContain) {
			delete _usedCardLayout->takeAt(1)->widget();
		}
		QPoint originPos = _usedCardFrame->pos();
		usedCardFrameMovingAnimation = new QPropertyAnimation(_usedCardFrame,
				"pos", this);
		usedCardFrameMovingAnimation->setDuration(
				GUIStaticData::useCardAnimationDuration / 2);
		usedCardFrameMovingAnimation->setStartValue(originPos);
		int cardFrameWidth = 93;
		usedCardFrameMovingAnimation->setKeyValueAt(0.999999,
				originPos + QPoint(cardFrameWidth, 0));
		usedCardFrameMovingAnimation->setEndValue(originPos);
		cardMovingAnimation->addAnimation(usedCardFrameMovingAnimation);
	}
	fullAnimation->start();
	blockLoop.exec();
}

void PosAnimation::movingStopped() {
	for (std::vector<std::pair<CardFrame *, bool> >::iterator iter =
			CardVector.begin(); iter != CardVector.end(); ++iter) {
		std::pair<CardFrame *, bool> cardInfo = *iter;
		if (cardInfo.second) {
			if (_usedCardLayout->count() > GUIStaticData::maxUsedCardContain) {
				delete _usedCardLayout->takeAt(1)->widget();
			}
			_usedCardLayout->addWidget(cardInfo.first);
		}
		// if it is not to abandon, it will be handled below
	}
}

void PosAnimation::animationStopped() {
	for (std::vector<std::pair<CardFrame *, bool> >::iterator iter =
			CardVector.begin(); iter != CardVector.end(); ++iter) {
		std::pair<CardFrame *, bool> cardInfo = *iter;
		// if it is to abandon, it has been handled above
		if (!cardInfo.second)
			delete cardInfo.first;
	}
	delete usedCardFrameMovingAnimation;
	usedCardFrameMovingAnimation = 0;

	CardVector.clear();
	for (std::vector<QPropertyAnimation *>::iterator iter =
			CardAnimationVector.begin(); iter != CardAnimationVector.end();
			++iter) {
		delete *iter;
	}
	CardAnimationVector.clear();
	cardMovingAnimation->clear();
	abandonCount = 0;
	addCardIndex = 0;
	blockLoop.quit();
}

} /* namespace sgsui */
