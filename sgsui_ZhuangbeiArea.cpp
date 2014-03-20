/*
 * sgsui_ZhuangbeiArea.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#include "sgsui_ZhuangbeiArea.h"
#include "sgsui_ZhuangbeiPic.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

const QSize ZhuangbeiArea::fixedSize(164, 170);

ZhuangbeiArea::ZhuangbeiArea(MainWindow *mainWindowPtr, QWidget * parent) :
		QWidget(parent), mainWindow(mainWindowPtr), wuqiCard(0), fangjuCard(0), jianmaCard(
				0), jiamaCard(0), wuqiPic(0), fangjuPic(0), jianmaPic(0), jiamaPic(
				0), lebuPixmap("images/status/indulgence.png"), shandianPixmap(
				"images/status/lightning.png"), bingliangPixmap(
				"images/status/supply_shortage.png") {
	setupUi(this);
	setFixedSize(fixedSize);

	judgeLabel[0] = judge0;
	judgeLabel[1] = judge1;
	judgeLabel[2] = judge2;

	judge0->hide();
	judge1->hide();
	judge2->hide();
}

const CardFrame * ZhuangbeiArea::getWuqi() const {
	return wuqiCard;
}

const CardFrame * ZhuangbeiArea::getFangju() const {
	return fangjuCard;
}

const CardFrame * ZhuangbeiArea::getJianma() const {
	return jianmaCard;
}

const CardFrame * ZhuangbeiArea::getJiama() const {
	return jiamaCard;
}

ZhuangbeiPic * ZhuangbeiArea::getWuqiPic() const {
	return wuqiPic;
}

ZhuangbeiPic * ZhuangbeiArea::getFangjuPic() const {
	return fangjuPic;
}

ZhuangbeiPic * ZhuangbeiArea::getJianmaPic() const {
	return jianmaPic;
}

ZhuangbeiPic * ZhuangbeiArea::getJiamaPic() const {
	return jiamaPic;
}

bool ZhuangbeiArea::isSelected(int zhuangbeiIndex) {
	switch (zhuangbeiIndex) {
	case 0:
		if (wuqiPic)
			return wuqiPic->isSelected();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelected: trying to get the status of weapon, while there is no weapon!");
		break;
	case 1:
		if (fangjuPic)
			fangjuPic->isSelected();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelected: trying to get the status of armor, while there is no armor!");
		break;
	case 2:
		if (jianmaPic)
			jianmaPic->isSelected();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelected: trying to get the status of dfdhorse, while there is no dfdhorse!");
		break;
	case 3:
		if (jiamaPic)
			jiamaPic->isSelected();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelected: trying to get the status of atkhorse, while there is no atkhorse!");
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelected: invalid index");
		break;
	}
	return true;
}

bool ZhuangbeiArea::isSelectable(int zhuangbeiIndex) {
	switch (zhuangbeiIndex) {
	case 0:
		if (wuqiPic)
			return wuqiPic->isSelectable();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelectable: trying to get the status of weapon, while there is no weapon!");
		break;
	case 1:
		if (fangjuPic)
			fangjuPic->isSelectable();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelectable: trying to get the status of armor, while there is no armor!");
		break;
	case 2:
		if (jianmaPic)
			jianmaPic->isSelectable();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelectable: trying to get the status of dfdhorse, while there is no dfdhorse!");
		break;
	case 3:
		if (jiamaPic)
			jiamaPic->isSelectable();
		else
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelectable: trying to get the status of atkhorse, while there is no atkhorse!");
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>ZhuangbeiArea::isSelectable: invalid index");
		break;
	}
	return true;
}

void ZhuangbeiArea::setSelected(int zhuangbeiIndex, bool selected, bool force) {
	switch (zhuangbeiIndex) {
	case 0:
		if (wuqiPic)
			wuqiPic->setSelected(selected);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelected: trying to change the status of weapon, while there is no weapon!");
		break;
	case 1:
		if (fangjuPic)
			fangjuPic->setSelected(selected);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelected: trying to change the status of armor, while there is no armor!");
		break;
	case 2:
		if (jianmaPic)
			jianmaPic->setSelected(selected);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelected: trying to change the status of dfdhorse, while there is no dfdhorse!");
		break;
	case 3:
		if (jiamaPic)
			jiamaPic->setSelected(selected);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelected: trying to change the status of atkhorse, while there is no atkhorse!");
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelected: invalid index");
		break;
	}
}

void ZhuangbeiArea::setSelectable(int zhuangbeiIndex, bool selectable,
		bool force) {
	switch (zhuangbeiIndex) {
	case 0:
		if (wuqiPic)
			wuqiPic->setSelectable(selectable);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelectable: trying to change the status of weapon, while there is no weapon!");
		break;
	case 1:
		if (fangjuPic)
			fangjuPic->setSelectable(selectable);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelectable: trying to change the status of armor, while there is no armor!");
		break;
	case 2:
		if (jianmaPic)
			jianmaPic->setSelectable(selectable);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelectable: trying to change the status of dfdhorse, while there is no dfdhorse!");
		break;
	case 3:
		if (jiamaPic)
			jiamaPic->setSelectable(selectable);
		else if (!force)
			printDebug(
					"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelectable: trying to change the status of atkhorse, while there is no atkhorse!");
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>ZhuangbeiArea::setSelectable: invalid index");
		break;
	}
}

void ZhuangbeiArea::addWuqi(CardFrame *newWuqiCard) {
	if (wuqiCard) {
		delete wuqiCard;
		delete wuqiPic;
	}
	wuqiCard = newWuqiCard;
	wuqiPic = new ZhuangbeiPic(wuqiCard, mainWindow, wuqiWidget);
	wuqiPic->show();
}

void ZhuangbeiArea::addFangju(CardFrame *newFangjuCard) {
	if (fangjuCard) {
		delete fangjuCard;
		delete fangjuPic;
	}
	fangjuCard = newFangjuCard;
	fangjuPic = new ZhuangbeiPic(fangjuCard, mainWindow, fangjuWidget);
	fangjuPic->show();
}

void ZhuangbeiArea::addJianma(CardFrame *newJianmaCard) {
	if (jianmaCard) {
		delete jianmaCard;
		delete jianmaPic;
	}
	jianmaCard = newJianmaCard;
	jianmaPic = new ZhuangbeiPic(jianmaCard, mainWindow, jianmaWidget);
	jianmaPic->show();
}

void ZhuangbeiArea::addJiama(CardFrame *newJiamaCard) {
	if (jiamaCard) {
		delete jiamaCard;
		delete jiamaPic;
	}
	jiamaCard = newJiamaCard;
	jiamaPic = new ZhuangbeiPic(jiamaCard, mainWindow, jiamaWidget);
	jiamaPic->show();
}

void ZhuangbeiArea::removeWuqi() {
	if (wuqiCard) {
		delete wuqiCard;
		delete wuqiPic;
	}
	wuqiPic = 0;
	wuqiCard = 0;
}

void ZhuangbeiArea::removeFangju() {
	if (fangjuCard) {
		delete fangjuCard;
		delete fangjuPic;
	}
	fangjuPic = 0;
	fangjuCard = 0;
}

void ZhuangbeiArea::removeJianma() {
	if (jianmaCard) {
		delete jianmaCard;
		delete jianmaPic;
	}
	jianmaPic = 0;
	jianmaCard = 0;
}

void ZhuangbeiArea::removeJiama() {
	if (jiamaCard) {
		delete jiamaCard;
		delete jiamaPic;
	}
	jiamaPic = 0;
	jiamaCard = 0;
}

void ZhuangbeiArea::addJudge(sgs::ConstData::CardType judgeCard) {
	judgeList.push_back(judgeCard);
	refreshJudge();
}

void ZhuangbeiArea::removeJudge(sgs::ConstData::CardType judgeCard) {
	judgeList.remove(judgeCard);
	refreshJudge();
}

void ZhuangbeiArea::refreshJudge() {
	int i = 0;
	for (std::list<sgs::ConstData::CardType>::iterator iter = judgeList.begin();
			iter != judgeList.end(); ++iter, ++i) {
		switch (*iter) {
		case sgs::ConstData::SHANDIAN:
			judgeLabel[i]->setPixmap(shandianPixmap);
			break;
		case sgs::ConstData::SISHU:
			judgeLabel[i]->setPixmap(lebuPixmap);
			break;
		case sgs::ConstData::BINGLIANG:
			judgeLabel[i]->setPixmap(bingliangPixmap);
			break;
		default:
			break;
		}
		judgeLabel[i]->show();
	}
	for (; i < 3; ++i) {
		judgeLabel[i]->hide();
	}
}

} /* namespace sgsui */
