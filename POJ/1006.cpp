#include <iostream>
using namespace std;

int main()
{
	int p, e, i, d;
	int count = 0;
	while (true) {
		count++;
		cin >> p >> e >> i >> d;
		if (p == -1 && e == -1 && i == -1 && d == -1) {break;}
		p %= 23;
		e %= 28;
		i %= 33;
		while((p - e) % 28 != 0) {p += 23;}
		while((p - i) % 33 != 0) {p += 644;}
		while (p <= d) {p += 21252;}
		cout << "Case " << count << ": the next triple peak occurs in " << p - d << " days." <<endl;
	}
}