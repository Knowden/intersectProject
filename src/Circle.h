#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <vector>

class Point;
class Line;

class Circle {
private:
	std::vector<Point> calculatePointsAtX(double x);
	std::vector<Point> calculateIntersectionWithNormalLine(Line& line);

public:
	Point* center;
	double r;

	Circle(const std::string& input);
	Circle(double x, double y, double r);


	std::vector<Point> getIntersectionWith(Line& line);
	std::vector<Point> getIntersectionWith(Circle& another);
};

#endif // !CIRCLE_H