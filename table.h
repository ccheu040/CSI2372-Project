#ifndef _Table_h_
#define _Table_h_

#include "player.h"
#include "deck.h"
#include "discard_pile.h"
#include "trade_area.h"

using std::istream;
using std::ostream;

using std::vector;
class Table {
	Player* player1;
	Player* player2;
	Deck* deck;
	string winner;
	vector<Card*> cards;
public:
	Table(istream&, CardFactory*);
	Table();
	Table(vector<Card*>);
	Table(Player* player1, Player* player2, Deck* deck, DiscardPile* discardPile, TradeArea* tradeArea);
	bool win(string&);
	void print(ostream&);
};
#endif