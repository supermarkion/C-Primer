// funtemp.cpp -- using a function template
#include <iostream>
template <class Any> // or typename Any
void Swap(Any &a, Any &b);

// same to extend <T> in Java?

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ". " << j << ".\n";
	cout << "Using compiler-generated int swapper: \n";
	Swap(i, j);
	cout << "Now i, j = " << i << ". " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ". " << y << ".\n";
	cout << "Using compiler-generated double swapper: \n";
	Swap(x, y);
	cout << "Now x, y = " << x << ". " << y << ".\n";

	return 0;
}

// function template defintion
template <class Any>
void Swap(Any &a, Any &b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}