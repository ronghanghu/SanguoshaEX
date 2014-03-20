/*
 * sgsui_GUIStaticData.h
 *
 *  Created on: Apr 4, 2012
 *      Author: latios
 */

#ifndef SGSUI_GUISTATICDATA_H_
#define SGSUI_GUISTATICDATA_H_

#include "sgsui_InitiateBox.h"
#include "sgsdata_enum.h"
#include <QtGui>
#include <vector>

namespace sgs {
namespace DataType {
class Player;
class Card;
class Message;
}
}

namespace sgsui {

enum PixmapAnimationType {
	BlackSlashAnimation,
	RedSlashAnimation,
	FireSlashAnimation,
	ThunderSlashAnimation,
	JinkAnimation,
	PeachAnimation,
	AnalepticAnimation,
	DamageAnimation,
	LightningAnimation,
	ChainAnimation,
	DuelAnimation,
	WuxieAnimation
};

struct GUIStaticData {
	static bool isPlayersCreated();
	static void setPlayersCreated();
	static bool isGameOver();
	static void setGameOver();
	static bool isDebugLogOn();

	static int getOptions();
	static int getPackage();
	static int getPlayerCount();
	static int getHumanIndex();

	const static int sujiangDefaultHP;
	const static sgs::ConstData::PlayerRole sujiangDefaultRole;
	const static sgs::ConstData::HeroType sujiangDefaultHeroType;
	const static sgs::ConstData::HeroSex sujiangDefaultSex;
	const static sgs::ConstData::HeroSide sujiangDefaultSide;

	const static int initWaitTime;
	const static int useCardAnimationDuration;
	const static int basicAnimationDuration;
	const static int damageAnimationDuration;
	const static int lineAnimationDuration;
	const static int blockingFrameMovingDuration;
	const static int showTipDuration;
	const static int dialogFadeDuration;
	const static int switchPhaseDuration;
	const static int skillBlockDuration;
	const static int showSkillDuration;
	const static int showEquipDuration;
	const static int createPlayerDuration;
	const static int dyingDuration;
	const static int killDuration;
	const static int showRecoverDuration;

	const static QString startingGame;
	const static QString initWindowWidgets;
	const static QString initStyleSheet;
	const static QString initAnimation;
	const static QString initMusic;
	const static QString initDebug;
	const static QString initOver;
	const static QString trustTurnedOn;
	const static QString trustTurnedOff;
	const static QString debugTurnedOn;
	const static QString debugTurnedOff;
	const static QString yourRoleIsZhu;
	const static QString yourRoleIsZhong;
	const static QString yourRoleIsFan;
	const static QString yourRoleIsNei;
	const static QString gamePaused;
	const static QString singleStep;
	const static QString quitOrNot;
	const static QString pleaseChooseCard;
	const static QString judgeCardText;
	const static QString judgePositive;
	const static QString judgeNegative;
	const static QString threeTargets;
	const static QString twoTargets;
	const static QString chooseWeaponOwner;
	const static QString chooseJiedaoVictim;
	const static QString chooseZhangbaTarget;
	const static QString gameIsQuiting;

	const static QString backgroundMusicLocation;
	const static QUrl helpTextLocation;
	const static QUrl aboutTextLocation;

	const static int maxUsedCardContain;
	const static int defaultMaxCardSelect;

	static QFont appFont;
	static QFont buttonFont;
	static QFont headingFont;
	static QFont contentFont;
	static QFont statusbarFont;
	static QFont skillFont;
	static QFont equipFont;

	static void loadFonts();
	static int zhuangbeiIndex(sgs::ConstData::CardType cardType);
	static sgs::DataType::Player * getPlayer(int playerIndex);
	static sgs::ConstData::HeroType getPlayerType(int playerIndex);
	static sgs::ConstData::HeroSex getPlayerSex(int playerIndex);
	static sgs::ConstData::HeroSide getPlayerSide(int playerIndex);
	static sgs::ConstData::PlayerRole getPlayerRole(int playerIndex,
			bool visible = true);
	static sgs::ConstData::HeroSkill getPlayerSkill(int playerIndex,
			int skillIndex);
	static int getSkillCount(int playerIndex);
	static int getPlayerHP(int playerIndex);
	static const sgs::DataType::Card * getCardDeckAt(int index);
	static const sgs::DataType::Card * getDustbinAt(int index);
	static void setCardDeckAt(int index, const sgs::DataType::Card *card);
	static void setDustbinAt(int index, const sgs::DataType::Card *card);
	static int getCardDeckSize();
	static int getDustbinSize();
	static const std::vector<sgs::DataType::Message *>& getHistoryVec();
	static void quitGame();
	static void resetData();

private:
	static bool playersCreated, debugLogOn, gameOver;
	static int options, package, fullPlayerCount, humanPlayerIndex;

	friend void InitiateBox::start();
};

} /* namespace sgsui */
#endif /* SGSUI_GUISTATICDATA_H_ */
