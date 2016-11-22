#pragma once

class Card;
class CardFactory;

#include <iostream>
#include <queue>

using std::queue;
using std::istream;
using std::ostream;

class Hand {
	queue<Card*> hand;

public:
	Hand(istream& in, CardFactory* factory);
	Card* play();
	Card* top() const;
	Hand& operator+=(Card* card);
	Card* operator[](const int i);
	friend ostream& operator<<(ostream& out, const Hand& hand);
};