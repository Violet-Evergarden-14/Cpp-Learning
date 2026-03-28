#include <iostream>
#include <vector>
using namespace std;

int count_move(vector<int>& diff, int n, int length) {
	int count = 0;
	int i = 1;
	int step = 0;
	while (i <= n + 1) {
		step += diff[i];
		if (step >= length) {
			count++;
			step = 0;
		}
		i++;
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int l, n, m;
	cin >> l >> n >> m;
	vector<int> stones(n + 2, 0);
	vector<int> diff(n + 2, 0);
	for (int i = 0; i < n; i++) cin >> stones[i + 1];
	stones[n + 1] = l;
	for (int i = 1; i < n + 2; i++) diff[i] = stones[i] - stones[i - 1];
	int left = 1;
	int right = l;
	while (right - left > 1) {
		int mid = (left + right) / 2;
		int count = count_move(diff, n, mid);
		if (n - count + 1 <= m) left = mid;
		else right = mid;
	}
	if (n - count_move(diff, n, right) + 1 <= m) cout << right;
	else cout << left;
}