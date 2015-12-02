#include <iostream>
#include <cmath>

struct polar
{
	double distance; 	// distance from origin
	double angle;		// direction from origin
};

struct rect
{
	double x;			// horizontal distance from origin
	double y;			// vertical distance from origin
};

// we can also give the address on return value, and 
// change it within function.

// prototypes
void rect_to_polar(const rect * pxy, polar * pda);
void show_polar(const polar * pda);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y) {
		rect_to_polar(&rplace, &pplace);
		show_polar(&pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Done.\n";
	return 0;
}

// convert rectangular to polar coordinates
void rect_to_polar(const rect * pxy, polar * pda)
{
	using namespace std;
	pda->distance = sqrt(pxy->x * pxy->x  * pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}

// show polar coordinates, converting angle to degrees
void show_polar(const polar * pda)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;

	cout << "Distance = " << pda->distance;
	cout << ", angle = " << pda->angle * Rad_to_deg;
	cout << " degrees\n";
}