/*
 * sgsui_MainWindow_Algorithm.cpp
 *
 *  Created on: Jun 29, 2012
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
#include <algorithm>

namespace sgsui {

void MainWindow::cardNormalize() {
	printDebug("MainWindow::cardNormalize: start");
	// Note: Discard card will not be handled here.
	// all the Discard card repsonse will be handled completely along

	// this function is called only at the beginning of a response, when all the cards are unselected
	// so all the players should be disabled since no card is selected
	// therefore, disable all the players first and
	// wait for the NormalizePlayer() to enable player select when a card is selected.
	disableAllPlayers();
	// if a response let user choose players without choosing any cards,
	// the following case of the response will enable player select

	if (selectedSkill != sgs::ConstData::hkNone) {
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::cardNormalize: selectedSkill not empty");
		skillCardNormalize();
		return;
	}

	// handle those case that are not using skills

	// handle equipCard
	disableAllZhuangbei();
	switch (responseType) {
	case UseCard:
		zhuangbeiA->setSelectable(0, canUseZhangba(), true);
		break;
	case ShaOrNot:
		zhuangbeiA->setSelectable(0, !skillVerShaOrNot && canUseZhangba(),
				true);
		break;
	default:
		break;
	}

	// handle handCard
	using namespace sgs::ConstData;
	switch (responseType) {
	case UseCard:
		maxShoupaiSelect = 1;
		minShoupaiSelect = 1;
		for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
				iter != shoupaiList.end(); ++iter) {
			sgs::ConstData::CardType cardType = (*iter)->card()->getCardType();
			switch (cardType) {
			case SHAN:
				(*iter)->setUnselectable();
				break;
			case SHA:
				(*iter)->setSelectable(canUseSha());
				break;
			case TAO:
				(*iter)->setSelectable(
						wujiangA->getHP() < wujiangA->getMaxHP());
				break;

				// armor
			case BAGUA:
			case RENWANG:

				// horse
			case CHITU:
			case DAWAN:
			case ZICI:
			case DILU:
			case JUEYING:
			case ZHUAHUANG:
			case HUALIU:

				// weapon
			case ZHUGE:
			case QINGGANG:
			case HANBING:
			case CIXIONG:
			case GUANSHI:
			case QINGLONG:
			case GUDING:
			case ZHANGBA:
			case FANGTIAN:
			case QILIN:
				(*iter)->setSelectable();
				break;

				// jinnang
			case SISHU:
			case GUOCHAI:
			case JIEDAO:
				// let User select this card, no matter whether it can use
				// if there's no weapon owner or no target in any weapon owner,
				// then User cannot use this card due to impossible player select
			case JUEDOU:
			case NANMAN:
			case SHUNQIAN:
			case TAOYUAN:
			case WANJIAN:
			case WUZHONG:
			case WUGU:
				(*iter)->setSelectable();
				break;
			case SHANDIAN:
				(*iter)->setSelectable(!hasShandianInJudge(myPlayer()));
				break;
			case WUXIE:
				(*iter)->setUnselectable();
				break;
			default:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::cardNormalize: Usecard normalize handled by default, card: "
								+ cardDisplayName(cardType));
				(*iter)->setUnselectable();
				break;
			}
		}
		break;
	case ShanOrNot:
		maxShoupaiSelect = 1;
		minShoupaiSelect = 1;
		for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
				iter != shoupaiList.end(); ++iter) {
			if ((*iter)->card()->getCardType() == sgs::ConstData::SHAN)
				(*iter)->setSelectable();
			else
				(*iter)->setUnselectable();
		}
		break;
	case TaoOrNot:
		maxShoupaiSelect = 1;
		minShoupaiSelect = 1;
		for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
				iter != shoupaiList.end(); ++iter) {
			if ((*iter)->card()->getCardType() == sgs::ConstData::TAO)
				(*iter)->setSelectable();
			else
				(*iter)->setUnselectable();
		}
		break;
	case ShaOrNot:
		maxShoupaiSelect = 1;
		minShoupaiSelect = 1;
		for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
				iter != shoupaiList.end(); ++iter) {
			if ((*iter)->card()->getCardType() == sgs::ConstData::SHA)
				(*iter)->setSelectable();
			else
				(*iter)->setUnselectable();
		}
		break;
	case WuxieOrNot:
		maxShoupaiSelect = 1;
		minShoupaiSelect = 1;
		for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
				iter != shoupaiList.end(); ++iter) {
			if ((*iter)->card()->getCardType() == sgs::ConstData::WUXIE)
				(*iter)->setSelectable();
			else
				(*iter)->setUnselectable();
		}
		break;
	case GetTuxi:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		break;
	case GetYiji:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		break;
	case GetLiuli:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		selectedSkillCardVec = cardContainer->chooseSkillCard(LIULI);
		if (selectedSkillCardVec.empty()) {
			cancelResponse = true;
			unblock();
			return;
		}
		break;
	default:
		break;
	}

	printDebug("MainWindow::cardNormalize: over");
}

void MainWindow::playerChooseNormalize() {
	printDebug("MainWindow::playerChooseNormalize: start");

	if (selectedSkill != sgs::ConstData::hkNone) {
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::playerChooseNormalize: selectedSkill not empty");
		skillPlayerChooseNormalize();
		return;
	}

	// unselect all players first
	unselectAllPlayers();

	using namespace sgs::ConstData;
	// processZhuangbei
	if (selectedZhuangbei) {
		if (responseType == UseCard) {
			enableShaTarget();
			showTipMessage(GUIStaticData::chooseZhangbaTarget);
			maxPlayerSelect = 1;
			minPlayerSelect = 1;
		} else {
			disableAllPlayers();
			maxPlayerSelect = 0;
			minPlayerSelect = 0;
		}
		return;
	}

	// the case that shoupaiList is empty should be handled here
	// all the player select for TAO is not done by user;
	switch (responseType) {
	case UseCard:
		if (selectedShoupaiList.empty()) {
			disableAllPlayers();
			maxPlayerSelect = 0;
			minPlayerSelect = 0;
		} else {
			switch (selectedShoupaiList.back()->card()->getCardType()) {
			case SHA:
				enableShaTarget();
				if (canUseFangtian() && GUIStaticData::getPlayerCount() > 2) {
					if (GUIStaticData::getPlayerCount() > 3)
						showTipMessage(GUIStaticData::threeTargets);
					else
						showTipMessage(GUIStaticData::twoTargets);
					maxPlayerSelect = 3;
				} else {
					maxPlayerSelect = 1;
				}
				minPlayerSelect = 1;
				break;
			case TAO:
				disableAllPlayers();
				maxPlayerSelect = 0;
				minPlayerSelect = 0;
				break;

				// equip:
			case CHITU:
			case DAWAN:
			case ZICI:
			case DILU:
			case JUEYING:
			case ZHUAHUANG:
			case HUALIU:
			case BAIYIN:
			case TENGJIA:
			case BAGUA:
			case RENWANG:
			case ZHUGE:
			case QINGGANG:
			case HANBING:
			case CIXIONG:
			case GUANSHI:
			case YINYUE:
			case QINGLONG:
			case GUDING:
			case ZHANGBA:
			case FANGTIAN:
			case QILIN:
			case ZHUQUE:
				disableAllPlayers();
				maxPlayerSelect = 0;
				minPlayerSelect = 0;
				break;

				// jinnang
			case SHANDIAN:
				disableAllPlayers();
				maxPlayerSelect = 0;
				minPlayerSelect = 0;
				break;
			case SHUNQIAN:
				enableShunqianTarget();
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case GUOCHAI:
				// only enable players with cards
				enableAllPlayers(true);
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case JIEDAO:
				// this is called for the fisrt player select (the attacker)
				// other work will be done in newSelectedPlayer and newUnselectedPlayer
				enablePlayerWithWeapon();
				showTipMessage(GUIStaticData::chooseWeaponOwner);
				maxPlayerSelect = 2;
				minPlayerSelect = 2;
				break;
			case JUEDOU:
				enableJuedouTarget();
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case WANJIAN:
			case NANMAN:
			case TAOYUAN:
			case WUGU:
			case WUZHONG:
				disableAllPlayers();
				minPlayerSelect = 0;
				minPlayerSelect = 0;
				break;
			case SISHU:
				enableSishuTarget();
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			default:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::playerChooseNormalize: case handled by default");
				break;
			}
		}
		break;
	case TaoOrNot:
		disableAllPlayers();
		maxPlayerSelect = 0;
		minPlayerSelect = 0;
		break;
	case ShanOrNot:
		disableAllPlayers();
		maxPlayerSelect = 0;
		minPlayerSelect = 0;
		break;
	case ShaOrNot:
		disableAllPlayers();
		maxPlayerSelect = 0;
		minPlayerSelect = 0;
		break;
	case GetTuxi:
		enableTuxiTarget();
		maxPlayerSelect = 2;
		minPlayerSelect = 1;
		break;
	case GetYiji:
		// also enable myself
		enableAllPlayers(false, true);
		maxPlayerSelect = 1;
		minPlayerSelect = 1;
		break;
	case GetLiuli:
		showTipMessage(
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\345\220\215\350\246\201\350\275\254\347\247\273\345\210\260\347\232\204\350\247\222\350\211\262\357\274\210\344\270\215\350\203\275\346\230\257\346\235\200\347\232\204\344\275\277\347\224\250\350\200\205\357\274\211"));
		enableLiuliTarget();
		maxPlayerSelect = 1;
		minPlayerSelect = 1;
		break;
	default:
		break;
	}

	printDebug("MainWindow::playerChooseNormalize: over");
}

void MainWindow::skillNormalize() {
	printDebug("MainWindow::skillNormalize: start");
	using namespace sgs::ConstData;

	// this function should be called at the beginning of a response (together with cardNormalize() )
	// almost all the active skill button (i.e skill button clicked by User) can be only clicked in main;
	sgs::ConstData::HeroSkill skill = sgs::ConstData::hkNone;
	switch (responseType) {
	case UseCard:
		for (int i = 0; i < 4; ++i) {
			skill = wujiangA->getSkill(i);
			if (skill == sgs::ConstData::hkNone)
				break;

			switch (skill) {
			case GUOSE:
				wujiangA->enableSkillButton(i, haveDiamondCard());
				break;
			case JIEYIN:
				wujiangA->enableSkillButton(i, canUseJieyin());
				break;
			case FANJIAN:
				wujiangA->enableSkillButton(
						i,
						myPlayer()->handnum() > 0
								&& !(myPlayer()->status()
										& sgs::ConstData::SkillOneUsed));
				break;
			case ZHIHENG:
				wujiangA->enableSkillButton(i,
						!(myPlayer()->status() & sgs::ConstData::SkillOneUsed));
				break;
			case LIJIAN:
				wujiangA->enableSkillButton(
						i,
						handEquipNum(myPlayer()) > 0
								&& !(myPlayer()->status()
										& sgs::ConstData::SkillOneUsed));
				break;
			case JIJIANG:
				wujiangA->enableSkillButton(
						i,
						myPlayer()->role() == sgs::ConstData::ZHU
								&& canUseSha());
				break;
			case RENDE:
				wujiangA->enableSkillButton(i, myPlayer()->handnum() > 0);
				break;
			case QINGNANG:
				wujiangA->enableSkillButton(i,
						!(myPlayer()->status() & sgs::ConstData::SkillOneUsed));
				break;
			case KUROU:
				wujiangA->enableSkillButton(i);
				break;
			case QIXI:
				wujiangA->enableSkillButton(i, haveBlackCard());
				break;
			case LONGDAN:
				wujiangA->enableSkillButton(i, canUseSha());
				break;
			case WUSHENG:
				wujiangA->enableSkillButton(i, canUseSha() && haveRedCard());
				break;
			default:
				wujiangA->disableSkillButton(i);
				break;
			}
		}
		break;
	case ShaOrNot:
		for (int i = 0; i < 4; ++i) {
			skill = wujiangA->getSkill(i);
			if (skill == sgs::ConstData::hkNone)
				break;

			switch (skill) {
			case JIJIANG:
				wujiangA->enableSkillButton(i,
						myPlayer()->role() == sgs::ConstData::ZHU);
				break;
			case LONGDAN:
			case WUSHENG:
				wujiangA->enableSkillButton(i, haveRedCard());
				break;
			default:
				wujiangA->disableSkillButton(i);
				break;
			}
		}
		break;
	case ShanOrNot:
		for (int i = 0; i < 4; ++i) {
			skill = wujiangA->getSkill(i);
			if (skill == sgs::ConstData::hkNone)
				break;

			switch (skill) {
			case HUJIA:
				wujiangA->enableSkillButton(i,
						myPlayer()->role() == sgs::ConstData::ZHU);
				break;
			case LONGDAN:
				wujiangA->enableSkillButton(i);
				break;
			case QINGGUO:
				wujiangA->enableSkillButton(i);
				break;
			default:
				wujiangA->disableSkillButton(i);
				break;
			}
		}
		break;
	case TaoOrNot:
		for (int i = 0; i < 4; ++i) {
			skill = wujiangA->getSkill(i);
			if (skill == sgs::ConstData::hkNone)
				break;

			switch (skill) {
			case JIJIU:
				wujiangA->enableSkillButton(i, handEquipNum(myPlayer()) > 0);
				break;
			default:
				wujiangA->disableSkillButton(i);
				break;
			}
		}
		break;
	default:
		wujiangA->disableAllSkillButtons();
		break;
	}
	printDebug("MainWindow::skillNormalize: over");
}

void MainWindow::skillCardNormalize() {

	// All the skills that useds both skillCardNormalize and chooseSkillCard
	// GUOSE

	printDebug("MainWindow::skillCardNormalize: start");
	using namespace sgs::ConstData;
	switch (selectedSkill) {
	case hkNone:
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::skillChooseCardNormalize: no selected skill");
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		break;
	case GUOSE:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		selectedSkillCardVec = cardContainer->chooseSkillCard(selectedSkill);
		if (selectedSkillCardVec.empty()) {
			resetSkillSelect();
			return;
		}
		skillPlayerChooseNormalize();
		break;
	case JIEYIN:
		showTipMessage(
				trUtf8(
						"\351\200\211\346\213\251\350\246\201\345\274\203\347\275\256\347\232\204\344\270\244\345\274\240\345\215\241\347\211\214"));
		enableAllShoupai();
		maxShoupaiSelect = 2;
		minShoupaiSelect = 2;
		break;
	case FANJIAN:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		break;
	case ZHIHENG:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		selectedSkillCardVec = cardContainer->chooseSkillCard(selectedSkill);
		if (selectedSkillCardVec.empty()) {
			printDebug(
					"MainWindow::skillChooseCardNormalize: zhiheng canceled");
			resetSkillSelect();
			return;
		}
		unblock();
		break;
	case HUJIA:
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		unblock();
		break;
	case LIJIAN:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		selectedSkillCardVec = cardContainer->chooseSkillCard(selectedSkill);
		if (selectedSkillCardVec.empty()) {
			resetSkillSelect();
			return;
		}
		skillPlayerChooseNormalize();
		break;
	case JIJIANG:
		switch (responseType) {
		case UseCard:
			disableAllShoupai();
			maxShoupaiSelect = 0;
			minShoupaiSelect = 0;
			break;
		case ShaOrNot:
			maxShoupaiSelect = 0;
			minShoupaiSelect = 0;
			unblock();
			break;
		default:
			break;
		}
		break;
	case RENDE:
		showTipMessage(
				trUtf8(
						"\351\200\211\346\213\251\344\273\273\346\204\217\346\225\260\351\207\217\347\232\204\346\211\213\347\211\214"));
		enableAllShoupai();
		maxShoupaiSelect = 0xFFFF;
		minShoupaiSelect = 1;
		break;
	case QINGNANG:
		showTipMessage(
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\345\274\240\346\211\213\347\211\214"));
		enableAllShoupai();
		maxShoupaiSelect = 1;
		minShoupaiSelect = 1;
		break;
	case JIJIU:
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		selectedSkillCardVec = cardContainer->chooseSkillCard(selectedSkill);
		if (selectedSkillCardVec.empty()) {
			resetSkillSelect();
			return;
		}
		unblock();
		break;
	case KUROU:
		unblock();
		break;
	case QIXI: {
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		selectedSkillCardVec = cardContainer->chooseSkillCard(selectedSkill);
		if (selectedSkillCardVec.empty()) {
			resetSkillSelect();
			return;
		}
		skillPlayerChooseNormalize();
	}
		break;
	case LONGDAN: {
		switch (responseType) {
		case UseCard:
		case ShaOrNot:
			// enable all shan
			showTipMessage(
					trUtf8(
							"\351\200\211\346\213\251\344\270\200\345\274\240\351\227\252"));
			for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
					iter != shoupaiList.end(); ++iter) {
				(*iter)->setSelectable(
						(*iter)->card()->getCardType() == sgs::ConstData::SHAN);
			}
			maxShoupaiSelect = 1;
			minShoupaiSelect = 1;
			break;
		case ShanOrNot:
			// enable all sha
			showTipMessage(
					trUtf8(
							"\351\200\211\346\213\251\344\270\200\345\274\240\346\235\200"));
			for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
					iter != shoupaiList.end(); ++iter) {
				(*iter)->setSelectable(
						(*iter)->card()->getCardType() == sgs::ConstData::SHA);
			}
			maxShoupaiSelect = 1;
			minShoupaiSelect = 1;
			break;
		default:
			break;
		}
	}
		break;
	case WUSHENG:
		disableAllShoupai();
		maxShoupaiSelect = 0;
		minShoupaiSelect = 0;
		selectedSkillCardVec = cardContainer->chooseSkillCard(selectedSkill);
		if (selectedSkillCardVec.empty()) {
			resetSkillSelect();
			return;
		}
		skillPlayerChooseNormalize();
		break;
	case QINGGUO:
		// enable all red shoupai
		showTipMessage(
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\345\274\240\351\273\221\350\211\262\346\211\213\347\211\214"));
		for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
				iter != shoupaiList.end(); ++iter) {
			sgs::ConstData::CardColor color = (*iter)->card()->getCardColor();
			(*iter)->setSelectable(
					color == sgs::ConstData::SPADE
							|| color == sgs::ConstData::CLUB);
		}
		maxShoupaiSelect = 1;
		minShoupaiSelect = 1;
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::skillChooseCardNormalize: selected skill handled by default, check if the cases covers all possible skills");
		break;
	}
	printDebug("MainWindow::skillCardNormalize: over");
}

void MainWindow::skillPlayerChooseNormalize() {
	printDebug("MainWindow::skillPlayerChooseNormalize: start");
	using namespace sgs::ConstData;
	switch (responseType) {
	case UseCard:
		if (selectedShoupaiList.empty()) {
			switch (selectedSkill) {
			case GUOSE:
				showTipMessage(
						trUtf8(
								"\351\200\211\346\213\251\345\257\271\344\270\200\345\220\215\347\216\251\345\256\266\344\275\277\347\224\250\344\271\220\344\270\215\346\200\235\350\234\200"));
				enableSishuTarget();
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case FANJIAN:
				showTipMessage(
						trUtf8(
								"\351\200\211\346\213\251\344\270\200\344\270\252\350\246\201\345\217\215\351\227\264\347\232\204\347\233\256\346\240\207"));
				enableAllPlayers();
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case LIJIAN:
				showTipMessage(
						trUtf8(
								"\345\210\206\345\210\253\351\200\211\346\213\251\344\270\244\344\270\252\347\224\267\346\200\247\350\277\233\350\241\214\345\206\263\346\226\227"));
				enableMalePlayers();
				maxPlayerSelect = 2;
				minPlayerSelect = 2;
				break;
			case JIJIANG:
				enableShaTarget();
				if (canUseFangtian() && GUIStaticData::getPlayerCount() > 2) {
					if (GUIStaticData::getPlayerCount() > 3)
						showTipMessage(GUIStaticData::threeTargets);
					else
						showTipMessage(GUIStaticData::twoTargets);
					maxPlayerSelect = 3;
				} else {
					showTipMessage(
							trUtf8(
									"\351\200\211\346\213\251\344\270\200\344\270\252\346\224\273\345\207\273\347\233\256\346\240\207"));
					maxPlayerSelect = 1;
				}
				minPlayerSelect = 1;
				break;
			case WUSHENG:
				enableShaTarget();
				if (canUseFangtian() && GUIStaticData::getPlayerCount() > 2) {
					if (GUIStaticData::getPlayerCount() == 3)
						showTipMessage(GUIStaticData::threeTargets);
					else
						showTipMessage(GUIStaticData::twoTargets);
					maxPlayerSelect = 3;
				} else {
					maxPlayerSelect = 1;
				}
				minPlayerSelect = 1;
				break;
			case QIXI:
				showTipMessage(
						trUtf8(
								"\351\200\211\346\213\251\344\270\200\344\270\252\345\245\207\350\242\255\347\232\204\347\233\256\346\240\207"));

				// only enable players with cards
				enableAllPlayers(true);
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			default:
				disableAllPlayers();
				break;
			}
		} else {
			switch (selectedSkill) {
			case hkNone:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::skillPlayerChooseNormalize: no selected skill");
				break;
			case JIEYIN:
				if (selectedShoupaiList.size() == 2) {
					showTipMessage(
							trUtf8(
									"\351\200\211\346\213\251\344\270\200\345\220\215\345\217\227\344\274\244\347\232\204\347\224\267\346\200\247\350\247\222\350\211\262"));
					enableJieyinTarget();
				} else {
					disableAllPlayers();
				}
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case RENDE:
				showTipMessage(
						trUtf8(
								"\351\200\211\346\213\251\344\270\200\344\270\252\350\247\222\350\211\262\351\200\201\345\207\272\346\211\213\347\211\214"));
				enableAllPlayers();
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case QINGNANG:
				showTipMessage(
						trUtf8(
								"\351\200\211\346\213\251\344\270\200\344\270\252\345\217\227\344\274\244\347\232\204\347\216\251\345\256\266\357\274\210\345\214\205\346\213\254\344\275\240\350\207\252\345\267\261\357\274\211"));
				enableQingnangTarget();
				maxPlayerSelect = 1;
				minPlayerSelect = 1;
				break;
			case LONGDAN:
				enableShaTarget();
				if (canUseFangtian() && GUIStaticData::getPlayerCount() > 2) {
					if (GUIStaticData::getPlayerCount() == 3)
						showTipMessage(GUIStaticData::threeTargets);
					else
						showTipMessage(GUIStaticData::twoTargets);
					maxPlayerSelect = 3;
				} else {
					maxPlayerSelect = 1;
				}
				minPlayerSelect = 1;
				break;
			default:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::skillPlayerChooseNormalize: selected skill handled by default, check if the cases covers all possible skills "
								+ skillDisplayName(selectedSkill));
				break;
			}
		}
		break; /*case UseCard Over*/
	case ShaOrNot:
		if (selectedShoupaiList.empty()) {
			disableAllPlayers();
		} else {
			switch (selectedSkill) {
			case hkNone:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::skillPlayerChooseNormalize: no selected skill");
				break;
			case LONGDAN:
			case WUSHENG:
				disableAllPlayers();
				maxPlayerSelect = 0;
				minPlayerSelect = 0;
				break;
			default:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::skillPlayerChooseNormalize: selected skill handled by default, check if the cases covers all possible skills "
								+ skillDisplayName(selectedSkill));
				disableAllPlayers();
				maxPlayerSelect = 0;
				minPlayerSelect = 0;
				break;
			}
		}
		break; /*case ShaOrNot Over*/
	case ShanOrNot:
		if (selectedShoupaiList.empty()) {
			disableAllPlayers();
		} else {
			switch (selectedSkill) {
			case hkNone:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::skillPlayerChooseNormalize: no selected skill");
				break;
			case LONGDAN:
			case QINGGUO:
				disableAllPlayers();
				maxPlayerSelect = 0;
				minPlayerSelect = 0;
				break;
			default:
				printDebug(
						"<font color=red><b>Warning: </b></font>MainWindow::skillPlayerChooseNormalize: selected skill handled by default, check if the cases covers all possible skills "
								+ skillDisplayName(selectedSkill));
				disableAllPlayers();
				maxPlayerSelect = 0;
				minPlayerSelect = 0;
				break;
			}
		}
		break; /*case ShanOrNot Over*/
	default:
		break; /*other ResponseType Over*/
	}

	printDebug("MainWindow::skillPlayerChooseNormalize: over");
}

