/*
 * sgsui_CardContainer.cpp
 *
 *  Created on: Mar 28, 2012
 *      Author: latios
 */

#include "sgsui_CardContainer.h"
#include "sgsui_MainWindow.h"
#include "sgsui_CardButton.h"
#include "sgsui_GUIStaticData.h"
#include "sgsui_output.h"
#include "sgsui_nameConvert.h"
#include <algorithm>

namespace sgsui {

QSize CardContainer::fixedSize(700, 346);

CardContainer::CardContainer(QWidget *parent) :
		BlockingFrame(parent), maxCardSelect(0), minCardSelect(0), _targetPlayer(
				0), _handSelectable(0), _equipSelectable(0), _judgeSelectable(
				0), skipGuanshi(false), onlyChooseHorse(false), canceled(0) {
	setupUi(this);

	setFixedSize(fixedSize);

	okButton->setEnabledPixmap(QPixmap("images/button/ok.png"));
	okButton->setDisabledPixmap(QPixmap("images/button/ok-disabled.png"));
	cancelButton->setEnabledPixmap(QPixmap("images/button/cancel.png"));
	cancelButton->setDisabledPixmap(
			QPixmap("images/button/cancel-disabled.png"));

	setStyleSheet(
			"QFrame#CardContainer{background-image:url(images/frame/cardContainer.png)}");

	connect(okButton, SIGNAL(clicked()), this, SLOT(unblock()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
	okButton->setDisabled();
}

CardContainer::~CardContainer() {

	// Normally the cardList is already destroyed by clearContainer()
	// However, in case the game is shutdown unexpectly, this destructor ensures that cards are destroyed
	for (std::list<CardButton*>::iterator iter = cardList.begin();
			iter != cardList.end(); ++iter)
		delete (*iter);
}

void CardContainer::enterKeyPressedEvent() {
	okButton->click();
}

CardPosPairVec CardContainer::chooseCard(const QString &message,
		sgs::DataType::Player *targetPlayer, bool handSelectable,
		bool equipSelectable, bool judgeSelectable, int selectNum,
		sgs::ConstData::CardType reason) {
	printDebug("CardContainer::chooseCard (card version): start");
	messageLabel->setText(setColored(message));
	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));
	_targetPlayer = targetPlayer;
	_handSelectable = handSelectable;
	_equipSelectable = equipSelectable;
	_judgeSelectable = judgeSelectable;
	maxCardSelect = selectNum;
	minCardSelect = selectNum;
	skipGuanshi = (reason == sgs::ConstData::GUANSHI);
	onlyChooseHorse = (reason == sgs::ConstData::QILIN);
	constructContainer();
	exec();
	collectData();
	clearContainer(); // destroy cards and lists
	printDebug(selectInterpret(returnValue));
	printDebug("CardContainer::chooseCard (card version): over");
	return returnValue;
}

CardPosPairVec CardContainer::chooseCard(const QString &message,
		sgs::DataType::Player *targetPlayer, bool handSelectable,
		bool equipSelectable, bool judgeSelectable, int selectNum,
		sgs::ConstData::HeroSkill reason) {
	printDebug("CardContainer::chooseCard (card version): start");
	messageLabel->setText(setColored(message));
	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));
	_targetPlayer = targetPlayer;
	_handSelectable = handSelectable;
	_equipSelectable = equipSelectable;
	_judgeSelectable = judgeSelectable;
	maxCardSelect = selectNum;
	minCardSelect = selectNum;
	constructContainer();
	exec();
	collectData();
	clearContainer(); // destroy cards and lists
	printDebug(selectInterpret(returnValue));
	printDebug("CardContainer::chooseCard (card version): over");
	return returnValue;
}

