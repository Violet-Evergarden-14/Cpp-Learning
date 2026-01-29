#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	int x, y;
	static int count;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {count++;}
	Point(const Point &another) : x(std::move(another.x)), y(std::move(another.y)) {count++;}
	~Point() {count--;}
	int get_x() {return x;}
	int get_y() {return y;}
	static void show_count() {cout << count << endl;}
	friend double dist(const Point &p1, const Point &p2);
};

double dist(const Point &p1, const Point &p2)
{
	double delta_x = p1.x - p2.x;
	double delta_y = p1.y - p2.y;
	return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int Point::count = 0;

int main()
{
	Point p1(2, 3);
	Point p2(-2, 0);
	cout << dist(p1, p2) << endl;
}

