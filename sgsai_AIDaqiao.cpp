/*
 * sgsai_AIDaqiao.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIDaqiao.h"
#include "sgsui_output.h"

namespace sgsai {

AIDaqiao::AIDaqiao(int seat) :
		AICommon(seat) {
}

bool AIDaqiao::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIDaqiao::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug(
			"<font color=red><b>Warning: </b></font>AIDaqiao::useSkillOrNot: shouldn't be called becase daqiao has no passive skill (note: liuli is canceled by getLiuli)");
	bool returnValue = true;
	printDebug(
			"AIDaqiao::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
