#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1, 1);
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < n + 1 - k; i++) {
			if (i == 0) dp[i] = dp[i + 1];
			else dp[i] = dp[i + 1] + dp[i - 1];
		}
	}
	cout << dp[0];
}