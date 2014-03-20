/*
 * sgsui_MessageBox.cpp
 *
 *  Created on: Mar 25, 2012
 *      Author: latios
 */

#include "sgsui_MessageBox.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_nameConvert.h"
#include <QtGui>

namespace sgsui {

const QSize MessageBox::fixedSize(480, 200);

MessageBox::MessageBox(QWidget* parent) :
		QLabel(parent) {
	setObjectName("MessageBox");
	setStyleSheet(
			"QLabel#MessageBox{background-image:url(images/frame/tip.png)}");
	setFixedSize(fixedSize);
	setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	setFont(GUIStaticData::headingFont);
	setWordWrap(true);
	setMargin(20);

	tipEffect = new QGraphicsOpacityEffect(this);
	showTextTimer = new QTimer(this);
	showTextTimer->setSingleShot(true);
	fadeTimer = new QTimer(this);

	connect(showTextTimer, SIGNAL(timeout()), this, SLOT(startFading()));
	connect(fadeTimer, SIGNAL(timeout()), this, SLOT(fading()));
}

void MessageBox::showTipMessage(const QString &tip, bool richText,
		int duration) {
	textDuration =
			(duration > GUIStaticData::dialogFadeDuration) ?
					duration : GUIStaticData::showTipDuration;
	opacity = 1;
	tipEffect->setOpacity(opacity);
	setGraphicsEffect(tipEffect);

	if (richText) {
		setText(tip);
	} else {
		setText(setColored(tip));
	}

	show();
	raise();
	fadeTimer->stop();
	showTextTimer->start(textDuration);
}

void MessageBox::showPauseMessage(const QString &pauseText, bool richText) {
	if (richText) {
		setText(pauseText);
	} else {
		setText(setColored(pauseText));
	}
	show();
	raise();
}

void MessageBox::startFading() {
	opacity = 1;
	fadeTimer->start(GUIStaticData::dialogFadeDuration / 10);
}

void MessageBox::fading() {
	if (opacity > 0) {
		tipEffect->setOpacity(opacity);
		setGraphicsEffect(tipEffect);
		opacity -= 0.1;
	} else {
		fadeTimer->stop();
		opacity = 0;
		hide();
	}
}

} /* namespace sgsui */
