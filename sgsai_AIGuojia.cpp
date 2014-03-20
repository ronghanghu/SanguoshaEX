/*
 * sgsai_AIGuojia.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIGuojia.h"
#include "sgsui_output.h"
#include "sgsdata_msg.h"

namespace sgsai {

AIGuojia::AIGuojia(int seat) :
		AICommon(seat) {
}

bool AIGuojia::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIGuojia::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug("AIGuojia::useSkillOrNot: use tiandu and yiji");

	bool returnValue = true;
	printDebug(
			"AIGuojia::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

sgs::DataType::Message * AIGuojia::getYiji(const sgs::DataType::Card * card1,
		const sgs::DataType::Card * card2) {
	return new sgs::Derive::MYiJi(myPlayer(), myPlayer(), card1, myPlayer(), card2);
}

} /* namespace sgsai */
