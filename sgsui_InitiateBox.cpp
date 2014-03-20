/*
 * sgsui_InitiateBox.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: latios
 */

#include "sgsui_InitiateBox.h"
#include "sgsui_MainWindow.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_RoleViewer.h"
#include "sgsui_output.h"
#include <exception>
#include <iostream>

typedef char Result_type;
Result_type datamain(int playerNumber);

namespace sgsui {

const QSize InitiateBox::fixedSize(400, 300);
const QString InitiateBox::playAgain(
		trUtf8("\345\206\215\346\235\245\344\270\200\345\261\200"));

InitiateBox::InitiateBox() :
		roleViewer(0) {
	setWindowIcon(QIcon("images/icon.png"));
	setupUi(this);
	setFixedSize(fixedSize);

	QApplication::setApplicationName("SanguoshaEX");
	QApplication::setOverrideCursor(QCursor(QPixmap("images/cursor/1.png")));
    GUIStaticData::loadFonts();
	debugOption->hide();
	connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
	connect(roleButton, SIGNAL(clicked()), this, SLOT(showRoleViewer()));
}

InitiateBox::~InitiateBox() {
	if (roleViewer) {
		delete roleViewer;
	}
}

void InitiateBox::start() {
	if (roleViewer)
		roleViewer->hide();

	int options = 0, package = 0;

	options += musicCheckBox->isChecked();
	options += soundCheckBox->isChecked() << 1;
	options += fullscreenCheckBox->isChecked() << 2;
	options += AICheckBox->isChecked() << 3;

	package += jzpCheckBox->isChecked();
	package += fengCheckBox->isChecked() << 1;
	package += huoCheckBox->isChecked() << 2;
	package += linCheckBox->isChecked() << 3;
	hide();

	GUIStaticData::debugLogOn = debugLogCheckBox->isChecked();
	GUIStaticData::options = options;
	GUIStaticData::package = package;
	GUIStaticData::fullPlayerCount = playerNumSpinBox->value();
	GUIStaticData::humanPlayerIndex = 1;

	sgs::Interface::_maxShaUse =
			shaCheckBox->isChecked() ? -1 : shaSpinBox->value();

	sgsui::printInitiateMessage();
	sgsui::MainWindow * mainWindow = new sgsui::MainWindow();
	printDebug("InitiateBox::start: MainWindow created");
	mainWindow->show();
	printDebug("InitiateBox::start: MainWindow shown, now wait some time");
	mainWindow->sleepSomeTime(GUIStaticData::initWaitTime); // wait for the windows to be fully constructed
	printDebug("InitiateBox::start: about to run datamain");
    Result_type result = 0;
	try {
		result = datamain(sgsui::GUIStaticData::fullPlayerCount); // run the game
	} catch (std::exception& expection) {
		std::cout << "Exception: " << expection.what();
	}

	mainWindow->gameOver(result); // show game result
	delete mainWindow;

	startButton->setText(playAgain);
	show();
}

void InitiateBox::showRoleViewer() {
	if (!roleViewer)
		roleViewer = new RoleViewer();
	roleViewer->show();
}

void InitiateBox::closeEvent(QCloseEvent *event) {
	event->ignore();
	GUIStaticData::quitGame();
}

void InitiateBox::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_D
			&& event->modifiers() == Qt::ControlModifier) {
		debugOption->setHidden(debugOption->isVisible());
	} else {
		QDialog::keyPressEvent(event);
	}
}

} /* namespace sgsui */
