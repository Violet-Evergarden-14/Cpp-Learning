#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Alibaba {
public:
	double value;
	int amount;
	friend bool operator>(const Alibaba& a, const Alibaba& b) {
		if (a.value > b.value) return true;
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	cin >> m >> n;
	if (m == 0 || n == 0) {cout << 0; return 0;}
	vector<Alibaba> list(m);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> list[i].amount >> a;
		list[i].value = 1.0 * a / list[i].amount;
	}
	sort(list.begin(), list.end(), greater<Alibaba>());
	int k = 0;
	double budget = 0;
	while (n > list[k].amount && k < m) {
		n -= list[k].amount;
		budget += list[k].value * list[k].amount;
		k++;
	}
	if (k < m) budget += n * list[k].value;
	cout << fixed << setprecision(2) << budget;
}
