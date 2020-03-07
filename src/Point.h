#ifndef POINT_H
#define POINT_H

#include <string>
#include <vector>

class Line;

class Point {
public:
	double x;
	double y;

	Point(double x, double y);
	bool operator<(const Point& another)const;

	double getDistanceToLine(const Line& line);
};

#endif // !POINT_H
