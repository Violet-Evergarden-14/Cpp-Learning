#include <iostream>
using namespace std;

class Base1
{
public:
	int var;
	void func() {cout << 1 << endl;}
};

class Base2
{
public:
	int var;
	void func() {cout << 2 << endl;}
};

class Derived: public Base1, public Base2
{
public:
	int var;
	void func() {cout << "Derived" << endl;}
};

int main()
{
	Derived d;
	Derived *p = &d;

	d.var = 1;
	d.func();

	d.Base1::var = 2;
	d.Base1::func();

	p->Base2::var = 3;
	d.Base2::func();
}