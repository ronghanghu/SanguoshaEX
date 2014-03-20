/*
 * sgsui_output.h
 *
 *  Created on: Mar 25, 2012
 *      Author: latios
 */

#ifndef SGSUI_OUTPUT_H_
#define SGSUI_OUTPUT_H_

#include <QString>

namespace sgsui {

void printDebug(const QString& textInput);
void printHistory(const QString& textInput);
void printInitiateMessage();
void printEndingMessage();

} /* namespace sgsui */

using sgsui::printDebug;

#endif /* SGSUI_OUTPUT_H_ */
