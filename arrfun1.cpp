// arrfun1.cpp -- functions with an array argument
#include <iostream>
const int ArSize = 8;

// please remember the two euqations:
// arr[i] == * *(ar + i) // values in two notations
// &arr[i] == ar + I // address in two notations

int sum_arr(int * arr, int n); 		// prototype
int main()
{
	using namespace std;
	int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
	cookies == &cookies[0];

	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten: " << sum << "\n";
	return 0;
}

int sum_arr(int * arr, int n)
{
	int total = 0;
	for (int i = 0; i < n; i++) {
		total = total + arr[i];
	}
	return total;
}