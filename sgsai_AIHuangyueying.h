/*
 * sgsai_AIHuangyueying.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIHUANGYUEYING_H_
#define SGSAI_AIHUANGYUEYING_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIHuangyueying: public AICommon {
public:
	explicit AIHuangyueying(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIHUANGYUEYING_H_ */