CardPosPairVec CardContainer::chooseSkillCard(sgs::ConstData::HeroSkill skill) {
	cancelButton->show();
	QString message;
	using namespace sgs::ConstData;
	switch (skill) {
	case LIULI:
		message +=
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\345\274\240\350\246\201\345\274\203\347\275\256\347\232\204\347\211\214");
		break;
	case ZHIHENG:
		message +=
				trUtf8(
						"\350\257\267\351\200\211\346\213\251\350\246\201\345\274\203\347\275\256\347\232\204\345\215\241\347\211\214");
		break;
	case GUOSE:
		message +=
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\345\274\240\342\231\246\350\212\261\350\211\262\347\232\204\345\215\241\347\211\214");
		break;
	case WUSHENG:
	case JIJIU:
		message +=
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\345\274\240\347\272\242\350\211\262\346\211\213\347\211\214\346\210\226\350\243\205\345\244\207");
		break;
	case QIXI:
		message +=
				trUtf8(
						"\351\200\211\346\213\251\344\270\200\345\274\240\351\273\221\350\211\262\346\211\213\347\211\214\346\210\226\350\243\205\345\244\207");
		break;
	case LIJIAN:
		message +=
				trUtf8(
						"\351\200\211\346\213\251\350\246\201\345\274\203\347\275\256\347\232\204\347\211\214");
		break;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>CardContainer::chooseSkillCard: skill handled by default");
		break;
	}
	messageLabel->setText(setColored(message));
	setGeometry(
			QRect(
					QPoint(window()->width() / 2 - width() / 2,
							window()->height() / 2 - height() / 2), size()));

	_targetPlayer = MainWindow::mainWindowPtr()->myPlayer();
	maxCardSelect = cardNum(skill);
	minCardSelect = 1;
	CardButton * newCardButton = 0;
	const sgs::DataType::Card * addingCard = 0;

// construct shoupai

	printDebug("CardContainer::chooseSkillCard: constructing hand card");
	int shoupaiNum = _targetPlayer->handnum();
	for (int i = shoupaiNum - 1; i >= 0; --i) {
		addingCard = _targetPlayer->hand(i);
		if (addThisCardInSkill(skill, addingCard)) {
			newCardButton = new CardButton(addingCard, this, _targetPlayer);
			cardList.push_back(newCardButton);
			cardLayout->addWidget(newCardButton);
		}
	}
	printDebug("CardContainer::chooseSkillCard: hand card constructed");

// construct zhuangbei
	printDebug("CardContainer::chooseSkillCard: constructing equip card");
	addingCard = _targetPlayer->weapon();
	if (addingCard && addThisCardInSkill(skill, addingCard)) {
		newCardButton = new CardButton(addingCard, this);
		cardList.push_back(newCardButton);
		cardLayout->addWidget(newCardButton);
	}
	addingCard = _targetPlayer->armor();
	if (addingCard && addThisCardInSkill(skill, addingCard)) {
		newCardButton = new CardButton(addingCard, this);
		cardList.push_back(newCardButton);
		cardLayout->addWidget(newCardButton);
	}
	addingCard = _targetPlayer->atkhorse();
	if (addingCard && addThisCardInSkill(skill, addingCard)) {
		newCardButton = new CardButton(addingCard, this);
		cardList.push_back(newCardButton);
		cardLayout->addWidget(newCardButton);
	}
	addingCard = _targetPlayer->dfdhorse();
	if (addingCard && addThisCardInSkill(skill, addingCard)) {
		newCardButton = new CardButton(addingCard, this);
		cardList.push_back(newCardButton);
		cardLayout->addWidget(newCardButton);
	}
	printDebug("CardContainer::chooseSkillCard: equip card constructed");
	exec();
	collectData();
	clearContainer(); // destroy cards and lists
	printDebug(selectInterpret(returnValue));
	printDebug("CardContainer::chooseSkillCard: over");
	return returnValue;
}

void CardContainer::cancel() {
	canceled = true;
	unblock();
}

