/*
 * sgsui_PlayerSort.cpp
 *
 *  Created on: Jun 27, 2012
 *      Author: latios
 */

#include "sgsui_PlayerSort.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_output.h"
#include "sgsdata_extern.h"
#include "sgsdata_gamedata.h"

namespace sgsui {

PlayerSort::PlayerSort(int _mySeat, ArrangeType _arrangeType) :
		mySeat(_mySeat), arrangeType(_arrangeType) , myself(sgs::ExternData::gamedata.players(_mySeat)){
}

bool PlayerSort::operator()(sgs::DataType::Player * player1, sgs::DataType::Player * player2) const {
	if (!player1 || !player2) {
		printDebug(
				"<font color=red><b>Warning: </b></font>PlayerSort::operator(): null pointer");
		return false;
	}

	switch (arrangeType) {
	case BySeat: {
		int playerSeat1 = player1->seat(), playerSeat2 = player2->seat();
		if (playerSeat1 < mySeat)
			playerSeat1 += GUIStaticData::getPlayerCount();
		if (playerSeat2 < mySeat)
			playerSeat2 += GUIStaticData::getPlayerCount();
		return (playerSeat1 < playerSeat2);
	}
		break;
	case ByThreat: {
		 //return true means that player1 is less threating than player2

		int threat1 = threatingIndex(myself, player1), threat2 = threatingIndex(myself, player2);
		return threat1 < threat2;
	}
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>PlayerSort::operator(): invalid type");
		return false;
	}
}

} /* namespace sgsui */
