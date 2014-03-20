/*
 //最后整理时间：2012-06-28
 //编辑者：李昂
 //消息及其派生类
 //消息是我们设计的三国杀中最重要的数据单位。
 //可以看到有许多的函数以消息基类指针作为参数和返回值，它是几乎所有函数之间沟通的桥梁，也是底层逻辑平台和界面、AI之间交互的纽带。
 //具体的信息见下方每个消息的定义前面的说明
 */
#ifndef _SGSDATA_MSG_H
#define _SGSDATA_MSG_H
#include <vector>
#include <utility>
#include "chain.h"
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
#include "sgsdata_skill.h"

class sgs::DataType::Message //基类，不用于生成对象
{
	sgs::ConstData::MessageType _type; //消息类型
	bool _dissolved; //是否是拆分得到的消息（如南蛮入侵针对每个玩家的结算过程）
	//关于拆分：
	//由于有些卡牌是对于许多目标依次结算，因此需要单独处理每一个结算过程，故将它们拆分为多个并依次处理。详见pcsha，pcnanman等函数的内部消息沟道机制。
public:
	Message(sgs::ConstData::MessageType t) :
			_type(t), _dissolved(false) {
	} //构造
	sgs::ConstData::MessageType type() const; //访问类型
	bool dissolved() const; //调查是否是拆分过的消息
	bool setdissolve(bool); //修改拆分状况
	virtual ~Message(); //虚析构函数
};

//MCard：卡牌的使用和打出信息
//Message::type:有两种可能的消息类型：USECARD和HITCARD，通常的卡牌使用为HITCARD，仅在使用已装备的装备牌或判定牌生效时时取USECARD类型。
//from:来源玩家，注意当这个消息描述的延时锦囊时这一项指的是被判定的玩家。
//to:目标玩家，可以有多个，由_target参数描述目标数量，从0开始计数。注意在借刀杀人中，第一目标为需要出杀的玩家，第二目标为被杀的玩家
//card:使用的卡片。需要注意的是生成卡牌使用或打出信息时应该将卡片从信息发出端弹出，即若某玩家生成了打出卡牌的信息时，应从他的手牌弹出该牌。
//pos:记录了游戏牌是在哪一个地方被打出的。
class sgs::Derive::MCard: public sgs::DataType::Message //卡牌相关：使用，打出。（这是一个命令性的消息，需要外部处理）
{
protected:
	sgs::DataType::Player * _from; //注意，延时锦囊中这一项代表被判定的玩家
	chain<sgs::DataType::Player *> _to; //目标
	int _targets; //目标数
	const sgs::DataType::Card * _card; //卡牌
	std::pair<sgs::ConstData::PlayerRegionType, int> _pos; //打出游戏牌的位置
public:
	MCard(bool use, sgs::DataType::Player * f,
			sgs::ConstData::PlayerRegionType p, int pos,
			sgs::DataType::Player * t = 0); //构造
	MCard(MCard *); //截取构造，截取第一个目标。用于拆分消息。
	MCard(bool use, sgs::DataType::Player * f, const sgs::DataType::Card *,
			sgs::DataType::Player * t = 0);
	~MCard(); //析构

	//访问用函数头
	sgs::DataType::Player * from() const; //访问来源玩家
	sgs::DataType::Player * to(int = 0) const; //访问目标玩家数组，从0开始计数
	const sgs::DataType::Card * card() const; //访问使用的卡片
	std::pair<sgs::ConstData::PlayerRegionType, int> pos() const; //访问使用卡片的位置
	int targets() const; //访问目标数

	//修改用函数头
	bool addto(sgs::DataType::Player *); //增加目标
	bool popto(int = 0); //减少一个目标，默认第一个
};

//MZhangBa：专用于处理丈八蛇矛效果的消息
class sgs::Derive::MZhangBa: public MCard {
protected:
	std::pair<const sgs::DataType::Card *, int> _cost[2];
public:
	MZhangBa(sgs::DataType::Player * f, sgs::DataType::Player * t); //构造
	~MZhangBa();

//访问用函数头
	std::pair<const sgs::DataType::Card *, int> cost(int pos) const; //访问弃牌

//修改用函数头
	bool addcost(int pos);
};

