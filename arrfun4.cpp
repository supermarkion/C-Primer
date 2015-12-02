#include <iostream>
const int ArSize = 8;
int sum_arr(const int * begin, const int * end);

// if we use const to define a pointer, we can make the this pointer is static
// therefore, we should use const, to aviod modify some const value

// we fact a 2-dimensity matrix, we can also use * to get value two times
// ar2[r][c] == *(*(ar2 + r) + c)

int main()
{
	using namespace std;
	int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "Total cookies eaten: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "Last four eaters ate " << sum << " cookies.\n";
	return 0;
}

int sum_arr(const int * begin, const int * end)
{
	const int * pt;
	int total = 0;
	for (pt = begin; pt != end; pt++) {
		total = total + *pt; // pt is the index pointer
	}
	return total;
}