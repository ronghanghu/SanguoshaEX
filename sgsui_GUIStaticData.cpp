/*
 * sgsui_GUIStaticData.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: latios
 */

#include "sgsui_GUIStaticData.h"
#include "sgsui_BlockLoop.h"
#include "sgsui_AudioPlayer.h"
#include "sgsui_output.h"
#include "sgsdata_extern.h"
#include "sgsdata_gamedata.h"
#include "sgsdata_player.h"
#include "sgsdata_platform.h"
#include "sgsdata_history.h"
#include "sgsdata_skill.h"
#include <QApplication>
#include <QtGui>
#include <cstdlib>

namespace sgsui {

bool GUIStaticData::playersCreated = false;
bool GUIStaticData::debugLogOn = false;
bool GUIStaticData::gameOver = false;
int GUIStaticData::options = 0;
int GUIStaticData::package = 0;
int GUIStaticData::fullPlayerCount = 2;
int GUIStaticData::humanPlayerIndex = 1;

const int GUIStaticData::sujiangDefaultHP = 4;
const sgs::ConstData::PlayerRole GUIStaticData::sujiangDefaultRole =
		sgs::ConstData::ZHONG;
const sgs::ConstData::HeroType GUIStaticData::sujiangDefaultHeroType =
		sgs::ConstData::htNone;
const sgs::ConstData::HeroSex GUIStaticData::sujiangDefaultSex =
		sgs::ConstData::MALE;
const sgs::ConstData::HeroSide GUIStaticData::sujiangDefaultSide =
		sgs::ConstData::QUN;

const int GUIStaticData::initWaitTime = 1000;
const int GUIStaticData::useCardAnimationDuration = 1000;
const int GUIStaticData::basicAnimationDuration = 1000;
const int GUIStaticData::damageAnimationDuration = 500;
const int GUIStaticData::lineAnimationDuration = 500;
const int GUIStaticData::blockingFrameMovingDuration = 100;
const int GUIStaticData::showTipDuration = 2000;
const int GUIStaticData::dialogFadeDuration = 250;
const int GUIStaticData::switchPhaseDuration = 300;
const int GUIStaticData::skillBlockDuration = 1000;
const int GUIStaticData::showSkillDuration = 2000;
const int GUIStaticData::showEquipDuration = 1000;
const int GUIStaticData::createPlayerDuration = 500;
const int GUIStaticData::dyingDuration = 800;
const int GUIStaticData::killDuration = 1000;
const int GUIStaticData::showRecoverDuration = 800;

QFont GUIStaticData::appFont("Microsoft YaHei", 11);
QFont GUIStaticData::buttonFont("FZLiBian-S02", 12);
QFont GUIStaticData::headingFont("FZLiBian-S02", 28);
QFont GUIStaticData::contentFont("FZLiBian-S02", 16);
QFont GUIStaticData::statusbarFont("Microsoft YaHei", 10);
QFont GUIStaticData::skillFont("FZLiBian-S02", 30);
QFont GUIStaticData::equipFont("FZLiBian-S02", 30);

const QString GUIStaticData::startingGame(
		QObject::trUtf8(
				"\346\255\243\345\234\250\345\220\257\345\212\250\344\270\211\345\233\275\346\235\200EX..."));
const QString GUIStaticData::initWindowWidgets(
		QObject::trUtf8(
				"\346\255\243\345\234\250\345\210\235\345\247\213\345\214\226\347\224\250\346\210\267\347\225\214\351\235\242\342\200\246\342\200\246"));
const QString GUIStaticData::initStyleSheet(
		QObject::trUtf8(
				"\346\255\243\345\234\250\345\210\235\345\247\213\345\214\226\346\240\267\345\274\217\350\241\250\342\200\246\342\200\246"));
const QString GUIStaticData::initAnimation(
		QObject::trUtf8(
				"\346\255\243\345\234\250\345\210\235\345\247\213\345\214\226\345\212\250\347\224\273\342\200\246\342\200\246"));
const QString GUIStaticData::initMusic(
		QObject::trUtf8(
				"\346\255\243\345\234\250\345\210\235\345\247\213\345\214\226\345\243\260\351\237\263\342\200\246\342\200\246"));
const QString GUIStaticData::initDebug(
		QObject::trUtf8(
				"\346\255\243\345\234\250\345\210\235\345\247\213\345\214\226\350\260\203\350\257\225\345\231\250\342\200\246\342\200\246"));
const QString GUIStaticData::initOver(
		QObject::trUtf8(
				"\345\210\235\345\247\213\345\214\226\345\256\214\346\257\225\357\274\214\346\255\243\345\234\250\346\211\223\345\274\200\346\270\270\346\210\217\347\225\214\351\235\242\342\200\246\342\200\246"));
const QString GUIStaticData::trustTurnedOn(
		QObject::trUtf8(
				"\345\267\262\345\274\200\345\220\257\346\211\230\347\256\241\346\250\241\345\274\217\357\274\214\344\270\213\346\254\241\345\223\215\345\272\224\346\227\266\347\224\237\346\225\210"));
const QString GUIStaticData::trustTurnedOff(
		QObject::trUtf8(
				"\345\267\262\345\205\263\351\227\255\346\211\230\347\256\241\346\250\241\345\274\217"));
const QString GUIStaticData::debugTurnedOn(
		QObject::trUtf8(
				"\345\267\262\345\274\200\345\220\257\350\260\203\350\257\225\346\250\241\345\274\217"));
const QString GUIStaticData::debugTurnedOff(
		QObject::trUtf8(
				"\345\267\262\345\205\263\351\227\255\350\260\203\350\257\225\346\250\241\345\274\217"));
const QString GUIStaticData::yourRoleIsZhu(
		QObject::trUtf8(
				"\346\202\250\347\232\204\350\272\253\344\273\275\346\230\257\344\270\273\345\205\254\357\274\214\350\257\267\351\200\211\346\213\251\346\255\246\345\260\206"));
const QString GUIStaticData::yourRoleIsZhong(
		QObject::trUtf8(
				"\346\202\250\347\232\204\350\272\253\344\273\275\346\230\257\345\277\240\350\207\243\357\274\214\350\257\267\351\200\211\346\213\251\346\255\246\345\260\206"));
const QString GUIStaticData::yourRoleIsFan(
		QObject::trUtf8(
				"\346\202\250\347\232\204\350\272\253\344\273\275\346\230\257\345\217\215\350\264\274\357\274\214\350\257\267\351\200\211\346\213\251\346\255\246\345\260\206"));
const QString GUIStaticData::yourRoleIsNei(
		QObject::trUtf8(
				"\346\202\250\347\232\204\350\272\253\344\273\275\346\230\257\345\206\205\345\245\270\357\274\214\350\257\267\351\200\211\346\213\251\346\255\246\345\260\206"));
const QString GUIStaticData::gamePaused(
		QObject::trUtf8(
				"\346\270\270\346\210\217\346\232\202\345\201\234\357\274\214\346\214\211F7\351\224\256\347\273\247\347\273\255"));
const QString GUIStaticData::singleStep(
		QObject::trUtf8(
				"\345\215\225\346\255\245\350\260\203\350\257\225\357\274\214\346\214\211F7\347\273\247\347\273\255"));
const QString GUIStaticData::quitOrNot(
		QObject::trUtf8(
				"\346\230\257\345\220\246\350\246\201\351\200\200\345\207\272\344\270\211\345\233\275\346\235\200EX \357\274\237"));
const QString GUIStaticData::pleaseChooseCard(
		QObject::trUtf8(
				"\351\200\211\346\213\251\344\270\200\345\274\240\346\211\213\347\211\214"));
const QString GUIStaticData::judgeCardText(
		QObject::trUtf8("\345\210\244\345\256\232\347\211\214"));
const QString GUIStaticData::judgePositive(
		QObject::trUtf8(
				"\357\274\214\345\210\244\345\256\232\347\273\223\346\236\234\357\274\232\347\224\237\346\225\210\357\274\201"));
const QString GUIStaticData::judgeNegative(
		QObject::trUtf8(
				"\357\274\214\345\210\244\345\256\232\347\273\223\346\236\234\357\274\232\344\270\215\347\224\237\346\225\210\357\274\201"));
const QString GUIStaticData::threeTargets(
		QObject::trUtf8(
				"\344\275\240\345\217\257\344\273\245\346\214\207\345\256\2323\344\270\252\347\233\256\346\240\207"));
const QString GUIStaticData::twoTargets(
		QObject::trUtf8(
				"\344\275\240\345\217\257\344\273\245\346\214\207\345\256\2322\344\270\252\347\233\256\346\240\207"));
const QString GUIStaticData::chooseWeaponOwner(
		QObject::trUtf8(
				"\351\200\211\346\213\251\344\270\200\344\270\252\346\234\211\346\255\246\345\231\250\347\232\204\350\247\222\350\211\262"));
const QString GUIStaticData::chooseJiedaoVictim(
		QObject::trUtf8(
				"\351\200\211\346\213\251\344\270\200\344\270\252\346\224\273\345\207\273\347\233\256\346\240\207\357\274\210\345\214\205\346\213\254\344\275\240\350\207\252\345\267\261\357\274\211"));
const QString GUIStaticData::chooseZhangbaTarget(
		QObject::trUtf8(
				"\350\257\267\351\200\211\346\213\251\344\270\200\344\270\252\346\224\273\345\207\273\347\233\256\346\240\207"));
const QString GUIStaticData::gameIsQuiting(
		QObject::trUtf8(
				"\346\255\243\345\234\250\351\200\200\345\207\272\344\270\211\345\233\275\346\235\200EX..."));

const QString GUIStaticData::backgroundMusicLocation("music/background.mp3");
const QUrl GUIStaticData::helpTextLocation("file:help/overview.html");
const QUrl GUIStaticData::aboutTextLocation("file:help/about.html");

const int GUIStaticData::maxUsedCardContain = 4;
const int GUIStaticData::defaultMaxCardSelect = 1;

bool GUIStaticData::isPlayersCreated() {
	return playersCreated;
}

void GUIStaticData::setPlayersCreated() {
	playersCreated = true;
}

bool GUIStaticData::isGameOver() {
	return gameOver;
}

void GUIStaticData::setGameOver() {
	gameOver = true;
}

bool GUIStaticData::isDebugLogOn() {
	return debugLogOn;
}

int GUIStaticData::getOptions() {
	return options;
}

int GUIStaticData::getPackage() {
	return package;
}

int GUIStaticData::getPlayerCount() {
	return fullPlayerCount;
}

int GUIStaticData::getHumanIndex() {
	return humanPlayerIndex;
}

void GUIStaticData::loadFonts() {
	QFontDatabase::addApplicationFont("font/FZLiBian-S02.TTF");
	appFont.setStyleStrategy(QFont::PreferAntialias);
	buttonFont.setStyleStrategy(QFont::PreferAntialias);
	headingFont.setStyleStrategy(QFont::PreferAntialias);
	contentFont.setStyleStrategy(QFont::PreferAntialias);
	statusbarFont.setStyleStrategy(QFont::PreferAntialias);
	skillFont.setStyleStrategy(QFont::PreferAntialias);
	equipFont.setStyleStrategy(QFont::PreferAntialias);
	QApplication::setFont(GUIStaticData::appFont);
}

int GUIStaticData::zhuangbeiIndex(sgs::ConstData::CardType cardType) {
	using namespace sgs::ConstData;
	switch (cardType) {

	case CHITU:
	case DAWAN:
	case ZICI:
		// jianma
		return 2;

	case DILU:
	case JUEYING:
	case ZHUAHUANG:
	case HUALIU:
		// jiama
		return 3;

	case BAIYIN:
	case TENGJIA:
	case BAGUA:
	case RENWANG:
		// fangju
		return 1;

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
		// wuqi
		return 0;

	default:
		// -1 indicates that the card is not zhuangbei card
		return -1;
	}
}

sgs::DataType::Player * GUIStaticData::getPlayer(int playerIndex) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	return gamedata.players(playerIndex);
}

