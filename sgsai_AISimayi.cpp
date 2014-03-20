/*
 * sgsai_AISimayi.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AISimayi.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"
#include "sgsdata_msg.h"

namespace sgsai {

AISimayi::AISimayi(int seat) :
		AICommon(seat), judgeMessage(0) {
}

bool AISimayi::useSkillOrNot(sgs::ConstData::HeroSkill /*skillType*/,
		sgs::DataType::Player * /*player*/) {
	printDebug(
			"AISimayi::useSkillOrNot (fankui version): start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;
	printDebug("AISimayi::useSkillOrNot (fankui version): over");
	return returnValue;
}

bool AISimayi::useSkillOrNot(sgs::ConstData::HeroSkill skillType,
		sgs::DataType::Message * message) {
	printDebug(
			"AISimayi::useSkillOrNot (guicai version): start, AI's seat = "
					+ QString::number(mySeat()));

	bool returnValue = false;
	judgeMessage = dynamic_cast<sgs::Derive::MJudge *>(message);
	if (!judgeMessage) {
		printDebug(
				"<font color=red><b>Warning: </b></font>AISimayi::useSkillOrNot (guicai version): message type is not MJudge, message"
						+ sgsui::allMessageInterpret(message));
		printDebug("AISimayi::useSkillOrNot (guicai version): over");
		return returnValue;
	}

	printDebug("AISimayi::useSkillOrNot (guicai version): over");
	return returnValue;
}

std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > AISimayi::chooseCardResponse(
		sgs::DataType::Player *targetPlayer, bool isHandSelectable,
		bool isEquipSelectable, bool isJudgeSelectable, int num,
		sgs::ConstData::HeroSkill skill) {
	printDebug(
			"AISimayi::chooseCardResponse (skill version): start, AI's seat = "
					+ QString::number(mySeat()));
	if (skill != sgs::ConstData::GUICAI)
		return AICommon::chooseCardResponse(targetPlayer, isHandSelectable,
				isEquipSelectable, isJudgeSelectable, num, skill);

	printDebug("AISimayi::chooseCardResponse (skill version): over");

	// TODO revise it
	return AICommon::chooseCardResponse(targetPlayer, isHandSelectable,
			isEquipSelectable, isJudgeSelectable, num, skill);
}

} /* namespace sgsai */
