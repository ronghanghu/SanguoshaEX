/*
 * sgsui_WugufengdengBox.cpp
 *
 *  Created on: May 3, 2012
 *      Author: latios
 */

#include "sgsui_WugufengdengBox.h"
#include "sgsui_MainWindow.h"
#include "sgsui_CardButton.h"
#include "sgsui_nameConvert.h"
#include "sgsui_output.h"

namespace sgsui {

const QSize WugufengdengBox::fixedSize(460, 360);
const QSize WugufengdengBox::buttonSize(93, 170);
const QPoint WugufengdengBox::cardPoint0(31, -4);
const QPoint WugufengdengBox::cardPoint1(133, -4);
const QPoint WugufengdengBox::cardPoint2(235, -4);
const QPoint WugufengdengBox::cardPoint3(337, -4);
const QPoint WugufengdengBox::cardPoint4(31, 134);
const QPoint WugufengdengBox::cardPoint5(133, 134);
const QPoint WugufengdengBox::cardPoint6(235, 134);
const QPoint WugufengdengBox::cardPoint7(337, 134);

WugufengdengBox::WugufengdengBox(QWidget *parent) :
		BlockingFrame(parent), isChoosing(false), returnValue(-1) {
	setupUi(this);
	setFixedSize(fixedSize);
	setStyleSheet(
			"QFrame#WugufengdengBox{background-image:url(images/frame/wuguBox.png)}");

	points[0] = &cardPoint0;
	points[1] = &cardPoint1;
	points[2] = &cardPoint2;
	points[3] = &cardPoint3;
	points[4] = &cardPoint4;
	points[5] = &cardPoint5;
	points[6] = &cardPoint6;
	points[7] = &cardPoint7;

	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	okButton->setDisabledPixmap(QPixmap("images/button/ok-disabled.png"));
	okButton->setDisabled();

	for (int i = 0; i < 8; ++i) {
		bigFrame[i] = new QFrame(this);
		bigFrame[i]->setFixedSize(buttonSize);
		bigFrame[i]->move(*points[i]);
		buttons[i] = 0;
	}
	connect(okButton, SIGNAL(clicked()), this, SLOT(unblock()));
}

void WugufengdengBox::showContainer(
		const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wugoInfo) {
	printDebug("WugufengdengBox::showContainer: start");
	if (isVisible()) {
		printDebug(
				"WugufengdengBox::showContainer: the window is already visible, quit");
		printDebug("WugufengdengBox::showContainer: over");
		return;
	}

	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));

	int i = 0;
	CardButton *newButton = 0;
	for (std::vector<std::pair<const sgs::DataType::Card *, bool> >::const_iterator citer =
			wugoInfo.begin(); citer != wugoInfo.end(); ++citer, ++i) {
		newButton = new CardButton((*citer).first, this, true, bigFrame[i]);
		buttons[i] = newButton;
		newButton->show();
	}
	show();
	printDebug("WugufengdengBox::showContainer: over");
}

QPoint WugufengdengBox::removeCard(int index) {
	printDebug("WugufengdengBox::removeCard: start");
	QPoint position;
	if (buttons[index]) {
		position = (MainWindow::realPos(buttons[index]));
		delete buttons[index];
		buttons[index] = 0;
	} else {
		printDebug(
				"<font color=red><b>Warning: </b></font>WugufengdengBox::removeCard: removing a non-exist card, index = "
						+ QString::number(index));
	}
	if (isEmpty()) {
		printDebug("WugufengdengBox::removeCard: all cards removed, close");
		close();
	}

	printDebug("WugufengdengBox::removeCard: over");
	return position;
}

int WugufengdengBox::chooseWugu(
		const std::vector<std::pair<const sgs::DataType::Card *, bool> >& wugoInfo) {
	printDebug("WugufengdengBox::chooseWugu: start");
	returnValue = -1;
	isChoosing = true;

	// don't hide after response
	exec(false);

	collectData();
	isChoosing = false;
	okButton->setDisabled();

	printDebug(
			"WugufengdengBox::chooseWugu: chosen card pos = "
					+ QString::number(returnValue));

	if (wugoInfo.at(returnValue).second) {
		printDebug(
				"<font color=red><b>Warning: </b></font>WugufengdengBox::chooseWugu: choosing a card which is already chosen, check bug");
	}
	printDebug("WugufengdengBox::chooseWugu: over");
	return returnValue;
}

void WugufengdengBox::collectData() {

	// pick out the selected card
	for (int i = 0; i < 8; ++i) {
		if (buttons[i] && buttons[i]->isSelected()) {
			returnValue = i;
			break;
		}
	}

	// reset all other cards
	for (int i = 0; i < 8; ++i) {
		if (buttons[i]) {
			buttons[i]->setUnselected();
			buttons[i]->setSelectable();
		}
	}
}

void WugufengdengBox::cardClicked(CardButton* clickedCard) {
	if (!isChoosing)
		return;

	if (!clickedCard->isSelected()) {

		// if the clicked card is not selected before click
		// set this card selected and others unselected (but still selectable)
		// set ok button enabled
		for (int i = 0; i < 8; ++i) {
			if (buttons[i]) {
				if (buttons[i] == clickedCard) {
					buttons[i]->setSelected();
					okButton->setEnabled();
				} else {
					buttons[i]->setUnselectable();
				}
			}
		}
	} else {

		// if the clicked card is already selected before click
		// set this card unselected and all cards selectable
		// set ok button disabled
		clickedCard->setUnselected();
		for (int i = 0; i < 8; ++i) {
			if (buttons[i]) {
				buttons[i]->setSelectable();
			}
		}
		okButton->setDisabled();
	}
}

bool WugufengdengBox::isEmpty() const {
	for (int i = 0; i < 8; ++i) {
		if (buttons[i]) {
			return false;
		}
	}
	return true;
}

void WugufengdengBox::enterKeyPressedEvent() {
	okButton->click();
}

} /* namespace sgsui */
