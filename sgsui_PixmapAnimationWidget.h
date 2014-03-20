/*
 * sgsui_PixmapAnimationWidget.h
 *
 *  Created on: Apr 14, 2012
 *      Author: latios
 */

#ifndef SGSUI_PIXMAPANIMATIONWIDGET_H_
#define SGSUI_PIXMAPANIMATIONWIDGET_H_

#include <QLabel>
#include <list>
#include <QSize>
#include "sgsui_GUIStaticData.h"

class QPixmap;
class QTimer;

namespace sgsui {

class PixmapAnimationWidget: public QLabel {
Q_OBJECT
public:
	explicit PixmapAnimationWidget(QWidget *parent = 0);
	~PixmapAnimationWidget();

public slots:
	void pixmapAnimation(const QPoint &position,
			PixmapAnimationType animationType);

private slots:
	void updatePixmap();

private:
	std::list<QPixmap *> useBlackSlashPixmapList;
	std::list<QPixmap *> useRedSlashPixmapList;
	std::list<QPixmap *> useFireSlashPixmapList;
	std::list<QPixmap *> useThunderSlashPixmapList;
	std::list<QPixmap *> usePeachPixmapList;
	std::list<QPixmap *> useJinkPixmapList;
	std::list<QPixmap *> useAnalepticPixmapList;
	std::list<QPixmap *> damagePixmapList;
	std::list<QPixmap *> lightningPixmapList;
	std::list<QPixmap *> chainPixmapList;
	std::list<QPixmap *> duelPixmapList;
	std::list<QPixmap *> wuxiePixmapList;
	std::list<QPixmap *>::iterator basicAnimationIter;
	std::list<QPixmap *>::iterator endIter;

	QSize blackSlashSize;
	QSize redSlashSize;
	QSize fireSlashSize;
	QSize thunderSlashSize;
	QSize jinkSize;
	QSize peachSize;
	QSize analepticSize;
	QSize damageSize;
	QSize lightningSize;
	QSize chainSize;
	QSize duelSize;
	QSize wuxieSize;
	QTimer* basicTimer;
};

} /* namespace sgsui */
#endif /* SGSUI_PIXMAPANIMATIONWIDGET_H_ */
