#include <iostream>
#include <random>
#include <algorithm>
#include "cardfactory.h"
CardFactory* CardFactory::getFactory() {
	static CardFactory factory;
	return &factory;
}
Deck CardFactory::getDeck() {
	Deck deck;

	for (int i = 0; i < 20; i++) {
		deck.push_back(new Quartz());
		if (i<18) deck.push_back(new Hematite());
		if (i<16) deck.push_back(new Obsidian());
		if (i<14) deck.push_back(new Malachite());
		if (i<12) deck.push_back(new Turquoise());
		if (i<10) deck.push_back(new Ruby());
		if (i<8) deck.push_back(new Amethyst());
		if (i<6) deck.push_back(new Emerald());
	}
	std::random_shuffle(deck.begin(), deck.end());
	return deck;
}
Card* CardFactory::createCard(const string& name) {
	Card* card = nullptr;
	if (name == "Quartz") {
		card = new Quartz();
	}
	else if (name == "Hematite") {
		card = new Hematite();
	}
	else if (name == "Obsidian") {
		card = new Obsidian();
	}
	else if (name == "Malachite") {
		card = new Malachite();
	}
	else if (name == "Turquoise") {
		card = new Turquoise();
	}
	else if (name == "Ruby") {
		card = new Ruby();
	}
	else if (name == "Amethyst") {
		card = new Amethyst();
	}
	else if (name == "Emerald") {
		card = new Emerald();
	}
	return card;
}