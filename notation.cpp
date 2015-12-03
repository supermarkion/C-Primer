#include <iostream>
#include <stdlib.h>
using namespace std;

double notation()
{
	char str[10];
	cin >> str;
	switch(str[0])
	{
		case '+':
			return notation() + notation();
		case '-':
			return notation() - notation();
		case '*':
			return notation() * notation();
		case '/':
			return notation() / notation();
		default:
			cout << atof(str) << endl;  
			return atof(str);
	}
}

int main()
{
	cout << notation() << endl;
	return 0;
}

// * / + 12 36 + 1 3 - 15 8
