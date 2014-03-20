/*
 //最后修改时间：2012-07-1
 //编辑者：李昂
 //各个技能效果函数的定义。
 */

#include "sgsdata_skill.h"
#include "sgsdata_skill_func.h"
#include "sgsdata_msg.h"
#include "sgsdata_card.h"
#include "sgsdata_extern.h"
#include "sgsdata_history.h"
#include "sgsdata_player.h"
#include "sgs_Interface.h"
#include "sgsdata_platform.h"
#include "sgsui_output.h"

using namespace sgs;
using namespace ConstData;
using namespace DataType;
using namespace Derive;

Message * func::pcwusheng(Message *m) {
	MWuSheng * message = static_cast<MWuSheng *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	MCard * result = new MCard(false, message->from(), message->pos().first, message->pos().second);
	for (int i = 0; i < message->targets(); i++) {
		result->addto(message->to(message->targets() - 1 - i));
	}
	message->card()->setmask(SHA);
	message->from()->popCard(message->pos());
	return result;
}

Message * func::pcganglie(Message * m) {
	MGangLie * message = static_cast<MGangLie *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	const Card * judge = ExternData::platform.getJudge();
	MJudge * judgeResult = 0;
	if (judge->color() != HEART) {
		judgeResult = new MJudge(message->from(), GANGLIE, judge, true);
	} else {
		judgeResult = new MJudge(message->from(), GANGLIE, judge, false);
	}
	judgeResult = static_cast<MJudge *>(func::pcguicai(judgeResult));
	ExternData::sgsout << judgeResult;
	ExternData::history.push(judgeResult);
	ExternData::platform.abandon(judgeResult->result());
	if (judgeResult->effect()) {
		if (message->to()->handnum() >= 2
				&& message->to()->input()->yesOrNot(GANGLIE)) { //yesOrNot返回真时表示选择弃牌
			std::vector<int> discard = message->to()->input()->discardCard(2);

			std::sort(discard.begin(), discard.end());

			MTransCard * result = new MTransCard(PLAYER, DUST, true,
					message->to(), PHAND);
			result->transpush(discard[1]);
			message->to()->popCard(
					std::pair<PlayerRegionType, int>(PHAND, discard[1]));
			result->transpush(discard[0]);
			message->to()->popCard(
					std::pair<PlayerRegionType, int>(PHAND, discard[0]));
			return result;
		} else {
			message->to()->sethp()--;MHurt
			* result = new MHurt(message->from(), message->to(), 1);
			return result;
		}
	} else
		return 0;
}

Message * func::pcqingguo(Message * m) {
	MQingGuo * message = static_cast<MQingGuo *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	MCard * result = new MCard(false, message->from(), PHAND, message->pos());
	message->card()->setmask(SHAN);
	message->from()->popCard(
			std::pair<PlayerRegionType, int>(PHAND, message->pos()));
	return result;
}

Message * func::pclongdan(Message * m) {
	MLongDan * message = static_cast<MLongDan *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	MCard * result = new MCard(false, message->from(), PHAND, message->pos());
	for (int i = 0; i < message->targets(); i++) {
		result->addto(message->to(message->targets() - 1 - i));
	}
	switch (message->card()->type()) {
	case SHA:
		message->card()->setmask(SHAN);
		break;
	case SHAN:
		message->card()->setmask(SHA);
		break;
	default:
		break;
	}
	message->from()->popCard(
			std::pair<PlayerRegionType, int>(PHAND, message->pos()));
	return result;
}

Message * func::pcqixi(Message * m) {
	MQiXi * message = static_cast<MQiXi *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	MCard * result = new MCard(false, message->from(), message->pos().first,
			message->pos().second);
	result->addto(message->to());
	message->card()->setmask(GUOCHAI);
	message->from()->popCard(message->pos());
	return result;
}

Message * func::pcfankui(Message * m) {
	MFanKui * message = static_cast<MFanKui *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	std::vector < std::pair<PlayerRegionType, int> > choose =
			message->from()->input()->chooseCardResponse(message->to(), true,
					true, false, 1, FANKUI);
	MTransCard * result = new MTransCard(PLAYER, PLAYER,
			message->from()->seat() == 0, message->to(), choose[0].first,
			message->from());
	result->transpush(choose[0].second);
	message->to()->popCard(choose[0]);
	return result;
}

