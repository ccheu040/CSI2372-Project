#pragma once

class CardFactory;

#include <iostream>
#include <vector>
#include <string>
#include "card_hierarchy.h"
#include "cardfactory.h"

using std::vector;
using std::string;
using std::istream;
using std::ostream;

class Chain_Base {
	string _dChainType;
public:
	Chain_Base(string name) {
		_dChainType = name;
	}
	string getChainType() {
		return _dChainType;
	}
	virtual int sell() = 0;
	virtual int getNumCards() const = 0;
	friend ostream& operator<<(ostream& out, Chain_Base& chain) {
		out << chain.getChainType();
		return out;
	}
};



template <class T>
class Chain : public Chain_Base {
	vector<T*> chain;

public:
	Chain(T* t);
	Chain(istream& in, CardFactory* factory);
	int sell();
	int getNumCards() const;
	Chain<T>& operator+=(Card* card);
};

template <class T>
Chain<T>::Chain(T* t) : Chain_Base(t->getName()) {
	chain.push_back(t);
}


template <class T>
Chain<T>::Chain(istream& in, CardFactory* factory) : Chain_Base("") {
	int numCards;
	string chainCard;
	while (in.good()) {
		getline(in, chainCard);
	}
	while ((const char*)chainCard.back() != "") {
		numCards = chainCard.back();
		chainCard.pop_back();
		if ((const char*)chainCard.back() == "Q") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Quartz");
			}
			chainCard.pop_back();
		}
		else if ((const char*)chainCard.back() == "H") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Hematite");
			}
			chainCard.pop_back();
		}
		else if ((const char*)chainCard.back() == "O") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Obsidian");
			}
			chainCard.pop_back();
		}
		else if ((const char*)chainCard.back() == "M") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Malachite");
			}
			chainCard.pop_back();
		}
		else if ((const char*)chainCard.back() == "T") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Turquoise");
			}
			chainCard.pop_back();
		}
		else if ((const char*)chainCard.back() == "R") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Ruby");
			}
			chainCard.pop_back();

		}
		else if ((const char*)chainCard.back() == "A") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Amethyst");
			}
			chainCard.pop_back();
		}
		else if ((const char*)chainCard.back() == "E") {
			for (int i = 0; i < numCards; i++) {
				*this += factory->createCard("Emerald");
			}
			chainCard.pop_back();
		}
	}
}

template <class T>
int Chain<T>::sell() {
	return chain[0]->getCoinsPerCard(chain.size());
}

template <class T>
int Chain<T>::getNumCards() const {
	return chain.size();
}

template <class T>
Chain<T>& Chain<T>::operator+=(Card* card) {
	try {
		T* gem = dynamic_cast<T*>(card);
		chain.push_back(gem);
		return *this;
	}
	catch (std::bad_cast& bc) {
		std::cout << "IllegalType" << std::endl;
	}
}
