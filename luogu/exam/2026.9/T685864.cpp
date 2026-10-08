#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int cnt = 0;
	vector<char> list(n + 1);
	for (int i = 1; i <= n; i++) cin >> list[i];
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		if ((r - l) % 2 == 0) {
			cout << -1; return 0;
		}
		int cnt1 = 0;
		for (int j = l; j <= r; j++) {
			if (list[j] == '1') cnt1++;
		}
		if (cnt1 * 2 != (r - l + 1)) cnt++;
	}
	cout << (cnt + 1) / 2;
}