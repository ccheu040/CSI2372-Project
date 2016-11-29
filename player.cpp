#include "player.h"
#include <exception>

using std::string;

Player::Player(istream& in, CardFactory* factory) {

}

Player::Player(string& name) : name(name), numCoins(0), maxNumChains(2) {}

string Player::getName() const {
	return name;
}

int Player::getNumCoins() const {
	return numCoins;
}

Player& Player::operator+=(int i) {
	numCoins += i;
	return *this;
}

int Player::getMaxNumChains() const {
	return maxNumChains;
}

int Player::getNumChains() const {
	return _dChain.size();
}

Chain_Base& Player::operator[](int i) {
	return *_dChain[i];
}

void Player::buyThirdChain() {
//	try {
		if (maxNumChains = 3) {
			throw "MaxChainExistException";
		}
		else if (numCoins < 2) {
			throw "NotEnoughCoinsException";
		}
		else {
			maxNumChains++;
		}
//	}
//	catch (MaxChainExistException& e) {
//		std::cout << e.what()<<std::endl;
//	}
//	catch (NotEnoughCoinsException& e) {
//		std::cout << e.what() << std::endl;
//	}
}

void Player::printHand(ostream& out, bool p) {
	if (p) {
		out << *hand;
	}
	else {
		std::cout << hand->top() << std::endl;
	}
}