/*
 * sgsui_ZhuangbeiLabel.cpp
 *
 *  Created on: Jun 27, 2012
 *      Author: latios
 */

#include "sgsui_ZhuangbeiLabel.h"
#include "sgsui_nameConvert.h"

namespace sgsui {

const QSize ZhuangbeiLabel::fixedSize(150, 50);

ZhuangbeiLabel::ZhuangbeiLabel(QWidget *parent) :
		QLabel(parent) {
	zhuangbeiTimer = new QTimer(this);
	zhuangbeiTimer->setSingleShot(true);
	connect(zhuangbeiTimer, SIGNAL(timeout()), this, SLOT(hide()));
	setFont(GUIStaticData::equipFont);
	setFixedSize(fixedSize);
}

void ZhuangbeiLabel::showZhuangbei(sgs::ConstData::CardType equipCard,
		int equipDuration) {
	if (equipDuration < 0)
		equipDuration = GUIStaticData::showEquipDuration;

	setText(setColored(cardDisplayName(equipCard), false));
	zhuangbeiTimer->start(equipDuration);
	show();
}

} /* namespace sgsui */