class sgs::Derive::MSkill: public sgs::DataType::Message {
protected:
	sgs::DataType::Skill _skill; //使用的技能种类
	sgs::DataType::Player * _from; //来源
public:
	MSkill(sgs::DataType::Player * from, sgs::ConstData::HeroSkill type); //构造
	~MSkill();

//访问用函数头
	sgs::DataType::Player * from() const; //访问来源
	sgs::ConstData::HeroSkill skill() const; //访问技能类型

//执行用函数头
	sgs::DataType::Message * settle(sgs::DataType::Message *); //技能对应处理函数
};

//MTrans:描述卡牌转移的信息，包括摸牌、弃牌、给牌、偷牌
//fromtype描述卡牌来自哪个区域，可用的枚举变量有：PLAYER（来自玩家），POOLTOP（来自牌堆），DESK（来自牌桌）
//from描述卡牌来自哪个玩家，仅在fromtype是PLAYER时有效。
//frompos描述卡牌来自哪个位置，可用的枚举变量有：PHAND（手牌），PEQUIP（装备），PJUDGE（判定）
//pos描述卡牌更具体的位置，从0开始计数，如frompos为PHAND时pos为0即表示第一张手牌
//同样注意生成该信息时转移的牌应该从发出端弹出，而在处理这个信息时再将牌插入目标端。
class sgs::Derive::MTransCard: public sgs::DataType::Message //卡牌转移（这是一个命令性的消息，需要外部处理）
{
	sgs::ConstData::RegionType _fromtype; //来源种类
	sgs::ConstData::RegionType _totype; //目标
	bool _open; //是否公开可见
	sgs::DataType::Player * _from; //如果来源是玩家，则记录玩家指针
	sgs::DataType::Player * _to; //如果目标是玩家，则记录玩家指针
	sgs::ConstData::PlayerRegionType _frompos; //如果是玩家的话，来自手牌、装备区或判定区
	int _cards; //转移牌数
	bool _toJudge; //如果是转移给玩家，是否是转移到它的判定区
	chain<int> _pos; //如果是玩家的话，来自哪个位置号
	chain<const sgs::DataType::Card *> _trans; //转移的牌
public:
	MTransCard(sgs::ConstData::RegionType ft, sgs::ConstData::RegionType tt,
			bool open, sgs::DataType::Player * f = 0,
			ConstData::PlayerRegionType p = ConstData::prtNone,
			sgs::DataType::Player * t = 0, bool = false);
	~MTransCard();

	//访问用函数头
	sgs::ConstData::RegionType fromtype() const; //访问来源种类
	sgs::ConstData::RegionType totype() const; //访问目标种类
	sgs::DataType::Player * from() const; //如果是玩家，访问来源指针
	sgs::DataType::Player * to() const; //如果是玩家，访问目标指针
	sgs::ConstData::PlayerRegionType frompos() const; //如果是玩家的话，来自手牌、装备区或判定区
	int cards() const; //访问牌数
	const sgs::DataType::Card * trans(int = 0) const; //访问转移的第n张牌，默认第一张
	int pos(int) const; //转移的位置，从0开始计数，只在从玩家处转移时有效
	bool open() const; //是否可见
	bool tojudge() const; //是否是转移到判定区

	//修改用函数头
	bool transpush(const sgs::DataType::Card *); //加入一张转移卡
	bool transpush(int fp); //加入转移的位置，仅在确定来自玩家时可以使用
	bool transpush(int fp, const sgs::DataType::Card *); //写入转移卡和位置，用于五谷丰登。
	bool transpop(int = 0); //弹出第一张转移卡，默认第一张
};

//MSwitchPhase:阶段切换信息
//在发出这个信息之前，阶段应该已经修改完毕
class sgs::Derive::MSwitchPhase: public sgs::DataType::Message //阶段切换（这是一个通知性的消息，不需要外部处理，即内部已经处理完成）
{
	sgs::DataType::Player * _from; //来源玩家指针
	sgs::ConstData::PlayerPhase _before; //原来的阶段
	sgs::ConstData::PlayerPhase _after; //转换到的阶段
public:
	MSwitchPhase(sgs::DataType::Player * f, sgs::ConstData::PlayerPhase b,
			sgs::ConstData::PlayerPhase a); //构造
	~MSwitchPhase();

