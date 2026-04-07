#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class Friend {public:
	ll lose, win, power;
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
	
	ll n, total;
	cin >> n >> total;
	vector<Friend> friends(n);
	for (ll i = 0; i < n; i++) {
		cin >> friends[i].lose >> friends[i].win >> friends[i].power;
	}
	vector<ll> dp(total + 1, 0);
	for (ll i = 0; i < n; i++) {
		for (ll j = total; j >= friends[i].power; j--) {
			dp[j] = max(dp[j] + friends[i].lose, dp[j - friends[i].power] + friends[i].win);
		}
		for (ll j = 0; j < friends[i].power; j++) {
			dp[j] += friends[i].lose;
		}
	}
	cout << dp[total] * 5;
}