#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;

void solve() {
	double a, b, d, r;
	cin >> a >> b >> r >> d;
	d = d / 180 * PI;
	if (d > atan(b / (a + r))) cout << sqrt(b * b + (a + r) * (a + r)) - r << endl;
	else cout << r * cos(d) + b * sin(d) + a * cos(d) - r << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(20);
	int t; cin >> t;
	while (t-- > 0) {solve();}
}