	//访问用函数头
	sgs::DataType::Player * from() const; //访问来源玩家指针
	sgs::ConstData::PlayerPhase before() const; //访问切换前阶段
	sgs::ConstData::PlayerPhase after() const; //访问切换后阶段
};

//MHurt:伤害/回复信息
//在发出这个信息之前，伤害与回复已经造成。
class sgs::Derive::MHurt: public sgs::DataType::Message {
	sgs::DataType::Player * _from; //伤害来源
	sgs::DataType::Player * _to; //受到伤害的人
	int _hurt; //正值表示损血，负值表示加血
public:
	MHurt(sgs::DataType::Player* f, sgs::DataType::Player* t, int h);
	~MHurt();
	//访问
	sgs::DataType::Player* from() const;
	sgs::DataType::Player* to() const;
	int hurt() const;
};
//伤害

//MJudge:判定消息
//在发出这个消息之前，判定已经结束并确定生效与否。
class sgs::Derive::MJudge: public sgs::DataType::Message {
	sgs::DataType::Player * _from; //判定来源。即谁接受了判定。
	const sgs::DataType::Card* _card; //需要判定的牌。
	const sgs::DataType::Card* _result; //作为判定结果的牌。
	bool _effect; //判定是否生效，如乐不思蜀是否成功
	sgs::ConstData::HeroSkill _skill; //需要判定的技能。
	bool _cardJudge; //判定的是牌吗？
public:
	MJudge(sgs::DataType::Player * from, const sgs::DataType::Card* card,
			const sgs::DataType::Card * result, bool);
	MJudge(sgs::DataType::Player * from, sgs::ConstData::HeroSkill,
			const sgs::DataType::Card * result, bool);
	~MJudge();
//访问用函数头
	sgs::DataType::Player * from() const;
	const sgs::DataType::Card* card() const;
	const sgs::DataType::Card* result() const;
	bool effect() const;
	bool cardJudge() const;
	sgs::ConstData::HeroSkill skill() const;
};

//MDying:濒死信息
//neg:恢复到1血所需要的桃个数
//murderer:自然死亡时该指针为空，如被闪电劈死
class sgs::Derive::MDying: public sgs::DataType::Message {
	sgs::DataType::Player * _from; //濒死的玩家
	sgs::DataType::Player * _murderer; //对他造成伤害的玩家
	int _neg; //求桃数
public:
	MDying(sgs::DataType::Player *, sgs::DataType::Player *, int);
	~MDying();
	//访问用函数头
	sgs::DataType::Player * from() const;
	sgs::DataType::Player * murderer() const;
	int neg() const;
};
//濒死

//MKill:击杀消息
//发出信息前死亡已经造成，但死亡引起的惩罚与结束判定尚未进行，死亡玩家的游戏牌处理也未完成。
class sgs::Derive::MKill: public sgs::DataType::Message {
	sgs::DataType::Player * _from; //造成最后伤害的人
	sgs::DataType::Player * _die; //被杀的人
public:
	MKill(sgs::DataType::Player * f, sgs::DataType::Player * t);
	~MKill();
	//访问用函数头
	sgs::DataType::Player * from() const;
	sgs::DataType::Player * to() const;
};
//击杀

//MBegin:事件开始标记
//暂时闲置不用
class sgs::Derive::MBegin: public sgs::DataType::Message //事件开始标记
{
public:
	MBegin() :
			Message(sgs::ConstData::BEGIN) {
	}
	~MBegin() {
	}
};

//MFinale:游戏结束标记
//这个消息标志着游戏的结束，储存着游戏结果。
class sgs::Derive::MFinale: public sgs::DataType::Message {
	char _finale; //游戏结果，用位存储玩家死亡信息
public:
	MFinale(char finale) :
			Message(sgs::ConstData::FINALE), _finale(finale) {
	}
	~MFinale() {
	}
	//访问用函数头
	char finale() const {
		return _finale;
	}
};

