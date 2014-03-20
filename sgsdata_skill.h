/*
 //最后整理时间：2012-06-30
 //编辑者：李昂
 //技能类。
 */
#ifndef _SGSDATA_SKILL_H
#define _SGSDATA_SKILL_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"

class sgs::DataType::Skill {
	sgs::ConstData::HeroSkill _skill; //技能类型
	sgs::DataType::Message* (*_processor)(sgs::DataType::Message*); //处理器

	void protrans(sgs::ConstData::HeroSkill); //由技能类型找到函数
public:
	Skill(); //默认构造
	Skill(sgs::ConstData::HeroSkill); //转换构造

//访问用函数头
	sgs::ConstData::HeroSkill skill() const; //访问技能类型
	sgs::DataType::Message* settle(sgs::DataType::Message*) const; //调用处理器函数
};

#endif /*_SGSDATA_SKILL_H*/
