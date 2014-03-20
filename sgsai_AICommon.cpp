/*
 * sgsai_AICommon.cpp
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#include "sgsai_AICommon.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include "sgsdata_player.h"
#include "sgsdata_msg.h"
#include "sgsdata_card.h"
#include <algorithm>
#include <cstdlib>

namespace sgsai {

AICommon::AICommon(int seat) :
		AIBasic(seat) {
}

void AICommon::chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
		std::vector<const sgs::DataType::Card *>& buttom) {
	printDebug(
			"<font color=red><b>Warning: </b></font>AICommon::chooseGuanxing: this function should not be called");
}

bool AICommon::useEquipOrNot(sgs::ConstData::CardType equipCardType,
		sgs::DataType::Player *targetPlayer) {
	printDebug(
			"AICommon::useEquipOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	bool returnValue = true;

	if (equipCardType == sgs::ConstData::HANBING
			&& (!targetPlayer->weapon() || !targetPlayer->armor()
					|| targetPlayer->hp() == 1)) {
		returnValue = false;
	}
	printDebug("AICommon::useEquipOrNot: over");
	return returnValue;
}

std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > AICommon::chooseCardResponse(
		sgs::DataType::Player *targetPlayer, bool isHandSelectable,
		bool isEquipSelectable, bool isJudgeSelectable, int num,
		sgs::ConstData::CardType reason) {
	printDebug(
			"AIBasic::chooseCardResponse: start, AI's seat = "
					+ QString::number(mySeat()));
	std::vector < std::pair<sgs::ConstData::PlayerRegionType, int>
			> returnValue;
	int count = 0;

	if (isEquipSelectable) {

		if ((reason != sgs::ConstData::QILIN) && targetPlayer->armor()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 1));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug("AICommon::chooseCardResponse: over");
				return returnValue;
			}
		}
		if ((reason != sgs::ConstData::QILIN) && targetPlayer->weapon()
				&& (reason != sgs::ConstData::GUANSHI)) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 0));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug("AICommon::chooseCardResponse: over");
				return returnValue;
			}
		}

		// Note: the dfdhorse and atkhorse order are reversed intentionally
		// to accelerate the game
		if (targetPlayer->dfdhorse()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 3));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug("AICommon::chooseCardResponse: over");
				return returnValue;
			}
		}
		if (targetPlayer->atkhorse()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 2));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug("AICommon::chooseCardResponse: over");
				return returnValue;
			}
		}
	}

	std::vector<int> selectedHandVec, selectedJudgeVec;
	// just select the first handcards from the target player
	if (isHandSelectable) {
		for (int i = 0; i < targetPlayer->handnum() && count < num;
				++i, ++count) {
			selectedHandVec.push_back(i);
		}
	}

	// just select the first judgecards from the target player
	if (isJudgeSelectable) {
		for (int i = 0; i < targetPlayer->judgenum() && count < num;
				++i, ++count) {
			selectedJudgeVec.push_back(i);
		}
	}

	// sort them from big to small (use reverse iterator)
	std::sort(selectedHandVec.rbegin(), selectedHandVec.rend());
	std::sort(selectedJudgeVec.rbegin(), selectedJudgeVec.rend());
	for (std::vector<int>::iterator iter = selectedHandVec.begin();
			iter != selectedHandVec.end(); ++iter) {
		returnValue.push_back(
				std::pair<sgs::ConstData::PlayerRegionType, int>(
						sgs::ConstData::PHAND, *iter));
	}
	for (std::vector<int>::iterator iter = selectedJudgeVec.begin();
			iter != selectedJudgeVec.end(); ++iter) {
		returnValue.push_back(
				std::pair<sgs::ConstData::PlayerRegionType, int>(
						sgs::ConstData::PJUDGE, *iter));
	}

	printDebug(sgsui::selectInterpret(returnValue));
	printDebug("AICommon::chooseCardResponse: over");
	return returnValue;
}

std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > AICommon::chooseCardResponse(
		sgs::DataType::Player *targetPlayer, bool isHandSelectable,
		bool isEquipSelectable, bool isJudgeSelectable, int num,
		sgs::ConstData::HeroSkill reason) {
	printDebug(
			"AIBasic::chooseCardResponse (skill version): start, AI's seat = "
					+ QString::number(mySeat()));
	std::vector < std::pair<sgs::ConstData::PlayerRegionType, int>
			> returnValue;
	int count = 0;

	if (isEquipSelectable) {

		if (targetPlayer->armor()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 1));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug(
						"AICommon::chooseCardResponse (skill version): over");
				return returnValue;
			}
		}

		if (targetPlayer->weapon()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 0));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug(
						"AICommon::chooseCardResponse: (skill version) over");
				return returnValue;
			}
		}

		// Note: the dfdhorse and atkhorse order are reversed intentionally
		// to accelerate the game
		if (targetPlayer->dfdhorse()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 3));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug(
						"AICommon::chooseCardResponse (skill version): over");
				return returnValue;
			}
		}

		if (targetPlayer->atkhorse()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 2));
			++count;
			if (count == num) {
				printDebug(sgsui::selectInterpret(returnValue));
				printDebug(
						"AICommon::chooseCardResponse (skill version): over");
				return returnValue;
			}
		}
	} /*isEquipSelectable Over*/

	std::vector<int> selectedHandVec, selectedJudgeVec;
	// just select the first handcards from the target player
	if (isHandSelectable) {
		for (int i = 0; i < targetPlayer->handnum() && count < num;
				++i, ++count) {
			selectedHandVec.push_back(i);
		}
	}

	// just select the first judgecards from the target player
	if (isJudgeSelectable) {
		for (int i = 0; i < targetPlayer->judgenum() && count < num;
				++i, ++count) {
			selectedJudgeVec.push_back(i);
		}
	}

	// sort them from big to small (use reverse iterator)
	std::sort(selectedHandVec.rbegin(), selectedHandVec.rend());
	std::sort(selectedJudgeVec.rbegin(), selectedJudgeVec.rend());
	for (std::vector<int>::iterator iter = selectedHandVec.begin();
			iter != selectedHandVec.end(); ++iter) {
		returnValue.push_back(
				std::pair<sgs::ConstData::PlayerRegionType, int>(
						sgs::ConstData::PHAND, *iter));
	}
	for (std::vector<int>::iterator iter = selectedJudgeVec.begin();
			iter != selectedJudgeVec.end(); ++iter) {
		returnValue.push_back(
				std::pair<sgs::ConstData::PlayerRegionType, int>(
						sgs::ConstData::PJUDGE, *iter));
	}

	printDebug(sgsui::selectInterpret(returnValue));
	printDebug("AICommon::chooseCardResponse (skill version): over");
	return returnValue;
}

