#include <iostream>
using namespace std;

class Complex
{
private:
	int a;
	int b;
public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void show_complex()
	{
		cout << a << " " << b << endl;
	}

	Complex operator+(Complex& another)
	{
		Complex result(this->a + another.a, this->b + another.b);
		return result;
	}

	friend Complex operator+(Complex& c1, Complex& c2);
};

/*
Complex operator+(Complex& c1, Complex& c2)
{
	Complex temp(c1.a + c2.a, c1.b + c2.b);
	return temp;
}
*/

int main()
{
	Complex c1(1, 4);
	Complex c2(3, 6);
	Complex c3 = c1.operator+(c2);
	c3.show_complex();
}