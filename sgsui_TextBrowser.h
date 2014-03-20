/*
 * sgsui_TextBrowser.h
 *
 *  Created on: Jun 17, 2012
 *      Author: latios
 */

#ifndef SGSUI_TEXTBROWSER_H_
#define SGSUI_TEXTBROWSER_H_

#include <QTextBrowser>

namespace sgsui {

class TextBrowser: public QTextBrowser {
public:
	explicit TextBrowser(QWidget *parent = 0);

private:
	const static QString stylesheet;
};

} /* namespace sgsui */
#endif /* SGSUI_TEXTBROWSER_H_ */