class sgs::Derive::MWuSheng: public sgs::Derive::MSkill {
protected:
	const sgs::DataType::Card * _card;
	chain<sgs::DataType::Player *> _to;
	int _targets;
	std::pair<sgs::ConstData::PlayerRegionType, int> _pos; //手牌的哪一张
public:
	MWuSheng(sgs::DataType::Player * from, sgs::ConstData::PlayerRegionType, int, sgs::DataType::Player * to = 0); //构造
	~MWuSheng();

	const sgs::DataType::Card * card() const;
	sgs::DataType::Player * to(int pos) const;
	int targets() const;
	std::pair<sgs::ConstData::PlayerRegionType, int> pos() const;
	void addto(sgs::DataType::Player *);
	void popto(int pos = 0);
};

class sgs::Derive::MQingGuo: public sgs::Derive::MSkill {
protected:
	const sgs::DataType::Card * _card;
	int _pos; //在手牌的那个位置
public:
	MQingGuo(sgs::DataType::Player * from, int pos);
	~MQingGuo();

	const sgs::DataType::Card * card() const;
	int pos() const;
};

class sgs::Derive::MLongDan: public sgs::Derive::MSkill {
protected:
	const sgs::DataType::Card * _card;
	chain<sgs::DataType::Player *> _to;
	int _targets;
	int _pos; //手牌的哪一张
public:
	MLongDan(sgs::DataType::Player * from, int, sgs::DataType::Player * to = 0); //构造
	~MLongDan();

	const sgs::DataType::Card * card() const;
	sgs::DataType::Player * to(int pos) const;
	int targets() const;
	int pos() const;
	void addto(sgs::DataType::Player *);
	void popto(int pos = 0);
};

class sgs::Derive::MQiXi: public sgs::Derive::MSkill {
protected:
	const sgs::DataType::Card * _card;
	sgs::DataType::Player * _to;
	std::pair<sgs::ConstData::PlayerRegionType, int> _pos;
public:
	MQiXi(sgs::DataType::Player * from, sgs::ConstData::PlayerRegionType, int,
			sgs::DataType::Player * to); //构造
	~MQiXi();

	const sgs::DataType::Card * card() const;
	sgs::DataType::Player * to() const;
	std::pair<sgs::ConstData::PlayerRegionType, int> pos() const;
};

class sgs::Derive::MFanKui: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _to;
public:
	MFanKui(sgs::DataType::Player * from, sgs::DataType::Player * to);
	~MFanKui();

	sgs::DataType::Player * to() const;
};

class sgs::Derive::MGangLie: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _to;
public:
	MGangLie(sgs::DataType::Player * from, sgs::DataType::Player * to); //构造
	~MGangLie();

	sgs::DataType::Player * to() const;
};

class sgs::Derive::MQingNang: public sgs::Derive::MSkill {
protected:
	const sgs::DataType::Card * _card;
	int _pos;
	sgs::DataType::Player * _to;
public:
	MQingNang(sgs::DataType::Player * from, int, sgs::DataType::Player * to);
	~MQingNang();

	const sgs::DataType::Card * card() const;
	sgs::DataType::Player * to() const;
	int pos() const;
};

class sgs::Derive::MJiJiu: public sgs::Derive::MSkill {
protected:
	const sgs::DataType::Card * _card;
	std::pair<sgs::ConstData::PlayerRegionType, int> _pos;
public:
	MJiJiu(sgs::DataType::Player * from, sgs::ConstData::PlayerRegionType, int);
	~MJiJiu();

	const sgs::DataType::Card * card() const;
	std::pair<sgs::ConstData::PlayerRegionType, int> pos() const;
};

class sgs::Derive::MRenDe: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _to;
	std::vector<std::pair<int, const sgs::DataType::Card *> > _card;
	int _cards;
public:
	MRenDe(sgs::DataType::Player * from, sgs::DataType::Player * to);
	~MRenDe();

	const sgs::DataType::Card * card(int pos) const;
	int pos(int) const;
	sgs::DataType::Player * to() const;
	int cards() const;

	void transpush(int);
	//返回消息时按从大到小排序，即插入时按从小到大插入
};

class sgs::Derive::MJiJiang: public sgs::Derive::MSkill {
protected:
	chain<sgs::DataType::Player *> _to;
	int _targets;
public:
	MJiJiang(sgs::DataType::Player * from, sgs::DataType::Player * to = 0);
	~MJiJiang();

