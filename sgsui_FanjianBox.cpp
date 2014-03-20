/*
 * sgsui_FanjianBox.cpp
 *
 *  Created on: May 3, 2012
 *      Author: latios
 */

#include "sgsui_FanjianBox.h"

namespace sgsui {

const QSize FanjianBox::fixedSize(480, 200);

FanjianBox::FanjianBox(QWidget *parent) :
		BlockingFrame(parent), returnColor(sgs::ConstData::ccNone) {
	setupUi(this);
	setFixedSize(fixedSize);

	setStyleSheet(
			"QFrame#FanjianBox{background-image:url(images/frame/dialog.png)}");

	connect(heartButton, SIGNAL(clicked()), this, SLOT(chooseHeart()));
	connect(spadeButton, SIGNAL(clicked()), this, SLOT(chooseSpade()));
	connect(diamondButton, SIGNAL(clicked()), this, SLOT(chooseDiamond()));
	connect(clubButton, SIGNAL(clicked()), this, SLOT(chooseClub()));
}

sgs::ConstData::CardColor FanjianBox::getFanjianColor() {
	exec();
	return returnColor;
}

void FanjianBox::chooseHeart() {
	returnColor = sgs::ConstData::HEART;
	unblock();
}

void FanjianBox::chooseSpade() {
	returnColor = sgs::ConstData::SPADE;
	unblock();
}

void FanjianBox::chooseDiamond() {
	returnColor = sgs::ConstData::DIAMOND;
	unblock();
}

void FanjianBox::chooseClub() {
	returnColor = sgs::ConstData::CLUB;
	unblock();
}

} /* namespace sgsui */
