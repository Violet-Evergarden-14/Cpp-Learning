#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Path {public:
	int u, v, c;
	friend bool operator<(const Path& a, const Path& b) {
		return a.c < b.c;
	}
};

int find(int x, vector<int>& set) {
	if (x != set[x]) {
		set[x] = find(set[x], set);
	}
	return set[x];
}

void merge(int x, int y, vector<int>& set) {
	set[find(x, set)] = find(y, set);
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int cross_number, path_number;
	cin >> cross_number >> path_number;
	vector<int> set(cross_number + 1);
	for (int i = 1; i <= cross_number; i++) set[i] = i;
	vector<Path> choices(path_number + 1);
	for (int i = 1; i <= path_number; i++) {
		cin >> choices[i].u >> choices[i].v >> choices[i].c;
	}
	sort(choices.begin() + 1, choices.end());
	int max;
	for (int i = 1; i <= path_number; i++) {
		if (find(choices[i].u, set) != find(choices[i].v, set)) {
			max = choices[i].c;
			merge(choices[i].u, choices[i].v, set);
		}
	}
	cout << cross_number - 1 << " " << max;
}