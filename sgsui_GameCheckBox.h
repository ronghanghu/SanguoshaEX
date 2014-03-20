/*
 * sgsui_GameCheckBox.h
 *
 *  Created on: Apr 7, 2012
 *      Author: latios
 */

#ifndef SGSUI_GAMECHECKBOX_H_
#define SGSUI_GAMECHECKBOX_H_

#include <QCheckBox>

namespace sgsui {

class GameCheckBox: public QCheckBox {
public:
	GameCheckBox(
			QWidget *parent = 0,
			const QPixmap& noncheckedPixmap = QPixmap(
					"images/button/nonchecked.png"),
			const QPixmap& checkedPixmap = QPixmap(
					"images/button/checked.png"));

private:
	void paintEvent(QPaintEvent *);

	QPixmap _noncheckedPixmap;
	QPixmap _checkedPixmap;
};

} /* namespace sgsui */
#endif /* SGSUI_GAMECHECKBOX_H_ */
