/*
 * sgsui_BlockableButton.cpp
 *
 *  Created on: May 1, 2012
 *      Author: latios
 */

#include "sgsui_BlockableButton.h"
#include "sgsui_MainWindow.h"

namespace sgsui {

BlockableButton::BlockableButton(QWidget *parent) :
		GameButton(parent) {
}

void BlockableButton::mousePressEvent(QMouseEvent *event) {
	if (static_cast<MainWindow*>(window())->isResponding())
		GameButton::mousePressEvent(event);
}

void BlockableButton::mouseReleaseEvent(QMouseEvent *event) {
	if (static_cast<MainWindow*>(window())->isRespondingNoAnimation())
		GameButton::mouseReleaseEvent(event);
}

} /* namespace sgsui */
