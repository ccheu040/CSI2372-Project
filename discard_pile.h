#pragma once

class CardFactory;

#include <vector>
#include "card_hierarchy.h"

using std::vector;
using std::istream;
using std::ostream;

class DiscardPile {
	vector<Card*> pile;

public:
	DiscardPile() {};
	DiscardPile(istream& in, CardFactory* factory);
	Card* pickUp();
	Card* top() const;
	vector<Card*>& getCards();
	void print(ostream& out) const;
	DiscardPile& operator+=(Card* card);
	friend ostream& operator<<(ostream& out, const DiscardPile& oPile);
};