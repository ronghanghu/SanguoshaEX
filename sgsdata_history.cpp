/*
//最后编辑时间：2012-06-28
//编辑者：李昂
*/
#include "sgsdata_history.h"
#include "sgsdata_msg.h"
using namespace sgs;
using namespace DataType;
 
History::~History(){
	//delete all the stored message
	for (std::vector <sgs::DataType::Message *>::iterator iter = _history.begin(); iter != _history.end(); ++iter) {
		delete *iter;
	}
//	_history.clear(); this is not necessary (a vector will clear itself automatically)
}
void History::push(Message * m){
    if (m == 0
            || m->dissolved()) return;
	_history.push_back(m);
}
Message * History::view(int pos) const{
	return *(_history.rbegin() + pos);
	// revised by Huronghang
	// previous code:
	// return _history.back();
}
int History::size() const{
	return _history.size();
}

const std::vector<sgs::DataType::Message *>& History::viewVec() const {
	return _history;
}
