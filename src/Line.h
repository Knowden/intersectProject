#pragma once

#include <string>
#include <vector>

class Point;
class Circle;

/**
ͨ�����ԣ�k��b�Ķ����볣����ѧ����һ��
�ر�ģ���k�����ڵ�ʱ������󣩣�k����Integer�����ֵ��ʾ����ʱ��b��ʾ������x��Ľ���
*/
class Line {
public:
	double k; // б��
	double b; // �ؾ�

	Line(const std::string& ori_input);
	Line(double k, double b);

	Point* get_intersection_with(const Line& another);
	std::vector<Point*> get_intersection_with(const Circle& another);
};

