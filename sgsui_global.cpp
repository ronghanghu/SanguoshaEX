/*
 * sgsui_global.cpp
 *
 *  Created on: May 3, 2012
 *      Author: latios
 */

#include "sgsui_global.h"
#include "sgsui_MainWindow.h"

namespace sgsui {

sgs::ConstData::HeroType heroChoose(sgs::ConstData::HeroType lordHeroType,
		sgs::ConstData::PlayerRole selfRole,
		sgs::ConstData::HeroType avaliable1,
		sgs::ConstData::HeroType avaliable2,
		sgs::ConstData::HeroType avaliable3) {
	return MainWindow::mainWindowPtr()->chooseWujiang(lordHeroType, selfRole,
			avaliable1, avaliable2, avaliable3);
}

sgs::ConstData::HeroType lordChoose(sgs::ConstData::HeroType avaliable1,
		sgs::ConstData::HeroType avaliable2,
		sgs::ConstData::HeroType avaliable3,
		sgs::ConstData::HeroType avaliable4,
		sgs::ConstData::HeroType avaliable5) {
	return MainWindow::mainWindowPtr()->chooseZhugongWujiang(avaliable1,
			avaliable2, avaliable3, avaliable4, avaliable5);
}

} /* namespace sgsui */
