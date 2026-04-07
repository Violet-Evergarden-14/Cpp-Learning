#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Cow { public:
	int id, start, end;
	int fence = 0;
};

bool cmd1(const Cow& a, const Cow& b) {
	if (a.start < b.start) return false;
	if (a.start > b.start) return true;
	if (a.end < b.end) return false;
	else return true;
}

bool cmd2(const Cow& a, const Cow& b) {
	if (a.end < b.end) return false;
	if (a.end > b.end) return true;
	if (a.start < b.start) return false;
	else return true;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> place(n, 0);
	priority_queue<Cow, vector<Cow>, bool(*)(const Cow&, const Cow&)> pq1(cmd1);
	priority_queue<Cow, vector<Cow>, bool(*)(const Cow&, const Cow&)> pq2(cmd2);
	vector<int> fence_id(n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		pq1.push({i, start, end});
	}
	for (int i = 0; i < n; i++) {
		Cow cow = pq1.top();
		pq1.pop();
		if (!pq2.empty() && pq2.top().end < cow.start) {
			cow.fence = pq2.top().fence;
			pq2.pop();
		} else {
			count++;
			cow.fence = count;
		}
		pq2.push(cow);
		fence_id[cow.id] = cow.fence;
	}
	cout << count << endl;
	for (int i = 0; i < n; i++) cout << fence_id[i] << endl;
}