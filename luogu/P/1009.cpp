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

	HighPrecisionNumber() {
		length = 1;
		number[0] = 1;
	}

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
		while (result.number[t] > 0) {
			result.number[t + 1] += result.number[t] / 10;
			result.number[t] %= 10;
			t++;
		}
		result.length = t;
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
	HighPrecisionNumber* list = new HighPrecisionNumber[51];
	for (int i = 2; i <= 50; i++) {
		list[i] = list[i - 1].int_multiple(i, 0);
	}

	HighPrecisionNumber* list_sum = new HighPrecisionNumber[51];
	for (int i = 2; i <= 50; i++) {
		list_sum[i] = list_sum[i - 1] + list[i];
	}

	int n;
	cin >> n;
	list_sum[n].show();


	delete[] list_sum;
	delete[] list;
}