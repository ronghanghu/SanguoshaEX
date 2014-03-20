/*
 //最后编辑时间：2012-06-28
 //编辑者：李昂
 */
#include "sgsdata_extern.h"
#include "sgsdata_player.h"
#include "sgs_Interface.h"
#include "sgsdata_hero.h"
#include "sgsdata_heroes.h"
#include "sgsui_global.h"
#include "sgsdata_card.h"
#include "sgsdata_card_func.h"
#include "sgsui_GUIStaticData.h"
#include "sgsdata_history.h"
#include "sgsdata_platform.h"

using namespace sgs;
using namespace ConstData;
using namespace DataType;
using namespace Derive;
using namespace ExternData;

Player::Player(int s, PlayerRole r) :
		_seat(s), _role(r) {
	_status = 0;
	_shaCount = 0;
	_phase = OTHER;
	_equip.armor = 0;
	_equip.atkhorse = 0;
	_equip.dfdhorse = 0;
	_equip.weapon = 0;
}
Player::~Player() {
	_hand.clear();
	_judge.clear();
}

void Player::herotrans(HeroType t) {
	switch (t) {
	case SUJIANG:
		_hero = &ExternData::hsujiang;
		break;
	case NVSUJIANG:
		_hero = &ExternData::hnvsujiang;
		break;
	case ZHANGFEI:
		_hero = &ExternData::hzhangfei;
		break;
	case LVMENG:
		_hero = &ExternData::hlvmeng;
		break;
	case MACHAO:
		_hero = &ExternData::hmachao;
		break;
	case GUANYU:
		_hero = &ExternData::hguanyu;
		break;
	case XIAHOUDUN:
		_hero = &ExternData::hxiahoudun;
		break;
	case XUCHU:
		_hero = &ExternData::hxuchu;
		break;
	case ZHENJI:
		_hero = &ExternData::hzhenji;
		break;
	case LAOZHUGE:
		_hero = &ExternData::hlaozhuge;
		break;
	case ZHAOYUN:
		_hero = &ExternData::hzhaoyun;
		break;
	case GANNING:
		_hero = &ExternData::hganning;
		break;
	case SIMAYI:
		_hero = &ExternData::hsimayi;
		break;
	case HUANGGAI:
		_hero = &ExternData::hhuanggai;
		break;
	case HUATUO:
		_hero = &ExternData::hhuatuo;
		break;
	case LIUBEI:
		_hero = &ExternData::hliubei;
		break;
	case CAOCAO:
		_hero = &ExternData::hcaocao;
		break;
	case HUANGYUEYING:
		_hero = &ExternData::hhuangyueying;
		break;
	case DIAOCHAN:
		_hero = &ExternData::hdiaochan;
		break;
	case ZHANGLIAO:
		_hero = &ExternData::hzhangliao;
		break;
	case GUOJIA:
		_hero = &ExternData::hguojia;
		break;
	case SUNQUAN:
		_hero = &ExternData::hsunquan;
		break;
	case LVBU:
		_hero = &ExternData::hlvbu;
		break;
	case ZHOUYU:
		_hero = &ExternData::hzhouyu;
		break;
	case SUNSHANGXIANG:
		_hero = &ExternData::hsunshangxiang;
		break;
	case LUXUN:
		_hero = &ExternData::hluxun;
		break;
	case DAQIAO:
		_hero = &ExternData::hdaqiao;
		break;
	default:
		_hero = 0;
		break;
	}
}

