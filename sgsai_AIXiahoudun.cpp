/*
 * sgsai_AIXiahoudun.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIXiahoudun.h"
#include "sgsui_output.h"

namespace sgsai {

AIXiahoudun::AIXiahoudun(int seat) :
		AICommon(seat) {
}

bool AIXiahoudun::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIXiahoudun::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;
	printDebug(
			"AIXiahoudun::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
