#ifndef _Table_h_
#define _Table_h_

#include <vector>
#include <string>
#include "player.h"
#include "deck.h"
#include "discard_pile.h"
#include "trade_area.h"
#include "cardfactory.h"

using std::istream;
using std::ostream;

using std::vector;
class Table {
	Player* player1;
	Player* player2;
	Deck* deck;
	string winner;
public:

	Table(const string& name1, const string& name2);
	Table(istream&, CardFactory*);
	bool win(string&);
	void print(ostream&);
	friend ostream& operator<<(ostream& out, Table& oTable);
};
#endif