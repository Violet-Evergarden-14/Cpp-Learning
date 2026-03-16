#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> list(n + 1, 0);
	for (int i = 0; i < n; i++) {cin >> list[i + 1];}
	int sum = list[1];
	int i = 2;
	int past = list[1];
	for (; i <= n; i++) {
		if (list[i] > list[i - 1]) {
			sum += list[i] - list[i - 1];
			past = list[i];
		}
	}
	cout << sum;
}