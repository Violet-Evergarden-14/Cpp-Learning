/*#include <iostream>
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

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> list1(n + 1), list2(n + 1);
	vector<int> pos1(n + 1), pos2(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> list1[i];
		pos1[list1[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> list2[i];
		pos2[list2[i]] = i;
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int m1 = 0, m2 = 0;
			if (pos2[list1[i]] <= j) m1 = 1 + dp[i - 1][pos2[list1[i]] - 1];
			if (pos1[list2[j]] <= i) m2 = 1 + dp[pos1[list2[j]] - 1][j - 1];
			dp[i][j] = max(max(m1, m2), dp[i - 1][j - 1]);
		}
	}
	cout << dp[n][n];
}