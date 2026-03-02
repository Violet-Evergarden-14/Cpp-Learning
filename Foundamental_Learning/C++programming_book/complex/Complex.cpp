#include <iostream>
using namespace std;

class Complex
{
private:
	double real, imag;
public:
	Complex(double _real = 0, double _imag = 0): real(_real), imag(_imag) {};
	friend Complex operator+(const Complex& c1, const Complex& c2);
	friend Complex operator-(const Complex& c1, const Complex& c2);
	friend ostream& operator<<(ostream& out, const Complex& c);
};

Complex operator+(const Complex& c1, const Complex& c2) {
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator-(const Complex& c1, const Complex& c2) {
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

ostream& operator<<(ostream& out, const Complex& c) {
	out << "(" << c.real << ", " << c.imag << ")";
	return out;
}

int main()
{
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1=" << c1 << endl;
	c3 = c1 - c2;
	cout << "c3=" << c3 << endl;
}