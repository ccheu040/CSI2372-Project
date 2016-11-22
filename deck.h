#pragma once

class Card;
class CardFactory;

#include <vector>

using std::vector;
using std::istream;
using std::ostream;

class Deck {
	vector<Card*> deck;

public:
	Deck(istream& in, CardFactory* factory);
	Card* draw();
	friend ostream& operator<<(ostream& out, const Deck& oDeck);
};