#include <vector>
#include "hand.h"

using std::vector;

Hand::Hand(istream& in, CardFactory* factory) {

}

Card* Hand::play() {
	Card* card = hand.front();
	hand.pop();
	return card;
}

Card* Hand::top() const {
	return hand.front();
}

Hand& Hand::operator+=(Card* card) {
	hand.push(card);
	return *this;
}

Card* Hand::operator[](const int i) {
	vector<Card*> vHand;
	while (!hand.empty()) {
		vHand.push_back(hand.front());
		hand.pop();
	}
	Card* card = vHand[i];
	vHand.erase(vHand.begin() + i);

}

ostream& operator<<(ostream& out, const Hand& hand) {
	return out;
}