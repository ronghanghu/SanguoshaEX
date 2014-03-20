/*
 * sgsui_MainWindow_Debug.cpp
 *
 *  Created on: May 1, 2012
 *      Author: latios
 */

#include "sgsui_MainWindow.h"
#include "sgsui_PlayerArea.h"
#include "sgsui_CardFrame.h"
#include "sgsui_WujiangArea.h"
#include "sgsui_PosAnimation.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"
#include "sgsui_AudioPlayer.h"
#include "sgsdata_msg.h"
#include "sgsdata_player.h"
#include "sgsdata_gamedata.h"

#include "sgsdata_extern.h"
#include "sgsdata_card.h"

namespace sgsui {

void MainWindow::initiateDebug() {
	debugTimer = new QTimer(this);
	connect(autorefreshCheckBox, SIGNAL(clicked(bool)), this,
			SLOT(setAutoRefresh(bool)));
	connect(autorefreshSpinBox, SIGNAL(valueChanged(int)), this,
			SLOT(refreshFrequencyChanged(int)));
	connect(debugTimer, SIGNAL(timeout()), this, SLOT(refreshData()));
	connect(refreshPlayerButton, SIGNAL(clicked()), this,
			SLOT(refreshPlayer()));
	connect(playerSpinBox, SIGNAL(valueChanged(int)), this,
			SLOT(refreshPlayer()));
	connect(refreshDataButton, SIGNAL(clicked()), this, SLOT(refreshData()));
	connect(refreshHistoryButton, SIGNAL(clicked()), this,
			SLOT(refreshHistory()));

	connect(exchangeButton, SIGNAL(clicked()), this, SLOT(exchangeCard()));
	connect(setHPButton, SIGNAL(clicked()), this, SLOT(setHPDebug()));

	connect(debugButton1, SIGNAL(clicked()), this, SLOT(debug1()));
	connect(debugButton2, SIGNAL(clicked()), this, SLOT(debug2()));
	connect(debugButton3, SIGNAL(clicked()), this, SLOT(debug3()));
	connect(debugButton4, SIGNAL(clicked()), this, SLOT(debug4()));
}

void MainWindow::debug1() {
	printDebug("<font color=red><b>Debug1 called</b></font>");

	using namespace sgs::ConstData;
	addJudgeAtIndex(1, SISHU);
	addJudgeAtIndex(1, SHANDIAN);
	addJudgeAtIndex(2, SISHU);
	addJudgeAtIndex(2, SHANDIAN);
}

void MainWindow::debug2() {
	printDebug("<font color=red><b>Debug2 called</b></font>");

	using namespace sgs::ConstData;
}

void MainWindow::debug3() {
	printDebug("<font color=red><b>Debug3 called</b></font>");
	std::vector < std::pair<const sgs::DataType::Card *, bool> > temp;

	using namespace sgs::ExternData;
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[0], true));
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[1], true));
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[2], true));
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[3], true));
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[4], true));
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[5], true));
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[6], true));
	temp.push_back(
			std::pair<const sgs::DataType::Card *, bool>(&card[7], true));
	showWugu(temp);
}

void MainWindow::debug4() {
	if (isBlocked()) {
		printDebug(
				"<font color=red><b>Warning: </b></font>MainWindow::debug4: MainWindow is still blocking!");
		return;
	}
	printDebug("show name");

	using namespace sgs::ConstData;
	printDebug(cardDisplayName(ZHUGE));
	printDebug(cardDisplayName(QINGGANG));
	printDebug(cardDisplayName(HANBING));
	printDebug(cardDisplayName(CIXIONG));
	printDebug(cardDisplayName(GUANSHI));
	printDebug(cardDisplayName(YINYUE));
	printDebug(cardDisplayName(QINGLONG));
	printDebug(cardDisplayName(GUDING));
	printDebug(cardDisplayName(ZHANGBA));
	printDebug(cardDisplayName(FANGTIAN));
	printDebug(cardDisplayName(QILIN));
	printDebug(cardDisplayName(ZHUQUE));
	printDebug(cardDisplayName(BAIYIN));
	printDebug(cardDisplayName(TENGJIA));
	printDebug(cardDisplayName(BAGUA));
	printDebug(cardDisplayName(RENWANG));
	printDebug(cardDisplayName(CHITU));
	printDebug(cardDisplayName(DAWAN));
	printDebug(cardDisplayName(ZICI));
	printDebug(cardDisplayName(DILU));
	printDebug(cardDisplayName(JUEYING));
	printDebug(cardDisplayName(ZHUAHUANG));
	printDebug(cardDisplayName(HUALIU));
}

