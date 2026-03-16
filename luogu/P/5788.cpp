#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> next_greater_element(vector<int>& nums) {
	int n = nums.size() - 1;
	vector<int> next_greater(n + 1, 0);
	stack<int> st;
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && nums[st.top()] <= nums[i]) {st.pop();}
		if (!st.empty()) {next_greater[i] = st.top();}
		st.push(i);
	}
	return next_greater;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) {cin >> nums[i];}
	vector<int> next_greater = next_greater_element(nums);
	for (int i = 1; i <= n; i++) {cout << next_greater[i] << " ";}
}