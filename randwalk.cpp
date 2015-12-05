// randwalk.cpp -- using the VEctor class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));			// seed random-number generator
	double direction;
	Vector step;
	Vector result (0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): "; // input 50
	while (cin >> target)
	{
		cout << "Enter step length: "; 			   // input 2
		if (! (cin >> dstep)) {
			break;
		}
		while (result.magval() < target) {
			direction = rand() % 360;
			step.set (dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location: \n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance (q to quit)";
	} 
	cout << "Bye!\n";

	return 0;
}
