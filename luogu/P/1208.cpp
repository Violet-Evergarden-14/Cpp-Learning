#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NaiLong {
public:
	int price;
	int amount;
	friend bool operator<(const NaiLong& a, const NaiLong& b) {
		if (a.price < b.price) return true;
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	if (m == 0 || n == 0) {cout << 0; return 0;}
	vector<NaiLong> list(m);
	for (int i = 0; i < m; i++) {
		cin >> list[i].price >> list[i].amount;
	}
	sort(list.begin(), list.end());
	int k = 0;
	int budget = 0;
	while (n > list[k].amount) {
		n -= list[k].amount;
		budget += list[k].price * list[k].amount;
		k++;
	}
	budget += n * list[k].price;
	cout << budget;
}
