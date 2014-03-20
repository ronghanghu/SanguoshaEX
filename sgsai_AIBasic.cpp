/*
 * sgsai_AIBasic.cpp
 *
 *  Created on: May 5, 2012
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

namespace sgsai {

const std::pair<sgs::DataType::Player *, sgs::DataType::Player *> AIBasic::invalidJiedaoPair(
		(sgs::DataType::Player *) 0, (sgs::DataType::Player *) 0);

AIBasic::AIBasic(int seat) :
		QObject(sgsui::MainWindow::mainWindowPtr()), Interface(seat), _lord(0) {
}

std::vector<int> AIBasic::discardCard(unsigned int cardNumToDiscard) {
	printDebug(
			"AIBasic::discardCard: start, AI's seat = "
					+ QString::number(mySeat()));

	std::vector<int> returnValue;

	printDebug(
			"AIBasic::useCardResponse: discard cards other than sha, shan, tao and wuxie");
	sgs::ConstData::CardType type;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		type = myPlayer()->hand(i)->type();
		if (type != sgs::ConstData::SHA && type != sgs::ConstData::SHAN
				&& type != sgs::ConstData::TAO
				&& type != sgs::ConstData::WUXIE) {
			returnValue.push_back(i);
			if (returnValue.size() >= cardNumToDiscard) {
				printDebug(sgsui::discardInterpret(returnValue, myPlayer()));
				printDebug("AIBasic::discardCard: over");
				return returnValue;
			}
		}
	}

	printDebug("AIBasic::useCardResponse: discard sha");
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::SHA) {
			returnValue.push_back(i);
			if (returnValue.size() >= cardNumToDiscard) {
				printDebug(sgsui::discardInterpret(returnValue, myPlayer()));
				printDebug("AIBasic::discardCard: over");
				return returnValue;
			}
		}
	}

	printDebug("AIBasic::useCardResponse: discard shan and wuxie");
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::SHAN
				|| myPlayer()->hand(i)->type() == sgs::ConstData::WUXIE) {
			returnValue.push_back(i);
			if (returnValue.size() >= cardNumToDiscard) {
				printDebug(sgsui::discardInterpret(returnValue, myPlayer()));
				printDebug("AIBasic::discardCard: over");
				return returnValue;
			}
		}
	}

	printDebug("AIBasic::useCardResponse: discard tao");
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::TAO) {
			returnValue.push_back(i);
			if (returnValue.size() >= cardNumToDiscard) {
				printDebug(sgsui::discardInterpret(returnValue, myPlayer()));
				printDebug("AIBasic::discardCard: over");
				return returnValue;
			}
		}
	}

	printDebug(sgsui::discardInterpret(returnValue, myPlayer()));
	printDebug("AIBasic::discardCard: over");
	return returnValue;
}

sgs::DataType::Message * AIBasic::useCardResponse() {
	printDebug(
			"AIBasic::useCardResponse: start, AI's seat = "
					+ QString::number(mySeat()));

	sgs::Derive::MCard * returnMessage = 0;

	if (!returnMessage) {
		printDebug("AIBasic::useCardResponse: trying to use zhangba");
		returnMessage = useZhangba();
	}

	if (!returnMessage) {
		printDebug("AIBasic::useCardResponse: trying to use equip");
		returnMessage = installEquip();
	}

	if (!returnMessage) {
		printDebug(
				"AIBasic::useCardResponse: trying to use jinnang (not wuxie)");
		returnMessage = useJinnang();
	}

	if (!returnMessage) {
		printDebug("AIBasic::useCardResponse: trying to use tao");
		returnMessage = useTao();
	}

	if (!returnMessage) {
		printDebug("AIBasic::useCardResponse: trying to use sha");
		returnMessage = useSha();
	}

	if (!returnMessage) {
		printDebug("AIBasic::useCardResponse: no suitable card to use");
	}
	printDebug(sgsui::messageInterpret(returnMessage));
	printDebug("AIBasic::useCardResponse: over");
	return returnMessage;
}

sgs::DataType::Message * AIBasic::taoOrNot(sgs::DataType::Player * from,
		int /*neededTaoNumber*/) {
	printDebug(
			"AIBasic::taoOrNot: start, AI's seat = "
					+ QString::number(mySeat()));

	sgs::Derive::MCard * returnMessage = 0;

	if (from != myPlayer()) {
		sgs::ConstData::PlayerRole myRole = myPlayer()->role(), fromRole =
				from->role();
		bool shouldNotSave = false;
		if ((myRole == sgs::ConstData::ZHU || myRole == sgs::ConstData::ZHONG)
				&& fromRole == sgs::ConstData::FAN) {
			shouldNotSave = true;
		} else if (myRole == sgs::ConstData::FAN
				|| fromRole == sgs::ConstData::ZHONG) {
			shouldNotSave = true;
		}
		if (shouldNotSave || !isMyFriend(from)) {
			returnMessage = 0;
			printDebug(sgsui::messageInterpret(returnMessage));
			printDebug("AIBasic::taoOrNot: over");
			return returnMessage;
		}
	}

	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::TAO) {
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i, from);
			printDebug(sgsui::messageInterpret(returnMessage));
			printDebug("AIBasic::taoOrNot: over");
			return returnMessage;
		}
	}

	printDebug("AIBasic::taoOrNot: no tao to use. response cancelled");
	returnMessage = 0;
	printDebug(sgsui::messageInterpret(returnMessage));
	printDebug("AIBasic::taoOrNot: over");
	return returnMessage;
}

