#ifndef _CardFactory_h_
#define _CardFactory_h_

#include <vector>

class CardFactory {
	vector<Card*> _dCard;
public:
	static CardFactory* getFactory();
	Deck getDeck();
};
#endif