#include <iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % j == 0) cout << j;
			else if (j % i == 0) cout << i;
			else cout << 1;
			cout << " ";
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}