#pragma once

class Point {
public:
	double x;
	double y;

	Point(double x, double y);
	bool operator<(const Point& another)const;
};

