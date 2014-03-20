/*
 * sgsai_AIHuangyueying.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIHuangyueying.h"
#include "sgsui_output.h"

namespace sgsai {

AIHuangyueying::AIHuangyueying(int seat) :
		AICommon(seat) {
}

bool AIHuangyueying::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIHuangyueying::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;
	printDebug(
			"AIHuangyueying::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
