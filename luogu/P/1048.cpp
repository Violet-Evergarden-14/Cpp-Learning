#include <iostream>
#include <vector>
using namespace std;

class Herb {
public:
	int t, v;
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int total_time, m;
	cin >> total_time >> m;
	vector<Herb> herbs(m);
	for (int i = 0; i < m; i++) cin >> herbs[i].t >> herbs[i].v;
	vector<int> dp(total_time + 1, 0);
	for (int i = 0; i < m; i++) {
		for (int j = total_time; j >= herbs[i].t; j--) {
			dp[j] = max(dp[j], dp[j - herbs[i].t] + herbs[i].v);
		}
	}
	cout << dp[total_time];
}