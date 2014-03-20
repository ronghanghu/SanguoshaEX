/*
 * sgsui_BlockLoop.h
 *
 *  Created on: May 31, 2012
 *      Author: latios
 */

#ifndef SGSUI_BLOCKLOOP_H_
#define SGSUI_BLOCKLOOP_H_

#include <QEventLoop>
#include <list>

namespace sgsui {

class BlockLoop {
public:
	void exec();
	bool isRunning() const;
	void quit();
	static void terminateAllLoops();

private:
	QEventLoop blocker;

	static std::list<QEventLoop *> blockLoopList;
	static bool isTerminated;
};

} /* namespace sgsui */
#endif /* SGSUI_BLOCKLOOP_H_ */
