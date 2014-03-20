/*
 * sgsai_AIHuanggai.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIHUANGGAI_H_
#define SGSAI_AIHUANGGAI_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIHuanggai: public AICommon {
public:
	explicit AIHuanggai(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
	virtual sgs::DataType::Message * useCardResponse();

private:
	sgs::Derive::MSkill * useKurouInUsecard();
};

} /* namespace sgsai */
#endif /* SGSAI_AIHUANGGAI_H_ */
