#include "Line.h"
#include "Point.h"
#include "Circle.h"

Line::Line(const std::string& ori_input) {
}

Line::Line(double k, double b) {
}

Point* Line::get_intersection_with(const Line& another) {
	return nullptr;
}

std::vector<Point*> Line::get_intersection_with(const Circle& another) {
	return std::vector<Point*>();
}
