/*
 * sgsai_AIZhangliao.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIZHANGLIAO_H_
#define SGSAI_AIZHANGLIAO_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIZhangliao: public AICommon {
public:
	explicit AIZhangliao(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIZHANGLIAO_H_ */
