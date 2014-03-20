/*
 * sgsui_WujiangArea.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#include "sgsui_WujiangArea.h"
#include "sgsui_MainWindow.h"
#include "sgsui_SkillLabel.h"
#include "sgsui_nameConvert.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

const QSize WujiangArea::fixedSize(190, 170);
const QRect WujiangArea::clickableRect(0, 0, 140, 110);
const QRect WujiangArea::coloredRect(25, 8, 94, 97);
const QColor WujiangArea::selectedColor(255, 0, 0, 150);
const QColor WujiangArea::unselectableColor(0, 0, 0, 100);

const QPoint WujiangArea::skillPosition(15, 15);
const QPoint WujiangArea::playerPixmapMargin(25, 8);
const QPoint WujiangArea::countrySmallMargin(22, 5);
const QPoint WujiangArea::rolePixmapMargin(77, 92);
const QPoint WujiangArea::chainPixmapMargin(0, 5);
const QPoint WujiangArea::dyingPixmapMargin(30, 0);
const QPoint WujiangArea::deadPixmapMargin(0, 10);
const QPoint WujiangArea::recoverLabelMargin(0, 0);

const int WujiangArea::horizontalHPMargin = 155;
const int WujiangArea::verticalHPMargin = 5;
const int WujiangArea::maxVerticalHPDifference = 30;
const int WujiangArea::maxHPHeight = 153;

WujiangArea::WujiangArea(int playerIndex, QWidget *parent) :
		QWidget(parent), _playerIndex(playerIndex), role(
				GUIStaticData::getPlayerRole(_playerIndex)), heroType(
				GUIStaticData::getPlayerType(_playerIndex)), sex(
				GUIStaticData::getPlayerSex(_playerIndex)), side(
				GUIStaticData::getPlayerSide(_playerIndex)), skillCount(
				GUIStaticData::getSkillCount(_playerIndex)),

		playerPixmap(wujiangSelfPixmapStr(heroType)), countrySmallPixmap(
				countrySmallPixmapStr(side)), rolePixmap(rolePixmapStr(role)), deadRolePixmap(
				deadRolePixmapStr(role)), dyingPixmap(
				"images/animation/save-me.png"), chainPixmap(
				"images/status/chain.png"),

		HP(GUIStaticData::getPlayerHP(GUIStaticData::getHumanIndex())), maxHP(
				GUIStaticData::getPlayerHP(GUIStaticData::getHumanIndex())), _isDead(
				false), _isDying(false), isChained(false), playerSelected(
				false), playerSelectable(true) {
	setupUi(this);
	setFixedSize(fixedSize);

	skillLabel = new SkillLabel(this);
	skillLabel->move(skillPosition);
	skillLabel->hide();

	skillButton[0] = skill0;
	skillButton[1] = skill1;
	skillButton[2] = skill2;
	skillButton[3] = skill3;
	skill0->hide();
	skill1->hide();
	skill2->hide();
	skill3->hide();
	spacer1->hide();
	spacer2->hide();
	skillWidget1->hide();
	skillWidget2->hide();
	noSkill->setFont(GUIStaticData::contentFont);

	// first disable all, then skill normalize will enable them
	disableAllSkillButtons();

	switch (skillCount) {
	case 4:
		skill3->show();
		spacer2->show();
		connect(skillButton[3], SIGNAL(clicked()), this, SLOT(skillSlot3()));
		/* no break */
	case 3:
		skill2->show();
		skillWidget2->show();
		connect(skillButton[2], SIGNAL(clicked()), this, SLOT(skillSlot2()));
		/* no break */
	case 2:
		skill1->show();
		spacer1->show();
		connect(skillButton[1], SIGNAL(clicked()), this, SLOT(skillSlot1()));
		/* no break */
	case 1:
		skill0->show();
		skillWidget1->show();
		connect(skillButton[0], SIGNAL(clicked()), this, SLOT(skillSlot0()));
		noSkill->hide();
		/* no break */
	}

	for (int i = 0; i < skillCount; ++i) {
		skillButton[i]->setText(
				setColored(
						skillDisplayName(
								GUIStaticData::getPlayerSkill(_playerIndex, i)),
						false));
	}

	recoverLabel = new QLabel(this);
	recoverLabel->move(recoverLabelMargin);
	recoverLabel->hide();
	recoverLabel->setPixmap(QPixmap("images/HP/recover.png"));
	recoverLabel->setFixedSize(recoverLabel->sizeHint());
	recoverTimer = new QTimer(this);
	recoverTimer->setSingleShot(true);
	connect(recoverTimer, SIGNAL(timeout()), recoverLabel, SLOT(hide()));
}

void WujiangArea::enableSkillButton(int skillButtonIndex, bool enable) {
	if (skillButtonIndex >= 0 && skillButtonIndex < skillCount)
		skillButton[skillButtonIndex]->setEnabled(enable);
}

void WujiangArea::disableSkillButton(int skillButtonIndex, bool disable) {
	if (skillButtonIndex >= 0 && skillButtonIndex < skillCount)
		skillButton[skillButtonIndex]->setDisabled(disable);
}

void WujiangArea::disableAllSkillButtons() {
	for (int i = 0; i < skillCount; ++i) {
		skillButton[i]->setDisabled();
	}
}

sgs::ConstData::HeroSex WujiangArea::getSex() const {
	return sex;
}

