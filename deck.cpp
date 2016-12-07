#include "deck.h"
#include <iostream>

Deck::Deck() {
}



Deck::Deck(istream& in, CardFactory* factory) {
	while (in != null) {
		cards.push_back(in);
	}
}


Card* Deck::draw() {
	Card* top = cards.back();
	cards.pop_back();
	return top;
}

ostream& operator<<(ostream& out, const Deck& oDeck) {
	for (int i = oDeck.cards.size() - 1; i >= 0; --i) {
		out << *(oDeck.cards[i]) << " ";
	}
	out << std::endl;
	return out;
}