/*
 * sgsui_SkillButton.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#include "sgsui_SkillButton.h"

namespace sgsui {

SkillButton::SkillButton(QString Skilltext, QWidget *parent) :
		BlockableButton(parent) {
	setText(Skilltext);
}

SkillButton::SkillButton(QWidget *parent) :
		BlockableButton(parent) {
}

} /* namespace sgsui */
