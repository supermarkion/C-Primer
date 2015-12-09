/*
	There are four methods to use new operation
	#include <new>
	struct chaff
	{
		char dross[20];
		int slag;
	};
	char buffer1[50];
	char buffer2[500];
	int main()
	{
		chaff *p1, *p2;
		int *p3, *p4;
		// first, the reuglar forms of new
		p1 = new chaff;					// place a structure in heap
		p3 = new int[20];				// place int array in heap
		// now, the two forms of placement new
		p2 = new (buffer1) chaff;		// place structure in buffer1
		p4 = new (buffer2) int[20]; 	// place int array in buffer2
	}
*/

// newplace.cpp -- using placement new
#include <iostream>
#include <new>
const int BUF = 512;
const int N = 5;
char buffer[BUF];
int main()
{
	using namespace std;
	double *pd1, *pd2;
	int i;
	cout << "Calling new and placement new:\n";
	pd1 = new double[N];				// use heap
	pd2 = new (buffer) double[N];		// use buffer array
	for (i = 0; i< N; i++) {
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer addresses:\n" << " heap: " << pd1
		<< " static: " << (void *) buffer << endl;
	cout << "Buffer contents:\n";
	for (i = 0; i < N; i++) {
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	cout << "\nCalling new and placement new a second time:\n";
	double *pd3, *pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];
	for (i = 0; i < N; i++) {
		pd4[i] = pd3[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer contents:\n";
	for (i = 0; i < N; i++) {
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	cout << "\nCalling new and placement new a third time:\n";
	delete [] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++) {
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer contents:\n";
	for (i = 0; i < N; i++) {
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete [] pd1;
	delete [] pd3;
	
	return 0;
}