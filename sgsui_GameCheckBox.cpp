/*
 * sgsui_GameCheckBox.cpp
 *
 *  Created on: Apr 7, 2012
 *      Author: latios
 */

#include "sgsui_GameCheckBox.h"
#include <QtGui>

namespace sgsui {

GameCheckBox::GameCheckBox(QWidget *parent, const QPixmap& noncheckedPixmap,
		const QPixmap& checkedPixmap) :
		QCheckBox(parent), _noncheckedPixmap(noncheckedPixmap), _checkedPixmap(
				checkedPixmap) {
	setFixedSize(_noncheckedPixmap.size());
}

void GameCheckBox::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.drawPixmap(0, 0,
			(isEnabled() && isChecked() ? _checkedPixmap : _noncheckedPixmap));
}

} /* namespace sgsui */
