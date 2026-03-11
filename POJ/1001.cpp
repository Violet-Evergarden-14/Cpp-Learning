#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class HighPrecisionNumber
{
public:
	int length;
	vector<int> number = vector<int>(200);

	HighPrecisionNumber(int n) {
		length = 0;
		while (n > 0) {
			this->number[length] = n % 10;
			n /= 10;
			length++;
		}
	}
	HighPrecisionNumber(const HighPrecisionNumber& another): length(another.length) {
		copy(another.number.begin(), another.number.end(), this->number.begin());
	}

	HighPrecisionNumber operator+(const HighPrecisionNumber& another) {
		HighPrecisionNumber result(0);
		int m = max(this->length, another.length);
		for (int i = 0; i < m; i++) {
			result.number[i] += (this->number[i] + another.number[i]);
			if (result.number[i] >= 10) {
				result.number[i] -= 10;
				result.number[i + 1]++;
			}
		}
		if(result.number[m] > 0) {
			result.length = m + 1;
		} else {
			result.length = m;
		}
		return result;
	}

	HighPrecisionNumber int_multiple(int m, int weishu) {
		HighPrecisionNumber result(0);
		for (int i = 0; i < this->length; i++) {
			result.number[i + weishu] += this->number[i] * m;
			result.number[i + 1 + weishu] += result.number[i + weishu] / 10;
			result.number[i + weishu] %= 10;
		}
		int t = 199;
		for (t; t >= 0; t--) {
			if (result.number[t] != 0) {break;}
		}
		result.length = t + 1;
		return result;
	}

	HighPrecisionNumber HPN_multiple(const HighPrecisionNumber& another) {
		HighPrecisionNumber result(0);
		for (int i = 0; i < another.length; i++) {
			result = result + this->int_multiple(another.number[i], i);
		}
		int m = 199;
		for (m; m >= 0; m--) {
			if (result.number[m] != 0) {break;}
		}
		result.length = m + 1;
		return result;
	}

	void show() {
		for (int i = length - 1; i >= 0; i--) {cout << this->number[i];}
		cout << endl;
	}
};

int p(int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {result *= 10;}
	return result;
}

int main()
{
	char a[10];
	int k;
	while (cin >> a >> k) {
		int l1 = strlen(a);
		int dot = 0;
		while (a[dot] != '.' && dot < l1) {
			dot++;
		}

		int n = 0;
		if (dot == l1) {
			for (int i = 0; i < l1; i++) {
				n += p(l1 - 1 - i) * (a[i] - '0');
			}
		} else {
			while (a[l1 - 1] == '0') {
				a[l1 - 1] = '\0';
				l1--;
		
			}
			for (int i = dot + 1; i < l1; i++) {
				n += p(l1 - 1 - i) * (a[i] - '0');
			}
			for (int i = 0; i < dot; i++) {
				n += p(l1 - 2 - i) * (a[i] - '0');
			}
		}
		
		HighPrecisionNumber hpn(n);
		HighPrecisionNumber result(1);
		for (int i = 0; i < k; i++) {
			result = result.HPN_multiple(hpn);
		}
		if (result.length == 0) {cout << "0"; return 0;} else {
			if (dot == l1 || dot == l1 - 1) {result.show();} else {
				int xiaoshu = k * (l1 - dot - 1);
				if (result.length > xiaoshu) {
					for (int i = result.length - 1; i >= xiaoshu; i--) {
						cout << result.number[i];
					}
					cout << ".";
					for (int i = xiaoshu - 1; i >= 0; i--) {
						cout << result.number[i];
					}
					cout << endl;
				} else {
					cout << ".";
					for (int i = 0; i < xiaoshu - result.length; i++) {cout << "0";}
					result.show();
				}
			}
		}
	}
}