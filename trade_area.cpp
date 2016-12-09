#include <iostream>
#include "trade_area.h"
#include "cardfactory.h"
TradeArea::TradeArea(istream& in, CardFactory* factory) {
	string tradeCard;
	while (in.good()) {
		getline(in, tradeCard);
	}
	reverse(tradeCard.begin(), tradeCard.end());
	while (tradeCard != "") {
		if ((const char*)tradeCard.back() == "Q") {
			tradeArea.push_back(factory->createCard("Quartz"));
			tradeCard.pop_back();
		}
		else if ((const char*)tradeCard.back() == "H") {
			tradeArea.push_back(factory->createCard("Hematite"));
			tradeCard.pop_back();
		}
		else if ((const char*)tradeCard.back() == "o") {
			tradeArea.push_back(factory->createCard("Obsidian"));
			tradeCard.pop_back();
		}
		else if ((const char*)tradeCard.back() == "M") {
			tradeArea.push_back(factory->createCard("Malachite"));
			tradeCard.pop_back();
		}
		else if ((const char*)tradeCard.back() == "T") {
			tradeArea.push_back(factory->createCard("Turquoise"));
			tradeCard.pop_back();
		}
		else if ((const char*)tradeCard.back() == "R") {
			tradeArea.push_back(factory->createCard("Ruby"));
			tradeCard.pop_back();
		}
		else if ((const char*)tradeCard.back() == "A") {
			tradeArea.push_back(factory->createCard("Amethyst"));
			tradeCard.pop_back();
		}
		else if ((const char*)tradeCard.back() == "E") {
			tradeArea.push_back(factory->createCard("Emerald"));
			tradeCard.pop_back();
		}
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

list<Card*>& TradeArea::getCards() {
	return tradeArea;
}