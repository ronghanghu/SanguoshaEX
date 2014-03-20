/*
 * sgsui_MessageBox.h
 *
 *  Created on: Mar 25, 2012
 *      Author: latios
 */

#ifndef SGSUI_MESSAGEBOX_H_
#define SGSUI_MESSAGEBOX_H_

#include "sgsui_GUIStaticData.h"
#include <QLabel>

class QGraphicsOpacityEffect;

namespace sgsui {

class MessageBox: public QLabel {
Q_OBJECT
public:
	explicit MessageBox(QWidget* parent = 0);

public slots:
	void showTipMessage(const QString &tip, bool richText = false,
			int duration = GUIStaticData::showTipDuration);
	void showPauseMessage(const QString &pauseText, bool richText = false);

private slots:
	void startFading();
	void fading();

private:
	qreal opacity;
	QTimer * showTextTimer;
	QTimer * fadeTimer;
	QGraphicsOpacityEffect * tipEffect;
	int textDuration;

	const static QSize fixedSize;
};

} /* namespace sgsui */
#endif /* SGSUI_MESSAGEBOX_H_ */
