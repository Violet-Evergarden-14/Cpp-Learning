#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x0fffffff;

int main() {
	int n; cin >> n;
	vector<vector<int>> dis(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> dis[i][j];
	}
	int full = 1 << n;
	vector<vector<int>> dp(full, vector<int>(n, INF));
	dp[1][0] = 0;
	for (int mask = 1; mask < full; mask++) {
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) continue;
			if (dp[mask][i] == INF) continue;
			for (int j = 0; j < n; j++) {
				if (mask & (1 << j)) continue;
				dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dis[i][j]);
			}
		}
	}
	int res = INF;
	for (int i = 1; i < n; i++) res = min(res, dp[full - 1][i] + dis[i][0]);
	cout << res;
}