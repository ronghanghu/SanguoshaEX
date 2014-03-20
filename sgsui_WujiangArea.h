/*
 * sgsui_WujiangArea.h
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#ifndef SGSUI_WUJIANGAREA_H_
#define SGSUI_WUJIANGAREA_H_

#include "ui_WujiangArea.h"
#include "sgsui_AbstractPlayerArea.h"
#include "sgsdata_enum.h"

namespace sgsui {

class MainWindow;
class SkillLabel;

class WujiangArea: public QWidget,
		protected Ui::WujiangArea,
		public AbstractPlayerArea {
Q_OBJECT
public:
	WujiangArea(int playerIndex, QWidget *parent);
	sgs::DataType::Player * getPlayer();
	sgs::ConstData::HeroSkill getSkill(int skillIndex);
	void click();
	bool isSelected();
	bool isSelectable();
	sgs::ConstData::HeroSex getSex() const;
	sgs::ConstData::HeroType getHeroType() const;
	sgs::ConstData::PlayerRole getRole() const;
	int getHP() const;
	int playerIndex() const;
	int getMaxHP() const;
	bool chained() const;
	bool isDead() const;
	bool isDying() const;
	void setDead();
	void setDying(bool dying);
	void showSkill(sgs::ConstData::HeroSkill skill);
	void showRecover();
	void resetChain();
	void enableSkillButton(int skillButtonIndex, bool enable = true);
	void disableSkillButton(int skillButtonIndex, bool disable = true);
	void disableAllSkillButtons();

signals:
	void skillClicked(sgs::ConstData::HeroSkill, int);

public slots:
	void setSelected(bool selected = true);
	void setUnselected(bool unselected = true);
	void setSelectable(bool selectable = true);
	void setUnselectable(bool unselectable = true);
	void setHP(int _HP);
	void setHPDamage(int damage);

private slots:
	void skillSlot0();
	void skillSlot1();
	void skillSlot2();
	void skillSlot3();

private:
	void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent*);
	MainWindow * mainWindow() const;

	const int _playerIndex;
	const sgs::ConstData::PlayerRole role;
	const sgs::ConstData::HeroType heroType;
	const sgs::ConstData::HeroSex sex;
	const sgs::ConstData::HeroSide side;

	int skillCount;
	SkillButton * skillButton[4];

	const QPixmap playerPixmap;
	const QPixmap countrySmallPixmap;
	const QPixmap rolePixmap;
	const QPixmap deadRolePixmap;
	const QPixmap dyingPixmap;
	const QPixmap chainPixmap;

	int HP;
	const int maxHP;

	bool _isDead;
	bool _isDying;
	bool isChained;

	bool playerSelected;
	bool playerSelectable;

	SkillLabel *skillLabel;

	QLabel * recoverLabel;
	QTimer * recoverTimer;

	const static QSize fixedSize;
	const static QPoint skillPosition;
	const static QPoint playerPixmapMargin;
	const static QPoint countrySmallMargin;
	const static QPoint rolePixmapMargin;
	const static QPoint chainPixmapMargin;
	const static QPoint dyingPixmapMargin;
	const static QPoint deadPixmapMargin;
	const static QPoint recoverLabelMargin;

	const static int horizontalHPMargin;
	const static int verticalHPMargin;
	const static int maxVerticalHPDifference;
	const static int maxHPHeight;

	const static QRect clickableRect;
	const static QRect coloredRect;
	const static QColor selectedColor;
	const static QColor unselectableColor;
};

} /* namespace sgsui */
#endif /* SGSUI_WUJIANGAREA_H_ */
