#include <iostream>
#include "player.h"
#include <exception>
#include <string>
using std::string;
Player::Player(istream& in, CardFactory* factory){

}

Player::Player() {

}



Player::Player(string& name) {
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
Chain_Base& Player::operator[](int i) {
	return *_dChain[i];
}
void Player::buyThirdChain() const {
	
		if (maxNumChain == 3) {
			std::cout<< "Already have three chains" ;
		}
		else if (coin < 2) {
			std::cout << "Does not have enough coin";;
		}
		else {
			maxNumChain = 3;
			coin = coin - 2;
		}
	}
	
}
void Player::printHand(ostream& out, bool p) {
	if (p) {
		out << ;
	}
	else {
		std::cout << hand->top() << std::endl;
	}
}