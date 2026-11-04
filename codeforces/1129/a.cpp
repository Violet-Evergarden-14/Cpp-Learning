#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	int t;
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	t = 0;
	int res = 0;
	while (1) {
		while (t < v.size() && v[t] <= res) ++t;
		if (t != 0) --t;
		if (v[t] != res) {cout << res << endl; return;}
		if (t + 1 < k * (res + 1)) {cout << res << endl; return;}
		++res;
	}
}

int main() {
	int t; cin >> t;
	while (--t >= 0) {solve();}
}