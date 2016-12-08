#pragma once

class Card;
class CardFactory;

#include <iostream>
#include <vector>
#include "card_hierarchy.h"

using std::vector;
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
	virtual int sell() const = 0;
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
	int sell() const;
	int getNumCards() const;
	Chain<T>& operator+=(Card* card);
};

template <class T>
Chain<T>::Chain(T* t) : Chain_Base(t->getName()) {
	chain.push_back(t);
}

template <class T>
Chain<T>::Chain(istream& in, CardFactory* factory) {
	
}

template <class T>
int Chain<T>::sell() const {
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