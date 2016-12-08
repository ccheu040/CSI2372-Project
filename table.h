#ifndef _Table_h_
#define _Table_h_

#include "player.h"
#include "deck.h"
#include "discard_pile.h"
#include "trade_area.h"
#include "cardfactory.h"

class Table {
	vector<Player> players;
	Deck deck;
	DiscardPile pile;
	TradeArea tradeArea;

public:
	Table() {};
	Table(const string& name1, const string& name2);
	Table(istream& in, CardFactory* factory);
	bool win(string& winner);
	vector<Player>& getPlayers();
	Deck& getDeck();
	DiscardPile& getPile();
	TradeArea& getTradeArea();
	void print(ostream& out);
	friend ostream& operator<<(ostream& out, Table& oTable);
};
#endif