/*
 * sgsui_DragableCardFrame.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#include "sgsui_DragableCardFrame.h"
#include <QtGui>

namespace sgsui {

DragableCardFrame::DragableCardFrame(QWidget* dragBorderWidget,
		AbstractDragProcessor * dragProcessor, const sgs::DataType::Card * card,
		const QPoint &pos) :
		CardFrame(card->type(), card->color(), card->number(),
				dragBorderWidget), lastPos(pos), _dragBorderWidget(
				dragBorderWidget), _dragProcessor(dragProcessor), pressed(
				false), platformCard(card) {
	move(pos);
}

DragableCardFrame::DragableCardFrame(QWidget* dragBorderWidget,
		AbstractDragProcessor * dragProcessor, const sgs::DataType::Card * card) :
		CardFrame(card->type(), card->color(), card->number(),
				dragBorderWidget), _dragBorderWidget(dragBorderWidget), _dragProcessor(
				dragProcessor), pressed(false), platformCard(card) {
	lastPos = pos();
}

const sgs::DataType::Card * DragableCardFrame::card() const {
	return platformCard;
}

const QPoint& DragableCardFrame::getLastPos() const {
	return lastPos;
}

void DragableCardFrame::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		lastPos = pos();
		dragPoint = event->pos();
		pressed = true;
	}
}

void DragableCardFrame::mouseMoveEvent(QMouseEvent *event) {
	if (!pressed)
		return;
	raise();
	QPoint moveToPosition(event->pos() - dragPoint + pos());
	this->move(normalizePosition(moveToPosition));
}

void DragableCardFrame::mouseReleaseEvent(QMouseEvent *event) {
	if (pressed && event->button() == Qt::LeftButton) {
		move(_dragProcessor->processDrag(this));
		lastPos = pos();
		pressed = false;
	}
}

const QPoint& DragableCardFrame::normalizePosition(
		QPoint &unnormalizedPosition) {
	if (unnormalizedPosition.rx() < 0)
		unnormalizedPosition.rx() = 0;
	if (unnormalizedPosition.rx() > _dragBorderWidget->width() - width())
		unnormalizedPosition.rx() = _dragBorderWidget->width() - width();
	if (unnormalizedPosition.ry() < 0)
		unnormalizedPosition.ry() = 0;
	if (unnormalizedPosition.ry() > _dragBorderWidget->height() - height())
		unnormalizedPosition.ry() = _dragBorderWidget->height() - height();
	return unnormalizedPosition;
}

} /* namespace sgsui */
