#ifndef _POINT_H
#define _POINT_H

class Point
{
private:
	int x, y;
	static int count;
public:
	Point();
	Point(int _x, int _y);
	~Point();

	void move(int _x, int _y);
	const int get_x() {return x;}
	const int get_y() {return y;}
	static void show_count();
};

#endif