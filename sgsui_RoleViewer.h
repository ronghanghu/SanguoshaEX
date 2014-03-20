/*
 * sgsui_RoleViewer.h
 *
 *  Created on: Jul 4, 2012
 *      Author: latios
 */

#ifndef SGSUI_ROLEVIEWER_H_
#define SGSUI_ROLEVIEWER_H_

#include "ui_RoleViewer.h"

namespace sgsui {

class RoleViewer: public QWidget, protected Ui::RoleViewer {
public:
	RoleViewer(QWidget *parent = 0);
};

} /* namespace sgsui */
#endif /* SGSUI_ROLEVIEWER_H_ */
