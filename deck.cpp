#include "deck.h"

Deck::Deck(istream& in, CardFactory* factory) {
	
}

Card* Deck::draw() {
	if (size() != 0) {
		Card* top = back();
		pop_back();
		return top;
	}
	return nullptr;
}

ostream& operator<<(ostream& out, const Deck& oDeck) {
	for (int i = oDeck.size() - 1; i >= 0; --i) {
		out << *(oDeck[i]) << " ";
	}
	out << std::endl;
	return out;
}