int Player::maxHP() const {
	return _hero->maxHP()
			+ (_role == ZHU && sgsui::GUIStaticData::getPlayerCount() >= 4);
}
HeroType Player::type() const {
	return _hero->type();
}
HeroSex Player::sex() const {
	return _hero->sex();
}
HeroSide Player::side() const {
	return _hero->side();
}
int Player::skillnum() const {
	return _hero->skillnum();
}
Skill Player::skill(int pos) {
	return _hero->skill(pos);
}
Interface * Player::input() const {
	return _input;
}
Player * Player::next() const {
	return _next;
}
Player * Player::prev() const {
	return _prev;
}
Player * Player::after() const {
	Player * aft = _next;
	while (aft->_status & DEAD) {
		aft = aft->_next;
		if (aft == this)
			return 0;
	}
	return aft;
}
Player * Player::before() const {
	Player * bef = _prev;
	while (bef->_status & DEAD) {
		bef = bef->_prev;
		if (bef == this)
			return 0;
	}
	return bef;
}
Player * Player::find(int n) const {
	if (n < 0)
		return 0;
	else if (n == _seat)
		return this->_next->_prev;
	else {
		Player * find = this->_next->_prev;
		for (int i = 0; find->_seat != n && i < 10; i++)
			find = find->_next;
		if (find->_seat == n)
			return find;
		else
			return 0;
	}
}
int Player::distance(const Player * p) const {
	if (p == 0)
		return -1;
	if (p == this)
		return 0;
	int n = 1, m = 1;
	for (Player * start = _next; start != p; start = start->_next)
		if (!(start->_status & DEAD))
			n++;
	for (Player * start = _prev; start != p; start = start->_prev)
		if (!(start->_status & DEAD))
			m++;
	n = (n > m) ? m : n;
	if (_equip.atkhorse != 0)
		n--;
	if (p->_equip.dfdhorse != 0)
		n++;
	if (type() == MACHAO && n > 0)
		n--;
	return n;
}
int Player::range() const {
	if (_equip.weapon == 0)
		return 1;
	else
		switch (_equip.weapon->mask()) {
		case ctNone:
			return 1;
		case ZHUGE:
			return 1;
		case QINGGANG:
			return 2;
		case HANBING:
			return 2;
		case CIXIONG:
			return 2;
		case GUANSHI:
			return 3;
		case YINYUE:
			return 3;
		case QINGLONG:
			return 3;
		case GUDING:
			return 2;
		case ZHANGBA:
			return 3;
		case FANGTIAN:
			return 4;
		case QILIN:
			return 5;
		case ZHUQUE:
			return 4;
		default:
			return 1;
		}
}
int Player::seat() const {
	return _seat;
}
PlayerRole Player::role() const {
	return _role;
}
PlayerPhase Player::phase() const {
	return _phase;
}
int Player::hp() const {
	return _hp;
}
char Player::status() const {
	return _status;
}
int Player::handnum() {
	return _hand.size();
}
const Card * Player::hand(int pos) {
	int N = 0;
	if (pos < 0 || pos >= (N = _hand.size()))
		return 0;
	return _hand.at(pos + 1);
}
int Player::judgenum() {
	return _judge.size();
}
const Card * Player::judge(int pos) {
	int N = 0;
	if (pos < 0 || pos >= (N = _judge.size()))
		return 0;
	return _judge.at(pos + 1);
}
const Card * Player::atkhorse() const {
	return _equip.atkhorse;
}
const Card * Player::dfdhorse() const {
	return _equip.dfdhorse;
}
const Card * Player::weapon() const {
	return _equip.weapon;
}
const Card * Player::armor() const {
	return _equip.armor;
}
const Card * Player::visitCard(std::pair<PlayerRegionType, int> pos) {
	switch (pos.first) {
	case PHAND:
		return hand(pos.second);
	case PEQUIP:
		switch (pos.second) {
		case 0:
			return _equip.weapon;
		case 1:
			return _equip.armor;
		case 2:
			return _equip.atkhorse;
		case 3:
			return _equip.dfdhorse;
		default:
			return 0;
		}
		break;
	case PJUDGE:
		return judge(pos.second);
	default:
		return 0;
	}
}

