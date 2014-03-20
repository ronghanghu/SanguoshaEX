/*
 * sgsui_Outstream.cpp
 *
 *  Created on: Jun 1, 2012
 *      Author: latios
 */

#include "sgsui_Outstream.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_MainWindow.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"
#include "sgsdata_enum.h"
#include "sgsdata_msg.h"

namespace sgsui {

Outstream& Outstream::operator<<(int) {
	if (!GUIStaticData::isPlayersCreated()) {
		MainWindow::mainWindowPtr()->createPlayers();
	} else
		printDebug(
				"<font color=red><b>Warning: </b></font>Outstream::operator<<: calling refresh all when the players have already been created");
	printDebug("Outstream::operator<<: sgsout-over");
	if (MainWindow::mainWindowPtr()->isSingleStep()) {
		printDebug(
				"<font color=red><b>Notice: </b></font>Outstream::operator<<: pause game due to single step debug");
		MainWindow::mainWindowPtr()->pause();
	}
	return *this;
}

Outstream& Outstream::operator<<(const sgs::DataType::Message * message) {
	printDebug("Outstream::operator<<: sgsout-start");
	if (!GUIStaticData::isPlayersCreated()) {
		printDebug(
				"<font color=red><b>Warning: </b></font>Outstream::operator<<: calling operator<< when the players have not been created");
		MainWindow::mainWindowPtr()->createPlayers();
	}

	using namespace sgs::Derive;
	switch (message->type()) {
	case sgs::ConstData::HITCARD:
		printDebug("Outstream::operator<<: HITCARD message received");
		printDebug(messageInterpret(static_cast<const MCard *>(message)));
		MainWindow::mainWindowPtr()->MCardReceived(
				static_cast<const MCard *>(message));
		break;
	case sgs::ConstData::USECARD:
		printDebug("Outstream::operator<<: USECARD message received");
		printDebug(messageInterpret(static_cast<const MCard *>(message)));
		MainWindow::mainWindowPtr()->MCardReceived(
				static_cast<const MCard *>(message));
		break;
		// TODO revise it later
	case sgs::ConstData::USESKILL:
		printDebug("Outstream::operator<<: USESKILL message received");
		printDebug(messageInterpret(static_cast<const MSkill *>(message)));
		MainWindow::mainWindowPtr()->MSkillReceived(
				static_cast<const MSkill *>(message));
		break;
	case sgs::ConstData::HURT:
		printDebug("Outstream::operator<<: HURT message received");
		printDebug(messageInterpret(static_cast<const MHurt *>(message)));
		MainWindow::mainWindowPtr()->MHurtReceived(
				static_cast<const MHurt *>(message));
		break;
	case sgs::ConstData::TRANSCARD:
		printDebug("Outstream::operator<<: TRANSCARD message received");
		printDebug(messageInterpret(static_cast<const MTransCard *>(message)));
		MainWindow::mainWindowPtr()->MTransCardReceived(
				static_cast<const MTransCard *>(message));
		break;
	case sgs::ConstData::SWITCHPHASE:
		printDebug("Outstream::operator<<: SWITCHPHASE message received");
		printDebug(
				messageInterpret(static_cast<const MSwitchPhase *>(message)));
		MainWindow::mainWindowPtr()->MSwitchPhaseReceived(
				static_cast<const MSwitchPhase *>(message));
		break;
	case sgs::ConstData::DYING:
		printDebug("Outstream::operator<<: DYING message received");
		printDebug(messageInterpret(static_cast<const MDying *>(message)));
		MainWindow::mainWindowPtr()->MDyingReceived(
				static_cast<const MDying *>(message));
		break;
	case sgs::ConstData::KILL:
		printDebug("Outstream::operator<<: KILL message received");
		printDebug(messageInterpret(static_cast<const MKill *>(message)));
		MainWindow::mainWindowPtr()->MKillReceived(
				static_cast<const MKill *>(message));
		break;
	case sgs::ConstData::JUDGE:
		printDebug("Outstream::operator<<: JUDGE message received");
		printDebug(messageInterpret(static_cast<const MJudge *>(message)));
		MainWindow::mainWindowPtr()->MJudgeReceived(
				static_cast<const MJudge *>(message));
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>Outstream::operator<<: Invalid Display Type");
		break;
	}
	printDebug("Outstream::operator<<: sgsout-over");
	if (MainWindow::mainWindowPtr()->isSingleStep()) {
		printDebug(
				"<font color=red><b>Notice: </b></font>Outstream::operator<<: pause game due to single step debug");
		MainWindow::mainWindowPtr()->pause();
	}

	return *this;
}

} /* namespace sgsui */
