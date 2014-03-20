/*
 * sgsui_WujiangButton.h
 *
 *  Created on: Apr 4, 2012
 *      Author: latios
 */

#ifndef SGSUI_WUJIANGBUTTON_H_
#define SGSUI_WUJIANGBUTTON_H_

#include <QLabel>
#include <QPixmap>
#include "sgsdata_enum.h"

namespace sgsui {

class WujiangButton: public QLabel {
Q_OBJECT
public:
	explicit WujiangButton(QWidget *parent = 0);
	void setWujiang(sgs::ConstData::HeroType heroType);

signals:
	void choosen(sgs::ConstData::HeroType heroType);

private:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	bool _clicked;
	QPixmap wujiangCardPixmap;
	sgs::ConstData::HeroType _heroType;

	const static QPoint selectedMargin;
	const static QPoint unselectedMargin;
};

} /* namespace sgsui */
#endif /* SGSUI_WUJIANGBUTTON_H_ */
