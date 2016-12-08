#include <random>
#include <algorithm>
#include "cardfactory.h"

CardFactory::CardFactory() {
	for (int i = 0; i < 20; i++) {
		_dCard.push_back(new Quartz());
		if (i<18) _dCard.push_back(new Hematite());
		if (i<16) _dCard.push_back(new Obsidian());
		if (i<14) _dCard.push_back(new Malachite());
		if (i<12) _dCard.push_back(new Turquoise());
		if (i<10) _dCard.push_back(new Ruby());
		if (i<8) _dCard.push_back(new Amethyst());
		if (i<6) _dCard.push_back(new Emerald());
	}
	//std::random_device rd;
	//std::mt19937 g(rd());
	//std::shuffle(_dCard.begin(), _dCard.end().g);
	std::random_shuffle(_dCard.begin(), _dCard.end());
}

CardFactory* CardFactory::getFactory() {
	static CardFactory* factory = new CardFactory();
	return factory;
}

Deck CardFactory::getDeck() {

}