#include "trade_area.h"

TradeArea::TradeArea(istream& in, CardFactory* factory) {
	
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

list<Card*>& TradeArea::getCards(){
	return tradeArea;
}

TradeArea& TradeArea::operator+=(Card* card) {
	tradeArea.push_back(card);
	return *this;
}

ostream& operator<<(ostream& out, const TradeArea& oTrade) {
	out << "Trade Area" << "\t";
	for (list<Card*>::const_iterator iter = oTrade.tradeArea.begin(); iter != oTrade.tradeArea.end(); ++iter) {
		out << **iter << " ";
	}
	out << std::endl;
	return out;
}