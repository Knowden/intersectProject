#pragma once

#include <vector>
#include <string>

class Point;
class Line;

class Circle {
private:
	std::vector<Point> calculatePointsAtX(int x);
	std::vector<Point> calculateIntersectionWithNormalLine(const Line& line);

public:
	Point* center;
	double r;

	Circle(const std::string& input);
	Circle(double x, double y, double r);


	std::vector<Point> getIntersectionWith(const Line& line);
	std::vector<Point> getIntersectionWith(const Circle& another);
};

