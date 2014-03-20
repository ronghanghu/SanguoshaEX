/*
 * sgsui_AbstractCardContainer.h
 *
 *  Created on: Mar 28, 2012
 *      Author: latios
 */

#ifndef SGSUI_ABSTRACTCARDCONTAINER_H_
#define SGSUI_ABSTRACTCARDCONTAINER_H_

#include <vector>
#include <utility>
#include "sgsdata_enum.h"

namespace sgsui {

typedef std::vector<std::pair<sgs::ConstData::PlayerRegionType, int> > CardPosPairVec;
typedef std::pair<sgs::ConstData::PlayerRegionType, int> CardPosPair;

class CardButton;

class AbstractCardContainer {
public:
	virtual void cardClicked(CardButton* clickedCard) = 0;
	virtual ~AbstractCardContainer() {
	}
};

} /* namespace sgsui */
#endif /* SGSUI_ABSTRACTCARDCONTAINER_H_ */