void CardContainer::cardClicked(CardButton* clickedCard) {
	if (clickedCard->isSelected()) {
		clickedCard->setUnselected();
		selectedCardList.remove(clickedCard);
	} else {
		clickedCard->setSelected();
		selectedCardList.push_back(clickedCard);
		if (selectedCardList.size() > maxCardSelect) {
			selectedCardList.front()->setUnselected();
			selectedCardList.pop_front();
		}
	}

	if (selectedCardList.size() <= maxCardSelect
			&& selectedCardList.size() >= minCardSelect)
		okButton->setEnabled();
	else
		okButton->setDisabled();
}

void CardContainer::constructContainer() {
	printDebug("CardContainer::constructContainer: start");
	CardButton * newCardButton = 0;
	const sgs::DataType::Card * addingCard = 0;

	// construct shoupai
	if (_handSelectable) {
		printDebug("CardContainer::constructContainer: constructing hand card");
		int shoupaiNum = _targetPlayer->handnum();
		for (int i = shoupaiNum - 1; i >= 0; --i) {
			addingCard = _targetPlayer->hand(i);
			newCardButton = new CardButton(
					addingCard,
					this,
					GUIStaticData::getPlayer(GUIStaticData::getHumanIndex())
							== _targetPlayer);
			cardList.push_back(newCardButton);
			cardLayout->addWidget(newCardButton);
		}
		printDebug("CardContainer::constructContainer: hand card constructed");
	}

	// construct zhuangbei
	if (_equipSelectable) {
		printDebug(
				"CardContainer::constructContainer: constructing equip card");
		addingCard = _targetPlayer->weapon();
		if (!onlyChooseHorse && addingCard && !skipGuanshi) {
			newCardButton = new CardButton(addingCard, this);
			cardList.push_back(newCardButton);
			cardLayout->addWidget(newCardButton);
		}
		addingCard = _targetPlayer->armor();
		if (!onlyChooseHorse && addingCard) {
			newCardButton = new CardButton(addingCard, this);
			cardList.push_back(newCardButton);
			cardLayout->addWidget(newCardButton);
		}
		addingCard = _targetPlayer->atkhorse();
		if (addingCard) {
			newCardButton = new CardButton(addingCard, this);
			cardList.push_back(newCardButton);
			cardLayout->addWidget(newCardButton);
		}
		addingCard = _targetPlayer->dfdhorse();
		if (addingCard) {
			newCardButton = new CardButton(addingCard, this);
			cardList.push_back(newCardButton);
			cardLayout->addWidget(newCardButton);
		}
		printDebug("CardContainer::constructContainer: equip card constructed");
	}

	// construct judge
	if (_judgeSelectable) {
		printDebug(
				"CardContainer::constructContainer: constructing judge card");
		int selectablePandingNum = _targetPlayer->judgenum();
		for (int i = 0; i < selectablePandingNum; ++i) {
			addingCard = _targetPlayer->judge(i);
			newCardButton = new CardButton(addingCard, this);
			cardList.push_back(newCardButton);
			cardLayout->addWidget(newCardButton);
		}
		printDebug("CardContainer::constructContainer: judge card constructed");
	}

	printDebug("CardContainer::constructContainer: over");
}

