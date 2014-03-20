/*
 * sgsui_BlockingFrame.h
 *
 *  Created on: Apr 6, 2012
 *      Author: latios
 */

#ifndef SGSUI_BLOCKINGFRAME_H_
#define SGSUI_BLOCKINGFRAME_H_

#include <QFrame>
#include "sgsui_BlockLoop.h"

class QGraphicsOpacityEffect;
class QTimer;

namespace sgsui {

class BlockingFrame: public QFrame {
Q_OBJECT
public:
	explicit BlockingFrame(QWidget *parent = 0);
	virtual void enterKeyPressedEvent(); // this function should be overrided by any child class that need to process Enter key
	virtual void escapeKeyPressedEvent(); // this function should be overrided by any child class that need to process ESC key
	virtual ~BlockingFrame() {
	}

protected slots:
	void exec(bool hide = true);
	void unblock();

private:
	BlockLoop blockLoop;
};

} /* namespace sgsui */
#endif /* SGSUI_BLOCKINGFRAME_H_ */
