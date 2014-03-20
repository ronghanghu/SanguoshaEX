/*
 * sgsui_ZhuangbeiPic.h
 *
 *  Created on: Apr 2, 2012
 *      Author: latios
 */

#ifndef SGSUI_ZHUANGBEIPIC_H_
#define SGSUI_ZHUANGBEIPIC_H_

#include <QWidget>
#include <QLabel>
#include "sgsdata_enum.h"

namespace sgsui {

class CardFrame;
class AbstractEquipProcessor;

class ZhuangbeiPic: public QWidget {
Q_OBJECT
public:
	ZhuangbeiPic(const CardFrame *newZhuangbeiCard,
			AbstractEquipProcessor * processor, QWidget *parent = 0);
	void click();
	bool isSelected() const;
	bool isSelectable() const;
	sgs::ConstData::CardType getCardType() const;
	sgs::ConstData::CardColor getCardColor() const;
	int getCardNumber() const;

public slots:
	void setSelected(bool selected = true);
	void setUnselected(bool unselected = true);
	void setSelectable(bool selectable = true);
	void setUnselectable(bool unselectable = true);

private:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);

	const sgs::ConstData::CardType _cardType;
	const sgs::ConstData::CardColor _cardColor;
	const int _number;
	AbstractEquipProcessor * const _processor;

	const QPixmap zhuangbeiPixmap;
	const QPixmap colorPixmap;
	const QPixmap numberPixmap;

	bool zhuangbeiSelected;
	bool zhuangbeiSelectable;

	const static QSize fixedSize;
	const static QPoint pixmapMargin;
	const static QPoint numberMargin;
	const static QPoint colorMargin;
	const static QPoint pixmapMargin_selected;
	const static QPoint numberMargin_selected;
	const static QPoint colorMargin_selected;
	const static QColor unselectableColor;
};

} /* namespace sgsui */
#endif /* SGSUI_ZHUANGBEIPIC_H_ */
