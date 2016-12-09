
#include "player.h"

Player::Player(const string& name) : name(name), coins(0), maxNumChain(2) {}

Player::Player(istream& in, CardFactory* factory){
	string name;
	while (in.good()) {
		getline(in, name);
	}
	reverse(name.begin(), name.end());
	
	Player player(name);
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

vector<Chain_Base*>& Player::getChains() {
	return _dChain;
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

ostream& operator<<(ostream& out, Player& player) {
	out << player.getName() << "\t" << player.getNumCoins() << " coins" << std::endl;
	for (int i = 0; i < player._dChain.size(); ++i) {
		out << *player._dChain[i] << "\t";
		for (int j = 0; j < player._dChain[i]->getNumCards(); ++i) {
			out << player._dChain[i]->getChainType().at(0) << " ";
		}
		out << std::endl;
	}
	return out;
}