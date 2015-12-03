// firstref.cpp -- defining and using a reference
// we use rodents as rats another name
// int rats;
// cint & rodents = rats; // make rodents an alias for rates

// we must initalize reference values

#include <iostream>
int main()
{
	using namespace std;
	int rats = 101;
	int & rodents = rats; 		//rodents is a reference

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ". rodents = " << rodents << endl;

	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;
	return 0;
}