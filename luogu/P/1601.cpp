#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HighPrecisionNumber {public:
	vector<int> num = vector<int>(501, 0);
	int length = 0;

	HighPrecisionNumber(const string& s) {
		int l = s.size();
		for (int i = 0; i < l; i++) {
			num[i] = s[l - 1 - i] - '0';
		}
		if (!(l == 1 && num[0] == 0)) length = l;
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

	string s1, s2;
	cin >> s1 >> s2;
	HighPrecisionNumber a(s1), b(s2);
	HighPrecisionNumber c = a + b;
	c.show();
}