#include <iostream>
#include <vector>
using namespace std;

int n = 3;

int byteSwap(int x, int n, int m) {
	n <<= 3;
	m <<= 3;
	int y = ((x & (255 << n)) >> n) << m;
	int z = ((x & (255 << m)) >> m) << n;
	x &= ~(255 << n);
	x &= ~(255 << m);
    return x + y + z;
}

int main() {cout << byteSwap(0xDEADBEEF, 0, 2);}