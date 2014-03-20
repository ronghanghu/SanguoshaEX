/*
 * sgsui_GameButton.cpp
 *
 *  Created on: Mar 20, 2012
 *      Author: latios
 */

#include "sgsui_GameButton.h"
#include "sgsui_GUIStaticData.h"
#include <QtGui>
#include <QMouseEvent>

namespace sgsui {

GameButton::GameButton(QWidget *parent, bool enable,
		const QPixmap& enabledPixmap, const QPixmap& disabledPixmap,
		const QPixmap& pressedPixmap) :
		QLabel(parent), buttonEnabledPixmap(enabledPixmap), buttonDisabledPixmap(
				disabledPixmap), buttonPressedPixmap(pressedPixmap), buttonEnabled(
				enable), isPressed(false) {
	setFixedSize(enabledPixmap.size());
	setFont(GUIStaticData::buttonFont);
	setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

void GameButton::click() {
	QMouseEvent temp(QEvent::MouseButtonRelease,
			QPoint(width() / 2, height() / 2), Qt::LeftButton, Qt::LeftButton,
			Qt::NoModifier);
	mousePressEvent(&temp);
	mouseReleaseEvent(&temp);
}

bool GameButton::isEnabled() {
	return buttonEnabled;
}

void GameButton::setEnabled(bool enabled) {
	if (buttonEnabled != enabled) {
		buttonEnabled = enabled;
		update();
	}
}

void GameButton::setDisabled(bool disabled) {
	setEnabled(!disabled);
}

void GameButton::setEnabledPixmap(const QPixmap& enabledPixmap) {
	buttonEnabledPixmap = enabledPixmap;
	if (buttonEnabled) {
		setFixedSize(buttonEnabledPixmap.size());
		update();
	}
}

void GameButton::setPressedPixmap(const QPixmap& pressedPixmap) {
	buttonPressedPixmap = pressedPixmap;
}

void GameButton::setDisabledPixmap(const QPixmap& disabledPixmap) {
	buttonDisabledPixmap = disabledPixmap;
	if (!buttonEnabled) {
		setFixedSize(buttonDisabledPixmap.size());
		update();
	}
}

void GameButton::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	painter.drawPixmap(
			0,
			0,
			buttonEnabled ?
					(isPressed ? buttonPressedPixmap : buttonEnabledPixmap) :
					buttonDisabledPixmap);
	QLabel::paintEvent(event);
}

void GameButton::mousePressEvent(QMouseEvent *event) {
	if (buttonEnabled && event->button() == Qt::LeftButton) {
		isPressed = true;
		move(x(), y() + 2);
		update();
	}
}

void GameButton::mouseReleaseEvent(QMouseEvent *event) {
	if (buttonEnabled && event->button() == Qt::LeftButton) {
		isPressed = false;
		move(x(), y() - 2);
		update();
		if (event->pos().x() >= -1 && event->pos().x() <= width() + 1
				&& event->pos().y() >= -1 && event->pos().y() <= height() + 1) {
			emit clicked();
		}
	}
}

} /* namespace sgsui */
