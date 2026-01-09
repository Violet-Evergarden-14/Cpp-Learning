#include <iostream>
using namespace std;

typedef double(*Func) (double);

double integral(double a, double b, Func func)
{
	double sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		sum += 0.0001 * func(a + 0.0001 * i * (b - a));
	}
	return sum;
}

double square(double x) {return x * x;}

int main()
{
	cout << integral(0, 3, square);
}