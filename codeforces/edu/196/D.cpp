#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<vector<int>> aside(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		aside[u].push_back(v);
		aside[v].push_back(u);
	}
	if (n % 2 == 0) {cout << n + 1 << endl; return;}
	int target = (n + 1) / 2;
	for (int i = 0; i < aside[target].size(); i++) {
		set<int> side;
		int head = aside[target][i];
		queue<int> q;
		q.push(head);
		side.insert(head);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			for (int j = 0; j < aside[t].size(); j++) {
				if (aside[t][j] != target && side.count(aside[t][j]) == 0) {
					q.push(aside[t][j]);
					side.insert(aside[t][j]);
				}
			}
		}
		vector<int> res;
		for (int x : side) {
			res.push_back(x);
		}
		sort(res.begin(), res.end());
		if (res.size() % 2 != 0) {cout << n + 1 << endl; return;}
		int length = res.size();
		for (int j = 0; j < length / 2; j++) {
			if (res[j] + res[length - 1 - j] != n + 1) {cout << n + 1 << endl; return;}
		}
	}
	target = 1;
	for (int i = 0; i < aside[target].size(); i++) {
		set<int> side;
		int head = aside[target][i];
		queue<int> q;
		q.push(head);
		side.insert(head);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			for (int j = 0; j < aside[t].size(); j++) {
				if (aside[t][j] != target && side.count(aside[t][j]) == 0) {
					q.push(aside[t][j]);
					side.insert(aside[t][j]);
				}
			}
		}
		vector<int> res;
		for (int x : side) {
			res.push_back(x);
		}
		sort(res.begin(), res.end());
		if (res.size() % 2 != 0) {cout << n + 2 << endl; return;}
		int length = res.size();
		for (int j = 0; j < length / 2; j++) {
			if (res[j] + res[length - 1 - j] != n + 2) {cout << n + 2 << endl; return;}
		}
	}
	cout << n << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t-- > 0) {solve();}
}