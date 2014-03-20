/*
 * sgsui_GameButton.h
 *
 *  Created on: Mar 20, 2012
 *      Author: latios
 */

#ifndef SGSUI_GAMEBUTTON_H_
#define SGSUI_GAMEBUTTON_H_

#include <QLabel>

namespace sgsui {

class GameButton: public QLabel {
	Q_OBJECT
public:
	GameButton(
			QWidget *parent,
			bool enable = true,
			const QPixmap& enabledPixmap = QPixmap("images/button/enabled.png"),
			const QPixmap& disabledPixmap = QPixmap(
					"images/button/disabled.png"),
			const QPixmap& pressedPixmap = QPixmap(
					"images/button/pressed.png"));
	bool isEnabled();
	void click();

	signals:
	void clicked();

public slots:
	void setEnabled(bool enabled = true);
	void setDisabled(bool disabled = true);
	void setEnabledPixmap(const QPixmap& enabledPixmap);
	void setPressedPixmap(const QPixmap& pressedPixmap);
	void setDisabledPixmap(const QPixmap& disabledPixmap);

protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);

	QPixmap buttonEnabledPixmap;
	QPixmap buttonDisabledPixmap;
	QPixmap buttonPressedPixmap;
	bool buttonEnabled;
	bool isPressed;
};

} /* namespace sgsui */
#endif /* SGSUI_GAMEBUTTON_H_ */
