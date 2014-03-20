/*
 * sgsui_LineAnimationWidget.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: latios
 */

#include "sgsui_LineAnimationWidget.h"
#include <QtGui>

namespace sgsui {

LineAnimationWidget::LineAnimationWidget(QWidget *parent) :
		QWidget(parent), linePen(Qt::white, 3, Qt::SolidLine, Qt::RoundCap), sourcePoint(
				0, 0) {
	fullTimer = new QTimer(this);
	fullTimer->setSingleShot(true);

	effect = new QGraphicsOpacityEffect(this);
	effect->setOpacity(.7);
	setGraphicsEffect(effect);

	connect(fullTimer, SIGNAL(timeout()), this, SLOT(hide()));
}

void LineAnimationWidget::lineAnimation(const QPoint &source,
		const std::vector<QPoint> &targetVec, int duration) {
	sourcePoint = source;
	targetCount = 0;

	for (std::vector<QPoint>::const_iterator citer = targetVec.begin();
			citer != targetVec.end(); ++citer) {
		targetPoint[targetCount++] = *citer;
	}

	fullDuration =
			(duration > 0) ? duration : GUIStaticData::lineAnimationDuration;
	update();
	fullTimer->start(fullDuration);
	show();
}

void LineAnimationWidget::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(linePen);
	for (int i = 0; i < targetCount; ++i)
		painter.drawLine(sourcePoint, targetPoint[i]);
}

} /* namespace sgsui */
