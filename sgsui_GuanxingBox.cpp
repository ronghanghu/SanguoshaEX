/*
 * sgsui_GuanxingBox.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#include "sgsui_GuanxingBox.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_nameConvert.h"
#include "sgsui_DragableCardFrame.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

const QPoint GuanxingBox::upperPosition0(1, 1);
const QPoint GuanxingBox::upperPosition1(103, 1);
const QPoint GuanxingBox::upperPosition2(205, 1);
const QPoint GuanxingBox::upperPosition3(307, 1);
const QPoint GuanxingBox::upperPosition4(409, 1);
const QSize GuanxingBox::fixedSize(915, 400);

GuanxingBox::GuanxingBox(QWidget *parent) :
		BlockingFrame(parent), upperCard0(0), upperCard1(0), upperCard2(0), upperCard3(
				0), upperCard4(0), lowerCard0(0), lowerCard1(0), lowerCard2(0), lowerCard3(
				0), lowerCard4(0) {
	setupUi(this);
	setFixedSize(fixedSize);

	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	okButton->setDisabledPixmap(QPixmap("images/button/ok-disabled.png"));
	upHint1->setFont(GUIStaticData::contentFont);
	upHint2->setFont(GUIStaticData::contentFont);
	downHint1->setFont(GUIStaticData::contentFont);
	downHint2->setFont(GUIStaticData::contentFont);
	hintLabel1->setFont(GUIStaticData::contentFont);
	hintLabel2->setFont(GUIStaticData::contentFont);

	upperCard[0] = &upperCard0;
	upperCard[1] = &upperCard1;
	upperCard[2] = &upperCard2;
	upperCard[3] = &upperCard3;
	upperCard[4] = &upperCard4;

	lowerCard[0] = &lowerCard0;
	lowerCard[1] = &lowerCard1;
	lowerCard[2] = &lowerCard2;
	lowerCard[3] = &lowerCard3;
	lowerCard[4] = &lowerCard4;

	upperPosition[0] = &upperPosition0;
	upperPosition[1] = &upperPosition1;
	upperPosition[2] = &upperPosition2;
	upperPosition[3] = &upperPosition3;
	upperPosition[4] = &upperPosition4;

	setStyleSheet(
			"QFrame#GuanxingBox{background-image:url(images/frame/guanxingBox.png)}");

	zhugeliangLabel->showResult(sgs::ConstData::LAOZHUGE);

	connect(okButton, SIGNAL(clicked()), this, SLOT(unblock()));
}

void GuanxingBox::enterKeyPressedEvent() {
	okButton->click();
}

void GuanxingBox::chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
		std::vector<const sgs::DataType::Card *>& buttom) {
	printDebug("GuanxingBox::chooseGuanxing: start");
	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));

	int i = 0;
	for (std::vector<const sgs::DataType::Card *>::iterator iter = top.begin();
			iter != top.end(); ++iter, ++i) {

		printDebug("GuanxingBox::chooseGuanxing: adding card");
		// Note: upperCard[i] is DragableCardFrame**
		// So *upperCard[i] is DragableCardFrame*
		*(upperCard[i]) = new DragableCardFrame(middleFrame, this, *iter,
				*(upperPosition[i]));
	}
	printDebug("GuanxingBox::chooseGuanxing: cards created");

	exec();
	top.clear();
	buttom.clear();
	DragableCardFrame * upper, *lower;
	for (int i = 0; i < 5; ++i) {
		upper = *(upperCard[i]);
		lower = *(lowerCard[i]);
		// Note: upperCard[i] is DragableCardFrame**
		// So *upperCard[i] is DragableCardFrame*
		if (upper) {
			top.push_back(upper->card());
		}
		if (lower) {
			buttom.push_back(lower->card());
		}
	}

	clearData();
}

QPoint GuanxingBox::processDrag(DragableCardFrame * card) {
	DragableCardFrame *& currentPositionPointer = getPointer(card->pos());
	DragableCardFrame *& lastPositionPointer = getPointer(card->getLastPos());

	if (currentPositionPointer != lastPositionPointer)
		lastPositionPointer = 0;

	if (currentPositionPointer) {
		currentPositionPointer->move(card->getLastPos());
		getPointer(currentPositionPointer->pos()) = currentPositionPointer;
	}
	currentPositionPointer = card;
	return posOfPointer(getPointer(card->pos()));
}

DragableCardFrame *& GuanxingBox::getPointer(const QPoint &currectPos) {
	if (currectPos.x() < 52)
		return (currectPos.y() < 73) ? upperCard0 : lowerCard0;
	else if (currectPos.x() < 154)
		return (currectPos.y() < 73) ? upperCard1 : lowerCard1;
	else if (currectPos.x() < 256)
		return (currectPos.y() < 73) ? upperCard2 : lowerCard2;
	else if (currectPos.x() < 358)
		return (currectPos.y() < 73) ? upperCard3 : lowerCard3;
	else
		return (currectPos.y() < 73) ? upperCard4 : lowerCard4;
}

QPoint GuanxingBox::posOfPointer(DragableCardFrame * const & pointer) const {
	if (&pointer == &upperCard0)
		return QPoint(1, 1);
	if (&pointer == &upperCard1)
		return QPoint(103, 1);
	if (&pointer == &upperCard2)
		return QPoint(205, 1);
	if (&pointer == &upperCard3)
		return QPoint(307, 1);
	if (&pointer == &upperCard4)
		return QPoint(409, 1);
	if (&pointer == &lowerCard0)
		return QPoint(1, 145);
	if (&pointer == &lowerCard1)
		return QPoint(103, 145);
	if (&pointer == &lowerCard2)
		return QPoint(205, 145);
	if (&pointer == &lowerCard3)
		return QPoint(307, 145);
	if (&pointer == &lowerCard4)
		return QPoint(409, 145);

	printDebug(
			"<font color=red><b>Warning: </b></font>GuanxingBox::posOfPointer: cannot trace to position from the pointer");
	return QPoint();
}

void GuanxingBox::clearData() {
	if (upperCard0) {
		delete upperCard0;
		upperCard0 = 0;
	}
	if (upperCard1) {
		delete upperCard1;
		upperCard1 = 0;
	}
	if (upperCard2) {
		delete upperCard2;
		upperCard2 = 0;
	}
	if (upperCard3) {
		delete upperCard3;
		upperCard3 = 0;
	}
	if (upperCard4) {
		delete upperCard4;
		upperCard4 = 0;
	}
	if (lowerCard0) {
		delete lowerCard0;
		lowerCard0 = 0;
	}
	if (lowerCard1) {
		delete lowerCard1;
		lowerCard1 = 0;
	}
	if (lowerCard2) {
		delete lowerCard2;
		lowerCard2 = 0;
	}
	if (lowerCard3) {
		delete lowerCard3;
		lowerCard3 = 0;
	}
	if (lowerCard4) {
		delete lowerCard4;
		lowerCard4 = 0;
	}
}

} /* namespace sgsui */
