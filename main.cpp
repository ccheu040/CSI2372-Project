#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
main() {
	int selection;
	bool pauseGame = false;
	Deck deck;
	CardFactory factory;
	DiscardPile pile;
	TradeArea TradeArea;
	Table table;
	Player player1;
	Player player2;
	cout << "Do you want to load a pause game?" << endl;
	cout << "If you want, enter 1; else, enter 2" << endl;
	cin >> selection;
	if (selection == 1) {
		string fileName;
		cout << "Enter the filename you want to load" << endl;
		cin >> fileName;
		factory = loadfile(fileName);
	}
	else {
		factory = start_newGame();
	}
	while (deck.size() > 0) {
		if (pauseGame) {
			string fileName;
			cout << "Enter the filename you want to save" << endl;
			cin >> fileName;
			std::ofstream myfile;
			myfile.open(fileName);
			myfile << "Deck \n";
			myfile << deck << ;
			myfile << "DiscardPile \n";
			myfile << pile << ;
			myfile << "TradeArea \n";
			myfile << TradeArea << ;
			myfile << "Table \n";
			myfile << table << ;
			myfile << "Player1 \n";
			myfile << player1.getName();
			myfile << player1.getNumCoins();
			myfile << player1.getNumChains();
			for (int i = 0; i < player1.getNumChains(); i++) {
				myfile << player1._dChain[i];
			}
			myfile << player1.printHand();
			myfile << "Player2 \n";
			myfile << player2.getName();
			myfile << player2.getNumCoins();
			myfile << player2.getNumChains();
			for (int i = 0; i < player2.getNumChains(); i++) {
				myfile << player2._dChain[i];
			}
			myfile << player2.printHand();
		}
	}
}

CardFactory loadfile(string fileName) {
	string name;
	string stringCards;
	CardFactory factory;
	Player player1;
	Player player2;
	std::ifstream infile;
	infile.open(fileName);
	vector<Card*> cards;
	Deck Deck;
	DiscardPile DiscardPile;
	TradeArea TradeArea;
	Table Table;
	while (!infile.eof) {
		for (int i = o; i < 2; i++) {
			if (i == 1) {
				getline(infile, name);
			}
			else {
				getline(infile, stringCards);
			}
		}
		cards = stringToCard(stringCards);
		//to do the constructor for each class
		if (name == "Deck")  Deck(cards);
		else if (name == "DiscardPile") DiscardPile(cards);
		else if (name == "TradeArea") TradeArea(cards);
		else if (name == "Table") Table(cards);
		else if (name == "Player1") {
			player1.name = cards;
			string coins;
			getline(infile, coins);
			int coin;
			std::istringstream(coins) >> coin;
			player1.coin = coin;
			string chains;
			int chain;
			getline(infile, chains);
			std::istringstream(chains) >> chain;
			player1.numChain = chain;
			for (int a = 0; a < chain; a++) {
				string dchain;
				getline(infile, dchain);
				cards = stringToCard(dchain);
				player1._dChain[a](cards, factory);
			}
			getline(infile, stringCards);
			cards = stringToCard(stringCards);
			player1.hand(cards, factory);
		}
		else if (name == "Player2") {
			player2.name = cards;
			string coins;
			getline(infile, coins);
			int coin;
			std::istringstream(coins) >> coin;
			player2.coin = coin;
			string chains;
			int chain;
			getline(infile, chains);
			std::istringstream(chains) >> chain;
			player2.numChain = chain;
			for (int a = 0; a < chain; a++) {
				string dchain;
				getline(infile, dchain);
				cards = stringToCard(dchain);
				player2._dChain[a](cards, factory);
			}
			getline(infile, stringCards);
			cards = stringToCard(stringCards);
			player2.hand(cards, factory);
		}

	}
	infile.close();

	return factory;
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

vector<Card*> stringToCard(string stringCard) {
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
}
