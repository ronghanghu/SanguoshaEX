/*
 * sgsai_AIBasic_Algorithm.cpp
 *
 *  Created on: Jun 28, 2012
 *      Author: latios
 */

#include "sgsai_AIBasic.h"
#include "sgsui_MainWindow.h"
#include "sgsui_PlayerSort.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include "sgsdata_enum.h"
#include "sgsdata_msg.h"
#include "sgsdata_player.h"
#include "sgsdata_card.h"
#include "sgsdata_extern.h"
#include "sgsdata_gamedata.h"
#include <algorithm>

namespace sgsai {

const PlayerVec& AIBasic::shaTarget() {
	shaTargetVec.clear();
	using sgs::ExternData::gamedata;
	sgs::DataType::Player * enemy = 0;

	for (int i = 0; i < gamedata.playernum(); ++i) {
		if (i == mySeat())
			continue;

		enemy = gamedata.players(i);
		if (enemy->status() & sgs::ConstData::DEAD)
			continue;

		// zhugeliang cannot be the target of sha if he has no handcards
		if (enemy->type() == sgs::ConstData::LAOZHUGE && enemy->handnum() == 0)
			continue;

		if (!isMyFriend(enemy)
				&& (myPlayer()->distance(enemy) <= myPlayer()->range())) {
			shaTargetVec.push_back(enemy);
		}
	}

	sgsui::PlayerSort arrange(mySeat(), sgsui::ByThreat);
	std::sort(shaTargetVec.begin(), shaTargetVec.end(), arrange);

	return shaTargetVec;
}

const PlayerVec& AIBasic::juedouTarget() {
	juedouTargetVec.clear();
	using sgs::ExternData::gamedata;
	sgs::DataType::Player * enemy = 0;
	for (int i = 0; i < gamedata.playernum(); ++i) {
		if (i == mySeat())
			continue;

		enemy = gamedata.players(i);
		if (enemy->status() & sgs::ConstData::DEAD)
			continue;

		// zhugeliang cannot be the target of juedou if he has no handcards
		if (enemy->type() == sgs::ConstData::LAOZHUGE && enemy->handnum() == 0)
			continue;

		if (!isMyFriend(enemy)) {
			juedouTargetVec.push_back(enemy);
		}
	}
	sgsui::PlayerSort arrange(mySeat(), sgsui::ByThreat);
	std::sort(juedouTargetVec.begin(), juedouTargetVec.end(), arrange);

	return juedouTargetVec;
}

const PlayerVec& AIBasic::sishuTarget() {
	sishuTargetVec.clear();
	using sgs::ExternData::gamedata;
	sgs::DataType::Player * enemy = 0;

	for (int i = 0; i < gamedata.playernum(); ++i) {
		if (i == mySeat())
			continue;

		enemy = gamedata.players(i);
		if (enemy->type() == sgs::ConstData::LUXUN)
			continue;
		if (enemy->status() & sgs::ConstData::DEAD)
			continue;

		if (!isMyFriend(enemy) && !hasSishuInJudge(enemy)) {
			sishuTargetVec.push_back(enemy);
		}
	}

	sgsui::PlayerSort arrange(mySeat(), sgsui::ByThreat);
	std::sort(sishuTargetVec.begin(), sishuTargetVec.end(), arrange);

	return sishuTargetVec;
}

const PlayerVec& AIBasic::guochaiTarget() {
	guochaiTargetVec.clear();
	using sgs::ExternData::gamedata;
	sgs::DataType::Player * enemy = 0;

	for (int i = 0; i < gamedata.playernum(); ++i) {
		if (i == mySeat())
			continue;

		enemy = gamedata.players(i);
		if (enemy->status() & sgs::ConstData::DEAD)
			continue;

		// Don't guochai enemy's judge card
		if (!isMyFriend(enemy)
				&& (totalCardNum(enemy) - enemy->judgenum() > 0)) {
			printDebug(
					"AIBasic::guochaiTarget: spoted target, seat = "
							+ QString::number(i));
			guochaiTargetVec.push_back(enemy);
		}
	}

	sgsui::PlayerSort arrange(mySeat(), sgsui::ByThreat);
	std::sort(guochaiTargetVec.begin(), guochaiTargetVec.end(), arrange);

	return guochaiTargetVec;
}

PlayerVec AIBasic::shunqianTarget() {
	using sgs::ExternData::gamedata;
	sgs::DataType::Player * enemy = 0;

	// the player at back is most threatening
	PlayerVec targetVec;

	for (int i = 0; i < gamedata.playernum(); ++i) {
		if (i == mySeat())
			continue;

		enemy = gamedata.players(i);
		if (enemy->type() == sgs::ConstData::LUXUN)
			continue;
		if (enemy->status() & sgs::ConstData::DEAD)
			continue;

		// Don't shunqian enemy's judge card
		if (!isMyFriend(enemy) && (totalCardNum(enemy) - enemy->judgenum() > 0)
				&& ((myPlayer()->distance(enemy) <= 1)
						|| myPlayer()->type() == sgs::ConstData::HUANGYUEYING)) {
			printDebug(
					"AIBasic::shunqianTarget: spoted target, seat = "
							+ QString::number(i));
			targetVec.push_back(enemy);
		}
	}

	sgsui::PlayerSort arrange(mySeat(), sgsui::ByThreat);
	std::sort(targetVec.begin(), targetVec.end(), arrange);

	return targetVec;
}

PlayerVec AIBasic::playersHavingWeapon() {
	using sgs::ExternData::gamedata;
	sgs::DataType::Player * weaponOwner = 0;

	// the player at back is most threatening
	PlayerVec weaponOwnerVec;

	for (int i = 0; i < gamedata.playernum(); ++i) {
		if (i == mySeat())
			continue;

		weaponOwner = gamedata.players(i);
		if (weaponOwner->status() & sgs::ConstData::DEAD)
			continue;

		if (weaponOwner->weapon()) {
			printDebug(
					"AIBasic::playersHavingWeapon: spoted weapon owner, seat = "
							+ QString::number(i));
			weaponOwnerVec.push_back(weaponOwner);
		}
	}

	// sort it, so enemis are at back and friends are at front
	sgsui::PlayerSort arrange(mySeat(), sgsui::ByThreat);
	std::sort(weaponOwnerVec.begin(), weaponOwnerVec.end(), arrange);

	return weaponOwnerVec;
}

PlayerVec AIBasic::jiedaoTarget(sgs::DataType::Player * weaponWwner) {
	using sgs::ExternData::gamedata;

	sgs::DataType::Player * target;
	// the player at back is most threatening
	PlayerVec targetVec;

	for (int i = 0; i < gamedata.playernum(); ++i) {

		// skip the weapon owner
		if (i == weaponWwner->seat())
			continue;

		target = gamedata.players(i);
		if (target->status() & sgs::ConstData::DEAD)
			continue;

		if (weaponWwner->range() >= weaponWwner->distance(target)) {
			printDebug(
					"AIBasic::jiedaoTarget: spoted target, seat = "
							+ QString::number(i));
			targetVec.push_back(target);
		}
	}

	// sort it, so enemis are at back and friends are at front
	sgsui::PlayerSort arrange(mySeat(), sgsui::ByThreat);
	std::sort(targetVec.begin(), targetVec.end(), arrange);

	return targetVec;
}

std::pair<sgs::DataType::Player *, sgs::DataType::Player *> AIBasic::makeJiedaoPair() {
	PlayerVec attackerVec(playersHavingWeapon());
	if (attackerVec.empty())
		return invalidJiedaoPair;

	for (PlayerVec::const_iterator iter = attackerVec.begin();
			iter != attackerVec.end(); ++iter) {

		PlayerVec victimVec(jiedaoTarget(*iter));

		if (!victimVec.empty())
			return std::pair<sgs::DataType::Player *, sgs::DataType::Player *>(
					*iter, victimVec.back());
	}
	return invalidJiedaoPair;
}

sgs::DataType::Player * AIBasic::lord() {
	printDebug("AIBasic::lord");

	// when lord has not been marked, pick it out first
	if (!_lord) {
		sgs::DataType::Player * player = 0;
		using sgs::ExternData::gamedata;
		for (int i = 0; i < gamedata.playernum(); ++i) {
			player = gamedata.players(i);
			if (player->role() == sgs::ConstData::ZHU) {
				_lord = player;
				break;
			}
		}
	}

	// return the lord player pointer only when the lord is alive
	// maybe it is unnecessary because game is over when to lord is killed
	// but to be careful, keep it
	return (isDead(_lord) ? 0 : _lord);
}

bool AIBasic::isMyFriend(sgs::DataType::Player * player) const {
	using namespace sgs::ConstData;

	if (!player) {
		printDebug(
				"<font color=red><b>Warning: </b></font>AIBasic::isMyFriend: null pointer");
		return false;
	}
	switch (myPlayer()->role()) {
	case ZHU:
	case ZHONG:
		switch (player->role()) {
		case ZHU:
		case ZHONG:
			return true;
		case NEI:
			return !isAllFanzeiDead();
		case FAN:
			return false;
		default:
			break;
		}
		break;
	case NEI:
		switch (player->role()) {
		case ZHU:
		case ZHONG:
			return !isAllFanzeiDead();
		case NEI:
			return true;
		case FAN:
			return false;
		default:
			break;
		}
		break;
	case FAN:
		switch (player->role()) {
		case ZHU:
		case ZHONG:
		case NEI:
			return false;
		case FAN:
			return true;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return true;
}

bool AIBasic::isAllFanzeiDead() const {
	using sgs::ExternData::gamedata;
	using namespace sgs::ConstData;
	PlayerRole role;
	for (int i = 0; i < gamedata.playernum(); ++i) {

		// skip the dead players
		if (isDead(i))
			continue;

		role = gamedata.players(i)->role();
		if (role == FAN)
			return false;
	}
	return true;
}

} /* namespace sgsai */
