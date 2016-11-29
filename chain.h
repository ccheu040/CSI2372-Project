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
	string getChainType() {
		return _dChainType;
	}
};


template <class T>
class Chain : public Chain_Base {
	vector<T*> chain;

public:
	Chain(istream& in, CardFactory* factory) const;
	int sell() const;
	Chain<T>& operator+=(Card* card);
	friend ostream& operator << (ostream& out, const Chain<T>& oChain);
	friend istream& operator >> (istream& in, const Chain<T>& oChain);
};

template <class T>
Chain<T>::Chain(istream& in, CardFactory* factory) const {
	
}

template <class T>
int Chain<T>::sell() const {
	return T[0]->getCoinsPerCard(chain.size());
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

template <class T>
ostream& operator<<(ostream& out, const Chain<T>& oChain) {
	out << oChain.getChainType() << "\t";
	for (int i = 0; i < chain.size(); i++) {
		out << oChain[i] << " ";
	}
	out << std::endl;
	return out;
}

template <class T>
istream& operator >> (istream& in, const Chain<T>& oChain) {
	oChain += (in >> chain._dChainType);
}