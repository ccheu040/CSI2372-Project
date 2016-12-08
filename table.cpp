#include "table.h"

Table::Table(istream& in, CardFactory* factory) {
	
}

bool Table::win(string& winner) {
	if (!deck.draw()) {
		if (player1.getNumCoins() > player2.getNumCoins()) {
			winner = player1.getName();
		}
		else if (player1.getNumCoins() < player2.getNumCoins()) {
			winner = player2.getName();
		}
		return true;
	}
	else {
		return false;
	}
}

void Table::print(ostream& out) {

}

ostream& operator<<(ostream& out, Table& oTable) {
	out << oTable.player1 << oTable.player2 << oTable.pile << oTable.tradeArea;
}