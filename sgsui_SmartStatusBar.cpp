/*
 * sgsui_SmartStatusBar.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: latios
 */

#include "sgsui_SmartStatusBar.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_nameConvert.h"
#include <QtGui>

namespace sgsui {

const int SmartStatusBar::fixedHeight = 20;

SmartStatusBar::SmartStatusBar(QWidget *parent) :
		QLabel(parent) {
	setFixedHeight(fixedHeight);
	setFont(GUIStaticData::statusbarFont);
	setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	timer = new QTimer(this);
	timer->setSingleShot(true);
	connect(timer, SIGNAL(timeout()), this, SLOT(clear()));
}

void SmartStatusBar::showStatusBarMessage(const QString &tip, bool richText,
		int duration) {
	if (richText) {
		setText(tip);
	} else {
		setText(setColored(tip, false));
	}

	if (duration > 0) {
		timer->start(duration);
	} else {
		timer->stop();
	}
}

void SmartStatusBar::clearMessage() {
	clear();
}

} /* namespace sgsui */
