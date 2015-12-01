// outfile.cpp -- write to a file
#include <iostream>
#include <fstream> 					// for file I/O 

int main()
{
	using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile; 				// create object for output
	outFile.open("carinfor.txt");	// associate with a file

	cout << "Enter the make and model of autombile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// display information on screen with cout

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << a_price << endl;
	cout << "Was aksing $" << a_price << endl;
	cout << "Not asking $" << d_price << endl;

	// now do exact same things using outFile instead of cout

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;

	outFile.close();
	return 0;
}