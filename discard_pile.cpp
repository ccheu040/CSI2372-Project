#include <iostream>
#include "cardfactory.h"
#include "discard_pile.h"

DiscardPile::DiscardPile(istream& in, CardFactory* factory) {
	string pileCard;
	while (in.good()) {
		getline(in, pileCard);
	}
	reverse(pileCard.begin(), pileCard.end());
	while (pileCard != "") {
		if ((const char*)pileCard.back() == "Q") {
			pile.push_back(factory->createCard("Quartz"));
			pileCard.pop_back();
		}
		else if ((const char*)pileCard.back() == "H") {
			pile.push_back(factory->createCard("Hematite"));
			pileCard.pop_back();
		}
		else if ((const char*)pileCard.back() == "o") {
			pile.push_back(factory->createCard("Obsidian"));
			pileCard.pop_back();
		}
		else if ((const char*)pileCard.back() == "M") {
			pile.push_back(factory->createCard("Malachite"));
			pileCard.pop_back();
		}
		else if ((const char*)pileCard.back() == "T") {
			pile.push_back(factory->createCard("Turquoise"));
			pileCard.pop_back();
		}
		else if ((const char*)pileCard.back() == "R") {
			pile.push_back(factory->createCard("Ruby"));
			pileCard.pop_back();
		}
		else if ((const char*)pileCard.back() == "A") {
			pile.push_back(factory->createCard("Amethyst"));
			pileCard.pop_back();
		}
		else if ((const char*)pileCard.back() == "E") {
			pile.push_back(factory->createCard("Emerald"));
			pileCard.pop_back();
		}
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

vector<Card*> DiscardPile::getCards(){
	return pile;
}