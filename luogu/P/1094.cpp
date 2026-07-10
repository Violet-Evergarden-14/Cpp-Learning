#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int w, n;
	cin >> w >> n;
	vector<int> v(n);
	vector<int> vis(n, 0);
	for (int i = 0 ; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	int count = 0;
	for (i; i < n; i++) {
		if (vis[i] == 0) {
			count++;
			while (j > i) {
				if (v[i] + v[j] <= w) {
					vis[j] = 1;
					j--;
					break;
				}
				j--;
			}
		}
	}
	cout << count;
}