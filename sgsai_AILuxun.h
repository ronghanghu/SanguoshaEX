/*
 * sgsai_AILuxun.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AILUXUN_H_
#define SGSAI_AILUXUN_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AILuxun: public AICommon {
public:
	explicit AILuxun(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AILUXUN_H_ */
