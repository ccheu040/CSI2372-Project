#ifndef _CardFactory_h_
#define _CardFactory_h_

#include <vector>
#include "card_hierarchy.h"
#include "deck.h"

using std::vector;

class CardFactory {
	vector<Card*> _dCard;
	Deck deck;

private:
	CardFactory();
	CardFactory(const CardFactory& factory) {};
	CardFactory& operator=(const CardFactory& factory) {};

public:
	static CardFactory* getFactory();
	Deck getDeck();
};
#endif