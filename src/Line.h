#ifndef LINE_H
#define LINE_H

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
	long double k; // б��
	long double b; // �ؾ�

	Line(const std::string& ori_input);
	Line(long double k, long double b);

	Point* get_intersection_with(Line& another);
	std::vector<Point> get_intersection_with(Circle& another);
};

#endif // !LINE_H