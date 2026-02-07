#include "Point.h"
#include <iostream>
using namespace std;

int Point::count = 0;

int main() {
	void (*ptr) () = &Point::show_count;      //静态成员不用指明哪个类
	int *ptr_number = &Point::count;
	cout << "Entering main.cpp..." << endl;
	Point a[2];
	for (int i = 0; i < 2; i++)
	{
		a[i].move(i + 10, i + 20);
	}
	ptr();
	cout << "Exiting main.cpp..." << endl;
}