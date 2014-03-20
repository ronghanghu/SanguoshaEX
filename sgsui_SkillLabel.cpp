/*
 * sgsui_SkillLabel.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: latios
 */

#include "sgsui_SkillLabel.h"
#include "sgsui_nameConvert.h"

namespace sgsui {

const QSize SkillLabel::fixedSize(100, 50);

SkillLabel::SkillLabel(QWidget *parent) :
		QLabel(parent) {
	skillTimer = new QTimer(this);
	skillTimer->setSingleShot(true);
	connect(skillTimer, SIGNAL(timeout()), this, SLOT(hide()));
	setFont(GUIStaticData::skillFont);
	setFixedSize(fixedSize);
}

void SkillLabel::showSkill(sgs::ConstData::HeroSkill skill, int skillDuration) {
	if (skillDuration < 0)
		skillDuration = GUIStaticData::showSkillDuration;

	setText(setColored(skillDisplayName(skill), false));
	skillTimer->start(skillDuration);
	show();
}

} /* namespace sgsui */
