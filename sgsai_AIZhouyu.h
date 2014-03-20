/*
 * sgsai_AIZhouyu.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIZHOUYU_H_
#define SGSAI_AIZHOUYU_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIZhouyu: public AICommon {
public:
	explicit AIZhouyu(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIZHOUYU_H_ */
