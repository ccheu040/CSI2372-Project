#include "deck.h"

Deck::Deck(istream& in, CardFactory* factory) {
	
}

Card* Deck::draw() {
	Card* top = back();
	pop_back();
	return top;
}

ostream& operator<<(ostream& out, const Deck& oDeck) {
	for (int i = oDeck.size() - 1; i >= 0; --i) {
		out << *(oDeck[i]) << " ";
	}
	out << std::endl;
	return out;
}