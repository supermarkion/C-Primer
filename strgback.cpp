#include <iostream>
char * buildstr(char c, int n);
int main()
{
	using namespace std;
	int times;
	char ch;

	cout << "Enter a character: ";
	cin >> ch;
	cout << "Enter an integer: ";
	cin >> times;
	char *ps = buildstr(ch, times); // use a char pointer to get a string
	cout << ps << endl;
	delete [] ps; // we can use delete to set ps to empty
	ps = buildstr('+', 20);
	cout << ps << "-Done-" << ps << endl;
	delete [] ps;
	return 0;
}

// builds string made of n c character
char * buildstr(char c, int n)
{
	char * pstr = new char[n + 1];
	pstr[n] = '\0'; // in C++, the end of array also is \0
	while (n-- > 0) {
		pstr[n] = c;
	}
	return pstr;
}