#include "deck.h"
#include <iostream>

Deck::Deck() {
}



Deck::Deck(istream& in, CardFactory* factory) {
	
}

Deck::Deck(vector<Card*> card) {
	for (int i = 0; i < card.size(); i++) {
		cards.push_back(card[i]);
	}
}

Card* Deck::draw() {
	if (!cards.empty()) {
		Card* top = cards.back();
		cards.pop_back();
		return top;
	}
	return nullptr;
}

ostream& operator<<(ostream& out, const Deck& oDeck) {
	for (int i = oDeck.cards.size() - 1; i >= 0; --i) {
		out << *(oDeck.cards[i]) << " ";
	}
	out << std::endl;
	return out;
}