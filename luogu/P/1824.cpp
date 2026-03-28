#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_cow(vector<int>& house, int n, int length) {
	int count = 1;
	int i = 0;
	int j = 0;
	while (j < n && i < n) {
		int dis = house[j] - house[i];
		if (dis >= length) {
			count++;
			i = j;
		}
		j++;
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> house(n, 0);
	for (int i = 0; i < n; i++) cin >> house[i];
	sort(house.begin(), house.end());
	int left = 1;
	int right = house[n - 1] - house[0];
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (count_cow(house, n, mid) >= m) left = mid;
		else right = mid;
	}
	if (count_cow(house, n, right) >= m) cout << right;
	else cout << left;
}