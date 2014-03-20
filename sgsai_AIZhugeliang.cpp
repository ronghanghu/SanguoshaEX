/*
 * sgsai_AIZhugeliang.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIZhugeliang.h"
#include "sgsui_output.h"
#include "sgsdata_card.h"

namespace sgsai {

AIZhugeliang::AIZhugeliang(int seat) :
		AICommon(seat) {
}

bool AIZhugeliang::useSkillOrNot(sgs::ConstData::HeroSkill skillType,
		sgs::DataType::Player * player) {
	printDebug(
			"AIZhugeliang::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));

	bool returnValue = true;
	printDebug(
			"AIZhugeliang::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

void AIZhugeliang::chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
		std::vector<const sgs::DataType::Card *>& buttom) {
	return;
}

} /* namespace sgsai */
