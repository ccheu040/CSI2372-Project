#pragma once

class CardFactory;
#include <list>
#include "card_hierarchy.h"

using std::list;
using std::istream;
using std::ostream;

class TradeArea {
	list<Card*> tradeArea;
public:
	TradeArea() = default;
	TradeArea(istream& in, CardFactory* factory);
	bool legal(const Card* card) const;
	Card* trade(const string name);
	int numCards() const;
	TradeArea& operator+=(Card* card);
	friend ostream& operator<<(ostream& out, const TradeArea& oTradeArea);
	list<Card*> getCards();
};