sgs::DataType::Message * AIBasic::shanOrNot(sgs::DataType::Player * /*from*/,
		const sgs::DataType::Card * /*card*/) {
	printDebug(
			"AIBasic::shanOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	sgs::Derive::MCard * returnMessage = 0;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::SHAN) {
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			printDebug(sgsui::messageInterpret(returnMessage));
			printDebug("AIBasic::shanOrNot: over");
			return returnMessage;
		}
	}

	printDebug("AIBasic::shanOrNot: no shan to use. response cancelled");
	returnMessage = 0;
	printDebug(sgsui::messageInterpret(returnMessage));
	printDebug("AIBasic::shanOrNot: over");
	return returnMessage;
}

sgs::DataType::Message * AIBasic::shanOrNot(sgs::DataType::Player * from,
		sgs::ConstData::HeroSkill skillType) {
	printDebug(
			"AIBasic::shanOrNot (skill version): start, AI's seat = "
					+ QString::number(mySeat()));

	if (skillType != sgs::ConstData::HUJIA) {
		printDebug(
				"<font color=red><b>Warning: </b></font>AIBasic::shanOrNot (skill version): skill is not HUJIA");
	}

	sgs::Derive::MCard * returnMessage = 0;
	if (!isMyFriend(from)) {
		printDebug(sgsui::messageInterpret(returnMessage));
		printDebug(
				"AIBasic::shanOrNot (skill version): from-player is not my friend");
		printDebug("AIBasic::shanOrNot (skill version): over");
		return returnMessage;
	}

	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::SHAN) {
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			printDebug(sgsui::messageInterpret(returnMessage));
			printDebug("AIBasic::shanOrNot (skill version): over");
			return returnMessage;
		}
	}

	printDebug(
			"AIBasic::shanOrNot (skill version): no shan to use. response cancelled");
	returnMessage = 0;
	printDebug(sgsui::messageInterpret(returnMessage));
	printDebug("AIBasic::shanOrNot (skill version): over");
	return returnMessage;
}

sgs::DataType::Message * AIBasic::shaOrNot(sgs::DataType::Player * /*from*/,
		const sgs::DataType::Card * /*card*/) {
	printDebug(
			"AIBasic::shaOrNot: start, AI's seat = "
					+ QString::number(mySeat()));
	sgs::Derive::MCard * returnMessage = 0;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::SHA) {
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			printDebug(sgsui::messageInterpret(returnMessage));
			printDebug("AIBasic::shaOrNot: over");
			return returnMessage;
		}
	}

	if (!returnMessage) {
		printDebug("AIBasic::shaOrNot: trying to use zhangba");
		returnMessage = useZhangba();
	}

	printDebug("AIBasic::shaOrNot: no sha to use. response cancelled");
	returnMessage = 0;
	printDebug(sgsui::messageInterpret(returnMessage));
	printDebug("AIBasic::shaOrNot: over");
	return returnMessage;
}

sgs::DataType::Message * AIBasic::shaOrNot(sgs::DataType::Player * from,
		sgs::ConstData::HeroSkill skillType) {
	printDebug(
			"AIBasic::shaOrNot (skill version): start, AI's seat = "
					+ QString::number(mySeat()));

	if (skillType != sgs::ConstData::RENDE) {
		printDebug(
				"<font color=red><b>Warning: </b></font>AIBasic::shaOrNot (skill version): skill is not RENDE");
	}

	sgs::Derive::MCard * returnMessage = 0;
	if (!isMyFriend(from)) {
		printDebug(sgsui::messageInterpret(returnMessage));
		printDebug(
				"AIBasic::shaOrNot (skill version): from-player is not my friend");
		printDebug("AIBasic::shaOrNot (skill version): over");
		return returnMessage;
	}

	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (myPlayer()->hand(i)->type() == sgs::ConstData::SHA) {
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			printDebug(sgsui::messageInterpret(returnMessage));
			printDebug("AIBasic::shaOrNot (skill version): over");
			return returnMessage;
		}
	}

	printDebug(
			"AIBasic::shaOrNot (skill version): no sha to use. response cancelled");
	returnMessage = 0;
	printDebug(sgsui::messageInterpret(returnMessage));
	printDebug("AIBasic::shaOrNot (skill version): over");
	return returnMessage;
}

