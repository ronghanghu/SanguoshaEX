/*
 * sgsui_PlayerArea.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: latios
 */

#include "sgsui_PlayerArea.h"
#include "sgsui_MainWindow.h"
#include "sgsui_CardFrame.h"
#include "sgsui_SkillLabel.h"
#include "sgsui_ZhuangbeiLabel.h"
#include "sgsui_nameConvert.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

const QSize PlayerArea::fixedSize(144, 199);
const QPoint PlayerArea::skillPosition(15, 60);
const QPoint PlayerArea::zhuangbeiPosition(0, 40);
const QPoint PlayerArea::playerFrameMargin(6, 6);
const QPoint PlayerArea::playerPixmapMargin(11, 23);
const QPoint PlayerArea::countryFrameMargin(9, 21);
const QPoint PlayerArea::countrySmallMargin(2, 2);
const QPoint PlayerArea::rolePixmapMargin(91, 23);
const QPoint PlayerArea::shoupaiPixmapMargin(113, 75);

const QPoint PlayerArea::wuqiColorMargin(1, 118);
const QPoint PlayerArea::wuqiPixmapMargin(20, 124);
const QPoint PlayerArea::fangjuColorMargin(1, 135);
const QPoint PlayerArea::fangjuPixmapMargin(20, 141);
const QPoint PlayerArea::jianmaColorMargin(1, 152);
const QPoint PlayerArea::jianmaPixmapMargin(20, 158);
const QPoint PlayerArea::jiamaColorMargin(1, 169);
const QPoint PlayerArea::jiamaPixmapMargin(20, 175);
const QPoint PlayerArea::chainPixmapMargin(0, 20);
const QPoint PlayerArea::phasePixmapMargin(121, 126);
const QPoint PlayerArea::dyingPixmapMargin(20, 80);
const QPoint PlayerArea::deadPixmapMargin(-10, 40);
const QPoint PlayerArea::statusPixmapMargin(30, 0);
const QPoint PlayerArea::recoverLabelMargin(0, 50);
const int PlayerArea::horizontalHPMargin = 11;
const int PlayerArea::verticalHPMargin = 77;
const int PlayerArea::maxHorizontalHPDifference = 14;
const int PlayerArea::maxHPWidth = 100;

const QRect PlayerArea::playerFrameRect(6, 6, 133, 185);
const QColor PlayerArea::selectedColor(255, 0, 0, 100);
const QColor PlayerArea::unselectableColor(0, 0, 0, 100);

PlayerArea::PlayerArea(int thisPlayerIndex, QWidget *parent) :
		QFrame(parent), _playerIndex(thisPlayerIndex), role(
				GUIStaticData::getPlayerRole(_playerIndex)), heroType(
				GUIStaticData::getPlayerType(_playerIndex)), sex(
				GUIStaticData::getPlayerSex(_playerIndex)), side(
				GUIStaticData::getPlayerSide(_playerIndex)),

		framePixmap("images/frame/playerArea.png"), playerPixmap(
				wujiangOtherPixmapStr(heroType)), countryFramePixmap(
				countryFramePixmapStr(side)), countrySmallPixmap(
				countrySmallPixmapStr(side)), rolePixmap(
				rolePixmapStr(role, GUIStaticData::isDebugLogOn())), deadRolePixmap(
				deadRolePixmapStr(role)), dyingPixmap(
				"images/animation/save-me.png"), shoupaiPixmap(
				"images/system/handcard.png"), chainPixmap(
				"images/status/chain.png"), lebuPixmap(
				"images/status/indulgence.png"), shandianPixmap(
				"images/status/lightning.png"), bingliangPixmap(
				"images/status/supply_shortage.png"),

		HP(GUIStaticData::getPlayerHP(_playerIndex)), maxHP(HP), shoupaiNumber(
				0),

		_isDead(false), _isDying(false), isResponding(false), isChained(false), phase(
				sgs::ConstData::OTHER), playerSelected(false), playerSelectable(
				true),

		wuqiCard(0), fangjuCard(0), jianmaCard(0), jiamaCard(0) {
	setupUi(this);
	setFixedSize(fixedSize);

	skillLabel = new SkillLabel(this);
	skillLabel->move(skillPosition);
	skillLabel->hide();

	zhuangbeiLabel = new ZhuangbeiLabel(this);
	zhuangbeiLabel->move(zhuangbeiPosition);
	zhuangbeiLabel->hide();

	recoverLabel = new QLabel(this);
	recoverLabel->move(recoverLabelMargin);
	recoverLabel->hide();
	recoverLabel->setPixmap(QPixmap("images/HP/recover.png"));
	recoverLabel->setFixedSize(recoverLabel->sizeHint());
	recoverTimer = new QTimer(this);
	recoverTimer->setSingleShot(true);
	connect(recoverTimer, SIGNAL(timeout()), recoverLabel, SLOT(hide()));

	shoupaiNumLabel->setFont(GUIStaticData::statusbarFont);
	shoupaiNumLabel->hide();
}