void MainWindow::refreshPlayer() {
	playerText->clear();
	if (GUIStaticData::isGameOver()) {
		playerText->append("Game Over");
		return;
	}

	if (GUIStaticData::isPlayersCreated()) {
		int playerSeat = playerSpinBox->value();
		sgs::DataType::Player * player = 0;
		if (playerSeat + 1 <= GUIStaticData::getPlayerCount()) {
			player = GUIStaticData::getPlayer(playerSeat + 1);
			playerText->append(
					"player " + QString::number(playerSeat)
							+ wujiangDisplayName(player->type()));
			playerText->append("Role: " + roleDisplayName(player->role()));
			playerText->append("HP: " + QString::number(player->hp()));

			QString wuqiStr("Weapon: ");
			wuqiStr.append(cardFullDisplayName(player->weapon()));
			playerText->append(wuqiStr);
			QString fangjuStr("Armor: ");
			fangjuStr.append(cardFullDisplayName(player->armor()));
			playerText->append(fangjuStr);
			QString jianmaStr("Atk(-1): ");
			jianmaStr.append(cardFullDisplayName(player->atkhorse()));
			playerText->append(jianmaStr);
			QString jiamaStr("Dfd(+1): ");
			jiamaStr.append(cardFullDisplayName(player->dfdhorse()));
			playerText->append(jiamaStr);

			int handnumber = player->handnum();
			QString handCardStr(QString::number(handnumber));
			handCardStr.append(" handcard(s): ");
			for (int j = 0; j < handnumber; ++j) {
				handCardStr.append(cardFullDisplayName(player->hand(j)));
				handCardStr.append(';');
			}
			playerText->append(handCardStr);

			int judgenumber = player->judgenum();
			QString judgeStr(QString::number(judgenumber));
			judgeStr.append(" judgecard(s): ");
			for (int j = 0; j < judgenumber; ++j) {
				judgeStr.append(cardFullDisplayName(player->judge(j)));
				judgeStr.append(';');
			}
			playerText->append(judgeStr);
		} else {
			playerText->append("This player does not exist");
		}
	} else {
		playerText->append("Players have not been created yet");
	}
}

