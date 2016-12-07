#include <iostream>
#include "trade_area.h"

TradeArea::TradeArea(istream& in, CardFactory* factory) {
	
}

TradeArea::TradeArea() {



}
TradeArea::TradeArea(vector<Card*> card) {
	for (int i = 0; i < card.size(); i++) {
		tradeArea.push_back(card[i]);
	}
}



bool TradeArea::legal(const Card* card) const {
	for (list<Card*>::const_iterator iter = tradeArea.begin(); iter != tradeArea.end(); ++iter) {
		if ((*iter)->getName() == card->getName()) {
			return true;
		}
	}
	return false;
}

Card* TradeArea::trade(const string name) {
	Card* card = nullptr;
	for (list<Card*>::const_iterator iter = tradeArea.begin(); iter != tradeArea.end(); ++iter) {
		if ((*iter)->getName() == name) {
			card = *iter;
			tradeArea.erase(iter);
			return card;
		}
	}
	return card;
}

int TradeArea::numCards() const {
	return tradeArea.size();
}

TradeArea& TradeArea::operator+=(Card* card) {
	tradeArea.push_back(card);
	return *this;
}

ostream& operator<<(ostream& out, const TradeArea& oTrade) {
	for (list<Card*>::const_iterator iter = oTrade.tradeArea.begin(); iter != oTrade.tradeArea.end(); ++iter) {
		out << **iter << " ";
	}
	out << std::endl;
	return out;
}