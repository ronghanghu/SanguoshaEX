/*
 * sgsai_AIHuatuo.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIHUATUO_H_
#define SGSAI_AIHUATUO_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIHuatuo: public AICommon {
public:
	explicit AIHuatuo(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);

};

} /* namespace sgsai */
#endif /* SGSAI_AIHUATUO_H_ */
