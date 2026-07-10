#include <iostream>
using namespace std;

int main()
{
	unsigned int n;
	cin >> n;
	cout << (n >> 16) + (n << 16);
}