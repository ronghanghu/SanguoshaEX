/*
 * sgsai_AIZhenji.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIZhenji.h"
#include "sgsui_output.h"
#include "sgsdata_card.h"
#include "sgsdata_skill.h"
#include "sgsdata_player.h"
#include "sgsdata_msg.h"
#include "sgsui_PlayerSort.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"

namespace sgsai {

AIZhenji::AIZhenji(int seat) :
		AICommon(seat) {
}

bool AIZhenji::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIZhenji::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));

	bool returnValue = true;
	printDebug(
			"AIZhenji::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

sgs::DataType::Message * AIZhenji::shanOrNot(sgs::DataType::Player * from,
		const sgs::DataType::Card * card) {
	sgs::Derive::MSkill * qingguo = useQingguoInShanOrNot();
	if (qingguo) {
		printDebug(sgsui::messageInterpret(qingguo));
		printDebug(
				"AIZhenji::shanOrNot: use qingguo, AI's seat = "
						+ QString::number(mySeat()));
		return qingguo;
	}
	return AICommon::shanOrNot(from, card);
}

sgs::Derive::MSkill * AIZhenji::useQingguoInShanOrNot() {
	sgs::Derive::MQingGuo * returnQingguo = 0;

	const CardVec& blackShoupaiFound = blackShoupai();
	if (blackShoupaiFound.empty()) {
		printDebug("AIZhenji::useQingguoInShanOrNot: no black card");
		return returnQingguo;
	}

	for (CardVec::const_iterator cardIter = blackShoupaiFound.begin();
			cardIter != blackShoupaiFound.end(); ++cardIter) {
		returnQingguo = new sgs::Derive::MQingGuo(myPlayer(),
				(*cardIter).second);
		printDebug(sgsui::messageInterpret(returnQingguo));
		printDebug("AIZhenji::useQingguoInShanOrNot: over");
		return returnQingguo;
	}
	return returnQingguo;
}

const CardVec& AIZhenji::blackShoupai() {
	blackShoupaiVec.clear();
	const sgs::DataType::Card * card = 0;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		card = myPlayer()->hand(i);
		if (card->color() == sgs::ConstData::SPADE
				|| card->color() == sgs::ConstData::CLUB) {
			blackShoupaiVec.push_back(cardPair(card, i));
		}
	}
	return blackShoupaiVec;
}

} /* namespace sgsai */
