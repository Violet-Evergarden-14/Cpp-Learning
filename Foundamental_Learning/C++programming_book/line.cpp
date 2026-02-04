#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	Point(const Point &another) : x(std::move(another.x)), y(std::move(another.y)) {};
	int get_x() {return x;}
	int get_y() {return y;}
};

class Line
{
private:
	Point p1;
	Point p2;
	mutable double len;
public:
	Line(const Point &_p1, const Point &_p2) : p1(_p1), p2(_p2), len(-1) {};
	const double get_len();
};

const double Line::get_len()
{
	if (len < 0)
	{
		double delta_x = p1.get_x() - p2.get_x();
		double delta_y = p1.get_y() - p2.get_y();
		len = sqrt(delta_x * delta_x + delta_y * delta_y);
	}
	return len;
}