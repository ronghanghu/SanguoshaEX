/*
 * sgsai_AISunquan.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AISUNQUAN_H_
#define SGSAI_AISUNQUAN_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AISunquan: public AICommon {
public:
	explicit AISunquan(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AISUNQUAN_H_ */
