#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> list(n);
	for (int i = 0; i < n; i++) cin >> list[i];
	if (n == 1) {cout << 1; return;}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}