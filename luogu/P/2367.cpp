#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, p;
	cin >> n >> p;
	vector<int> d(n + 2);
	d[0] = 0;
	d[n + 1] = 0;
	int list[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> list[i];
		d[i] = list[i] - list[i - 1];
	}
	for (int i = 0; i < p; i++)
	{
		int l, r, delta;
		cin >> l >> r >> delta;
		d[l] += delta;
		d[r + 1] -= delta;
	}
	vector<int> res(n + 1);
	res[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		res[i] = res[i - 1] + d[i];
	}
	sort(res.begin() + 1, res.end());
	cout << res[1];
}