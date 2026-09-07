#include <iostream>
#include <cmath>
using namespace std;

void mul(int* res, int& len, int k) {
	for (int i = 0; i < len; i++) {
		res[i] *= k;
	}
	for (int i = 0; i < len; i++) {
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	while (res[len] != 0) {
		res[len + 1] = res[len] / 10;
		res[len] %= 10;
		len++;
	}
}

int main()
{
	int res[5000] = {0};
	res[0] = 1;
	int len = 1;
	int n;
	cin >> n;
	if (n <= 4) {
		cout << n << endl << n;
		return 0;
	}
	double x = (-1.0 + sqrt(1.0 + 8.0 * (n + 1))) / 2.0;
	int t = x;
	int m = n - ((t * (t + 1)) / 2 - 1);
	if (m == t) {
		for (int i = 3; i <= t; i++) {
			mul(res, len, i);
			cout << i << " ";
		}
		cout << t + 2 << endl;
		mul(res, len, t + 2);
	} else {
		for (int i = 2; i <= t - m; i++) {
			mul(res, len, i);
			cout << i << " ";
		}
		for (int i = t - m + 1; i <= t; i++) {
			mul(res, len, i + 1);
			cout << i + 1 << " ";
		}
		cout << endl;
		
	}
	for (int i = len - 1; i >= 0; i--) {
		cout << res[i];
	}
}