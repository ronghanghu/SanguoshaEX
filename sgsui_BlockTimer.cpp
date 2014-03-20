/*
 * sgsui_BlockTimer.cpp
 *
 *  Created on: May 3, 2012
 *      Author: latios
 */

#include "sgsui_BlockTimer.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_output.h"
#include <QtGui>

namespace sgsui {

BlockTimer::BlockTimer(QObject *parent) :
		QObject(parent) {
	blockTimer = new QTimer(this);
	blockTimer->setSingleShot(true);
	connect(blockTimer, SIGNAL(timeout()), this, SLOT(unblock()));
}

BlockTimer::~BlockTimer() {
}

void BlockTimer::block(int blockTime) {
	if (blockLoop.isRunning()) {
		printDebug(
				"<font color=red><b>Warning: </b></font>BlockTimer::block: it is already blocked");
		return;
	}
	if (blockTime <= 0) {
		printDebug(
				"<font color=red><b>Warning: </b></font>BlockTimer::block: invalid blockTime");
		blockTime = GUIStaticData::basicAnimationDuration;
	}
	blockTimer->start(blockTime);
	printDebug(
			"<font color=red><b>Notice: </b></font>BlockTimer::block: block start");
	blockLoop.exec();
	printDebug(
			"<font color=red><b>Notice: </b></font>BlockTimer::block: block over");
}

void BlockTimer::unblock() {
	blockLoop.quit();
}

} /* namespace sgsui */
