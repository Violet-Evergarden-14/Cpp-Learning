#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

double line_fit(const Point points[], int number_of_points) {
	double avg_x = 0, avg_y = 0;
	double lxx = 0, lyy = 0, lxy = 0;
	for (int i = 0; i < number_of_points; i++) {
		avg_x += points[i].get_x();
		avg_y += points[i].get_y();
	}
	avg_x /= number_of_points;
	avg_y /= number_of_points;
	for (int i = 0; i < number_of_points; i++)
	{
		lxx += (points[i].get_x() - avg_x) * (points[i].get_x() - avg_x);
		lyy += (points[i].get_x() - avg_x) * (points[i].get_x() - avg_x);
		lxy += (points[i].get_x() - avg_x) * (points[i].get_y() - avg_y);
	}
	lxx /= number_of_points;
	lyy /= number_of_points;
	lxy /= number_of_points;
	cout << "This line can be fitted by line: ax + b" <<endl;
	cout << "a = " << lxy / lxx << endl;
	cout << "b = " << avg_y - lxy / lxx * avg_x << endl;
	return lxy / sqrt(lxx * lyy);
}

int main() {
	Point p[10] = {Point(6, 10), Point(14, 20), Point(26, 30), Point(33, 40), Point(46, 50),
				   Point(54, 60), Point(67, 70), Point(75, 80), Point(84, 90), Point(100, 100)};
	double r = line_fit(p, 10);
	cout << "Coefficiency: " << r << endl;
}