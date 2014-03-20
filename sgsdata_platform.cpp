/*
 //最后编辑时间：2012-06-28
 //编辑者：李昂
 */
#include "sgsdata_platform.h"
#include "sgsdata_extern.h"
#include "sgsdata_gamedata.h"
#include "sgsdata_msg.h"
#include "sgsdata_player.h"
#include "sgsdata_card.h"
#include "sgsdata_card_func.h"
#include "sgsdata_history.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"
#include "sgs_Interface.h"

using namespace sgs;
using namespace ConstData;
using namespace DataType;
using namespace Derive;

void Platform::start(int N) {
	load();
	//int N = 8;
	_playernum = N;
	_player = create(N);

	ExternData::gamedata.initialize(this);
	/*ExternData::gamedata.normalize();*/

	ExternData::sgsout << 1;
	for (int i = 0; i < N; i++) {
		MTransCard * m = 0;
		if (_player->seat() == 0)
			m = new MTransCard(POOLTOP, PLAYER, true, 0, prtNone, _player);
		else
			m = new MTransCard(POOLTOP, PLAYER, false, 0, prtNone, _player);
		for (int j = 0; j < 4; j++) {
			const Card * c = get();
			m->transpush(c);
		}
		analyze(m);
		_player = _player->after();
	}
	//_player->setphase(START);
}
char Platform::run() {
	bool end = false;
	Message * r = 0;
	while (!end) {
		msgInsert(_player->round(*this));
		while (!msgEmpty()) {
			r = msgRead();
			msgPop();
			r = analyze(r);
			if (r != 0 && r->type() == FINALE) {
				end = true;
				break;
			} else
				msgInsert(r);
		}
	}
	MFinale * f = static_cast<MFinale *>(r);
	return f->finale();
}
void Platform::end() {
	printDebug("Platform::end: cleaning cards");
	clearcard();
	printDebug("Platform::end: cleaning players");
	clearplayer();
	printDebug("Platform::end: over");
	while (!_groove.empty()) {
		delete _groove.top();
		_groove.pop();
	}
}
Message * Platform::analyze(Message * m) {
	if (m == 0)
		return 0;
	Message * result = 0;
	switch (m->type()) {
	case HITCARD: {
		MCard* message = static_cast<MCard*>(m);
		bool jinnang = false;

		switch (message->card()->mask()) {
		case SHUNQIAN:
		case GUOCHAI:
		case JUEDOU:
		case JIEDAO:
		case NANMAN:
		case WANJIAN:
		case TAOYUAN:
		case WUGU:
		case WUZHONG:
			jinnang = true;
			break;
		default:
			break;
		}

		if (message->from()->type() == HUANGYUEYING && jinnang
				&& message->from()->input()->useSkillOrNot(JIZHI)) {
			MSkill * jizhi = new MSkill(message->from(), JIZHI);
			ExternData::sgsout << jizhi;
			ExternData::history.push(jizhi);
			MTransCard * trans = new MTransCard(POOLTOP, PLAYER,
					message->from()->seat() == 0, 0, prtNone, message->from());
			trans->transpush(get());
			analyze(trans);
		}
		result = message->card()->settle(message);
		return result;
	}
	case USECARD: {
		MCard* message = static_cast<MCard*>(m);
		switch (message->card()->mask()) {
		case SISHU:
			result = func::pcsishu(message);
			break;
		case SHANDIAN:
			result = func::pcshandian(message);
			break;
		case ZHANGBA:
			printDebug("Platform::analyze: In case USECARD/ZHANGBA");
			result = func::pcsha(static_cast<MZhangBa *>(message));
			break;
		default:
			result = 0;
		}
		return result;
	}
	case USESKILL: {
		MSkill * message = static_cast<MSkill *>(m);
		result = message->settle(message);
		return result;
	}
	case SWITCHPHASE: {
		MSwitchPhase* message = static_cast<MSwitchPhase*>(m);
		if (message->from()->phase() == OTHER) {
			_player = _player->after();
		}
		ExternData::history.push(m);
		ExternData::sgsout << m;
		return 0;
	}
	case TRANSCARD: {
		MTransCard* message = static_cast<MTransCard*>(m);
		switch (message->totype()) {
		case PLAYER: {
			if (message->tojudge()) {
				int n = message->cards();
				for (int i = 0; i < n; i++) {
					message->to()->setjudge().push(message->trans(i));
				}
			} else {
				int n = message->cards();
				for (int i = 0; i < n; i++) {
					message->to()->pushHand(message->trans(i));
				}
			}
		}
			break;
		case POOLTOP: {
			int n = message->cards();
			for (int i = 0; i < n; i++)
				ExternData::platform.pooltop(message->trans(n - 1 - i));
		}
			break;
		case POOLBOTTOM: {
			int n = message->cards();
			for (int i = 0; i < n; i++)
				ExternData::platform.poolbottom(message->trans(n - 1 - i));
		}
			break;
		case DUST: {
			int n = message->cards();
			for (int i = 0; i < n; i++)
				ExternData::platform.abandon(message->trans(i));
		}
			break;
		default:
			break;
		}
		ExternData::sgsout << m;
		ExternData::history.push(m);

		// sunshangxiang
		if (message->fromtype() == PLAYER
				&& message->from()->type() == SUNSHANGXIANG
				&& !(message->from()->status() & DEAD)
				&& message->frompos() == PEQUIP
				&& message->from()->input()->useSkillOrNot(XIAOJI)) {
			MSkill * xiaoji = new MSkill(message->from(), XIAOJI);
			ExternData::sgsout << xiaoji;
			ExternData::history.push(xiaoji);

			MTransCard * trans = new MTransCard(POOLTOP, PLAYER,
					message->from()->seat() == 0, 0, prtNone, message->from());
			for (int i = 0; i < 2; i++)
				trans->transpush(get());
			analyze(trans);
		}
		return 0;
	}
	case HURT: {
		printDebug("Platform::analyze: case HURT start");
		MHurt * h = static_cast<MHurt *>(m);
		ExternData::sgsout << m;
		ExternData::history.push(m);
		MDying * d = 0;
		while (h->to()->hp() <= 0) {
			printDebug("Platform::analyze: case HURT ask for Tao (self)");
			d = new MDying(h->to(), h->from(), 1 - h->to()->hp());
			ExternData::sgsout << d;
			ExternData::history.push(d);
			Message * rescue = d->from()->TaoOrNot(d);
			if (rescue != 0) {
				MCard * c = static_cast<MCard *>(rescue);
				Message * res = c->card()->settle(c);
				ExternData::sgsout << res;
				ExternData::history.push(res);
			} else
				break;
		}
		if (h->to()->hp() <= 0) {
			for (Player * temp = d->from()->after(); temp != d->from(); temp =
					temp->after()) {
				printDebug("Platform::analyze: case HURT in loop");
				if (h->to()->hp() <= 0) {
					printDebug(
							"Platform::analyze: case HURT ask for Tao (others)");
					Message * rescue = temp->TaoOrNot(d);
					while (rescue != 0) {
						MCard * c = static_cast<MCard *>(rescue);
						Message * res = c->card()->settle(c);
						ExternData::sgsout << res;
						ExternData::history.push(res);
						if (h->to()->hp() <= 0) {
							d = new MDying(h->to(), h->from(),
									1 - h->to()->hp());
							ExternData::sgsout << d;
							ExternData::history.push(d);
							rescue = temp->TaoOrNot(d);
						} else
							break;
					}
				} else
					break;
			}
		}
		printDebug("Platform::analyze: case HURT over");
		if (h->to()->hp() <= 0) {
			result = new MKill(d->murderer(), d->from());
			return result;
		} else {
			if (h->to()->type() == XIAHOUDUN && h->from() != 0
					&& !(h->from()->status() & DEAD) && h->hurt() > 0
					&& h->to()->input()->useSkillOrNot(GANGLIE, h->from())) {
				MGangLie * m = new MGangLie(h->to(), h->from());
				return m;
			} else if (h->to()->type() == SIMAYI && h->from() != 0
					&& !(h->from()->status() & DEAD) && h->hurt() > 0
					&& h->to()->input()->useSkillOrNot(FANKUI, h->from())) {
				MFanKui * m = new MFanKui(h->to(), h->from());
				return m;

			} else if (h->to()->type() == GUOJIA) {
				for (int i = 0; i < h->hurt(); i++) {
					if (h->to()->input()->useSkillOrNot(YIJI)) {
						MYiJi * yiji =
								dynamic_cast<MYiJi *>(h->to()->input()->getYiji(
										ExternData::platform.get(),
										ExternData::platform.get()));
						ExternData::sgsout << yiji;
						ExternData::history.push(yiji);

						for (int i = 0; i < 2; i++) {
							MTransCard * trans = new MTransCard(POOLTOP, PLAYER,
									yiji->from()->seat() == 0, 0, prtNone,
									yiji->trans(i).first);
							trans->transpush(yiji->trans(i).second);
							ExternData::platform.analyze(trans);
						}

					} else
						break;
				}
				return 0;
			} else
				return 0;
		}
	}
	case KILL: {
		printDebug("Platform::analyze: case KILL start");
		MKill * k = static_cast<MKill *>(m);
		ExternData::sgsout << m;
		ExternData::history.push(m);
		k->to()->setstatus() |= DEAD;
		if (_player == k->to())
			_player = k->to()->after();

		/*these code has been revised by Hu Ronghang, May 12*/
		char result = endOrNot();
		if (result != 0) {
			MFinale * f = new MFinale(result);
			return f;
		}

		// 被杀死的人弃掉所有的手牌和装备牌
		MTransCard * t = new MTransCard(PLAYER, DUST, true, k->to(), PHAND);
		while (k->to()->handnum()>0) {
			t->transpush(k->to()->handnum() - 1);
			k->to()->popCard(std::pair<PlayerRegionType,int>(PHAND,k->to()->handnum()-1));
		}
		if (t->cards()) {
			analyze(t);
		} else {
			delete t;
		}

		MTransCard * judge = new MTransCard(PLAYER, DUST, true, k->to(),
				PJUDGE);
		for (int i = 0; i < k->to()->judgenum(); ++i) {
			judge->transpush(i);
		}
		k->to()->setjudge().clear();
		if (judge->cards()) {
			analyze(judge);
		} else {
			delete judge;
		}

		t = new MTransCard(PLAYER, DUST, true, k->to(), PEQUIP);
		bool existEquip = 0;
		if (k->to()->weapon() != 0) {
			t->transpush(0);
			k->to()->setweapon(0);
			existEquip = true;
		}
		if (k->to()->armor()) {
			t->transpush(1);
			k->to()->setarmor(0);
			existEquip = true;
		}
		if (k->to()->atkhorse()) {
			t->transpush(2);
			k->to()->setatk(0);
			existEquip = true;
		}
		if (k->to()->dfdhorse()) {
			t->transpush(3);
			k->to()->setdfd(0);
			existEquip = true;
		}

		if (existEquip) {
			analyze(t);
		} else {
			delete t;
		}
		t = 0;

		// 别忘了还要弃装备和判定区的牌 TODO

		if (k->from() && !(k->from()->status() & DEAD)) {

			// 如果主公杀了忠臣，在内部发出消息t，然后返回主公弃牌的消息
			if (k->from() && k->from()->role() == ZHU
					&& k->to()->role() == ZHONG) {
				//			ExternData::sgsout << t;
				//			ExternData::history.push(t);

				printDebug(
						"Platform::analyze: case KILL: lord discards all hand and equip cards");
				Player * lord = k->from();

				MTransCard * lordDiscardAll = new MTransCard(PLAYER, DUST, true,
						lord, PHAND);
				while (lord->handnum() > 0) {
					lordDiscardAll->transpush(lord->handnum() - 1);
					lord->popCard(std::pair<PlayerRegionType,int>(PHAND,lord->handnum()-1));
				}
				if (lordDiscardAll->cards())
					analyze(lordDiscardAll);
				else
					delete lordDiscardAll;
				lordDiscardAll = new MTransCard(PLAYER, DUST, true, lord,
						PEQUIP);
				bool lordHasEquip = false;
				if (lord->weapon()) {
					lordDiscardAll->transpush(0);
					lordHasEquip = true;
					lord->setweapon(0);
				}
				if (lord->armor()) {
					lordDiscardAll->transpush(1);
					lordHasEquip = true;
					lord->setarmor(0);
				}
				if (lord->atkhorse()) {
					lordDiscardAll->transpush(2);
					lordHasEquip = true;
					lord->setatk(0);
				}
				if (lord->dfdhorse()) {
					lordDiscardAll->transpush(3);
					lordHasEquip = true;
					lord->setdfd(0);
				}
				if (lordHasEquip) {
					analyze(lordDiscardAll);
				} else {
					delete lordDiscardAll;
				}
				return 0;
			}

			// 如果杀了反贼，在内部发出消息t，然后返回凶手摸牌的消息
			if (k->from() && k->to()->role() == FAN) {
				printDebug(
						"Platform::analyze: case KILL: murderer gets 3 cards");
				Player * murderer = k->from();
				MTransCard * murdererGetCard = new MTransCard(POOLTOP, PLAYER,
						((murderer->seat() == 0) ? true : false), 0, prtNone,
						murderer);
				for (int i = 0; i < 3; i++) {
					const Card * temp = get();
					murdererGetCard->transpush(temp);
				}
				return murdererGetCard;
			}
			printDebug("Platform::analyze: case KILL start");
			return t;
		} else {
			return 0;
		}
		break;
	}
	case JUDGE: {
		ExternData::history.push(m);
		ExternData::sgsout << m;
		MJudge * temp = static_cast<MJudge *>(m);
		if (temp->from()->type() == GUOJIA
				&& temp->from()->input()->useSkillOrNot(TIANDU)) {
			MSkill * tiandu = new MSkill(temp->from(), TIANDU);
			ExternData::sgsout << tiandu;
			ExternData::history.push(tiandu);

			MTransCard* trans = new MTransCard(POOLTOP, PLAYER, true, 0,
					prtNone, temp->from());
			trans->transpush(temp->result());
			analyze(trans);
			return 0;
		} else {
			abandon(temp->result());
			return 0;
		}
	}

	default:
		delete m;
		return 0;
	}
}
char Platform::endOrNot() {

	/*the following code has been revised by Hu Ronghang, May 12*/

	int zhugongNum(0), zhongchenNum(0), fanzeiNum(0), neijianNum(0);
	char result = 0;
	for (int i = 0; i < _playernum; i++) {
		if (!(_player->find(i)->status() & DEAD)) {
			switch (_player->find(i)->role()) {
			case ZHU:
				zhugongNum++;
				break;
			case ZHONG:
				zhongchenNum++;
				break;
			case FAN:
				fanzeiNum++;
				break;
			case NEI:
				neijianNum++;
				break;
			default:
				break;
			}
		}
	}

	if (!(zhugongNum == 0 || (fanzeiNum + neijianNum) == 0)) {
		// indicating that game is not over
		return 0;
	}

	if (zhugongNum == 0) {
		if (zhongchenNum == 0 && fanzeiNum == 0) {

			// NEIJIAN wins, others lose
			for (int i = 0; i < _playernum; i++) {
				switch (_player->find(i)->role()) {
				case ZHU:
					/*DO NOTHING*/
					break;
				case ZHONG:
					/*DO NOTHING*/
					break;
				case FAN:
					/*DO NOTHING*/
					break;
				case NEI:
					result |= 1 << i;
					break;
				default:
					break;
				}
			}
			return result;
		} else {

			// FANZEI wins, others lose
			for (int i = 0; i < _playernum; i++) {
				switch (_player->find(i)->role()) {
				case ZHU:
					/*DO NOTHING*/
					break;
				case ZHONG:
					/*DO NOTHING*/
					break;
				case FAN:
					result |= 1 << i;
					break;
				case NEI:
					/*DO NOTHING*/
					break;
				default:
					break;
				}
			}
			return result;
		}
	}

	if ((fanzeiNum + neijianNum) == 0) {

		// ZHUGONG and ZHONGCHEN wins, others lose
		for (int i = 0; i < _playernum; i++) {
			switch (_player->find(i)->role()) {
			case ZHU:
				result |= 1 << i;
				break;
			case ZHONG:
				result |= 1 << i;
				break;
			case FAN:
				/*DO NOTHING*/
				break;
			case NEI:
				/*DO NOTHING*/
				break;
			default:
				break;
			}
		}
		return result;
	}

	return result;
}
void Platform::msgInsert(Message * m) {
	if (m != 0)
		_groove.push(m);
}
bool Platform::msgEmpty() {
	return _groove.empty();
}
Message * Platform::msgRead() {
	return _groove.top();
}
void Platform::msgPop() {
	_groove.pop();
}

const Card * Platform::getJudge() {
	//暂时不询问司马懿。
	return get();
}
