#include <iostream>
#include "discard_pile.h"

DiscardPile::DiscardPile(istream& in, CardFactory* factory) {
	
}

DiscardPile::DiscardPile() {



}
DiscardPile::DiscardPile(vector<Card*> card) {
	for (int i = 0; i < card.size(); i++) {
		pile.push_back(card[i]);
	}
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
	for (int i = pile.size() - 1; i >= 0; --i) {
		out << *(pile[i]) << " ";
	}
	out << std::endl;
}

DiscardPile& DiscardPile::operator+=(Card* card) {
	pile.push_back(card);
	return *this;
}

ostream& operator<<(ostream& out, const DiscardPile& oPile) {
	out << *(oPile.pile.back());
	return out;
}