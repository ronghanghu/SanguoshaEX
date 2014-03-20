/*
 * sgsai_AISunshangxiang.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AISunshangxiang.h"
#include "sgsui_output.h"

namespace sgsai {

AISunshangxiang::AISunshangxiang(int seat) :
		AICommon(seat) {
}

bool AISunshangxiang::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AISunshangxiang::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;
	printDebug(
			"AISunshangxiang::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
