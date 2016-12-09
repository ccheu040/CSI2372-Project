#include <iostream>
#include "hand.h"
#include <vector>
#include "cardfactory.h"
using std::vector;

Hand::Hand(istream& in, CardFactory* factory) {
	string handCard;
	while (in.good()) {
		getline(in,handCard);
	}
	while (handCard != "") {
		if ((const char*)handCard.back() == "Q") {
			hand.push(factory->createCard("Quartz"));
			handCard.pop_back();
		}
		else if ((const char*)handCard.back() == "H") {
			hand.push(factory->createCard("Hematite"));
			handCard.pop_back();
		}
		else if ((const char*)handCard.back() == "o") {
			hand.push(factory->createCard("Obsidian"));
			handCard.pop_back();
		}
		else if ((const char*)handCard.back() == "M") {
			hand.push(factory->createCard("Malachite"));
			handCard.pop_back();
		}
		else if ((const char*)handCard.back() == "T") {
			hand.push(factory->createCard("Turquoise"));
			handCard.pop_back();
		}
		else if ((const char*)handCard.back() == "R") {
			hand.push(factory->createCard("Ruby"));
			handCard.pop_back();
		}
		else if ((const char*)handCard.back() == "A") {
			hand.push(factory->createCard("Amethyst"));
			handCard.pop_back();
		}
		else if ((const char*)handCard.back() == "E") {
			hand.push(factory->createCard("Emerald"));
			handCard.pop_back();
		}
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


int Hand::getNumCards() const {
	return hand.size();
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
	out << "Hand\t";
	for (int i = 0; i < oHand.hand.size(); ++i) {
		out << *(oHand.hand.front()) << " ";
		oHand.hand.push(oHand.hand.front());
		oHand.hand.pop();
	}
	out << std::endl;
	return out;
}