#pragma once

class CardFactory;
#include <vector>
#include <list>
#include "card_hierarchy.h"

using std::string;
using std::list;
using std::istream;
using std::ostream;
using std::vector;
using std::endl;
class TradeArea {
	list<Card*> tradeArea;
public:
	TradeArea(istream& in, CardFactory* factory);
	TradeArea();
	TradeArea(vector<Card*>);
	bool legal(const Card* card) const;
	Card* trade(const string name);
	int numCards() const;
	TradeArea& operator+=(Card* card);
	friend ostream& operator<<(ostream& out, const TradeArea& oTradeArea);
};