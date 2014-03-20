/*
 * sgsui_SkillLabel.h
 *
 *  Created on: Jun 18, 2012
 *      Author: latios
 */

#ifndef SGSUI_SKILLLABEL_H_
#define SGSUI_SKILLLABEL_H_

#include <QLabel>
#include "sgsui_GUIStaticData.h"

namespace sgsui {

class SkillLabel: public QLabel {
public:
	explicit SkillLabel(QWidget *parent = 0);
	void showSkill(sgs::ConstData::HeroSkill skill, int skillDuration =
			GUIStaticData::showSkillDuration);

private:
	QTimer * skillTimer;
	const static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_SKILLLABEL_H_ */
