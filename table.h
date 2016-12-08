#ifndef _Table_h_
#define _Table_h_

#include <string>
#include "player.h"
#include "deck.h"
#include "discard_pile.h"
#include "trade_area.h"
#include "cardfactory.h"

using std::istream;
using std::ostream;

class Table {
	vector<Player> players;
	Deck deck;
	DiscardPile pile;
	TradeArea tradeArea;
public:
	Table() {};
	Table(const string& name1, const string& name2);
	Table(istream&, CardFactory*);
	bool win(string&);
	vector<Player>& getPlayers();
	Deck& getDeck();
	DiscardPile& getPile();
	TradeArea& getTradeArea();
	void print(ostream&);
	friend ostream& operator<<(ostream& out, Table& oTable);
};
#endif