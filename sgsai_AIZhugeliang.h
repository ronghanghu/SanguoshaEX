/*
 * sgsai_AIZhugeliang.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIZHUGELIANG_H_
#define SGSAI_AIZHUGELIANG_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIZhugeliang: public AICommon {
public:
	explicit AIZhugeliang(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
	virtual void chooseGuanxing(std::vector<const sgs::DataType::Card *>& top,
			std::vector<const sgs::DataType::Card *>& buttom);
};

} /* namespace sgsai */
#endif /* SGSAI_AIZHUGELIANG_H_ */
