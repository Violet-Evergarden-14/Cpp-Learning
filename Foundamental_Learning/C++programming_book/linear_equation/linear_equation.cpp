#include "linear_equation.h"
#include <iostream>
#include <cmath>
using namespace std;

LinearEquation::LinearEquation(int size): Matrix(size) {
	sums = new double[size];
	solution = new double[size];
}

LinearEquation::~LinearEquation() {
	delete[] sums;
	delete[] solution;
}

void LinearEquation::set_linear_equation(const double* A, const double* b) {
	set_matrix(A);
	for (int i = 0; i < get_size(); i++) {sums[i] = b[i];}
}

void LinearEquation::print_linear_equation() const {
	cout << "The linear equation is:" << endl;
	for (int i = 0; i < get_size(); i++) {
		for (int j = 0; j < get_size(); j++) {
			cout << element(i, j) << " ";
			cout << "    " << sums[i] << endl;
		}
	}
}

void LinearEquation::print_solution() const {
	cout << "The result is:" << endl;
	for (int i = 0; i < get_size(); i++) {cout << "x" << i << " = " << solution[i] << endl;}
}

void swap(double& v1, double& v2) {
	double temp = v1;
	v1 = v2;
	v2 = temp;
}

bool LinearEquation::solve() {
	int* js = new int[get_size()];
	for (int k = 0; k < get_size() - 1; k++) {
		int is;
		double max = 0;
		for (int i = k; i < get_size(); i++) {
			for (int j = k; j < get_size(); j++) {
				double t = fabs(element(i, j));
				if (t > max) {
					max = t;
					js[k] = j;
					is = i;
				}
			}
		}

		if (max == 0) {
			delete[] js;
			return false;
		} else {
			if (js[k] != k) {
				for (int i = 0; i < get_size(); i++) {swap(element(i, k), element(i, js[k]));}
			}
			if (is != k) {
				for (int j = 0; j < get_size(); j++) {swap(element(k, j), element(is, j));}
				swap(sums[is], sums[k]);
			}
		}

		double major = element(k, k);
		for (int j = k + 1; j < get_size(); j++) {
			element(k, j) /= major;
		}
		sums[k] /= major;
		for (int i = k + 1; i < get_size(); i++) {
			for (int j = k + 1; j < get_size(); j++) {
				element(i, j) -= element(i, k) * element(k, j);
			}
			sums[i] -= element(i, k) * sums[k];
		}
	}

	double d = element(get_size() - 1, get_size() - 1);
	if (fabs(d) < 1e-15) {
		delete[] js;
		return false;
	}

	solution[get_size() - 1] = sums[get_size() - 1] / d;
	for (int i = get_size() - 2; i >= 0; i--) {
		double t = 0.0;
		for (int j = i + 1; j < get_size(); j++) {t += element(i, j) * solution[j];}
		solution[i] = sums[i] - t;
	}
	js[get_size() - 1] = get_size() - 1;
	for (int k = get_size() - 1; k >= 0; k--) {
		if (js[k] != k) {swap(solution[k], solution[js[k]]);}
	}
	delete[] js;
	return true;
}