#include <iostream>
#include "player.h"
#include <exception>
#include <string>
using std::string
Player::Player(istream& in, CardFactory* factory) const {

}
Player::Player(string& name) const {
	name = name;
	coin = 0;
	numChain = 0;
	maxNumChain = 2;
}
string Player::getName() const {
	return name;
}
int Player::getNumCoins() const {
	return coin;
}
Player& Player::operator+=(int i) {
	this->coin += i;
	return *this;
}
int Player::getMaxNumChains() const {
	return maxNumChain;
}
int Player::getNumChains() const {
	return numChain;
}
Chain& Player::operator[](int i) {
	return *_dChain[i];
}
void Player::buyThirdChain() const {
	try {
		if (maxNumChain = 3) {
			throw MaxChainExistException;
		}
		else if (coin < 2) {
			throw NoEnoughCoinsException;
		}
		else {
			maxNumChain++;
		}
	}
	catch (MaxChainExistException& e) {
		std::cout << e.what()<<std::endl;
	}
	catch (NoEnoughCoinsException& e) {
		std::cout << e.what() << std::endl;
	}
}
void Player::printHand(ostream& out, bool p) {
	if (p) {
		out << ;
	}
	else {
		std::cout << hand->top()<<std::endl;
	}
}