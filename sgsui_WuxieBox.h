/*
 * sgsui_WuxieBox.h
 *
 *  Created on: Jun 30, 2012
 *      Author: latios
 */

#ifndef SGSUI_WUXIEBOX_H_
#define SGSUI_WUXIEBOX_H_

#include "sgsui_MessageBox.h"

namespace sgsui {

class WuxieBox: protected MessageBox {
public:
	WuxieBox(QWidget *parent = 0);
};

} /* namespace sgsui */
#endif /* SGSUI_WUXIEBOX_H_ */