	int targets() const;
	void addto(sgs::DataType::Player *);
	void popto(int = 0);
	sgs::DataType::Player * to(int = 0) const;
};

class sgs::Derive::MLiJian: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _toFirst;
	sgs::DataType::Player * _toSecond;
	std::pair<sgs::ConstData::PlayerRegionType, int> _pos;
	const sgs::DataType::Card * _card;
public:
	MLiJian(sgs::DataType::Player * from, sgs::ConstData::PlayerRegionType, int,
			sgs::DataType::Player * first, sgs::DataType::Player * second);
	~MLiJian();

	sgs::DataType::Player * first() const;
	sgs::DataType::Player * second() const;
	std::pair<sgs::ConstData::PlayerRegionType, int> pos() const;
	const sgs::DataType::Card * card() const;
};

class sgs::Derive::MTuXi: public sgs::Derive::MSkill {
protected:
	std::pair<sgs::DataType::Player *, int> _pos[2];
	const sgs::DataType::Card * _card[2];
	int _targets;
public:
	MTuXi(sgs::DataType::Player * from, sgs::DataType::Player * target1,
			int pos1, sgs::DataType::Player * target2 = 0, int pos2 = -1);
	~MTuXi();

	std::pair<sgs::DataType::Player *, int> pos(int p) const;
	const sgs::DataType::Card * card(int p) const;
	int targets() const;
};

class sgs::Derive::MYiJi: public sgs::Derive::MSkill {
protected:
	std::pair<sgs::DataType::Player *, const sgs::DataType::Card *> _trans[2];
public:
	MYiJi(sgs::DataType::Player * from, sgs::DataType::Player * target1,
			const sgs::DataType::Card * card1, sgs::DataType::Player * target2,
			const sgs::DataType::Card * card2);
	~MYiJi();

	std::pair<sgs::DataType::Player *, const sgs::DataType::Card *> trans(
			int pos) const;
};

class sgs::Derive::MZhiHeng: public sgs::Derive::MSkill {
protected:
	std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > _pos;
	std::vector<const sgs::DataType::Card *> _card;
	int _cards;

public:
	MZhiHeng(sgs::DataType::Player *);
	~MZhiHeng();

	void transpush(sgs::ConstData::PlayerRegionType, int);
	std::pair<sgs::ConstData::PlayerRegionType, int> pos(int) const;
	const sgs::DataType::Card * card(int) const;
	int cards() const;
};

class sgs::Derive::MFanJian: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _to;
public:
	MFanJian(sgs::DataType::Player * from, sgs::DataType::Player * to);
	~MFanJian();

	sgs::DataType::Player * to() const;
};

class sgs::Derive::MJieYin: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _to;
	int _pos[2];
	const sgs::DataType::Card * _card[2];
public:
	MJieYin(sgs::DataType::Player * from, sgs::DataType::Player * to, int pos1,
			int pos2);
	~MJieYin();

	sgs::DataType::Player * to() const;
	int pos(int) const;
	const sgs::DataType::Card * card(int) const;
};

class sgs::Derive::MGuoSe: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _to;
	std::pair<sgs::ConstData::PlayerRegionType, int> _pos;
	const sgs::DataType::Card * _card;
public:
	MGuoSe(sgs::DataType::Player * from, sgs::ConstData::PlayerRegionType, int,
			sgs::DataType::Player * to);
	~MGuoSe();

	sgs::DataType::Player * to() const;
	std::pair<sgs::ConstData::PlayerRegionType, int> pos() const;
	const sgs::DataType::Card * card() const;
};

class sgs::Derive::MLiuLi: public sgs::Derive::MSkill {
protected:
	sgs::DataType::Player * _to;
	std::pair<sgs::ConstData::PlayerRegionType, int> _pos;
	const sgs::DataType::Card * _card;
public:
	MLiuLi(sgs::DataType::Player * from, sgs::ConstData::PlayerRegionType, int,
			sgs::DataType::Player * to);
	~MLiuLi();

	sgs::DataType::Player * to() const;
	std::pair<sgs::ConstData::PlayerRegionType, int> pos() const;
	const sgs::DataType::Card * card() const;
};

#endif /*SGSDATA_MSG_H*/
