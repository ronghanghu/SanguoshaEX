/*
 //最后编辑时间2012-06-28
 //编辑者：李昂
 */
#include "sgsdata_hero.h"
#include "sgsdata_heroes.h"
#include "sgsdata_msg.h"
#include "sgsdata_card.h"
#include "sgsdata_card_func.h"
#include "sgsdata_skill_func.h"
#include "sgsdata_extern.h"
#include "sgsdata_history.h"
#include "sgsdata_platform.h"
#include "sgs_Interface.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"

using namespace sgs::ConstData;
using namespace sgs::Derive;
using namespace sgs::DataType;

HSuJiang::HSuJiang() :
		Hero(4, SUJIANG, MALE, QUN) {
}

HSuJiang::~HSuJiang() {
}

HNvSuJiang::HNvSuJiang() :
		Hero(4, NVSUJIANG, FEMALE, QUN) {
}

HNvSuJiang::~HNvSuJiang() {
}

HZhangFei::HZhangFei() :
		Hero(4, ZHANGFEI, MALE, SHU, PAOXIAO) {
}

HZhangFei::~HZhangFei() {
}

Message * HZhangFei::heromain(Player * player) {
	printDebug("HZhangFei::main: start");
	Message * m = player->input()->useCardResponse();
	if (m == 0) {
		m = new MSwitchPhase(player, MAIN, ABANDONCARD);
		player->setphase(ABANDONCARD);
	} else {
		switch (m->type()) {
		case HITCARD: {
			MCard* message = static_cast<MCard*>(m);
			switch (message->pos().first) {
			case PHAND:
				message->from()->popCard(
						std::pair<PlayerRegionType, int>(PHAND,
								message->pos().second));
				break;
			default:
				break;
			}
			if (message->card()->mask() == SHA) {
				if (player->status() & SkillOneUsed) { //对于张飞来说，SkillOneUsed意思是开始触发咆哮效果
					MSkill * paoxiao = new MSkill(player, PAOXIAO);
					ExternData::sgsout << paoxiao;
					ExternData::history.push(paoxiao);
				} else
					player->setstatus() |= SkillOneUsed;
			}
		}
			break;
		case USECARD: {
			MCard* temp = static_cast<MCard*>(m);
			MZhangBa * message = new MZhangBa(temp->from(), temp->to());
			delete temp;
			message = func::pczhangba(message);
			printDebug(
					"HZhangFei::main: message: "
							+ sgsui::messageInterpret(message));
			m = message;
			if (m != 0) {
				if (player->status() & SkillOneUsed) { //对于张飞来说，SkillOneUsed意思是开始触发咆哮效果
					MSkill * paoxiao = new MSkill(player, PAOXIAO);
					ExternData::sgsout << paoxiao;
					ExternData::history.push(paoxiao);
				} else
					player->setstatus() |= SkillOneUsed;
			}
		}
			break;
		default:
			m = 0;
			break;
		}
	}
	printDebug("HZhangFei::main: over");
	return m;
}

HLvMeng::HLvMeng() :
		Hero(4, LVMENG, MALE, WU, KEJI) {
}

HLvMeng::~HLvMeng() {
}

Message * HLvMeng::get(Player * player) {
	static bool got = false;
	Message * m = 0;
	if (!got) {
		MTransCard* t = new MTransCard(POOLTOP, PLAYER,
				(player->seat() == 0) ? true : false, 0, prtNone, player);
		for (int i = 0; i < 2; i++) {
			const Card * temp = ExternData::platform.get();
			t->transpush(temp);
		}
		m = t;
		got = true;
	} else if (player->status() & LE) {
		if (player->input()->useSkillOrNot(KEJI)) {
			MSkill * keji = new MSkill(player, KEJI);
			ExternData::sgsout<<keji;
			ExternData::history.push(keji);

			m = new MSwitchPhase(player, GETCARD, END);
			player->setphase(END);
		} else {
			m = new MSwitchPhase(player, GETCARD, ABANDONCARD);
			player->setphase(ABANDONCARD);
		}
		player->setstatus() = player->setstatus() & ~LE;
		got = false;
	} else {
		m = new MSwitchPhase(player, GETCARD, MAIN);
		player->setphase(MAIN);
		got = false;
	}
	return m;
}

