#pragma once

class CardFactory;

#include <queue>
#include "card_hierarchy.h"

using std::queue;
using std::istream;
using std::ostream;

class Hand {
	queue<Card*> hand;

public:
	Hand() {};
	Hand(istream& in, CardFactory* factory);
	Card* play();
	Card* top() const;
	int getNumCards() const;
	Hand& operator+=(Card* card);
	Card* operator[](const int i);
	friend ostream& operator<<(ostream& out, Hand& oHand);
	queue<Card*> getHandCard();
};