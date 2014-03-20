/*
 * sgsui_AboutFrame.h
 *
 *  Created on: Apr 7, 2012
 *      Author: latios
 */

#ifndef SGSUI_ABOUTFRAME_H_
#define SGSUI_ABOUTFRAME_H_

#include "sgsui_BlockingFrame.h"
#include "ui_AboutFrame.h"

namespace sgsui {

class AboutFrame: public BlockingFrame, protected Ui::AboutFrame {
Q_OBJECT
public:
	explicit AboutFrame(QWidget *parent = 0);
	void enterKeyPressedEvent();
	void escapeKeyPressedEvent();

public slots:
	void showAboutInfo();

private:
	static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_ABOUTFRAME_H_ */
