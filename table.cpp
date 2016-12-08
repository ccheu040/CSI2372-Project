#include "table.h"

Table::Table(const string& name1, const string& name2) {
	players.push_back(Player(name1));
	players.push_back(Player(name2));
	deck = CardFactory::getFactory()->getDeck();
	for (int i = 0; i < 5; ++i) {
		players.front().getHand() += deck.draw();
		players.back().getHand() += deck.draw();
	}
}

Table::Table(istream& in, CardFactory* factory) {
	
}

bool Table::win(string& winner) {
	Player player1 = players.front();
	Player player2 = players.back();
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


vector<Player>& Table::getPlayers() {
	return players;
}

Deck& Table::getDeck() {
	return deck;
}

DiscardPile& Table::getPile() {
	return pile;
}

TradeArea& Table::getTradeArea() {
	return tradeArea;
}

void Table::print(ostream& out) {
	out << *this;
}

ostream& operator<<(ostream& out, Table& oTable) {
	out << oTable.players.front() << oTable.players.back();
	if (!oTable.pile.getCards().empty()) {
		out << oTable.pile;
	}
	if (!oTable.tradeArea.getCards().empty()) {
		out << oTable.tradeArea;
	}
	return out;
}