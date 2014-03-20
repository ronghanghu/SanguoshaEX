/*
 //最后编辑时间：2012-06-28
 //编辑者：李昂
 */
#include "sgsdata_msg.h"
#include "sgsdata_player.h"
#include "sgsui_output.h"
using namespace sgs;
using namespace ConstData;
using namespace DataType;
using namespace Derive;

MessageType Message::type() const {
	return _type;
}
bool Message::dissolved() const {
	return _dissolved;
}
bool Message::setdissolve(bool b) {
	_dissolved = b;
	return _dissolved;
}
Message::~Message() {
}

MCard::MCard(bool use, Player * f, sgs::ConstData::PlayerRegionType p, int pos,
		Player * t) :
		Message(use ? USECARD : HITCARD), _from(f), _targets(0) {
	_pos.first = p;
	_pos.second = pos;
	switch (p) {
	case PHAND:
		_card = f->hand(pos);
		break;
	case PEQUIP:
		switch (pos) {
		case 0:
			_card = f->weapon();
			break;
		case 1:
			_card = f->armor();
			break;
		case 2:
			_card = f->atkhorse();
			break;
		case 3:
			_card = f->dfdhorse();
			break;
		}
		break;
	case PJUDGE:
		_card = f->judge(pos);
		break;
	default:
		break;
	}
	if (t != 0) {
		_to.push(t);
		_targets++;
	}
}
MCard::MCard(MCard * m) :
		Message(m->type()), _from(m->from()), _targets(1) {
	_pos.first = m->pos().first;
	_pos.second = m->pos().second;
	_card = m->card();
	_to.push(m->to(0));
}
MCard::MCard(bool use, Player *f, const Card * c, Player *t) :
		Message(use ? USECARD : HITCARD), _from(f), _targets(0) {
	_pos.first = prtNone;
	_pos.second = -1;
	_card = c;
	if (t != 0) {
		_to.push(t);
		_targets++;
	}
}

MSkill::MSkill(Player * from, HeroSkill type) :
		Message(USESKILL), _from(from), _skill(type) {
}
MSkill::~MSkill() {
}
Player * MSkill::from() const {
	return _from;
}
HeroSkill MSkill::skill() const {
	return _skill.skill();
}
Message * MSkill::settle(Message * m) {
	return _skill.settle(m);
}

MWuSheng::MWuSheng(Player * from, PlayerRegionType prt, int pos, Player * to) :
		MSkill(from, WUSHENG), _targets(0) {
	_pos = std::pair<PlayerRegionType, int>(prt, pos);
	_card = from->visitCard(_pos);
	if (to != 0) {
		_to.push(to);
		_targets++;
	}
}
MWuSheng::~MWuSheng() {
}
const Card * MWuSheng::card() const {
	return _card;
}
Player * MWuSheng::to(int pos) const {
	return _to.at(pos + 1);
}
int MWuSheng::targets() const {
	return _targets;
}
std::pair<PlayerRegionType, int> MWuSheng::pos() const {
	return _pos;
}
void MWuSheng::addto(Player * to) {
	if (to != 0) {
		_to.push(to);
		_targets++;
	}
}

void MWuSheng::popto(int pos) {
	if (pos >= 0 && pos < _targets) {
		_to.pop(pos + 1);
		_targets--;
	}
}

MGangLie::MGangLie(Player * from, Player * to) :
		MSkill(from, GANGLIE), _to(to) {
}
MGangLie::~MGangLie() {
}
Player * MGangLie::to() const {
	return _to;
}

MQingGuo::MQingGuo(Player * from, int pos) :
		MSkill(from, QINGGUO), _pos(pos) {
	if (pos >= 0 && pos < from->handnum()) {
		_card = from->hand(pos);
	} else {
		_card = 0;
		_pos = -1;
	}
}

MQingGuo::~MQingGuo() {
}
const Card * MQingGuo::card() const {
	return _card;
}
int MQingGuo::pos() const {
	return _pos;
}

