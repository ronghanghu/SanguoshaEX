/*
 * sgsui_Outstream.h
 *
 *  Created on: Jun 1, 2012
 *      Author: latios
 */

#ifndef SGSUI_OUTSTREAM_H_
#define SGSUI_OUTSTREAM_H_

namespace sgs {
namespace DataType {
class Message;
}
}

namespace sgsui {

class Outstream {
public:
	Outstream& operator<<(int); // create players in window, call this method when all players have been constructed
	Outstream& operator<<(const sgs::DataType::Message *);
};

} /* namespace sgsui */

#endif /* SGSUI_OUTSTREAM_H_ */