bool AIBasic::useSkillOrNot(sgs::ConstData::HeroSkill skillType,
		sgs::DataType::Message * message) {
	QString text(
			"<font color=red><b>Warning: </b></font>AIBasic::useSkillOrNot: this function should not be called. ");
	text.append(" skill: ");
	text.append(sgsui::skillDisplayName(skillType));
	text.append(" message: ");
	text.append(sgsui::allMessageInterpret(message));
	printDebug(text);
	return true;
}

sgs::Derive::MCard * AIBasic::installEquip() {
	sgs::Derive::MCard * returnMessage = 0;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		if (sgsui::getEquipType(myPlayer()->hand(i)->type()) == NotEquip)
			continue;

		// TODO how to sort which weapon is better
		returnMessage = new sgs::Derive::MCard(false, myPlayer(),
				sgs::ConstData::PHAND, i);
		return returnMessage;
	}
	return returnMessage;
}

sgs::Derive::MCard * AIBasic::useTao() {
	sgs::Derive::MCard * returnMessage = 0;

	if (myPlayer()->hp() < myPlayer()->maxHP()) {
		bool hasPreserved = false;
		for (int i = 0; i < myPlayer()->handnum(); ++i) {
			if (myPlayer()->hand(i)->type() == sgs::ConstData::TAO) {

				// if the lord's hp is 1 or 2, and me (zhongchen)'s hp is above 2
				// and I (zhongchen) have not preserved tao for lord
				// then skip to preserve tao for lord
				if (myPlayer()->role() == sgs::ConstData::ZHONG
						&& myPlayer()->hp() > 2 && lord()->hp() < 3
						&& !hasPreserved) {
					hasPreserved = true;
					printDebug("AIBasic::useTao: preserved Tao for lord");
					continue; // Do Nothing to keep the Tao for lord
				}
				returnMessage = new sgs::Derive::MCard(false, myPlayer(),
						sgs::ConstData::PHAND, i, myPlayer());
				return returnMessage;
			}
		}
	}
	return returnMessage;
}

sgs::Derive::MCard * AIBasic::useSha() {
	sgs::Derive::MCard * returnMessage = 0;

	if (!canUseSha())
		return returnMessage;

	// the player at back is most threatening
	const PlayerVec& attackTargetVec = shaTarget();
	if (!attackTargetVec.empty()) {
		// use sha
		for (int i = 0; i < myPlayer()->handnum(); ++i) {
			if (myPlayer()->hand(i)->type() == sgs::ConstData::SHA) {
				if (canUseFangtian() && attackTargetVec.size() > 1) {
					printDebug("AIBasic::useSha: using fangtian");
					returnMessage = new sgs::Derive::MCard(false, myPlayer(),
							sgs::ConstData::PHAND, i);

					// push in the fisrt 3 enemies;
					int j = 0;
					PlayerVec arrangedTargets;
					for (PlayerVec::const_iterator iter =
							attackTargetVec.begin();
							iter != attackTargetVec.end() && j < 3;
							++iter, ++j) {
						arrangedTargets.push_back(*iter);
					}

					// sort the targets by seat;
					sgsui::PlayerSort arrangeSeat(mySeat(), sgsui::BySeat);
					std::sort(arrangedTargets.begin(), arrangedTargets.end(),
							arrangeSeat);
					for (PlayerVec::const_iterator iter =
							arrangedTargets.begin();
							iter != arrangedTargets.end(); ++iter) {
						returnMessage->addto(*iter);
					}
				} else {
					printDebug("AIBasic::useSha: not using fangtian");

					// Do not use black Sha to Renwang
					// try each player in range
					for (PlayerVec::const_reverse_iterator riter =
							attackTargetVec.rbegin();
							riter != attackTargetVec.rend(); ++riter) {
						sgs::DataType::Player * target = *riter;

						sgs::ConstData::CardColor color =
								myPlayer()->hand(i)->color();
						bool isBlackSha = (color == sgs::ConstData::CLUB
								|| color == sgs::ConstData::SPADE);
						bool enemyHasRenwang = (target->armor()
								&& (target->armor()->type()
										== sgs::ConstData::RENWANG));
						const sgs::DataType::Card * myWeapon =
								myPlayer()->weapon();
						bool renwangEffective = !myWeapon
								|| myWeapon->type() != sgs::ConstData::QINGGANG;

						if (!isBlackSha || !enemyHasRenwang
								|| !renwangEffective) {
							returnMessage = new sgs::Derive::MCard(false,
									myPlayer(), sgs::ConstData::PHAND, i,
									target);
							printDebug(
									"AIBasic::useSha: will attack player "
											+ QString::number(target->seat())
											+ ", break and stop searching for target");
							break;
						} else {
							printDebug(
									"AIBasic::useSha: skip player "
											+ QString::number(target->seat())
											+ " due to renwang, going to try next player");
						}
					}
				}
				return returnMessage;
			}
		}
	}
	return returnMessage;
}

