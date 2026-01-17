#include <iostream>
using namespace std;

int count_0(unsigned int n)
{
	int ones = 0;
	while (n > 0)
	{
		ones += (1 & n);
		n >>= 1;
	}
	return ones;
}

int main()
{
	int n;
	cin >> n;
	cout << count_0(n) << endl;
}