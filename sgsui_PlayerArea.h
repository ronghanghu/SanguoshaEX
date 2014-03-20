/*
 * sgsui_PlayerArea.h
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#ifndef SGSUI_PLAYERAREA_H_
#define SGSUI_PLAYERAREA_H_

#include "ui_PlayerArea.h"
#include "sgsui_AbstractPlayerArea.h"
#include "sgsdata_enum.h"

namespace sgsui {

class MainWindow;
class CardFrame;
class SkillLabel;
class ZhuangbeiLabel;

class PlayerArea: public QFrame,
		protected Ui::PlayerArea,
		public AbstractPlayerArea {
Q_OBJECT
public:
	PlayerArea(int thisPlayerIndex, QWidget *parent);
	QPoint topLeftPoint() const;
	QRect realGeometry() const;
	int playerIndex() const;
	sgs::DataType::Player * getPlayer();
	void click();
	bool isSelected();
	bool isSelectable();
	sgs::ConstData::HeroSex getSex() const;
	sgs::ConstData::HeroType getHeroType() const;
	sgs::ConstData::PlayerRole getRole() const;
	int getHP() const;
	int getPhase() const;
	int getShoupaiNumber() const;
	const CardFrame * getWuqi() const;
	const CardFrame * getFangju() const;
	const CardFrame * getJianma() const;
	const CardFrame * getJiama() const;
	void addJudge(sgs::ConstData::CardType judgeCard);
	void removeJudge(sgs::ConstData::CardType judgeCard);
	bool chained() const;
	bool isDead() const;
	bool isDying() const;
	void setDead();
	void setDying(bool dying);
	void setResponding(bool responding);

	//Return value indicates whether any old card is deserted (processed by GUI algorithm)
	void addWuqi(CardFrame * newWuqiCard);
	void addFangju(CardFrame * newFangjuCard);
	void addJianma(CardFrame * newJianmaCard);
	void addJiama(CardFrame * newJiamaCard);
	void removeWuqi();
	void removeFangju();
	void removeJianma();
	void removeJiama();

	void showSkill(sgs::ConstData::HeroSkill skill);
	void showRecover();
	void showZhuangbei(sgs::ConstData::CardType equipCard);
	void resetChain();

public slots:
	void setSelected(bool selected = true);
	void setUnselected(bool unselected = true);
	void setSelectable(bool selectable = true);
	void setUnselectable(bool unselectable = true);
	void setHP(int _HP);
	void setHPDamage(int damage);
	void setPhase(sgs::ConstData::PlayerPhase _phase);
	void setShoupaiNumber(int _shoupaiNumber);

private:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	MainWindow* mainWindow() const;

	const int _playerIndex;

	const sgs::ConstData::PlayerRole role;
	const sgs::ConstData::HeroType heroType;
	const sgs::ConstData::HeroSex sex;
	const sgs::ConstData::HeroSide side;

	const QPixmap framePixmap;
	const QPixmap playerPixmap;
	const QPixmap countryFramePixmap;
	const QPixmap countrySmallPixmap;
	QPixmap rolePixmap;
	const QPixmap deadRolePixmap;
	const QPixmap dyingPixmap;
	const QPixmap shoupaiPixmap;
	const QPixmap chainPixmap;
	const QPixmap lebuPixmap;
	const QPixmap shandianPixmap;
	const QPixmap bingliangPixmap;

	int HP;
	const int maxHP;

	int shoupaiNumber;

	bool _isDead;
	bool _isDying;
	bool isResponding;

	bool isChained;

	sgs::ConstData::PlayerPhase phase;

	bool playerSelected;
	bool playerSelectable;

	CardFrame *wuqiCard;
	CardFrame *fangjuCard;
	CardFrame *jianmaCard;
	CardFrame *jiamaCard;

	SkillLabel * skillLabel;
	ZhuangbeiLabel * zhuangbeiLabel;

	QLabel * recoverLabel;
	QTimer * recoverTimer;

	const static QSize fixedSize;
	const static QPoint skillPosition;
	const static QPoint zhuangbeiPosition;
	const static QPoint playerFrameMargin;
	const static QPoint playerPixmapMargin;
	const static QPoint countryFrameMargin;
	const static QPoint countrySmallMargin;
	const static QPoint rolePixmapMargin;
	const static QPoint shoupaiPixmapMargin;

	const static QPoint wuqiColorMargin;
	const static QPoint wuqiPixmapMargin;
	const static QPoint wuqiNumberMargin;
	const static QPoint fangjuColorMargin;
	const static QPoint fangjuPixmapMargin;
	const static QPoint fangjuNumberMargin;
	const static QPoint jianmaColorMargin;
	const static QPoint jianmaPixmapMargin;
	const static QPoint jianmaNumberMargin;
	const static QPoint jiamaColorMargin;
	const static QPoint jiamaPixmapMargin;
	const static QPoint jiamaNumberMargin;
	const static QPoint chainPixmapMargin;
	const static QPoint phasePixmapMargin;
	const static QPoint dyingPixmapMargin;
	const static QPoint deadPixmapMargin;
	const static QPoint statusPixmapMargin;
	const static QPoint recoverLabelMargin;
	const static int horizontalHPMargin;
	const static int verticalHPMargin;
	const static int maxHorizontalHPDifference;
	const static int maxHPWidth;

	const static QRect playerFrameRect;
	const static QColor selectedColor;
	const static QColor unselectableColor;

	std::list<sgs::ConstData::CardType> judgeList;
};

} /* namespace sgsui */
#endif /* SGSUI_PLAYERAREA_H_ */
