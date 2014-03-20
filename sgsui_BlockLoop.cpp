/*
 * sgsui_BlockLoop.cpp
 *
 *  Created on: May 31, 2012
 *      Author: latios
 */

#include "sgsui_BlockLoop.h"
#include "sgsui_output.h"
#include <iostream>

namespace sgsui {

std::list<QEventLoop *> BlockLoop::blockLoopList;
bool BlockLoop::isTerminated = false;

void BlockLoop::exec() {
	blockLoopList.push_back(&blocker);
	blocker.exec();
	if (isTerminated) {
		// this code is to make the thread sleep with little CPU cost
		while (true) {
			std::cin.get();
		}
	} else {
		blockLoopList.remove(&blocker);
	}
}

bool BlockLoop::isRunning() const {
	return blocker.isRunning();
}

void BlockLoop::quit() {
	blocker.quit();
}

void BlockLoop::terminateAllLoops() {
	isTerminated = true;
	for (std::list<QEventLoop *>::iterator iter = blockLoopList.begin();
			iter != blockLoopList.end(); ++iter) {
		(*iter)->quit();
	}
	printDebug("BlockLoop::terminateAllLoops: all loops terminated");
}

} /* namespace sgsui */
