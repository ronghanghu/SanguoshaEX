/*
 * sgsai_AISujiang.h
 *
 *  Created on: Jun 30, 2012
 *      Author: latios
 */

#ifndef SGSAI_AISUJIANG_H_
#define SGSAI_AISUJIANG_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AISujiang: public AICommon {
public:
	explicit AISujiang(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AISUJIANG_H_ */
