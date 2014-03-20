/*
 * sgsai_AIZhenji.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIZHENJI_H_
#define SGSAI_AIZHENJI_H_

#include "sgsai_AICommon.h"

namespace sgsai {

class AIZhenji: public AICommon {
public:
	explicit AIZhenji(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
	virtual sgs::DataType::Message * shanOrNot(sgs::DataType::Player * /*from*/,
			const sgs::DataType::Card * /*card*/);

private:
	sgs::Derive::MSkill * useQingguoInShanOrNot();
	const CardVec& blackShoupai();
	CardVec blackShoupaiVec;

};

} /* namespace sgsai */
#endif /* SGSAI_AIZHENJI_H_ */
