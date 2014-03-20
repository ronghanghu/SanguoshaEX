/*
 * sgsai_AICaocao.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AICaocao.h"
#include "sgsui_output.h"
#include "sgsdata_card.h"
#include "sgsdata_skill.h"
#include "sgsdata_player.h"
#include "sgsdata_msg.h"
#include "sgsdata_extern.h"
#include "sgsdata_gamedata.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"

namespace sgsai {

AICaocao::AICaocao(int seat) :
		AICommon(seat) {
}

bool AICaocao::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AICaocao::useSkillOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;
	printDebug(
			"AICaocao::useSkillOrNot: over, return "
					+ QString(returnValue ? "true" : "false"));
	return returnValue;
}

sgs::DataType::Message * AICaocao::shanOrNot(sgs::DataType::Player * from,
		const sgs::DataType::Card * card) {
	sgs::Derive::MSkill * hujia = useHujiaInShanOrNot();
	if (hujia) {
		printDebug(sgsui::messageInterpret(hujia));
		printDebug(
				"AICaocao::shanOrNot: use hujia, AI's seat = "
						+ QString::number(mySeat()));
		return hujia;
	}
	return AICommon::shanOrNot(from, card);
}

sgs::Derive::MSkill * AICaocao::useHujiaInShanOrNot() {
	sgs::Derive::MSkill * returnHujia = 0;
	if (myPlayer()->role() != sgs::ConstData::ZHU) {
		return returnHujia;
	}

	using sgs::ExternData::gamedata;
	sgs::ConstData::HeroSide side;
	for (int i = 0; i < gamedata.playernum(); ++i) {
		side = gamedata.players(i)->side();
		if (side == sgs::ConstData::WEI) {
			returnHujia = new sgs::Derive::MSkill(myPlayer(),
					sgs::ConstData::HUJIA);
			break;
		}
	}
	return returnHujia;
}

} /* namespace sgsai */
