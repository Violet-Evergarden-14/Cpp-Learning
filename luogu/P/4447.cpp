#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Student {public:
	int number, count;
};

struct Attr{
	bool in_or_not;
	int pos;
};

Attr find(int x, vector<Student> team) {
	int l = team.size();
	if (l == 0) return {false, 0};
	if (x < team[0].number) return {false, 0};
	if (x == team[0].number) return {true, 0};
	if (x > team[l - 1].number) return {false, l};
	if (x == team[l - 1].number) return {true, l - 1};
	int left = 0, right = l - 1;
	while (right - left >= 2) {
		int mid = (left + right) / 2;
		if (x == team[mid].number) return {true, mid};
		if (x > team[mid].number) left = mid;
		else right = mid;
	}
	return {false, right};
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Student> team;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		Attr res = find(a, team);
		if (res.in_or_not == true) team[res.pos].count++;
		else team.insert(team.begin() + res.pos, {a, 1});
	}

	int res = 2000000000;
	Student temp = team[0];
	int count = 0;
	priority_queue<int> pq;
	for (int i = 0; i < temp.count; i++) pq.push(0); 
	for (int i = 1; i < team.size(); i++) {
		count++;
		if (team[i].number == temp.number + 1) {
			if (team[i].count > temp.count) {
				for (int t = 0; t < team[i].count - temp.count; t++) {
					pq.push(-count);
				}
			}
			if (team[i].count < temp.count) {
				for (int t = 0; t < -team[i].count + temp.count; t++) {
					int m = pq.top();
					pq.pop();
					res = min(res, m + count);
				}
			}
		} else {
			for (int t = 0; t < temp.count; t++) {
				int m = pq.top();
				pq.pop();
				res = min(res, m + count);
			}
			count = 0;
			pq.push(0);
		}
		temp = team[i];
	}
	count++;
	for (int t = 0; t < temp.count; t++) {
		int m = pq.top();
		pq.pop();
		res = min(res, m + count);
	}
	cout << res;
}