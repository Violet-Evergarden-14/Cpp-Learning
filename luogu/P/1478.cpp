#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, s, a, b;
	cin >> n >> s >> a >> b;
	int x, y;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x <= a + b) {
			v.push_back(y);
		}
	}
	vector<int> dp(s + 1, 0);
	for (int i = 0; i < v.size(); i++) {
		for (int j = s; j >= v[i]; j--) {
			dp[j] = max(dp[j], 1 + dp[j - v[i]]);
		}
	}
	cout << dp[s];
}