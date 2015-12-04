/*
	In a head file, we should only consist of prototpye of functions,
	#define or const variables, struct defitnion, class defition,
	template defintion and inline function.
	Moreover, when we include man-made head file, we should not use 
	<> to cover it to aviod system search it in library.
	What is more, we can use CC file1.cpp file2.cpp to link to files.
*/

// coordin.h -- structure templates and function prototypes and structure templates
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double distance;		// distance from origin
	double angle;			// directin from origin
};
struct rect
{
	double x;				// horizontal distance from origin
	double y;				// vertical distance from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif