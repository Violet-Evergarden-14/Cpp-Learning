#include <iostream>
using namespace std;

class Complex
{
private:
	int a, b;
public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	friend Complex add_complex(Complex& c1, Complex& c2);

	void print_complex()
	{
		cout << "(" << a << "," << b << ")" << endl;
	}

	void add(Complex& another_c)
	{
		cout << "(" << this->a + another_c.a << "," << this->b + another_c.b << ")" << endl;
	}

	Complex add_Complex(Complex& another_c)
	{
		Complex temp(this->a + another_c.a, this->b + another_c.b);
		return temp;
	}
};

Complex add_complex(Complex& c1, Complex& c2)
{
	Complex c3(c1.a + c2.a, c1.b + c2.b);
	return c3;
}

int main()
{
	Complex c1(1, 2);
	Complex c2(3, 7);
	c1.print_complex();
	c1.add(c2);
	Complex c3 = add_complex(c1, c2);
	c3.print_complex();
	Complex c4 = c1.add_Complex(c2);
	c4.print_complex();
}