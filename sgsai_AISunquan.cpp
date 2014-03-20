/*
 * sgsai_AISunquan.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AISunquan.h"
#include "sgsui_output.h"

namespace sgsai {

AISunquan::AISunquan(int seat) :
		AICommon(seat) {
}

bool AISunquan::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AISunquan::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug(
			"<font color=red><b>Warning: </b></font>AISunquan::useSkillOrNot: shouldn't be called becase sunquan has no passive skill");
	bool returnValue = true;
	printDebug(
			"AISunquan::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
