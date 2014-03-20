/*
 * sgsai_AIGuanyu.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AIGuanyu.h"
#include "sgsui_output.h"
#include "sgsdata_card.h"
#include "sgsdata_skill.h"
#include "sgsdata_player.h"
#include "sgsdata_msg.h"
#include "sgsui_PlayerSort.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"

namespace sgsai {

AIGuanyu::AIGuanyu(int seat) :
		AICommon(seat) {
}

bool AIGuanyu::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AIGuanyu::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	printDebug(
			"<font color=red><b>Warning: </b></font>AIGuanyu::useSkillOrNot: shouldn't be called becase guanyu has no passive skill");
	bool returnValue = true;
	printDebug(
			"AIGuanyu::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

sgs::DataType::Message * AIGuanyu::useCardResponse() {
	sgs::Derive::MSkill * wusheng = useWushengInUsecard();
	if (wusheng) {
		printDebug(sgsui::messageInterpret(wusheng));
		printDebug(
				"AIGuanyu::useCardResponse: use wusheng, AI's seat = "
						+ QString::number(mySeat()));
		return wusheng;
	}
	return AICommon::useCardResponse();
}

sgs::DataType::Message * AIGuanyu::shaOrNot(sgs::DataType::Player * from,
		const sgs::DataType::Card * card) {
	sgs::Derive::MSkill * wusheng = useWushengInShaOrNot();
	if (wusheng) {
		printDebug(sgsui::messageInterpret(wusheng));
		printDebug(
				"AIGuanyu::shaOrNot: use wusheng, AI's seat = "
						+ QString::number(mySeat()));
		return wusheng;
	}
	return AICommon::shaOrNot(from, card);
}

sgs::Derive::MSkill * AIGuanyu::useWushengInUsecard() {
	sgs::Derive::MWuSheng * returnWusheng = 0;
	if (!canUseSha())
		return returnWusheng;

	const CardVec& redShoupaiFound = redShoupai();
	if (redShoupaiFound.empty()) {
		printDebug("AIGuanyu::useWusheng: no red card");
		return returnWusheng;
	}

	PlayerVec attackTargetVec = shaTarget();
	if (attackTargetVec.empty()) {
		for (CardVec::const_iterator cardIter = redShoupaiFound.begin();
				cardIter != redShoupaiFound.end(); ++cardIter) {

			if (canUseFangtian() && attackTargetVec.size() > 1) {
				printDebug("AIGuanyu::useWusheng: using fangtian");
				returnWusheng = new sgs::Derive::MWuSheng(myPlayer(),
						sgs::ConstData::PHAND, (*cardIter).second);

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
					returnWusheng->addto(*iter);
				}
			} else {
				printDebug("AIGuanyu::useWusheng: not using fangtian");

				// Do not use black Sha to Renwang
				// try each player in range
				for (PlayerVec::reverse_iterator riter =
						attackTargetVec.rbegin();
						riter != attackTargetVec.rend(); ++riter) {
					sgs::DataType::Player * target = *riter;

					returnWusheng = new sgs::Derive::MWuSheng(myPlayer(),
							sgs::ConstData::PHAND, (*cardIter).second, target);
					printDebug(
							"AIGuanyu::useWusheng: will attack player "
									+ QString::number(target->seat())
									+ ", break and stop searching for target");
					break;
				}
			}
			return returnWusheng;
		}
	}
	return returnWusheng;
}

sgs::Derive::MSkill * AIGuanyu::useWushengInShaOrNot() {
	sgs::Derive::MWuSheng * returnWusheng = 0;

	const CardVec& redShoupaiFound = redShoupai();
	if (redShoupaiFound.empty()) {
		printDebug("AIGuanyu::useWushengInShaOrNot: no red card");
		return returnWusheng;
	}

	for (CardVec::const_iterator cardIter = redShoupaiFound.begin();
			cardIter != redShoupaiFound.end(); ++cardIter) {
		returnWusheng = new sgs::Derive::MWuSheng(myPlayer(),
				sgs::ConstData::PHAND, (*cardIter).second);
		printDebug(sgsui::messageInterpret(returnWusheng));
		printDebug("AIGuanyu::useWushengInShaOrNot: over");
		return returnWusheng;
	}
	return returnWusheng;
}

const CardVec& AIGuanyu::redShoupai() {
	redShoupaiVec.clear();
	const sgs::DataType::Card * card = 0;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		card = myPlayer()->hand(i);
		if (card->color() == sgs::ConstData::HEART
				|| card->color() == sgs::ConstData::DIAMOND) {
			redShoupaiVec.push_back(cardPair(card, i));
		}
	}
	return redShoupaiVec;
}

} /* namespace sgsai */
