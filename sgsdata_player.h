/*
 //最后整理时间：2012-06-28
 //编辑者：李昂
 //玩家类。
 //玩家类是数据量最大的一个类，记录着每个玩家的全部消息。也提供平台和玩家交互的接口。
 */
#ifndef _SGSDATA_PLAYER_H
#define _SGSDATA_PLAYER_H
#include <vector>
#include <list>
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"

class sgs::DataType::Player {
	//初始化信息
	sgs::Interface * _input; //指令来源，UI/AI
	const int _seat; //从0开始编号，0表示用户
	sgs::DataType::Player * _next; //下一位置的玩家
	sgs::DataType::Player * _prev; //上一位置的玩家
	const sgs::ConstData::PlayerRole _role; //玩家身份
	sgs::DataType::Hero * _hero; //玩家所选武将

	//游戏中使用的信息
	char _status; //玩家的状态
	int _shaCount; // 当回合使用过的杀的个数
	sgs::ConstData::PlayerPhase _phase; //玩家所处的阶段
	int _hp; //玩家当前的血量
	chain<const sgs::DataType::Card *> _hand; //玩家的手牌
	chain<const sgs::DataType::Card *> _judge; //玩家的判定区
	struct //玩家的装备区
	{
		const sgs::DataType::Card * atkhorse; //减一马
		const sgs::DataType::Card * dfdhorse; //加一马
		const sgs::DataType::Card * weapon; //武器
		const sgs::DataType::Card * armor; //防具
	} _equip;

	void herotrans(sgs::ConstData::HeroType t); //依据武将类型改变武将指针
public:
	Player(int s, sgs::ConstData::PlayerRole r); //构造
	~Player(); //析构

	//访问用函数头
	//英雄信息
	int maxHP() const; //最大血量
	sgs::ConstData::HeroType type() const; //英雄种类
	sgs::ConstData::HeroSex sex() const; //英雄性别
	sgs::ConstData::HeroSide side() const; //英雄势力
	sgs::DataType::Skill skill(int pos); //英雄技能，从0开始计数
	int skillnum() const; //英雄技能个数
	//玩家数据信息
	sgs::Interface * input() const; //返回输入来源
	Player * next() const; //返回后面玩家的指针(无论死活)
	Player * prev() const; //返回前面玩家的指针(无论死活)
	Player * after() const; //返回后面活着玩家的指针
	Player * before() const; //返回前面活着玩家的指针
	Player * find(int n) const; //寻找座位号为n的玩家
	int distance(const Player *) const; //计算由自己到对方的距离，-1作为报错值
	int range() const; //计算攻击距离
	int seat() const; //座位号
	sgs::ConstData::PlayerRole role() const; //身份
	sgs::ConstData::PlayerPhase phase() const; //阶段
	int hp() const; //血量
	char status() const; //状态
	int handnum(); //手牌张数
	const sgs::DataType::Card * hand(int pos); //手牌，从0开始计数
	int judgenum(); //判定牌张数
	const sgs::DataType::Card * judge(int pos); //判定区，从0开始计数
	const sgs::DataType::Card * atkhorse() const;
	const sgs::DataType::Card * dfdhorse() const;
	const sgs::DataType::Card * weapon() const;
	const sgs::DataType::Card * armor() const;
	int shaCount() const; // 当回合使用杀的次数
	const sgs::DataType::Card * visitCard(
			std::pair<sgs::ConstData::PlayerRegionType, int>); //根据位置信息访问卡牌

	//平台用函数头，包括修改用函数头

	char& setstatus(); //修改状态
	int& sethp(); //修改当前血量
	//chain<const sgs::DataType::Card *>& sethand(); //修改手牌
	chain<const sgs::DataType::Card *>& setjudge(); //修改判定区
	void addShaCount(); // 增加一次使用杀的记录
	void clearShaCount(); // 将出杀的个数归0
	void setphase(sgs::ConstData::PlayerPhase); //修改阶段
	void setatk(const sgs::DataType::Card *);
	void setdfd(const sgs::DataType::Card *);
	void setweapon(const sgs::DataType::Card *);
	void setarmor(const sgs::DataType::Card *);
	void choosehero(std::vector<sgs::ConstData::HeroType>& herovec,
			sgs::ConstData::HeroType lord = sgs::ConstData::htNone);
	void setinput(sgs::Interface * i); //设置输入端口
	void popCard(std::pair<sgs::ConstData::PlayerRegionType, int>); //根据位置信息弹出卡牌
	void pushHand(const sgs::DataType::Card *);

	// 逻辑用函数头
	sgs::DataType::Message * round(sgs::DataType::Platform&); //执行过程
	//sgs::DataType::Message * react(sgs::DataType::Message *);//响应
	sgs::DataType::Message * ShanOrNot(sgs::DataType::Message *); //请求出闪
	sgs::DataType::Message * TaoOrNot(sgs::DataType::Message *); //请求出桃
	sgs::DataType::Message * WuXieOrNot(sgs::DataType::Message *, int times); //请求出无懈，传入最初引发无懈的消息和已经被无懈的次数。
	sgs::DataType::Message * ShaOrNot(sgs::DataType::Message *); //请求出杀

	friend class sgs::DataType::Manager;
	//玩家管理员为友元
};

#endif /*_SGSDATA_PLAYER_H*/
