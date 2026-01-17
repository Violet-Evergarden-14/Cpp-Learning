#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	int p = 0;
	while(!(a & 1) && !(b & 1)) {
		a >>= 1;
		b >>= 1;
		p++;
	}

	while(1) {
		(a > b) ? a = a - b : b = b - a;
		if (a == 0) {return b << p;}
		if (b == 0) {return a << p;}
	}
}

int main()
{
	cout << gcd(4940299840889299892, 8002901890492492548);
}