#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n, a, q;
	cin >> n >> a >> q;
	if (q == 0) {
		cout << fixed << setprecision(3) << 1.0;
		return 0;
	}
	char m;
	int same = 0, unsame = 0;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == '0') unsame++;
		else same++;
	}
	q = n - q;
	double p = a * 1.0 / 100;
	vector<vector<double>> dp(6, vector<double>(6, 0));
	double total = 0.0;
	dp[0][0] = pow(p, same) * pow(1 - p, unsame);
	total += dp[0][0];
	for (int i = 0; i <= q; i++) {
		for (int j = 0; j <= q - i; j++) {
			if (i == 0 && j == 0) continue;
			if (i > j) dp[i][j] = dp[i - 1][j] * (1 - p) / p * (same - i + 1) / i;
			else dp[i][j] = dp[i][j - 1] * p / (1 - p) * (unsame - j + 1) / j;
			total += dp[i][j];
		}
	}
	cout << fixed << setprecision(3) << total;
}