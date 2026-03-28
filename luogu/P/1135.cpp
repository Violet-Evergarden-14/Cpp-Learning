#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Floor {
public:
	int floor;
	int numb;
	int way = -1;
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;
	if (a == b) {cout << 0; return 0;}
	vector<Floor> building(n + 1);
	for (int i = 1; i <= n; i++) {
		building[i].floor = i;
		cin >> building[i].numb;
	}
	queue<int> q;
	building[a].way = 0;
	q.push(a);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int m = building[now].floor + building[now].numb;
		if (m <= n && m >= 1 && building[m].way == -1) {
			building[m].way = building[now].way + 1;
			if (m == b) {cout << building[b].way; return 0;}
			q.push(m);
		}
		m = building[now].floor - building[now].numb;
		if (m <= n && m >= 1 && building[m].way == -1) {
			building[m].way = building[now].way + 1;
			if (m == b) {cout << building[b].way; return 0;}
			q.push(m);
		}
	}
	if (building[b].way == -1) cout << -1;
}