#include <iostream>
using namespace std;

long long fib(int n)
{
	return (n < 2) ? n : fib(n - 1) + fib(n - 2);
}

long long fib(int n, long long &prev)
{
	if (n == 0)
	{
		prev = 1;
		return 0;
	}
	
	long long prev_prev;
	prev = fib(n - 1, prev_prev);
	return prev + prev_prev;
}

long long fib(int n)
{
	int f = 0, g = 1;
	
	for (int i = 0; i < n; i++)
	{
		g += f;
		f = g - f;
	}
	
	return f;
}