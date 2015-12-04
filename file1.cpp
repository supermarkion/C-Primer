// file1.cpp -- example of three-file program
#include <iostream>
#include "coordin.h"
using namespace std;

// in order to compile it, should better make main method located file start
// g++ file1.cpp file2.cpp -o linktest

int main()
{
	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y) {		// slick use of cin
		show_polar(pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}