/*
 * sgsui_global.h
 *
 *  Created on: May 3, 2012
 *      Author: latios
 */

#ifndef SGSUI_GLOBAL_H_
#define SGSUI_GLOBAL_H_

#include "sgsdata_enum.h"
#include <utility>

namespace sgsui {

sgs::ConstData::HeroType heroChoose(sgs::ConstData::HeroType lordHeroType,
		sgs::ConstData::PlayerRole selfRole,
		sgs::ConstData::HeroType avaliable1,
		sgs::ConstData::HeroType avaliable2,
		sgs::ConstData::HeroType avaliable3); // choose hero of ZHONG, FAN and NEI
sgs::ConstData::HeroType lordChoose(sgs::ConstData::HeroType avliable1,
		sgs::ConstData::HeroType avliable2, sgs::ConstData::HeroType avliable3,
		sgs::ConstData::HeroType avliable4, sgs::ConstData::HeroType avliable5); // choose hero of ZHU

} /* namespace sgsui */
#endif /* SGSUI_GLOBAL_H_ */
