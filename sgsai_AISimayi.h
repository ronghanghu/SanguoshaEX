/*
 * sgsai_AISimayi.h
 *
 *  Created on: May 15, 2012
 *      Author: latios
 */

#ifndef SGSAI_AISIMAYI_H_
#define SGSAI_AISIMAYI_H_

#include "sgsai_AICommon.h"

namespace sgs {
namespace Derive {
class MJudge;
}
}

namespace sgsai {

class AISimayi: public AICommon {
public:
	explicit AISimayi(int seat);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Player * player);
	bool useSkillOrNot(sgs::ConstData::HeroSkill skillType,
			sgs::DataType::Message * message);
	std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > chooseCardResponse(
			sgs::DataType::Player *targetPlayer, bool isHandSelectable,
			bool isEquipSelectable, bool isJudgeSelectable, int num,
			sgs::ConstData::HeroSkill skill);

private:
	bool canRejudgeSishu();
	bool canRejudgeShandian();
	bool canRejudgeBagua();
	bool canRejudgeTieqi();
	bool canRejudgeLuoshen();
	bool canRejudgeGanglie();
	int rejudgeCardNum;
	sgs::Derive::MJudge * judgeMessage;
};

} /* namespace sgsai */
#endif /* SGSAI_AISIMAYI_H_ */
