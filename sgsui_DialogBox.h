/*
 * sgsui_DialogBox.h
 *
 *  Created on: Apr 3, 2012
 *      Author: latios
 */

#ifndef SGSUI_DIALOGBOX_H_
#define SGSUI_DIALOGBOX_H_

#include "ui_DialogBox.h"
#include "sgsui_BlockingFrame.h"
#include "sgsui_MainWindow.h"

namespace sgsui {

class DialogBox: public BlockingFrame, protected Ui::DialogBox {
Q_OBJECT
public:
	explicit DialogBox(QWidget *parent = 0);
	void enterKeyPressedEvent();
	void escapeKeyPressedEvent();
	int exec(const QString &message);

private slots:
	void accept();
	void reject();

private:
	int returnValue;

	const static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_DIALOGBOX_H_ */
