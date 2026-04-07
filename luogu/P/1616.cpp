#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

class Herb { public:
	ll time, value;
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	ll total_time, m;
	cin >> total_time >> m;
	vector<Herb> herb(m);
	for (ll i = 0; i < m; i++) {
		cin >> herb[i].time >> herb[i].value;
	}
	vector<ll> dp(total_time + 1, 0);
	for (ll i = 0; i < m; i++) {
		for (ll j = herb[i].time; j <= total_time; j++) {
			dp[j] = max(dp[j], dp[j - herb[i].time] + herb[i].value);
		}
	}
	cout << dp[total_time];
}