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

			while (tradeArea.numCards() != 0) {
				bool played = false;
				Card* card = tradeArea.trade(tradeArea.getCards().front()->getName());
				// Add cards to chain or discard
				for (int i = 0; i < player.getNumChains; ++i) {
					Chain_Base* chain = &player[i];
					if (card->getName() == chain->getChainType()) {
						cout << "Adding " << card->getName() << " from trade area to chain." << endl;
						if (card->getName() == "Quartz") {
							dynamic_cast<Chain<Quartz>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Hematite") {
							dynamic_cast<Chain<Hematite>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Obsidian") {
							dynamic_cast<Chain<Obsidian>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Malachite") {
							dynamic_cast<Chain<Malachite>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Turquoise") {
							dynamic_cast<Chain<Turquoise>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Ruby") {
							dynamic_cast<Chain<Ruby>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Amethyst") {
							dynamic_cast<Chain<Amethyst>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Emerald") {
							dynamic_cast<Chain<Emerald>*>(chain)->operator+=(card);
						}
						played = true;
						break;
					}
				}
				if (!played) {
					if (player.getNumChains() < player.getMaxNumChains()) {

					}
				}
			}

			cout << "Top card: " << player.getHand().top() << endl;

			do {
				bool played = false;
				Card* card = player.getHand().play();
				for (int i = 0; i < player.getNumChains(); ++i) {
					Chain_Base* chain = &player[i];

					if (card->getName() == chain->getChainType()) {
						cout << "Card will be added to existing chain at index " << i << "." << endl;
						// Add card
						if (card->getName() == "Quartz") {
							dynamic_cast<Chain<Quartz>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Hematite") {
							dynamic_cast<Chain<Hematite>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Obsidian") {
							dynamic_cast<Chain<Obsidian>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Malachite") {
							dynamic_cast<Chain<Malachite>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Turquoise") {
							dynamic_cast<Chain<Turquoise>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Ruby") {
							dynamic_cast<Chain<Ruby>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Amethyst") {
							dynamic_cast<Chain<Amethyst>*>(chain)->operator+=(card);
						}
						else if (card->getName() == "Emerald") {
							dynamic_cast<Chain<Emerald>*>(chain)->operator+=(card);
						}
						played = true;
						break;
					}
				}
				if (!played) {
					if (player.getNumChains() < player.getMaxNumChains()) {
						cout << "Card will be added to empty chain at index " << player.getNumChains() << "." << endl;
						// Add card to new chain
						if (card->getName() == "Quartz") {
							player.getChains().push_back(new Chain<Quartz>(dynamic_cast<Quartz*>(card)));
						}
						else if (card->getName() == "Hematite") {
							player.getChains().push_back(new Chain<Hematite>(dynamic_cast<Hematite*>(card)));
						}
						else if (card->getName() == "Obsidian") {
							player.getChains().push_back(new Chain<Obsidian>(dynamic_cast<Obsidian*>(card)));
						}
						else if (card->getName() == "Malachite") {
							player.getChains().push_back(new Chain<Malachite>(dynamic_cast<Malachite*>(card)));
						}
						else if (card->getName() == "Turquoise") {
							player.getChains().push_back(new Chain<Turquoise>(dynamic_cast<Turquoise*>(card)));
						}
						else if (card->getName() == "Ruby") {
							player.getChains().push_back(new Chain<Ruby>(dynamic_cast<Ruby*>(card)));
						}
						else if (card->getName() == "Amethyst") {
							player.getChains().push_back(new Chain<Amethyst>(dynamic_cast<Amethyst*>(card)));
						}
						else if (card->getName() == "Emerald") {
							player.getChains().push_back(new Chain<Emerald>(dynamic_cast<Emerald*>(card)));
						}
					}
					else {
						cout << "There are no available chains to add the card." << endl;
						// print existing chains
						cout << player;
						cout << "Which chain would you like to sell? [1-" << player.getNumChains() << "]" << endl;
						int index;
						cin >> index;
						while (index < 1 || index > player.getNumChains()) {
							cout << "Please enter a valid number." << endl;
							cout << "Which chain would you like to sell? [1-" << player.getNumChains() << "]" << endl;
							cin >> index;
						}
						int coins = player[index - 1].sell();
						player.getChains().erase(player.getChains().begin() + index - 1);
						player += coins;
						cout << player;
						// Add card
						cout << "Card will be added to empty chain at index " << player.getNumChains() << "." << endl;
						if (card->getName() == "Quartz") {
							player.getChains().push_back(new Chain<Quartz>(dynamic_cast<Quartz*>(card)));
						}
						else if (card->getName() == "Hematite") {
							player.getChains().push_back(new Chain<Hematite>(dynamic_cast<Hematite*>(card)));
						}
						else if (card->getName() == "Obsidian") {
							player.getChains().push_back(new Chain<Obsidian>(dynamic_cast<Obsidian*>(card)));
						}
						else if (card->getName() == "Malachite") {
							player.getChains().push_back(new Chain<Malachite>(dynamic_cast<Malachite*>(card)));
						}
						else if (card->getName() == "Turquoise") {
							player.getChains().push_back(new Chain<Turquoise>(dynamic_cast<Turquoise*>(card)));
						}
						else if (card->getName() == "Ruby") {
							player.getChains().push_back(new Chain<Ruby>(dynamic_cast<Ruby*>(card)));
						}
						else if (card->getName() == "Amethyst") {
							player.getChains().push_back(new Chain<Amethyst>(dynamic_cast<Amethyst*>(card)));
						}
						else if (card->getName() == "Emerald") {
							player.getChains().push_back(new Chain<Emerald>(dynamic_cast<Emerald*>(card)));
						}
					}
				}
				cout << "Top card: " << player.getHand().top() << endl;
				cout << "Would you like to play this card? [Y/N]" << endl;
				getline(cin, input);
				while (input != "Y" && input != "y" && input != "N" && input != "n") {
					cout << "Please enter a valid response." << endl;
					cout << "Would you like to play this card? [Y/N]" << endl;
					getline(cin, input);
				}
			} while (input == "Y" || input == "y");
		}
	}
}