#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> ori(n + 1, 0);
	vector<int> neg;
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> ori[i];
		if (ori[i] < 0) neg.push_back(i);
		sum[i] = sum[i - 1] + ori[i];
	}
	int s = neg.size();
	int count = 0;
	for (int i = 1; i <= n; i++) {
		bool judge = true;
		for (int k = 0; k < s; k++) {
			int a;
			int j = neg[k] - i;
			if (j < 0) j += n;
			if (i + j <= n) a = sum[i + j] - sum[i - 1];
			else a = sum[n] - sum[i - 1] + sum[i + j - n];
			if (a < 0) {judge = false; break;}
		}
		if (judge == true) count++;
	}
	cout << count;
}