#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Relationship {public:
	int x, y;
	int relation;

	friend bool operator<(const Relationship& a, const Relationship& b) {
		return a.relation > b.relation;
	}
};

int find(int x, vector<int>& set) {
	if (set[x] != x) {
		set[x] = find(set[x], set);
	}
	return set[x];
}

void merge(int x, int y, vector<int>& set) {
	set[find(y, set)] = find(x, set);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> set(n * 2);
	vector<Relationship> relations;
	for (int i = 0; i < n * 2; i++) set[i] = i;
	int x, y, relation;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> relation;
		relations.push_back({x - 1, y - 1, relation});
	}
	sort(relations.begin(), relations.end());
	for (int i = 0; i < m; i++) {
		if (find(relations[i].x, set) != find(relations[i].y, set) && find(relations[i].x, set) != find(relations[i].y + n, set)) {
			merge(relations[i].x, relations[i].y + n, set);
			merge(relations[i].x + n, relations[i].y, set);
		} else {
			if (find(relations[i].x, set) == find(relations[i].y, set)) {
				cout << relations[i].relation;
				return 0;
			}
		}
	}
	cout << 0;
}