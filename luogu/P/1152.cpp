#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int res[n] = {0};
	int a, b;
	cin >> a;
	for (int i = 0; i < n - 1; i++) {
		cin >> b;
		int t = abs(a - b);
		if (t <= 0 || t >= n) {
			cout << "Not jolly" << endl;
			return 0;
		} else {
			res[t]++;
		}
		a = b;
	}
	for (int i = 1; i < n; i++) {
		if (res[i] != 1) {
			cout << "Not jolly" << endl;
			return 0;
		}
	}
	cout << "Jolly" << endl;
}