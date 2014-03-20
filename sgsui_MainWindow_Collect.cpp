/*
 * sgsui_MainWindow_Normalize.cpp
 *
 *  Created on: Jul 3, 2012
 *      Author: latios
 */

#include "sgsui_MainWindow.h"
#include "sgsui_Shoupai.h"
#include "sgsui_ZhuangbeiArea.h"
#include "sgsui_WujiangArea.h"
#include "sgsui_PlayerArea.h"
#include "sgsui_WugufengdengBox.h"
#include "sgsui_AudioPlayer.h"
#include "sgsui_CardContainer.h"
#include "sgsui_ZhuangbeiPic.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"
#include "sgsui_PlayerSort.h"
#include "sgsai_AIBasic.h"
#include "sgsdata_enum.h"
#include "sgsdata_msg.h"
#include "sgsdata_player.h"

namespace sgsui {

void MainWindow::enableAllShoupai() {
	for (std::list<Shoupai*>::iterator iter = shoupaiList.begin();
			iter != shoupaiList.end(); ++iter) {
		(*iter)->setSelectable();
		(*iter)->setUnselected();
	}
	selectedShoupaiList.clear();
}

void MainWindow::disableAllShoupai() {
	for (std::list<Shoupai*>::iterator iter = shoupaiList.begin();
			iter != shoupaiList.end(); ++iter) {
		(*iter)->setUnselectable();
	}
	selectedShoupaiList.clear();
}

void MainWindow::disableAllPlayers() {
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayerAreaAtIndex(i)->setUnselectable();
		}
	}
	selectedPlayerAreaList.clear();
}

void MainWindow::disableAllZhuangbei() {
	zhuangbeiA->setSelectable(0, false, true);
	zhuangbeiA->setSelectable(1, false, true);
	zhuangbeiA->setSelectable(2, false, true);
	zhuangbeiA->setSelectable(3, false, true);
	selectedZhuangbei = 0;
}

void MainWindow::clearCardPlayerEquipSelect() {
	unselectAllShoupai();
	unselectAllPlayers();
	unselectAllZhuangbei();
}

void MainWindow::unselectAllShoupai() {
	for (std::list<Shoupai*>::iterator iter = shoupaiList.begin();
			iter != shoupaiList.end(); ++iter) {
		(*iter)->setUnselected();
	}
	selectedShoupaiList.clear();
}

void MainWindow::unselectAllPlayers() {
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setUnselected();
		} else {
			otherPlayerAreaAtIndex(i)->setUnselected();
		}
	}
	selectedPlayerAreaList.clear();
}

void MainWindow::unselectAllZhuangbei() {
	zhuangbeiA->setSelected(0, false, true);
	zhuangbeiA->setSelected(1, false, true);
	zhuangbeiA->setSelected(2, false, true);
	zhuangbeiA->setSelected(3, false, true);
	selectedZhuangbei = 0;
}

void MainWindow::enablePlayer(int targetPlayerIndex) {
	if (targetPlayerIndex == playerIndex) {
		wujiangA->setSelectable();
	} else {
		otherPlayerAreaAtIndex(targetPlayerIndex)->setSelectable();
	}
}

void MainWindow::enableShaTarget() {
	sgs::DataType::Player * thisPlayer = GUIStaticData::getPlayer(playerIndex),
			*otherPlayer = 0;

	// do it no matter the player is alive or dead
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayer = GUIStaticData::getPlayer(i);
			PlayerArea * playerArea = otherPlayerAreaAtIndex(i);
			if (otherPlayer->type() == sgs::ConstData::LAOZHUGE
					&& otherPlayer->handnum() == 0) {
				playerArea->setUnselectable();
				continue;
			}
			playerArea->setSelectable(
					thisPlayer->distance(otherPlayer) <= thisPlayer->range());
			playerArea->setUnselected();
		}
	}
}

