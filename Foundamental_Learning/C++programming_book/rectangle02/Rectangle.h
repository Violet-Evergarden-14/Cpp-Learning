#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle: private Point
{
private:
	double w, h;
public:
	void init_rectangle(double _x, double _y, double _w, double _h) {
		init_point(_x, _y);
		w = _w;
		h = _h;
	}
	void move(double off_x, double off_y) {Point::move(off_x, off_y);}
	double get_x() const {return Point::get_x();}
	double get_y() const {return Point::get_y();}
	double get_h() const {return h;}
	double get_w() const {return w;}
};

#endif