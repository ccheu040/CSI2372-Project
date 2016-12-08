#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <queue>
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
main() {
	int selection;
	bool pausegame = false;
	Deck* deck;
	CardFactory* factory;
	DiscardPile* pile;
	TradeArea* TradeArea;
	Table* table;
	Player* player1;
	Player* player2;
	queue<string> lastGame;
	cout << "Do you want to load a pause game?" << endl;
	cout << "If you want, enter 1; else, enter 2" << endl;
	cin >> selection;
	if (selection == 1) {
		
		lastGame = loadfile();
	}
	else {
		factory = start_newGame();
	}
	while (deck.size() > 0) {
		if (pausegame) pauseGame(player1, player2, deck, pile, TradeArea);
	}
}

queue<string> loadfile() {
	queue<string> s;
	string line;
	std::ifstream file;
	file.open("SavingGame.txt");
	while (getline(file, line)) {
		s.push(line);
	}
	return s;
}

void pauseGame(Player* player1, Player* player2, Deck* deck, DiscardPile* discardPile, TradeArea* tradeArea) {
	std::ofstream file;
	file.open("SavingGame.txt");
	string s = player1->getName();
	file << s;
	queue<Card*> cards = player1->getHand()->getHandCard();
	Card* card;
	while (!cards.empty()) {
		card = cards.pop();
		file << card->getName();
	}
	s = player2->getName();
	file << s;
	while (!cards.empty()) {
		card= cards.pop();
		file << card->getName();
	}
	cards = deck->getDeckCard();
	while (!cards.empty()) {
		card = cards.pop();
		file << card->getName();
	}
	cards = discardPile->getPileCard();
	while (!cards.empty()) {
		card = cards.pop();
		file << card->getName();
	}
	list<Card*> car = tradeArea->getTradeAreaCard();
	while (!cards.empty()) {
		card = car.pop_front();
		file << card->getName();
	}
	file.close();
}

CardFactory start_newGame() {
	CardFactory factory;
	string player1_name;
	string player2_name;
	cout << "Now, Let's play new game" << std::endl;
	cout << "Please enter player 1 's name" << endl;
	cin >> player1_name;
	cout << "Please enter player 2 's name" << endl;
	cin >> player2_name;
	Player player1(player1_name);
	Player player2(player2_name);
	CardFactory();
	//to do create game



	return factory;
}

/*vector<Card*> stringToCard(string stringCard) {
	vector<Card*> cards;
	Quartz* Quartz;
	Hematite* Hematite;
	Obsidian* Obsidian;
	Malachite* Malachite;
	Turquoise* Turquoise;
	Ruby* Ruby;
	Amethyst* Amethyst;
	Emerald* Emerald;
	char *charCards = new char[stringCard.length() + 1];
	std::strcpy(charCards, stringCard.c_str());
	for (int i = 0; i < stringCard.length() + 1; i++) {
		if (&charCards[i] == "Q") {
			cards.push_back(Quartz);
			}
		else if (&charCards[i] == "A") {
			cards.push_back(Amethyst);
		}
		else if (&charCards[i] == "H") {
			cards.push_back(Hematite);
		}
		else if (&charCards[i] == "O") {
			cards.push_back(Obsidian);
		}
		else if (&charCards[i] == "M") {
			cards.push_back(Malachite);
		}
		else if (&charCards[i] == "T") {
			cards.push_back(Turquoise);
		}
		else if (&charCards[i] == "R") {
			cards.push_back(Ruby);
		}
		else if (&charCards[i] == "E") {
			cards.push_back(Emerald);
		}
	}
	return cards;
}*/