sgs::DataType::Message * AICommon::wuxieOrNot(
		sgs::DataType::Message * originMsg, int count) {

	printDebug(
			"AICommon::wuxieOrNot: start, AI's seat = "
					+ QString::number(mySeat()));

	sgs::Derive::MCard * messageToWuxie =
			static_cast<sgs::Derive::MCard *>(originMsg);
	sgs::Derive::MCard * returnMessage = 0;
	/*if (messageToWuxie->card()->type() == sgs::ConstData::WANJIAN
	 || messageToWuxie->card()->type() == sgs::ConstData::NANMAN) {

	 // TODO consider how to identify whether the current target is my friend
	 returnMessage = 0;

	 } else*/

	bool shouldNotWuxie = isMyFriend(messageToWuxie->from());
	if (count % 2 != 0)
		shouldNotWuxie = !shouldNotWuxie;
	if (sgsui::isJudgeCard(messageToWuxie->card()->type()))
		shouldNotWuxie = !shouldNotWuxie;

	if (shouldNotWuxie) {
		printDebug(sgsui::messageInterpret(returnMessage));
		printDebug("AICommon::wuxieOrNot: over");
		return returnMessage;
	}

	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::WUXIE) {

			// Do not add target in message
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			printDebug(sgsui::messageInterpret(returnMessage));
			printDebug("AICommon::wuxieOrNot: over");
			return returnMessage;
		}
		printDebug("AICommon::wuxieOrNot: no wuxie to use. response cancelled");
	}
	printDebug(sgsui::messageInterpret(returnMessage));
	printDebug("AICommon::wuxieOrNot: over");
	return returnMessage;
}

bool AICommon::yesOrNot(sgs::ConstData::CardType) {
	// TODO reconsider whether to let opponent choose card
	printDebug(
			"AICommon::yesOrNot(card version): start, AI's seat = "
					+ QString::number(mySeat()));
	bool result = true;
	printDebug(
			QString("AICommon::yesOrNot(card version): over, return ")
					+ (result ? "true" : "false"));
	return result;
}

bool AICommon::yesOrNot(sgs::ConstData::HeroSkill) {
	// TODO reconsider whether to let opponent choose card
	printDebug(
			"AICommon::yesOrNot(skill version): start, AI's seat = "
					+ QString::number(mySeat()));
	int result = true;
	printDebug(
			QString("AICommon::yesOrNot(skill version): over, return ")
					+ (result ? "true" : "false"));
	return result;
}

int AICommon::chooseWugu(
		const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wuguCards) {
	showWugu(wuguCards);

	// TODO reconsider whether to let opponent choose card
	printDebug(
			"AICommon::chooseWugu: start, AI's seat = "
					+ QString::number(mySeat()));

	int returnValue = -1;
	for (unsigned i = 0; i < wuguCards.size(); ++i) {
		if (wuguCards.at(i).second)
			continue;

		returnValue = i;
		break;
	}
	printDebug(
			"AICommon::chooseWugu: over, chosen card pos = "
					+ QString::number(returnValue));
	return returnValue;
}

sgs::DataType::Message * AICommon::getTuxi() {
	printDebug(
			"<font color=red><b>Warning: </b></font>AICommon::getTuxi: this function should not be called, it should be overrided in subclass");
	return 0;
}

sgs::DataType::Message * AICommon::getYiji(const sgs::DataType::Card * card1,
		const sgs::DataType::Card * card2) {
	printDebug(
			"<font color=red><b>Warning: </b></font>AICommon::getYiji: this function should not be called, it should be overrided in subclass");
	return 0;
}

sgs::DataType::Message * AICommon::getLiuli(sgs::DataType::Player * attacker) {
	printDebug(
			"<font color=red><b>Warning: </b></font>AICommon::getLiuli: this function should not be called, it should be overrided in subclass");
	return 0;
}

std::pair<sgs::ConstData::CardColor, int> AICommon::respondFanjian(
		sgs::DataType::Player * zhouyu) {
	sgs::ConstData::CardColor choosenColor;
	switch (rand() % 4) {
	case 0:
		choosenColor = sgs::ConstData::HEART;
		break;
	case 1:
		choosenColor = sgs::ConstData::DIAMOND;
		break;
	case 2:
		choosenColor = sgs::ConstData::SPADE;
		break;
	default:
		choosenColor = sgs::ConstData::CLUB;
		break;
	}
	if (zhouyu->handnum() <= 0) {
		printDebug(
				"<font color=red><b>Warning: </b></font>AICommon::respondFanjian: zhouyu doesn't have any handcards!");
	}
	return std::pair<sgs::ConstData::CardColor, int>(choosenColor, 0);
}

} /* namespace sgsai */
