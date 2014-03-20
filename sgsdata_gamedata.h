/*
//最后整理时间：2012-06-28
//编辑者：李昂
//显示用数据堆，主要作用是为界面提供专门的访问接口。
*/
#ifndef _SGSDATA_GAMEDATA_H
#define _SGSDATA_GAMEDATA_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
 
class sgs::Surface::GameData
{
	int _playernum;//玩家个数
	sgs::DataType::Player ** _players;//指针数组，角标对应座位
	sgs::DataType::Player * _open;//开放玩家（显示这个玩家的内部讯息）
public:
	GameData();
	~GameData();
	void initialize(sgs::DataType::Platform * platform);//初始化
	bool clear();//清空所有内容

	//访问用函数头
	int playernum() const;
	sgs::DataType::Player * players(int seat) const;//通过座位号访问玩家，从0开始
	sgs::DataType::Player * open() const;//访问开放玩家
};
 
#endif /*_SGSDATA_GAMEDATA_H*/
