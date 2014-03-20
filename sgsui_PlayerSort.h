/*
 * sgsui_PlayerSort.h
 *
 *  Created on: Jun 27, 2012
 *      Author: latios
 */

#ifndef SGSUI_PLAYERSORT_H_
#define SGSUI_PLAYERSORT_H_

#include "sgsdata_player.h"

namespace sgs {
namespace DataType {
class Player;
}
}

namespace sgsui {

enum ArrangeType {
	BySeat, ByThreat
};

class PlayerSort {
public:
	PlayerSort(int _mySeat, ArrangeType _arrangeType);
	bool operator()(sgs::DataType::Player * player1,
			sgs::DataType::Player * player2) const;

private:
	const int mySeat;
	const ArrangeType arrangeType;
	const sgs::DataType::Player * const myself;
};

inline int threatingIndex(const sgs::DataType::Player * myself,
		const sgs::DataType::Player * player) {

	// to accelerate sort, don't check whether the point is 0
	using namespace sgs::ConstData;
	PlayerRole myRole = myself->role(), playerRole = player->role();
	int threat = 0;
	switch (myRole) {
	case ZHU:
	case ZHONG:
		switch (playerRole) {
		case ZHU:
			threat = -200;
			break;
		case ZHONG:
			threat = -100;
			break;
		case FAN:
			threat = 100;
			break;
		case NEI:
			threat = 95;
			break;
		default:
			break;
		}
		break;
	case FAN:
		switch (playerRole) {
		case ZHU:
			threat = 200;
			break;
		case ZHONG:
			threat = 100;
			break;
		case FAN:
			threat = -100;
			break;
		case NEI:
			threat = 95;
			break;
		default:
			break;
		}
		break;
	case NEI:
		switch (playerRole) {
		case ZHU:
			threat = 95;
			break;
		case ZHONG:
			threat = 100;
			break;
		case FAN:
			threat = 100;
			break;
		case NEI:
			threat = -100;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	threat -= myself->distance(player);
	threat -= player->hp();
	return threat;
}

} /* namespace sgsui */
#endif /* SGSUI_PLAYERSORT_H_ */
