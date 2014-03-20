/*
 * sgsui_RoleFrame.cpp
 *
 *  Created on: Jul 1, 2012
 *      Author: latios
 */

#include "sgsui_RoleFrame.h"
#include "sgsui_nameConvert.h"

namespace sgsui {

const QSize RoleFrame::fixedSize(190, 70);

RoleFrame::RoleFrame(QWidget *parent) :
		QFrame(parent), zhugongNum(0), zhongchenNum(0), fanzeiNum(0), neijianNum(
				0), aliveZhugongNum(0), aliveZhongchenNum(0), aliveFanzeiNum(0), aliveNeijianNum(
				0) {

	setupUi(this);
	setFixedSize(fixedSize);
	setObjectName("roleFrame");
	setStyleSheet(
			"QFrame#roleFrame{background-image:url(images/frame/role.png)}");

	roleLabel[0] = roleLabel0;
	roleLabel[1] = roleLabel1;
	roleLabel[2] = roleLabel2;
	roleLabel[3] = roleLabel3;
	roleLabel[4] = roleLabel4;
	roleLabel[5] = roleLabel5;
	roleLabel[6] = roleLabel6;
	roleLabel[7] = roleLabel7;

	for (int i = 0; i < 8; ++i) {
		roleLabel[i]->hide();
	}
}

void RoleFrame::setupRole(int _zhugongNum, int _zhongchenNum, int _fanzeiNum,
		int _neijianNum) {

	zhugongNum = _zhugongNum;
	zhongchenNum = _zhongchenNum;
	fanzeiNum = _fanzeiNum;
	neijianNum = _neijianNum;

	aliveZhugongNum = zhugongNum;
	aliveZhongchenNum = zhongchenNum;
	aliveFanzeiNum = fanzeiNum;
	aliveNeijianNum = neijianNum;

	using namespace sgs::ConstData;
	int count = 0;
	for (int i = 0; i < zhugongNum; ++i, ++count) {
		roleLabel[count]->setPixmap(roleSmallPixmapStr(ZHU));
		roleLabel[count]->show();
	}
	for (int i = 0; i < zhongchenNum; ++i, ++count) {
		roleLabel[count]->setPixmap(roleSmallPixmapStr(ZHONG));
		roleLabel[count]->show();
	}
	for (int i = 0; i < fanzeiNum; ++i, ++count) {
		roleLabel[count]->setPixmap(roleSmallPixmapStr(FAN));
		roleLabel[count]->show();
	}
	for (int i = 0; i < neijianNum; ++i, ++count) {
		roleLabel[count]->setPixmap(roleSmallPixmapStr(NEI));
		roleLabel[count]->show();
	}
}

void RoleFrame::setDead(sgs::ConstData::PlayerRole killedPlayerRole) {
	using namespace sgs::ConstData;
	switch (killedPlayerRole) {
	case ZHU:
		roleLabel[--aliveZhugongNum]->setPixmap(roleSmallPixmapStr(ZHU, true));
		break;
	case ZHONG:
		roleLabel[zhugongNum + (--aliveZhongchenNum)]->setPixmap(
				roleSmallPixmapStr(ZHONG, true));
		break;
	case FAN:
		roleLabel[zhugongNum + zhongchenNum + (--aliveFanzeiNum)]->setPixmap(
				roleSmallPixmapStr(FAN, true));
		break;
	case NEI:
		roleLabel[zhugongNum + zhongchenNum + fanzeiNum + (--aliveNeijianNum)]->setPixmap(
				roleSmallPixmapStr(NEI, true));
		break;
	default:
		break;
	}
}

} /* namespace sgsui */