void MainWindow::refreshData() {
	dataText->clear();
	if (GUIStaticData::isGameOver()) {
		playerText->append("Game Over");
		return;
	}

	if (GUIStaticData::isPlayersCreated()) {
		std::list<const sgs::DataType::Card *> totalCardList;
		std::list<const sgs::DataType::Card *> missingCardList;
		int cardDeckSize = GUIStaticData::getCardDeckSize();
		dataText->append("CardDeck: size = " + QString::number(cardDeckSize));
		for (int i = 0; i < cardDeckSize; ++i) {
			const sgs::DataType::Card * card = GUIStaticData::getCardDeckAt(i);
			totalCardList.push_back(card);
			QString cardText(
					QString::number(i + 1) + QString(i < 9 ? "  " : " "));
			if (i < 9) {
				cardText.append("  ");
			} else {
				cardText.append(" ");
			}
			cardText.append(cardFullDisplayName(card));

			if (card->type() != card->mask()) {
				cardText.append(" mask ");
				cardText.append(cardDisplayName(card->mask()));
			}
			dataText->append(cardText);
		}
		int dustbinSize = GUIStaticData::getDustbinSize();
		dataText->append("Dustbin: size = " + QString::number(dustbinSize));
		for (int i = 0; i < dustbinSize; ++i) {
			const sgs::DataType::Card * card = GUIStaticData::getDustbinAt(i);
			totalCardList.push_back(card);
			QString cardText(
					QString::number(i + 1) + QString(i < 9 ? "  " : " "));
			if (i < 9) {
				cardText.append("  ");
			} else {
				cardText.append(" ");
			}
			cardText.append(cardFullDisplayName(card));

			if (card->type() != card->mask()) {
				cardText.append(" mask ");
				cardText.append(cardDisplayName(card->mask()));
			}
			dataText->append(cardText);
		}

		int playerCardNum = 0;
		QString playerCardStr("players': ");
		sgs::DataType::Player * player = 0;
		for (int index = 1, playerCount = GUIStaticData::getPlayerCount();
				index <= playerCount; ++index) {
			player = GUIStaticData::getPlayer(index);
			if (player->weapon()) {
				++playerCardNum;
				totalCardList.push_back(player->weapon());
			}
			if (player->armor()) {
				++playerCardNum;
				totalCardList.push_back(player->armor());
			}
			if (player->atkhorse()) {
				++playerCardNum;
				totalCardList.push_back(player->atkhorse());
			}
			if (player->dfdhorse()) {
				++playerCardNum;
				totalCardList.push_back(player->dfdhorse());
			}

			int handnum = player->handnum();
			playerCardNum += handnum;
			for (int j = 0; j < handnum; ++j) {
				totalCardList.push_back(player->hand(j));
			}

			int judgenum = player->judgenum();
			playerCardNum += judgenum;
			for (int j = 0; j < judgenum; ++j) {
				totalCardList.push_back(player->judge(j));
			}
		}
		playerCardStr.append(QString::number(playerCardNum));
		dataText->append(playerCardStr);

		QString allCardStr("total: ");
		allCardStr.append(
				QString::number(playerCardNum + cardDeckSize + dustbinSize));
		dataText->append(allCardStr);

		QString missingStr("missing: ");
		for (int i = 0; i < 108; ++i) {
			const sgs::DataType::Card * thiscard = sgs::ExternData::card + i;
			bool thiscardExist = false;
			for (std::list<const sgs::DataType::Card *>::iterator iter =
					totalCardList.begin(); iter != totalCardList.end();
					++iter) {
				if (*iter == thiscard) {
					thiscardExist = true;
					totalCardList.erase(iter);
					break;
				}
			}
			if (!thiscardExist) {
				missingCardList.push_back(thiscard);
			}
		}
		missingStr.append(QString::number(missingCardList.size()));
		dataText->append(missingStr);
		for (std::list<const sgs::DataType::Card *>::iterator iter =
				missingCardList.begin(); iter != missingCardList.end();
				++iter) {
			const sgs::DataType::Card * card = (*iter);
			QString missingCardText(cardFullDisplayName(card));
			if (card->type() != card->mask()) {
				missingCardText.append(" mask ");
				missingCardText.append(cardDisplayName(card->mask()));
			}
			dataText->append(missingCardText);
		}

	} else {
		dataText->append("Players have not been created yet");
	}
}

void MainWindow::refreshHistory() {
	historyMessageText->clear();
	if (GUIStaticData::isGameOver()) {
		historyMessageText->append("Game Over");
		return;
	}

	if (GUIStaticData::isPlayersCreated()) {
		using namespace sgs::ConstData;
		MessageType messageType;

		QString text = historyComboBox->currentText();
		printDebug(text);
		if (text == "HITCARD (MCard)") {
			messageType = HITCARD;
		} else if (text == "USECARD (MCard)") {
			messageType = USECARD;
		} else if (text == "USESKILL (MSkill)") {
			messageType = USESKILL;
		} else if (text == "HURT (MHurt)") {
			messageType = HURT;
		} else if (text == "TRANSCARD (MTransCard)") {
			messageType = TRANSCARD;
		} else if (text == "SWITCHPHASE (MSwitchPhase)") {
			messageType = SWITCHPHASE;
		} else if (text == "DYING (MDying)") {
			messageType = DYING;
		} else if (text == "KILL (MKill)") {
			messageType = KILL;
		} else if (text == "JUDGE (MJudge)") {
			messageType = JUDGE;
		} else {
			messageType = mtNone;
		}
		int count = historySpinBox->value();
		std::vector<sgs::DataType::Message *>::const_reverse_iterator citer =
				GUIStaticData::getHistoryVec().rbegin();
		for (int i = 0;
				i < count && citer != GUIStaticData::getHistoryVec().rend();
				++citer) {
			if (messageType == mtNone || (*citer)->type() == messageType) {
				historyMessageText->append(allMessageInterpret(*citer));
				++i;
			}
		}
	} else {
		historyMessageText->append("Players have not been created yet");
	}
}

