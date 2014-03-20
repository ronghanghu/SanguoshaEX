/*
 * sgsui_BlockableButton.h
 *
 *  Created on: May 1, 2012
 *      Author: latios
 */

#ifndef SGSUI_BLOCKABLEBUTTON_H_
#define SGSUI_BLOCKABLEBUTTON_H_

#include "sgsui_GameButton.h"

namespace sgsui {

class BlockableButton: public GameButton {
public:
	explicit BlockableButton(QWidget *parent = 0);

private:
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
};

} /* namespace sgsui */
#endif /* SGSUI_BLOCKABLEBUTTON_H_ */
