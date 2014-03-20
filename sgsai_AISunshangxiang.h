/*
 * sgsai_AISunshangxiang.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AISUNSHANGXIANG_H_
#define SGSAI_AISUNSHANGXIANG_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AISunshangxiang: public AICommon {
public:
	explicit AISunshangxiang(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
				sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AISUNSHANGXIANG_H_ */
