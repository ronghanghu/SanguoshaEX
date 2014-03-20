/*
 * sgsui_DragableCardFrame.h
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#ifndef DRAGABLECARDFRAME_H_
#define DRAGABLECARDFRAME_H_

#include "sgsui_CardFrame.h"
#include "sgsui_AbstractDragProcessor.h"
#include "sgsdata_card.h"

namespace sgsui {

class DragableCardFrame: public CardFrame {
public:
	DragableCardFrame(QWidget* dragBorderWidget, AbstractDragProcessor * dragProcessor,
			const sgs::DataType::Card * card, const QPoint &pos);

	// NO pos version of constructor
	DragableCardFrame(QWidget* dragBorderWidget, AbstractDragProcessor * dragProcessor,
			const sgs::DataType::Card * card);
	const sgs::DataType::Card * card() const;

	const QPoint& getLastPos() const;

private:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	const QPoint& normalizePosition(QPoint &unnormalizedPosition);

	QPoint lastPos;
	QWidget * const _dragBorderWidget;
	AbstractDragProcessor * const _dragProcessor;
	QPoint dragPoint;
	bool pressed;
	const sgs::DataType::Card * const platformCard;
};

} /* namespace sgsui */
#endif /* DRAGABLECARDFRAME_H_ */
