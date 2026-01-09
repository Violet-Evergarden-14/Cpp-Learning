#include <iostream>
#include <iomanip>
using namespace std;

#define CHAZHI 1E-5

double (*p) (double x);
double yici(double x) {return x;}
double erci(double x) {return x * x;}
double sanci(double x) {return x * x * x;}

typedef double (*function) (double x);

double integral(double a, double b, function p)
{
	int n = 1;
	double SUM = 0;
	double sum = 0;
	double s;
	do
	{
		SUM = sum;
		sum = 0;
		s = (b - a) / n;
		for (int i = 0; i < n; i++)
		{
			sum += s * (*p) (a + i * s);
		}
		n *= 2;
	} while (!(sum - SUM < CHAZHI && sum - SUM > -CHAZHI));
	return sum;
}

int main()
{
	cout << fixed << setprecision(2);
	cout << integral(1, 2, yici) << endl;
	cout << integral(1, 2, erci) << endl;
	cout << integral(1, 2, sanci) << endl;
}