#ifndef _LINEAREQUATION_H
#define _LINEAREQUATION_H

#include "matrix.h"

class LinearEquation: public Matrix
{
private:
	double* sums;
	double* solution;
public:
	LinearEquation(int size = 2);
	~LinearEquation();
	void set_linear_equation(const double* A, const double* b);
	bool solve();
	void print_linear_equation() const;
	void print_solution() const;
};

#endif