#include "linear_equation.h"
#include <iostream>
using namespace std;

int main()
{
	double A[] = {1,1,1,2,3,1,1,-1,2};
	double b[] = {2,-1,9};

	LinearEquation equ(3);
	equ.set_linear_equation(A, b);
	equ.print_linear_equation();
	if (equ.solve() == true) {
		equ.print_solution();
	} else {
		cout << "Fail" << endl;
	}
}