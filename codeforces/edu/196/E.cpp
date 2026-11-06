#include <iostream>
#include <vector>
using namespace std;

int MOD = 998244353;

void solve() {
	int n; cin >> n;
	char s[n + 1]; cin >> s;
	if (n == 1) {cout << 1 << " " << 1 << endl; return;}
	if (n == 2) {
		if (s[0] == s[1]) cout << 2 << " " << 2 << endl;
		else cout << 4 << " " << 1 << endl;
		return;
	}
	for (int i = 0; i < n; i++) s[i] -= '0';
	int cnt = 0;
	int cnt1 = 0;
	int cnt0 = 0;
	int length = 0;
	vector<int> length_for_each;
	vector<char> safe;
	for (int i = 1; i < n - 1; i++) {
		if (s[i - 1] == s[i] && s[i] == s[i + 1]) {
			cnt++;
			if (s[i] == 0) cnt0++;
			else cnt1++;
		}
	}
	if (s[0] == s[1]) cnt++;
	if (s[n - 1] == s[n - 2]) cnt++;
	cout << 2 * n - cnt << " ";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}