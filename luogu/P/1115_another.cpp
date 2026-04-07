/*#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, ans = INT_MIN;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i == 0) s[i] = a;
		else s[i] = max(a, s[i - 1] + a);
		ans = max(ans, s[i]);
	}
	cout << ans;
}*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> list(n);
	for (int i = 0; i < n; i++) cin >> list[i];
	vector<int> dp(n + 1, 0);
	int sum = -10000000;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + list[i - 1], list[i - 1]);
		sum = max(sum, dp[i]);
	}
	cout << sum;
}