#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> next_greater_element(vector<long long>& height) {
	long long n = height.size() - 1;
	vector<long long> next_greater(n + 1, n + 1);
	stack<long long> st;
	for (long long i = n; i >= 1; i--) {
		while (!st.empty() && height[st.top()] < height[i]) {st.pop();}
		if (!st.empty()) {next_greater[i] = st.top();}
		st.push(i);
	}
	return next_greater;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n;
	cin >> n;
	vector<long long> height(n + 1);
	for (long long i = 1; i <= n; i++) {cin >> height[i];}
	vector<long long> next_greater = next_greater_element(height);
	long long sum = 0;
	for (long long i = 1; i <= n; i++) {sum += next_greater[i] - i - 1;}
	cout << sum;
}