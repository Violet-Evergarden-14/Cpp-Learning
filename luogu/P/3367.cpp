#include <iostream>
#include <vector>
using namespace std;

int find_set(vector<int>& set, int x) {
	if (set[x] != x) {
		set[x] = find_set(set, set[x]);
	}
	return set[x];
}

void merge(vector<int>& set, int x, int y) {
	set[find_set(set, x)] = find_set(set, y);
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
	
	int n, m;
	cin >> n >> m;
	vector<int> set(n + 1);
	for (int i = 1; i <= n; i++) set[i] = i;
	for (int i = 0; i < m; i++) {
		int a, x, y;
		cin >> a >> x >> y;
		if (a == 1) merge(set, x, y);
		else {
			if (find_set(set, x) == find_set(set, y)) cout << "Y" << endl;
			else cout << "N" << endl;
		}
	}
}
