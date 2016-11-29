#include "deck.h"

Deck::Deck(istream& in, CardFactory* factory) {

}

Card* Deck::draw() {
	Card* top = deck.back();
	deck.pop_back();
	return top;
}

ostream& operator<<(ostream& out, const Deck& oDeck) {
	for (int i = oDeck.deck.size()-1 ; i >= 0; --i) {
		oDeck.deck[i]->print(out);
	}
	return out;
}