/*
 * sgsui_HelpBox.cpp
 *
 *  Created on: May 10, 2012
 *      Author: latios
 */

#include "sgsui_HelpBox.h"
#include "sgsui_GUIStaticData.h"

namespace sgsui {

const QSize HelpBox::fixedSize(1024, 600);

HelpBox::HelpBox(QWidget * parent) :
		BlockingFrame(parent) {
	setupUi(this);
	setFixedSize(fixedSize);
	setStyleSheet(
			"QFrame#HelpBox{background-image:url(images/frame/helpBox.png)}");

	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	helpText->setSource(GUIStaticData::helpTextLocation);
	connect(okButton, SIGNAL(clicked()), this, SLOT(unblock()));
}

void HelpBox::enterKeyPressedEvent() {
	unblock();
}

void HelpBox::escapeKeyPressedEvent() {
	unblock();
}

void HelpBox::displayHelp() {
	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2 - 40),
					size()));
	exec();
}

} /* namespace sgsui */