void MainWindow::enableJiedaoVictim(int attackerIndex) {

	// this function does not disable players that is already selected
	// kira is the Japaese version of English word "Killer"
	sgs::DataType::Player * kiraPlayer = GUIStaticData::getPlayer(
			attackerIndex), *otherPlayer = 0;

	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setSelectable(
					kiraPlayer->distance(myPlayer()) <= kiraPlayer->range());
			wujiangA->setUnselected();
		} else {
			otherPlayer = GUIStaticData::getPlayer(i);
			PlayerArea * playerArea = otherPlayerAreaAtIndex(i);

			// skip the attacker
			if (i == attackerIndex) {
				playerArea->setUnselectable();
				continue;
			}
			playerArea->setSelectable(
					kiraPlayer->distance(otherPlayer) <= kiraPlayer->range());
			playerArea->setUnselected();
		}
	}
}

void MainWindow::enableShunqianTarget() {
	sgs::DataType::Player * thisPlayer = GUIStaticData::getPlayer(playerIndex),
			*otherPlayer = 0;

	// do it no matter the player is alive or dead
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayer = GUIStaticData::getPlayer(i);
			PlayerArea * playerArea = otherPlayerAreaAtIndex(i);
			bool selectable = totalCardNum(otherPlayer) > 0;

			// huangyueying and luxun
			selectable &= (myPlayer()->type() == sgs::ConstData::HUANGYUEYING
					|| thisPlayer->distance(otherPlayer) <= 1);
			selectable &= otherPlayer->type() != sgs::ConstData::LUXUN;

			playerArea->setSelectable(selectable);
		}
	}
}

void MainWindow::enablePlayerWithWeapon(bool enableMyself) {
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setSelectable(enableMyself);
		} else {
			otherPlayerAreaAtIndex(i)->setSelectable(
					hasWeapon(GUIStaticData::getPlayer(i)));
		}
	}
}

void MainWindow::enableAllPlayers(bool hasCard, bool enableMyself) {

	// do it no matter the player is alive or dead
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setSelectable(enableMyself);
		} else {
			otherPlayerAreaAtIndex(i)->setSelectable();
			otherPlayerAreaAtIndex(i)->setUnselected();

			// check card num
			if (hasCard && totalCardNum(GUIStaticData::getPlayer(i)) < 1) {
				otherPlayerAreaAtIndex(i)->setUnselectable();
			}
		}
	}
}

void MainWindow::enableJuedouTarget() {
	sgs::DataType::Player *otherPlayer = 0;

	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayer = GUIStaticData::getPlayer(i);
			PlayerArea * playerArea = otherPlayerAreaAtIndex(i);

			if (otherPlayer->type() == sgs::ConstData::LAOZHUGE
					&& otherPlayer->handnum() == 0) {
				playerArea->setUnselectable();
				continue;
			}

			playerArea->setSelectable();
		}
	}
}

void MainWindow::enableSishuTarget() {
	sgs::DataType::Player *otherPlayer = 0;
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayer = GUIStaticData::getPlayer(i);

			// luxun cannot be a target
			otherPlayerAreaAtIndex(i)->setSelectable(
					!hasSishuInJudge(GUIStaticData::getPlayer(i))
							&& otherPlayer->type() != sgs::ConstData::LUXUN);
		}
	}
}

void MainWindow::enableQingnangTarget() {
	sgs::DataType::Player *otherPlayer = 0;

	for (int i = 1; i <= playerCount; ++i) {
		otherPlayer = GUIStaticData::getPlayer(i);

		if (i == playerIndex) {
			wujiangA->setSelectable(otherPlayer->hp() < otherPlayer->maxHP());
		} else {
			otherPlayerAreaAtIndex(i)->setSelectable(
					otherPlayer->hp() < otherPlayer->maxHP());
		}
	}
}

void MainWindow::enableMalePlayers() {
	sgs::DataType::Player *otherPlayer = 0;

	for (int i = 1; i <= playerCount; ++i) {
		otherPlayer = GUIStaticData::getPlayer(i);
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayerAreaAtIndex(i)->setSelectable(
					otherPlayer->sex() == sgs::ConstData::MALE);
		}
	}
}