QPoint PlayerArea::topLeftPoint() const {
	QPoint topLeftCoordinate = pos();
	for (QWidget *thisWidget = parentWidget(); thisWidget != window();
			thisWidget = thisWidget->parentWidget()) {
		topLeftCoordinate += thisWidget->pos();
	}
	return topLeftCoordinate;
}

QRect PlayerArea::realGeometry() const {
	return QRect(topLeftPoint(), size());
}

int PlayerArea::playerIndex() const {
	return _playerIndex;
}

sgs::ConstData::HeroSex PlayerArea::getSex() const {
	return sex;
}

sgs::ConstData::HeroType PlayerArea::getHeroType() const {
	return heroType;
}

sgs::ConstData::PlayerRole PlayerArea::getRole() const {
	return role;
}

int PlayerArea::getHP() const {
	return HP;
}

int PlayerArea::getPhase() const {
	return phase;
}

int PlayerArea::getShoupaiNumber() const {
	return shoupaiNumber;
}

const CardFrame * PlayerArea::getWuqi() const {
	return wuqiCard;
}

const CardFrame * PlayerArea::getFangju() const {
	return fangjuCard;
}

const CardFrame * PlayerArea::getJianma() const {
	return jianmaCard;
}

const CardFrame * PlayerArea::getJiama() const {
	return jiamaCard;
}

void PlayerArea::addJudge(sgs::ConstData::CardType judgeCard) {
	judgeList.push_back(judgeCard);
	update();
}

void PlayerArea::removeJudge(sgs::ConstData::CardType judgeCard) {
	judgeList.remove(judgeCard);
	update();
}

bool PlayerArea::chained() const {
	return isChained;
}

bool PlayerArea::isDead() const {
	return _isDead;
}

bool PlayerArea::isDying() const {
	return _isDying;
}

void PlayerArea::setDead() {
	if (!_isDead) {
		_isDead = true;
		if (role != sgs::ConstData::ZHU)
			rolePixmap = QPixmap(rolePixmapStr(role, true));
		playerSelected = false;
		playerSelectable = false;
		shoupaiNumLabel->hide();
		_isDying = false;
		isResponding = false;
		phase = sgs::ConstData::OTHER;
		update();
	}
}

void PlayerArea::setDying(bool dying) {
	if (_isDying != dying) {
		_isDying = dying;
		update();
	}
}

void PlayerArea::setResponding(bool responding) {
	if (isResponding != responding) {
		isResponding = responding;
		update();
	}
}

void PlayerArea::addWuqi(CardFrame * newWuqiCard) {
	if (wuqiCard)
		delete wuqiCard;
	wuqiCard = newWuqiCard;
	update();
}

void PlayerArea::addFangju(CardFrame * newFangjuCard) {
	if (fangjuCard)
		delete fangjuCard;
	fangjuCard = newFangjuCard;
	update();
}

