/*
 * sgsui_LineAnimationWidget.h
 *
 *  Created on: Apr 14, 2012
 *      Author: latios
 */

#ifndef SGSUI_LINEANIMATIONWIDGET_H_
#define SGSUI_LINEANIMATIONWIDGET_H_

#include "sgsui_GUIStaticData.h"
#include <QFrame>
#include <QPen>
#include <vector>

class QTimer;
class QGraphicsOpacityEffect;

namespace sgsui {

class LineAnimationWidget: public QWidget {
Q_OBJECT
public:
	explicit LineAnimationWidget(QWidget *parent = 0);

public slots:
	void lineAnimation(const QPoint &source,
			const std::vector<QPoint> &targetVec, int duration =
					GUIStaticData::lineAnimationDuration);

private:
	void paintEvent(QPaintEvent*);

	QPen linePen;
	QPoint sourcePoint;
	QPoint targetPoint[7];
	int fullDuration;
	int updateCount;
	int targetCount;
	QTimer * fullTimer;

	QGraphicsOpacityEffect * effect;
};

} /* namespace sgsui */
#endif /* SGSUI_LINEANIMATIONWIDGET_H_ */
