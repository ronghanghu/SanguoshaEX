/*
 * sgsui_CardViewer.cpp
 *
 *  Created on: Jul 3, 2012
 *      Author: latios
 */

#include "sgsui_CardViewer.h"
#include "sgsdata_card.h"
#include "sgsui_nameConvert.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_CardFrame.h"

namespace sgsui {

const QSize CardViewer::fixedSize(560, 290);

CardViewer::CardViewer(QWidget *parent) :
		QFrame(parent), card1(0), card2(0), cardFrame1(0), cardFrame2(0) {
	setupUi(this);
	setFixedSize(fixedSize);
	setObjectName("CardViewer");
	setStyleSheet(
			"QFrame#CardViewer{background-image:url(images/frame/cardViewer.png)}");

	messageLabel->setFont(GUIStaticData::headingFont);
}

void CardViewer::showViewer(const sgs::DataType::Card * _card1,
		const sgs::DataType::Card * _card2) {
	if (cardFrame1) {
		delete cardFrame1;
		cardFrame1 = 0;
	}
	if (cardFrame2) {
		delete cardFrame2;
		cardFrame2 = 0;
	}
	card1 = _card1;
	card2 = _card2;

	if (!card1 || !card2)
		return;

	cardFrame1 = new CardFrame(card1->type(), card1->color(), card1->number(),
			cardLabel1);
	cardFrame2 = new CardFrame(card2->type(), card2->color(), card2->number(),
			cardLabel2);
	cardFrame2->setDimed(true);
	cardFrame1->show();
	cardFrame2->show();

	QString text;
	text +=
			trUtf8(
					"\350\257\267\351\200\211\346\213\251\350\246\201\350\216\267\345\276\227\347\254\254\344\270\200\345\274\240\345\215\241\347\211\214 ");
	text += cardDisplayName(card1->type());
	text += trUtf8(" \347\232\204\347\216\251\345\256\266");

	messageLabel->setText(setColored(text));
	show();
}

void CardViewer::showSecondViewer() {
	if (!card1 || !card2)
		return;

	if (cardFrame1 && cardFrame2) {
		cardFrame1->setDimed(true);
		cardFrame2->setDimed(false);
	}
	QString text;
	text +=
			trUtf8(
					"\350\257\267\351\200\211\346\213\251\350\246\201\350\216\267\345\276\227\347\254\254\344\272\214\345\274\240\345\215\241\347\211\214");
	text += cardDisplayName(card2->type());
	text += trUtf8(" \347\232\204\347\216\251\345\256\266");
	messageLabel->setText(setColored(text));
}

} /* namespace sgsui */
