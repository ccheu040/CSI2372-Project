#include <iostream>
#include <random>
#include <algorithm>
#include "cardfactory.h"
CardFactory* CardFactory::getFactory() {

}
Deck CardFactory::getDeck() {

}
vector<Card*> CardFactory::createGame() {
	Quartz* Quartz;
	Hematite* Hematite;
	Obsidian* Obsidian;
	Malachite* Malachite;
	Turquoise* Turquoise;
	Ruby* Ruby;
	Amethyst* Amethyst;
	Emerald* Emerald;
	for (int i = 0; i < 20; i++) {
		_dCard.push_back(Quartz);
		if (i<18) _dCard.push_back(Hematite);
		if (i<16) _dCard.push_back(Obsidian);
		if (i<14) _dCard.push_back(Malachite);
		if (i<12) _dCard.push_back(Turquoise);
		if (i<10) _dCard.push_back(Ruby);
		if (i<8) _dCard.push_back(Amethyst);
		if (i<6) _dCard.push_back(Emerald);
	}
	//std::random_device rd;
	//std::mt19937 g(rd());
	//std::shuffle(_dCard.begin(), _dCard.end().g);
	std::random_shuffle(_dCard.begin(), _dCard.end());

	return _dCard;
}