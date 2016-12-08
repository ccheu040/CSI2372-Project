#ifndef _Player_h_
#define _Player_h_
#include "chain.h"
#include "hand.h"
#include <iostream>
#include <string>
#include <vector>
using std::istream;
using std::string;
using std::ostream;
class Player {
	string name;
	int coins;
	int maxNumChain;
	vector<Chain_Base*> _dChain;
	Hand hand;

public:
	Player() {};
	Player(const string& name);
	Player(istream& in, CardFactory* factory);
	string getName() const;
	int getNumCoins() const;
	Player& operator+=(int num);
	int getMaxNumChains() const;
	int getNumChains() const;
	vector<Chain_Base*>& getChains();
	Hand& getHand();

	Chain_Base& operator[](int i);
	void buyThirdChain();
	void printHand(ostream& out, bool p);

	friend ostream& operator<<(ostream& out, Player& player);
};
#endif