Message * Player::round(Platform& /*platform*/) {
	Message * m = 0;
	switch (_phase) {
	case OTHER:
		m = new MSwitchPhase(this, OTHER, START);
		_phase = START;
		break;
	case START:
		m = _hero->start(this);
		break;
	case JUDGEMENT:
		m = _hero->judge(this);
		break;
	case GETCARD:
		m = _hero->get(this);
		break;
	case MAIN:
        m = _hero->heromain(this);
		break;
	case ABANDONCARD:
		m = _hero->abandon(this);
		break;
	case END:
		m = _hero->end(this);
		break;
	default:
		break;
	}
	return m;
}
char& Player::setstatus() {
	return _status;
}
int Player::shaCount() const {
	return _shaCount;
}
void Player::addShaCount() {
	++_shaCount;
}
void Player::clearShaCount() {
	_shaCount = 0;
}
void Player::setphase(PlayerPhase s) {
	_phase = s;
}
int& Player::sethp() {
	return _hp;
}
//chain<const sgs::DataType::Card *>& Player::sethand() {
//	return _hand;
//}
chain<const sgs::DataType::Card *>& Player::setjudge() {
	return _judge;
}
void Player::setatk(const sgs::DataType::Card *c) {
	_equip.atkhorse = c;
}
void Player::setdfd(const sgs::DataType::Card *c) {
	_equip.dfdhorse = c;
}
void Player::setweapon(const sgs::DataType::Card *c) {
	_equip.weapon = c;
}
void Player::setarmor(const sgs::DataType::Card *c) {
	_equip.armor = c;
}

void Player::choosehero(std::vector<HeroType>& herovec, HeroType lord) {
	if (lord == sgs::ConstData::htNone) {
		HeroType avaliable[5];
		std::vector<HeroType>::reverse_iterator riter = herovec.rbegin();
		for (int i = 0; i < 5; ++i) {
			avaliable[i] = *riter++;
		}
		HeroType choosenHero;
		if (_seat == 0) {
			herotrans(
					choosenHero = sgsui::lordChoose(avaliable[0], avaliable[1],
							avaliable[2], avaliable[3], avaliable[4]));
		} else {
			herotrans(choosenHero = avaliable[rand() % 5]);
		}
		for (int i = 0; i < 5; ++i)
			herovec.pop_back();

		for (int i = 0; i < 5; ++i) {
			if (avaliable[i] != choosenHero)
				herovec.push_back(avaliable[i]);
		}
		_hp = _hero->maxHP() + 1;
	} else {
		if (_seat == 0) {
			herotrans(
					sgsui::heroChoose(lord, _role, *(herovec.rbegin() + 0),
							*(herovec.rbegin() + 1), *(herovec.rbegin() + 2)));
		} else {
			herotrans(*(herovec.rbegin() + rand() % 3));
		}

		for (int i = 0; i < 3; ++i)
			herovec.pop_back();

		_hp = _hero->maxHP();
	}
}

void Player::popCard(std::pair<PlayerRegionType, int> pos) {
	switch (pos.first) {
	case PHAND:
		_hand.pop(pos.second + 1);
		if (type() == LUXUN && !(status() & DEAD) && _hand.empty()
				&& input()->useSkillOrNot(LIANYING)) {
			MSkill * lianying = new MSkill(this, LIANYING);
			ExternData::sgsout << lianying;
			ExternData::history.push(lianying);

			MTransCard * trans = new MTransCard(POOLTOP, PLAYER, _seat == 0, 0,
					prtNone, this);
			trans->transpush(ExternData::platform.get());
			ExternData::platform.analyze(trans);
		}
		break;
	case PEQUIP:
		switch (pos.second) {
		case 0:
			_equip.weapon = 0;
			break;
		case 1:
			_equip.armor = 0;
			break;
		case 2:
			_equip.atkhorse = 0;
			break;
		case 3:
			_equip.dfdhorse = 0;
			break;
		default:
			return;
		}
		break;
	case PJUDGE:
		_judge.pop(pos.second + 1);
		break;
	default:
		return;
	}
}

void Player::setinput(sgs::Interface * i) {
	_input = i;
}

void Player::pushHand(const Card * c) {
	c->setmask();
	_hand.push(c);
}

Message * Player::ShanOrNot(Message * m) {
	MCard * c = static_cast<MCard *>(m);
	Message *response = _input->shanOrNot(c->from(), c->card());
	if (response == 0)
		return 0;
	else {
		MCard * res = 0;
		switch (response->type()) {
		case USESKILL:
			response = static_cast<MSkill *>(response)->settle(response);
			if (response == 0)
				return 0;
			res = static_cast<MCard *>(response);
			break;
		default:
			res = static_cast<MCard *>(response);
			res->from()->popCard(
					std::pair<PlayerRegionType, int>(PHAND, res->pos().second));
			break;
			/* no break */
		}
		return res;
	}
}

