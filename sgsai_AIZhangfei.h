/*
 * sgsai_AIZhangfei.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIZHANGFEI_H_
#define SGSAI_AIZHANGFEI_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIZhangfei: public AICommon {
public:
	explicit AIZhangfei(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIZHANGFEI_H_ */
