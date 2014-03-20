/*
 * sgsai_AICommon.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AICOMMON_H_
#define SGSAI_AICOMMON_H_

#include "sgsai_AIBasic.h"

namespace sgsai {

class AICommon: public AIBasic {
public:
	explicit AICommon(int seat);
	virtual bool useEquipOrNot(sgs::ConstData::CardType equipCardType,
			sgs::DataType::Player *targetPlayer);
	virtual std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > chooseCardResponse(
			sgs::DataType::Player *targetPlayer, bool isHandSelectable,
			bool isEquipSelectable, bool isJudgeSelectable, int num,
			sgs::ConstData::CardType reason);
	virtual std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > chooseCardResponse(
			sgs::DataType::Player *targetPlayer, bool isHandSelectable,
			bool isEquipSelectable, bool isJudgeSelectable, int num,
			sgs::ConstData::HeroSkill skill);
	virtual sgs::DataType::Message * wuxieOrNot(
			sgs::DataType::Message * originMsg, int count);
	virtual bool yesOrNot(sgs::ConstData::CardType reason);
	virtual bool yesOrNot(sgs::ConstData::HeroSkill reason);
	virtual int chooseWugu(
			const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wuguCards);
	virtual void chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
			std::vector<const sgs::DataType::Card *>& buttom);
	virtual sgs::DataType::Message * getTuxi(); // This function should not be called. AIZhangliao should override it.
	virtual sgs::DataType::Message * getYiji(const sgs::DataType::Card * card1,
			const sgs::DataType::Card * card2); // This function should not be called. AIGuojia should override it.
	virtual sgs::DataType::Message * getLiuli(sgs::DataType::Player * attacker); // This function should not be called. AIDaqiao should override it.
	virtual std::pair<sgs::ConstData::CardColor, int> respondFanjian(
			sgs::DataType::Player * zhouyu);
};

} /* namespace sgsai */
#endif /* SGSAI_AICOMMON_H_ */
