/*
 * sgsui_ZhuangbeiLabel.h
 *
 *  Created on: Jun 27, 2012
 *      Author: latios
 */

#ifndef SGSUI_ZHUANGBEILABEL_H_
#define SGSUI_ZHUANGBEILABEL_H_

#include <QLabel>
#include "sgsui_GUIStaticData.h"

namespace sgsui {

class ZhuangbeiLabel: public QLabel {
public:
	explicit ZhuangbeiLabel(QWidget *parent = 0);
	void showZhuangbei(sgs::ConstData::CardType equipCard, int equipDuration =
			GUIStaticData::showEquipDuration);

private:
	QTimer * zhuangbeiTimer;
	const static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_ZHUANGBEILABEL_H_ */
