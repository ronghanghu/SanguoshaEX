/*
 * sgsui_MainWindow_Core.cpp
 *
 *  Created on: May 1, 2012
 *      Author: latios
 */

#include "sgsui_MainWindow.h"
#include "sgsui_Shoupai.h"
#include "sgsui_ZhuangbeiArea.h"
#include "sgsui_WujiangArea.h"
#include "sgsui_PlayerArea.h"
#include "sgsui_WugufengdengBox.h"
#include "sgsui_GuanxingBox.h"
#include "sgsui_AudioPlayer.h"
#include "sgsui_CardContainer.h"
#include "sgsui_ZhuangbeiPic.h"
#include "sgsui_CardViewer.h"
#include "sgsui_output.h"
#include "sgsui_FanjianBox.h"
#include "sgsui_nameConvert.h"
#include "sgsui_PlayerSort.h"
#include "sgsai_AIBasic.h"
#include "sgsdata_enum.h"
#include "sgsdata_msg.h"
#include "sgsdata_player.h"

namespace sgsui {

std::vector<int> MainWindow::discardCard(unsigned int cardNumToDiscard) {
	if (AICheckBox->isChecked()) {
		return innerAI->discardCard(cardNumToDiscard);
	}
	printDebug("MainWindow::discardCard: start");

	responseType = DiscardCard;

	showTipMessage(
			trUtf8("\345\274\203") + QString::number(cardNumToDiscard)
					+ trUtf8("\345\274\240\346\211\213\347\211\214"));
	shoupaiNumToDiscard = cardNumToDiscard;

	// Ensure that all cards are available and unselected
	for (std::list<Shoupai *>::iterator iter = shoupaiList.begin();
			iter != shoupaiList.end(); ++iter) {
		(*iter)->setUnselected();
		(*iter)->setSelectable();
	}
	selectedAbandonList.clear();
	okButton->setDisabled();
	cancelButton->setDisabled();
	abandonButton->setDisabled();
	disableAllPlayers();
	wujiangA->disableAllSkillButtons();
	zhuangbeiA->setSelectable(0, false, true);
	zhuangbeiA->setSelectable(1, false, true);
	zhuangbeiA->setSelectable(2, false, true);
	zhuangbeiA->setSelectable(3, false, true);

	exec();

	discardIndexList.clear();
	collectDiscardedShoupai();
	clearAbandonData();

	printDebug("MainWindow::discardCard");
	printDebug(discardInterpret(discardIndexList, myPlayer()));
	endResponse();
	return discardIndexList;
}

sgs::DataType::Message * MainWindow::useCardResponse() {
	if (AICheckBox->isChecked()) {
		return innerAI->useCardResponse();
	}
	printDebug("MainWindow::useCardResponse: start");
	responseType = UseCard;
	cardNormalize();
	playerChooseNormalize();
	skillNormalize();
	checkButtons();

	audioPlayer->playSound(YourTurn);
	exec();
	sgs::Derive::MCard * useZhuangbei = collectZhuangbei();
	if (useZhuangbei) {
		printDebug("MainWindow::useCardResponse: ");
		printDebug(messageInterpret(useZhuangbei));
		endResponse();
		return useZhuangbei;
	}
	sgs::Derive::MSkill * useSkill = collectSkill();
	if (useSkill) {
		printDebug("MainWindow::useCardResponse: ");
		printDebug(messageInterpret(useSkill));
		endResponse();
		return useSkill;
	}

	sgs::Derive::MCard * returnMessage = collectZhuangbei();

	if (isGoingToAbandon)
		returnMessage = 0;
	else {

		returnMessage = new sgs::Derive::MCard(false,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PHAND,
				getIndex(selectedShoupaiList.back()));

		// add targets
		if (selectedShoupaiList.back()->card()->getCardType()
				== sgs::ConstData::JIEDAO) {

			returnMessage->addto(selectedPlayerAreaList.back()->getPlayer());
			returnMessage->addto(selectedPlayerAreaList.front()->getPlayer());

		} else {
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
		}

		// add target for tao
		if (selectedShoupaiList.back()->card()->getCardType()
				== sgs::ConstData::TAO) {
			returnMessage->addto(GUIStaticData::getPlayer(playerIndex));
		}

		// add target for shandian
		if (selectedShoupaiList.back()->card()->getCardType()
				== sgs::ConstData::SHANDIAN) {
			returnMessage->addto(GUIStaticData::getPlayer(playerIndex));
		}
	}
	printDebug("MainWindow::useCardResponse: ");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::taoOrNot(sgs::DataType::Player * from,
		int neededTaoNumber) {
	if (AICheckBox->isChecked()) {
		return innerAI->taoOrNot(from, neededTaoNumber);
	}
	printDebug("MainWindow::taoOrNot: start");

	responseType = TaoOrNot;
	cardNormalize();
	playerChooseNormalize();
	skillNormalize();
	checkButtons();

	if (from->seat() + 1 != playerIndex) {
		if (getDialogResponse(
				wujiangDisplayName(from->type())
						+ trUtf8(
								"\346\277\222\346\255\273\357\274\214\345\205\261\351\234\200\350\246\201")
						+ QString::number(neededTaoNumber)

						+ trUtf8(
								"\344\270\252\346\241\203\345\255\220\357\274\214\350\246\201\344\270\215\350\246\201\346\225\221\345\212\251\357\274\237"))
				== 0) {
			printDebug("MainWindow::taoOrNot: response canceled by user");
			endResponse();
			return 0;
		}
	} else {
		showTipMessage(
				trUtf8("\344\275\240\351\234\200\350\246\201")
						+ QString::number(neededTaoNumber)
						+ trUtf8(
								"\344\270\252\346\241\203\345\255\220\346\235\245\346\225\221\345\212\251\350\207\252\345\267\261"));
	}
	exec();
	sgs::Derive::MSkill * useSkill = collectSkill();
	if (useSkill) {
		printDebug("MainWindow::taoOrNot: (use skill)");
		printDebug(messageInterpret(useSkill));
		endResponse();
		return useSkill;
	}

	sgs::Derive::MCard * returnMessage = 0;
	if (cancelResponse) {
		printDebug("MainWindow::taoOrNot: cancelled");
		returnMessage = 0;
	} else {
		returnMessage = new sgs::Derive::MCard(false,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PHAND,
				getIndex(selectedShoupaiList.back()), from);
	}
	printDebug("MainWindow::taoOrNot: ");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::shanOrNot(sgs::DataType::Player * from,
		const sgs::DataType::Card * card) {
	if (AICheckBox->isChecked()) {
		return innerAI->shanOrNot(from, card);
	}
	printDebug("MainWindow::shanOrNot: start");

	responseType = ShanOrNot;
	cardNormalize();
	playerChooseNormalize();
	skillNormalize();
	checkButtons();

	if (from && card) {
		showTipMessage(
				wujiangDisplayName(from->type())
						+ trUtf8(
								"\345\257\271\344\275\240\344\275\277\347\224\250\344\272\206")
						+ cardFullDisplayName(card, false)
						+ trUtf8(
								"\357\274\214\350\257\267\347\224\250\351\227\252\346\235\245\345\223\215\345\272\224"));
	} else {
		showTipMessage(
				trUtf8(
						"\357\274\214\350\257\267\347\224\250\351\227\252\346\235\245\345\223\215\345\272\224"));
	}
	exec();
	sgs::Derive::MCard * useZhuangbei = collectZhuangbei();
	if (useZhuangbei) {
		printDebug("MainWindow::shanOrNot: (use equip)");
		printDebug(messageInterpret(useZhuangbei));
		endResponse();
		return useZhuangbei;
	}
	sgs::Derive::MSkill * useSkill = collectSkill();
	if (useSkill) {
		printDebug("MainWindow::shanOrNot: (use skill)");
		printDebug(messageInterpret(useSkill));
		endResponse();
		return useSkill;
	}
	sgs::Derive::MCard * returnMessage = 0;
	if (cancelResponse) {
		returnMessage = 0;
	} else {
		returnMessage = new sgs::Derive::MCard(false,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PHAND,
				getIndex(selectedShoupaiList.back()));
	}
	printDebug("MainWindow::shanOrNot: ");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::shanOrNot(sgs::DataType::Player * from,
		sgs::ConstData::HeroSkill skillType) {
	if (AICheckBox->isChecked()) {
		return innerAI->shanOrNot(from, skillType);
	}
	printDebug("MainWindow::shanOrNot (skill version): start");

	responseType = ShanOrNot;
	cardNormalize();
	playerChooseNormalize();
	skillNormalize();
	checkButtons();

	showTipMessage(
			wujiangDisplayName(from->type())
					+ trUtf8(
							"\344\275\277\347\224\250\344\272\206\346\212\200\350\203\275")
					+ skillDisplayName(skillType)
					+ trUtf8(
							"\357\274\214\346\230\257\345\220\246\345\207\272\351\227\252\357\274\237"));
	exec();
	sgs::Derive::MSkill * useSkill = collectSkill();
	if (useSkill) {
		printDebug("MainWindow::shanOrNot (skill version): (use skill)");
		printDebug(messageInterpret(useSkill));
		endResponse();
		return useSkill;
	}

	sgs::Derive::MCard * returnMessage = 0;
	if (cancelResponse) {
		returnMessage = 0;
	} else {

		// Do not add target here
		returnMessage = new sgs::Derive::MCard(false,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PHAND,
				getIndex(selectedShoupaiList.back()));
	}
	printDebug("MainWindow::shanOrNot (skill version): ");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::shaOrNot(sgs::DataType::Player * from,
		const sgs::DataType::Card * card) {
	if (AICheckBox->isChecked()) {
		return innerAI->shaOrNot(from, card);
	}
	printDebug("MainWindow::shaOrNot: start");

	responseType = ShaOrNot;
	skillVerShaOrNot = true;
	cardNormalize();
	playerChooseNormalize();
	skillNormalize();
	checkButtons();

	if (from && card && from != myPlayer()) {
		showTipMessage(
				wujiangDisplayName(from->type())
						+ trUtf8(
								"\345\257\271\344\275\240\344\275\277\347\224\250\344\272\206")
						+ cardFullDisplayName(card, false)
						+ trUtf8(
								"\357\274\214\350\257\267\344\275\277\347\224\250\344\270\200\345\274\240\346\235\200"));
	} else {
		showTipMessage(
				trUtf8(
						"\344\275\240\347\216\260\345\234\250\345\217\257\344\273\245\344\275\277\347\224\250\344\270\200\345\274\240\346\235\200"));
	}
	exec();
	sgs::Derive::MCard * useZhuangbei = collectZhuangbei();
	if (useZhuangbei) {
		printDebug("MainWindow::shaOrNot: (use equip)");
		printDebug(messageInterpret(useZhuangbei));
		endResponse();
		return useZhuangbei;
	}
	sgs::Derive::MSkill * useSkill = collectSkill();
	if (useSkill) {
		printDebug("MainWindow::shaOrNot: (use skill)");
		printDebug(messageInterpret(useSkill));
		endResponse();
		return useSkill;
	}

	sgs::Derive::MCard * returnMessage = 0;
	if (cancelResponse) {
		returnMessage = 0;
	} else {

		// Do not add target here
		returnMessage = new sgs::Derive::MCard(false,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PHAND,
				getIndex(selectedShoupaiList.back()));
	}
	printDebug("MainWindow::shaOrNot: ");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::shaOrNot(sgs::DataType::Player * from,
		sgs::ConstData::HeroSkill skillType) {
	if (AICheckBox->isChecked()) {
		return innerAI->shaOrNot(from, skillType);
	}
	printDebug("MainWindow::shaOrNot (skill version): start");

	responseType = ShaOrNot;
	skillVerShaOrNot = true;
	cardNormalize();
	playerChooseNormalize();
	skillNormalize();
	checkButtons();

	showTipMessage(
			wujiangDisplayName(from->type())
					+ trUtf8(
							"\344\275\277\347\224\250\344\272\206\346\212\200\350\203\275")
					+ skillDisplayName(skillType)
					+ trUtf8(
							"\357\274\214\346\230\257\345\220\246\345\207\272\346\235\200\357\274\237"));
	exec();
	sgs::Derive::MSkill * useSkill = collectSkill();
	if (useSkill) {
		printDebug("MainWindow::shaOrNot (skill version): (use skill)");
		printDebug(messageInterpret(useSkill));
		endResponse();
		return useSkill;
	}

	sgs::Derive::MCard * returnMessage = 0;
	if (cancelResponse) {
		returnMessage = 0;
	} else {

		// Do not add target here
		returnMessage = new sgs::Derive::MCard(false,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PHAND,
				getIndex(selectedShoupaiList.back()));
	}
	printDebug("MainWindow::shaOrNot (skill version): ");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::wuxieOrNot(
		sgs::DataType::Message * originMsg, int count) {
	if (AICheckBox->isChecked()) {
		return innerAI->wuxieOrNot(originMsg, count);
	}
	printDebug("MainWindow::wuxieOrNot: start");

	if (!Interface::haveWuxie()) {
		printDebug("MainWindow::wuxieOrNot: don't have wuxie, return 0");
		printDebug("MainWindow::wuxieOrNot: over");
		return 0;
	}

	responseType = WuxieOrNot;
	cardNormalize();
	playerChooseNormalize();
	skillNormalize();
	checkButtons();

	sgs::Derive::MCard * messageToWixie =
			static_cast<sgs::Derive::MCard *>(originMsg);

	/*	if (messageToWixie->from() == myPlayer() && count == 0) {
	 printDebug(
	 "MainWindow::wuxieOrNot: from() == myPlayer() and count = 0, skip response, return 0");
	 printDebug("MainWindow::wuxieOrNot: over");
	 return 0;
	 }*/

	sgs::ConstData::CardType cardType = messageToWixie->card()->type();
	QString question = (wujiangDisplayName(messageToWixie->from()->type()));
	if (isJudgeCard(cardType)) {
		question.append(
				trUtf8("\347\232\204\345\210\244\345\256\232\347\211\214"));
		question.append(cardDisplayName(messageToWixie->card()->type()));
		question.append(
				trUtf8("\345\260\206\350\246\201\345\210\244\345\256\232"));
	} else {
		question.append(trUtf8("\344\275\277\347\224\250\344\272\206"));
		question.append(cardDisplayName(messageToWixie->card()->type()));
	}
	if (count > 0)
		question.append(
				trUtf8(
						"\357\274\214\345\267\262\347\273\217\350\242\253\346\227\240\346\207\210\345\217\257\345\207\273")
						+ QString::number(count) + trUtf8("\346\254\241"));

	question.append(
			trUtf8(
					"\357\274\214\344\275\240\345\217\257\344\273\245\344\275\277\347\224\250\346\227\240\346\207\210\345\217\257\345\207\273"));

	showTipMessage(question);

	exec();
	sgs::Derive::MSkill * useSkill = collectSkill();
	if (useSkill) {
		printDebug("MainWindow::wuxieOrNot: (use skill) ");
		printDebug(messageInterpret(useSkill));
		endResponse();
		return useSkill;
	}

	sgs::Derive::MCard * returnMessage = 0;
	if (cancelResponse) {
		returnMessage = 0;
	} else {

		// Do not add target here
		returnMessage = new sgs::Derive::MCard(false,
				GUIStaticData::getPlayer(playerIndex), sgs::ConstData::PHAND,
				getIndex(selectedShoupaiList.back()));
	}
	printDebug("MainWindow::wuxieOrNot: ");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

bool MainWindow::useEquipOrNot(sgs::ConstData::CardType equipCardType,
		sgs::DataType::Player *targetPlayer) {
	if (AICheckBox->isChecked()) {
		return innerAI->useEquipOrNot(equipCardType, targetPlayer);
	}
	printDebug("MainWindow::useEquipOrNot: start");
	QString question;
	if (targetPlayer) {
		question.append(
				trUtf8("\346\230\257\345\220\246\350\246\201\345\257\271")
						+ wujiangDisplayName(targetPlayer->type())
						+ trUtf8("\345\217\221\345\212\250"));
	} else {
		question.append(
				trUtf8(
						"\346\230\257\345\220\246\350\246\201\345\217\221\345\212\250"));
	}
	question.append(cardDisplayName(equipCardType));
	question.append(trUtf8("\347\232\204\346\225\210\346\236\234\357\274\237"));
	bool result = getDialogResponse(question);
	printDebug(
			QString("MainWindow::useEquipOrNot: over, return ")
					+ QString(result ? "true" : "false"));
	return result;
}

bool MainWindow::useSkillOrNot(sgs::ConstData::HeroSkill skillType,
		sgs::DataType::Player * targetPlayer) {
	if (AICheckBox->isChecked()) {
		return innerAI->useSkillOrNot(skillType, targetPlayer);
	}
	printDebug("MainWindow::useSkillOrNot: start");
	QString question(trUtf8("\346\230\257\345\220\246\350\246\201"));
	if (targetPlayer) {
		question.append(
				trUtf8("\345\257\271")
						+ wujiangDisplayName(targetPlayer->type()));
	}
	question.append(trUtf8("\345\217\221\345\212\250\346\212\200\350\203\275"));
	question.append(skillDisplayName(skillType));
	question.append(trUtf8("\357\274\237"));
	bool result = getDialogResponse(question);
	printDebug(
			QString("MainWindow::useSkillOrNot: over, return ")
					+ QString(result ? "true" : "false"));
	return result;
}

bool MainWindow::useSkillOrNot(sgs::ConstData::HeroSkill skillType,
		sgs::DataType::Message * message) {
	if (AICheckBox->isChecked()) {
		return innerAI->useSkillOrNot(skillType, message);
	}
	printDebug("MainWindow::useSkillOrNot: start");

	sgs::Derive::MJudge * judgeMessage =
			dynamic_cast<sgs::Derive::MJudge *>(message);
	if (!judgeMessage) {
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::useSkillOrNot (message vesion): message type is not MJudge, message: "
						+ allMessageInterpret(message));
		pause();
	}

	QString question(wujiangDisplayName(judgeMessage->from()->type()));
	if (judgeMessage->cardJudge()) {
		question.append(
				trUtf8("\347\232\204\345\210\244\345\256\232\347\211\214"));
		question.append(cardDisplayName(judgeMessage->card()->type()));
	} else {
		question.append(skillDisplayName(judgeMessage->skill()));
	}
	question.append(
			judgeMessage->effect() ?
					GUIStaticData::judgePositive :
					GUIStaticData::judgeNegative);
	question.append(
			trUtf8(
					"\346\230\257\345\220\246\346\224\271\345\210\244\357\274\237"));
	bool result = getDialogResponse(question);
	printDebug(
			QString("MainWindow::useSkillOrNot (message vesion): over, return ")
					+ QString(result ? "true" : "false"));
	return result;
}

std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > MainWindow::chooseCardResponse(
		sgs::DataType::Player *targetPlayer, bool isHandSelectable,
		bool isEquipSelectable, bool isJudgeSelectable, int num,
		sgs::ConstData::CardType reason) {
	if (AICheckBox->isChecked()) {
		return innerAI->chooseCardResponse(targetPlayer, isHandSelectable,
				isEquipSelectable, isJudgeSelectable, num, reason);
	}

	QString text(trUtf8("\351\200\211\346\213\251"));
	text.append(QString::number(num));
	text.append(trUtf8("\345\274\240\345\215\241\347\211\214"));
	return cardContainer->chooseCard(text, targetPlayer, isHandSelectable,
			isEquipSelectable, isJudgeSelectable, num, reason);
}

std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > MainWindow::chooseCardResponse(
		sgs::DataType::Player *targetPlayer, bool isHandSelectable,
		bool isEquipSelectable, bool isJudgeSelectable, int num,
		sgs::ConstData::HeroSkill reason) {
	if (AICheckBox->isChecked()) {
		return innerAI->chooseCardResponse(targetPlayer, isHandSelectable,
				isEquipSelectable, isJudgeSelectable, num, reason);
	}

	QString text(trUtf8("\351\200\211\346\213\251"));
	text.append(QString::number(num));
	text.append(trUtf8("\345\274\240\345\215\241\347\211\214"));
	return cardContainer->chooseCard(text, targetPlayer, isHandSelectable,
			isEquipSelectable, isJudgeSelectable, num, reason);
}

bool MainWindow::yesOrNot(sgs::ConstData::CardType reason) {
	if (AICheckBox->isChecked()) {
		return innerAI->yesOrNot(reason);
	}

	printDebug("MainWindow::yesOrNot(card version): start");
	QString question;
	if (reason == sgs::ConstData::CIXIONG) {
		question.append(
				trUtf8(
						"\346\230\257\345\220\246\350\256\251\345\257\271\346\226\271\346\221\270\344\270\200\345\274\240\347\211\214\357\274\210\345\220\246\345\210\231\350\207\252\345\267\261\345\274\203\344\270\200\345\274\240\347\211\214\357\274\211\357\274\237"));
	}
	bool result = getDialogResponse(question);
	printDebug(
			QString("MainWindow::yesOrNot(card version): over, return ")
					+ QString(result ? "true" : "false"));
	return result;
}

bool MainWindow::yesOrNot(sgs::ConstData::HeroSkill reason) {
	if (AICheckBox->isChecked()) {
		return innerAI->yesOrNot(reason);
	}

	printDebug("MainWindow::yesOrNot(skill version): start");
	QString question;
	if (reason == sgs::ConstData::GANGLIE) {
		question.append(
				trUtf8(
						"\346\230\257\345\220\246\345\274\2032\345\274\240\346\211\213\347\211\214\357\274\210\345\220\246\345\210\231\345\217\227\345\210\2601\347\202\271\344\274\244\345\256\263\357\274\211"));
	}
	bool result = getDialogResponse(question);
	printDebug(
			QString("MainWindow::yesOrNot(skill version): over, return ")
					+ QString(result ? "true" : "false"));
	return result;
}

int MainWindow::chooseWugu(
		const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wuguCards) {
	if (AICheckBox->isChecked()) {
		return innerAI->chooseWugu(wuguCards);
	}

	showWugu(wuguCards);
	return wugufengdengBox->chooseWugu(wuguCards);
}

void MainWindow::chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
		std::vector<const sgs::DataType::Card *>& buttom) {
	if (AICheckBox->isChecked()) {
		innerAI->chooseGuanxing(top, buttom);
		return;
	}
	guanxingBox->chooseGuanxing(top, buttom);
}

sgs::DataType::Message * MainWindow::getTuxi() {
	if (AICheckBox->isChecked()) {
		return innerAI->getTuxi();
	}
	responseType = GetTuxi;
	printDebug("MainWindow::getTuxi: start");
	if (getDialogResponse(
			trUtf8(
					"\346\230\257\345\220\246\350\246\201\344\275\277\347\224\250\346\212\200\350\203\275\347\252\201\350\242\255\357\274\237"))
			== 0) {
		printDebug("MainWindow::getTuxi: response canceled by user");
		endResponse();
		return 0;
	} else {
		showTipMessage(
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\350\207\263\344\270\244\345\220\215\347\252\201\350\242\255\347\233\256\346\240\207"));
	}
	cardNormalize();
	playerChooseNormalize();
	checkButtons();
	exec();

	sgs::Derive::MSkill * returnMessage = 0;
	if (cancelResponse) {
		printDebug("MainWindow::getTuxi: cancelled");
		returnMessage = 0;
	} else {
		if (tuxiList.size() == 1) {
			returnMessage = new sgs::Derive::MTuXi(myPlayer(),
					tuxiList.front().second->getPlayer(),
					tuxiList.front().first);
		} else {
			returnMessage = new sgs::Derive::MTuXi(myPlayer(),
					tuxiList.front().second->getPlayer(),
					tuxiList.front().first, tuxiList.back().second->getPlayer(),
					tuxiList.back().first);
		}
	}
	printDebug("MainWindow::getTuxi: over");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::getYiji(const sgs::DataType::Card * card1,
		const sgs::DataType::Card * card2) {
	if (AICheckBox->isChecked()) {
		return innerAI->getYiji(card1, card2);
	}
	printDebug("MainWindow::getYiji: start");
	responseType = GetYiji;
	sgs::DataType::Player * player1, *player2;

	cardViewer->setGeometry(
			QRect(
					mainFrame->geometry().center()
							- QPoint(cardViewer->width() / 2,
									cardViewer->height() / 5),
					cardViewer->size()));
	cardViewer->showViewer(card1, card2);

	cardNormalize();
	playerChooseNormalize();
	checkButtons();
	exec();
	player1 = selectedPlayerAreaList.back()->getPlayer();

	cardViewer->setGeometry(
			QRect(
					mainFrame->geometry().center()
							- QPoint(cardViewer->width() / 2,
									cardViewer->height() / 5),
					cardViewer->size()));
	cardViewer->showSecondViewer();

	cardNormalize();
	playerChooseNormalize();
	checkButtons();
	exec();
	cardViewer->hide();
	player2 = selectedPlayerAreaList.back()->getPlayer();
	sgs::Derive::MSkill * returnMessage = new sgs::Derive::MYiJi(myPlayer(),
			player1, card1, player2, card2);
	printDebug("MainWindow::getYiji: over");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

sgs::DataType::Message * MainWindow::getLiuli(
		sgs::DataType::Player * attacker) {
	if (AICheckBox->isChecked()) {
		return innerAI->getLiuli(attacker);
	}
	responseType = GetLiuli;
	liuliAttacker = attacker;
	printDebug("MainWindow::getLiuli: start");
	if (getDialogResponse(
			wujiangDisplayName(attacker->type())
					+ trUtf8(
							"\345\257\271\344\275\240\344\275\277\347\224\250\344\272\206\346\235\200\357\274\214\346\230\257\345\220\246\350\246\201\344\275\277\347\224\250\346\212\200\350\203\275\346\265\201\347\246\273\357\274\237"))
			== 0) {
		printDebug("MainWindow::getLiuli: response canceled by user");
		endResponse();
		return 0;
	}
	cardNormalize();
	playerChooseNormalize();
	checkButtons();
	exec();

	sgs::Derive::MSkill * returnMessage = 0;
	if (cancelResponse) {
		printDebug("MainWindow::getLiuli: cancelled");
		returnMessage = 0;
	} else {
		CardPosPair liuliPair = selectedSkillCardVec.back();
		returnMessage = new sgs::Derive::MLiuLi(myPlayer(), liuliPair.first, liuliPair.second, selectedPlayerAreaList.back()->getPlayer());
	}
	printDebug("MainWindow::getLiuli: over");
	printDebug(messageInterpret(returnMessage));
	endResponse();
	return returnMessage;
}

std::pair<sgs::ConstData::CardColor, int> MainWindow::respondFanjian(
		sgs::DataType::Player * zhouyu) {
	sgs::ConstData::CardColor choosenColor = runFanjian();
	QString text(
			trUtf8(
					"\351\200\211\346\213\251\345\221\250\347\221\234\347\232\204\344\270\200\345\274\240\346\211\213\347\211\214"));
	std::pair<sgs::ConstData::CardColor, int> choosen;
	choosen.first = choosenColor;
	choosen.second = cardContainer->chooseCard(text, zhouyu, true, false, false,
			1, sgs::ConstData::hkNone).back().second;
	return choosen;
}

void MainWindow::collectDiscardedShoupai() {
	for (std::list<Shoupai *>::const_iterator iter =
			selectedAbandonList.begin(); iter != selectedAbandonList.end();
			++iter) {
		discardIndexList.push_back(getIndex(*iter));
	}
}

void MainWindow::clearAbandonData() {
	selectedAbandonList.clear();
	shoupaiNumToDiscard = 0;
	// DO NOT clear discardIndexList herer because it is return value!!
}

} /* namespace sgsui */
