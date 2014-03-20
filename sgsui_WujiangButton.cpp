/*
 * sgsui_WujiangButton.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: latios
 */

#include "sgsui_WujiangButton.h"
#include "sgsui_nameConvert.h"
#include <QtGui>

namespace sgsui {

const QPoint WujiangButton::selectedMargin(4, 4);
const QPoint WujiangButton::unselectedMargin(0, 0);

WujiangButton::WujiangButton(QWidget *parent) :
		QLabel(parent), _clicked(false), _heroType(sgs::ConstData::htNone) {
}

void WujiangButton::setWujiang(sgs::ConstData::HeroType heroType) {
	_heroType = heroType;
	wujiangCardPixmap.load(wujiangCardPixmapStr(_heroType));
	setFixedSize(wujiangCardPixmap.size());
}

void WujiangButton::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	if (_clicked)
		painter.drawPixmap(selectedMargin, wujiangCardPixmap);
	else
		painter.drawPixmap(unselectedMargin, wujiangCardPixmap);
}

void WujiangButton::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		_clicked = true;
		update();
	}
}

void WujiangButton::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		_clicked = false;
		if (QRect(QPoint(0, 0), size()).contains(event->pos()))
			emit choosen(_heroType);
		update();
	}
}

} /* namespace sgsui */
