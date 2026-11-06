#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n; cin >> n;
	int cur = 1;
	for (int i = 2; i <= n - 1; i++) cur ^= i;
	cur ^= 2 * n;
	int k = 0, m = n;
	while (m > 0) {++k; m /= 2;}
	vector<int> bits(k);
	for (int i = 0; i < k; i++) bits[i] = (cur >> i) & 1;
	vector<int> res;
	for (int i = k - 1; i > 0; i--) {
		if (bits[i] == 0) {
			bits[i - 1] = (~bits[i - 1]) & 1;
			res.push_back(1 << (i - 1));
		}
	}
	int length = res.size();
	int r = 0;
	for (int i = 1; i < n; i++) {
		bool judge = false;
		for (int j = 0; j < length; j++) {
			if (i == res[j]) {judge = true; break;}
		}
		if (judge == false) r ^= i;
		else r ^= 2 * i;
	}
	r ^= 2 * n;
	cout << r << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}