#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long ll;

ll count_section(vector<ll>& nums, ll n, ll max_add) {
	ll count = 1;
	ll i = 1;
	ll j = 1;
	ll dis = 0;
	while (i <= n && j <= n) {
		dis += nums[j];
		if (dis >= max_add) {
			i = j;
			count++;
			dis = 0;
			continue;
		}
		j++;
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	vector<ll> nums(n + 1, 0);
	ll sum_ = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> nums[i];
		sum_ += nums[i];
	} 
	if (m == 1) {
		cout << sum_ << endl;
		return 0;
	}
	auto max_val = max_element(nums.begin() + 1, nums.end());
	ll left = *max_val;
	ll right = sum_;
	while (right - left > 1) {
		ll mid = (left + right) / 2;
		ll count = count_section(nums, n, mid);
		if (count > m) left = mid;
		else right = mid;
	}
	cout << left;
}