/*
 * sgsui_RoleFrame.h
 *
 *  Created on: Jul 1, 2012
 *      Author: latios
 */

#ifndef SGSUI_ROLEFRAME_H_
#define SGSUI_ROLEFRAME_H_

#include "ui_RoleFrame.h"
#include "sgsdata_enum.h"

namespace sgsui {

class RoleFrame: public QFrame, protected Ui::RoleFrame {
public:
	explicit RoleFrame(QWidget *parent = 0);
	void setupRole(int _zhugongNum, int _zhongchenNum, int _fanzeiNum,
			int _neijianNum);
	void setDead(sgs::ConstData::PlayerRole killedPlayerRole);

private:
	const static QSize fixedSize;
	QLabel *roleLabel[8];
	int zhugongNum;
	int zhongchenNum;
	int fanzeiNum;
	int neijianNum;
	int aliveZhugongNum;
	int aliveZhongchenNum;
	int aliveFanzeiNum;
	int aliveNeijianNum;
};

} /* namespace sgsui */
#endif /* SGSUI_ROLEFRAME_H_ */