Message * func::pcguicai(Message * m) {
	MJudge * message = static_cast<MJudge *>(m);
	Player * simayi = 0;
	if (message->from()->type() == SIMAYI) {
		simayi = message->from();
	} else
		for (Player * temp = message->from()->after();
				temp != message->from(); temp = temp->after()) {
			if (temp->type() == SIMAYI) {
				simayi = temp;
				break;
			}
		}

	if (simayi && !(simayi->status() & DEAD) && simayi->handnum()
			&& simayi->input()->useSkillOrNot(GUICAI, message)) {

//播放动画
		MSkill * guicai = new MSkill(simayi, GUICAI);
		ExternData::sgsout << guicai;
		ExternData::history.push(guicai);

//确定改判牌
		std::vector < std::pair<PlayerRegionType, int> > choose =
				simayi->input()->chooseCardResponse(simayi, true, false, false,
						1, GUICAI);

//处理原判定情况
		ExternData::sgsout << message;
		ExternData::history.push(message);
		ExternData::platform.abandon(message->result());

//播放改判动画
		MTransCard * trans = new MTransCard(PLAYER, POOLTOP, true, simayi,
				PHAND);
		trans->transpush(choose[0].second);
		ExternData::sgsout << trans;
		delete trans;

//确定改判牌
		const Card * change = simayi->visitCard(choose[0]);
		simayi->popCard(choose[0]);

//修改判定结果
		if (message->cardJudge()) {
			switch (message->card()->mask()) {
			case SISHU:
				if (change->color() != HEART)
					message = new MJudge(message->from(), message->card(),
							change, true);
				else
					message = new MJudge(message->from(), message->card(),
							change, false);
				return message;
			case BAGUA:
				if (change->color() == HEART || change->color() == DIAMOND)
					message = new MJudge(message->from(), message->card(),
							change, true);
				else
					message = new MJudge(message->from(), message->card(),
							change, false);
				return message;
			case SHANDIAN:
				if (change->color() == SPADE && change->number() >= 2
						&& change->number() <= 9)
					message = new MJudge(message->from(), message->card(),
							change, true);
				else
					message = new MJudge(message->from(), message->card(),
							change, false);
				return message;
			}
		} else {
			switch (message->skill()) {
			case GANGLIE:
				if (change->color() != HEART)
					message = new MJudge(message->from(), message->skill(),
							change, true);
				else
					message = new MJudge(message->from(), message->skill(),
							change, false);
				return message;
			case LUOSHEN:
				if (change->color() == SPADE || change->color() == CLUB)
					message = new MJudge(message->from(), message->skill(),
							change, true);
				else
					message = new MJudge(message->from(), message->skill(),
							change, false);
				return message;
			case TIEQI:
				if (change->color() == HEART || change->color() == DIAMOND)
					message = new MJudge(message->from(), message->skill(),
							change, true);
				else
					message = new MJudge(message->from(), message->skill(),
							change, false);
				return message;
			}
		}
	} else
		return m;

	return 0;
}

Message * func::pckurou(Message * m) {
	MSkill * message = static_cast<MSkill *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	message->from()->sethp()--;Message
	* res = new MHurt(message->from(), message->from(), 1);
	while (res != 0) {
		if (res->type() == KILL)
			return res;
		res = ExternData::platform.analyze(res);
	}
	MTransCard * trans = new MTransCard(POOLTOP, PLAYER,
			message->from()->seat() == 0, 0, prtNone, message->from());
	trans->transpush(ExternData::platform.get());
	trans->transpush(ExternData::platform.get());
	return trans;
}

Message * func::pcqingnang(Message * m) {
	MQingNang * message = static_cast<MQingNang *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	message->from()->setstatus() |= SkillOneUsed;

	MTransCard * trans = new MTransCard(PLAYER, DUST, true, message->from(),
			PHAND);
	trans->transpush(message->pos());
	message->from()->popCard(
			std::pair<PlayerRegionType, int>(PHAND, message->pos()));
	ExternData::platform.analyze(trans);

	message->to()->sethp()++;MHurt
	* hurt = new MHurt(message->from(), message->to(), -1);
	return hurt;
}

Message * func::pcjijiu(Message * m) {
	MJiJiu * message = static_cast<MJiJiu *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	MCard * result = new MCard(false, message->from(), message->pos().first,
			message->pos().second);
	message->card()->setmask(TAO);
	message->from()->popCard(message->pos());
	return result;
}

