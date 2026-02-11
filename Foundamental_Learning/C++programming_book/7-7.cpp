#include <iostream>
using namespace std;

class Base0 {
public:
	int var0;
	void fun0() {cout << "0" << endl;}
};

class Base1: virtual public Base0 {
public:
	int var1;
};

class Base2: virtual public Base0 {
public:
	int var2;
};

class Derived: public Base1, public Base2 {
public:
	int var;
	void fun() {cout << "D" << endl;}
};

int main()
{
	Derived d;
	d.Base1::var0 = 2;
	d.Base1::fun0();
	
}