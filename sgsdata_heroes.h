/*
 //最后修改时间2012-06-28
 //编辑者：李昂
 //各种武将的类定义。
 //目前版本为1.10 alpha版，还未扩展武将功能，只支持男女素将。
 */
#ifndef _SGSDATA_HEROES_H
#define _SGSDATA_HEROES_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
#include "sgsdata_hero.h"

class sgs::Derive::HSuJiang: public sgs::DataType::Hero {
public:
	HSuJiang();
	~HSuJiang();
};

class sgs::Derive::HNvSuJiang: public sgs::DataType::Hero {
public:
	HNvSuJiang();
	~HNvSuJiang();
};

class sgs::Derive::HZhangFei: public sgs::DataType::Hero {
public:
	HZhangFei();
	~HZhangFei();

    sgs::DataType::Message * heromain(sgs::DataType::Player *); //虚函数，张飞的主要阶段略有不同
};

class sgs::Derive::HLvMeng: public sgs::DataType::Hero {
public:
	HLvMeng();
	~HLvMeng();

    sgs::DataType::Message * heromain(sgs::DataType::Player *); //虚函数，吕蒙的主要阶段略有不同
	sgs::DataType::Message * get(sgs::DataType::Player *);
};

class sgs::Derive::HMaChao: public sgs::DataType::Hero {
public:
	HMaChao();
	~HMaChao();
};

class sgs::Derive::HGuanYu: public sgs::DataType::Hero {
public:
	HGuanYu();
	~HGuanYu();
};

class sgs::Derive::HXiaHouDun: public sgs::DataType::Hero {
public:
	HXiaHouDun();
	~HXiaHouDun();
};

class sgs::Derive::HXuChu: public sgs::DataType::Hero {
public:
	HXuChu();
	~HXuChu();

	sgs::DataType::Message * get(sgs::DataType::Player *); //虚函数
};

class sgs::Derive::HZhenJi: public sgs::DataType::Hero {
public:
	HZhenJi();
	~HZhenJi();

	sgs::DataType::Message * start(sgs::DataType::Player *);
};

class sgs::Derive::HLaoZhuGe: public sgs::DataType::Hero {
public:
	HLaoZhuGe();
	~HLaoZhuGe();

	sgs::DataType::Message * start(sgs::DataType::Player *);
};

class sgs::Derive::HZhaoYun: public sgs::DataType::Hero {
public:
	HZhaoYun();
	~HZhaoYun();
};

class sgs::Derive::HGanNing: public sgs::DataType::Hero {
public:
	HGanNing();
	~HGanNing();
};

class sgs::Derive::HSiMaYi: public sgs::DataType::Hero {
public:
	HSiMaYi();
	~HSiMaYi();
};

class sgs::Derive::HHuangGai: public sgs::DataType::Hero {
public:
	HHuangGai();
	~HHuangGai();
};

class sgs::Derive::HHuaTuo: public sgs::DataType::Hero {
public:
	HHuaTuo();
	~HHuaTuo();
};

class sgs::Derive::HLiuBei: public sgs::DataType::Hero {
public:
	HLiuBei();
	~HLiuBei();
};

class sgs::Derive::HCaoCao: public sgs::DataType::Hero {
public:
	HCaoCao();
	~HCaoCao();
};

class sgs::Derive::HHuangYueYing: public sgs::DataType::Hero {
public:
	HHuangYueYing();
	~HHuangYueYing();
};

class sgs::Derive::HDiaoChan: public sgs::DataType::Hero {
public:
	HDiaoChan();
	~HDiaoChan();

	sgs::DataType::Message * end(sgs::DataType::Player *);
};

class sgs::Derive::HZhangLiao: public sgs::DataType::Hero {
public:
	HZhangLiao();
	~HZhangLiao();

	sgs::DataType::Message * get(sgs::DataType::Player *);
};

class sgs::Derive::HGuoJia: public sgs::DataType::Hero {
public:
	HGuoJia();
	~HGuoJia();
};

class sgs::Derive::HSunQuan: public sgs::DataType::Hero {
public:
	HSunQuan();
	~HSunQuan();
};

class sgs::Derive::HLvBu: public sgs::DataType::Hero {
public:
	HLvBu();
	~HLvBu();
};

class sgs::Derive::HZhouYu: public sgs::DataType::Hero {
public:
	HZhouYu();
	~HZhouYu();

	sgs::DataType::Message * get(sgs::DataType::Player * player);
};

class sgs::Derive::HSunShangXiang: public sgs::DataType::Hero {
public:
	HSunShangXiang();
	~HSunShangXiang();
};

class sgs::Derive::HLuXun: public sgs::DataType::Hero {
public:
	HLuXun();
	~HLuXun();
};

class sgs::Derive::HDaQiao: public sgs::DataType::Hero {
public:
	HDaQiao();
	~HDaQiao();
};

#endif /*_SGSDATA_HEROES_H*/