MLongDan::MLongDan(Player * from, int pos, Player * to) :
		MSkill(from, LONGDAN), _targets(0), _pos(pos) {
	_card = from->hand(pos);
	if (to != 0) {
		_to.push(to);
		_targets++;
	}
}
MLongDan::~MLongDan() {
}
const Card * MLongDan::card() const {
	return _card;
}
Player * MLongDan::to(int pos) const {
	return _to.at(pos + 1);
}
int MLongDan::targets() const {
	return _targets;
}
int MLongDan::pos() const {
	return _pos;
}
void MLongDan::addto(Player * to) {
	if (to != 0) {
		_to.push(to);
		_targets++;
	}
}
void MLongDan::popto(int pos) {
	if (pos >= 0 && pos < _targets) {
		_to.pop(pos + 1);
		_targets--;
	}
}

MQiXi::MQiXi(Player * from, PlayerRegionType prt, int pos, Player * to) :
		MSkill(from, QIXI), _to(to) {
	_pos = std::pair<PlayerRegionType, int>(prt, pos);
	_card = from->visitCard(_pos);
}
MQiXi::~MQiXi() {
}
MFanKui::MFanKui(Player * from, Player * to) :
		MSkill(from, FANKUI), _to(to) {
}
MFanKui::~MFanKui() {
}
Player * MFanKui::to() const {
	return _to;
}

const Card *MQiXi::card() const {
	return _card;
}
Player * MQiXi::to() const {
	return _to;
}
std::pair<PlayerRegionType, int> MQiXi::pos() const {
	return _pos;
}

MQingNang::MQingNang(Player * from, int pos, Player * to) :
		MSkill(from, QINGNANG), _pos(pos), _to(to) {
	_card = from->hand(pos);
	// Note:  _pos(pos) was missing, added by Hu Ronghang
}
MQingNang::~MQingNang() {
}
const Card * MQingNang::card() const {
	return _card;
}
Player * MQingNang::to() const {
	return _to;
}
int MQingNang::pos() const {
	return _pos;
}

MJiJiu::MJiJiu(Player * from, PlayerRegionType prt, int pos) :
		MSkill(from, JIJIU) {
	_pos = std::pair<PlayerRegionType, int>(prt, pos);
	_card = from->visitCard(_pos);
}
MJiJiu::~MJiJiu() {
}
const Card * MJiJiu::card() const {
	return _card;
}
std::pair<sgs::ConstData::PlayerRegionType, int> MJiJiu::pos() const {
	return _pos;
}

MZhangBa::MZhangBa(Player * f, Player * t) :
		MCard(true, f, PEQUIP, 0, t) {
	_cost[0].first = 0;
	_cost[0].second = -1;
	_cost[1].first = 0;
	_cost[1].second = -1;
}
MZhangBa::~MZhangBa() {
}
std::pair<const Card *, int> MZhangBa::cost(int pos) const {
	if (pos < 0 || pos > 2)
		return std::pair<const Card *, int>((const Card *) 0, -1);
	else
		return _cost[pos];
}
bool MZhangBa::addcost(int pos) {
	if (pos < 0 || pos > from()->handnum()) {
		printDebug("MZhangBa::addcost: condition 1");
		return false;
	} else if (_cost[0].first && _cost[1].first) {
		printDebug("MZhangBa::addcost: condition 2");
		return false;
	} else if (_cost[0].first) {
		printDebug("MZhangBa::addcost: condition 3");
		_cost[1].second = pos;
		_cost[1].first = from()->hand(pos);
		return true;
	} else {
		printDebug("MZhangBa::addcost: condition 4");
		_cost[0].second = pos;
		_cost[0].first = from()->hand(pos);
		return true;
	}
}
Player * MCard::from() const {
	return _from;
}
Player * MCard::to(int pos) const {
	if (pos < 0 || pos >= _targets)
		return 0;
	else
		return _to.at(pos + 1);
}
const Card * MCard::card() const {
	return _card;
}
int MCard::targets() const {
	return _targets;
}
bool MCard::addto(sgs::DataType::Player * t) {
	if (t == 0)
		return false;
	else if (_to.push(t)) {
		_targets++;
		return true;
	} else
		return false;
}
bool MCard::popto(int pos) {
	if (pos < 0 || pos >= _to.size())
		return false;
	else if (_to.pop(pos + 1)) {
		_targets--;
		return true;
	} else
		return false;
}
std::pair<PlayerRegionType, int> MCard::pos() const {
	return _pos;
}
MCard::~MCard() {
	_to.clear();
}