void PlayerArea::addJianma(CardFrame * newJianmaCard) {
	if (jianmaCard)
		delete jianmaCard;
	jianmaCard = newJianmaCard;
	update();
}

void PlayerArea::addJiama(CardFrame * newJiamaCard) {
	if (jiamaCard)
		delete jiamaCard;
	jiamaCard = newJiamaCard;
	update();
}

void PlayerArea::removeWuqi() {
	if (wuqiCard)
		delete wuqiCard;
	wuqiCard = 0;
	update();
}

void PlayerArea::removeFangju() {
	if (fangjuCard)
		delete fangjuCard;
	fangjuCard = 0;
	update();
}

void PlayerArea::removeJianma() {
	if (jianmaCard)
		delete jianmaCard;
	jianmaCard = 0;
	update();
}

void PlayerArea::removeJiama() {
	if (jiamaCard)
		delete jiamaCard;
	jiamaCard = 0;
	update();
}

sgs::DataType::Player * PlayerArea::getPlayer() {
	return GUIStaticData::getPlayer(_playerIndex);
}

void PlayerArea::click() {
	QMouseEvent temp(QEvent::MouseButtonRelease,
			QPoint(width() / 2, height() / 2), Qt::LeftButton, Qt::LeftButton,
			Qt::NoModifier);
	mousePressEvent(&temp);
	mouseReleaseEvent(&temp);
}

bool PlayerArea::isSelected() {
	return playerSelected;
}

bool PlayerArea::isSelectable() {
	return playerSelectable;
}

void PlayerArea::setSelected(bool selected) {
	if (_isDead)
		return;

	if (isSelectable() && (isSelected() != selected)) {
		playerSelected = selected;
		update();
	}
}

void PlayerArea::setUnselected(bool unselected) {
	setSelected(!unselected);
}

void PlayerArea::setSelectable(bool selectable) {
	if (_isDead)
		return;

	if (!selectable)
		setUnselected(true);

	if (playerSelectable != selectable) {
		playerSelectable = selectable;
		update();
	}
}

void PlayerArea::setUnselectable(bool unselectable) {
	setSelectable(!unselectable);
}

void PlayerArea::setHP(int _HP) {
	if (HP != _HP) {
		HP = _HP;
		if (HP > 0)
			_isDying = false;
		update();
	}
}

void PlayerArea::setHPDamage(int damage) {
	HP -= damage;
	if (HP > 0)
		_isDying = false;
	update();
	if (damage < 0)
		showRecover();
}

void PlayerArea::setPhase(sgs::ConstData::PlayerPhase _phase) {
	if (phase != _phase) {
		phase = _phase;
		update();
	}
}

void PlayerArea::setShoupaiNumber(int _shoupaiNumber) {
	if (shoupaiNumber != _shoupaiNumber) {
		shoupaiNumber = _shoupaiNumber;
		if (shoupaiNumber > 0) {
			shoupaiNumLabel->setText(
					setColored(QString::number(shoupaiNumber)));

			if (shoupaiNumLabel->isHidden()) {
				shoupaiNumLabel->show();
				update();
			}
		} else {
			shoupaiNumLabel->hide();
			update();
		}
	}
}

