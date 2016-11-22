#include "deck.h"

Deck::Deck(istream& in, CardFactory* factory) {

}

Card* Deck::draw() {
	Card* top = deck.back();
	deck.pop_back();
	return top;
}

ostream& operator<<(ostream& out, const Deck& oDeck) {
	return out;
}