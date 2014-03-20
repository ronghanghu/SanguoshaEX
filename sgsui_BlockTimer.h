/*
 * sgsui_BlockTimer.h
 *
 *  Created on: May 3, 2012
 *      Author: latios
 */

#ifndef SGSUI_BLOCKTIMER_H_
#define SGSUI_BLOCKTIMER_H_

#include <QObject>
#include "sgsui_BlockLoop.h"

class QTimer;

namespace sgsui {

class BlockTimer: public QObject {
Q_OBJECT
public:
	explicit BlockTimer(QObject *parent);
	virtual ~BlockTimer();
	void block(int blockTime);

private slots:
	void unblock();

private:
	QTimer * blockTimer;
	BlockLoop blockLoop;
};

} /* namespace sgsui */
#endif /* SGSUI_BLOCKTIMER_H_ */
