#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Wait {
public:
	int id;
	int time;
	friend bool operator<(const Wait& a, const Wait& b) {
		if (a.time < b.time) return true;
		if (a.time > b.time) return false;
		if (a.id > b.id) return false;
		return true;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
	
	int n;
	cin >> n;
	vector<Wait> wait(n);
	for (int i = 0; i < n; i++) {
		wait[i].id = i + 1;
		cin >> wait[i].time;
	}
	sort(wait.begin(), wait.end());
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += wait[i].time * (n - 1 -i);
		cout << wait[i].id << " ";
	}
	cout << endl;
	cout << fixed << setprecision(2) << sum / n;
}