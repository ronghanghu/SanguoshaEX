/*
 * sgsui_DialogBox.cpp
 *
 *  Created on: Apr 3, 2012
 *      Author: latios
 */

#include "sgsui_DialogBox.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"
#include <QtGui>

namespace sgsui {

const QSize DialogBox::fixedSize(480, 200);

DialogBox::DialogBox(QWidget *parent) :
		BlockingFrame(parent), returnValue(-1) {
	setupUi(this);
	setFixedSize(fixedSize);

	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	okButton->setDisabledPixmap(QPixmap("images/button/ok-disabled.png"));
	cancelButton->setEnabledPixmap(QPixmap("images/button/cancel.png"));
	cancelButton->setDisabledPixmap(
			QPixmap("images/button/cancel-disabled.png"));

	setStyleSheet(
			"QFrame#DialogBox{background-image:url(images/frame/dialog.png)}");

	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void DialogBox::enterKeyPressedEvent() {
	okButton->click();
}

void DialogBox::escapeKeyPressedEvent() {
	cancelButton->click();
}

int DialogBox::exec(const QString &message) {
	messageLabel->setText(setColored(message));

	BlockingFrame::exec();
	return returnValue;
}

void DialogBox::accept() {
	returnValue = 1;
	unblock();
}

void DialogBox::reject() {
	returnValue = 0;
	unblock();
}

} /* namespace sgsui */
