/*
 * sgsui_WujiangChooseBox.h
 *
 *  Created on: Apr 2, 2012
 *      Author: latios
 */

#ifndef SGSUI_WUJIANGCHOOSEBOX_H_
#define SGSUI_WUJIANGCHOOSEBOX_H_

#include "ui_WujiangChooseBox.h"
#include "sgsui_BlockingFrame.h"

namespace sgsui {

class WujiangChooseBox: public BlockingFrame, protected Ui::WujiangChooseBox {
Q_OBJECT
public:
	explicit WujiangChooseBox(QWidget *parent);
	sgs::ConstData::HeroType chooseWujiang(sgs::ConstData::HeroType zhugong,
			sgs::ConstData::PlayerRole shenfen,
			sgs::ConstData::HeroType avaliable1,
			sgs::ConstData::HeroType avaliable2,
			sgs::ConstData::HeroType avaliable3);
	sgs::ConstData::HeroType chooseZhugongWujiang(
			sgs::ConstData::HeroType avaliable1,
			sgs::ConstData::HeroType avaliable2,
			sgs::ConstData::HeroType avaliable3,
			sgs::ConstData::HeroType avaliable4,
			sgs::ConstData::HeroType avaliable5);

private slots:
	void submit(sgs::ConstData::HeroType choosenWujiang);

private:
	sgs::ConstData::HeroType choosen;

	const static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_WUJIANGCHOOSEBOX_H_ */
