#include <iostream>
#include <vector>
using namespace std;

bool check(int length, int k, vector<int>& road) {
	int count = 0;
	for (int i = 0; i < road.size() - 1; i++) {
		int l = road[i + 1] - road[i];
		count += (l - 1) / length;
	}
	if (count > k) return false;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int l, n, k;
	cin >> l >> n >> k;
	vector<int> road;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		road.push_back(a);
	}
	int left = 1;
	int right = l;
	if (n + k >= l) {
		cout << 1;
		return 0;
	}
	int mid;
	while (right - left > 1) {
		mid = (left + right) / 2;
		if (check(mid, k, road) == true) {
			right = mid;
		} else left = mid;
	}
	cout << right;
}