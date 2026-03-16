#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Dots {
public:
	int x, y;
	friend bool operator<(const Dots& a, const Dots& b) {
		if (a.y < b.y) return true;
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, d;
	cin >> n >> d;
	vector<Dots> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i].x >> pos[i].y;
	}
	sort(pos.begin(), pos.end());
	if (pos[n - 1].y - pos[0].y < d) {cout << -1; return 0;}
	int min_delta = abs(pos[n - 1].x - pos[0].x);
	for (int i = 0; i < n; i++) {
		if (pos[i].y > pos[n - 1].y - d) {break;}
		int right = n - 1;
		while (pos[i].y <= pos[right].y - d) {
			int delta = abs(pos[right].x - pos[i].x);
			if (delta < min_delta) min_delta = delta;
			right--;
		}
	}
	cout << min_delta;
}