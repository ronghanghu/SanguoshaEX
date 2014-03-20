/*
 * sgs_Interface.h
 *
 *  Created on: Apr 2, 2012
 *      Author: latios
 */

#ifndef SGS_INTERFACE_H_
#define SGS_INTERFACE_H_

#include "sgsui_InitiateBox.h"
#include "sgsdata_enum.h"
#include <vector>
#include <utility>

namespace sgs {

namespace DataType {
class Message;
class Player;
class Card;
}

namespace Derive {
class MCard;
class MSkill;
}

class Interface {
public:
	explicit Interface(int seat);
	virtual ~Interface();

	static Interface * createInterface(int seat, ConstData::HeroType heroType,
			bool forceToBeAI = false); // 用这个函数创建AI

	// 扩展这些接口是比较容易的，如果将来出现新的情况，我们只需在接口中加入默认实参或者重载接口
	// 杀闪桃版三国杀所需的响应
	virtual std::vector<int> discardCard(unsigned cardNumToDiscard) = 0; // 弃牌（传入要弃的牌的张数，返回所弃牌位置的数组）
	virtual DataType::Message * useCardResponse() = 0; // 出牌阶段使用某个卡牌，如果选择弃牌则返回空Message，也就是0
	virtual DataType::Message * taoOrNot(DataType::Player * from,
			int neededTaoNumber) = 0; // 被求桃，传入需要桃的玩家指针和需要的桃的个数，如果给桃则返回出牌Message，否则返回0
	virtual DataType::Message * shanOrNot(DataType::Player * from,
			const DataType::Card * card) = 0; // 要求打闪，传入使出杀（或者将来万箭齐发）的玩家指针，和相应的杀卡牌（或万箭齐发卡牌）,返回出牌Message，否则返回0
	virtual DataType::Message * shanOrNot(DataType::Player * from,
			ConstData::HeroSkill) = 0; // 要求打闪，传入谁使用了什么技能（比如曹操使用了护驾）
	virtual DataType::Message * shaOrNot(DataType::Player * from,
			const DataType::Card * card) = 0; // 要求打杀，传入谁使用了什么牌（比如自己使用了青龙偃月刀，对手使用了决斗，或者南蛮入侵）
	virtual DataType::Message * shaOrNot(DataType::Player * from,
			ConstData::HeroSkill) = 0; // 要求打杀，传入谁使用了什么技能（比如刘备使用了激将）
	virtual DataType::Message * wuxieOrNot(DataType::Message * originMsg,
			int count) = 0; // 要求无懈可击，传入要被无懈的出牌Message，以及已经被无懈的次数（一般是0次）
	virtual bool useEquipOrNot(ConstData::CardType equipCardType,
			DataType::Player *targetPlayer) = 0; // 询问是否发动装备的效果。传入要发动的装备卡，以及对谁发动（如果没有目标则为0），返回是否发动
	virtual bool useSkillOrNot(ConstData::HeroSkill skillType,
			DataType::Player * player = 0) = 0; // 询问是否使用技能。传入要使用的技能和目标
	virtual bool useSkillOrNot(ConstData::HeroSkill skillType,
			DataType::Message * message) = 0; // 询问是否使用技能。传入上一次判定的消息

	virtual std::vector<std::pair<ConstData::PlayerRegionType, int> > chooseCardResponse(
			DataType::Player *targetPlayer, bool isHandSelectable,
			bool isEquipSelectable, bool isJudgeSelectable, int num,
			ConstData::CardType reason) = 0; // 要求选择卡牌。传入被选玩家，能否选择手牌，装备牌，判定牌，以及选择卡牌的原因（比如过河拆桥或某个装备牌）
	virtual std::vector<std::pair<ConstData::PlayerRegionType, int> > chooseCardResponse(
			DataType::Player *targetPlayer, bool isHandSelectable,
			bool isEquipSelectable, bool isJudgeSelectable, int num,
			ConstData::HeroSkill reason) = 0; // 要求选择卡牌。传入被选玩家，能否选择手牌，装备牌，判定牌，以及选择卡牌的原因（比如司马懿的反馈或者鬼才）
	virtual bool yesOrNot(ConstData::CardType reason) = 0; // 询问一般的“是否”，传入原因。对于雌雄双股剑，返回true是让对方摸排，返回false是让自己弃牌
	virtual bool yesOrNot(ConstData::HeroSkill reason) = 0; // 询问一般的“是否”，传入原因。对于刚烈，返回true表示要弃牌，返回false表示扣血
	virtual int chooseWugu(
			const std::vector<std::pair<const DataType::Card *, bool> >& wuguCards) = 0; // 五谷丰登选牌，传入的所有牌的Vector，包括什么牌和是否已经被拿走，返回选牌的编号
	virtual void chooseGuanxing(std::vector<const DataType::Card *>& top,
			std::vector<const DataType::Card *>& buttom) = 0;
	virtual DataType::Message * getTuxi() = 0; // 返回是否使用突袭
	virtual DataType::Message * getYiji(const DataType::Card *card1,
			const DataType::Card *card2) = 0; // 返回是否使用遗迹
	virtual DataType::Message * getLiuli(DataType::Player * attacker) = 0;
	virtual std::pair<ConstData::CardColor, int> respondFanjian(
			DataType::Player * zhouyu) = 0;

	int mySeat() const;
	DataType::Player * myPlayer() const;

protected:
	bool canUseSha() const;
	bool canUseFangtian() const;
	bool canUseZhangba() const;
	bool canUseJieyin() const;
	bool haveWuxie() const;
	bool haveRedCard() const;
	bool haveBlackCard() const;
	bool haveDiamondCard() const;

	static bool isDead(int seat);
	static bool isDead(DataType::Player * player);
	static int handEquipNum(DataType::Player * player);
	static int totalCardNum(DataType::Player * player);
	static bool hasWeapon(DataType::Player * player);
	static bool hasSishuInJudge(DataType::Player * player);
	static bool hasShandianInJudge(DataType::Player * player);
	static void showWugu(
			const std::vector<std::pair<const DataType::Card *, bool> >& wuguCards);

private:
	const int _seat;
	static int _maxShaUse;
	mutable DataType::Player * _myPlayer;

	friend void sgsui::InitiateBox::start();
};

} /* namespace sgs */
#endif /* SGS_INTERFACE_H_ */
