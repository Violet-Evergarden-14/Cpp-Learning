#include <iostream>
#include <vector>
using namespace std;

int find_head(int x, vector<int>& set) {
	if (x != set[x]) {
		set[x] = find_head(set[x], set);
	}
	return set[x];
}

void merge(int x, int y, vector<int>& set) {
	set[find_head(x, set)] = find_head(y, set);
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
	
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> set(n + 1);
	for (int i = 0; i <= n; i++) set[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b, set);
	}
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		if (find_head(a, set) == find_head(b, set)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}