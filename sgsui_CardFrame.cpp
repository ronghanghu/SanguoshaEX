/*
 * sgsui_CardFrame.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#include "sgsui_CardFrame.h"
#include "sgsui_nameConvert.h"
#include "sgsui_GUIStaticData.h"
#include <QtGui>

namespace sgsui {

const QSize CardFrame::fixedSize(93, 130);
const QPoint CardFrame::numberMargin(0, 3);
const QPoint CardFrame::colorMargin(0, 18);
const QPoint CardFrame::wujiangMiniMargin(51, 0);
const QPoint CardFrame::judgePixmapMargin(-40, 15);

const QColor CardFrame::unselectableColor(0, 0, 0, 100);
const QRect CardFrame::judgeTextRect(0, 50, 93, 130);

CardFrame::CardFrame(sgs::ConstData::CardType cardType,
		sgs::ConstData::CardColor cardColor, int number, QWidget *parent) :
		QWidget(parent),

		judge(false), wujiangMiniPixmap(), judgeString(),

		_cardType(cardType), _cardColor(cardColor), _number(number),

		cardPixmap(cardPixmapStr(_cardType)), colorPixmap(
				cardColorStr(_cardColor)), numberPixmap(
				cardNumberStr(_number, _cardColor)), dimed(false),

		judgeResult(false) {
	setFixedSize(fixedSize);
}

CardFrame::CardFrame(sgs::ConstData::HeroType heroType,
		sgs::ConstData::CardType cardType, sgs::ConstData::CardColor cardColor,
		int number, bool result, QWidget *parent) :
		QWidget(parent),

		judge(true), wujiangMiniPixmap(wujiangMiniPixmapStr(heroType)), judgeString(
				wujiangDisplayName(heroType).append(
						GUIStaticData::judgeCardText)),

		_cardType(cardType), _cardColor(cardColor), _number(number),

		cardPixmap(cardPixmapStr(_cardType)), colorPixmap(
				cardColorStr(_cardColor)), numberPixmap(
				cardNumberStr(_number, _cardColor)), dimed(false),

		judgeResult(result), judgePixmap(
				judgeResult ?
						QString("images/system/positive.png") :
						QString("images/system/negative.png")), judgeTextColor(
				isZhuangbeiCard(cardType) || isJinnangCard(cardType) ?
						QColor(255, 0, 0) : QColor(255, 255, 0)) {
	setFixedSize(fixedSize);
}

CardFrame::CardFrame(QWidget *parent) :
		QWidget(parent),

		judge(false),

		_cardType(sgs::ConstData::ctNone), _cardColor(sgs::ConstData::ccNone), _number(
				0), cardPixmap("images/card/card-back.jpg"), dimed(false),

		judgeResult(false) {
	setFixedSize(fixedSize);
}

QPoint CardFrame::topLeftPoint() const {
	QPoint topLeftCoordinate = pos();
	for (QWidget *thisWidget = parentWidget(); thisWidget != window();
			thisWidget = thisWidget->parentWidget()) {
		topLeftCoordinate += thisWidget->pos();
	}
	return topLeftCoordinate;
}

bool CardFrame::isDimed() const {
	return dimed;
}

void CardFrame::setDimed(bool dim) {
	dimed = dim;
	update();
}

void CardFrame::setNotDimed(bool notDim) {
	setDimed(!notDim);
}

void CardFrame::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, cardPixmap);
	painter.drawPixmap(numberMargin, numberPixmap);
	painter.drawPixmap(colorMargin, colorPixmap);

	if (dimed)
		painter.fillRect(QRect(QPoint(0, 0), fixedSize), unselectableColor);

	if (judge) {
		painter.setPen(judgeTextColor);
		painter.drawPixmap(judgePixmapMargin, judgePixmap);
		painter.drawPixmap(wujiangMiniMargin, wujiangMiniPixmap);
		painter.setFont(GUIStaticData::statusbarFont);
		painter.drawText(judgeTextRect, Qt::AlignHCenter | Qt::AlignVCenter,
				judgeString);
	}
}

sgs::ConstData::CardType CardFrame::getCardType() const {
	return _cardType;
}

sgs::ConstData::CardColor CardFrame::getCardColor() const {
	return _cardColor;
}

int CardFrame::getNumber() const {
	return _number;
}

} /* namespace sgsui */
