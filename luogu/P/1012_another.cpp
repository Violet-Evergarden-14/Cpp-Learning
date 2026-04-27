#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string& a, string& b) {
	return a + b > b + a;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end(), cmp);
	for (int i = 0; i < n; i++) cout << nums[i];
}