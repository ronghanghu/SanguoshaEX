/*
 * sgsai_AIXuchu.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIXUCHU_H_
#define SGSAI_AIXUCHU_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIXuchu: public AICommon {
public:
	explicit AIXuchu(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIXUCHU_H_ */
