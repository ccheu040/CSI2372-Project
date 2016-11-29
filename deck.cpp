#include "deck.h"

Deck::Deck(istream& in, CardFactory* factory) {

}

Card* Deck::draw() {
	if (!deck.empty()) {
		Card* top = deck.back();
		deck.pop_back();
		return top;
	}
	return nullptr;
}

ostream& operator<<(ostream& out, const Deck& oDeck) {
	for (int i = oDeck.deck.size() - 1 ; i >= 0; --i) {
		out << *(oDeck.deck[i]) << " ";
	}
	out << std::endl;
	return out;
}