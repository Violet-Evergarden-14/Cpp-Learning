#include <iostream>
using namespace std;

int main()
{
	const int EPS = 1e-7;
	int n;
	cin >> n;
	double x, y;
	double area;
	double time;
	double time_int;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		cout << "Property " << i + 1 << ": This property will begin eroding in year ";
		area = 0.5 * (x * x + y * y) * 3.1415926;
		time = area / 50.0;
		time_int = int(time) + 1;
		if (-time_int + time + 1 < EPS) {cout << time_int - 1;} else {cout << time_int;}
		cout << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
}