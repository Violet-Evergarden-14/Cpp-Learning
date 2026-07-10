#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n, f;
	cin >> n >> f;
	vector<long long> r(n + 1);
	for (long long i = 0; i < n; i++) cin >> r[i + 1];
	vector<vector<long long>> dp(n + 1, vector<long long>(f, 0));
	dp[0][0] = 1;
	long long m;
	for (long long i = 1; i <= n; i++) {
		for (long long j = 0; j < f; j++) {
			m = (j - r[i]) % f;
			if (m < 0) m += f;
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][m]) % 100000000;
		}
	}
	cout << (dp[n][0] - 1) % 100000000;
}