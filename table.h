#ifndef _Table_h_
#define _Table_h_

#include <string>
using std::istream;
using std::ostream;

class Table {

public:
	Table(istream&, CardFactory*);
	bool win(string&);
	void print(ostream&);
	friend ostream& operator << (ostream& out, Table& table);
	friend istream& operator >> (istream& in, Table& table);

};
#endif