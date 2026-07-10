#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double a, b, c, d;

double f(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

double delta(double x) {
	return 3 * a * x * x + 2 * b * x + c;
}

double find_res(double x) {
	double temp = x + 1;
	double res = x;
	while (fabs(res - temp) > 0.001) {
		temp = res;
		res = temp - f(temp) / delta(temp);
	}
	return res;
}

int main()
{
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(2);

	double temp = f(-1.5);
	double now;
	for (double i = -1; i <= 100; i += 0.5) {
		if (fabs(f(i)) < 0.000001) {
			cout << i << " ";
			i += 0.5;
			temp = f(i);
		} else {
			now = f(i);
			if (now * temp < 0) {
				cout << find_res(i) << " ";
			}
			temp = f(i);
		}
	}
}