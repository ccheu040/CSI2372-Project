#pragma once

class CardFactory;

#include <vector>
#include "card_hierarchy.h"

using std::vector;
using std::istream;
using std::ostream;

class Deck {
	vector<Card*> cards;

public:
	Deck() = default;
	Deck(istream& in, CardFactory* factory);
	Deck(vector<Card*> card);
	Card* draw();
	friend ostream& operator<<(ostream& out, const Deck& oDeck);
};