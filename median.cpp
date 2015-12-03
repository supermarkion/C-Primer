#include <iostream>
#include <vector>

using namespace std;
int recursionSearch(vector<int> numbers, int median, int start, int end);
int loopSearch(vector<int> numbers, int median);
int indexSearch(vector<int> numbers, int median);

// compare three versions of median search in a vector.
// the number list is sorted.
int main()
{
	std::vector<int> numbers = {1, 2, 3, 4, 6, 7, 9, 10, 12, 14, 15, 16};

	int median = 3; // first of all, we set a median which located in numbers
	cout << "We find the median number at " << recursionSearch(numbers, median, 0, numbers.size() - 1) 
		<< " index by recursionSearch method." << endl;
	cout << "We find the median number at " << loopSearch(numbers, median) 
		<< " index by loopSearch method." << endl;
	cout << "We find the median number at " << indexSearch(numbers, median) 
		<< " index by indexSearch method." << endl;

	median = 5; // then, set a median number not in numbers
	cout << "We find the nearest median number at " << recursionSearch(numbers, median, 0, numbers.size() - 1) 
		<< " index by recursionSearch method." << endl;
	cout << "We find the nearest median number at " << loopSearch(numbers, median) 
		<< " index by loopSearch method." << endl;
	cout << "We find the nearest median number at " << indexSearch(numbers, median) 
		<< " index by indexSearch method." << endl;

}

/*
	This method used recursion method to solve median number search in a number list.
*/
int recursionSearch(vector<int> numbers, int median, int start, int end)
{
	if (start + 1 >= end) {
		return start; // when two pointers meet together, still not find, return nearest index
	}
	int mid = start + (end - start) / 2;
	if (numbers[mid] == median) {
		return mid;
	} else if (numbers[mid] > median) {
		end = mid;
	} else {
		start = mid;
	}
	return recursionSearch(numbers, median, start, end);
}

/*
	This method used loop search method to solve median number search in a number list.
*/
int loopSearch(vector<int> numbers, int median)
{
	int start = 0;
	int end = numbers.size();
	while (start + 1 < end) {
		int mid = start + (end - start) / 2;
		if (numbers[mid] == median) {
			return mid;
		} else if (numbers[mid] > median) {
			end = mid;
		} else {
			start = mid;
		}
	}
	return start;
}

/*
	This method use normal index method to search for median number in a number list.
	Not a robust method, just act as an example.
*/
int indexSearch(vector<int> numbers, int median)
{
	int i = 0;
	while (i < numbers.size()) {
		if (numbers[i] == median) {
			return i;
		} else if (numbers[i] > median) {
			break;
		} else {
			i++;
		}
	}
	return i - 1;
}