/*
//最后整理时间：2012-06-28
//编辑者：李昂
//武将基类的定义。武将以全局变量的形式存在，构造玩家时会决定对应的武将并通过指针来访问。
//其他武将在heroes.h中定义。
*/
#ifndef _SGSDATA_HERO_H
#define _SGSDATA_HERO_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
#include "sgsdata_skill.h"
#include "sgsdata_msg.h"
#include "sgsdata_player.h"
 
class sgs::DataType::Hero
{
	int _maxHP;//最大血量
	sgs::ConstData::HeroType _type;//武将种类
	sgs::ConstData::HeroSex _sex;//武将性别
	sgs::ConstData::HeroSide _side;//武将势力
	sgs::DataType::Skill _skill[4];//武将技能
	int _skills;//武将技能个数
public:
	Hero(int maxHP, sgs::ConstData::HeroType type, sgs::ConstData::HeroSex sex, sgs::ConstData::HeroSide side,
	sgs::ConstData::HeroSkill skill0 = sgs::ConstData::hkNone, sgs::ConstData::HeroSkill skill1 = sgs::ConstData::hkNone,
	sgs::ConstData::HeroSkill skill2 = sgs::ConstData::hkNone, sgs::ConstData::HeroSkill skill3 = sgs::ConstData::hkNone);//构造函数
	virtual ~Hero();

	//访问用函数头
    int maxHP() const;//最大血量
    sgs::ConstData::HeroType type() const;//英雄种类
    sgs::ConstData::HeroSex sex() const;//英雄性别
    sgs::ConstData::HeroSide side() const;//英雄势力
	sgs::DataType::Skill skill(int pos);//英雄技能，从0开始计数
	int skillnum() const;//英雄技能个数

    //阶段函数。锁定技会写死在这些函数的多态中。传入参数为对应的玩家。
	virtual sgs::DataType::Message * start(sgs::DataType::Player *);//开始阶段
	virtual sgs::DataType::Message * judge(sgs::DataType::Player *);//判定阶段
	virtual sgs::DataType::Message * get(sgs::DataType::Player *);//摸牌阶段
    virtual sgs::DataType::Message * heromain(sgs::DataType::Player *);//主要阶段
	virtual sgs::DataType::Message * abandon(sgs::DataType::Player *);//弃牌阶段
	virtual sgs::DataType::Message * end(sgs::DataType::Player *);//结束阶段
};

#endif /*_SGSDATA_HERO_H*/
