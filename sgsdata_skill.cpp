/*
 //最后整理时间：2012-06-28
 //编辑者：李昂
 //技能类。
 */

#include "sgsdata_skill.h"
#include "sgsdata_enum.h"
#include "sgsdata_skill_func.h"
using namespace sgs;
using namespace DataType;
using namespace ConstData;

Skill::Skill() {
	_skill = hkNone;
	_processor = 0;
}

Skill::Skill(HeroSkill k) :
		_skill(k) {
	protrans(k);
}

HeroSkill Skill::skill() const {
	return _skill;
}

Message* Skill::settle(Message* m) const {
	return (*_processor)(m);
}

void Skill::protrans(HeroSkill k) {
	switch (k) {
	case GUANXING:
	case KONGCHENG:
	case LUOSHEN:
	case LUOYI:
	case MASHU:
	case TIEQI:
	case KEJI:
	case PAOXIAO:
		_processor = 0;
		break;
	case WUSHENG:
		_processor = func::pcwusheng;
		break;
	case GANGLIE:
		_processor = func::pcganglie;
		break;
	case QINGGUO:
		_processor = func::pcqingguo;
		break;
	case LONGDAN:
		_processor = func::pclongdan;
		break;
	case QIXI:
		_processor = func::pcqixi;
		break;
	case FANKUI:
		_processor = func::pcfankui;
		break;
	case GUICAI:
		_processor = func::pcguicai;
		break;
	case KUROU:
		_processor = func::pckurou;
		break;
	case QINGNANG:
		_processor = func::pcqingnang;
		break;
	case JIJIU:
		_processor = func::pcjijiu;
		break;
	case RENDE:
		_processor = func::pcrende;
		break;
	case JIJIANG:
		_processor = func::pcjijiang;
		break;
	case HUJIA:
		_processor = func::pchujia;
		break;
	case LIJIAN:
		_processor = func::pclijian;
		break;
	case ZHIHENG:
		_processor = func::pczhiheng;
		break;
	case FANJIAN:
		_processor = func::pcfanjian;
		break;
	case JIEYIN:
		_processor = func::pcjieyin;
		break;
	case GUOSE:
		_processor = func::pcguose;
		break;
	default:
		_processor = 0;
		break;
	}
}
