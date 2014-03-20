/*
 * sgsai_AIGanning.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIGANNING_H_
#define SGSAI_AIGANNING_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIGanning: public AICommon {
public:
	explicit AIGanning(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);

private:
//	virtual sgs::DataType::Message * useCardResponse();
	sgs::Derive::MSkill * useQixiInUsecard();
	const CardVec& blackShoupai();
	const CardVec& blackEquip();
	CardVec blackShoupaiVec;
	CardVec blackEquipVec;
};

} /* namespace sgsai */
#endif /* SGSAI_AIGANNING_H_ */
