/*
 * sgsai_AIZhaoyun.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIZHAOYUN_H_
#define SGSAI_AIZHAOYUN_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIZhaoyun: public AICommon {
public:
	explicit AIZhaoyun(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);

private:
	virtual sgs::DataType::Message * useCardResponse();
	virtual sgs::DataType::Message * shaOrNot(sgs::DataType::Player * /*from*/,
			const sgs::DataType::Card * /*card*/);
	virtual sgs::DataType::Message * shanOrNot(sgs::DataType::Player * /*from*/,
			const sgs::DataType::Card * /*card*/);
	sgs::Derive::MSkill * useLongdanInUsecard();
	sgs::Derive::MSkill * useLongdanInShaOrNot();
	sgs::Derive::MSkill * useLongdanInShanOrNot();
	const CardVec& shaCard();
	const CardVec& shanCard();
	CardVec shaVec;
	CardVec shanVec;
};

} /* namespace sgsai */
#endif /* SGSAI_AIZHAOYUN_H_ */
