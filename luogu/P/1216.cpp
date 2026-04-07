#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int r;
	cin >> r;
	vector<int> dp(r + 2, 0);
	vector<int> dp1(r + 2, 0);
	for (int k = 1; k <= r; k++) {
		vector<int> line(k + 1, 0);
		for (int i = 1; i <= k; i++) {
			cin >> line[i];
		}
		for (int i = k; i >= 1; i--) {
			dp1[i] = max(dp[i], dp[i - 1]) + line[i];
		}
		for (int i = 0; i <= r; i++) {
			dp[i] = dp1[i];
		}
	}
	int m = dp[1];
	for (int i = 2; i <= r; i++) {
		m = max(dp[i], m);
	}
	cout << m;
}