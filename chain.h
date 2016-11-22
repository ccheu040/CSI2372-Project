#pragma once

class Card;
class CardFactory;

#include <iostream>
#include <vector>

using std::vector;
using std::istream;
using std::ostream;

template <class T>
class Chain {
	vector<T*> chain;

public:
	Chain(istream& in, CardFactory* factory) const;
	int sell() const;
	Chain<T>& operator+=(Card* card);
	friend ostream& operator<<(ostream& out, const Chain<T>& oChain);
};

template <class T>
Chain<T>::Chain(istream& in, CardFactory* factory) const {

}

template <class T>
int Chain<T>::sell() const {
	return T.getCoinsPerCard(chain.size());
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

}