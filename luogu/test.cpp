#include <iostream>
#include <vector>
using namespace std;

int n = 3;

unsigned reverse(unsigned v) {
    int mask = 0x0000ffff;
	v = ((v & mask) << 16) + ((v >> 16) & mask);
	mask = 0x00ff00ff;
	v = ((v & mask) << 8) + ((v >> 8) & mask);
	mask = 0x0f0f0f0f;
	v = ((v & mask) << 4) + ((v >> 4) & mask);
	mask = 0x33333333;
	v = ((v & mask) << 2) + ((v >> 2) & mask);
	mask = 0x55555555;
	v = ((v & mask) << 1) + ((v >> 1) & mask);
	return v;
}

int main() {cout << reverse(0xFFFF0000);}