void MainWindow::enableTuxiTarget() {
	sgs::DataType::Player *otherPlayer = 0;
	for (int i = 1; i <= playerCount; ++i) {
		otherPlayer = GUIStaticData::getPlayer(i);
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayerAreaAtIndex(i)->setSelectable(
					otherPlayer->handnum() > 0);
		}
	}
}

void MainWindow::enableJieyinTarget() {
	sgs::DataType::Player *otherPlayer = 0;
	for (int i = 1; i <= playerCount; ++i) {
		otherPlayer = GUIStaticData::getPlayer(i);
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayerAreaAtIndex(i)->setSelectable(
					otherPlayer->sex() == sgs::ConstData::MALE
							&& otherPlayer->hp() < otherPlayer->maxHP());
		}
	}
}

void MainWindow::enableLiuliTarget() {
	sgs::DataType::Player * thisPlayer = GUIStaticData::getPlayer(playerIndex),
			*otherPlayer = 0;

	// do it no matter the player is alive or dead
	for (int i = 1; i <= playerCount; ++i) {
		if (i == playerIndex) {
			wujiangA->setUnselectable();
		} else {
			otherPlayer = GUIStaticData::getPlayer(i);
			PlayerArea * playerArea = otherPlayerAreaAtIndex(i);

			if (otherPlayer->type() == sgs::ConstData::LAOZHUGE
					&& otherPlayer->handnum() == 0) {
				playerArea->setUnselectable();
				continue;
			}
			if (otherPlayer == liuliAttacker) {
				playerArea->setUnselectable();
				continue;
			}
			playerArea->setSelectable(
					thisPlayer->distance(otherPlayer) <= thisPlayer->range());
			playerArea->setUnselected();
		}
	}
}

void MainWindow::okClicked() {
	unblock(); // clearAbandonData() in discardCard() will do the following work
}

void MainWindow::cancelClicked() {

	if (selectedSkill != sgs::ConstData::hkNone) {
		printDebug("MainWindow::cancelClicked: handle skill");
		selectedSkill = sgs::ConstData::hkNone;
		selectedSkillCardVec.clear();
		clearCardPlayerEquipSelect();
		cardNormalize();
		skillNormalize();
		checkButtons();
		return;
	}

	// unselect selected zhuangbei;
	if (selectedZhuangbei) {
		printDebug("MainWindow::cancelClicked: handle zhuangbei");
		zhuangbeiClicked(selectedZhuangbei);
		checkButtons();
		return;
	}

	if (responseType == DiscardCard) {
		// Ensure that all cards are available and unselected
		for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
				iter != shoupaiList.end(); ++iter) {
			(*iter)->setUnselected();
		}
		selectedAbandonList.clear();
		okButton->setDisabled();
	} else {
		switch (responseType) {
		case UseCard:
			for (unsigned int i = 0; i < selectedShoupaiList.size(); ++i) {
				newUnselectedCard(selectedShoupaiList.back());
				// Do not call popback here, newUnselectedCard will remove cards
			}
			break;
		default:
			cancelResponse = true;
			unblock();
			break;
		}
	}
}

void MainWindow::resetSkillSelect() {
	printDebug("MainWindow::resetSkillSelect: reset");
	selectedSkill = sgs::ConstData::hkNone;
	selectedSkillCardVec.clear();
	clearCardPlayerEquipSelect();
	cardNormalize();
	skillNormalize();
	checkButtons();
	return;
}

void MainWindow::abandonClicked() {
	if (responseType == UseCard) {
		isGoingToAbandon = true;
		unblock();
	}
}