MTransCard::MTransCard(RegionType ft, RegionType tt, bool open, Player * f,
		PlayerRegionType p, Player * t, bool tojudge) :
		Message(TRANSCARD), _fromtype(ft), _totype(tt), _open(open), _from(f), _to(
				t), _frompos(p), _cards(0), _toJudge(tojudge) {
}
MTransCard::~MTransCard() {
	_trans.clear();
	_pos.clear();
}
RegionType MTransCard::fromtype() const {
	return _fromtype;
}
RegionType MTransCard::totype() const {
	return _totype;
}
Player * MTransCard::from() const {
	return _from;
}
Player * MTransCard::to() const {
	return _to;
}
PlayerRegionType MTransCard::frompos() const {
	return _frompos;
}
int MTransCard::cards() const {
	return _cards;
}
const Card * MTransCard::trans(int pos) const {
	if (pos < 0 || pos >= _cards)
		return 0;
	else
		return _trans.at(pos + 1);
}
int MTransCard::pos(int p) const {
	if (p < 0 || p >= _cards)
		return 0;
	else
		return _pos.at(p + 1);
}
bool MTransCard::open() const {
	return _open;
}
bool MTransCard::tojudge() const {
	return _toJudge;
}
bool MTransCard::transpush(const sgs::DataType::Card * c) {
	if (c == 0)
		return false;
	else if (_trans.push(c)) {
		_cards++;
		return true;
	} else
		return false;
}
bool MTransCard::transpush(int fp) {
	switch (_frompos) {
	case PHAND:
		if (fp < 0 || fp >= _from->handnum())
			return false;
		else {
			_pos.push(fp);
			_trans.push(_from->hand(fp));
			_cards++;
			return true;
		}
		break;
	case PEQUIP:
		switch (fp) {
		case 0:
			_pos.push(fp);
			_trans.push(_from->weapon());
			_cards++;
			return true;
		case 1:
			_pos.push(fp);
			_trans.push(_from->armor());
			_cards++;
			return true;
		case 2:
			_pos.push(fp);
			_trans.push(_from->atkhorse());
			_cards++;
			return true;
		case 3:
			_pos.push(fp);
			_trans.push(_from->dfdhorse());
			_cards++;
			return true;
		default:
			return false;
		}
		break;
	case PJUDGE:
		if (fp < 0 || fp >= _from->judgenum())
			return false;
		else {
			_pos.push(fp);
			_trans.push(_from->judge(fp));
			_cards++;
			return true;
		}
	default:
		return false;
	}
}
bool MTransCard::transpush(int fp, const Card * c) {
	if (c == 0)
		return false;
	else {
		_pos.push(fp);
		_trans.push(c);
		_cards++;
		return true;
	}
}
bool MTransCard::transpop(int pos) {
	if (pos < 0 || pos >= _trans.size())
		return false;
	else if (_trans.pop(pos + 1)) {
		_cards--;
		if (_fromtype == PLAYER)
			_pos.pop(pos + 1);
		//_frompos.pop(pos+1);
		//_topos.pop(pos+1);
		return true;
	} else
		return false;
}