void MainWindow::exchangeCard() {
	resultLabel->clear();
	if (GUIStaticData::isGameOver()) {
		resultLabel->setText("Error: game is over");
		return;
	}

	if (GUIStaticData::isPlayersCreated()) {
		int cardDeckSize = GUIStaticData::getCardDeckSize();
		int dustbinSize = GUIStaticData::getDustbinSize();
		int cardindex1 = card1->value() - 1;
		int cardindex2 = card2->value() - 1;
		bool isDustbin1 = dustbinCheckBox1->isChecked();
		bool isDustbin2 = dustbinCheckBox2->isChecked();

		const sgs::DataType::Card *card1 = 0, *card2 = 0;

		if (isDustbin1) {
			if (cardindex1 < dustbinSize) {
				card1 = GUIStaticData::getDustbinAt(cardindex1);
			} else {
				resultLabel->setText("Error: card1 out of range");
			}
		} else {
			if (cardindex1 < cardDeckSize) {
				card1 = GUIStaticData::getCardDeckAt(cardindex1);
			} else {
				resultLabel->setText("Error: card1 out of range");
			}
		}

		if (isDustbin2) {
			if (cardindex2 < dustbinSize) {
				card2 = GUIStaticData::getDustbinAt(cardindex2);
			} else {
				resultLabel->setText("Error: card2 out of range");
			}
		} else {
			if (cardindex2 < cardDeckSize) {
				card2 = GUIStaticData::getCardDeckAt(cardindex2);
			} else {
				resultLabel->setText("Error: card2 out of range");
			}
		}

		// exchange cards
		if (card1 && card2) {
			if (isDustbin1)
				GUIStaticData::setDustbinAt(cardindex1, card2);
			else
				GUIStaticData::setCardDeckAt(cardindex1, card2);

			if (isDustbin2)
				GUIStaticData::setDustbinAt(cardindex2, card1);
			else
				GUIStaticData::setCardDeckAt(cardindex2, card1);

			resultLabel->setText("Exchange successful");
		}

	} else {
		resultLabel->setText("Error: players not created");
	}
}

void MainWindow::setHPDebug() {
	resultLabel->clear();
	if (GUIStaticData::isGameOver()) {
		resultLabel->setText("Error: game is over");
		return;
	}

	if (GUIStaticData::isPlayersCreated()) {
		int playerSeat = HPPlayerSpinBox->value();

		if (playerSeat < GUIStaticData::getPlayerCount()) {
			int HP = HPSpinBox->value();
			sgs::DataType::Player * player = sgs::ExternData::gamedata.players(
					playerSeat);

			if (player->hp() > 0 && HP <= player->maxHP()) {
				setHP(playerSeat + 1, HP);
				player->sethp() = HP;
				resultLabel->setText("HP set successfully");
			} else {
				resultLabel->setText("Error: already dead or overflow");
			}

		}

		else {
			resultLabel->setText("Error: player not exist");
		}
	} else {
		resultLabel->setText("Error: players not created");
	}
}

void MainWindow::setAutoRefresh(bool autorefresh) {
	if (autorefresh) {
		debugTimer->start(1000 * autorefreshSpinBox->value());
	} else {
		debugTimer->stop();
	}
	refreshDataButton->setDisabled(autorefresh);
}

void MainWindow::refreshFrequencyChanged(int time) {
	if (autorefreshCheckBox->isChecked()) {
		debugTimer->start(1000 * time);
	}
}

} /* namespace sgsui */
