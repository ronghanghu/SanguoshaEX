/*
 * sgsai_AIXiahoudun.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIXIAHOUDUN_H_
#define SGSAI_AIXIAHOUDUN_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIXiahoudun: public AICommon {
public:
	explicit AIXiahoudun(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIXIAHOUDUN_H_ */
