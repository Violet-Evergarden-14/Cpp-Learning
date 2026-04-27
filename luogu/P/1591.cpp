#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HighPrecisionNumber {public:
	vector<int> num = vector<int>(5000, 0);
	int length = 0;

	HighPrecisionNumber(const string& s) {
		int l = s.size();
		for (int i = 0; i < l; i++) {
			num[i] = s[l - 1 - i] - '0';
		}
		if (!(l == 1 && num[0] == 0)) length = l;
	}

	HighPrecisionNumber(const int& s) {
		int t = s;
		int idx = 0;
		while (t > 0) {
			this->num[idx] = t % 10;
			t /= 10;
			idx++;
		}
		length = idx;
	}

	HighPrecisionNumber operator+(const HighPrecisionNumber& a) {
		HighPrecisionNumber res = HighPrecisionNumber("0");
		for (int i = 0; i < max(this->length, a.length); i++) {
			res.num[i] += this->num[i] + a.num[i];
			if (res.num[i] >= 10) {
				res.num[i + 1] += 1;
				res.num[i] -= 10;
			}
		}
		if (res.num[max(this->length, a.length)] == 1) res.length = max(this->length, a.length) + 1;
		else res.length = max(this->length, a.length);
		return res;
	}

	HighPrecisionNumber operator*(const HighPrecisionNumber& a) {
		HighPrecisionNumber res = HighPrecisionNumber("0");
		for (int i = 0; i < this->length + a.length + 1; i++) {
			int sum_up = 0;
			for (int j = 0; j <= i; j++) {
				sum_up += this->num[j] * a.num[i - j];
			}
			res.num[i] += sum_up;
			res.num[i + 1] += res.num[i] / 10;
			res.num[i] %= 10;
		}
		for (int i = 4999; i >= 0; i--) {
			if (res.num[i] > 0) {
				res.length = i + 1;
				break;
			}
		}
		return res;
	}

	HighPrecisionNumber operator*(int m) {
		HighPrecisionNumber res = HighPrecisionNumber("0");
		for (int i = 0; i < this->length; i++) {
			res.num[i] += this->num[i] * m;
			res.num[i + 1] += res.num[i] / 10;
			res.num[i] %= 10;
		}
		int idx = this->length;
		while (res.num[idx] >= 10) {
			res.num[idx + 1] += res.num[idx] / 10;
			res.num[idx] %= 10;
			idx++;
		}
		for (int i = 4999; i >= 0; i--) {
			if (res.num[i] > 0) {
				res.length = i + 1;
				break;
			}
		}
		return res;
	}

	void show() {
		if (length == 0) {cout << 0; return;}
		for (int i = 0; i < length; i++) {
			cout << num[length - 1 - i];
		}
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

	int t, n, a;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n >> a;
		int count = 0;
		HighPrecisionNumber res(1);
		for (int i = 1; i <= n; i++) res = res * i;
		for (int j = 0; j < res.length; j++) {
			if (res.num[j] == a) count++;
		}
		cout << count << endl;
	}
}