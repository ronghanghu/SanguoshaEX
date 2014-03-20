/*
 //最后整理时间：2012-06-28
 //编辑者：李昂
 //卡牌类的定义。
 //卡牌以全局常变量的形式存在，游戏过程中一直以常指针来访问它，摸牌、洗牌等操作都是对常指针进行操作。
 //考虑到有“当做xx牌使用“的情况，加入了mask功能，用于临时作为某牌使用的情况。
 */
#ifndef _SGSDATA_CARD_H
#define _SGSDATA_CARD_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"

class sgs::DataType::Card {
	int _number; //点数
	sgs::ConstData::CardColor _color; //花色
	sgs::ConstData::CardType _type; //实体卡种类
	mutable sgs::ConstData::CardType _mask; //执行效果种类（如大乔国色时实际效果卡即与实体卡种类无关）
	mutable sgs::DataType::Message * (*_processor)(sgs::DataType::Message*); //对应的处理器函数

	void protrans(sgs::ConstData::CardType) const; //根据卡牌种类为处理器函数指针赋值
public:
	Card(); //默认构造
	Card(sgs::ConstData::CardColor c, int n, sgs::ConstData::CardType t); //构造
	~Card(); //析构

	//访问用函数头
	int number() const; //访问点数
	sgs::ConstData::CardColor color() const; //访问花色
	sgs::ConstData::CardType type() const; //访问实体卡类型
	sgs::ConstData::CardType mask() const; //访问效果类型
	sgs::DataType::Message * settle(sgs::DataType::Message *) const; //调用处理器函数

	//修改用函数头
	void setmask(sgs::ConstData::CardType m) const; //设置效果，同时修改处理器指向
	void setmask() const; //将效果改回实体卡效果，同时修改处理器指向
};

#endif /*_SGSDATA_CARD_H*/
