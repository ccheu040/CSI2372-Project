#include "deck.h"
#include <iostream>
#include "cardfactory.h"


Deck::Deck(istream& in, CardFactory* factory) {
	string deckCard;
	while (in.good()) {
		getline(in, deckCard);
	}
	reverse(deckCard.begin(), deckCard.end());
	while (deckCard != "") {
		if ((const char*)deckCard.back() == "Q") {
			push_back(factory->createCard("Quartz"));
			deckCard.pop_back();
		}
		else if ((const char*)deckCard.back() == "H") {
			push_back(factory->createCard("Hematite"));
			deckCard.pop_back();
		}
		else if ((const char*)deckCard.back() == "o") {
			push_back(factory->createCard("Obsidian"));
			deckCard.pop_back();
		}
		else if ((const char*)deckCard.back() == "M") {
			push_back(factory->createCard("Malachite"));
			deckCard.pop_back();
		}
		else if ((const char*)deckCard.back() == "T") {
			push_back(factory->createCard("Turquoise"));
			deckCard.pop_back();
		}
		else if ((const char*)deckCard.back() == "R") {
			push_back(factory->createCard("Ruby"));
			deckCard.pop_back();
		}
		else if ((const char*)deckCard.back() == "A") {
			push_back(factory->createCard("Amethyst"));
			deckCard.pop_back();
		}
		else if ((const char*)deckCard.back() == "E") {
			push_back(factory->createCard("Emerald"));
			deckCard.pop_back();
		}
	}
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
