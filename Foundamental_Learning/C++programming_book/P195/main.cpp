#include "Point.h"
#include <iostream>
using namespace std;

int Point::count = 0;

int main() {
	cout << "Entering main.cpp..." << endl;
	Point a[2];
	for (int i = 0; i < 2; i++)
	{
		a[i].move(i + 10, i + 20);
	}
	cout << "Exiting main.cpp..." << endl;
}