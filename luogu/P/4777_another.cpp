#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Student {public:
	int number, count;
	friend bool operator<(const Student& a, const Student& b) {return a.number < b.number;}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; 
	cin >> n;
	map<int, int> count_map;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		count_map[a]++;
	}
	vector<Student> team;
	for (auto& x : count_map) team.push_back({x.first, x.second});
	sort(team.begin(), team.end());
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
			for (int t = 0; t < team[i].count; t++) pq.push(0);
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