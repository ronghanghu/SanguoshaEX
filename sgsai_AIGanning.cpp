/*
 * sgsai_AIGanning.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIGanning.h"
#include "sgsui_output.h"
#include "sgsdata_card.h"
#include "sgsdata_skill.h"
#include "sgsdata_player.h"
#include "sgsdata_msg.h"
#include "sgsui_PlayerSort.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"

namespace sgsai {

AIGanning::AIGanning(int seat) :
		AICommon(seat) {
}

bool AIGanning::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIGanning::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug(
			"<font color=red><b>Warning: </b></font>AIGanning::useSkillOrNot: shouldn't be called becase Ganning has no passive skill");
	bool returnValue = true;
	printDebug(
			"AIGanning::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

sgs::Derive::MSkill * AIGanning::useQixiInUsecard() {
	sgs::Derive::MQiXi * returnQixi = 0;

//	const CardVec& blackShoupaiFound = blackShoupai();
//	if (blackShoupaiFound.empty()) {
//		printDebug("AIZhenji::useQingguoInShanOrNot: no black card");
//		return returnQixi;
//	}
//
//	for (CardVec::const_iterator cardIter = blackShoupaiFound.begin();
//			cardIter != blackShoupaiFound.end(); ++cardIter) {
//		returnQixi = new sgs::Derive::MQiXi(myPlayer(),
//				(*cardIter).second);
//		printDebug(sgsui::messageInterpret(returnQixi));
//		printDebug("AIZhenji::useQingguoInShanOrNot: over");
//		return returnQixi;
//	}
	return returnQixi;
}

const CardVec& AIGanning::blackShoupai() {
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

const CardVec& AIGanning::blackEquip() {
	blackEquipVec.clear();
	const sgs::DataType::Card * card = 0;
	card = myPlayer()->weapon();
	if (card
			&& (card->color() == sgs::ConstData::SPADE
					|| card->color() == sgs::ConstData::CLUB)) {
		blackShoupaiVec.push_back(cardPair(card, 0));
	}
	card = myPlayer()->armor();
	if (card
			&& (card->color() == sgs::ConstData::SPADE
					|| card->color() == sgs::ConstData::CLUB)) {
		blackShoupaiVec.push_back(cardPair(card, 1));
	}
	card = myPlayer()->atkhorse();
	if (card
			&& (card->color() == sgs::ConstData::SPADE
					|| card->color() == sgs::ConstData::CLUB)) {
		blackShoupaiVec.push_back(cardPair(card, 2));
	}
	card = myPlayer()->dfdhorse();
	if (card
			&& (card->color() == sgs::ConstData::SPADE
					|| card->color() == sgs::ConstData::CLUB)) {
		blackShoupaiVec.push_back(cardPair(card, 3));
	}
	return blackEquipVec;
}

} /* namespace sgsai */
