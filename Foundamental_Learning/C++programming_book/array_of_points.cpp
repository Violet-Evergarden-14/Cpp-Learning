#include <iostream>
#include <cassert>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point() : x(0), y(0) {};
	Point(double _x, double _y):x(_x), y(_y) {};
	~Point() {};
	double get_x() const {return x;}
	double get_y() const {return y;}
};

class array_of_points
{
private:
	Point *points;
	int size;
public:
	array_of_points(int _size) : size(_size) {points = new Point[size];}
	~array_of_points() {
		cout << "Exiting..." << endl;
		delete[] points;
	}

	Point &element(int index) {
		assert(index >= 0 && index < size);
		return points[index];
	}
};

