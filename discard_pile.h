#pragma once

class Card;
class CardFactory;

#include <vector>

using std::vector;
using std::istream;
using std::ostream;

class DiscardPile {
	vector<Card*> pile;

public:
	DiscardPile(istream& in, CardFactory* factory);
	Card* pickUp();
	Card* top() const;
	void print(ostream& out) const;
	DiscardPile& operator+=(Card* card);
	friend ostream& operator<<(ostream& out, const DiscardPile& oPile);
};