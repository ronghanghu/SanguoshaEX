/*
 //最后整理时间2012-06-28
 //编辑者：李昂
 //卡牌类成员函数的定义
 */
#include "sgsdata_card.h"
#include "sgsdata_card_func.h"
using namespace sgs;
using namespace ConstData;
using namespace DataType;

//Card
Card::Card() :
		_number(0), _color(ccNone), _type(ctNone), _mask(ctNone), _processor(0) {
}
Card::Card(CardColor c, int n, CardType t) :
		_number(n), _color(c), _type(t), _mask(t) {
	protrans(t);
}
Card::~Card() {
}
CardColor Card::color() const {
	return _color;
}
int Card::number() const {
	return _number;
}
CardType Card::type() const {
	return _type;
}
CardType Card::mask() const {
	return _mask;
}
Message* Card::settle(Message *m) const {
	return (*_processor)(m);
}
void Card::setmask(CardType m) const {
	_mask = m;
	protrans(m);
}
void Card::setmask() const {
	_mask = _type;
	protrans(_type);
}
void Card::protrans(CardType m) const {
	switch (m) {
	case SHA:
		_processor = func::pcsha;
		break;
	case SHAN:
		_processor = func::pcshan;
		break;
	case TAO:
		_processor = func::pctao;
		break;
	case CHITU:
	case DAWAN:
	case ZICI:
		_processor = func::pcatk;
		break;
	case DILU:
	case JUEYING:
	case ZHUAHUANG:
	case HUALIU:
		_processor = func::pcdfd;
		break;
	case ZHUGE:
	case QINGGANG:
	case HANBING:
	case CIXIONG:
	case GUANSHI:
	case YINYUE:
	case QINGLONG:
	case GUDING:
	case ZHANGBA:
	case FANGTIAN:
	case QILIN:
	case ZHUQUE:
		_processor = func::pcweapon;
		break;
	case RENWANG:
	case BAGUA:
		_processor = func::pcarmor;
		break;
	case SHUNQIAN:
		_processor = func::pcshunqian;
		break;
	case GUOCHAI:
		_processor = func::pcguochai;
		break;
	case WUZHONG:
		_processor = func::pcwuzhong;
		break;
	case JUEDOU:
		_processor = func::pcjuedou;
		break;
	case TAOYUAN:
		_processor = func::pctaoyuan;
		break;
	case WANJIAN:
		_processor = func::pcwanjian;
		break;
	case NANMAN:
		_processor = func::pcnanman;
		break;
	case SISHU:
	case SHANDIAN:
		_processor = func::pcyanshi;
		break;
	case WUGU:
		_processor = func::pcwugu;
		break;
	case JIEDAO:
		_processor = func::pcjiedao;
		break;
	default:
		break;
	}
}