Message * HLvMeng::heromain(Player * player) {
	printDebug("HLvMeng::main: start");
	Message * m = player->input()->useCardResponse();
	if (m == 0) {
		if (!(player->status() & ATTACKED)) {
			bool useKeJi = player->input()->useSkillOrNot(KEJI);
			if (useKeJi) {
				MSkill * keji = new MSkill(player, KEJI);
				ExternData::sgsout << keji;
				ExternData::history.push(keji);
				m = new MSwitchPhase(player, MAIN, END);
				player->setphase(END);
				printDebug("HLvMeng::main: over");
				return m;
			}
		}
		m = new MSwitchPhase(player, MAIN, ABANDONCARD);
		player->setphase(ABANDONCARD);
	} else {
		switch (m->type()) {
		case HITCARD: {
			MCard* message = static_cast<MCard*>(m);
			switch (message->pos().first) {
			case PHAND:
				message->from()->popCard(
						std::pair<PlayerRegionType, int>(PHAND,
								message->pos().second));
				break;
			default:
				break;
			}
		}
			break;
		case USECARD: {
			MCard* temp = static_cast<MCard*>(m);
			MZhangBa * message = new MZhangBa(temp->from(), temp->to());
			delete temp;
			message = func::pczhangba(message);
			printDebug(
					"HLvMeng::main: message: "
							+ sgsui::messageInterpret(message));
			m = message;
		}
			break;
		default:
			m = 0;
			break;
		}
	}
	printDebug("HLvMeng::main: over");
	return m;
}

HMaChao::HMaChao() :
		Hero(4, MACHAO, MALE, SHU, MASHU, TIEQI) {
}

HMaChao::~HMaChao() {
}

HGuanYu::HGuanYu() :
		Hero(4, GUANYU, MALE, SHU, WUSHENG) {
}

HGuanYu::~HGuanYu() {
}

HXiaHouDun::HXiaHouDun() :
		Hero(4, XIAHOUDUN, MALE, WEI, GANGLIE) {
}

HXiaHouDun::~HXiaHouDun() {
}

HXuChu::HXuChu() :
		Hero(4, XUCHU, MALE, WEI, LUOYI) {
}

HXuChu::~HXuChu() {
}

Message * HXuChu::get(Player * player) {
	static bool got = false;
	Message * m = 0;
	if (!got) {
		if (player->input()->useSkillOrNot(LUOYI)) {
			MSkill * luoyi = new MSkill(player, LUOYI);
			ExternData::sgsout << luoyi;
			ExternData::history.push(luoyi);
			MTransCard * t = new MTransCard(POOLTOP, PLAYER,
					(player->seat() == 0) ? true : false, 0, prtNone, player);
			const Card * temp = ExternData::platform.get();
			t->transpush(temp);
			m = t;
			player->setstatus() |= SkillOneUsed;
		} else {
			MTransCard* t = new MTransCard(POOLTOP, PLAYER,
					(player->seat() == 0) ? true : false, 0, prtNone, player);
			for (int i = 0; i < 2; i++) {
				const Card * temp = ExternData::platform.get();
				t->transpush(temp);
				m = t;
			}
		}
		got = true;
	} else if (player->status() & LE) {
		m = new MSwitchPhase(player, GETCARD, ABANDONCARD);
		player->setphase(ABANDONCARD);
		player->setstatus() = player->setstatus() & ~LE;
		got = false;
	} else {
		m = new MSwitchPhase(player, GETCARD, MAIN);
		player->setphase(MAIN);
		got = false;
	}
	return m;
}

HZhenJi::HZhenJi() :
		Hero(3, ZHENJI, FEMALE, WEI, QINGGUO, LUOSHEN) {
}

HZhenJi::~HZhenJi() {
}

Message * HZhenJi::start(Player * player) {
	bool LuoShenFailed = false;
	while (!LuoShenFailed && player->input()->useSkillOrNot(LUOSHEN)) {
		MSkill * luoshen = new MSkill(player, LUOSHEN);
		ExternData::sgsout << luoshen;
		ExternData::history.push(luoshen);
		const Card * judge = ExternData::platform.getJudge();
		MJudge * judgeResult = 0;
		if (judge->color() == SPADE || judge->color() == CLUB) {
			judgeResult = new MJudge(player, LUOSHEN, judge, true);
		} else {
			judgeResult = new MJudge(player, LUOSHEN, judge, false);
		}
		judgeResult = static_cast<MJudge *>(func::pcguicai(judgeResult));
		ExternData::sgsout << judgeResult;
		ExternData::history.push(judgeResult);
		if (judgeResult->effect()) {
			MTransCard * trans = new MTransCard(POOLTOP, PLAYER, true, 0,
					prtNone, player);
			trans->transpush(judge);
			ExternData::platform.analyze(trans);
		} else {
			LuoShenFailed = true;
			ExternData::platform.abandon(judge);
		}
	}
	Message * m = new MSwitchPhase(player, START, JUDGEMENT);
	player->setphase(JUDGEMENT);
	return m;
}

