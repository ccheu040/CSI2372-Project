#include "table.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
	string name1, name2, input;
	bool pause = false;

	cout << "Enter Player1's name:" << endl;
	getline(cin, name1);
	cout << "Enter Player2's name:" << endl;
	getline(cin, name2);

	Table table = Table(name1, name2);
	vector<Player>& players = table.getPlayers();
	Deck& deck = table.getDeck();
	DiscardPile& pile = table.getPile();
	TradeArea& tradeArea = table.getTradeArea();

	while (!deck.empty()) {
		if (pause) {
			break;
		}

		for (auto& player : players) {
			cout << "It is " << player.getName() << "'s turn." << endl;
			cout << table;

			if (player.getNumCoins() >= 3 && player.getMaxNumChains() == 2) {
				cout << "Do you want to buy a third chain? [Y/N]" << endl;
				getline(cin, input);
				while (input != "Y" && input != "y" && input != "N" && input != "n") {
					cout << "Please enter a valid response." << endl;
					cout << "Do you want to buy a third chain? [Y/N]" << endl;
					getline(cin, input);
				}
				if (input == "Y" || input == "y") {
					player.buyThirdChain();
				}
			}

			cout << "Drawing card from deck." << endl;
			player.getHand() += deck.draw();

			if (tradeArea.numCards() != 0) {
				for (int i = 0; i < tradeArea.numCards(); ++i) {
					// Add cards to chain or discard
				}
			}


		}
	}
}