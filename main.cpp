/*
 * main.cpp
 *
 *  Created on: Feb 26, 2012
 *      Author: latios
 */

#include "sgsui_InitiateBox.h"
#include <QApplication>
#include <ctime>
#include <cstdlib>

int main(int argc, char** argv) {
	srand(static_cast<unsigned>(time(0)));
	QApplication app(argc, argv);
	sgsui::InitiateBox * initiateBox = new sgsui::InitiateBox();
	initiateBox->show();
	return app.exec();
}
