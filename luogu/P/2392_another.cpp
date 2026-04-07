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
		vector<int> dp(m + 1, 0);
		for (int i = 0; i < s; i++) {
			for (int j = m; j >= time[i]; j--) {
				dp[j] = max(dp[j], dp[j - time[i]] + time[i]);
			}
		}
		sum_up += total - dp[m];
	}
	cout << sum_up;
}