void MainWindow::skillClicked(sgs::ConstData::HeroSkill skill, int skillIndex) {
	printDebug("MainWindow::skillClicked: skill: " + skillDisplayName(skill));

	// disable the skill button to avoid the player to click again
	wujiangA->disableSkillButton(skillIndex);
	// when a skill button is clicked, first clear previous select
	clearCardPlayerEquipSelect();
	selectedSkill = skill;
	skillCardNormalize();
	skillPlayerChooseNormalize();
	checkButtons();
}

void MainWindow::cardClicked(CardButton * clickedCard) {

	// newSelectedCard and newUnselectedCard will process skill choose card

	Shoupai * clickedShoupai = static_cast<Shoupai *>(clickedCard);

	if (responseType == DiscardCard) {
		if (clickedCard->isSelected()) {
			clickedCard->setUnselected();
			selectedAbandonList.remove(clickedShoupai);
		} else {
			clickedCard->setSelected();
			selectedAbandonList.push_back(clickedShoupai);
			if (selectedAbandonList.size() > shoupaiNumToDiscard) {
				selectedAbandonList.front()->setUnselected();
				selectedAbandonList.pop_front();
			}
		}
		if (selectedAbandonList.size() == shoupaiNumToDiscard)
			okButton->setEnabled();
		else
			okButton->setDisabled();
	} else {
		if (clickedShoupai->isSelected())
			newUnselectedCard(clickedShoupai);
		else
			newSelectedCard(clickedShoupai);
	}
}

void MainWindow::zhuangbeiClicked(ZhuangbeiPic *clickedEquip) {
	if (clickedEquip->isSelected()) {
		clickedEquip->setUnselected();
		cardNormalize();
		selectedZhuangbei = 0;
		playerChooseNormalize();
		checkButtons();
	} else {
		clickedEquip->setSelected();
		disableAllShoupai();
		selectedZhuangbei = clickedEquip;
		playerChooseNormalize();
		checkButtons();
	}
}

void MainWindow::playerClicked(AbstractPlayerArea * clickedPlayerArea) {
	if (clickedPlayerArea->isSelected())
		newUnselectedPlayer(clickedPlayerArea);
	else
		newSelectedPlayer(clickedPlayerArea);
}

int MainWindow::getIndex(Shoupai * clickedCard) const {
	const sgs::DataType::Card * platformCard = clickedCard->platformCard();
	sgs::DataType::Player * player = GUIStaticData::getPlayer(playerIndex);
	for (int i = 0; i < player->handnum(); ++i) {
		if (player->hand(i) == platformCard)
			return i;
	}

	printDebug(
			"<font color=red><b>Warning: </b></font>MainWindow::getIndex: cannot find the card "
					+ cardFullDisplayName(platformCard, false)
					+ " in Player's hand, pause game to check bug");
	pauseButton->click();
	return -1;
}

Shoupai * MainWindow::goToCard(const sgs::DataType::Card * card) const {
	for (std::list<Shoupai *>::const_iterator iter = shoupaiList.begin();
			iter != shoupaiList.end(); ++iter) {
		if ((*iter)->platformCard() == card)
			return *iter;
	}

	printDebug(
			"<font color=red><b>Warning: </b></font>MainWindow::goToCard: cannot find the certain card in shoupai, card: "
					+ cardFullDisplayName(card, false)
					+ ", pause game to check bug");
	pauseButton->click();
	return 0;
}

void MainWindow::newSelectedCard(Shoupai * selectedCard) {
	if (!selectedCard)
		return;

	selectedShoupaiList.push_back(selectedCard);
	if (selectedShoupaiList.size() > maxShoupaiSelect)
		newUnselectedCard(selectedShoupaiList.front());
	// Do not call popfront here, newUnselectedCard will remove old card

	selectedCard->setSelected();
	if (selectedSkill != sgs::ConstData::hkNone) {
		skillPlayerChooseNormalize();
	} else {
		playerChooseNormalize();
	}
	checkButtons();
}