void MainWindow::checkButtons() {

	// if is Not Responding
	if (responseType == NotResponding) {
		okButton->setDisabled();
		cancelButton->setDisabled();
		abandonButton->setDisabled();
		return;
	}

	if (selectedZhuangbei) {
		okButton->setEnabled();
		cancelButton->setEnabled();
		abandonButton->setDisabled();
		return;
	}

	// handle OK Button
	if (selectedShoupaiList.size() >= minShoupaiSelect
			&& selectedShoupaiList.size() <= maxShoupaiSelect
			&& selectedPlayerAreaList.size() >= minPlayerSelect
			&& selectedPlayerAreaList.size() <= maxPlayerSelect) {
		okButton->setEnabled();
	} else {
		okButton->setDisabled();
	}

	// handle Cancel Button
	if (selectedSkill == sgs::ConstData::hkNone) {

		// if not using skill
		switch (responseType) {
		case GetLiuli:
		case GetTuxi:
		case TaoOrNot:
		case ShanOrNot:
		case ShaOrNot:
		case WuxieOrNot:
			cancelButton->setEnabled();
			break;
		case UseCard:
		case GetYiji:
		case DiscardCard:
			cancelButton->setDisabled();
			break;
		default:
			cancelButton->setDisabled();
			break;
		}

	} else {
		cancelButton->setEnabled();
	}

	switch (responseType) {
	case UseCard:
		abandonButton->setEnabled();
		break;
	default:
		abandonButton->setDisabled();
		break;
	}
}

} /* namespace sgsui */
