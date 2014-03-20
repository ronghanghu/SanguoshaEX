/*
 * sgsui_ResultPlayerLabel.cpp
 *
 *  Created on: May 27, 2012
 *      Author: latios
 */

#include "sgsui_ResultPlayerLabel.h"
#include "sgsui_nameConvert.h"
#include <QtGui>

namespace sgsui {

const QSize ResultPlayerLabel::fixedSize(96, 98);
const QColor ResultPlayerLabel::deadColor(0, 0, 0, 100);

ResultPlayerLabel::ResultPlayerLabel(QWidget * parent) :
		QLabel(parent), heroType(sgs::ConstData::htNone), isDead(false) {
	setFixedSize(fixedSize);
}

void ResultPlayerLabel::showResult(sgs::ConstData::HeroType _heroType,
		bool _isDead) {
	heroType = _heroType;
	isDead = _isDead;
}

void ResultPlayerLabel::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, QPixmap("images/frame/result.png"));
	painter.drawPixmap(1, 1, wujiangSelfPixmapStr(heroType));
	if (isDead) {
		painter.fillRect(QRect(QPoint(0, 0), fixedSize), deadColor);
		painter.drawPixmap(5, 20, QPixmap("images/death/dead.png"));
	}
}

} /* namespace sgsui */
