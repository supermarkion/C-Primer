/*
A priority queue is an abstract data type that captures the idea of a container whose elements have "priorities" 
attached to them.  An element of highest priority always appears at the front of the queue. If that element 
is removed, the next  highest priority  element  advances to the front. 

The C++ standard library defines a class template priority_queue, with the following operations:
	push:  Insert an element into the prioity queue.
	top: Return (without removing it) a highest priority element from the priority queue.
	pop: Remove a highest priority element from the priority queue.
	size: Return the number of elements in the priority queue.
	empty: Return true or false according to whether the priority queue is empty or not.

*/

#include <queue>
// priority_queue<int> q1;
// priority_queue<string> q2;
#include <string>
#include <iostream>
#include <iomanip>
#include <array>

struct Time {
	int h;
	int m;
	int s;
};

class CompareTime {
public:
	bool operator() (Time& t1, Time& t2) {
		if (t1.h < t2.h) {
			return true;
		}
		if (t1.h == t2.h && t1.m < t2.m) {
			return true;
		}
		if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) {
			return true;
		}
		return false;
	}
};

using namespace std;

int main() {

	priority_queue<string> pq;
	// The strings are ordered inside the priority queue in lexicographic (dictionary) order:
    // "fox", "jumped over", "the lazy dog", "the quick"
    //  The lowest priority string is "fox", and the highest priority string is "the quick"
	pq.push("the quick");
	pq.push("fox");
	pq.push("jumped over");
	pq.push("the lazy dog");

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	priority_queue<Time, vector<Time>, CompareTime> timepq;
	Time t[4] = { {3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};
	for (int i = 0; i < 4; ++i) {
		timepq.push(t[i]);
	}

	while (! timepq.empty()) {
       Time t2 = timepq.top();
       cout << setw(3) << t2.h << " " << setw(3) << t2.m << " " <<
       setw(3) << t2.s << endl;
       timepq.pop();
    }

       

	return 0;
}