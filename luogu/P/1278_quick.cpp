#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> s;
vector<vector<int>> dp;

int Dfs(int x, int vis) {
	if (dp[x][vis]) return dp[x][vis];
	int best = 0;
	for (int j = 0; j < n; j++) {
		if (vis >> j & 1) continue;
		if (s[x].back() != s[j].front()) continue;
		best = max(best, Dfs(j, vis | (1 << j)));
	}
	return dp[x][vis] = best + (int)s[x].size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	dp.assign(n, vector<int>(1 << n, 0));
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, Dfs(i, 1 << i));
	cout << ans;
}