sgs::Derive::MCard * AIBasic::useJinnang() {
	sgs::Derive::MCard * returnMessage = 0;
	using namespace sgs::ConstData;
	for (int i = 0; i < myPlayer()->handnum(); ++i) {
		const sgs::ConstData::CardType currentJinnang =
				myPlayer()->hand(i)->type();

		if (!sgsui::isJinnangCard(currentJinnang))
			continue;

		if (currentJinnang == WUXIE)
			continue;

		printDebug(
				"AIBasic::useJinnang: trying to use jinnang "
						+ sgsui::cardFullDisplayName(myPlayer()->hand(i), false));
		switch (currentJinnang) {
		case SHANDIAN:
			if (!hasShandianInJudge(myPlayer())) {
				returnMessage = new sgs::Derive::MCard(false, myPlayer(),
						sgs::ConstData::PHAND, i, myPlayer());
			}
			break;
		case SHUNQIAN: {
			PlayerVec enemyVec(shunqianTarget());
			if (!enemyVec.empty())
				returnMessage = new sgs::Derive::MCard(false, myPlayer(),
						sgs::ConstData::PHAND, i, enemyVec.back());
		}
			break;
		case GUOCHAI: {
			const PlayerVec& enemyVec = guochaiTarget();
			if (!enemyVec.empty())
				returnMessage = new sgs::Derive::MCard(false, myPlayer(),
						sgs::ConstData::PHAND, i, enemyVec.back());
		}
			break;
		case JIEDAO: {
			PlayerVec weaponOwnerVec(shunqianTarget());

			std::pair<sgs::DataType::Player *, sgs::DataType::Player *> jiedaoPair =
					makeJiedaoPair();
			if (jiedaoPair != invalidJiedaoPair) {
				returnMessage = new sgs::Derive::MCard(false, myPlayer(),
						sgs::ConstData::PHAND, i);
				// the first is the attacker and the second is the victim
				returnMessage->addto(jiedaoPair.second);
				returnMessage->addto(jiedaoPair.first);
			}
		}
			break;
			// TODO reconsider whether to use this card
		case JUEDOU: {
			const PlayerVec& enemyVec = juedouTarget();
			if (!enemyVec.empty())
				returnMessage = new sgs::Derive::MCard(false, myPlayer(),
						sgs::ConstData::PHAND, i, enemyVec.back());
		}
			break;
		case WANJIAN:
			// TODO reconsider whether to use this card
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			break;
		case NANMAN:
			// TODO reconsider whether to use this card
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			break;
		case TAOYUAN:
			// TODO reconsider whether to use this card
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			break;
		case WUGU:
			// TODO reconsider whether to use this card
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			break;
		case WUZHONG:
			returnMessage = new sgs::Derive::MCard(false, myPlayer(),
					sgs::ConstData::PHAND, i);
			break;
		case SISHU: {
			const PlayerVec& enemyVec = sishuTarget();
			if (!enemyVec.empty())
				returnMessage = new sgs::Derive::MCard(false, myPlayer(),
						sgs::ConstData::PHAND, i, enemyVec.back());
		}
			break;
		default:
			printDebug(
					"<font color=red><b>Warning: </b></font>AIBasic::useJinnang: jinnang type handled by default!");
			break;
		}

		// if jinnang used, escape loop and stop searching next card
		if (returnMessage) {
			break;
		} else {
			printDebug(
					"AIBasic::useJinnang: cannot use "
							+ sgsui::cardDisplayName(currentJinnang)
							+ ", skip");
		}
	}
	return returnMessage;
}

sgs::Derive::MCard * AIBasic::useZhangba() {
	sgs::Derive::MCard * returnMessage = 0;
	if (canUseZhangba()) {
		const PlayerVec& attackTargetVec = shaTarget();
		if (!attackTargetVec.empty()) {
			returnMessage = new sgs::Derive::MCard(true, myPlayer(),
					sgs::ConstData::PEQUIP, 0, attackTargetVec.back());
		}
	}
	return returnMessage;
}

} /* namespace sgsai */
