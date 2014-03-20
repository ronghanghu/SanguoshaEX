/*
 * sgsai_AIZhaoyun.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIZhaoyun.h"
#include "sgsui_output.h"
#include "sgsdata_card.h"
#include "sgsdata_skill.h"
#include "sgsdata_player.h"
#include "sgsdata_msg.h"
#include "sgsui_PlayerSort.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"

namespace sgsai {

AIZhaoyun::AIZhaoyun(int seat) :
		AICommon(seat) {
}

bool AIZhaoyun::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIZhaoyun::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug(
			"<font color=red><b>Warning: </b></font>AIZhaoyun::useSkillOrNot: shouldn't be called becase zhaoyun has no passive skill");
	bool returnValue = true;
	printDebug(
			"AIZhaoyun::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

sgs::DataType::Message * AIZhaoyun::useCardResponse() {
	sgs::Derive::MSkill * longdan = useLongdanInUsecard();
	if (longdan) {
		printDebug(sgsui::messageInterpret(longdan));
		printDebug(
				"AIZhaoyun::useCardResponse: use longdan, AI's seat = "
						+ QString::number(mySeat()));
		return longdan;
	}
	return AICommon::useCardResponse();
}

sgs::DataType::Message * AIZhaoyun::shaOrNot(sgs::DataType::Player * from,
		const sgs::DataType::Card * card) {
	sgs::Derive::MSkill * longdan = useLongdanInShaOrNot();
	if (longdan) {
		printDebug(sgsui::messageInterpret(longdan));
		printDebug(
				"AIZhaoyun::shaOrNot: use longdan, AI's seat = "
						+ QString::number(mySeat()));
		return longdan;
	}
	return AICommon::shaOrNot(from, card);
}

sgs::DataType::Message * AIZhaoyun::shanOrNot(sgs::DataType::Player * from,
		const sgs::DataType::Card * card) {
	sgs::Derive::MSkill * longdan = useLongdanInShanOrNot();
	if (longdan) {
		printDebug(sgsui::messageInterpret(longdan));
		printDebug(
				"AIZhaoyun::shanOrNot: use longdan, AI's seat = "
						+ QString::number(mySeat()));
		return longdan;
	}
	return AICommon::shanOrNot(from, card);
}

sgs::Derive::MSkill * AIZhaoyun::useLongdanInUsecard() {
	sgs::Derive::MLongDan * returnLongdan = 0;
	if (!canUseSha())
		return returnLongdan;

	const CardVec& shanCardFound = shanCard();
	if (shanCardFound.empty()) {
		printDebug("AIZhaoyun::useLongdanInUsecard: no red card");
		return returnLongdan;
	}

	PlayerVec attackTargetVec = shaTarget();
	if (attackTargetVec.empty()) {
		for (CardVec::const_iterator cardIter = shanCardFound.begin();
				cardIter != shanCardFound.end(); ++cardIter) {

			if (canUseFangtian() && attackTargetVec.size() > 1) {
				printDebug("AIZhaoyun::useLongdanInUsecard: using fangtian");
				returnLongdan = new sgs::Derive::MLongDan(myPlayer(),
						(*cardIter).second);

				// push in the fisrt 3 enemies;
				int j = 0;
				PlayerVec arrangedTargets;
				for (PlayerVec::iterator iter = attackTargetVec.begin();
						iter != attackTargetVec.end() && j < 3; ++iter, ++j) {
					arrangedTargets.push_back(*iter);
				}

				// sort the targets by seat;
				sgsui::PlayerSort arrangeSeat(mySeat(), sgsui::BySeat);
				std::sort(arrangedTargets.begin(), arrangedTargets.end(),
						arrangeSeat);
				for (PlayerVec::iterator iter = arrangedTargets.begin();
						iter != arrangedTargets.end(); ++iter) {
					returnLongdan->addto(*iter);
				}
			} else {
				printDebug(
						"AIZhaoyun::useLongdanInUsecard: not using fangtian");

				// Do not use black Sha to Renwang
				// try each player in range
				for (PlayerVec::reverse_iterator riter =
						attackTargetVec.rbegin();
						riter != attackTargetVec.rend(); ++riter) {
					sgs::DataType::Player * target = *riter;

					returnLongdan = new sgs::Derive::MLongDan(myPlayer(),
							(*cardIter).second, target);
					printDebug(
							"AIZhaoyun::useLongdanInUsecard: will attack player "
									+ QString::number(target->seat())
									+ ", break and stop searching for target");
					break;
				}
			}
			return returnLongdan;
		}
	}
	return returnLongdan;
}

sgs::Derive::MSkill * AIZhaoyun::useLongdanInShaOrNot() {
	sgs::Derive::MLongDan * returnLongdan = 0;

	const CardVec& shanCardFound = shanCard();
	if (shanCardFound.empty()) {
		printDebug("AIZhaoyun::useLongdanInShaOrNot: no shan card");
		return returnLongdan;
	}

	for (CardVec::const_iterator cardIter = shanCardFound.begin();
			cardIter != shanCardFound.end(); ++cardIter) {
		returnLongdan = new sgs::Derive::MLongDan(myPlayer(),
				(*cardIter).second);
		printDebug(sgsui::messageInterpret(returnLongdan));
		printDebug("AIZhaoyun::useLongdanInShaOrNot: over");
		return returnLongdan;
	}
	return returnLongdan;
}

sgs::Derive::MSkill * AIZhaoyun::useLongdanInShanOrNot() {
	sgs::Derive::MLongDan * returnLongdan = 0;

	const CardVec& shaCardFound = shaCard();
	if (shaCardFound.empty()) {
		printDebug("AIZhaoyun::useLongdanInShanOrNot: no sha");
		return returnLongdan;
	}

	for (CardVec::const_iterator cardIter = shaCardFound.begin();
			cardIter != shaCardFound.end(); ++cardIter) {
		returnLongdan = new sgs::Derive::MLongDan(myPlayer(),
				(*cardIter).second);
		printDebug(sgsui::messageInterpret(returnLongdan));
		printDebug("AIZhaoyun::useLongdanInShanOrNot: over");
		return returnLongdan;
	}
	return returnLongdan;
}

const CardVec& AIZhaoyun::shaCard() {
	shaVec.clear();
	const sgs::DataType::Card * card = 0;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		card = myPlayer()->hand(i);
		if (card->type() == sgs::ConstData::SHA) {
			shaVec.push_back(cardPair(card, i));
		}
	}
	return shaVec;
}

const CardVec& AIZhaoyun::shanCard() {
	shanVec.clear();
	const sgs::DataType::Card * card = 0;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		card = myPlayer()->hand(i);
		if (card->type() == sgs::ConstData::SHAN) {
			shanVec.push_back(cardPair(card, i));
		}
	}
	return shanVec;
}

} /* namespace sgsai */