MSwitchPhase::MSwitchPhase(sgs::DataType::Player *f,
		sgs::ConstData::PlayerPhase b, sgs::ConstData::PlayerPhase a) :
		Message(SWITCHPHASE), _from(f), _before(b), _after(a) {
}
Player * MSwitchPhase::from() const {
	return _from;
}
PlayerPhase MSwitchPhase::before() const {
	return _before;
}
PlayerPhase MSwitchPhase::after() const {
	return _after;
}
MSwitchPhase::~MSwitchPhase() {
}
;

MHurt::MHurt(Player* f, Player* t, int h) :
		Message(HURT), _from(f), _to(t), _hurt(h) {
}
MHurt::~MHurt() {
}
Player* MHurt::from() const {
	return _from;
}
Player* MHurt::to() const {
	return _to;
}
int MHurt::hurt() const {
	return _hurt;
}

MJudge::MJudge(Player * f, const Card * card, const Card * result, bool e) :
		Message(JUDGE), _from(f), _card(card), _result(result), _effect(e), _skill(
				hkNone), _cardJudge(true) {
}
MJudge::MJudge(Player * f, HeroSkill k, const Card * result, bool e) :
		Message(JUDGE), _from(f), _card(0), _result(result), _effect(e), _skill(
				k), _cardJudge(false) {
}
MJudge::~MJudge() {
}
Player* MJudge::from() const {
	return _from;
}
const Card* MJudge::card() const {
	return _card;
}
const Card* MJudge::result() const {
	return _result;
}
bool MJudge::effect() const {
	return _effect;
}
bool MJudge::cardJudge() const {
	return _cardJudge;
}
HeroSkill MJudge::skill() const {
	return _skill;
}

MDying::MDying(Player * from, Player * murderer, int neg) :
		Message(DYING), _from(from), _murderer(murderer), _neg(neg) {
}
MDying::~MDying() {
}
Player * MDying::from() const {
	return _from;
}
Player * MDying::murderer() const {
	return _murderer;
}
int MDying::neg() const {
	return _neg;
}

MKill::MKill(Player * f, Player * t) :
		Message(KILL), _from(f), _die(t) {
}
MKill::~MKill() {
}
Player * MKill::from() const {
	return _from;
}
Player * MKill::to() const {
	return _die;
}

MRenDe::MRenDe(Player * from, Player * to) :
		MSkill(from, RENDE), _to(to), _cards(0) {
}
MRenDe::~MRenDe() {
}
const Card * MRenDe::card(int pos) const {
	return _card[pos].second;
}
int MRenDe::pos(int p) const {
	return _card[p].first;
}
Player * MRenDe::to() const {
	return _to;
}

int MRenDe::cards() const {
	return _cards;
}

void MRenDe::transpush(int pos) {
	_card.push_back(
			std::pair<int, const sgs::DataType::Card *>(pos, _from->hand(pos)));
	_cards++;
}

MJiJiang::MJiJiang(Player * from, Player * to) :
		MSkill(from, JIJIANG), _targets(0) {
	if (to != 0) {
		_to.push(to);
		_targets++;
	}
}

MJiJiang::~MJiJiang() {
	_to.clear();
}

int MJiJiang::targets() const {
	return _targets;
}

void MJiJiang::addto(Player * to) {
	if (to != 0) {
		_to.push(to);
		_targets++;
	}
}

void MJiJiang::popto(int i) {
	if (i < 0 || i >= _targets)
		return;
	else {
		_to.pop(i + 1);
		_targets--;
	}
}

Player * MJiJiang::to(int pos) const {
	return _to.at(pos + 1);
}

MLiJian::MLiJian(Player * from, sgs::ConstData::PlayerRegionType prt, int pos,
		Player * first, Player * second) :
		MSkill(from, LIJIAN), _toFirst(first), _toSecond(second) {
	_pos = std::pair<PlayerRegionType, int>(prt, pos);
	_card = from->visitCard(_pos);
}

MLiJian::~MLiJian() {
}

Player * MLiJian::first() const {
	return _toFirst;
}

Player * MLiJian::second() const {
	return _toSecond;
}

std::pair<PlayerRegionType, int> MLiJian::pos() const {
	return _pos;
}

