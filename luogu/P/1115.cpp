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
	vector<int> sum(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a; 
	}
	int min = 0, id_min = 0, max = sum[1], id_max = 1;
	int delta = sum[1];
	int search = 1;
	while (search <= n) {
		int temp = min;
		if (sum[search] > max) {max = sum[search]; id_max = search;}
		if (sum[search] < min) {min = sum[search]; id_min = search;}
		if (id_min >= id_max) {
			int a = max - temp;
			if (a > delta) delta = a;
			id_max = id_min + 1;
			max = sum[id_max];
		}
		search++;
	}
	if (id_max != id_min && id_max != n + 1) {
		int a = max - min;
		if (a > delta) delta = a;
	}
	cout << delta;
}