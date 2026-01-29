#include <iostream>
using namespace std;

class Complex
{
private:
	double re, im;
public:
	Complex(double _re, double _im) : re(_re), im(_im) {};
	Complex(double _re) : re(_re) {};
	Complex(const Complex &_another) : re(_another.re), im(_another.im) {};
	Complex& operator= (double _re) {re = _re; im = 0; return *this;};
	void add(const Complex &_complex) {
		this->im += _complex.im;
		this->re += _complex.re;
	}
	void show() {
		cout << re << "+" << im << "i" << endl;
	}
};

int main()
{
	Complex c1(3, 5);
	Complex c2 = 4.5;
	c1.add(c2);
	c1.show();
}