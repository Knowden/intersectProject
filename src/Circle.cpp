#include "Circle.h"
#include "Line.h"
#include "Point.h"

using namespace std;

string trim(string s) {
    if (s.empty()) {
        return s;
    }

    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

vector<string> split(const std::string& s, const std::string& c) {
    vector<string> result;

    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        result.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        result.push_back(s.substr(pos1));

    return result;
}

Circle::Circle(const string& input) {
    vector<string> infos = split(trim(input), " ");
    Circle(stod(infos.at(1)), stod(infos.at(2)), stod(infos.at(3)));
}

Circle::Circle(double x, double y, double r) {
    this->center = new Point(x, y);
    this->r = r;
}

vector<Point> Circle::getIntersectionWith(const Line& line) {
    vector<Point> result;

    double distance = this->center->getDistanceToLine(line);
    if (distance > this->r) {
        return result;
    }

    if (line.k == INT_MAX) {
        return calculatePointsAtX(line.b);
    }

    return calculateIntersectionWithNormalLine(line);
}

vector<Point> Circle::calculatePointsAtX(int x) {
   vector<Point> result;

   double common_part = sqrt(pow(r, 2) - pow(x - center->x, 2));
   double y1 = center->y + common_part;
   double y2 = center->y - common_part;

   result.push_back(Point(x, y1));
   result.push_back(Point(x, y2));

   return result;
}

double calulateYOfXInLine(const Line& line, double x) {
    return line.k * x + line.b;
}

vector<Point> Circle::calculateIntersectionWithNormalLine(const Line& line) {
    vector<Point> result;

    double t = line.b - center->y;

    double a = pow(line.k, 2) + 1;
    double b = 2 * (line.k * t - center->x);
    double c = pow(t, 2) + pow(center->x, 2) - pow(r, 2);

    double delta = sqrt(b * b - 4 * a * c);

    double x1 = (-b + delta) / (2 * a);
    double x2 = (-b - delta) / (2 * a);

    result.push_back(Point(x1, calulateYOfXInLine(line, x1)));
    result.push_back(Point(x2, calulateYOfXInLine(line, x2)));
    
    return result;
}

double calculateDistanceBetweenPoints(const Point& point1, const Point& point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

Line getCommonLineBetweenCricles(const Circle& c1, const Circle c2) {
    double a = 2 * (c2.center->x - c1.center->x);
    double b = 2 * (c2.center->y - c1.center->y);
    double c = (pow(c1.center->x, 2) + pow(c1.center->y, 2) - pow(c1.r, 2)) -
        (pow(c2.center->x, 2) + pow(c2.center->y, 2) - pow(c2.r, 2));

    return Line(-a / b, -c / b);
}

vector<Point> Circle::getIntersectionWith(const Circle& another) {
    vector<Point> result;

    double distance = calculateDistanceBetweenPoints(*center, *another.center);
    
    if (distance > r + another.r || distance < abs(r - another.r)) {
        return result;
    }

    Line common_line = getCommonLineBetweenCricles(*center, *another.center);
    return getIntersectionWith(common_line);
}
