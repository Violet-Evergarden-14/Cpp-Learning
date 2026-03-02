#include "tranpzint.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	MyFunction f;
	Tranz tranz(f);
	cout << fixed << setprecision(7) << tranz(0, 2, 1E-7) << endl;
}