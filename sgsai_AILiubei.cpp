/*
 * sgsai_AILiubei.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AILiubei.h"
#include "sgsui_output.h"

namespace sgsai {

AILiubei::AILiubei(int seat) :
		AICommon(seat) {
}

bool AILiubei::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AILiubei::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug(
			"<font color=red><b>Warning: </b></font>AILiubei::useSkillOrNot: shouldn't be called becase liubei has no passive skill");

	bool returnValue = true;
	printDebug(
			"AILiubei::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
