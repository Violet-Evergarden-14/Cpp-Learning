#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Borrow {
public:
	long long d, s, t;
};

bool judge(vector<Borrow>& students, vector<long long>& rooms, long long n, long long days) {
	vector<long long> diff(n + 2, 0);
	vector<long long> sum_up(n + 1, 0);
	for (long long i = 1; i <= days; i++) {
		diff[students[i].s] += students[i].d;
		diff[students[i].t + 1] -= students[i].d;
	}
	for (long long i = 1; i <= n; i++) {
		sum_up[i] = sum_up[i - 1] + diff[i];
		if (sum_up[i] > rooms[i]) return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	vector<long long> rooms(n + 1, 0);
	for (long long i = 1; i <= n; i++) cin >> rooms[i];
	vector<Borrow> students(m + 1);
	for (long long i = 1; i <= m; i++) {
		cin >> students[i].d >> students[i].s >> students[i].t;
	}
	long long left = 1;
	long long right = m;
	if (judge(students, rooms, n, m) == true) {cout << 0 << endl; return 0;}
	if (judge(students, rooms, n, 1) == false) {cout << -1 << endl << 1; return 0;}
	else {cout << -1 << endl;}
	while (right - left > 1) {
		long long mid = (left + right) / 2;
		if (judge(students, rooms, n, mid) == true) left = mid;
		else right = mid;
	}
	cout << right << endl;
}