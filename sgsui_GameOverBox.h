/*
 * sgsui_GameOverBox.h
 *
 *  Created on: May 6, 2012
 *      Author: latios
 */

#ifndef SGSUI_GAMEOVERBOX_H_
#define SGSUI_GAMEOVERBOX_H_

#include "ui_GameOverBox.h"
#include "sgsui_BlockingFrame.h"
#include <vector>

class QLabel;
class QFrame;

namespace sgsui {

class ResultPlayerLabel;

class GameOverBox: public BlockingFrame, protected Ui::GameOverBox {
public:
	explicit GameOverBox(QWidget * parent = 0);
	void showResult(char result);
	virtual void enterKeyPressedEvent();

private:
	bool getResult(int Index);

	char _result;

	const static QSize fixedSize;
	std::vector<QLabel *> roleLabelVec;
	std::vector<ResultPlayerLabel *> resultPixmapVec;
	std::vector<QLabel *> resultLabelVec;
	std::vector<QFrame *> resultFrameVec;
};

} /* namespace sgsui */
#endif /* SGSUI_GAMEOVERBOX_H_ */
