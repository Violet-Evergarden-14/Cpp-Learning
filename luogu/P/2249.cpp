#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long square(long long x) {return x * x;}

int find(int t, vector<int>& list) {
	int n = list.size() - 1;
	if (t < list[1] || t > list[n]) return -1;
	if (t == list[1]) return 1;
	if (t == list[n]) return n;
	int l = 1, r = n;
	int mid;
	while (l < r - 1) {
		mid = (l + r) / 2;
		if (t == list[mid]) return mid;
		if (t < list[mid]) r = mid;
		else l = mid;
	}
	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> list(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> list[i];
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		int k = find(t, list);
		if (k == -1 || k == 1) {cout << k << " "; continue;}
		int l = 1, r = k;
		int mid;
		while (l < r - 1) {
			mid = (l + r) / 2;
			if (list[mid] == t) r = mid;
			else l = mid;
		}
		cout << r << " ";
	}
}