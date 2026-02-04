#ifndef _POINT_H
#define _POINT_H

class Point
{
private:
	double x, y;
public:
	Point(double _x = 0, double _y = 0):x(_x), y(_y) {};
	~Point() {};
	double get_x() const {return x;}
	double get_y() const {return y;}
};

#endif