#include <iostream>
using namespace std;

bool judge(int m, int k) {
	int pos = 0;
	for (int i = 0; i < k; i++) {
		pos = (pos + m - 1) % (2 * k - i);
		if (pos < k) return false;
	}
	return true;
}

int main()
{
	int list[15] = {0};
	int k;
	int m;
	while (cin >> k && k != 0) {
		if (list[k] != 0) {
			cout << list[k] << endl;
			continue;
		}
		m = 1;
		A:
		for (int i = 1; i <= k; i++) {
			if (judge(m, k) == false) {
				do {m++;} while (m % (2 * k) >= 1 && m % (2 * k) <= k);
				goto A;
			}
		}
		cout << m << endl;
		list[k] = m;
	}
}