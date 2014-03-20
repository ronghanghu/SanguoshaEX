/*
 * sgsai_AILvbu.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AILVBU_H_
#define SGSAI_AILVBU_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AILvbu: public AICommon {
public:
	explicit AILvbu(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AILVBU_H_ */
