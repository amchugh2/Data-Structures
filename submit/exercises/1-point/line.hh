#ifndef LINE_HH_
#define LINE_HH_

#include <string>
#include "point.hh"

struct Line{
	Point x,y;
	Line(Point x, Point y): x(x), y(y) {}

	// return length of function
	double length() const;

	std::string toString() const;
};

#endif

