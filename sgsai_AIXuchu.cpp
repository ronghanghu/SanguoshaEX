/*
 * sgsai_AIXuchu.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIXuchu.h"
#include "sgsdata_player.h"
#include "sgsdata_card.h"
#include "sgsui_output.h"

namespace sgsai {

AIXuchu::AIXuchu(int seat) :
		AICommon(seat) {
}

bool AIXuchu::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIXuchu::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));

	bool returnValue = false;
	if (myPlayer()->status() & sgs::ConstData::LE) {
		// Do nothing
	} else {
		sgs::ConstData::CardType cardType;
		for (int i = 0; i < myPlayer()->handnum(); ++i) {
			cardType = myPlayer()->hand(i)->type();
			if (cardType == sgs::ConstData::SHA
					|| cardType == sgs::ConstData::JUEDOU) {
				returnValue = true;
				break;
			}
		}
	}

	// if there is no enemy in range, set return value false
	if (returnValue) {
		returnValue = !shaTarget().empty();
	}

	printDebug(
			"AIXuchu::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

} /* namespace sgsai */
