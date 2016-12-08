#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Card {
private:
	Card(const Card& card) {};
	Card& operator=(const Card& card) {};

public:
	virtual int getCoinsPerCard(const int cards) const = 0;
	virtual string getName() const = 0;
	virtual void print(ostream& out) = 0;

	friend ostream& operator<<(ostream& out, Card& c) {
		out << c.getName();
		return out;
	}
};

class Quartz : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};

class Hematite : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};

class Obsidian : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};

class Malachite : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};

class Turquoise : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};

class Ruby : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};

class Amethyst : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};

class Emerald : public Card {
public:
	int getCoinsPerCard(const int cards) const;
	string getName() const;
	void print(ostream& out);
};