sgs::ConstData::HeroType GUIStaticData::getPlayerType(int playerIndex) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	return gamedata.players(playerIndex)->type();
}

sgs::ConstData::HeroSex GUIStaticData::getPlayerSex(int playerIndex) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	return gamedata.players(playerIndex)->sex();
}

sgs::ConstData::HeroSide GUIStaticData::getPlayerSide(int playerIndex) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	return gamedata.players(playerIndex)->side();
}

sgs::ConstData::PlayerRole GUIStaticData::getPlayerRole(int playerIndex,
		bool visible) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	sgs::ConstData::PlayerRole role = gamedata.players(playerIndex)->role();
	if (!visible && role != sgs::ConstData::ZHU) {
		role = sgs::ConstData::prNone;
	}
	return role;
}

sgs::ConstData::HeroSkill GUIStaticData::getPlayerSkill(int playerIndex,
		int skillIndex) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	return gamedata.players(playerIndex)->skill(skillIndex).skill();
}

int GUIStaticData::getSkillCount(int playerIndex) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	return gamedata.players(playerIndex)->skillnum();
}

int GUIStaticData::getPlayerHP(int playerIndex) {
	using sgs::ExternData::gamedata;
	--playerIndex;
	return gamedata.players(playerIndex)->hp();
}

const sgs::DataType::Card * GUIStaticData::getCardDeckAt(int index) {
	using sgs::ExternData::platform;
	return platform.peekpool(index);
}

