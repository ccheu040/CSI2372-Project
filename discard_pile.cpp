#include "discard_pile.h"

DiscardPile::DiscardPile(istream& in, CardFactory* factory) {

}

Card* DiscardPile::pickUp() {
	Card* back = pile.back();
	pile.pop_back();
	return back;
}

Card* DiscardPile::top() const {
	return pile.back();
}

void DiscardPile::print(ostream& out) const {

}

DiscardPile& DiscardPile::operator+=(Card* card) {
	pile.push_back(card);
	return *this;
}

ostream& operator<<(ostream& out, const DiscardPile& oPile) {
	return out;
}