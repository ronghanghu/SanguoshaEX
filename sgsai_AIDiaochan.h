/*
 * sgsai_AIDiaochan.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIDIAOCHAN_H_
#define SGSAI_AIDIAOCHAN_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIDiaochan: public AICommon {
public:
	explicit AIDiaochan(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
};

} /* namespace sgsai */
#endif /* SGSAI_AIDIAOCHAN_H_ */
