/*
 * sgsui_CardViewer.h
 *
 *  Created on: Jul 3, 2012
 *      Author: latios
 */

#ifndef SGSUI_CARDVIEWER_H_
#define SGSUI_CARDVIEWER_H_

#include "ui_CardViewer.h"

namespace sgs {
namespace DataType {
class Card;
}
}

namespace sgsui {

class CardFrame;

class CardViewer: public QFrame, protected Ui::CardViewer {
public:
	CardViewer(QWidget *parent = 0);
	void showViewer(const sgs::DataType::Card * _card1, const sgs::DataType::Card * _card2);
	void showSecondViewer();

private:
	const static QSize fixedSize;
	const sgs::DataType::Card * card1;
	const sgs::DataType::Card * card2;
	CardFrame* cardFrame1;
	CardFrame* cardFrame2;
};

} /* namespace sgsui */
#endif /* SGSUI_CARDVIEWER_H_ */
