#include "card_hierarchy.h"
#include <iostream>
/*
Quartz
*/
int Quartz::getCoinsPerCard(const int cards) const {
	if (cards >= 10) {
		return 4;
	}
	else if (cards >= 8) {
		return 3;
	}
	else if (cards >= 6) {
		return 2;
	}
	else if (cards >= 4) {
		return 1;
	}
	return 0;
}

string Quartz::getName() const {
	return "Quartz";
}

void Quartz::print(ostream& out) {
	out << *this;
}

/*
Hematite
*/
int Hematite::getCoinsPerCard(const int cards) const {
	if (cards >= 9) {
		return 4;
	}
	else if (cards == 8) {
		return 3;
	}
	else if (cards >= 6) {
		return 2;
	}
	else if (cards >= 3) {
		return 1;
	}
	return 0;
}

string Hematite::getName() const {
	return "Hematite";
}

void Hematite::print(ostream& out) {
	out << *this;
}

/*
Obsidian
*/
int Obsidian::getCoinsPerCard(const int cards) const {
	if (cards >= 8) {
		return 4;
	}
	else if (cards == 7) {
		return 3;
	}
	else if (cards >= 5) {
		return 2;
	}
	else if (cards >= 3) {
		return 1;
	}
	return 0;
}

string Obsidian::getName() const {
	return "Obsidian";
}

void Obsidian::print(ostream& out) {
	out << *this;
}

/*
Malachite
*/
int Malachite::getCoinsPerCard(const int cards) const {
	if (cards >= 7) {
		return 4;
	}
	else if (cards == 6) {
		return 3;
	}
	else if (cards == 5) {
		return 2;
	}
	else if (cards >= 3) {
		return 1;
	}
	return 0;
}

string Malachite::getName() const {
	return "Malachite";
}

void Malachite::print(ostream& out) {
	out << *this;
}

/*
Turquoise
*/
int Turquoise::getCoinsPerCard(const int cards) const {
	if (cards >= 7) {
		return 4;
	}
	else if (cards == 6) {
		return 3;
	}
	else if (cards >= 4) {
		return 2;
	}
	else if (cards >= 2) {
		return 1;
	}
	return 0;
}

string Turquoise::getName() const {
	return "Turquoise";
}

void Turquoise::print(ostream& out) {
	out << *this;
}

/*
Ruby
*/
int Ruby::getCoinsPerCard(const int cards) const {
	if (cards >= 6) {
		return 4;
	}
	else if (cards == 5) {
		return 3;
	}
	else if (cards == 4) {
		return 2;
	}
	else if (cards >= 2) {
		return 1;
	}
	return 0;
}

string Ruby::getName() const {
	return "Ruby";
}

void Ruby::print(ostream& out) {
	out << *this;
}

/*
Amethyst
*/
int Amethyst::getCoinsPerCard(const int cards) const {
	if (cards >= 5) {
		return 4;
	}
	else if (cards == 4) {
		return 3;
	}
	else if (cards == 3) {
		return 2;
	}
	else if (cards == 2) {
		return 1;
	}
	return 0;
}

string Amethyst::getName() const {
	return "Amethyst";
}

void Amethyst::print(ostream& out) {
	out << *this;
}

/*
Emerald
*/
int Emerald::getCoinsPerCard(const int cards) const {
	if (cards >= 3) {
		return 3;
	}
	else if (cards == 2) {
		return 2;
	}
	return 0;
}

string Emerald::getName() const {
	return "Emerald";
}

void Emerald::print(ostream& out) {
	out << *this;
}