Message * Player::TaoOrNot(Message * m) {
	MDying * c = static_cast<MDying *>(m);
	Message *response = static_cast<MCard *>(_input->taoOrNot(c->from(),
			c->neg()));
	if (response == 0)
		return 0;
	else {
		MCard * res = 0;
		switch (response->type()) {
		case USESKILL:
			response = static_cast<MSkill *>(response)->settle(response);
			res = static_cast<MCard *>(response);
			res->addto(c->from());
			break;
		default:
			res = static_cast<MCard *>(response);
			res->from()->popCard(
					std::pair<PlayerRegionType, int>(PHAND, res->pos().second));
			break;
			/* no break */
		}
		return res;
	}
}

Message * Player::ShaOrNot(Message * m) {
	if (m->type() == USESKILL) {
		MLiJian * l = static_cast<MLiJian *>(m);
		Player * target = (this == l->first()) ? l->second() : l->first();
		Message * response = _input->shaOrNot(target, LIJIAN);
		if (response == 0)
			return 0;
		else
			switch (response->type()) {
			case USESKILL: {
				response = static_cast<MSkill *>(response)->settle(response);
				if (response == 0)
					return 0;
				MCard * res = static_cast<MCard *>(response);
				while (res->targets())
					res->popto();
				res->addto(target);
			}
				break;
			case HITCARD:
			case USECARD: {
				MCard * res = static_cast<MCard *>(response);
				if (res->card()->type() == ZHANGBA) {
					MZhangBa * zhangba = new MZhangBa(res->from(), 0);
					delete res;
					res = func::pczhangba(zhangba);
				} else {
					res->from()->popCard(
							std::pair<PlayerRegionType, int>(PHAND,
									res->pos().second));
				}
				while (res->targets())
					res->popto();
				res->addto(target);
			}
				break;
            default:
                break;
			}
		return response;
	} else {
		MCard * c = static_cast<MCard *>(m);
		Message * response = _input->shaOrNot(c->from(), c->card());
		if (response == 0)
			return 0;
		else {
			switch (response->type()) {
			case USESKILL: {
				response = static_cast<MSkill *>(response)->settle(response);
				if (response == 0)
					return 0;
				MCard * res = static_cast<MCard *>(response);
				while (res->targets())
					res->popto();
				switch (c->card()->mask()) {
				case SHA:
					res->addto(c->to());
					break;
				case NANMAN:
// res->addto(c->from());
					break;
				case JUEDOU:
					if (c->from() == this)
						res->addto(c->to());
					else
						res->addto(c->from());
					break;
				case JIEDAO:
					res->addto(c->to(1));
					break;
				default:
					break;
				}
			}
				break;
			case HITCARD:
			case USECARD: {
				MCard * res = static_cast<MCard *>(response);
				if (res->card()->type() == ZHANGBA) {
					MZhangBa * zhangba = new MZhangBa(res->from(), 0);
					delete res;
					res = func::pczhangba(zhangba);
				} else {
					res->from()->popCard(
							std::pair<PlayerRegionType, int>(PHAND,
									res->pos().second));
				}
				while (res->targets())
					res->popto();
				switch (c->card()->type()) {
				case SHA:
					res->addto(c->to());
					break;
				case NANMAN:
// res->addto(c->from());
					break;
				case JUEDOU:
					if (c->from() == this)
						res->addto(c->to());
					else
						res->addto(c->from());
					break;
				case JIEDAO:
					res->addto(c->to(1));
					break;
				default:
					break;
				}
			}
				break;
			default:
				break;
			}
			return response;
		}
	}
}

Message * Player::WuXieOrNot(Message * m, int times) {
	MCard * res = static_cast<MCard *>(_input->wuxieOrNot(m, times));
	if (res == 0)
		return 0;
	else {
		popCard(res->pos());
		res->addto(this);
		return res;
	}
}
