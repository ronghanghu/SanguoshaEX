/*
 * sgsui_CardContainer.h
 *
 *  Created on: Mar 28, 2012
 *      Author: latios
 */

#ifndef SGSUI_CARDCONTAINER_H_
#define SGSUI_CARDCONTAINER_H_

#include "ui_CardContainer.h"
#include "sgsui_BlockingFrame.h"
#include "sgsui_AbstractCardContainer.h"
#include "sgsdata_enum.h"
#include "sgsdata_player.h"
#include "sgsdata_card.h"
#include <list>

namespace sgsui {

class CardContainer: public BlockingFrame,
		protected Ui::CardContainer,
		protected AbstractCardContainer {
Q_OBJECT
public:
	explicit CardContainer(QWidget *parent = 0);
	virtual ~CardContainer();

	void enterKeyPressedEvent();
	CardPosPairVec chooseCard(const QString &message, sgs::DataType::Player *,
			bool handSelectable, bool equipSelectable, bool judgeSelectable,
			int selectNum, sgs::ConstData::CardType reason);
	CardPosPairVec chooseCard(const QString &message, sgs::DataType::Player *,
			bool handSelectable, bool equipSelectable, bool judgeSelectable,
			int selectNum, sgs::ConstData::HeroSkill reason);
	CardPosPairVec chooseSkillCard(sgs::ConstData::HeroSkill skill);

private slots:
	void cancel();

private:
	virtual void cardClicked(CardButton * clickedCard);
	void constructContainer();
	void collectData();
	void clearContainer();

	virtual int getIndexAtHand(CardButton * clickedCard) const;
	virtual int getIndexAtEquip(CardButton * clickedCard) const;

	bool addThisCardInSkill(sgs::ConstData::HeroSkill skill,
			const sgs::DataType::Card * card) const;
	unsigned cardNum(sgs::ConstData::HeroSkill skill) const;
	unsigned maxCardSelect;
	unsigned minCardSelect;
	std::list<CardButton *> selectedCardList;
	std::list<CardButton *> cardList;

	sgs::DataType::Player * _targetPlayer;
	bool _handSelectable;
	bool _equipSelectable;
	bool _judgeSelectable;
	CardPosPairVec returnValue;
	static QSize fixedSize;

	bool skipGuanshi;
	bool onlyChooseHorse;

	bool canceled;
};

} /* namespace sgsui */
#endif /* SGSUI_CARDCONTAINER_H_ */
