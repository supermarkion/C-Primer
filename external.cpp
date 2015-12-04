/*
	In the C++ language, we have three kinds of approaches to define
	static variables.
	1. int global = 1000; 			// static duration, external linkage
	2. static int one_file = 50;	// static duration, internal linkage
	3. void funct1(int n)
	   {
	    static int count = 0; 		// static duration, no linkage
	    int llama = 0;
	   }
*/

// external.cpp -- external variables
#include <iostream>
using namespace std;
double warming = 0.3;

void update(double dt);
void local();

int main()			// uses global variable
{
	cout << "Global warming is " << warming << " degrees.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degrees.\n";
	local();
	cout << "Global warming is " << warming << " degrees.\n";
	return 0;
}

void update(double dt)
{
	extern double warming;
	warming += dt;
	cout << "Updating global warming to " << warming;
	cout << " degrees.\n";
}

void local()
{
	double warming = 0.8;
	cout << "Local warming = " << warming << " degrees.\n";
	cout << "But global warming = " << ::warming;
	cout << " degrees.\n";
}