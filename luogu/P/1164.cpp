#include <iostream>
#include <vector>
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> dish(n);
	for (int i = 0; i < n; i++) cin >> dish[i];
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= dish[i]; j--) {
			if (dish[i] > j) dp[j] = dp[j];
			if (dish[i] == j) dp[j] = dp[j] + 1;
			if (dish[i] < j) dp[j] = dp[j] + dp[j - dish[i]];
		}
	}
	cout << dp[m];
}