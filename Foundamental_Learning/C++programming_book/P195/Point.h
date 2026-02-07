#ifndef _POINT_H
#define _POINT_H

class Point
{
private:
	int x, y;
public:
	static int count;
	Point();
	Point(int _x, int _y);
	~Point();

	void move(int _x, int _y);
	int get_x() const {return x;}
	int get_y() const {return y;}
	static void show_count();
};

#endif