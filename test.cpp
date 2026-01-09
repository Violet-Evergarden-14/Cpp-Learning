#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double image;
public:
	Complex();
	~Complex();

	Complex(double _real, double _image);

	double getReal() const
	{
		return this->real;
	}

	double getImage() const {return this->image;}
	void set_image(double _image);
	bool judge(const Complex& a) const;


	friend std::ostream& operator<< (std::ostream& out, const Complex& com);
};

Complex::Complex(double _real, double _image)
{
	this->real = _real;
	this->image = _image;
}

std::ostream& operator<< (std::ostream& out, const Complex& com)
{
	double a = com.getReal();
	double b = com.getImage();

	out << "Complex(" <<  a<< "," << b<< ")";

	return out;
}

void Complex::set_image(double _image)
{
	this->image = _image;
}

bool Complex::judge(const Complex& a) const
{
	if (this->image != a.image)
	{
		return false;
	}
	return true;
}

bool JUDGE(Complex& a, const Complex& b)
{
	if (a.getReal() != b.getReal())
	{
		return false;
	}
	return true;
}