void MainWindow::newUnselectedCard(Shoupai * unselectedCard) {
	if (!unselectedCard)
		return;

	selectedShoupaiList.remove(unselectedCard);
	unselectedCard->setUnselected();

	if (selectedSkill != sgs::ConstData::hkNone) {
		skillPlayerChooseNormalize();
	} else {
		playerChooseNormalize();
	}
	checkButtons();
}

void MainWindow::newSelectedPlayer(AbstractPlayerArea * playerArea) {
	if (!playerArea)
		return;

	if (!selectedShoupaiList.empty() && selectedSkill == sgs::ConstData::hkNone
			&& selectedShoupaiList.back()->card()->getCardType()
					== sgs::ConstData::JIEDAO) {

		// if first player (i.e. the weapon owner) is clicked
		if (selectedPlayerAreaList.empty()) {
			showTipMessage(GUIStaticData::chooseJiedaoVictim);
			enableJiedaoVictim(playerArea->playerIndex());
		}
	}

	playerArea->setSelected();
	selectedPlayerAreaList.push_back(playerArea);
	if (selectedPlayerAreaList.size() > maxPlayerSelect) {
		printDebug("MainWindow::newSelectedPlayer: in");
		newUnselectedPlayer(selectedPlayerAreaList.front());
		// Do not call popfront here, newUnselectedPlayer will remove old player

		// Do not remove tuxi, newUnselectedPlayer will do it
	}

	if (responseType == GetTuxi) {
		QString text(
				trUtf8(
						"\351\200\211\346\213\251\347\233\256\346\240\207\347\232\204\344\270\200\345\274\240\346\211\213\347\211\214"));
		sgs::DataType::Player * targetPlayer = playerArea->getPlayer();
		std::pair<sgs::ConstData::PlayerRegionType, int> temp1(
				cardContainer->chooseCard(text, targetPlayer, true, false,
						false, 1, sgs::ConstData::TUXI).back());

		std::pair<int, AbstractPlayerArea*> temp2(temp1.second, playerArea);
		tuxiList.push_back(temp2);
		printDebug("MainWindow::newSelectedPlayer: temp");
	}
	checkButtons();
}

void MainWindow::newUnselectedPlayer(AbstractPlayerArea * playerArea) {
	if (!playerArea)
		return;

	// handle jiedao
	if (!selectedShoupaiList.empty()
			&& selectedShoupaiList.back()->card()->getCardType()
					== sgs::ConstData::JIEDAO) {

		// if both attacker and victim are selected
		// and the unselected player is the attacker
		if (selectedPlayerAreaList.size() == 2
				&& selectedPlayerAreaList.front() == playerArea) {
			showTipMessage(GUIStaticData::chooseWeaponOwner);
			selectedPlayerAreaList.back()->setUnselectable();
			selectedPlayerAreaList.pop_back();
		} else {
			showTipMessage(GUIStaticData::chooseJiedaoVictim);
		}
	}

	selectedPlayerAreaList.remove(playerArea);

	if (responseType == GetTuxi) {
		if (tuxiList.front().second == playerArea) {
			tuxiList.pop_front();
		} else {
			tuxiList.pop_back();
		}
	}

	playerArea->setUnselected();
	checkButtons();
}

sgs::Derive::MCard * MainWindow::collectZhuangbei() {
	sgs::Derive::MCard * returnMessage = 0;
	if (selectedZhuangbei) {

		returnMessage = new sgs::Derive::MCard(true,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PEQUIP,
				0);

		std::vector<sgs::DataType::Player *> targetPlayerVec;
		for (std::list<AbstractPlayerArea *>::iterator iter =
				selectedPlayerAreaList.begin();
				iter != selectedPlayerAreaList.end(); ++iter) {
			targetPlayerVec.push_back((*iter)->getPlayer());
		}
		// sort the selected players from small to big;
		std::sort(targetPlayerVec.begin(), targetPlayerVec.end(),
				PlayerSort(playerIndex - 1, BySeat));
		for (std::vector<sgs::DataType::Player *>::iterator iter =
				targetPlayerVec.begin(); iter != targetPlayerVec.end();
				++iter) {
			returnMessage->addto(*iter);
		}
		printDebug("MainWindow::collectZhuangbei: using zhuangbei");
	}
	return returnMessage;
}