void PlayerArea::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.drawPixmap(playerFrameMargin, framePixmap);
	painter.drawPixmap(playerPixmapMargin, playerPixmap);
	painter.drawPixmap(countryFrameMargin, countryFramePixmap);
	painter.drawPixmap(countrySmallMargin, countrySmallPixmap);
	painter.drawPixmap(rolePixmapMargin, rolePixmap);

	if (shoupaiNumber > 0)
		painter.drawPixmap(shoupaiPixmapMargin, shoupaiPixmap);

	int horizontalDifference = maxHPWidth / maxHP;
	if (horizontalDifference > maxHorizontalHPDifference)
		horizontalDifference = maxHorizontalHPDifference;
	for (int i = 0, j = horizontalHPMargin; i < maxHP; ++i, j +=
			horizontalDifference) {
		if (i < HP)
			painter.drawPixmap(j, verticalHPMargin, (smallHPPixmapStr(HP)));
		else
			painter.drawPixmap(j, verticalHPMargin, (smallHPPixmapStr(0)));
	}

	// take all numbers on small zhuangbei pixmap as SPADE (black color)
	using sgs::ConstData::SPADE;
	if (wuqiCard) {
		painter.drawPixmap(wuqiColorMargin,
				cardColorStr(wuqiCard->getCardColor()));
		painter.drawPixmap(wuqiPixmapMargin,
				smallZhuangbeiPixmapStr(wuqiCard->getCardType()));
	}
	if (fangjuCard) {
		painter.drawPixmap(fangjuColorMargin,
				cardColorStr(fangjuCard->getCardColor()));
		painter.drawPixmap(fangjuPixmapMargin,
				smallZhuangbeiPixmapStr(fangjuCard->getCardType()));
	}
	if (jianmaCard) {
		painter.drawPixmap(jianmaColorMargin,
				cardColorStr(jianmaCard->getCardColor()));
		painter.drawPixmap(jianmaPixmapMargin,
				smallZhuangbeiPixmapStr(jianmaCard->getCardType()));
	}
	if (jiamaCard) {
		painter.drawPixmap(jiamaColorMargin,
				cardColorStr(jiamaCard->getCardColor()));
		painter.drawPixmap(jiamaPixmapMargin,
				smallZhuangbeiPixmapStr(jiamaCard->getCardType()));
	}

	int i = 0;
	for (std::list<sgs::ConstData::CardType>::iterator iter = judgeList.begin();
			iter != judgeList.end(); ++iter) {
		switch (*iter) {
		case sgs::ConstData::SHANDIAN:
			painter.drawPixmap(statusPixmapMargin * (++i), shandianPixmap);
			break;
		case sgs::ConstData::SISHU:
			painter.drawPixmap(statusPixmapMargin * (++i), lebuPixmap);
			break;
		case sgs::ConstData::BINGLIANG:
			painter.drawPixmap(statusPixmapMargin * (++i), bingliangPixmap);
			break;
		default:
			break;
		}
	}

	if (isChained)
		painter.drawPixmap(chainPixmapMargin, chainPixmap);

	if (phase != sgs::ConstData::OTHER || _isDying || isResponding) {
		painter.drawPixmap(phasePixmapMargin,
				QPixmap(phasePixmapStr(phase, _isDying, isResponding)));
		painter.drawPixmap(0, 0,
				QPixmap(phaseFramePixmapStr(phase, _isDying, isResponding)));
	}

	if (_isDying)
		painter.drawPixmap(dyingPixmapMargin, dyingPixmap);

	if (_isDead)
		painter.drawPixmap(deadPixmapMargin, deadRolePixmap);

	if (playerSelected)
		painter.fillRect(playerFrameRect, selectedColor);

	if (!playerSelectable)
		painter.fillRect(playerFrameRect, unselectableColor);
}

void PlayerArea::mousePressEvent(QMouseEvent *event) {
	if (_isDead)
		return;

	if (playerSelectable && event->button() == Qt::LeftButton
			&& mainWindow()->isResponding())
		mainWindow()->playerClicked(this);
}

MainWindow* PlayerArea::mainWindow() const {
	return static_cast<MainWindow*>(window());
}

void PlayerArea::showSkill(sgs::ConstData::HeroSkill skill) {
	skillLabel->showSkill(skill);
}

void PlayerArea::showRecover() {
	recoverLabel->show();
	recoverTimer->start(GUIStaticData::showRecoverDuration);
}

void PlayerArea::showZhuangbei(sgs::ConstData::CardType equipCard) {
	zhuangbeiLabel->showZhuangbei(equipCard);
}

void PlayerArea::resetChain() {
	isChained = !isChained;
	update();
}

} /* namespace sgsui */
