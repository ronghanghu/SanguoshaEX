/*
 * sgsai_AILuxun.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AILuxun.h"
#include "sgsui_output.h"

namespace sgsai {

AILuxun::AILuxun(int seat) :
		AICommon(seat) {
}

bool AILuxun::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AILuxun::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));

	bool returnValue = true;
	printDebug(
			"AILuxun::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
