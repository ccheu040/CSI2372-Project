#pragma once

class CardFactory;

#include <vector>
#include "card_hierarchy.h"

using std::vector;
using std::istream;
using std::ostream;

class Deck : public vector<Card*>{
public:
	Deck(istream& in, CardFactory* factory);
	Card* draw();
	friend ostream& operator<<(ostream& out, const Deck& oDeck);
};