/*
 * sgsai_AIGuojia.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIGUOJIA_H_
#define SGSAI_AIGUOJIA_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIGuojia: public AICommon {
public:
	explicit AIGuojia(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
	virtual sgs::DataType::Message * getYiji(const sgs::DataType::Card * card1,
			const sgs::DataType::Card * card2);
};

} /* namespace sgsai */
#endif /* SGSAI_AIGUOJIA_H_ */
