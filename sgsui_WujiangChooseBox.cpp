/*
 * sgsui_WujiangChooseBox.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: latios
 */

#include "sgsui_WujiangChooseBox.h"
#include "sgsui_MainWindow.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

const QSize WujiangChooseBox::fixedSize(1024, 400);

WujiangChooseBox::WujiangChooseBox(QWidget *parent) :
		BlockingFrame(parent), choosen(sgs::ConstData::htNone) {
	setupUi(this);
	setFixedSize(fixedSize);
	setStyleSheet(
			"QFrame#WujiangChooseBox{background-image:url(images/frame/wujiangChooseBox.png)}");
	zhugongWujiangLabel->setFont(GUIStaticData::contentFont);

	connect(wujiangButton1, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(submit(sgs::ConstData::HeroType)));
	connect(wujiangButton2, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(submit(sgs::ConstData::HeroType)));
	connect(wujiangButton3, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(submit(sgs::ConstData::HeroType)));
	connect(wujiangButton4, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(submit(sgs::ConstData::HeroType)));
	connect(wujiangButton5, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(submit(sgs::ConstData::HeroType)));
	connect(wujiangButton1, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(unblock()));
	connect(wujiangButton2, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(unblock()));
	connect(wujiangButton3, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(unblock()));
	connect(wujiangButton4, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(unblock()));
	connect(wujiangButton5, SIGNAL(choosen(sgs::ConstData::HeroType)), this,
			SLOT(unblock()));
}

sgs::ConstData::HeroType WujiangChooseBox::chooseWujiang(
		sgs::ConstData::HeroType zhugong, sgs::ConstData::PlayerRole shenfen,
		sgs::ConstData::HeroType avaliable1,
		sgs::ConstData::HeroType avaliable2,
		sgs::ConstData::HeroType avaliable3) {

	switch (shenfen) {
	case sgs::ConstData::ZHONG:
		messageLabel->setText(setColored(GUIStaticData::yourRoleIsZhong));
		break;
	case sgs::ConstData::FAN:
		messageLabel->setText(setColored(GUIStaticData::yourRoleIsFan));
		break;
	case sgs::ConstData::NEI:
		messageLabel->setText(setColored(GUIStaticData::yourRoleIsNei));
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>WujiangChooseBox::chooseWujiang: Shenfen is invalid");
		break;
	}

	zhugongPixmapLabel->showResult(zhugong);

	zhugongInfoFrame->show();
	wujiangButton1->setWujiang(avaliable1);
	wujiangButton2->setWujiang(avaliable2);
	wujiangButton3->setWujiang(avaliable3);
	wujiangButton4->hide();
	wujiangButton5->hide();

	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));

	exec();
	return choosen;
}

sgs::ConstData::HeroType WujiangChooseBox::chooseZhugongWujiang(
		sgs::ConstData::HeroType avaliable1,
		sgs::ConstData::HeroType avaliable2,
		sgs::ConstData::HeroType avaliable3,
		sgs::ConstData::HeroType avaliable4,
		sgs::ConstData::HeroType avaliable5) {

	zhugongInfoFrame->hide();

	messageLabel->setText(setColored(GUIStaticData::yourRoleIsZhu));

	wujiangButton1->setWujiang(avaliable1);
	wujiangButton2->setWujiang(avaliable2);
	wujiangButton3->setWujiang(avaliable3);
	wujiangButton4->setWujiang(avaliable4);
	wujiangButton5->setWujiang(avaliable5);

	wujiangButton4->show();
	wujiangButton5->show();

	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));

	exec();
	return choosen;
}

void WujiangChooseBox::submit(sgs::ConstData::HeroType choosenWujiang) {
	choosen = choosenWujiang;
}

} /* namespace sgsui */
