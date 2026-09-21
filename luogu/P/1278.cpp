#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> s;

int solve(int t, int n) {
	swap(s[0], s[t]);
	int res = 0;
	vector<vector<int>> dis(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dis[i][j] = 0;
			else if (s[i][s[i].size() - 1] == s[j][0]) dis[i][j] = s[j].size();
			else dis[i][j] = -1;
		}
	}
	int full = 1 << n;
	vector<vector<int>> dp(full, vector<int>(n, -1));
	dp[1][0] = s[0].size();
	for (int mask = 1; mask < full; mask++) {
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) continue;
			if (dp[mask][i] == -1) continue;
			for (int j = 0; j < n; j++) {
				if ((mask & (1 << j)) || (i == j) || (dis[i][j] == -1)) continue;
				int now = max(dp[mask | (1 << j)][j], dp[mask][i] + dis[i][j]);
				dp[mask | (1 << j)][j] = now;
				res = max(res, now);
			}
		}
	}
	swap(s[0], s[t]);
	return res;
}

int main() {
	int n; cin >> n;
	s = vector<string>(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	int res = 0;
	for (int i = 0; i < n; i++) res = max(solve(i, n), res);
	cout << res;
}