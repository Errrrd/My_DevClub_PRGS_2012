#include <iostream>
#include <cmath>

#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getDistance(const Point& other) const {
	return hypot(x-other.x, y-other.y);
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

bool Point::operator==(const Point& other) const {
	return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
	// return !operator==(other);
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
	out << '(' << p.x << ", " << p.y << ')';
	return out;
}
