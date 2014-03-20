/*
//最后编辑时间2012-06-28
//编辑者：李昂
*/
#include "sgsdata_hero.h"
#include "sgs_Interface.h"
#include "sgsdata_extern.h"
#include "sgsdata_skill.h"
#include "sgsdata_gamedata.h"
#include "sgsdata_platform.h"
#include "sgsdata_player.h"
#include "sgsdata_card_func.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include <algorithm>
using namespace sgs;
using namespace ConstData;
using namespace DataType;
using namespace Derive;
using namespace ExternData;
 
Hero::Hero(int maxHP, HeroType type, HeroSex sex, HeroSide side, HeroSkill skill0, HeroSkill skill1, HeroSkill skill2, HeroSkill skill3):_maxHP(maxHP),_type(type),_sex(sex),_side(side)
{
	if ((_skill[0] = skill0).skill() != hkNone)
	{
		_skills = 1;
		if ((_skill[1] = skill1).skill() != hkNone)
		{
			_skills = 2;
			if ((_skill[2] = skill2).skill() != hkNone)
			{
				_skills=3;
				if ((_skill[3] = skill3).skill() != hkNone)
				{
					_skills = 4;
				}
			}
		}
	}
	else _skills = 0;
}
Hero::~Hero(){}
int Hero::maxHP() const {return _maxHP;}
HeroSex Hero::sex() const {return _sex;}
HeroSide Hero::side() const {return _side;}
Skill Hero::skill(int pos)
{
	if (pos<0 || pos>=_skills) return hkNone;
	else return _skill[pos];
}
int Hero::skillnum() const {return _skills;}
HeroType Hero::type() const {return _type;}
 
Message * Hero::start(Player * player){
	Message * m = new MSwitchPhase(player, START, JUDGEMENT);
	player->setphase(JUDGEMENT);
	return m;
}
Message * Hero::judge(Player * player) {
	if (player->judgenum() == 0) {
		Message * m = new MSwitchPhase(player, JUDGEMENT, GETCARD);
		player->setphase(GETCARD);
		return m;
	} else {
		MCard * m = new MCard(true, player, PJUDGE, 0, player);
		player->popCard(m->pos());
		return m;
	}
}
Message * Hero::get(Player * player) {
	static bool got = false;
	Message * m = 0;
	if (!got) {
		MTransCard* t = new MTransCard(POOLTOP, PLAYER,
				(player->seat() == 0) ? true : false, 0, prtNone, player);
		for (int i = 0; i < 2; i++) {
			const Card * temp = platform.get();
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

Message * Hero::heromain(Player * player) {
	printDebug("Hero::main: start");
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
				message->from()->popCard(std::pair<PlayerRegionType,int>(PHAND,message->pos().second ));
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
					"Hero::main: message: " + sgsui::messageInterpret(message));
			m = message;
		}
			break;
		case USESKILL:
			break;
		default:
			m = 0;
			break;
		}
	}
	printDebug("Hero::main: over");
	return m;
}

Message * Hero::abandon(Player * player){
    printDebug("Hero::abandon: start");
	Message * m = 0;
	static bool abandoned = false;
	if (abandoned || player->handnum() <= player->hp())
	{
		m = new MSwitchPhase(player, ABANDONCARD, END);
		player->setphase(END);
		abandoned = false;
	}
	else
	{
		MTransCard * t = new MTransCard(PLAYER,DUST,true,player,PHAND);
		int needs = player->handnum() - player->hp();
		std::vector<int> abandon = player->input()->discardCard(needs);

		std::sort(abandon.begin(), abandon.end());

		for (int i=needs-1; i>=0; i--)
		{
			t->transpush(abandon.back());
			player->popCard(std::pair<PlayerRegionType,int>(PHAND,abandon.back()));
			abandon.pop_back();
		}
		m = t;
		abandoned = true;
	}
    printDebug("Hero::abandon: over");
	return m;
}
Message * Hero::end(Player * player)
{
	Message * m = new MSwitchPhase(player, END, OTHER);
	player->setstatus() &=~ATTACKED;
	player->setstatus() &=~SkillOneUsed;
	player->setstatus() &=~SkillTwoUsed;
	player->clearShaCount(); // added by Hu Ronghang
	player->setphase(OTHER);
	return m;
}
