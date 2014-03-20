/*
 * sgsui_GameOverBox.cpp
 *
 *  Created on: May 6, 2012
 *      Author: latios
 */

#include "sgsui_GameOverBox.h"
#include "sgsui_MainWindow.h"
#include "sgsui_nameConvert.h"
#include "sgsui_AudioPlayer.h"
#include "sgsui_output.h"

namespace sgsui {

const QSize GameOverBox::fixedSize(1024, 400);

GameOverBox::GameOverBox(QWidget * parent) :
		BlockingFrame(parent) {
	setupUi(this);
	setFixedSize(fixedSize);
	setStyleSheet(
			"QFrame#GameOverBox{background-image:url(images/frame/wujiangChooseBox.png)}");

	roleLabelVec.push_back(playerRole1);
	roleLabelVec.push_back(playerRole2);
	roleLabelVec.push_back(playerRole3);
	roleLabelVec.push_back(playerRole4);
	roleLabelVec.push_back(playerRole5);
	roleLabelVec.push_back(playerRole6);
	roleLabelVec.push_back(playerRole7);
	roleLabelVec.push_back(playerRole8);

	resultPixmapVec.push_back(playerPixmap1);
	resultPixmapVec.push_back(playerPixmap2);
	resultPixmapVec.push_back(playerPixmap3);
	resultPixmapVec.push_back(playerPixmap4);
	resultPixmapVec.push_back(playerPixmap5);
	resultPixmapVec.push_back(playerPixmap6);
	resultPixmapVec.push_back(playerPixmap7);
	resultPixmapVec.push_back(playerPixmap8);

	resultLabelVec.push_back(playerResult1);
	resultLabelVec.push_back(playerResult2);
	resultLabelVec.push_back(playerResult3);
	resultLabelVec.push_back(playerResult4);
	resultLabelVec.push_back(playerResult5);
	resultLabelVec.push_back(playerResult6);
	resultLabelVec.push_back(playerResult7);
	resultLabelVec.push_back(playerResult8);

	resultFrameVec.push_back(resultFrame1);
	resultFrameVec.push_back(resultFrame2);
	resultFrameVec.push_back(resultFrame3);
	resultFrameVec.push_back(resultFrame4);
	resultFrameVec.push_back(resultFrame5);
	resultFrameVec.push_back(resultFrame6);
	resultFrameVec.push_back(resultFrame7);
	resultFrameVec.push_back(resultFrame8);

	for (std::vector<QLabel *>::iterator iter = roleLabelVec.begin();
			iter != roleLabelVec.end(); ++iter) {
		(*iter)->setFont(GUIStaticData::contentFont);
	}
	for (std::vector<QLabel *>::iterator iter = resultLabelVec.begin();
			iter != resultLabelVec.end(); ++iter) {
		(*iter)->setFont(GUIStaticData::contentFont);
	}
	for (std::vector<QFrame *>::iterator iter = resultFrameVec.begin();
			iter != resultFrameVec.end(); ++iter) {
		(*iter)->hide();
	}

	wonLabel->hide();
	lostLabel->hide();

	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	okButton->setDisabledPixmap(QPixmap("images/button/ok-disabled.png"));
	connect(okButton, SIGNAL(clicked()), this, SLOT(unblock()));
}

void GameOverBox::enterKeyPressedEvent() {
	unblock();
}

void GameOverBox::showResult(char result) {
	GUIStaticData::setGameOver();
	MainWindow * mainWindowPtr = static_cast<MainWindow *>(window());
	_result = result;
	for (int i = 0; i < mainWindowPtr->playerCount; ++i) {
		roleLabelVec.at(i)->setText(
				setColored(
						roleDisplayName(mainWindowPtr->getRoleAtIndex(i + 1)),
						false));
		resultPixmapVec.at(i)->showResult(
				mainWindowPtr->getHeroTypeAtIndex(i + 1),
				mainWindowPtr->getIsDeadAtIndex(i + 1));
		resultLabelVec.at(i)->setText(
				setColored(resultDisplayStr(getResult(i + 1)), false));
		resultFrameVec.at(i)->show();
	}
	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));

	if (getResult(mainWindowPtr->playerIndex)) {
		mainWindowPtr->audioPlayer->playEndingMusic(true);
		wonLabel->show();
	} else {
		mainWindowPtr->audioPlayer->playEndingMusic(false);
		lostLabel->show();
	}

	exec();
	// now InitiateBox will determinate whether to quit or to play again
}

bool GameOverBox::getResult(int Index) {
	--Index;
	return (_result >> Index) & 1;
}

} /* namespace sgsui */
