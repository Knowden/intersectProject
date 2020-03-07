#include "Point.h"

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

bool Point::operator<(const Point& another) const {
	if (this->x == another.x && this->y == another.y) {
		return false;
	}
	return true;
}
