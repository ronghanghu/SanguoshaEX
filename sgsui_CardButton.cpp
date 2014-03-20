/*
 * sgsui_CardButton.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#include "sgsui_CardButton.h"
#include "sgsui_CardFrame.h"
#include "sgsui_AbstractCardContainer.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

const QSize CardButton::fixedSize(93, 170);

CardButton::CardButton(const sgs::DataType::Card * platformCard,
		AbstractCardContainer* container, bool visible, QWidget *parent) :
		QFrame(parent), _cardContainer(container), cardSelectable(true), _plaformCard(
				platformCard) {
	setupUi(this);
	setFixedSize(fixedSize);

	if (visible) {
		cardFrame = new CardFrame(platformCard->type(), platformCard->color(),
				platformCard->number(), this);
	} else {
		cardFrame = new CardFrame(this);
	}
	cardLayout->addWidget(cardFrame);
	lowerSpacerWidget->hide();
}

const sgs::DataType::Card * CardButton::platformCard() {
	return _plaformCard;
}

bool CardButton::isSelected() const {
	return upperSpacerWidget->isHidden();
}

bool CardButton::isSelectable() const {
	return cardSelectable;
}

const CardFrame* CardButton::card() const {
	return cardFrame;
}

void CardButton::click() {
	QMouseEvent temp(QEvent::MouseButtonRelease,
			QPoint(width() / 2, height() / 2), Qt::LeftButton, Qt::LeftButton,
			Qt::NoModifier);
	mousePressEvent(&temp);
	mouseReleaseEvent(&temp);
}

void CardButton::setSelected(bool selected) {
	if (isSelectable() && (isSelected() != selected)) {
		if (selected) {
			lowerSpacerWidget->show();
			upperSpacerWidget->hide();
		} else {
			upperSpacerWidget->show();
			lowerSpacerWidget->hide();
		}
	}
}

void CardButton::setUnselected(bool unselected) {
	setSelected(!unselected);
}

void CardButton::setSelectable(bool selectable) {
	if (!selectable)
		setUnselected();
	cardSelectable = selectable;
	cardFrame->setNotDimed(cardSelectable);
}

void CardButton::setUnselectable(bool unselectable) {
	setSelectable(!unselectable);
}

void CardButton::mousePressEvent(QMouseEvent *event) {
	if (cardSelectable && event->button() == Qt::LeftButton)
		container()->cardClicked(this);
}

AbstractCardContainer* CardButton::container() const {
	return _cardContainer;
}

} /* namespace sgsui */
