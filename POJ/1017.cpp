#include <iostream>
using namespace std;

void find_min_box(int a, int b, int c, int d, int e, int f) {
	int count = 0;
	count += d + e + f + c / 4 + 1;
	c %= 4;
	switch (c)
	{
	case 0:
		count--;
		break;
	case 1:
		b -= 5;
		a -= 7;
		break;
	case 2:
		b -= 3;
		a -= 6;
		break;
	case 3:
		b -= 1;
		a -= 9;
		break;
	default:
		break;
	}	
	a -= e * 11;
	b -= d * 5;
	if (b < 0) {
		a += b * 4;
		b = 0;
	}
	if (a < 0) a = 0;
	if (a > 0 || b > 0) {
		int m = a + b * 4;
		count += m / 36;
		if (m % 36 != 0) count++;
	}
	cout << count << endl;
}

int main()
{
	int a, b, c, d, e, f;
	while (cin >> a >> b >> c >> d >> e >> f) {
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) break;
		find_min_box(a, b, c, d, e, f);
	}
}