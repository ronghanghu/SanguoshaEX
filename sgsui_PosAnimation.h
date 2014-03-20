/*
 * sgsui_PosAnimation.h
 *
 *  Created on: May 5, 2012
 *      Author: latios
 */

#ifndef SGSUI_POSANIMATION_H_
#define SGSUI_POSANIMATION_H_

#include <QObject>
#include <QEventLoop>
#include <QPoint>
#include <vector>
#include "sgsui_BlockLoop.h"

class QHBoxLayout;
class QFrame;
class QPropertyAnimation;
class QParallelAnimationGroup;
class QPauseAnimation;
class QSequentialAnimationGroup;

namespace sgsui {

class CardFrame;

class PosAnimation: public QObject {
Q_OBJECT
public:
	PosAnimation(QFrame * usedCardFrame, QHBoxLayout * usedCardLayout,
			QObject * parent = 0);
	~PosAnimation();
	void addCard(const QPoint &startPoint, const QPoint &finishPoint,
			CardFrame * targetCard, bool abandonCard);
	void runAnimation(); // the CardFrames are deleted or added into usedCardLayout when animation stopped

private slots:
	void movingStopped();
	void animationStopped();

private:
	QFrame * const _usedCardFrame;
	QHBoxLayout * const _usedCardLayout;

	std::vector<std::pair<CardFrame *, bool> > CardVector;
	std::vector<QPropertyAnimation *> CardAnimationVector;
	QParallelAnimationGroup * cardMovingAnimation;
	unsigned int abandonCount;
	int addCardIndex;
	QPropertyAnimation * usedCardFrameMovingAnimation;
	QPauseAnimation * pauseAnimation;
	QSequentialAnimationGroup * fullAnimation;

	BlockLoop blockLoop;

	int animationCount;
};

} /* namespace sgsui */
#endif /* SGSUI_POSANIMATION_H_ */