const sgs::DataType::Card * GUIStaticData::getDustbinAt(int index) {
	using sgs::ExternData::platform;
	return platform.peekdustbin(index);
}

void GUIStaticData::setCardDeckAt(int index, const sgs::DataType::Card *card) {
	using sgs::ExternData::platform;
	platform.setpool(index, card);
}

void GUIStaticData::setDustbinAt(int index, const sgs::DataType::Card *card) {
	using sgs::ExternData::platform;
	platform.setdustbin(index, card);
}

int GUIStaticData::getCardDeckSize() {
	using sgs::ExternData::platform;
	return platform.poolsize();
}

int GUIStaticData::getDustbinSize() {
	using sgs::ExternData::platform;
	return platform.dustbinsize();
}

const std::vector<sgs::DataType::Message *>& GUIStaticData::getHistoryVec() {
	using sgs::ExternData::history;
	return history.viewVec();
}

void GUIStaticData::quitGame() {
	printDebug("GUIStaticData::quitGame: start");
	BlockLoop::terminateAllLoops();
	AudioPlayer::terminateAllPlayers();
	printEndingMessage();
	QApplication::quit();
	exit(0);
}

void GUIStaticData::resetData() {
	playersCreated = false;
	gameOver = false;
}

} /* namespace sgsui */
