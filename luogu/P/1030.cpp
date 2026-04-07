#include <iostream>
#include <vector>
using namespace std;

class Herb {
public:
	int p, v;
	int w;
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int budget, amount;
	cin >> budget >> amount;
	vector<Herb> herbs(amount);
	for (int i = 0; i < amount; i++) {
		cin >> herbs[i].v >> herbs[i].p;
		herbs[i].w = herbs[i].v * herbs[i].p;
	}
	vector<int> dp(budget + 1, 0);
	for (int i = 0; i < amount; i++) {
		for (int j = budget; j >= herbs[i].v; j--) {
			dp[j] = max(dp[j], dp[j - herbs[i].v] + herbs[i].w);
		}
	}
	cout << dp[budget];
}