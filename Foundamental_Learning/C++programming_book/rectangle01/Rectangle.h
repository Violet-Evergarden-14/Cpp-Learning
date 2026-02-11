#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle: public Point
{
private:
	double w, h;
public:
	void init_rectangle(double _x, double _y, double _w, double _h) {
		init_point(_x, _y);
		w = _w;
		h = _h;
	}
	double get_h() const {return h;}
	double get_w() const {return w;}
};

#endif