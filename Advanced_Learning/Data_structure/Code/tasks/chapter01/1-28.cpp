#include <iostream>
using namespace std;

int hail(int n)
{
	int step = 1;
	while (n > 1)
	{
		step++;
		n = (n & 1) ? 3 * n + 1 : n >>= 1;
	}
	return step;
}