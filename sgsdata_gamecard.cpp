/*
 //最后编辑时间2012-06-28
 //编辑者：李昂
 */
#include "sgsdata_card.h"
#include "sgsdata_gamecard.h"
#include "sgsdata_extern.h"
#include <iostream>
#include <cstdlib>

using namespace sgs;
using namespace ConstData;
using namespace DataType;

GameCard::GameCard() {
}
GameCard::~GameCard() {
	pool.clear();
	dustbin.clear();
}
void GameCard::refresh() {
	if (!pool.empty())
		return;
	int N = dustbin.size();
	for (int i = 1; i <= N; i++) {
		int index = rand() % i;
		const Card * temp = dustbin.at();
		dustbin.pop();
		pool.push(temp, index);
	}
}
void GameCard::load() {
	const Card * temp = 0;
	for (int i = 0; i < 108; i++) {
		temp = &ExternData::card[i];
		dustbin.push(temp);
	}
	refresh();
}
const Card *GameCard::get() {
	if (pool.empty())
		refresh();
	const Card * temp = pool.at();
	pool.pop();
	return temp;
}
void GameCard::pooltop(const Card *c) {
	pool.push(c);
}
void GameCard::poolbottom(const Card *c) {
	pool.push_back(c);
}
void GameCard::abandon(const Card *c) {
	c->setmask();
	dustbin.push(c);
}
void GameCard::clearcard() {
	pool.clear();
	dustbin.clear();
}
const Card * GameCard::peekpool(int n) const {
	if (n < 0 || n >= pool.size())
		return 0;
	return pool.at(n + 1);
}
const Card * GameCard::peekdustbin(int n) const {
	if (n < 0 || n >= dustbin.size())
		return 0;
	return dustbin.at(n + 1);
}
int GameCard::poolsize() const {
	return pool.size();
}
int GameCard::dustbinsize() const {
	return dustbin.size();
}
void GameCard::setpool(int n, const sgs::DataType::Card *card) {
	if (n < 0 || n >= pool.size() || !card)
		return;
	else
		pool.at(n + 1) = card;
}
void GameCard::setdustbin(int n, const sgs::DataType::Card *card) {
	if (n < 0 || n >= dustbin.size() || !card)
		return;
	else
		dustbin.at(n + 1) = card;
}
