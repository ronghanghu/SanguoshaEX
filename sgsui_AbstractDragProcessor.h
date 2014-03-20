/*
 * sgsui_AbstractDragProcessor.h
 *
 *  Created on: Apr 5, 2012
 *      Author: latios
 */

#ifndef SGSUI_ABSTRACTDRAGPROCESSOR_H_
#define SGSUI_ABSTRACTDRAGPROCESSOR_H_

namespace sgsui {

class DragableCardFrame;

class AbstractDragProcessor {
public:
	virtual QPoint processDrag(DragableCardFrame * card) = 0;
	virtual ~AbstractDragProcessor() {
	}
};

} /* namespace sgsui */
#endif /* SGSUI_ABSTRACTDRAGPROCESSOR_H_ */
