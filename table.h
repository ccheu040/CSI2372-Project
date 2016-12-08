#ifndef _Table_h_
#define _Table_h_

#include "player.h"
#include "deck.h"
#include "discard_pile.h"
#include "trade_area.h"

class Table {
	Player player1;
	Player player2;
	Deck deck;
	DiscardPile pile;
	TradeArea tradeArea;
	string winner;

public:
	Table() = default;
	Table(istream& in, CardFactory* factory);
	bool win(string& winner);
	void print(ostream& out);
	friend ostream& operator<<(ostream& out, Table& oTable);
};
#endif