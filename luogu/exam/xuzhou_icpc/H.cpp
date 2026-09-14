#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

struct Data {
	int l, r, id;
	Data(): l(0), r(0), id(0) {};
	Data(int _l, int _r, int _id): l(_l), r(_r), id(_id) {};
	bool operator<(const Data& s) {
		if (l < s.l) return true;
		if (l > s.l) return false;
		return r < s.r;
	} 
};

int main() {
	int t, n, k, l, r;
	cin >> t;
	while (t-- > 0) {
		cin >> n >> k;
		vector<Data> line(n);
		for (int i = 0; i < n; i++) {
			cin >> l >> r;
			line[i] = Data(l, r, i);
		}
		sort(line.begin(), line.end());
		priority_queue<int, vector<int>, greater<int>> pq;
		long long now = 0, bef = 0, cnt = 0;
		int idx = 0;
		bool judge = false;

		while (idx < n || !pq.empty()) {
			long long nxt = (1LL << 62);
			if (idx < n) nxt = min(nxt, (long long)line[idx].l);
			if (!pq.empty()) nxt = min(nxt, (long long)pq.top());
			now = nxt;
			if (judge) cnt += now - bef;
			while (idx < n && line[idx].l == now) {
				pq.push(line[idx].r);
				idx++;
			}
			while (!pq.empty() && pq.top() == now)pq.pop();
			bef = now;
			judge = (pq.size() >= (size_t)k);
		}
		vector<long long> f(k, LLONG_MIN / 4);
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> hp;
		for (int g = 0; g < k; g++) hp.push(make_pair(f[g], g));
		vector<int> color(n);
		for (int i = 0; i < n; i++) {
			while (hp.top().first != f[hp.top().second]) hp.pop();
			int g = hp.top().second;
			hp.pop();
			color[line[i].id] = g;
			if ((long long)line[i].r > f[g]) f[g] = line[i].r;
			hp.push(make_pair(f[g], g));
		}

		cout << cnt << '\n';
		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			cout << color[i] + 1;
		}
		cout << '\n';
	}
}