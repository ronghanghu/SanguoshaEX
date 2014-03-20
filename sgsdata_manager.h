/*
//最后整理时间：2012-06-28
//编辑者：李昂
//玩家管理员类的定义
//负责玩家的构造、身份分配、武将选择等功能的实现。
//是平台类的一个基类。
*/
#ifndef _SGSDATA_MANAGER_H
#define _SGSDATA_MANAGER_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
 
class sgs::DataType::Manager
{
	sgs::DataType::Player * players;//玩家指针，指向用户对应的玩家
	int N;//玩家个数
public:
	Manager();//构造函数
	~Manager();//析构函数
    void clearplayer();//清空玩家
    sgs::DataType::Player * create(int n);//创造n(2~8)个玩家，分配身份并选定武将。返回主公（开始游戏的玩家）指针。

	//访问用函数头
	int playernum() const;//访问玩家个数
	sgs::DataType::Player * player();//访问用户对应的玩家
};
 
#endif /*_SGSDATA_MANAGER_H*/
