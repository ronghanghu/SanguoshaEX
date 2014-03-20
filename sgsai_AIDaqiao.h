/*
 * sgsai_AIDaqiao.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIDAQIAO_H_
#define SGSAI_AIDAQIAO_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIDaqiao: public AICommon {
public:
	explicit AIDaqiao(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIDAQIAO_H_ */
