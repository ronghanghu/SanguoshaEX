/*
 //最后编辑时间：2012-06-28
 //编辑者：李昂
 */
#include "sgsdata_manager.h"
#include "sgsdata_player.h"
#include "sgsdata_extern.h"
#include "sgsdata_heroes.h"
#include "sgs_Interface.h"
#include <cstdlib>
using namespace sgs;
using namespace DataType;
using namespace ConstData;
void shuffleHero(std::vector<sgs::ConstData::HeroType>& heroVec);

Manager::Manager() :
		players(0), N(0) {
}

void Manager::clearplayer() {

	/*Hu Ronghang has revised these code*/
	if (players) {
		Player * firstPlayer = players;
		do {
			Player * del = players;
			players = players->_next;
			delete del;
		} while (players != firstPlayer);
	}
	/* previous code*/
	//	while (players != 0) {
	//		Player * del = players;
	//		players = players->_next;
	//		delete del;
	//	}
	N = 0;
}
Manager::~Manager() {
	/*Hu Ronghang has revised these code*/

	// remove this destructor, move all the destruction work into platfrom::end();
	// consider use std::list instead of your list
	/* previous code*/
	//clearplayer();
}

Player * Manager::create(int n) {
	if (n < 2 || n > 8)
		return 0;
	N = n;

	/*Revised by Hu Ronghang. The order is changed.*/
	PlayerRole r[8] = { ZHU, FAN, NEI, ZHONG, FAN, FAN, ZHONG, FAN };

	/* previous code*/
	/*PlayerRole r[8] = { ZHU, FAN, ZHONG, NEI, FAN, FAN, ZHONG, FAN };*/

	PlayerRole s[8] = { };
	Player * begin = 0;
	for (int i = 0; i < n; i++) {
		int p = rand() % (n - i);
		s[i] = r[p];
		for (int j = p; j < 7 - i; j++)
			r[j] = r[j + 1];
	}

	players = new Player(0, s[0]);
	/*Use this function to create AI: Interface::createInterface(int playerseat, sgs::ConstData::HeroType heroType = sgs::ConstData::SUJIANG)
	 The AI will be deleted automatically at the end of the game, so you don't need to delete it yourself;*/
	/*Revised by Huronghang*/

	/*Revised by Huronghang: even if new fails, it WILL NOT return 0*/
	/*if (players == 0)
	 return 0;*/

	if (s[0] == ZHU)
		begin = players;
	Player * creator = players;
	for (int i = 1; i < n; i++) {
		creator->_next = new Player(i, s[i]);

		/*Revised by Huronghang on Jun30: PLEASE DO NOT check operator new! Esven if new fails, it WILL NOT return 0. Instread, it throws std::bad_alloc*/
		/*if (creator->_next == 0) {
		 clearplayer();
		 return 0;
		 }*/
		if (s[i] == ZHU)
			begin = creator->_next;

		creator = creator->_next;
	}
	creator->_next = players;
	for (creator = players->_next; creator != players; creator = creator->_next)
		creator->_next->_prev = creator;
	players->_next->_prev = players;

	using namespace sgs::ConstData;
	std::vector<sgs::ConstData::HeroType> heroes;
	heroes.push_back(XIAHOUDUN);
	heroes.push_back(XUCHU);
	heroes.push_back(ZHENJI);
	heroes.push_back(GUOJIA);
	heroes.push_back(ZHANGLIAO);
	heroes.push_back(SIMAYI);

	heroes.push_back(GUANYU);
	heroes.push_back(ZHANGFEI);
	heroes.push_back(ZHAOYUN);
	heroes.push_back(MACHAO);
	heroes.push_back(LAOZHUGE);
	heroes.push_back(HUANGYUEYING);

	heroes.push_back(HUANGGAI);
	heroes.push_back(GANNING);
	heroes.push_back(LVMENG);
	heroes.push_back(DAQIAO);
	heroes.push_back(LUXUN);
	heroes.push_back(SUNSHANGXIANG);
	heroes.push_back(ZHOUYU);

	shuffleHero(heroes);

	heroes.push_back(CAOCAO);
	heroes.push_back(SUNQUAN);
	heroes.push_back(LIUBEI);

	begin->choosehero(heroes);
	shuffleHero(heroes);

	begin->setinput(Interface::createInterface(begin->seat(), begin->type()));
	HeroType hero = begin->type();

	/*Revised by Huronghang on Jun30: Why call pop_back()?*/
	/*your choosehero() uses components from FRONT, so pop_back() will not change anything*/
	/*Note heroes[0] is the front*/
	/*FURTHER: your choosehero() needs at least 3 components in the vector, but only 2 are left*/
	/*for (int i = 0; i < 3; i++)
	 heroes.pop_back();*/

	for (creator = begin->_next; creator != begin; creator = creator->_next) {
		creator->choosehero(heroes, hero);
		creator->setinput(
				Interface::createInterface(creator->seat(), creator->type()));
	}
	return begin;
}

int Manager::playernum() const {
	return N;
}

void shuffleHero(std::vector<sgs::ConstData::HeroType>& heroVec) {
	int size = heroVec.size();
	sgs::ConstData::HeroType temp;
	for (int i = size - 1; i > 0; --i) {
		int random = rand() % (i + 1);
		temp = heroVec.at(i);
		heroVec.at(i) = heroVec.at(random);
		heroVec.at(random) = temp;
	}
}
