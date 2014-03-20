/*
//最后整理时间：2012-06-28
//编辑者：李昂
//历史记录类的定义
*/
#ifndef _SGSDATA_HISTORY_H
#define _SGSDATA_HISTORY_H
#include "sgsdata_enum.h"
#include "sgsdata_namespace.h"
#include <vector>
 
class sgs::DataType::History
{
	std::vector<sgs::DataType::Message *> _history;
public:
	~History(); // has been revised by Huronghang (Jun. 26 14:44)
	void push(sgs::DataType::Message *);//插入一个事件记录
	sgs::DataType::Message * view(int pos) const;//按照顺序访问历史，越靠后的事件数字越小，从0开始计数，通常0就是当前的事件
	int size() const;//访问历史长度
	int begin() const;//找到最近的一次连锁的开始位置
	const std::vector<sgs::DataType::Message *>& viewVec() const; // added by Huronghang (Jun. 26 14:44) 我希望能够用访问标准库vector的方式访问viewvec，故返回了它的常引用
};
 
#endif /*_SGSDATA_HISTORY_H*/
