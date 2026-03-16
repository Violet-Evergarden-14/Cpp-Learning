#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> list(n);
	vector<int> sum(n);
	cin >> list[0];
	sum[0] = list[0];
	for (int i = 1; i < n; i++) {
		cin >> list[i];
		sum[i] = sum[i - 1] + list[i];
	}
	int ave = sum[n - 1] / n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (sum[i] != (i + 1) * ave) count++;
	}
	cout << count;
}