#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> part1(n + 1, 0);
	vector<int> part2(n + 1, 0);
	for (int i = 0; i < n; i++) cin >> part1[i + 1];
	for (int i = 0; i < n; i++) cin >> part2[i + 1];
	vector<int> pos(n + 1, 0);
	for (int i = 1; i <= n; i++) pos[part2[i]] = i;
	vector<int> dp(n + 1, 0);
	vector<int> shadow(n + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = pos[part1[i + 1]]; j <= n; j++) {
			dp[j] = max(shadow[j], shadow[pos[part1[i + 1]] - 1] + 1);
		}
		for (int i = 1; i <= n; i++) shadow[i] = dp[i];
	}
	cout << dp[n];
}


/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> part1(n + 1, 0);
	vector<int> part2(n + 1, 0);
	for (int i = 0; i < n; i++) cin >> part1[i + 1];
	for (int i = 0; i < n; i++) cin >> part2[i + 1];
	vector<int> pos(n + 1, 0);
	for (int i = 1; i <= n; i++) pos[part2[i]] = i;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < pos[part1[i + 1]]) dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = max(dp[i][j], dp[i][pos[part1[i + 1]] - 1] + 1);
		}
	}
	cout << dp[n][n];
}
*/