// stacktem.cpp -- testing the template stack class
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Stack<std::string> st;
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order. \n"
		<< "P to process a PO, or Q to quit.\n";
	int number = 0;
	while (cin >> ch && std::toupper(ch) != 'Q') {
		while (cin.get() != '\n') {
			continue;
		}
		if (!std::isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a': cout << "Enter a PO number to add: ";
				cin >> po;
				if (st.isfull()) {
					cout << "stack alraedy full\n";
				} else {
					st.push(po);
					number++;
				}
				cout << "Contents: "
				for (int j = 0; j < number; j++) {
					cout << st[j] << " ";
				}
				cout << endl;
				break;
			case 'P':
			case 'p': if (st.isempty()) {
						cout << "stack alraedy empty\n";
					} else {
						st.pop(po);
						cout << "PO #" << po << " popped\n";
						break;
					}
					cout << "Contents: "
					for (int j = 0; j < number; j++) {
						cout << st[j] << " ";
					}
					cout << endl;
					break;

		}
		cout << "Please enter A to add a purchase order, \n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}