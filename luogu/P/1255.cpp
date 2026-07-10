#include <iostream>
#include <vector>
using namespace std;

class HighPrecisionNumber { public:
	int length;
	vector<int> number = vector<int>(2000, 0);

	HighPrecisionNumber(int n) {
		int t = n;
		int l = 0;
		while (t > 0) {
			number[l] = t % 10;
			l++;
			t /= 10;
		}
		length = l;
	}

	HighPrecisionNumber operator+(HighPrecisionNumber& a) {
		HighPrecisionNumber res(0);
		int l = max(this->length, a.length);
		for (int i = 0; i < l; i++) {
			res.number[i] += a.number[i] + this->number[i];
			res.number[i + 1] += res.number[i] / 10;
			res.number[i] %= 10;
		}
		if (res.number[l] == 0) res.length = l;
		else res.length = l + 1;
		return res;
	}

	void show() {
		for (int i = length - 1; i >= 0; i--) {
			cout << number[i];
		}
		cout << endl;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	vector<HighPrecisionNumber> s(n + 1, 1);
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		s[i] = s[i - 1] + s[i - 2];
	}
	s[n].show();
}