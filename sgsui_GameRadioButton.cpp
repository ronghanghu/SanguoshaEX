/*
 * sgsui_GameRadioButton.cpp
 *
 *  Created on: Jun 16, 2012
 *      Author: latios
 */

#include "sgsui_GameRadioButton.h"
#include <QtGui>

namespace sgsui {

GameRadioButton::GameRadioButton(QWidget *parent, const QPixmap& radioOffPixmap,
		const QPixmap& radioOnPixmap) :
		QRadioButton(parent), _radioOffPixmap(radioOffPixmap), _radioOnPixmap(
				radioOnPixmap) {
	setFixedSize(_radioOffPixmap.size());
}

void GameRadioButton::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.drawPixmap(0, 0,
			(isEnabled() && isChecked() ? _radioOnPixmap : _radioOffPixmap));
}

} /* namespace sgsui */
