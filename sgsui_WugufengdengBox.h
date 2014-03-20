/*
 * sgsui_WugufengdengBox.h
 *
 *  Created on: May 3, 2012
 *      Author: latios
 */

#ifndef SGSUI_WUGUFENGDENGBOX_H_
#define SGSUI_WUGUFENGDENGBOX_H_

#include "ui_WugufengdengBox.h"
#include "sgsui_BlockingFrame.h"
#include "sgsui_AbstractCardContainer.h"
#include "sgsdata_card.h"
#include <vector>
#include <utility>

namespace sgsui {

class WugufengdengBox: public BlockingFrame,
		protected Ui::WugufengdengBox,
		protected AbstractCardContainer {
public:
	explicit WugufengdengBox(QWidget *parent = 0);
	void showContainer(
			const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wugoInfo);
	QPoint removeCard(int index);
	int chooseWugu(
			const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wugoInfo);

private:
	void constructContainer();
	void collectData();
	virtual void cardClicked(CardButton* clickedCard);
	bool isEmpty() const;
	void enterKeyPressedEvent();

	bool isChoosing;
	CardButton* buttons[8];
	QFrame* bigFrame[8];
	const QPoint *points[8];
	int returnValue;

	const static QSize fixedSize;
	const static QSize buttonSize;
	const static QPoint cardPoint0;
	const static QPoint cardPoint1;
	const static QPoint cardPoint2;
	const static QPoint cardPoint3;
	const static QPoint cardPoint4;
	const static QPoint cardPoint5;
	const static QPoint cardPoint6;
	const static QPoint cardPoint7;

};

} /* namespace sgsui */
#endif /* SGSUI_WUGUFENGDENGBOX_H_ */
