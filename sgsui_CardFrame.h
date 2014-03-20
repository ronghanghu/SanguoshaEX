/*
 * sgsui_CardFrame.h
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#ifndef SGSUI_CARDFRAME_H_
#define SGSUI_CARDFRAME_H_

#include <QWidget>
#include "sgsdata_enum.h"

namespace sgsui {

class CardFrame: public QWidget {
Q_OBJECT
public:
	CardFrame(sgs::ConstData::CardType cardType,
			sgs::ConstData::CardColor cardColor, int number,
			QWidget *parent = 0);
	CardFrame(sgs::ConstData::HeroType heroType,
			sgs::ConstData::CardType cardType,
			sgs::ConstData::CardColor cardColor, int number, bool result,
			QWidget *parent = 0);
	explicit CardFrame(QWidget *parent = 0);
	QPoint topLeftPoint() const;
	bool isDimed() const;

	sgs::ConstData::CardType getCardType() const;
	sgs::ConstData::CardColor getCardColor() const;
	int getNumber() const;

public slots:
	void setDimed(bool dim);
	void setNotDimed(bool notDim);

protected:
	void paintEvent(QPaintEvent*);

	const bool judge;
	const QPixmap wujiangMiniPixmap;
	const QString judgeString;

	const sgs::ConstData::CardType _cardType;
	const sgs::ConstData::CardColor _cardColor;
	const int _number;

	const QPixmap cardPixmap;
	const QPixmap colorPixmap;
	const QPixmap numberPixmap;

	bool dimed;

	const bool judgeResult;
	const QPixmap judgePixmap;
	const QColor judgeTextColor;

	const static QSize fixedSize;
	const static QPoint numberMargin;
	const static QPoint colorMargin;
	const static QPoint wujiangMiniMargin;
	const static QPoint judgePixmapMargin;

	const static QColor unselectableColor;
	const static QRect judgeTextRect;
};

} /* namespace sgsui */
#endif /* SGSUI_CARDFRAME_H_ */
