#pragma once

#include <string>
#include <vector>

class Point;
class Circle;

/**
通常而言，k和b的定义与常规数学定义一致
特别的，当k不存在的时候（无穷大），k采用Integer的最大值表示，此时的b表示竖线与x轴的交点
*/
class Line {
public:
	double k; // 斜率
	double b; // 截距

	Line(const std::string& ori_input);
	Line(double k, double b);

	Point* get_intersection_with(const Line& another);
	std::vector<Point*> get_intersection_with(const Circle& another);
};

