/*
 * sgsui_nameConvert.h
 *
 *  Created on: Mar 20, 2012
 *      Author: latios
 */

#ifndef SGSUI_NAMECONVERT_H_
#define SGSUI_NAMECONVERT_H_

#include <QString>
#include <vector>
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"

enum EquipType {
	NotEquip, Wuqi, Fangju, Jianma, Jiama
};

namespace sgsui {

QString phasePixmapStr(sgs::ConstData::PlayerPhase phase, bool isDying,
		bool isResponding);
QString phaseFramePixmapStr(sgs::ConstData::PlayerPhase phase, bool isDying,
		bool isResponding);
QString roleDisplayName(sgs::ConstData::PlayerRole playerRole);
QString roleSmallPixmapStr(sgs::ConstData::PlayerRole playerRole, bool dead =
		false);
QString rolePixmapStr(sgs::ConstData::PlayerRole playerRole,
		bool visible = true);
QString deadRolePixmapStr(sgs::ConstData::PlayerRole playerRole);
QString HPPixmapStr(int hp);
QString smallHPPixmapStr(int hp);
QString countrySmallPixmapStr(sgs::ConstData::HeroSide heroSide);
QString countryFramePixmapStr(sgs::ConstData::HeroSide heroSide);
QString cardNumberStr(int number, sgs::ConstData::CardColor cardColor);
QString cardColorStr(sgs::ConstData::CardColor cardColor);
QString cardColorDisplayName(sgs::ConstData::CardColor cardColor,
		bool richText = true);
QString bigCardColorStr(sgs::ConstData::CardColor cardColor);
QString cardPixmapStr(sgs::ConstData::CardType cardType);
QString cardSoundStr(sgs::ConstData::CardType cardType, bool sex = true);
bool isZhuangbeiCard(sgs::ConstData::CardType cardType);
bool isJinnangCard(sgs::ConstData::CardType cardType);
bool isJudgeCard(sgs::ConstData::CardType cardType);
QString cardDisplayName(sgs::ConstData::CardType cardType);
QString cardFullDisplayName(const sgs::DataType::Card * card, bool richText =
		true);
QString cardFullDisplayName(sgs::ConstData::CardType cardType,
		sgs::ConstData::CardColor cardColor, int number, bool richText = true);
QString cardNumberChar(int number);
QString zhuangbeiPixmapStr(sgs::ConstData::CardType cardType);
QString smallZhuangbeiPixmapStr(sgs::ConstData::CardType cardType);
QString cardFilenameStr(sgs::ConstData::CardType cardType);
QString wujiangSelfPixmapStr(sgs::ConstData::HeroType heroType);
QString wujiangMiniPixmapStr(sgs::ConstData::HeroType heroType);
QString wujiangOtherPixmapStr(sgs::ConstData::HeroType heroType);
QString wujiangCardPixmapStr(sgs::ConstData::HeroType heroType);
QString wujiangFilenameStr(sgs::ConstData::HeroType heroType);
QString wujiangDeathSoundStr(sgs::ConstData::HeroType heroType);
QString wujiangDisplayName(sgs::ConstData::HeroType heroType);
QString skillSoundStr(sgs::ConstData::HeroSkill heroSkill);
QString skillDisplayName(sgs::ConstData::HeroSkill heroSkill);
QString resultDisplayStr(bool win);
QString messageInterpret(const sgs::Derive::MCard * message);
QString messageInterpret(const sgs::Derive::MZhangBa * message);
QString messageInterpret(const sgs::Derive::MSkill * message);
QString messageInterpret(const sgs::Derive::MHurt * message);
QString messageInterpret(const sgs::Derive::MTransCard * message);
QString messageInterpret(const sgs::Derive::MSwitchPhase * message);
QString messageInterpret(const sgs::Derive::MDying * message);
QString messageInterpret(const sgs::Derive::MKill * message);
QString messageInterpret(const sgs::Derive::MJudge * message);
QString allMessageInterpret(const sgs::DataType::Message * message);
QString discardInterpret(const std::vector<int>& discardVec,
		sgs::DataType::Player * from);
QString selectInterpret(
		const std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> >& selectVec);
QString setColored(const QString &originalString, bool bold = true);
QString splashStr();
EquipType getEquipType(sgs::ConstData::CardType cardType);

} /* namespace sgsui */
#endif /* SGSUI_NAMECONVERT_H_ */
