/*
 * sgsui_AboutFrame.cpp
 *
 *  Created on: Apr 7, 2012
 *      Author: latios
 */

#include "sgsui_AboutFrame.h"
#include "sgsui_GUIStaticData.h"

namespace sgsui {

QSize AboutFrame::fixedSize(560, 346);

AboutFrame::AboutFrame(QWidget *parent) :
		BlockingFrame(parent) {
	setupUi(this);

	setFixedSize(fixedSize);

	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	setStyleSheet(
			"QFrame#AboutFrame{background-image:url(images/frame/aboutFrame.png)}");

	aboutText->setSource(GUIStaticData::aboutTextLocation);
	connect(okButton, SIGNAL(clicked()), this, SLOT(unblock()));
}

void AboutFrame::enterKeyPressedEvent() {
	okButton->click();
}

void AboutFrame::escapeKeyPressedEvent() {
	okButton->click();
}

void AboutFrame::showAboutInfo() {
	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2 - 40),
					size()));
	exec();
}

} /* namespace sgsui */
