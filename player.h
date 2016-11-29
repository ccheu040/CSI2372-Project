#ifndef _Player_h_
#define _Player_h_

#include <string>
#include "chain.h"
#include "hand.h"

using std::istream;
using std::string;
using std::ostream;

class Player {
	string name;
	int numCoins;
	int maxNumChains;
	vector<Chain_Base*> _dChain;
	Hand* hand;

public:
	Player(istream& in, CardFactory* factory);
	Player(string& name);
	string getName() const;
	int getNumCoins() const;
	Player& operator+=(int num);
	int getMaxNumChains() const;
	int getNumChains() const; 

	Chain_Base& operator[](int i);
	void buyThirdChain();
	void printHand(ostream& out, bool);

	friend ostream& operator<<(ostream& out, Player& player) {
		out << player.getName()<<"\t"<< player.getNumCoins()<<" coins"<<std::endl;
		for (int i = 0; i < _dChain.size(); i++) {
			out << *_dChain[i];
		}
		return out;
	}
};
#endif