Message * func::pcrende(Message * m) {
	MRenDe * message = static_cast<MRenDe *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);

	if (((message->cards() == 1 && (message->from()->status() & SkillTwoUsed))
			|| message->cards() >= 2)
			&& !(message->from()->status() & SkillOneUsed)) {
		message->from()->setstatus() |= SkillOneUsed;
		if (message->from()->hp() < message->from()->maxHP()) {
			printDebug(
					"func::pcrende: add HP, player:"
							+ QString::number(message->from()->seat())
							+ " current HP = "
							+ QString::number(message->from()->hp())
							+ " maxHP = "
							+ QString::number(message->from()->maxHP()));
			message->from()->sethp()++;MHurt
			* hurt = new MHurt(message->from(), message->from(), -1);
			ExternData::platform.analyze(hurt);
		}
	} else if (message->cards() == 1
			&& !(message->from()->status() & SkillTwoUsed)
			&& !(message->from()->status() & SkillOneUsed))
		message->from()->setstatus() |= SkillTwoUsed;

	MTransCard * trans = new MTransCard(PLAYER, PLAYER,
			message->from()->seat() == 0 || message->to()->seat() == 0,
			message->from(), PHAND, message->to());
	for (int i = 0; i < message->cards(); i++) {
		trans->transpush(message->pos(i));
		message->from()->popCard(
				std::pair<PlayerRegionType, int>(PHAND, message->pos(i)));
	}
	return trans;
}

Message * func::pcjijiang(Message * m) {
	MJiJiang * message = static_cast<MJiJiang *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	Message * result = 0;

	for (Player * temp = message->from()->after(); temp != message->from();
			temp = temp->after()) {
		if (temp->side() == SHU && temp->input()->yesOrNot(JIJIANG)) {
			result = temp->input()->shaOrNot(message->from(), JIJIANG);
			if (result == 0)
				continue;
			else {
				MCard * c = 0;
				switch (result->type()) {
				case USESKILL:
					c =
							static_cast<MCard *>(static_cast<MSkill *>(result)->settle(
									result));
					break;
				case HITCARD:
					c = static_cast<MCard *>(result);
					c->from()->popCard(c->pos());
					break;
				}

				MTransCard * trans = new MTransCard(PLAYER, PLAYER, true,
						c->from(), PHAND, message->from());
				trans->transpush(c->pos().second, c->card());
				ExternData::platform.analyze(trans);

				delete c;
				c = new MCard(false, message->from(), PHAND, 0);
				message->from()->popCard(
						std::pair<PlayerRegionType, int>(PHAND, 0));
				for (int i = 0; i < message->targets(); i++)
					c->addto(message->to(message->targets() - 1 - i));
				return c;
			}
		}
	}
	return 0;
}

Message * func::pchujia(Message * m) {
	MSkill * message = static_cast<MSkill *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	Message * result = 0;

	for (Player * temp = message->from()->after(); temp != message->from();
			temp = temp->after()) {
		if (temp->side() == WEI && temp->input()->yesOrNot(HUJIA)) {
			result = temp->input()->shanOrNot(message->from(), HUJIA);
			if (result == 0)
				continue;
			else {
				MCard * c = 0;
				switch (result->type()) {
				case USESKILL:
					c =
							static_cast<MCard *>(static_cast<MSkill *>(result)->settle(
									result));
					break;
				case HITCARD:
					c = static_cast<MCard *>(result);
					c->from()->popCard(c->pos());
					break;
				}

				MTransCard * trans = new MTransCard(PLAYER, PLAYER, true,
						c->from(), PHAND, message->from());
				trans->transpush(c->pos().second, c->card());
				ExternData::platform.analyze(trans);

				delete c;
				c = new MCard(false, message->from(), PHAND, 0);
				message->from()->popCard(
						std::pair<PlayerRegionType, int>(PHAND, 0));
				return c;
			}
		}
	}
	return 0;
}

