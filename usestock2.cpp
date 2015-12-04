// usestock2.cpp -- using the Stock class
// compile with stock2.cpp
#include <iostream>
#include "stock2.h"

const int STKS = 4;
int main()
{
	using std::cout;
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	cout.precision(2);
	cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	cout.setf(std::ios_base::showpoint);

	cout << "Stock holidings:\n";
	int st;
	for (st = 0; st < STKS; st++) {
		stocks[st].show();
	}
	Stock top = stocks[0];
	for (st = 1; st < STKS; st++) {
		top = top.topval(stocks[st]);
	}
	cout << "\nMost valueable holding:\n";
	top.show();

	return 0;
}