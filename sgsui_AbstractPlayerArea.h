/*
 * sgsui_AbstractPlayerArea.h
 *
 *  Created on: May 6, 2012
 *      Author: latios
 */

#ifndef SGSUI_ABSTRACTPLAYERAREA_H_
#define SGSUI_ABSTRACTPLAYERAREA_H_

#include "sgsdata_enum.h"

namespace sgs {
namespace DataType {
class Player;
}
}

namespace sgsui {

class AbstractPlayerArea {
public:
	virtual sgs::DataType::Player * getPlayer() = 0;
	virtual void click() = 0;
	virtual bool isSelected() = 0;
	virtual bool isSelectable() = 0;
	virtual void setSelected(bool selected = true) = 0;
	virtual void setSelectable(bool selectable = true) = 0;
	virtual void setUnselected(bool unselected = true) = 0;
	virtual void setUnselectable(bool unselectable = true) = 0;
	virtual sgs::ConstData::HeroSex getSex() const = 0;
	virtual sgs::ConstData::HeroType getHeroType() const = 0;
	virtual sgs::ConstData::PlayerRole getRole() const = 0;
	virtual int playerIndex() const = 0;
	virtual int getHP() const = 0;
	virtual ~AbstractPlayerArea() {
	}
};

} /* namespace sgsui */
#endif /* SGSUI_ABSTRACTPLAYERAREA_H_ */
