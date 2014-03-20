/*
 * sgsai_AIGuanyu.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIGUANYU_H_
#define SGSAI_AIGUANYU_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIGuanyu: public AICommon {
public:
	explicit AIGuanyu(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);

private:
	virtual sgs::DataType::Message * useCardResponse();
	virtual sgs::DataType::Message * shaOrNot(sgs::DataType::Player * /*from*/,
			const sgs::DataType::Card * /*card*/);
	sgs::Derive::MSkill * useWushengInUsecard();
	sgs::Derive::MSkill * useWushengInShaOrNot();
	const CardVec& redShoupai();
	CardVec redShoupaiVec;
};

} /* namespace sgsai */
#endif /* SGSAI_AIGUANYU_H_ */
