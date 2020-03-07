#pragma once

class Point {
private:
	double x;
	double y;

public:
	Point(double x, double y);
	bool operator<(const Point& another)const;
};

