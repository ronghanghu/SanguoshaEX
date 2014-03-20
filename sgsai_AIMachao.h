/*
 * sgsai_AIMachao.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIMACHAO_H_
#define SGSAI_AIMACHAO_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIMachao: public AICommon {
public:
	explicit AIMachao(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIMACHAO_H_ */