sgs::Derive::MSkill * MainWindow::collectSkill() {
	using namespace sgs::ConstData;
	using namespace sgs::Derive;
	if (selectedSkill == sgs::ConstData::hkNone)
		return 0;

	MSkill * returnSkill = 0;

	switch (selectedSkill) {
	case GUOSE: {
		MGuoSe * returnGuose = new MGuoSe(myPlayer(),
				selectedSkillCardVec.back().first,
				selectedSkillCardVec.back().second,
				selectedPlayerAreaList.back()->getPlayer());
		returnSkill = returnGuose;
	}
		break;
	case JIEYIN: {
		int cardIndex1 = getIndex(selectedShoupaiList.front());
		int cardIndex2 = getIndex(selectedShoupaiList.back());

		// from big to small
		if (cardIndex1 < cardIndex2) {
			int temp = cardIndex1;
			cardIndex1 = cardIndex2;
			cardIndex2 = temp;
		}
		MJieYin * returnJieyin = new MJieYin(myPlayer(),
				selectedPlayerAreaList.back()->getPlayer(), cardIndex1,
				cardIndex2);
		returnSkill = returnJieyin;
	}
		break;
	case FANJIAN: {
		MFanJian * returnFanjian = new MFanJian(myPlayer(),
				selectedPlayerAreaList.back()->getPlayer());
		returnSkill = returnFanjian;
	}
		break;
	case ZHIHENG: {
		MZhiHeng * returnZhiheng = new MZhiHeng(myPlayer());
		for (CardPosPairVec::const_iterator citer =
				selectedSkillCardVec.begin();
				citer != selectedSkillCardVec.end(); ++citer) {
			returnZhiheng->transpush((*citer).first, (*citer).second);
		}
		returnSkill = returnZhiheng;
	}
		break;
	case LIJIAN: {
		sgs::DataType::Player * juedou1, *juedou2;
		juedou1 = (selectedPlayerAreaList.front()->getPlayer());
		juedou2 = (selectedPlayerAreaList.back()->getPlayer());
		MLiJian * returnLijian = new MLiJian(myPlayer(),
				selectedSkillCardVec.back().first,
				selectedSkillCardVec.back().second, juedou1, juedou2);
		returnSkill = returnLijian;
	}
		break;
	case HUJIA: {
		MSkill * returnHujia = new MSkill(myPlayer(), HUJIA);
		returnSkill = returnHujia;
	}
		break;
	case JIJIANG: {
		MJiJiang * returnJijiang = new MJiJiang(myPlayer());
		std::vector<sgs::DataType::Player *> targetPlayerVec;
		for (std::list<AbstractPlayerArea *>::iterator iter =
				selectedPlayerAreaList.begin();
				iter != selectedPlayerAreaList.end(); ++iter) {
			targetPlayerVec.push_back((*iter)->getPlayer());
		}
		// sort the selected players from small to big (by seat);
		std::sort(targetPlayerVec.begin(), targetPlayerVec.end(),
				PlayerSort(playerIndex - 1, BySeat));
		for (std::vector<sgs::DataType::Player *>::iterator iter =
				targetPlayerVec.begin(); iter != targetPlayerVec.end();
				++iter) {
			returnJijiang->addto(*iter);
		}
		returnSkill = returnJijiang;
	}
		break;
	case RENDE: {
		MRenDe * returnRende = new MRenDe(myPlayer(),
				selectedPlayerAreaList.back()->getPlayer());
		std::vector<int> cardVec;
		for (std::list<Shoupai *>::iterator iter = selectedShoupaiList.begin();
				iter != selectedShoupaiList.end(); ++iter) {
			cardVec.push_back(getIndex(*iter));
		}

		// push the big one first
		// sort the selected cards from big to small
		std::sort(cardVec.rbegin(), cardVec.rend());
		for (std::vector<int>::iterator iter = cardVec.begin();
				iter != cardVec.end(); ++iter) {
			returnRende->transpush(*iter);
		}
		returnSkill = returnRende;
	}
		break;
	case QINGNANG: {
		printDebug("MainWindow::collectSkill: collect QINGNANG");
		MQingNang * returnQingnang = new MQingNang(myPlayer(),
				getIndex(selectedShoupaiList.back()),
				selectedPlayerAreaList.back()->getPlayer());
		returnSkill = returnQingnang;
	}
		break;
	case JIJIU: {
		printDebug("MainWindow::collectSkill: collect JIJIU");
		MJiJiu * returnJijiu = new MJiJiu(myPlayer(),
				selectedSkillCardVec.back().first,
				selectedSkillCardVec.back().second);
		returnSkill = returnJijiu;
	}
		break;
	case QIXI: {
		printDebug("MainWindow::collectSkill: collect QIXI");
		MQiXi * returnQixi = new MQiXi(myPlayer(),
				selectedSkillCardVec.back().first,
				selectedSkillCardVec.back().second,
				selectedPlayerAreaList.back()->getPlayer());
		returnSkill = returnQixi;
	}
		break;
	case LONGDAN: {
		printDebug("MainWindow::collectSkill: collect LONGDAN");
		MLongDan * returnLongdan = new MLongDan(myPlayer(),
				getIndex(selectedShoupaiList.back()));
		std::vector<sgs::DataType::Player *> targetPlayerVec;
		for (std::list<AbstractPlayerArea *>::iterator iter =
				selectedPlayerAreaList.begin();
				iter != selectedPlayerAreaList.end(); ++iter) {
			targetPlayerVec.push_back((*iter)->getPlayer());
		}
		// sort the selected players from small to big;
		std::sort(targetPlayerVec.begin(), targetPlayerVec.end(),
				PlayerSort(playerIndex - 1, BySeat));
		for (std::vector<sgs::DataType::Player *>::iterator iter =
				targetPlayerVec.begin(); iter != targetPlayerVec.end();
				++iter) {
			returnLongdan->addto(*iter);
		}
		returnSkill = returnLongdan;
	}
		break;
	case WUSHENG: {
		printDebug("MainWindow::collectSkill: collect WUSHENG");
		MWuSheng * returnWusheng = new MWuSheng(myPlayer(),
				selectedSkillCardVec.back().first,
				selectedSkillCardVec.back().second);
		std::vector<sgs::DataType::Player *> targetPlayerVec;
		for (std::list<AbstractPlayerArea *>::iterator iter =
				selectedPlayerAreaList.begin();
				iter != selectedPlayerAreaList.end(); ++iter) {
			targetPlayerVec.push_back((*iter)->getPlayer());
		}
		// sort the selected players from small to big;
		std::sort(targetPlayerVec.begin(), targetPlayerVec.end(),
				PlayerSort(playerIndex - 1, BySeat));
		for (std::vector<sgs::DataType::Player *>::iterator iter =
				targetPlayerVec.begin(); iter != targetPlayerVec.end();
				++iter) {
			returnWusheng->addto(*iter);
		}
		returnSkill = returnWusheng;
	}
		break;
	case QINGGUO: {
		printDebug("MainWindow::collectSkill: collect Qingguo");
		MQingGuo * returnQingguo = new MQingGuo(myPlayer(),
				getIndex(selectedShoupaiList.back()));
		returnSkill = returnQingguo;
	}
		break;
	case KUROU: {
		printDebug("MainWindow::collectSkill: collect Kurou");
		MSkill * returnKurou = new MSkill(myPlayer(), KUROU);
		return returnKurou;
	}
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::collectSkill: collection handled by default, skill "
						+ skillDisplayName(selectedSkill));
		pause();
		return returnSkill;
		break;
	}
	return returnSkill;
}

} /* namespace sgsui */