sgs::ConstData::HeroType WujiangArea::getHeroType() const {
	return heroType;
}

sgs::ConstData::PlayerRole WujiangArea::getRole() const {
	return role;
}

int WujiangArea::getHP() const {
	return HP;
}

int WujiangArea::playerIndex() const {
	return _playerIndex;
}

int WujiangArea::getMaxHP() const {
	return maxHP;
}

bool WujiangArea::chained() const {
	return isChained;
}

bool WujiangArea::isDead() const {
	return _isDead;
}

bool WujiangArea::isDying() const {
	return _isDying;
}

void WujiangArea::setDead() {
	if (!_isDead) {
		_isDead = true;
		setDying(false);
		playerSelected = false;
		playerSelectable = false;
		update();
	}
}

void WujiangArea::setDying(bool dying) {
	if (_isDying != dying) {
		_isDying = dying;
		update();
	}
}

void WujiangArea::showSkill(sgs::ConstData::HeroSkill skill) {
	skillLabel->showSkill(skill);
}

void WujiangArea::showRecover() {
	recoverLabel->show();
	recoverTimer->start(GUIStaticData::showRecoverDuration);
}

void WujiangArea::resetChain() {
	isChained = !isChained;
	update();
}

sgs::DataType::Player * WujiangArea::getPlayer() {
	return GUIStaticData::getPlayer(GUIStaticData::getHumanIndex());
}

sgs::ConstData::HeroSkill WujiangArea::getSkill(int skillIndex) {
	return (skillIndex < skillCount) ?
			GUIStaticData::getPlayerSkill(_playerIndex, skillIndex) :
			sgs::ConstData::hkNone;
}

void WujiangArea::click() {
	QMouseEvent temp(QEvent::MouseButtonRelease, clickableRect.center(),
			Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
	mousePressEvent(&temp);
	mouseReleaseEvent(&temp);
}

bool WujiangArea::isSelected() {
	return playerSelected;
}

bool WujiangArea::isSelectable() {
	return playerSelectable;
}

void WujiangArea::setSelected(bool selected) {
	if (_isDead)
		return;

	if (isSelectable() && (isSelected() != selected)) {
		playerSelected = selected;
		update();
	}
}

void WujiangArea::setUnselected(bool unselected) {
	setSelected(!unselected);
}

void WujiangArea::setSelectable(bool selectable) {
	if (_isDead)
		return;

	if (!selectable)
		setUnselected(true);

	if (playerSelectable != selectable) {
		playerSelectable = selectable;
		update();
	}
}

void WujiangArea::setUnselectable(bool unselectable) {
	setSelectable(!unselectable);
}

void WujiangArea::setHP(int _HP) {
	if (HP != _HP) {
		HP = _HP;
		if (HP > 0)
			_isDying = false;
		update();
	}
}

void WujiangArea::setHPDamage(int damage) {
	HP -= damage;
	printDebug("WujiangArea::setHPDamage: now HP = " + QString::number(HP));
	if (HP > 0)
		_isDying = false;
	update();
	if (damage < 0)
		showRecover();
}

void WujiangArea::skillSlot0() {
	emit skillClicked(GUIStaticData::getPlayerSkill(_playerIndex, 0), 0);
}

void WujiangArea::skillSlot1() {
	emit skillClicked(GUIStaticData::getPlayerSkill(_playerIndex, 1), 1);
}

void WujiangArea::skillSlot2() {
	emit skillClicked(GUIStaticData::getPlayerSkill(_playerIndex, 2), 2);
}

void WujiangArea::skillSlot3() {
	emit skillClicked(GUIStaticData::getPlayerSkill(_playerIndex, 3), 3);
}

void WujiangArea::mousePressEvent(QMouseEvent *event) {
	if (_isDead || !clickableRect.contains(event->pos()))
		return;

	if (playerSelectable && event->button() == Qt::LeftButton
			&& mainWindow()->isResponding())
		static_cast<MainWindow *>(window())->playerClicked(this);
}

void WujiangArea::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.drawPixmap(playerPixmapMargin, playerPixmap);
	painter.drawPixmap(countrySmallMargin, countrySmallPixmap);
	painter.drawPixmap(rolePixmapMargin, rolePixmap);

	int verticalDifference = maxHPHeight / maxHP;
	if (verticalDifference > maxVerticalHPDifference)
		verticalDifference = maxVerticalHPDifference;
	for (int i = 0, j = verticalHPMargin; i < maxHP; ++i, j +=
			verticalDifference) {
		if (i < HP)
			painter.drawPixmap(horizontalHPMargin, j, HPPixmapStr(HP));
		else
			painter.drawPixmap(horizontalHPMargin, j, HPPixmapStr(0));
	}

	if (isChained)
		painter.drawPixmap(chainPixmapMargin, chainPixmap);

	if (playerSelected)
		painter.fillRect(coloredRect, selectedColor);

	if (!playerSelectable)
		painter.fillRect(coloredRect, unselectableColor);

	if (_isDead)
		painter.drawPixmap(deadPixmapMargin, deadRolePixmap);

	if (_isDying)
		painter.drawPixmap(dyingPixmapMargin, dyingPixmap);
}

MainWindow * WujiangArea::mainWindow() const {
	return static_cast<MainWindow *>(window());
}

} /* namespace sgsui */
