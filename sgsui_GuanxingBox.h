/*
 * sgsui_GuanxingBox.h
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#ifndef SGSUI_GUANXINGBOX_H_
#define SGSUI_GUANXINGBOX_H_

#include "ui_GuanxingBox.h"
#include "sgsui_BlockingFrame.h"
#include "sgsui_AbstractDragProcessor.h"
#include "sgsdata_card.h"

namespace sgsui {

class GuanxingBox: public BlockingFrame,
		protected Ui::GuanxingBox,
		public AbstractDragProcessor {
public:
	explicit GuanxingBox(QWidget *parent);
	void enterKeyPressedEvent();
	void chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
			std::vector<const sgs::DataType::Card *>& buttom);

private:
	QPoint processDrag(DragableCardFrame * card);
	DragableCardFrame*& getPointer(const QPoint &currectPos);
	QPoint posOfPointer(DragableCardFrame * const & pointer) const;
	void clearData();

	DragableCardFrame ** upperCard[5];
	DragableCardFrame ** lowerCard[5];
	DragableCardFrame * upperCard0;
	DragableCardFrame * upperCard1;
	DragableCardFrame * upperCard2;
	DragableCardFrame * upperCard3;
	DragableCardFrame * upperCard4;
	DragableCardFrame * lowerCard0;
	DragableCardFrame * lowerCard1;
	DragableCardFrame * lowerCard2;
	DragableCardFrame * lowerCard3;
	DragableCardFrame * lowerCard4;
	const QPoint * upperPosition[5];

	const static QPoint upperPosition0;
	const static QPoint upperPosition1;
	const static QPoint upperPosition2;
	const static QPoint upperPosition3;
	const static QPoint upperPosition4;
	const static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_GUANXINGBOX_H_ */
