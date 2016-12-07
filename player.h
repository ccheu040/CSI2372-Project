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
	int coin;
	int numChain;
	int maxNumChain;
	vector<Chain_Base*> _dChain;
	Hand* hand;
public:
	Player(istream& in, CardFactory* factory) const;
	Player();
	Player(string& name) const;
	string getName() const;
	int getNumCoins() const;
	Player& operator+=(int num);
	int getMaxNumChains() const;
	int getNumChains() const;

	Chain_Base& operator[](int i);
	void buyThirdChain() const;
	void printHand(ostream& out, bool)


		friend ostream& operator<<(ostream& out, Player& player) {
		out << player.getName() << "  " << player.getNumCoins() << " coins" << std::endl;
		for (int i = 0; i < _dChain.size(); i++) {
			out << *_dChain[i];
		}
		return out;
	}
};
#endif