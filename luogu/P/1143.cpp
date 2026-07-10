#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> s(16, 1);

void times(int m) {
	for (int i = 1; i < m; i++) {
		s[i] = s[i - 1] * m;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	times(n);
	int num = 0;
	string ori;
	cin >> ori;
	int l = ori.size();
	for (int i = 0; i < l; i++) {
		int t;
		if (ori[i] >= '0' && ori[i] <= '9') t = ori[i] - '0';
		else t = ori[i] - 'A' + 10;
		num += s[l - 1 - i] * t;
	}
	cin >> n;
	vector<char> res;
	while (num > 0) {
		int m = num % n;
		num /= n;
		if (m < 10) res.push_back(m + '0');
		else res.push_back(m - 10 + 'A');
	}
	for (int i = 0; i < res.size(); i++) cout << res[res.size() - 1 - i];
}