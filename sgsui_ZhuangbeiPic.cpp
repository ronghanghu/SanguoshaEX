/*
 * sgsui_ZhuangbeiPic.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: latios
 */

#include "sgsui_ZhuangbeiPic.h"
#include "sgsui_CardFrame.h"
#include "sgsui_MainWindow.h"
#include "sgsui_AbstractEquipProcessor.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

const QSize ZhuangbeiPic::fixedSize(146, 29);
const QPoint ZhuangbeiPic::pixmapMargin(2, 2);
const QPoint ZhuangbeiPic::numberMargin(110, 2);
const QPoint ZhuangbeiPic::colorMargin(124, 2);
const QPoint ZhuangbeiPic::pixmapMargin_selected(-2, -2);
const QPoint ZhuangbeiPic::numberMargin_selected(106, -2);
const QPoint ZhuangbeiPic::colorMargin_selected(120, -2);
const QColor ZhuangbeiPic::unselectableColor(0, 0, 0, 150);

ZhuangbeiPic::ZhuangbeiPic(const CardFrame *newZhuangbeiCard,
		AbstractEquipProcessor * processor, QWidget *parent) :
		QWidget(parent), _cardType(newZhuangbeiCard->getCardType()), _cardColor(
				newZhuangbeiCard->getCardColor()), _number(
				newZhuangbeiCard->getNumber()), _processor(processor),

		zhuangbeiPixmap(zhuangbeiPixmapStr(_cardType)), colorPixmap(
				cardColorStr(_cardColor)), numberPixmap(
				cardNumberStr(_number, _cardColor)),

		zhuangbeiSelected(false), zhuangbeiSelectable(true) {
	setFixedSize(fixedSize);
	if (zhuangbeiPixmap.isNull())
		printDebug(
				"<font color=red><b>Warning: </b></font>ZhuangbeiPic::ZhuangbeiPic: invalid Zhuangbei Pixmap "
						+ zhuangbeiPixmapStr(_cardType)
						+ ", perhaps the cardType is not Zhuangbei Card");
}

void ZhuangbeiPic::click() {
	QMouseEvent temp(QEvent::MouseButtonRelease,
			QPoint(width() / 2, height() / 2), Qt::LeftButton, Qt::LeftButton,
			Qt::NoModifier);
	mousePressEvent(&temp);
	mouseReleaseEvent(&temp);
}

bool ZhuangbeiPic::isSelected() const {
	return zhuangbeiSelected;
}

bool ZhuangbeiPic::isSelectable() const {
	return zhuangbeiSelectable;
}

sgs::ConstData::CardType ZhuangbeiPic::getCardType() const {
	return _cardType;
}

sgs::ConstData::CardColor ZhuangbeiPic::getCardColor() const {
	return _cardColor;
}

int ZhuangbeiPic::getCardNumber() const {
	return _number;
}

void ZhuangbeiPic::setSelected(bool selected) {
	if (isSelectable() && (isSelected() != selected)) {
		zhuangbeiSelected = selected;
		update();
	}
}

void ZhuangbeiPic::setUnselected(bool unselected) {
	setSelected(!unselected);
}

void ZhuangbeiPic::setSelectable(bool selectable) {
	if (!selectable)
		setUnselected();

	if (zhuangbeiSelectable != selectable) {
		zhuangbeiSelectable = selectable;
		update();
	}
}

void ZhuangbeiPic::setUnselectable(bool unselectable) {
	setSelectable(!unselectable);
}

void ZhuangbeiPic::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	if (zhuangbeiSelected) {
		painter.drawPixmap(pixmapMargin, zhuangbeiPixmap);
		painter.drawPixmap(numberMargin, numberPixmap);
		painter.drawPixmap(colorMargin, colorPixmap);
	} else {
		painter.drawPixmap(pixmapMargin_selected, zhuangbeiPixmap);
		painter.drawPixmap(numberMargin_selected, numberPixmap);
		painter.drawPixmap(colorMargin_selected, colorPixmap);
	}

	if (!zhuangbeiSelectable) {
		painter.fillRect(rect(), unselectableColor);
	}
}

void ZhuangbeiPic::mousePressEvent(QMouseEvent *event) {
	if (zhuangbeiSelectable && event->button() == Qt::LeftButton
			&& static_cast<MainWindow*>(window())->isResponding()) {
		_processor->zhuangbeiClicked(this);
	}
}

} /* namespace sgsui */
