#include <iostream>
#include <vector>
using namespace std;

class Food { public:
	int h, t, k;
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int h_max, t_max;
	int n;
	cin >> h_max >> t_max;
	cin >> n;
	vector<Food> choices(n);
	for (int i = 0; i < n; i++) {
		cin >> choices[i].h >> choices[i].t >> choices[i].k;
	}
	vector<vector<int>> dp(h_max + 1, vector<int>(t_max + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j1 = h_max; j1 >= choices[i].h; j1--) {
			for (int j2 = t_max; j2 >= choices[i].t; j2--) {
				dp[j1][j2] = max(dp[j1][j2], dp[j1 - choices[i].h][j2 - choices[i].t] + choices[i].k);
			}
		}
	}
	cout << dp[h_max][t_max];
}