const Card * MLiJian::card() const {
	return _card;
}

MTuXi::MTuXi(Player * from, Player * target1, int pos1, Player * target2,
		int pos2) :
		MSkill(from, TUXI), _targets(0) {
	if (target1 != 0) {
		_pos[0] = std::pair<Player *, int>(target1, pos1);
		_card[0] = target1->hand(pos1);
		_targets++;
	}
	if (target2 != 0) {
		_pos[1] = std::pair<Player *, int>(target2, pos2);
		_card[1] = target2->hand(pos2);
		_targets++;
	}
}

MTuXi::~MTuXi() {
}

std::pair<Player *, int> MTuXi::pos(int p) const {
	return _pos[p];
}

const Card * MTuXi::card(int p) const {
	return _card[p];
}

int MTuXi::targets() const {
	return _targets;
}

MYiJi::MYiJi(Player * from, Player * target1, const Card * card1,
		Player * target2, const Card * card2) :
		MSkill(from, YIJI) {
	_trans[0] = std::pair<Player *, const Card *>(target1, card1);
	_trans[1] = std::pair<Player *, const Card *>(target2, card2);
}

MYiJi::~MYiJi() {
}

std::pair<Player *, const Card *> MYiJi::trans(int pos) const {
	return _trans[pos];
}

MZhiHeng::MZhiHeng(Player * from) :
		MSkill(from, ZHIHENG), _cards(0) {
}

MZhiHeng::~MZhiHeng() {
}

void MZhiHeng::transpush(PlayerRegionType prt, int pos) {
	_pos.push_back(std::pair<PlayerRegionType, int>(prt, pos));
	_card.push_back(
			from()->visitCard(std::pair<PlayerRegionType, int>(prt, pos)));
	_cards++;
}

std::pair<PlayerRegionType, int> MZhiHeng::pos(int p) const {
	return _pos[p];
}

const Card * MZhiHeng::card(int p) const {
	return _card[p];
}

int MZhiHeng::cards() const {
	return _cards;
}

MFanJian::MFanJian(Player * from, Player * to) :
		MSkill(from, FANJIAN), _to(to) {
}

MFanJian::~MFanJian() {
}

Player * MFanJian::to() const {
	return _to;
}

MJieYin::MJieYin(Player * from, Player * to, int pos1, int pos2) :
		MSkill(from, JIEYIN), _to(to) {
	_pos[0] = pos1;
	_card[0] = from->hand(pos1);
	_pos[1] = pos2;
	_card[1] = from->hand(pos2);
}
MJieYin::~MJieYin() {
}
Player * MJieYin::to() const {
	return _to;
}
int MJieYin::pos(int i) const {
	return _pos[i];
}
const Card * MJieYin::card(int i) const {
	return _card[i];
}

MGuoSe::MGuoSe(Player * from, PlayerRegionType prt, int pos, Player * to) :
		MSkill(from, GUOSE), _to(to) {
	_pos = std::pair<PlayerRegionType, int>(prt, pos);
	_card = from->visitCard(_pos);
}
MGuoSe::~MGuoSe() {
}
Player * MGuoSe::to() const {
	return _to;
}
std::pair<sgs::ConstData::PlayerRegionType, int> MGuoSe::pos() const {
	return _pos;
}
const sgs::DataType::Card * MGuoSe::card() const {
	return _card;
}

MLiuLi::MLiuLi(Player * from, PlayerRegionType prt, int pos, Player * to) :
		MSkill(from, LIULI), _to(to) {
	_pos = std::pair<PlayerRegionType, int>(prt, pos);
	_card = from->visitCard(_pos);
}
MLiuLi::~MLiuLi() {
}
Player * MLiuLi::to() const {
	return _to;
}
std::pair<sgs::ConstData::PlayerRegionType, int> MLiuLi::pos() const {
	return _pos;
}
const sgs::DataType::Card * MLiuLi::card() const {
	return _card;
}
