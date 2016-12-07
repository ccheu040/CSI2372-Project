#include <iostream>
#include "table.h"

Table::Table(istream& in, CardFactory* factory) {
	while (in != null) {
		cards.push_back(in);
	}
}

Table::Table() {

}



bool Table::win(string& player) {
	if (deck->draw() == NULL) {
		if (first_player->getNumCoins() > second_player->getNumCoins()) {
			winner = first_player.getName();
		}
		else if (first_player->getNumCoins() < second_player->getNumCoins()) {
			winner = second_player.getName();
		}
		return true;
	}
	else {
		winner = null;
		return false;
	}

}
void Table::print(ostream& out) {

}