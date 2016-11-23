#pragma once

class CardFactory;

#include <iostream>
#include <list>
#include <string>
#include "card_hierarchy.h"

using std::string;
using std::list;
using std::istream;
using std::ostream;

class TradeArea {
	list<Card*> tradeArea;

public:
	TradeArea(istream& in, CardFactory* factory);
	bool legal(const Card* card) const;
	Card* trade(const string name);
	int numCards() const;
	TradeArea& operator+=(Card* card);
	friend ostream& operator<<(ostream& out, const TradeArea& oTradeArea);
};