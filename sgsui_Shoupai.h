/*
 * sgsui_Shoupai.h
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#ifndef SGSUI_SHOUPAI_H_
#define SGSUI_SHOUPAI_H_

#include "sgsui_CardButton.h"

namespace sgs {
namespace DataType {
class Card;
}
}

namespace sgsui {

class Shoupai: public CardButton {
public:
	Shoupai(const sgs::DataType::Card * card, AbstractCardContainer* container,
			QWidget *parent = 0);

private:
	void mousePressEvent(QMouseEvent*);
	void mouseDoubleClickEvent(QMouseEvent*);
};

} /* namespace sgsui */
#endif /* SGSUI_SHOUPAI_H_ */
