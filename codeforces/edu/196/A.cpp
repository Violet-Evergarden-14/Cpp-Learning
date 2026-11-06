#include <iostream>
using namespace std;

void solve() {
	int l, r; cin >> l >> r;
	if (l * r > 0) {cout << abs(l - r) << endl; return;}
	if (l * r < 0) {
		if (l + r == 0) {cout << 0 << endl; return;}
		else {cout << abs(l + r) - 1 << endl; return;}
	}
	if (abs(l + r) < 2) {cout << 0 << endl; return;}
	else cout << abs(l + r) - 1 << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}