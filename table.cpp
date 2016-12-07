#include <iostream>
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