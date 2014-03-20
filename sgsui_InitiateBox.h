/*
 * sgsui_InitiateBox.h
 *
 *  Created on: Apr 2, 2012
 *      Author: latios
 */

#ifndef SGSUI_INITIATEBOX_H_
#define SGSUI_INITIATEBOX_H_

#include "ui_InitiateBox.h"

class QCloseEvent;

namespace sgsui {

class RoleViewer;

class InitiateBox: public QDialog, protected Ui::InitiateBox {
	Q_OBJECT
public:
	InitiateBox();
	~InitiateBox();

public slots:
	void start();
	void showRoleViewer();

private:
	void closeEvent(QCloseEvent *event);
	void keyPressEvent(QKeyEvent *event);

	const static QSize fixedSize;
	const static QString playAgain;

	RoleViewer * roleViewer;
};

} /* namespace sgsui */
#endif /* SGSUI_INITIATEBOX_H_ */