HLaoZhuGe::HLaoZhuGe() :
		Hero(3, LAOZHUGE, MALE, SHU, GUANXING, KONGCHENG) {
}

HLaoZhuGe::~HLaoZhuGe() {
}

Message * HLaoZhuGe::start(Player * player) {
	if (player->input()->useSkillOrNot(GUANXING)) {
		MSkill * guanxing = new MSkill(player, GUANXING);
		ExternData::sgsout << guanxing;
		ExternData::history.push(guanxing);
		int playerAlive = 1;
		for (Player * temp = player->after(); temp != player; temp =
				temp->after())
			playerAlive++;
		std::vector<const Card *> top;
		std::vector<const Card *> bottom;
		for (int i = 0; i < playerAlive && i < 5; i++)
			top.push_back(ExternData::platform.get());
		printDebug("HLaoZhuGe::start: about to choose");
		player->input()->chooseGuanxing(top, bottom);
		printDebug("HLaoZhuGe::start: choose over");
		for (unsigned i = 0, topsize = top.size(); i < topsize; i++)
			ExternData::platform.pooltop(top[topsize - 1 - i]);
		for (unsigned i = 0, buttomsize = bottom.size(); i < buttomsize; i++)
			ExternData::platform.poolbottom(bottom[i]);
	}
	Message * m = new MSwitchPhase(player, START, JUDGEMENT);
	player->setphase(JUDGEMENT);
	return m;
}

HZhaoYun::HZhaoYun() :
		Hero(4, ZHAOYUN, MALE, SHU, LONGDAN) {
}

HZhaoYun::~HZhaoYun() {
}

HGanNing::HGanNing() :
		Hero(4, GANNING, MALE, WU, QIXI) {
}

HGanNing::~HGanNing() {
}

HSiMaYi::HSiMaYi() :
		Hero(3, SIMAYI, MALE, WEI, FANKUI, GUICAI) {
}

HSiMaYi::~HSiMaYi() {
}

HHuangGai::HHuangGai() :
		Hero(4, HUANGGAI, MALE, WU, KUROU) {
}

HHuangGai::~HHuangGai() {
}

HHuaTuo::HHuaTuo() :
		Hero(3, HUATUO, MALE, QUN, JIJIU, QINGNANG) {
}

HHuaTuo::~HHuaTuo() {
}

HLiuBei::HLiuBei() :
		Hero(4, LIUBEI, MALE, SHU, RENDE, JIJIANG) {
}

HLiuBei::~HLiuBei() {

}

HCaoCao::HCaoCao() :
		Hero(4, CAOCAO, MALE, WEI, JIANXIONG, HUJIA) {
}

HCaoCao::~HCaoCao() {
}

HHuangYueYing::HHuangYueYing() :
		Hero(3, HUANGYUEYING, FEMALE, SHU, JIZHI, QICAI) {
}

HHuangYueYing::~HHuangYueYing() {
}

HDiaoChan::HDiaoChan() :
		Hero(3, DIAOCHAN, FEMALE, QUN, LIJIAN, BIYUE) {
}
HDiaoChan::~HDiaoChan() {
}

Message * HDiaoChan::end(Player * player) {
	if (player->input()->useSkillOrNot(BIYUE)) {
		MSkill * biyue = new MSkill(player, BIYUE);
		ExternData::sgsout << biyue;
		ExternData::history.push(biyue);

		MTransCard * trans = new MTransCard(POOLTOP, PLAYER,
				player->seat() == 0, 0, prtNone, player);
		trans->transpush(ExternData::platform.get());
		ExternData::platform.analyze(trans);
	}
	Message * m = new MSwitchPhase(player, END, OTHER);
	player->setstatus() &= ~ATTACKED;
	player->setstatus() &= ~SkillOneUsed;
	player->setstatus() &= ~SkillTwoUsed;
	player->clearShaCount(); // added by Hu Ronghang
	player->setphase(OTHER);
	return m;
}

