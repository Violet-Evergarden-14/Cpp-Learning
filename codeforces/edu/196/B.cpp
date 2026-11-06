#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> list(n);
	vector<int> cnt(n, 0);
	for (int i = 0; i < n; i++) cin >> list[i];
	sort(list.begin(), list.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cnt[i] == -1) continue;
			if (list[j] % list[i] == 0) {
				cnt[i]++; cnt[j] = -1;
			}
		}
	}
	int m = 0;
	for (int i = 0; i < n; i++) m = max(m, cnt[i]);
	cout << n - (m + 1) << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}