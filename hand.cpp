#include <iostream>
#include "hand.h"
#include <vector>

using std::vector;

Hand::Hand(istream& in, CardFactory* factory) {
	
}

Hand::Hand() {


}
Hand::Hand(vector<Card*> card) {
	for (int i = 0; i < card.size(); i++) {
		hand.push(card[i]);
	}
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

Card* Hand::operator[](const int index) {
	vector<Card*> vHand;
	while (!hand.empty()) {
		vHand.push_back(hand.front());
		hand.pop();
	}
	Card* card = vHand[index];
	vHand.erase(vHand.begin() + index);
	for (int i = 0; i < vHand.size(); ++i) {
		hand.push(vHand[i]);
	}
	return card;
}

ostream& operator<<(ostream& out, Hand& oHand) {
	for (int i = 0; i < oHand.hand.size(); ++i) {
		out << *(oHand.hand.front()) << " ";
		oHand.hand.push(oHand.hand.front());
		oHand.hand.pop();
	}
	out << std::endl;
	return out;
}