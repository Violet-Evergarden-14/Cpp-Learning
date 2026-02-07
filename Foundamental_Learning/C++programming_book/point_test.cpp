#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point();
	Point(int _x, int _y);
	~Point();
	int get_x() const {return x;}
	int get_y() const {return y;}
	void move(int _x, int _y) {x = _x; y = _y;}
};

Point::Point() : x(0), y(0) {
	cout << "Constructor called." << endl;
}

Point::Point(int _x, int _y) : x(_x), y(_y) {
	cout << "Constructor called." << endl;
}

Point::~Point() {
	cout << "Destuctor called" << endl;
}

int main()
{
	Point (*ptr)[20][10] = new Point[4][20][10];    //must include [20][10]
	ptr[3][2][1].move(321, 0);
	cout << ptr[3][2][1].get_x() << endl;
	delete[] ptr;
}