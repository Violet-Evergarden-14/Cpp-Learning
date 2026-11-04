#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	vector<int> res(33);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	res[0] = a[n - 1] - a[0];
	for (int k = 1; k < 33; k++) {
		vector<int> cur;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				cur.push_back(a[i] ^ a[j]);
			}
		}
		sort(cur.begin(), cur.end());
		for (int i = 0; i < n; i++) a[i] = cur[i];
		res[k] = a[n - 1] - a[0];
	}
	for (int i = 0; i < q; i++) {
		int cur; cin >> cur;
		cout << res[min(cur, 32)] << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}