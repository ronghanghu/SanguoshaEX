/*
 * sgsai_AIZhangliao.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIZhangliao.h"
#include "sgsui_output.h"

namespace sgsai {

AIZhangliao::AIZhangliao(int seat) :
		AICommon(seat) {
}

bool AIZhangliao::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIZhangliao::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug(
			"<font color=red><b>Warning: </b></font>AIZhangliao::useSkillOrNot: shouldn't be called becase zhangliao has no passive skill (note: tuxi is canceled by getTuxi)");
	bool returnValue = true;
	printDebug(
			"AIZhangliao::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
