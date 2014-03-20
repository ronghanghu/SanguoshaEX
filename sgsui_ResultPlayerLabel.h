/*
 * sgsui_ResultPlayerLabel.h
 *
 *  Created on: May 27, 2012
 *      Author: latios
 */

#ifndef SGSUI_RESULTPLAYERLABEL_H_
#define SGSUI_RESULTPLAYERLABEL_H_

#include <QLabel>
#include "sgsdata_enum.h"

namespace sgsui {

class ResultPlayerLabel: public QLabel {
public:
	explicit ResultPlayerLabel(QWidget * parent = 0);
	void paintEvent(QPaintEvent * event);
	void showResult(sgs::ConstData::HeroType _heroType, bool _isDead = false);

private:
	sgs::ConstData::HeroType heroType;
	bool isDead;
	const static QSize fixedSize;
	const static QColor deadColor;
};

} /* namespace sgsui */
#endif /* SGSUI_RESULTPLAYERLABEL_H_ */
