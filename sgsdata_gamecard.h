/*
//最后整理时间：2012-06-28
//编辑者：李昂
//用于管理牌堆和弃牌堆的类
//是平台类的一个基类。
*/
#ifndef _SGSDATA_GAMECARD_H
#define _SGSDATA_GAMECARD_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
 
class sgs::DataType::GameCard
{
    chain <const sgs::DataType::Card *> pool;//牌堆
    chain <const sgs::DataType::Card *> dustbin;//弃牌堆

	void refresh();//洗牌
public:
	GameCard();//构造
	~GameCard();//析构
    void load();//读入牌组（将全局常变量的指针存入牌堆）
	void clearcard();//清理牌堆，即清空牌堆与弃牌堆

	//执行过程用函数
    const sgs::DataType::Card * get();//从牌堆顶取出一张牌，执行完毕后牌堆里即无此牌
    void pooltop(const sgs::DataType::Card *);//向牌堆顶插入一张牌
    void poolbottom(const sgs::DataType::Card *);//向牌堆底插入一张牌
    void abandon(const sgs::DataType::Card *);//弃一张牌

	//调试用函数
	const sgs::DataType::Card * peekpool(int n) const;//观察牌堆从顶向底数的第n张牌，从0开始计数
	const sgs::DataType::Card * peekdustbin(int n) const;//观察弃牌堆从顶向底数的第n张牌，从0开始计数
	int poolsize() const;
	int dustbinsize() const;
	void setpool(int n, const sgs::DataType::Card *card);//修改卡牌，用于调试
	void setdustbin(int n, const sgs::DataType::Card *card);//修改卡牌，用于调试
};
 
#endif /*_SGSDATA_GAMECARD_H*/
