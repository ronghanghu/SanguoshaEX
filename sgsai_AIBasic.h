/*
 * sgsai_AIBasic.h
 *
 *  Created on: May 5, 2012
 *      Author: latios
 */

#ifndef SGSAI_AIBASIC_H_
#define SGSAI_AIBASIC_H_

#include "sgs_Interface.h"
#include <QObject>

typedef std::pair<const sgs::DataType::Card *, int> cardPair;
typedef std::vector<std::pair<const sgs::DataType::Card *, int> > CardVec;
typedef std::vector<sgs::DataType::Player *> PlayerVec;

namespace sgsai {

class AIBasic: public QObject, public sgs::Interface {
public:
	explicit AIBasic(int seat);
	virtual std::vector<int> discardCard(unsigned int cardNumToDiscard);
	virtual sgs::DataType::Message * useCardResponse();
	virtual sgs::DataType::Message * taoOrNot(sgs::DataType::Player * from,
			int /*neededTaoNumber*/);
	virtual sgs::DataType::Message * shanOrNot(sgs::DataType::Player * /*from*/,
			const sgs::DataType::Card * /*card*/);
	virtual sgs::DataType::Message * shanOrNot(sgs::DataType::Player * from,
			sgs::ConstData::HeroSkill skillType);
	virtual sgs::DataType::Message * shaOrNot(sgs::DataType::Player * /*from*/,
			const sgs::DataType::Card * /*card*/);
	virtual sgs::DataType::Message * shaOrNot(sgs::DataType::Player * from,
			sgs::ConstData::HeroSkill skillType);
	virtual bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Message * message);

protected:
	// these functions are called by useCardResponse()
	virtual sgs::Derive::MCard * installEquip();
	virtual sgs::Derive::MCard * useTao();
	virtual sgs::Derive::MCard * useSha();
	virtual sgs::Derive::MCard * useJinnang();

	virtual sgs::Derive::MCard * useZhangba();

	virtual bool isMyFriend(sgs::DataType::Player * player) const; // this method does not care whether the argument player is dead
	sgs::DataType::Player * lord(); // when lord is dead, this method returns 0
	const PlayerVec& shaTarget();
	const PlayerVec& sishuTarget(); // sorted
	const PlayerVec& guochaiTarget(); // sorted
	const PlayerVec& juedouTarget(); // sorted
	PlayerVec shunqianTarget(); // sorted
	PlayerVec playersHavingWeapon();
	PlayerVec jiedaoTarget(sgs::DataType::Player *weaponOwner);
	std::pair<sgs::DataType::Player *, sgs::DataType::Player *> makeJiedaoPair(); // the first is the attacker and the second is the victim
	bool isAllFanzeiDead() const;

private:
	sgs::DataType::Player * _lord;

	PlayerVec shaTargetVec;
	PlayerVec sishuTargetVec;
	PlayerVec guochaiTargetVec;
	PlayerVec juedouTargetVec;

	const static std::pair<sgs::DataType::Player *, sgs::DataType::Player *> invalidJiedaoPair;
};

} /* namespace sgsai */
#endif /* SGSAI_AIBASIC_H_ */
