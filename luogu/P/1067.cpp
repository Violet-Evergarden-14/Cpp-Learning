#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 0) {
		cin >> n;
		cout << n;
		return 0;
	}
	if (n == 1) {
		cin >> n;
		if (n == 1) cout << "x";
		else if (n == -1) cout << "-x";
		else cout << n << "x";
		cin >> n;
		if (n == 0) return 0;
		if (n > 0) cout << "+" << n;
		else cout << n;
	}
	for (int i = 0; i < n + 1; i++) {
		int idx;
		cin >> idx;
		if (idx == 0) continue;
		if (i == 0) {
			if (abs(idx) == 1) {
				if (idx > 0) cout << "x^" << n;
				else cout << "-x^" << n;
			} else {
				cout << idx << "x^" << n;
			}
		} else if (i == n) {
			if (idx > 0) cout << "+" << idx;
			else cout << idx;
		} else if (i == n - 1) {
			if (abs(idx) == 1) {
				if (idx > 0) cout << "+x";
				else cout << "-x";
			} else {
				if (idx > 0) cout << "+" << idx << "x";
				else cout << idx << "x";
			}
		} else {
			if (abs(idx) == 1) {
				if (idx > 0) cout << "+x^" << n - i;
				else cout << "-x^" << n - i;
			} else {
				if (idx > 0) cout << "+" << idx << "x^" << n - i;
				else cout << idx << "x^" << n - i;
			}
		}
	}
}