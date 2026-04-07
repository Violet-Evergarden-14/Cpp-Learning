#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	vector<int> list(4);
	for (int i = 0; i < 4; i++) cin >> list[i];

	int sum_up = 0;
	for (int k = 0; k < 4; k++) {
		int s = list[k];
		int m = 0;
		vector<int> time(s);
		for (int i = 0; i < s; i++) {
			cin >> time[i];
			m += time[i];
		}
		int total = m;
		m /= 2;
		vector<vector<int>> dp(s, vector<int>(m + 1, 0));
		dp[0][0] = 0;
		for (int i = 0; i < s; i++) {
			if (i == 0) {
				for (int j = m; j >= 0; j--) {
					if (time[i] <= j) dp[i][j] = time[i];
					else dp[i][j] = 0;
				}
				continue;
			}
			for (int j = m; j >= 0; j--) {
				if (time[i] > j) dp[i][j] = dp[i - 1][j];
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + time[i]);
				}
			}
		}
		sum_up += total - dp[s - 1][m];
	}
	cout << sum_up;
}