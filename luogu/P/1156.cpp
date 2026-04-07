#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Rubbish { public:
	int t, h, f;
	friend bool operator<(const Rubbish& a, const Rubbish& b) {
		return a.t < b.t;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
	
	int d, g;
	cin >> d >> g;
	vector<Rubbish> rubbish(g + 1);
	for (int i = 1; i <= g; i++) {
		cin >> rubbish[i].t >> rubbish[i].f >> rubbish[i].h;
	}
	sort(rubbish.begin() + 1, rubbish.end());
	vector<vector<int>> dp(g + 1, vector<int>(d + 1));
	dp[0][0] = 10;
	int ans = 10;
	for (int j = 1; j <= d; j++) dp[0][j] = -1;
	for (int i = 1; i <= g; i++) {
		for (int j = 0; j <= d; j++) {
			int a;
			if (dp[i - 1][j] < rubbish[i].t) {
				a = -1;
				ans = max(ans, dp[i - 1][j]);
			} else {
				a = dp[i - 1][j] + rubbish[i].f;
				ans = max(ans, dp[i - 1][j] + rubbish[i].f);
			}
			int b;
			int idx;
			if (j >= rubbish[i].h) idx = j - rubbish[i].h;
			else idx = 0;
			if (dp[i - 1][idx] < rubbish[i].t) {
				b = -1;
				ans = max(ans, dp[i - 1][idx]);
			} else {
				b = dp[i - 1][idx];
				ans = max(ans, dp[i - 1][idx]);
			}
			dp[i][j] = max(a, b);
		}
	}
	bool judge = false;
	for (int i = 1; i <= g; i++) {
		if (dp[i][d] >= rubbish[i].t) {
			judge = true;
			cout << rubbish[i].t;
			break;
		}
	}
	if (judge == false) cout << ans;
}