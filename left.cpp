// left.cpp -- string function with a default argument
#include <iostream>
const int ArSize = 80;
char * left (const char * str, int n = 1);

int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "Enter a string: \n";
	cin.get(sample, ArSize);
	char * ps = left(sample, 4);
	cout << ps << endl;
	delete [] ps;
	ps = left(sample);
	cout << ps << endl;
	delete [] ps;

	return 0;
}

// this function return a pointer to a new string
// consisting of the first n characters in the str string
char * left (const char * str, int n)
{
	if (n < 0) {
		n = 0;
	}
	char * p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++) {
		p[i] = str[i]; 		// copy characters
	}
	while (i <= n) {
		p[i++] == '\0';
	}
	return p;
}