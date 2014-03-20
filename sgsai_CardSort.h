/*
 * sgsai_CardSort.h
 *
 *  Created on: Jun 29, 2012
 *      Author: latios
 */

#ifndef SGSAI_CARDSORT_H_
#define SGSAI_CARDSORT_H_

namespace sgs {
namespace DataType {
class Card;
}
}

namespace sgsai {

enum CardAlgorithm {
	DEFAULT
};

class CardSort {
public:
	CardSort(CardAlgorithm _algorithm = DEFAULT);
	bool operator()(sgs::DataType::Card * card1, sgs::DataType::Card * card2);

private:
	const CardAlgorithm algorithm;
};

} /* namespace sgsai */
#endif /* SGSAI_CARDSORT_H_ */
