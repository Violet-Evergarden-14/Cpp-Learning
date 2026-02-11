#ifndef _POINT_H
#define _POINT_H

class Point
{
private:
	double x, y;
public:
	void init_point(double _x, double _y) {x = _x; y = _y;}
	void move(double off_x, double off_y) {x += off_x; y += off_y;}
	double get_x() const {return x;}
	double get_y() const {return y;}
};

#endif