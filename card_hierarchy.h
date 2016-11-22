#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Card {
public:
	virtual int getCoinsPerCard(const int cards) const = 0;
	virtual string getName() const = 0;
	virtual void print(ostream& out) const = 0;
};

class Quartz : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};

class Hematite : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};

class Obsidian : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};

class Malachite : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};

class Turquoise : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};

class Ruby : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};

class Amethyst : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};

class Emerald : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out) const;
};