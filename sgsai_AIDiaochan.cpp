/*
 * sgsai_AIDiaochan.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIDiaochan.h"
#include "sgsui_output.h"

namespace sgsai {

AIDiaochan::AIDiaochan(int seat) :
		AICommon(seat) {
}

bool AIDiaochan::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIDiaochan::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;
	printDebug(
			"AIDiaochan::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
