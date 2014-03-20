/*
 * sgsai_AIZhangfei.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIZhangfei.h"
#include "sgsui_output.h"

namespace sgsai {

AIZhangfei::AIZhangfei(int seat) :
		AICommon(seat) {
}

bool AIZhangfei::useSkillOrNot(sgs::ConstData::HeroSkill skillType,
		sgs::DataType::Player * player) {
	printDebug(
			"AILvmeng::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;
	printDebug(
			"AILvmeng::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
