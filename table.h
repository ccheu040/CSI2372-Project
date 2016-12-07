#ifndef _Table_h_
#define _Table_h_

#include <vector>
#include <string>
#include "player.h"
#include "deck.h"

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
	bool win(string&);
	void print(ostream&);
	friend ostream& operator<< (ostream& out, Table& table);

};
#endif