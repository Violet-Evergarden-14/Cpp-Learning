#include <iostream>
#include <cmath>
using namespace std;

long times(long m) {
	long result = 1;
	for (long i = 0; i < m; i++) result *= 10;
	return result;
}

long pos(long i, long k, long* list) {
	return i * k - list[i];
}

void find_position() {
	long m;
	cin >> m;
	long list_minus[6] = {0, 0, 9, 108, 1107, 11106};
	long list_dot[5] = {0, 45, 9045, 1395495, 189414495};
	long weishu = 1;
	while (m >= list_dot[weishu] && weishu <= 4) {weishu++;}
	m -= list_dot[weishu - 1];
	if (m == 0) {cout << 9 << endl; return;}
	long count = 0;
	long index = times(weishu - 1);
	while (count <= m) {
		count += pos(weishu, index, list_minus);
		index++;
	}
	index--;
	m = m - count + pos(weishu, index, list_minus);
	if (m == 0) {cout << (index - 1) % 10 << endl; return;}
	long list[6] = {0, 9, 189, 2889, 38889, 488889};
	long t = 1;
	while (m >= list[t] && t <= 4) {t++;}
	m -= list[t - 1];
	if (m == 0) {cout << 9 << endl; return;}
	long number = times(t - 1);
	number += (m - 1) / t;
	m -=  t * (number - times(t - 1));
	if (m == 0) {cout << (number - 1) % 10 << endl; return;}
	for (long i = 0; i < t - m; i++) {number /= 10;}
	cout << number % 10 << endl;
}

int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; i++) {
		find_position();
	}
}