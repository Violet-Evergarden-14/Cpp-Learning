#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> sb(n, vector<int>(2));
	for (int i = 0; i < n; i++) cin >> sb[i][0] >> sb[i][1];
	int MAX = 1 << n;
	int d;
	int index = 1;
	int s = 1;
	int b = 0;
	for (int j = 0; j < n; j++) {
		if (index & 1 == 1) {
			s *= sb[j][0];
			b += sb[j][1];
			d = abs(s - b);
		}
	}
	vector<int> list(MAX);
	for (int i = 2; i < MAX; i++) {
		int index = i;
		int s = 1;
		int b = 0;
		for (int j = 0; j < n; j++) {
			if (index & 1 == 1) {
				s *= sb[j][0];
				b += sb[j][1];
				int delta = abs(s - b);
				if (delta < d) d = delta;
			}
			index >>= 1;
		}
	}
	cout << d;
}