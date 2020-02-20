#include "line.hh"
#include <cmath>
#include <string>
#include <sstream>
#include <math.h>

// return distance
double Line::length() const{
	const auto dx = x.x - y.x;
	const auto dy = x.y - y.y;
	return sqrt(dx * dx + dy * dy);
}

std::string Line::toString() const{
	std::stringstream s;
	s << "(" << x.x << ", " << x.y << ") -- (" << y.x << ", " << y.y << ")";
	return s.str();
}
