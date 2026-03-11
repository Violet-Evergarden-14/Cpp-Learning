#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_max_index(vector<int>& sum, int n, int m) {
	for (int i = n - 1; i >= 0; i--)
	{
		if (sum[i] == m) return i;
	}
	return -1;
}

int find_min_index(vector<int>& sum, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		if (sum[i] == m) return i;
	}
	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> sum(n);
	int a;
	cin >> a;
	sum[0] = a % 7;
	for (int i = 1; i < n; i++) {
		cin >> a;
		sum[i] = (sum[i - 1] + a) % 7;
	}

	int max[7];
	int min[7];
	vector<int> delta(7);
	for (int i = 0; i < 7; i++)
	{
		max[i] = find_max_index(sum, n, i);
		min[i] = find_min_index(sum, n, i);
		delta[i] = max[i] - min[i];
	}
	sort(delta.begin(), delta.end(), greater<int>());
	if (delta[0] < max[0] + 1) cout << max[0] + 1;
	else if (delta[0] > 0) cout << delta[0];
	else if (max[0] != -1) cout << 1;
	else cout << 0;
}