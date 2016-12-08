
#include "player.h"
#include "cardfactory.h"

Player::Player(const string& name) : name(name), coins(0), maxNumChain(2) {}
Player::Player(istream& in, CardFactory* factory){
	string name;
	while (in.good()) {
		getline(in, name);
	}
	reverse(name.begin(), name.end());
	
	Player player(name);
	
	while ((const char*)s.back() != "") {
		s.pop_back();
		if ((const char*)s.back() == "Q") {
			player._dChain.front().(factory->createCard("Quartz"));
			s.pop_back();
		}
		else if ((const char*)s.back() == "H") {
			player.hand.operator+=(factory->createCard("Hematite"));
			s.pop_back();
		}
		else if ((const char*)s.back() == "o") {
			player.hand.operator+=(factory->createCard("Obsidian"));
			s.pop_back();
		}
		else if ((const char*)s.back() == "M") {
			player.hand.operator+=(factory->createCard("Malachite"));
			s.pop_back();
		}
		else if ((const char*)s.back() == "T") {
			player.hand.operator+=(factory->createCard("Turquoise"));
			s.pop_back();
		}
		else if ((const char*)s.back() == "R") {
			player.hand.operator+=(factory->createCard("Ruby"));
			s.pop_back();
		}
		else if ((const char*)s.back() == "A") {
			player.hand.operator+=(factory->createCard("Amethyst"));
			s.pop_back();
		}
		else if ((const char*)s.back() == "E") {
			player.hand.operator+=(factory->createCard("Emerald"));
			s.pop_back();
		}
	}
}


string Player::getName() const {
	return name;
}
int Player::getNumCoins() const {
	return coins;
}
Player& Player::operator+=(int i) {
	this->coins += i;
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

Chain_Base& Player::operator[](int i) {
	return *_dChain[i];
}
void Player::buyThirdChain() {
	
	maxNumChain=3;
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

Hand& Player::getHand() {
	return hand;
}
