#include <iostream>
#include <vector>

using namespace std;
int recursionSearch(vector<int> numbers, int target, int start, int end);
int loopSearch(vector<int> numbers, int target);
int indexSearch(vector<int> numbers, int target);

// compare three versions of target search in a vector.
// the number list is sorted.
int main()
{
	std::vector<int> numbers = {1, 2, 3, 4, 6, 7, 9, 10, 12, 14, 15, 16};

	int target = 3; // first of all, we set a target which located in numbers
	cout << "We find the target number at " << recursionSearch(numbers, target, 0, numbers.size() - 1) 
		<< " index by recursionSearch method." << endl;
	cout << "We find the target number at " << loopSearch(numbers, target) 
		<< " index by loopSearch method." << endl;
	cout << "We find the target number at " << indexSearch(numbers, target) 
		<< " index by indexSearch method." << endl;

	target = 5; // then, set a target number not in numbers
	cout << "We find the nearest target number at " << recursionSearch(numbers, target, 0, numbers.size() - 1) 
		<< " index by recursionSearch method." << endl;
	cout << "We find the nearest target number at " << loopSearch(numbers, target) 
		<< " index by loopSearch method." << endl;
	cout << "We find the nearest target number at " << indexSearch(numbers, target) 
		<< " index by indexSearch method." << endl;

}

/*
	This method used recursion method to solve target number search in a number list.
*/
int recursionSearch(vector<int> numbers, int target, int start, int end)
{
	if (start + 1 >= end) {
		return start; // when two pointers meet together, still not find, return nearest index
	}
	int mid = start + (end - start) / 2;
	if (numbers[mid] == target) {
		return mid;
	} else if (numbers[mid] > target) {
		end = mid;
	} else {
		start = mid;
	}
	return recursionSearch(numbers, target, start, end);
}

/*
	This method used loop search method to solve target number search in a number list.
*/
int loopSearch(vector<int> numbers, int target)
{
	int start = 0;
	int end = numbers.size();
	while (start + 1 < end) {
		int mid = start + (end - start) / 2;
		if (numbers[mid] == target) {
			return mid;
		} else if (numbers[mid] > target) {
			end = mid;
		} else {
			start = mid;
		}
	}
	return start;
}

/*
	This method use normal index method to search for target number in a number list.
	Not a robust method, just act as an example.
*/
int indexSearch(vector<int> numbers, int target)
{
	int i = 0;
	while (i < numbers.size()) {
		if (numbers[i] == target) {
			return i;
		} else if (numbers[i] > target) {
			break;
		} else {
			i++;
		}
	}
	return i - 1;
}