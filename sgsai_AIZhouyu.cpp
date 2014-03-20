/*
 * sgsai_AIZhouyu.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIZhouyu.h"
#include "sgsui_output.h"

namespace sgsai {

AIZhouyu::AIZhouyu(int seat) :
		AICommon(seat) {
}

bool AIZhouyu::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIZhouyu::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));

	bool returnValue = true;
	printDebug(
			"AIZhouyu::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
