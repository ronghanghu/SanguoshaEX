/*
//最后修改时间：2012-06-28
//编辑者：李昂
*/
#include "sgsdata_gamedata.h"
#include "sgsdata_player.h"
#include "sgsdata_platform.h"
#include "sgsdata_extern.h"
using namespace sgs;
using namespace Surface;
using namespace DataType;
 
GameData::GameData():_playernum(0),_players(0),_open(0){}
GameData::~GameData()
{
	if (_players != 0) delete [] _players;
}
void GameData::initialize(Platform * platform)
{
//	clear();
	_playernum = platform->playernum();
	if (_playernum <=0) return;
	_players = new Player * [_playernum];
	if (_players == 0) return;
	for (int i = 0; i<_playernum; i++) _players[i] = platform->_player->find(i);
	_open = platform->_player->find(0);//将第一个玩家设置为开放玩家
}
bool GameData::clear()
{
	_playernum = 0;
	if (_players != 0) delete [] _players;
	return true;
}
int GameData::playernum() const {return _playernum;}
Player *GameData::players(int seat) const {return _open->find(seat);}
Player *GameData::open() const {return _open;}
