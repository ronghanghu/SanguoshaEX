/*
 * sgsai_AICaocao.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AICAOCAO_H_
#define SGSAI_AICAOCAO_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AICaocao: public AICommon {
public:
	explicit AICaocao(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
	sgs::DataType::Message * shanOrNot(sgs::DataType::Player * /*from*/,
			const sgs::DataType::Card * /*card*/);

private:
	sgs::Derive::MSkill * useHujiaInShanOrNot();
};

} /* namespace sgsai */
#endif /* SGSAI_AICAOCAO_H_ */
