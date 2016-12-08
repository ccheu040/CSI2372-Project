#include "table.h"

Table::Table(istream& in, CardFactory* factory) {
	
}

Table::Table() {

}

Table::Table(vector<Card*> card){
	for (int i = 0; i < card.size(); i++) {
		cards.push_back(card[i]);
	}
}

Table::Table(Player* player1, Player* player2, Deck* deck, DiscardPile* discardPile, TradeArea* tradeArea) {
	player1 = player1;
	player2 = player2;
	deck = deck;
	discardPile = discardPile;
	tradeArea = tradeArea;
}

bool Table::win(string& player) {
	if (deck->draw() == NULL) {
		if (player1->getNumCoins() > player2->getNumCoins()) {
			winner = player1->getName();
		}
		else if (player1->getNumCoins() < player2->getNumCoins()) {
			winner = player2->getName();
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