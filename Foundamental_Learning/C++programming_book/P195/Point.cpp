#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() {
	x = y = 0;
	cout << "Default Constructor called." << endl;
	count++;
}

Point::Point(int _x, int _y) : x(_x), y(_y) {
	cout << "Constructor called." << endl;
	count++;
}

Point::~Point() {
	cout << "Dstructor called." << endl;
}

void Point::move(int _x, int _y) {
	x = _x;
	y = _y;
	cout << "Moving the point to ("<< _x <<", "<< _y <<")" << endl;
}

void Point::show_count() {
	cout << count << endl;
}