void CardContainer::collectData() {
	returnValue.clear();
	if (canceled)
		return;

	std::vector<int> selectedHandVec, selectedJudgeVec;
	int result;
	CardButton* card = 0;
	for (std::list<CardButton *>::iterator iter = selectedCardList.begin();
			iter != selectedCardList.end(); ++iter) {
		card = (*iter);
		result = getIndexAtHand(card);
		if (result != -1) {
			selectedHandVec.push_back(result);
			continue;
		}
		result = getIndexAtEquip(card);
		if (result != -1) {
			selectedJudgeVec.push_back(result);
			continue;
		}
		if (_targetPlayer->weapon() == card->platformCard()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 0));
			continue;
		}
		if (_targetPlayer->armor() == card->platformCard()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 1));
			continue;
		}
		if (_targetPlayer->atkhorse() == card->platformCard()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 2));
			continue;
		}
		if (_targetPlayer->dfdhorse() == card->platformCard()) {
			returnValue.push_back(
					std::pair<sgs::ConstData::PlayerRegionType, int>(
							sgs::ConstData::PEQUIP, 3));
			continue;
		}
	}

	// sort them from big to small (use reverse iterator)
	std::sort(selectedHandVec.rbegin(), selectedHandVec.rend());
	std::sort(selectedJudgeVec.rbegin(), selectedJudgeVec.rend());
	for (std::vector<int>::iterator iter = selectedHandVec.begin();
			iter != selectedHandVec.end(); ++iter) {
		returnValue.push_back(
				std::pair<sgs::ConstData::PlayerRegionType, int>(
						sgs::ConstData::PHAND, *iter));
	}
	for (std::vector<int>::iterator iter = selectedJudgeVec.begin();
			iter != selectedJudgeVec.end(); ++iter) {
		returnValue.push_back(
				std::pair<sgs::ConstData::PlayerRegionType, int>(
						sgs::ConstData::PJUDGE, *iter));
	}
}

void CardContainer::clearContainer() {
	for (std::list<CardButton *>::iterator iter = cardList.begin();
			iter != cardList.end(); ++iter) {
		cardLayout->removeWidget(*iter);
		delete *iter;
	}
	// DO NOT clean returnValue here, or you can only return an empty vector!
	cardList.clear();
	selectedCardList.clear();
	_targetPlayer = 0;
	_handSelectable = false;
	_equipSelectable = false;
	_judgeSelectable = false;
	skipGuanshi = false;
	onlyChooseHorse = false;
	maxCardSelect = 0;
	minCardSelect = 0;
	canceled = false;
	okButton->setDisabled();
	cancelButton->hide();
}

int CardContainer::getIndexAtHand(CardButton * clickedCard) const {
	int shoupaiNum = _targetPlayer->handnum();
	const sgs::DataType::Card * platCard = clickedCard->platformCard();
	for (int i = 0; i < shoupaiNum; ++i) {
		if (_targetPlayer->hand(i) == platCard)
			return i;
	}
	return -1;
}

int CardContainer::getIndexAtEquip(CardButton * clickedCard) const {
	int judgeNum = _targetPlayer->judgenum();
	const sgs::DataType::Card * platCard = clickedCard->platformCard();
	for (int i = 0; i < judgeNum; ++i) {
		if (_targetPlayer->judge(i) == platCard)
			return i;
	}
	return -1;
}

bool CardContainer::addThisCardInSkill(sgs::ConstData::HeroSkill skill,
		const sgs::DataType::Card * card) const {
	using namespace sgs::ConstData;
	if (!card) {
		printDebug(
				"<font color=red><b>Warning: </b></font>CardContainer::addThisCardInSkill: null pointer");
		return false;
	}

	switch (skill) {
	case GUOSE:
		return (card->color() == sgs::ConstData::DIAMOND);
	case WUSHENG:
	case JIJIU:
		return (card->color() == sgs::ConstData::HEART
				|| card->color() == sgs::ConstData::DIAMOND);
	case QIXI:
		return (card->color() == sgs::ConstData::SPADE
				|| card->color() == sgs::ConstData::CLUB);
	case LIULI:
	case ZHIHENG:
	case LIJIAN:
		return true;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>CardContainer::addThisCardInSkill: skill handled by default");
		return false;
	}
}

unsigned CardContainer::cardNum(sgs::ConstData::HeroSkill skill) const {
	using namespace sgs::ConstData;
	switch (skill) {
	case ZHIHENG:
		return 0xFFFF;
	case LIULI:
	case GUOSE:
	case WUSHENG:
	case JIJIU:
	case QIXI:
	case LIJIAN:
		return 1;
	default:
		printDebug(
				"<font color=red><b>Warning: </b></font>CardContainer::cardNum: skill handled by default");
		return 1;
	}
}

} /* namespace sgsui */
