#include <iostream>
#include <cmath>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	Rectangle rect;
	rect.init_rectangle(2, 3, 20, 30);
	cout << rect.get_h() * rect.get_w() << endl;
}