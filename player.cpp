#include "player.h"

Player::Player(const string& name) : name(name), coins(0), maxNumChain(2) {}

Player::Player(istream& in, CardFactory* factory){

}

string Player::getName() const {
	return name;
}

int Player::getNumCoins() const {
	return coins;
}

Player& Player::operator+=(int i) {
	coins += i;
	return *this;
}

int Player::getMaxNumChains() const {
	return maxNumChain;
}

int Player::getNumChains() const {
	return _dChain.size();
}

Hand& Player::getHand() {
	return hand;
}

Chain_Base& Player::operator[](int i) {
	return *_dChain[i];
}

void Player::buyThirdChain() {
	maxNumChain = 3;
	coins = coins - 3;
}
	
void Player::printHand(ostream& out, bool p) {
	if (p) {
		out << hand;
	}
	else {
		std::cout << hand.top() << std::endl;
	}
}