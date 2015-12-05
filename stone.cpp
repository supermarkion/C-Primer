// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt st, int n);

int main()
{
	Stonewt pavarotti = 260;
	Stonewt wolfe(285.7);
	Stonewt taft(21.8);

	cout << "The tenor weighted ";
	pavarotti.show_stn();
	cout << "The detective weighted ";
	wolfe.show_stn();
	cout << "The President weighted ";
	taft.show_lbs();
	pavarotti = 265.8;
	taft = 325;
	cout << "After dinner, the tenor weighted ";
	pavarotti.show_stn();
	cout << "After dinner, the President weighted ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighted even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";

	return 0;
}

void display (const Stonewt st, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Wow! ";
		st.show_stn();
	}
}