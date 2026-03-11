#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int change(int t, int n, int m) {
	for (int i = 1; i <= n; i++) {
		t = (t + m) % (n + i);
		if (t == 0) t = n + i;
	}
	return t;
}

bool judge(int* change_list, int k, int count) {
	if (change_list[count - 1] > k) return false;
	for (int i = 0; i < count - 1; i++) {
		if (change_list[i] == change_list[count - 1]) return false;
	}
	return true;
}

int main()
{
	int k;
	int m;
	while (cin >> k && k != 0) {
		int change_list[15];
		m = 1;
		A:
		for (int i = 1; i <= k; i++) {
			change_list[i - 1] = change(i, k, m);
			if (judge(change_list, k, i) == false) {
				do {m++;} while (m % (2 * k) >= 1 && m % (2 * k) <= k);
				goto A;
			}
		}
		cout << m << endl;
	}
}