HZhangLiao::HZhangLiao() :
		Hero(4, ZHANGLIAO, MALE, WEI, TUXI) {
}

HZhangLiao::~HZhangLiao() {
}

Message * HZhangLiao::get(Player * player) {
	static bool got = false;
	Message * m = 0;
	if (!got) {
		MTuXi * tuxi = dynamic_cast<MTuXi *>(player->input()->getTuxi());
		if (tuxi != 0) {
			ExternData::sgsout << tuxi;
			ExternData::history.push(tuxi);

			got = true;
			for (int i = 0; i < tuxi->targets(); i++) {
				MTransCard * trans = new MTransCard(PLAYER, PLAYER,
						player->seat() == 0, tuxi->pos(i).first, PHAND, player);
				trans->transpush(tuxi->pos(i).second);
				tuxi->pos(i).first->popCard(
						std::pair<PlayerRegionType, int>(PHAND,
								tuxi->pos(i).second));
				ExternData::platform.analyze(trans);
			}

			return 0;
		}

		MTransCard* t = new MTransCard(POOLTOP, PLAYER,
				(player->seat() == 0) ? true : false, 0, prtNone, player);
		for (int i = 0; i < 2; i++) {
			const Card * temp = ExternData::platform.get();
			t->transpush(temp);
		}
		m = t;
		got = true;
	} else if (player->status() & LE) {
		m = new MSwitchPhase(player, GETCARD, ABANDONCARD);
		player->setphase(ABANDONCARD);
		player->setstatus() = player->setstatus() & ~LE;
		got = false;
	} else {
		m = new MSwitchPhase(player, GETCARD, MAIN);
		player->setphase(MAIN);
		got = false;
	}
	return m;
}

HGuoJia::HGuoJia() :
		Hero(3, GUOJIA, MALE, WEI, TIANDU, YIJI) {
}

HGuoJia::~HGuoJia() {
}

HSunQuan::HSunQuan() :
		Hero(4, SUNQUAN, MALE, WU, ZHIHENG, JIUYUAN) {
}
HSunQuan::~HSunQuan() {
}

HLvBu::HLvBu() :
		Hero(4, LVBU, MALE, QUN, WUSHUANG) {
}
HLvBu::~HLvBu() {
}

HZhouYu::HZhouYu() :
		Hero(3, ZHOUYU, MALE, WU, FANJIAN, YINGZI) {
}
HZhouYu::~HZhouYu() {
}
Message* HZhouYu::get(Player * player) {
	static bool got = false;
	Message * m = 0;
	if (!got) {
		MTransCard* t = new MTransCard(POOLTOP, PLAYER,
				(player->seat() == 0) ? true : false, 0, prtNone, player);
		for (int i = 0; i < 2; i++) {
			const Card * temp = ExternData::platform.get();
			t->transpush(temp);
		}
		if (player->input()->useSkillOrNot(YINGZI)) {
			MSkill * yingzi = new MSkill(player, YINGZI);
			ExternData::sgsout << yingzi;
			ExternData::history.push(yingzi);

			t->transpush(ExternData::platform.get());
		}
		m = t;
		got = true;
	} else if (player->status() & LE) {
		m = new MSwitchPhase(player, GETCARD, ABANDONCARD);
		player->setphase(ABANDONCARD);
		player->setstatus() = player->setstatus() & ~LE;
		got = false;
	} else {
		m = new MSwitchPhase(player, GETCARD, MAIN);
		player->setphase(MAIN);
		got = false;
	}
	return m;
}

HSunShangXiang::HSunShangXiang() :
		Hero(3, SUNSHANGXIANG, FEMALE, WU, JIEYIN, XIAOJI) {
}

HSunShangXiang::~HSunShangXiang() {
}

HLuXun::HLuXun() :
		Hero(3, LUXUN, MALE, WU, QIANXUN, LIANYING) {
}

HLuXun::~HLuXun() {
}

HDaQiao::HDaQiao() :
		Hero(3, DAQIAO, FEMALE, WU, GUOSE, LIULI) {
}
HDaQiao::~HDaQiao() {
}
