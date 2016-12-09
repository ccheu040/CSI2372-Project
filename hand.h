#pragma once

class CardFactory;

#include <queue>
#include "card_hierarchy.h"
#include <vector>
using std::vector;
using std::queue;
using std::istream;
using std::ostream;

class Hand {
	queue<Card*> hand;

public:
	Hand(istream& in, CardFactory* factory);
	Hand() {};
	Card* play();
	Card* top() const;
	int getNumCards() const;
	Hand& operator+=(Card* card);
	Card* operator[](const int i);
	friend ostream& operator<<(ostream& out, Hand& oHand);
};