#ifndef _CardFactory_h_
#define _CardFactory_h_

#include <vector>
#include "card_hierarchy.h"
#include "deck.h"
#include "discard_pile.h"
#include "chain.h"
#include "table.h"
#include "hand.h"
#include "player.h"
#include "trade_area.h"

using std::vector;
class CardFactory {
	vector<Card*> _dCard;
	Deck deck;
	DiscardPile pile;
	Hand hand;
	Table table;
public:
	static CardFactory* getFactory();
	Deck getDeck();
	vector<Card*> createGame();
};
#endif