#include <iostream>
using namespace std;

typedef int A[10];

int main()
{
	A a;
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}
for (int i = 0; i < 10; i++)
{
	

	cout << *a + i;
}
}