Message * func::pclijian(Message * m) {
	MLiJian * message = static_cast<MLiJian *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	message->from()->setstatus() |= SkillOneUsed;

	MTransCard * trans = new MTransCard(PLAYER, DUST, true, message->from(),
			message->pos().first);
	trans->transpush(message->pos().second);
	ExternData::platform.analyze(trans);

	Player * inTurn = message->second();
	Player * hurtFrom = message->first();
	while (1) {
		bool checkLvbu = hurtFrom->type() == LVBU; //检查是否是吕布
		for (int i = 0; i < 1 + checkLvbu; i++) {
			if (i == 1) {
				MSkill* wushuang = new MSkill(hurtFrom, WUSHUANG);
				ExternData::sgsout << wushuang;
				ExternData::history.push(wushuang);
			}
			Message * shaornot = inTurn->ShaOrNot(message);
			if (shaornot == 0) {
				inTurn->sethp() --;Message
				* hurt = new MHurt(hurtFrom, inTurn, 1);
				return hurt;
			} else {
				switch (shaornot->type()) {
				case HITCARD:
					ExternData::sgsout << shaornot;
					ExternData::history.push(shaornot);
					ExternData::platform.abandon(
							static_cast<MCard *>(shaornot)->card());
					break;
				case USECARD: {
					MZhangBa * zhangba = static_cast<MZhangBa *>(shaornot);
					ExternData::sgsout << shaornot;
					ExternData::history.push(shaornot);
					ExternData::platform.abandon(zhangba->cost(0).first);
					ExternData::platform.abandon(zhangba->cost(1).first);
					break;
				}
					break;
				default:
					break;
				}
			}
		}
		Player * temp = inTurn;
		inTurn = hurtFrom;
		hurtFrom = temp;
	}
}

Message * func::pczhiheng(Message * m) {
	MZhiHeng * message = static_cast<MZhiHeng *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	message->from()->setstatus() |= SkillOneUsed;

	for (int i = 0; i < message->cards(); i++) {
		MTransCard * trans = new MTransCard(PLAYER, DUST, true, message->from(),
				message->pos(i).first);
		trans->transpush(message->pos(i).second);
		message->from()->popCard(message->pos(i));
		ExternData::platform.analyze(trans);
	}

	MTransCard * trans = new MTransCard(POOLTOP, PLAYER,
			message->from()->seat() == 0, 0, prtNone, message->from());
	for (int i = 0; i < message->cards(); i++)
		trans->transpush(ExternData::platform.get());
	return trans;
}

Message * func::pcfanjian(Message * m) {
	MFanJian * message = static_cast<MFanJian *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	message->from()->setstatus() |= SkillOneUsed;
	std::pair<CardColor, int> result = message->to()->input()->respondFanjian(
			message->from());
	const Card * choose = message->from()->hand(result.second);
	MTransCard * trans = new MTransCard(PLAYER, PLAYER, true, message->from(),
			PHAND, message->to());
	trans->transpush(result.second);
	message->from()->popCard(
			std::pair<PlayerRegionType, int>(PHAND, result.second));
	ExternData::platform.analyze(trans);

	if (choose->color() != result.first) {
		message->to()->sethp()--;MHurt
		* hurt = new MHurt(message->from(), message->to(), 1);
		return hurt;
	} else
		return 0;
}

Message * func::pcjieyin(Message * m) {
	MJieYin * message = static_cast<MJieYin *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);
	message->from()->setstatus() |= SkillOneUsed;

	MTransCard * trans = new MTransCard(PLAYER, DUST, true, message->from(),
			PHAND);
	for (int i = 0; i < 2; i++) {
		trans->transpush(message->pos(i));
		message->from()->popCard(
				std::pair<PlayerRegionType, int>(PHAND, message->pos(i)));
	}
	ExternData::platform.analyze(trans);

	message->to()->sethp()++;MHurt
	* recover = new MHurt(message->from(), message->to(), -1);
	ExternData::platform.analyze(recover);

	if (message->from()->hp() < message->from()->maxHP()) {
		message->from()->sethp()++;recover
		= new MHurt(message->from(), message->from(), -1);
		ExternData::platform.analyze(recover);
	}

	return 0;
}

Message * func::pcguose(Message * m) {
	MGuoSe * message = static_cast<MGuoSe *>(m);
	ExternData::sgsout << message;
	ExternData::history.push(message);

	MCard * result = new MCard(false, message->from(), message->pos().first,
			message->pos().second, message->to());
	message->card()->setmask(SISHU);
	message->from()->popCard(message->pos());
	return result;
}
