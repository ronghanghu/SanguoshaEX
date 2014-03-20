/*
 * sgsui_output.cpp
 *
 *  Created on: Mar 25, 2012
 *      Author: latios
 */

#include "sgsui_output.h"
#include "sgsui_MainWindow.h"
#include "sgsui_GUIStaticData.h"
#include <QtGui>
#include <cstdio>

namespace sgsui {

QFile debugLog("debug_log.html");
QFile historyLog("history_log.html");
QTextStream debugStream(&debugLog);
QTextStream historyStream(&historyLog);
//QTextStream debugStream(stdout);

void printDebug(const QString& textInput) {
	if (GUIStaticData::isDebugLogOn()) {
		debugLog.open(
				QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
		debugStream << QDateTime::currentDateTime().toString() << " ";
		debugStream << textInput << "<br />" << endl;
		debugLog.close();
		MainWindow::appendDebug(textInput);
	}
}

void printHistory(const QString& textInput) {
	if (GUIStaticData::isDebugLogOn()) {
		historyLog.open(
				QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
		historyStream << QDateTime::currentDateTime().toString() << " "
				<< textInput << "<br />" << endl;
		historyLog.close();
	}
	MainWindow::appendHistory(textInput);
}

void printInitiateMessage() {
	if (GUIStaticData::isDebugLogOn()) {
		debugLog.open(QIODevice::WriteOnly | QIODevice::Text);
		debugStream
				<< "<html><head>"
				<< "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">"
				<< "<title>SanguoshaEX - Debug Log</title></head>";
		debugStream << "<body>New Game Started ("
				<< QDateTime::currentDateTime().toString() << ")<br />" << endl;
		debugLog.close();

		historyLog.open(QIODevice::WriteOnly | QIODevice::Text);
		historyStream
				<< "<html><head>"
				<< "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">"
				<< "<title>SanguoshaEX - History Log</title></head>";
		historyStream << "<body>New Game Started ("
				<< QDateTime::currentDateTime().toString() << ")<br />" << endl;
		historyLog.close();
	}
}

void printEndingMessage() {
	if (GUIStaticData::isDebugLogOn()) {
		debugLog.open(
				QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
		debugStream << "Game is Over ("
				<< QDateTime::currentDateTime().toString()
				<< ")<br /></body></html>" << endl;
		debugLog.close();

		historyLog.open(
				QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
		historyStream << "Game is Over ("
				<< QDateTime::currentDateTime().toString()
				<< ")<br /></body></html>" << endl;
		historyLog.close();
	}
}

} /* namespace sgsui */
