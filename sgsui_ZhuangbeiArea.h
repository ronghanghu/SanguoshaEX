/*
 * sgsui_ZhuangbeiArea.h
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#ifndef SGSUI_ZHUANGBEIAREA_H_
#define SGSUI_ZHUANGBEIAREA_H_

#include "ui_ZhuangbeiArea.h"
#include "sgsui_CardFrame.h"
#include "sgsui_MainWindow.h"
#include "sgsdata_enum.h"

namespace sgsui {

class ZhuangbeiPic;

class ZhuangbeiArea: public QWidget, protected Ui::ZhuangbeiArea {
Q_OBJECT
public:
	explicit ZhuangbeiArea(MainWindow *mainWindowPtr, QWidget * parent);
	const CardFrame * getWuqi() const;
	const CardFrame * getFangju() const;
	const CardFrame * getJianma() const;
	const CardFrame * getJiama() const;
	ZhuangbeiPic * getWuqiPic() const;
	ZhuangbeiPic * getFangjuPic() const;
	ZhuangbeiPic * getJianmaPic() const;
	ZhuangbeiPic * getJiamaPic() const;
	bool isSelected(int zhuangbeiIndex);
	bool isSelectable(int zhuangbeiIndex);

	// index: 1 for wuqi, 2 for zhuangbei, 3 for jianma, 4 for jiama
	void setSelected(int zhuangbeiIndex, bool selected, bool force = false);
	void setSelectable(int zhuangbeiIndex, bool selectable, bool force = false);

	// Return value indicates whether any old card is deserted (processed by GUI algorithm)
	void addWuqi(CardFrame *newWuqiCard);
	void addFangju(CardFrame *newFangjuCard);
	void addJianma(CardFrame *newJianmaCard);
	void addJiama(CardFrame *newJiamaCard);
	void removeWuqi();
	void removeFangju();
	void removeJianma();
	void removeJiama();
	void addJudge(sgs::ConstData::CardType judgeCard);
	void removeJudge(sgs::ConstData::CardType judgeCard);

private:
	void refreshJudge();
	MainWindow * mainWindow;

	CardFrame* wuqiCard;
	CardFrame* fangjuCard;
	CardFrame* jianmaCard;
	CardFrame* jiamaCard;

	ZhuangbeiPic* wuqiPic;
	ZhuangbeiPic* fangjuPic;
	ZhuangbeiPic* jianmaPic;
	ZhuangbeiPic* jiamaPic;

	const QPixmap lebuPixmap;
	const QPixmap shandianPixmap;
	const QPixmap bingliangPixmap;

	std::list<sgs::ConstData::CardType> judgeList;
	QLabel *judgeLabel[3];

	const static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_ZHUANGBEIAREA_H_ */
