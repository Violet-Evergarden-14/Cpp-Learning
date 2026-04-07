#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int time_4(int k) {return k * k * k *k;}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int n;
	cin >> n;
	int m = sqrt(sqrt(n));
	vector<int> dp(n + 1);
	for (int i = 0; i <= n; i++) dp[i] = i;
	for (int i = 2; i <= m; i++) {
		for (int j = time_4(i); j <= n; j++) {
			dp[j] = min(1 + dp[j - time_4(i)], dp[j]);
		}
	}
	cout << dp[n];
}