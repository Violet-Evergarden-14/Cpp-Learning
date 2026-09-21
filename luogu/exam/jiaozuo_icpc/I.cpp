#include <iostream>
#include <vector>
using namespace std;

void solve() {
	long long n; cin >> n;
	long long dist[n - 1];
	vector<long long> l(n / 2, 0);
	for (long long i = 0; i < n - 1; i++) cin >> dist[i];
	long long sum = 0;
	for (long long i = 0; i < n - 1; i++) sum += dist[i];
	l[0] = sum;
	for (long long i = 1; i < l.size(); i++)  l[i] = l[i - 1] - dist[i - 1] - dist[n - i - 1];
	for (long long i = 1; i < l.size(); i++) l[i] += l[i - 1];
	long long out = 0, idx = 0;
	for (long long i = 1; i < n; i++) {
		cout << out << " ";
		out += l[idx];
		if (i % 2 == 0) idx++;
	}
	cout << out << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long t; cin >> t;
	while (t-- > 0) {
		solve();
	}
}