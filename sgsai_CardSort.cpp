/*
 * sgsai_CardSort.cpp
 *
 *  Created on: Jun 29, 2012
 *      Author: latios
 */

#include "sgsai_CardSort.h"

namespace sgsai {

CardSort::CardSort(CardAlgorithm _algorithm) :
		algorithm(_algorithm) {
}

bool CardSort::operator()(sgs::DataType::Card * /*card1*/,
		sgs::DataType::Card * /*card2*/) {

	// TODO complete it
	return false;
}

} /* namespace sgsai */
