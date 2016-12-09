#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "cardfactory.h"
#include "chain.h"
#include "deck.h"
#include "discard_pile.h"
#include "card_hierarchy.h"
#include "hand.h"
#include "player.h"
#include "table.h"
#include "trade_area.h"
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {

	int selection;
	cout << "Do you want to load a pause game?" << endl;
	cout << "If you want, enter 1; else, enter 2" << endl;
	cin >> selection;
	if (selection == 1) {
		CardFactory* factory;
		std::ifstream file("saveGame.txt");
		string line = "";
		if (file) {
			Player(std::getline(file, line), factory);
			Hand(std::getline(file, line), factory);
			Chain<class T> Chain(std::getline(file, line), factory);
			Player(std::getline(file, line), factory);
			Hand(std::getline(file, line), factory);
			//Chain<class T> Chain(std::getline(file, line), factory);
			Deck(std::getline(file, line), factory);
			DiscardPile(std::getline(file, line), factory);
			TradeArea(std::getline(file, line), factory);
		}
	}
	else {

		string name1, name2, input;
		bool pause = false;

		cout << "Enter Player1's name:" << endl;
		cin.ignore();
		getline(cin, name1);
		cout << "Enter Player2's name:" << endl;
		cin.ignore();
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
					for (int i = 0; i < player.getNumChains(); ++i) {
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
							cout << "Do you want to start a new chain for " << card->getName() << "? [Y/N]" << endl;
							getline(cin, input);
							while (input != "Y" && input != "y" && input != "N" && input != "n") {
								cout << "Please enter a valid response." << endl;
								cout << "Do you want to start a new chain for " << card->getName() << "? [Y/N]" << endl;
								getline(cin, input);
							}
							if (input == "Y" || input == "y") {
								cout << "Adding " << card->getName() << " from trade area to chain." << endl;
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
								cout << "Discarding " << card->getName() << "." << endl;
								pile.getCards().push_back(card);
							}
						}
						else {
							cout << "Discarding " << card->getName() << "." << endl;
							pile.getCards().push_back(card);
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
					if (player.getHand().getNumCards() != 0) {
						cout << "Top card: " << player.getHand().top() << endl;
						cout << "Would you like to play this card? [Y/N]" << endl;
						getline(cin, input);
						while (input != "Y" && input != "y" && input != "N" && input != "n") {
							cout << "Please enter a valid response." << endl;
							cout << "Would you like to play this card? [Y/N]" << endl;
							getline(cin, input);
						}
					}
					else {
						cout << "You have no more cards." << endl;
						input = "N";
					}
				} while (input == "Y" || input == "y");


			}
		}
	}
}




void pauseGame(Table table) {
	vector<Player>& players = table.getPlayers();
	Deck& deck = table.getDeck();
	DiscardPile& pile = table.getPile();
	TradeArea& tradeArea = table.getTradeArea();
	std::ofstream ofs("saveGame.txt");
	string s = players.front().getName();
	ofs << s;
	ofs << "\n";
	while (!players.front().getHand().getHandCard().empty()) {
		string n= (const char*)players.front().getHand().getHandCard().front()->getName().at(0);
		players.front().getHand().getHandCard().pop();
		ofs << n;
	}
	ofs << "\n";
	while (!players.front().getChains().empty()) {
		string n = (const char*)players.front().getChains().back()->getChainType().at(0);
		int t = players.front().getChains().back()->getNumCards();
		players.front().getChains().pop_back();
		ofs << n << t;
	}
	ofs << "\n";
	s = players.back().getName();
	ofs << s;
	ofs << "\n";
	while (!players.back().getHand().getHandCard().empty()) {
		string n = (const char*)players.back().getHand().getHandCard().front()->getName().at(0);
		players.back().getHand().getHandCard().pop();
		ofs << n;
	}
	ofs << "\n";
	while (!players.back().getChains().empty()) {
		string n = (const char*)players.back().getChains().back()->getChainType().at(0);
		int t = players.back().getChains().back()->getNumCards();
		players.back().getChains().pop_back();
		ofs << n << t;
	}
	ofs << "\n";
	while (!deck.empty()) {
		string c = (const char*)deck.back()->getName().at(0);
		deck.pop_back();
		ofs << c;
	}
	ofs << "\n";
	while (!pile.getCards().empty()) {
		string p =(const char*)pile.getCards().back()->getName().at(0);
		pile.getCards().pop_back();
		ofs << p;
	}
	ofs << "\n";
	while (!tradeArea.getCards().empty()) {
		string t = (const char*)tradeArea.getCards().front()->getName().at(0);
		tradeArea.getCards().pop_front();
		ofs << t;
	}
	ofs << "n";
	table.print(ofs);
}


