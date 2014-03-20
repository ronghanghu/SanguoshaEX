/*
 * sgsui_SkillButton.h
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#ifndef SGSUI_SKILLBUTTON_H_
#define SGSUI_SKILLBUTTON_H_

#include "sgsui_BlockableButton.h"

namespace sgsui {

class SkillButton: public BlockableButton {
public:
	SkillButton(QString Skilltext, QWidget *parent = 0);
	explicit SkillButton(QWidget *parent = 0);
};

} /* namespace sgsui */
#endif /* SGSUI_SKILLBUTTON_H_ */
